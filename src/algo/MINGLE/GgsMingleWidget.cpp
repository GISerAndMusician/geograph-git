#include "GgsMingleWidget.h"
#include "qgsproject.h"
#include "qgsvectorlayer.h"
#include "qgsfeature.h"
#include "qgsmemoryproviderutils.h"
#include "qgsrenderer.h"
#include "qgscategorizedsymbolrenderer.h"
#include "qgssinglesymbolrenderer.h"
#include "qgslinesymbollayer.h"

#include "GgsGraphProject.h"
#include "GgsMingleBundler.h"

#pragma execution_character_set("utf-8") 

GgsMingleWidget::GgsMingleWidget(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{
	setupUi(this);

	initComboBox();
	initRenderComboBox();
	initUiValues();

	connect(pushButtonRun, &QPushButton::clicked, this, &GgsMingleWidget::run);
	connect(GgsGraphProject::instance(), &GgsGraphProject::graphLayerAdded, this, &GgsMingleWidget::refreshGraphProxys);
	connect(comboBoxGraph, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentProxyChanged(int)));
	connect(checkBoxLoose, &QCheckBox::stateChanged, this, &GgsMingleWidget::toggleMargin);
	connect(horizontalSliderDelta, &QSlider::valueChanged, this, &GgsMingleWidget::updateDeltaUiText);
	connect(horizontalSliderCurveness, &QSlider::valueChanged, this, &GgsMingleWidget::updateCurvenessUiText);
	connect(comboBoxLineType, SIGNAL(currentIndexChanged(int)), this, SLOT(toggleLoose(int)));
	connect(horizontalSliderAlpha, &QSlider::valueChanged, this, &GgsMingleWidget::updateAlphaUiText);

	this->progressBar->setHidden(true);
}

GgsMingleWidget::~GgsMingleWidget()
{

}

void GgsMingleWidget::refreshGraphProxys(GgsGraphProxy* graphProxy)
{
	this->comboBoxGraph->clear();
	initComboBox();
}

