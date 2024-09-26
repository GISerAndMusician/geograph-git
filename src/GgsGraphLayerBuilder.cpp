#include "GgsGraphLayerBuilder.h"
#include "qgscoordinatereferencesystem.h"
#include "qgsproject.h"
#include "qgsrenderer.h"
#include "qgssinglesymbolrenderer.h"
#include "qgssymbolselectordialog.h"
#include "qgsstyle.h"
#include "qgsmemoryproviderutils.h"
#include "GgsGraphProxy.h"

#pragma execution_character_set("utf-8") 

GgsGraphLayerBuilder::GgsGraphLayerBuilder()
{

}

GgsGraphLayerBuilder::~GgsGraphLayerBuilder()
{

}

void GgsGraphLayerBuilder::buildNodeLayer(
	GgsGraphProxy* graphProxy,
	const QMap<QString, QStringList>& data,
	const QString& XLabel, 
	const QString& YLabel, 
	const QString& IDLabel,
	const QStringList& fieldLabels,
	QMap<QString, QgsFeatureId>& idMap,
	QProgressBar* progressBar
	)
{
	
	// 创建节点图层代理
	GgsNodeLayerProxy* nodeLayerProxy = graphProxy->nodeLayerProxy();
	QgsVectorDataProvider* dateProvider = nodeLayerProxy->nodeLayer()->dataProvider();

	// 添加要素
	nodeLayerProxy->nodeLayer()->startEditing();
	int iFeatureCount = data[XLabel].size() < data[YLabel].size() ? data[XLabel].size() : data[YLabel].size();
	if (progressBar)
	{
		progressBar->setRange(0, iFeatureCount - 1);
		progressBar->setFormat(QObject::tr("正在载入节点要素...%p%"));
	}
	for (int i=0; i<iFeatureCount; i++)
	{
		QgsFeature feature;

		QgsPointXY pt;
		pt.setX(data[XLabel][i].toDouble());
		pt.setY(data[YLabel][i].toDouble());
		feature.setGeometry(QgsGeometry::fromPointXY(pt));
		
		// 添加属性字段
		QgsAttributes nodeAttributes;
		for each (QgsField field in nodeLayerProxy->nodeLayer()->fields())
		{
			nodeAttributes << data[field.name()][i];
			/*nodeLayerProxy->nodeLayer()->changeAttributeValue(feature.id(), 
				nodeLayerProxy->nodeLayer()->fields().indexOf(key),
				data[key][i]);*/
		}
		feature.setAttributes(nodeAttributes);
		dateProvider->addFeature(feature);

		// 存储要素ID和导入节点图层ID的对应表
		idMap.insert(data[IDLabel][i], feature.id());

		// 创建节点代理
		GgsNodeProxy* nodeProxy = graphProxy->newNodeProxy(feature);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}

	nodeLayerProxy->nodeLayer()->commitChanges();
	nodeLayerProxy->nodeLayer()->updateExtents();
}

void GgsGraphLayerBuilder::buildEdgeLayer(
	GgsGraphProxy* graphProxy,
	const QMap<QString, QStringList>& data,
	const QMap<QString, QgsFeatureId>& idMap,
	const QString& sourceLabel,
	const QString& targetLabel,
	const QStringList& fieldLabels,
	QProgressBar* progressBar)
{
	// 创建连边图层代理
	GgsEdgeLayerProxy* edgeLayerProxy = graphProxy->edgeLayerProxy();
	QgsVectorDataProvider* dateProvider = edgeLayerProxy->edgeLayer()->dataProvider();

	// 添加要素
	edgeLayerProxy->edgeLayer()->startEditing();
	int iFeatureCount = data[sourceLabel].size() < data[sourceLabel].size() ? data[targetLabel].size() : data[targetLabel].size();
	if (progressBar)
	{
		progressBar->setRange(0, iFeatureCount - 1);
		progressBar->setFormat(QObject::tr("正在载入连边要素...%p%"));
	}
	for (int i = 0; i < iFeatureCount; i++)
	{
		if (data[sourceLabel][i] == data[targetLabel][i])
		{
			continue;
		}

		QgsFeature feature;
		
		QgsPolylineXY pl;
		pl.append(
			graphProxy->nodeLayerProxy()->nodeLayer()->getFeature(idMap.value(data[sourceLabel][i])).geometry().asPoint()
		);
		pl.append(
			graphProxy->nodeLayerProxy()->nodeLayer()->getFeature(idMap.value(data[targetLabel][i])).geometry().asPoint()
		);

		if ( !graphProxy->nodeLayerProxy()->nodeLayer()->getFeature(idMap.value(data[sourceLabel][i])).isValid() ||
			 !graphProxy->nodeLayerProxy()->nodeLayer()->getFeature(idMap.value(data[targetLabel][i])).isValid()
			) {
			continue;
		}
		
		feature.setGeometry(QgsGeometry::fromPolylineXY(pl));

		// 添加属性字段
		QgsAttributes edgeAttributes;
		for each (QgsField field in edgeLayerProxy->edgeLayer()->fields())
		{
			edgeAttributes << data[field.name()][i];
			/*edgeLayerProxy->edgeLayer()->changeAttributeValue(feature.id(),
				edgeLayerProxy->edgeLayer()->fields().indexOf(key),
				data[key][i]);*/
		}
		feature.setAttributes(edgeAttributes);
		bool bSuccess = dateProvider->addFeature(feature);

		// 创建连边代理
		GgsEdgeProxy* edgeProxy = graphProxy->newEdgeProxy(
			graphProxy->nodeLayerProxy()->findNode(idMap.value(data[sourceLabel][i])),
			graphProxy->nodeLayerProxy()->findNode(idMap.value(data[targetLabel][i])),
			feature
		);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}

	edgeLayerProxy->edgeLayer()->commitChanges();
	edgeLayerProxy->edgeLayer()->updateExtents();
}

bool GgsGraphLayerBuilder::isNumber(const QString& d)
{
	if (d.size() == 0) {
		return false;
	}
	QRegExp regx("[+-]*\\d+\\.?\\d*[Ee]*[+-]*\\d+");

	bool isNumber = regx.exactMatch(d.trimmed());
	if (isNumber) {
		return isNumber;
	}
	regx.setPattern("^[-\\+]?[.\\d]*$");
	return regx.exactMatch(d.trimmed());
}

QString GgsGraphLayerBuilder::buildFieldPropertyString(const QMap<QString, QStringList>& data)
{
	QList<QString> keys = data.keys();

	QString fieldProps;
	for each (QString key in keys)
	{
		bool bNumber = true;
		for each (QString var in data[key])
		{
			if (!isNumber(var))
			{
				bNumber = false; // 但凡有一个不是数值，则判断为字符串类型
			}
		}
		
		fieldProps.append(
			QString("field=%1:%2&").
			arg(key).
			arg(bNumber?"double":"string(50)")
		);
	}

	return fieldProps;
}

QgsFields GgsGraphLayerBuilder::buildFields(const QMap<QString, QStringList>& data)
{
	QgsFields fields;

	QList<QString> keys = data.keys();

	QString fieldProps;
	for each (QString key in keys)
	{
		// 如果有值，则可以通过值判断值类型
		if (data[key].size() > 0)
		{
			QgsField field(key, QVariant(data[key][0]).type());
			fields.append(field);
		}
		else { // 否则，直接默认是字符串类型
			QgsField field(key, QVariant::String);
			fields.append(field);
		}
	}

	return fields;
}
