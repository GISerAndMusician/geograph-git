#include "GgsKcoreDialog.h"
#include "qgsproject.h"
#include "GgsGraphProject.h"
#include <QMessageBox>

#pragma execution_character_set("utf-8") 

GgsKcoreDialog::GgsKcoreDialog(GgsGraphProxy* graph, QWidget* parent /*= nullptr*/)
	: QDialog(parent)
{
	mGraph = graph;
	mPy.initialize("./python/graph/");
	mModule = mPy.importModule("k-core");

	QgsVectorLayer* pNodeLayer = mGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = mGraph->edgeLayerProxy()->edgeLayer();

	QList<GgsNodeProxy*> nodeProxys = mGraph->nodeLayerProxy()->nodes();
	for each (GgsNodeProxy* n in nodeProxys)
	{
		mNodesStringList << QString::number(n->feature().id());
	}

	QList<GgsEdgeProxy*> edgeProxys = mGraph->edgeLayerProxy()->edges();
	for each (GgsEdgeProxy* e in edgeProxys)
	{
		mEdgesStringList << QString::number(e->fromNode()->feature().id())
			<< QString::number(e->toNode()->feature().id());
	}

	setupUi(this);
	initSpinBox();

	connect(this->pushButton_ok, &QPushButton::clicked, this, &GgsKcoreDialog::onOk);
	connect(this->pushButton_cancel, &QPushButton::clicked, this, &GgsKcoreDialog::reject);

	progressBar->setVisible(false);
}

GgsKcoreDialog::~GgsKcoreDialog()
{

}

