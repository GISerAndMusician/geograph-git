#include "GgsLwoInteractionWidget.h"
#include "GgsGraphProject.h"
#include "GgsGraphProxy.h"
#include <QColorDialog>

GgsLwoInteractionWidget::GgsLwoInteractionWidget(GgsLwoInteraction* lwo, QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{
	setupUi(this);

	connect(GgsGraphProject::instance(), &GgsGraphProject::graphSelectionChanged, this, &GgsLwoInteractionWidget::onGraphSelectionChanged);

	mLwoInteraction = lwo;

	GgsGraphProxy* current = GgsGraphProject::instance()->currentSelection();
	if (current)
	{
		onGraphSelectionChanged(current);
	}

	initDockUi();

	connect(nodeFillColor_toolButton, &QToolButton::clicked, this, &GgsLwoInteractionWidget::onFillColorBtnClicked);
	connect(nodeStrokeColor_toolButton, &QToolButton::clicked, this, &GgsLwoInteractionWidget::onStrokeColorBtnClicked);
	connect(cNodeFillColor_toolButton, &QToolButton::clicked, this, &GgsLwoInteractionWidget::onCircleFillColorBtnClicked);
	connect(cNodeStrokeColor_toolButton, &QToolButton::clicked, this, &GgsLwoInteractionWidget::onCircleStrokeColorBtnClicked);

	connect(ok_pushButton, &QPushButton::clicked, this, &GgsLwoInteractionWidget::onOk);

	connect(updateComboBox_pushButton, &QPushButton::clicked, this, &GgsLwoInteractionWidget::onUpdateComboBox);
}

GgsLwoInteractionWidget::~GgsLwoInteractionWidget()
{

}

void GgsLwoInteractionWidget::onGraphSelectionChanged(GgsGraphProxy* current)
{
	field_comboBox->clear();

	QgsVectorLayer* pNodeLayer = current->nodeLayerProxy()->nodeLayer();
	QgsFields fields = pNodeLayer->fields();

	for (int i=0; i<fields.size(); i++)
	{
		field_comboBox->insertItem(i, fields.at(i).name());
	}
}

void GgsLwoInteractionWidget::onFillColorBtnClicked()
{
	QColor newColor = QColorDialog::getColor(nodeFillColor_toolButton->palette().color(QPalette::Button), nullptr, tr("选择颜色"));
	QPalette nodeFillColorBtnPal = nodeFillColor_toolButton->palette();
	nodeFillColorBtnPal.setColor(QPalette::Button, newColor);
	this->nodeFillColor_toolButton->setPalette(nodeFillColorBtnPal);
}

void GgsLwoInteractionWidget::onStrokeColorBtnClicked()
{
	QColor newColor = QColorDialog::getColor(nodeStrokeColor_toolButton->palette().color(QPalette::Button), nullptr, tr("选择颜色"));
	QPalette nodeStrokeColorBtnPal = nodeStrokeColor_toolButton->palette();
	nodeStrokeColorBtnPal.setColor(QPalette::Button, newColor);
	this->nodeStrokeColor_toolButton->setPalette(nodeStrokeColorBtnPal);
}

void GgsLwoInteractionWidget::onCircleFillColorBtnClicked()
{
	QColor newColor = QColorDialog::getColor(cNodeFillColor_toolButton->palette().color(QPalette::Button), nullptr, tr("选择颜色"));
	QPalette cNodeFillColorBtnPal = cNodeFillColor_toolButton->palette();
	cNodeFillColorBtnPal.setColor(QPalette::Button, newColor);
	this->cNodeFillColor_toolButton->setPalette(cNodeFillColorBtnPal);
}

void GgsLwoInteractionWidget::onCircleStrokeColorBtnClicked()
{
	QColor newColor = QColorDialog::getColor(cNodeStrokeColor_toolButton->palette().color(QPalette::Button), nullptr, tr("选择颜色"));
	QPalette cNodeStrokeColorBtnPal = cNodeStrokeColor_toolButton->palette();
	cNodeStrokeColorBtnPal.setColor(QPalette::Button, newColor);
	this->cNodeStrokeColor_toolButton->setPalette(cNodeStrokeColorBtnPal);
}

void GgsLwoInteractionWidget::onOk()
{
	mLwoInteraction->setLabel(field_comboBox->currentText());

	mLwoInteraction->setNodeRadius(nodeSize_doubleSpinBox->value());

	mLwoInteraction->setNodeFillColor(nodeFillColor_toolButton->palette().color(QPalette::Button));

	mLwoInteraction->setNodeStrokeColor(nodeStrokeColor_toolButton->palette().color(QPalette::Button));

	mLwoInteraction->setNodeRatio(nodeRatio_doubleSpinBox->value());

	mLwoInteraction->setLabelSpan(labelSpan_doubleSpinBox->value());

	mLwoInteraction->setCircleNodeFillColor(cNodeFillColor_toolButton->palette().color(QPalette::Button));

	mLwoInteraction->setCircleNodeStrokeColor(cNodeStrokeColor_toolButton->palette().color(QPalette::Button));

	// 渲染符号
	mLwoInteraction->renderSymbols(true);
}

void GgsLwoInteractionWidget::onUpdateComboBox()
{
	GgsGraphProxy* current = GgsGraphProject::instance()->currentSelection();
	if (current)
	{
		onGraphSelectionChanged(current);
	}
}

void GgsLwoInteractionWidget::initDockUi()
{
	this->nodeSize_doubleSpinBox->setValue(mLwoInteraction->getNodeRadius());

	QPalette nodeFillColorBtnPal = nodeFillColor_toolButton->palette();
	nodeFillColorBtnPal.setColor(QPalette::Button, mLwoInteraction->getNodeFillColor());
	this->nodeFillColor_toolButton->setPalette(nodeFillColorBtnPal);

	QPalette nodeStrokeColorBtnPal = nodeStrokeColor_toolButton->palette();
	nodeStrokeColorBtnPal.setColor(QPalette::Button, mLwoInteraction->getNodeStrokeColor());
	this->nodeStrokeColor_toolButton->setPalette(nodeStrokeColorBtnPal);

	nodeRatio_doubleSpinBox->setValue(mLwoInteraction->getNodeRatio());

	labelSpan_doubleSpinBox->setValue(mLwoInteraction->getLabelSpan());

	QPalette cNodeFillColorBtnPal = cNodeFillColor_toolButton->palette();
	cNodeFillColorBtnPal.setColor(QPalette::Button, mLwoInteraction->getCircleNodeFillColor());
	this->cNodeFillColor_toolButton->setPalette(cNodeFillColorBtnPal);

	QPalette cNodeStrokeColorBtnPal = cNodeStrokeColor_toolButton->palette();
	cNodeStrokeColorBtnPal.setColor(QPalette::Button, mLwoInteraction->getCircleNodeStrokeColor());
	this->cNodeStrokeColor_toolButton->setPalette(cNodeStrokeColorBtnPal);
}