void GgsMingleWidget::run()
{

	GgsGraphProxy* graphProxy = comboBoxGraph->currentData().value<GgsGraphProxy*>();

	if (!graphProxy)
	{
		return;
	}

	if (!mWidgetParams.contains(graphProxy->uuid()))
	{
		mWidgetParams.insert(graphProxy->uuid(), QList<QVariant>());
	}

	QList<QVariant>& wp = mWidgetParams[graphProxy->uuid()];

	// 存储界面参数
	wp << doubleSpinBox->value() << spinBoxNeighbors->value() << horizontalSliderDelta->value() << 
		horizontalSliderCurveness->value() << spinBoxMargin->value() << comboBoxLineType->currentIndex() << 
		comboBoxColor->currentIndex() << checkBoxLoose->isChecked() << horizontalSliderAlpha->value();

	QgsVectorLayer* edgeLayer = graphProxy->edgeLayerProxy()->edgeLayer();
	QgsFeatureIterator iter_feature = edgeLayer->getFeatures();
	QgsFeature f;

	QList<GgsMingleNode*> nodes;
	while (iter_feature.nextFeature(f))
	{
		QgsPolylineXY plXY = f.geometry().asPolyline();

		GgsMingleNode* n = new GgsMingleNode;
		n->setId(QString::number(f.id()));
		n->setName(QString::number(f.id()));
		n->setCoordSource(plXY.first());
		n->setCoordTarget(plXY.last());

		nodes << n;
	}

	GgsMingleBundler bundler;
	connect(&bundler, &GgsMingleBundler::progressChanged, this, &GgsMingleWidget::onProgressChanged);

	bundler.setAngleStrength(doubleSpinBox->value());
	bundler.setNodes(nodes);
	bundler.buildNearestNeighborGraph(spinBoxNeighbors->value());
	bundler.mingle();

	GgsMingleRenderContext ctx;
	ctx.setLineType(GgsMingleRenderContext::LineType(comboBoxLineType->currentData().toInt()));
	ctx.setDelta(horizontalSliderDelta->value() / 100.0);
	ctx.setCurveness(horizontalSliderCurveness->value() / 100.0);
	ctx.setMargin(spinBoxMargin->value());
	ctx.enableLoose(checkBoxLoose->isChecked());
	ctx.setColorType(GgsMingleRenderContext::ColorType(comboBoxColor->currentData().toInt()));
	ctx.setAlpha(horizontalSliderAlpha->value() / 100.0);
	
	// 执行渲染
	QgsField clusterField;
	clusterField.setName(GgsMingleRenderContext::MINGLE_CLUSTER);
	clusterField.setAlias(GgsMingleRenderContext::MINGLE_CLUSTER);
	clusterField.setType(QVariant::Int);
	clusterField.setTypeName("integer");
	clusterField.setLength(10);

	QgsField edgeField;
	edgeField.setName(GgsMingleRenderContext::MINGLE_EDGE);
	edgeField.setAlias(GgsMingleRenderContext::MINGLE_EDGE);
	edgeField.setType(QVariant::Int);
	edgeField.setTypeName("integer");
	edgeField.setLength(10);

	QgsField directionField;
	directionField.setName(GgsMingleRenderContext::MINGLE_DIRECTION);
	directionField.setAlias(GgsMingleRenderContext::MINGLE_DIRECTION);
	directionField.setType(QVariant::Int);
	directionField.setTypeName("integer");
	directionField.setLength(10);

	QgsFields fields;
	fields.append(clusterField);
	fields.append(edgeField);
	fields.append(directionField);
	
	QgsVectorLayer* pLayer = QgsMemoryProviderUtils::createMemoryLayer(
		"[MINGLE]" + graphProxy->edgeLayerProxy()->edgeLayer()->name(),
		fields,
		QgsWkbTypes::LineString,
		edgeLayer->crs());

	if (!pLayer->isValid())
	{
		this->progressBar->hide();
		return;
	}

	bundler.render(ctx, pLayer);

	// 设置图层的渲染，必须在render操作之后
	if (ctx.getColorType() == GgsMingleRenderContext::SOLID)
	{
		mRandomColorRamp.setTotalColorCount(1);

		QgsSimpleLineSymbolLayer* lineSymbolLayer = new QgsSimpleLineSymbolLayer;
		QgsSymbolLayerList symbolLayerList;
		symbolLayerList.append(lineSymbolLayer);

		QgsLineSymbol* ls = new QgsLineSymbol(symbolLayerList);
		ls->setColor(mRandomColorRamp.color(0));
		ls->setOpacity(ctx.getAlpha());

		QgsSingleSymbolRenderer* renderer = new QgsSingleSymbolRenderer(ls);
		pLayer->setRenderer(renderer);
	}
	else
	{
		QString fieldName;
		switch (ctx.getColorType())
		{
		case GgsMingleRenderContext::CLUSTER:
			fieldName = GgsMingleRenderContext::MINGLE_CLUSTER;
			break;
		case GgsMingleRenderContext::EDGE:
			fieldName = GgsMingleRenderContext::MINGLE_EDGE;
			break;
		case GgsMingleRenderContext::DIRECTION:
			fieldName = GgsMingleRenderContext::MINGLE_DIRECTION;
			break;
		default:
			break;
		}

		// 字段索引
		int fieldIndex = pLayer->fields().indexOf(fieldName);
		if (fieldIndex != -1)
		{
			// 字段对应的所有属性值
			QSet<QVariant> set = pLayer->uniqueValues(fieldIndex);
			QVariantList list = set.toList();

			// 不同值渲染不同颜色
			QgsCategoryList categoryList = QgsCategorizedSymbolRenderer::createCategories(list,
				QgsSymbol::defaultSymbol(pLayer->geometryType()), pLayer, fieldName);

			mRandomColorRamp.setTotalColorCount(categoryList.size());

			int i = 0;
			for (auto iter = categoryList.begin(); iter != categoryList.end(); ++iter, ++i)
			{
				iter->symbol()->setColor(mRandomColorRamp.color(i));
				QgsLineSymbol* ls = dynamic_cast<QgsLineSymbol*>(iter->symbol());
				ls->setOpacity(ctx.getAlpha());
			}

			//初始化渲染器，并赋给图层
			std::unique_ptr<QgsCategorizedSymbolRenderer> renderer = qgis::make_unique<QgsCategorizedSymbolRenderer>(fieldName, categoryList);
			pLayer->setRenderer(renderer->clone());
		}
	}

	QgsProject::instance()->addMapLayer(pLayer);

	this->progressBar->hide();
}