void GgsKcoreDialog::onOk()
{

	PyObject* pFunc = mPy.getFunction(mModule, "run");

	PyObject* pArgs = PyTuple_New(3);

	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", mNodesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", mEdgesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 2, Py_BuildValue("i", this->spinBox->value()));

	PyObject* pResult = mPy.callFunction(pFunc, pArgs);

	if (!pResult)
	{
		PyErr_Print();
		this->accept();
		return;
	}

	PyObject* nodes = PyTuple_GetItem(pResult, 0);
	PyObject* edges = PyTuple_GetItem(pResult, 1);

	Py_ssize_t nodes_size = PyList_Size(nodes);
	std::cout << "node size: " << nodes_size << std::endl;
	QList<int> nodeIdList;
	for (Py_ssize_t i = 0; i < nodes_size; i++) {
		int nodeId;
		PyObject* item = PyList_GetItem(nodes, i);
		PyArg_Parse(item, "i", &nodeId);
		nodeIdList << nodeId;
	}

	Py_ssize_t edges_size = PyList_Size(edges);
	std::cout << "edge size: " << edges_size << std::endl;
	QList<QPair<int, int>> edgeIdList;
	for (Py_ssize_t i = 0; i < edges_size; i++) {
		int from, to;
		PyObject* item = PyList_GetItem(edges, i);
		PyObject* fromItem = PyTuple_GetItem(item, 0);
		PyObject* toItem = PyTuple_GetItem(item, 1);

		PyArg_Parse(fromItem, "i", &from);
		PyArg_Parse(toItem, "i", &to);
		edgeIdList << QPair<int, int>(from, to);
	}

	QString szConfirmText = QString("nodes size: %1; edge size: %2. Continue?").arg(nodes_size).arg(edges_size);
	QMessageBox::StandardButton response = QMessageBox::question(this, "确定", 
		szConfirmText,
		QMessageBox::Yes | QMessageBox::No);

	if (response == QMessageBox::No)
	{
		return;
	}

	QgsVectorLayer* pOriginNodeLayer = mGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pOriginEdgeLayer = mGraph->edgeLayerProxy()->edgeLayer();

	progressBar->setVisible(true);
	progressBar->setTextVisible(true);

	progressBar->setRange(0, nodeIdList.size() - 1);
	progressBar->setFormat(tr("正在创建图层...%p%"));

	// 创建节点图层
	QString nodeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("Point").
		arg(pOriginNodeLayer->crs().authid()).
		arg(QUuid::createUuid().toString());    // 几何类型
	QgsVectorLayer* pNodeLayer = new QgsVectorLayer(
		nodeLayerProperties,
		pOriginNodeLayer->name() + QString("[%1-core]").arg(this->spinBox->value()),
		"memory");

	if (!pNodeLayer->isValid())
	{
		this->accept();
		return;
	}
	else {
		pNodeLayer->dataProvider()->addAttributes(pOriginNodeLayer->fields().toList());

		QList< QgsMapLayer * > layers;
		layers << pNodeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	// 创建连边图层
	QString edgeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("LineString").
		arg(pOriginEdgeLayer->crs().authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	QgsVectorLayer* pEgdeLayer = new QgsVectorLayer(
		edgeLayerProperties,
		pOriginEdgeLayer->name() + QString("[%1-core]").arg(this->spinBox->value()),
		"memory");

	if (!pEgdeLayer->isValid())
	{
		this->accept();
		return;
	}
	else {
		pEgdeLayer->dataProvider()->addAttributes(pOriginEdgeLayer->fields().toList());

		QList< QgsMapLayer * > layers;
		layers << pEgdeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	mKcoreGraphProxy = new GgsGraphProxy(pNodeLayer,
		pEgdeLayer,
		"[图]" + pEgdeLayer->name()
	);

	if (progressBar)
	{
		progressBar->setRange(0, nodeIdList.size() - 1);
		progressBar->setFormat(QObject::tr("正在载入节点要素...%p%"));
	}
	pNodeLayer->startEditing();
	QMap<QgsFeatureId, QPair<GgsNodeProxy*, GgsNodeProxy*>> nodeMap;
	for (int i=0; i<nodeIdList.size(); i++)
	{
		GgsNodeProxy* originNodeProxy = mGraph->nodeLayerProxy()->findNode(nodeIdList[i]);

		QgsFeature feature = originNodeProxy->feature();
		pNodeLayer->dataProvider()->addFeature(feature);

		// 创建节点代理
		GgsNodeProxy* nodeProxy = mKcoreGraphProxy->newNodeProxy(feature);

		nodeMap.insert(nodeIdList[i], QPair<GgsNodeProxy*, GgsNodeProxy*>(originNodeProxy, nodeProxy));

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}
	pNodeLayer->commitChanges();
	pNodeLayer->updateExtents();

	pEgdeLayer->startEditing();
	if (progressBar)
	{
		progressBar->setRange(0, edgeIdList.size() - 1);
		progressBar->setFormat(QObject::tr("正在载入连边要素...%p%"));
	}
	for (int i=0; i<edgeIdList.size(); i++)
	{
		GgsNodeProxy* fromNodeProxy = nodeMap[edgeIdList[i].first].second;
		GgsNodeProxy* toNodeProxy = nodeMap[edgeIdList[i].second].second;

		GgsEdgeProxy* pEdgeLayerProxy = mGraph->edgeLayerProxy()->findEdge(
			mGraph->nodeLayerProxy()->findNode(edgeIdList[i].first), 
			mGraph->nodeLayerProxy()->findNode(edgeIdList[i].second));
		
		if (pEdgeLayerProxy)
		{
			QgsFeature feature = pEdgeLayerProxy->feature();
			pEgdeLayer->dataProvider()->addFeature(feature);

			// 创建连边代理
			GgsEdgeProxy* edgeProxy = mKcoreGraphProxy->newEdgeProxy(
				fromNodeProxy,
				toNodeProxy,
				feature
			);
			
		}
		
		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}
	pEgdeLayer->commitChanges();
	pEgdeLayer->updateExtents();

	GgsGraphProject::instance()->addGraphProxy(mKcoreGraphProxy);

	this->accept();
}

void GgsKcoreDialog::initSpinBox()
{
	PyObject* pFunc = mPy.getFunction(mModule, "getMaxCoreNumber");

	PyObject* pArgs = PyTuple_New(2);

	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", mNodesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", mEdgesStringList.join(",").toStdString().c_str()));

	PyObject* pResult = mPy.callFunction(pFunc, pArgs);

	if (!pResult)
	{
		PyErr_Print();
		return;
	}

	int maxCore = 0;
	PyArg_Parse(pResult, "i", &maxCore);

	this->spinBox->setMinimum(0);
	this->spinBox->setMaximum(maxCore + 1);

	label_kcore->setText(QString("k核[0,%1]").arg(QString::number(maxCore+1)));
}
