#include "GgsGraphLegendWidget.h"
#include <QVariant>
#include "GgsGraphProject.h"
#include "GgsGraphProxy.h"
#include "GgsApp.h"
#include "qgslayertreeview.h"
#include "qgslayertreemodel.h"

GgsGraphLegendWidget::GgsGraphLegendWidget(QWidget* parent /*= 0*/)
	: QWidget(parent)
{
	setupUi(this);

	connect(GgsGraphProject::instance(), SIGNAL(graphLayerAdded(GgsGraphProxy*)), this, SLOT(onGraphLayerAdded(GgsGraphProxy*)));
	connect(listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(onItemChanged(QListWidgetItem*)));
	connect(listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onItemSelectionChanged()));
	connect(linkage_toolButton, SIGNAL(clicked(bool)), this, SLOT(onLinkageClicked(bool)));
	connect(remove_toolButton, SIGNAL(clicked(bool)), this, SLOT(onRemoveClicked(bool)));

	this->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

GgsGraphLegendWidget::~GgsGraphLegendWidget()
{

}

void GgsGraphLegendWidget::removeGraphLayer(GgsGraphProxy* pGraph)
{
	QListWidgetItem* current = listWidget->currentItem();
	if (!current) return;

	disconnect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
	disconnect(listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(onItemChanged(QListWidgetItem*)));
	{
		listWidget->takeItem(listWidget->row(current));
		delete current;
	}
	connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClicked(QListWidgetItem*)));
	connect(listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(onItemChanged(QListWidgetItem*)));

	// 如果已选中，则取消
	if (GgsGraphProject::instance()->hasSelected(pGraph)) {
		GgsGraphProject::instance()->removeSelection(pGraph);
	}

	int iIndex = GgsGraphProject::instance()->indexOfGraphProxy(pGraph);
	GgsGraphProject::instance()->removeGraphProxyAt(iIndex);
}

void GgsGraphLegendWidget::onGraphLayerAdded(GgsGraphProxy* graph)
{
	QListWidgetItem* pItem = new QListWidgetItem(QIcon(":/graph/bundling/graphlayer.png"), graph->getName());
	pItem->setData(Qt::UserRole, QVariant::fromValue(graph));
	pItem->setCheckState(Qt::Checked);
	this->listWidget->addItem(pItem);

	// 清除默认选择
	this->listWidget->clearSelection();
}

void GgsGraphLegendWidget::onItemChanged(QListWidgetItem* item)
{
	//如果视图联动则继续
	if (!mLinkage) return;

	GgsGraphProxy* pGraph = item->data(Qt::UserRole).value<GgsGraphProxy*>();

	GgsApp::instance()->layerTreeView()->setLayerVisible(
		pGraph->nodeLayerProxy()->nodeLayer(),
		item->checkState()
	);
	
	GgsApp::instance()->layerTreeView()->setLayerVisible(
		pGraph->edgeLayerProxy()->edgeLayer(),
		item->checkState()
	);
}

void GgsGraphLegendWidget::onItemSelectionChanged()
{
	GgsGraphProject::instance()->clearSelections();

	QList<QListWidgetItem*> selections = listWidget->selectedItems();
	for each (QListWidgetItem* item in selections)
	{
		GgsGraphProxy* pGraph = item->data(Qt::UserRole).value<GgsGraphProxy*>();

		GgsApp::instance()->layerTreeView()->setCurrentLayer(pGraph->nodeLayerProxy()->nodeLayer());
		QModelIndex nodeIndex = GgsApp::instance()->layerTreeView()->layerTreeModel()->currentIndex();
		GgsApp::instance()->layerTreeView()->setCurrentLayer(pGraph->edgeLayerProxy()->edgeLayer());
		QModelIndex edgeIndex = GgsApp::instance()->layerTreeView()->layerTreeModel()->currentIndex();

		if (mLinkage) {
			GgsApp::instance()->layerTreeView()->selectionModel()->select(nodeIndex, QItemSelectionModel::Select);
			GgsApp::instance()->layerTreeView()->selectionModel()->select(edgeIndex, QItemSelectionModel::Select);
		}

		GgsGraphProject::instance()->addSelection(pGraph);
	}
}

void GgsGraphLegendWidget::onLinkageClicked(bool bChecked)
{
	mLinkage = bChecked;
}

void GgsGraphLegendWidget::onRemoveClicked(bool bChecked)
{
	if (!listWidget->currentItem()) {
		return;
	}

	GgsGraphProxy* pGraph = listWidget->currentItem()->data(Qt::UserRole).value<GgsGraphProxy*>();

	if (!pGraph) {
		return;
	}

	QgsVectorLayer* nodeLayer = pGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* edgeLayer = pGraph->edgeLayerProxy()->edgeLayer();

	if (!nodeLayer || !edgeLayer)
	{
		return;
	}

	QList<QgsMapLayer*> layers;
	layers << edgeLayer << nodeLayer;
	GgsApp::instance()->removeLayers(layers);

	removeGraphLayer(pGraph);
}