void GgsMingleWidget::onProgressChanged(int iter, int current, int total)
{

	if (this->progressBar->isHidden())
	{
		this->progressBar->show();
	}
	this->progressBar->setFormat(QString("正在执行第%1次迭代...").arg(QString::number(iter)));
	this->progressBar->setRange(0, total);
	this->progressBar->setValue(current);
	qApp->processEvents();
}

void GgsMingleWidget::onCurrentProxyChanged(int index)
{
	if (index == -1)
	{
		return;
	}

	GgsGraphProxy* graphProxy = comboBoxGraph->currentData().value<GgsGraphProxy*>();
	if (!graphProxy)
	{
		return;
	}

	if (!mWidgetParams.contains(graphProxy->uuid()))
	{
		return;
	}

	QList<QVariant> wp = mWidgetParams.value(graphProxy->uuid());

	doubleSpinBox->setValue(wp[0].toDouble());
	spinBoxNeighbors->setValue(wp[1].toInt());
	horizontalSliderDelta->setValue(wp[2].toInt());
	horizontalSliderCurveness->setValue(wp[3].toInt());
	spinBoxMargin->setValue(wp[4].toDouble());
	comboBoxLineType->setCurrentIndex(wp[5].toInt());
	comboBoxColor->setCurrentIndex(wp[6].toInt());
	checkBoxLoose->setChecked(wp[7].toBool());
	horizontalSliderAlpha->setValue(wp[8].toInt());
}

void GgsMingleWidget::toggleMargin(int checkState)
{
	spinBoxMargin->setEnabled((bool)checkState);
}

void GgsMingleWidget::updateDeltaUiText(int value)
{
	int span = horizontalSliderDelta->maximum() - horizontalSliderDelta->minimum();
	labelDelta->setText(QString("Delta(%1%)").arg(value*100.0 / span));
}

void GgsMingleWidget::updateCurvenessUiText(int value)
{
	int span = horizontalSliderCurveness->maximum() - horizontalSliderCurveness->minimum();
	labelCurveness->setText(QString("Curveness(%1%)").arg(value*100.0 / span));
}

void GgsMingleWidget::updateAlphaUiText(int value)
{
	int span = horizontalSliderAlpha->maximum() - horizontalSliderAlpha->minimum();
	labelAlpha->setText(QString("Alpha(%1%)").arg(value*100.0 / span));
}

void GgsMingleWidget::toggleLoose(int index)
{
	if (index == -1)
	{
		return;
	}

	if (comboBoxLineType->currentData().toInt() == GgsMingleRenderContext::LINE)
	{
		checkBoxLoose->setChecked(false);
		checkBoxLoose->setEnabled(false);
	}
	else
	{
		checkBoxLoose->setChecked(true);
		checkBoxLoose->setEnabled(true);
	}
}

void GgsMingleWidget::initComboBox()
{
	for each (GgsGraphProxy* graphProxy in GgsGraphProject::instance()->graphProxys())
	{
		comboBoxGraph->addItem(QIcon(":/graph/bundling/graphlayer.png"),
			graphProxy->getName(),
			QVariant::fromValue(graphProxy)
		);
	}
}

void GgsMingleWidget::initUiValues()
{
	int index = this->comboBoxLineType->findData(GgsMingleRenderContext::BEZIER);
	this->comboBoxLineType->setCurrentIndex(index);
}

void GgsMingleWidget::initRenderComboBox()
{
	// line type comboBox
	this->comboBoxLineType->addItem(QString("Line"), GgsMingleRenderContext::LineType::LINE);
	this->comboBoxLineType->addItem(QString("Bezier"), GgsMingleRenderContext::LineType::BEZIER);
	this->comboBoxLineType->addItem(QString("Quadratic"), GgsMingleRenderContext::LineType::QUADRATIC);

	// color type comboBox
	this->comboBoxColor->addItem(QString("Solid"), GgsMingleRenderContext::SOLID);
	this->comboBoxColor->addItem(QString("Cluster"), GgsMingleRenderContext::CLUSTER);
	this->comboBoxColor->addItem(QString("Direction"), GgsMingleRenderContext::DIRECTION);
	this->comboBoxColor->addItem(QString("Edge"), GgsMingleRenderContext::EDGE);
}
