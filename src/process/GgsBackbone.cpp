#include "GgsBackbone.h"
#include "GgsGraphStatistic.h"
#include "GgsCluster.h"
#include <QMessageBox>
#include <QApplication>
#include "GgsEntropyWeight.h"
#include "GgsGraphProject.h"
#include "GgsPython.h"

#pragma execution_character_set("utf-8") 

const QString LABEL_STAT = "LABEL_STAT"; // 用于判断图层是否已经进行了统计操作
const QString LABEL_CLUSTER = "LABEL_CLUSTER"; // 用于判断图层是否已经进行了聚类操作

GgsBackbone::GgsBackbone(GgsGraphProxy* pGraph)
{
	mGraph = pGraph;
}

GgsGraphProxy* GgsBackbone::create(Method m, double rate)
{
	if (m == Entropy)
	{
		return this->createByEntropy(rate);
	}
	else if (m == Degree) {
		return this->createByDegree(rate);
	}else if (m == BetweenessCentrality)
	{
		return this->createByBetweenessCentrality(rate);
	}else if (m == ClosenessCentrality)
	{
		return this->createByClosenessCentrality(rate);
	}else if (m == EigenvectorCentrality)
	{
		return this->createByEigenvectorCentrality(rate);
	}
		return nullptr;
}

GgsGraphProxy* GgsBackbone::createByEntropy(double rate)
{
	QgsFields fields = mGraph->nodeLayerProxy()->nodeLayer()->fields();

	if (!fields.names().filter(QRegExp(LABEL_STAT)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("提示"), QObject::tr("在进行骨架线提取前，图层必须已经计算过中心性指标！您可以通过[统计]-[复杂网络指标统计]功能计算中心性指标。"));
		return false;
	}

	if (!fields.names().filter(QRegExp(LABEL_CLUSTER)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("提示"), QObject::tr("在进行骨架线提取前，图层必须已经进行了聚类处理！您可以通过[处理]-[聚类]功能实现图层聚类。"));
		return false;
	}

// 	GgsGraphProxy* copy = copyGraph(QString("-entropy-%1%").arg(int(rate * 100)));
// 
// 	if (!copy)
// 	{
// 		return nullptr;
// 	}

	QgsVectorLayer* pNodeLayer = mGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = mGraph->edgeLayerProxy()->edgeLayer();

	QgsFeatureIterator iter_nodes = pNodeLayer->getFeatures();
	QgsFeature nodeFeature;

	QMap<QString, QList<QgsFeature>> clusterMap;
	QList<QgsFeatureId> idIndex;
	// 4*n
	MatrixXd matrix(4, pNodeLayer->featureCount());
	int index = 0;
	while (iter_nodes.nextFeature(nodeFeature))
	{
		QString clusterid = nodeFeature.attribute(GgsCluster::LABEL_CLUSTER_ID).toString();

		if (!clusterMap.contains(clusterid))
		{
			clusterMap.insert(clusterid, QList<QgsFeature>() << nodeFeature);
		}
		else {
			clusterMap[clusterid].append(nodeFeature);
		}

		matrix(0, index) = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_DEGREE_CENTRALITY).toDouble();
		matrix(1, index) = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_BETWEENNESS_CENTRALITY).toDouble();
		matrix(2, index) = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_CLOSENESS_CENTRALITY).toDouble();
		matrix(3, index) = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_EIGENVECTOR_CENTRALITY).toDouble();

		idIndex << nodeFeature.id();
		index++;
	}

	// 4*1
	MatrixXd W = GgsEntropyWeight::calculate(matrix);

	double w1 = W(0, 0);
	double w2 = W(1, 0);
	double w3 = W(2, 0);
	double w4 = W(3, 0);

	// 1*n 权重因子
	MatrixXd V = W.transpose() * matrix;
	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	std::cout << V.format(HeavyFmt) << std::endl;

	// 节点重要性
	MatrixXd K(1, V.cols());
	for (int i=0; i< V.cols(); i++)
	{
		double adjV = 0;

		QgsFeatureId fid = idIndex[i];
		GgsNodeProxy* nodeProxy = mGraph->nodeLayerProxy()->findNode(fid);
		
		ogdf::List<ogdf::edge> elist;
		nodeProxy->node()->adjEdges(elist);
		ogdf::List<ogdf::edge>::iterator iter = elist.begin();
		while (iter != elist.end())
		{
			ogdf::edge edge = *iter;
			GgsEdgeProxy* edgeProxy = mGraph->edgeLayerProxy()->findEgde(edge);

			int adjIndex = -1;
			QgsFeatureId adjFid;
			if (edgeProxy->fromNode() == nodeProxy)
			{
				adjFid = edgeProxy->toNode()->feature().id();
			}
			else if (edgeProxy->toNode() == nodeProxy)
			{
				adjFid = edgeProxy->toNode()->feature().id();
			}

			adjIndex = idIndex.indexOf(fid);
			adjV += V(0, adjIndex);

			std::cout << "adj:"  << adjIndex << std::endl;
			iter++;
		}
		
		K(0, i) = V(0, i) + adjV;

		std::cout << i << std::endl;
	}

	std::cout << K.format(HeavyFmt) << std::endl;

	std::cout << "copying..." << std::endl;
	GgsGraphProxy* copy = copyGraph(QString("-entropy-%1%").arg(int(rate * 100)));

	if (!copy)
	{
		return nullptr;
	}

	/*
	// 计算综合压缩比（论文绘图使用，后续可以删除）
	int iVV, iEE;
	double iRR = backbone(iVV, iEE, clusterMap, idIndex, K, rate, copy);;
	
	int times = 1;
	int step = 0;
	QList<QPair<int, double>> R_Map;
	R_Map.append(QPair<int, double>(times, iRR));

	QStringList VVStr, EEStr;
	VVStr.append(QString::number(iVV));
	EEStr.append(QString::number(iEE));
	while (abs(iRR - (1- rate)) > 0.0001)
	{
		if (R_Map.size() >= 2)
		{
			if ((R_Map.last().second > (1 - rate) && R_Map[R_Map.size() - 2].second < (1 - rate)) ||
				(R_Map.last().second < (1 - rate) && R_Map[R_Map.size() - 2].second >(1 - rate))
				)
			{
				break;
			}
		}

		if (iRR < (1 - rate))
		{
			iRR = backbone(iVV, iEE, clusterMap, idIndex, K, rate, copy, --step);
		}
		else {
			iRR = backbone(iVV, iEE, clusterMap, idIndex, K, rate, copy, ++step);
		}

		times++;
		R_Map.append(QPair<int, double>(times, iRR));
		VVStr.append(QString::number(iVV));
		EEStr.append(QString::number(iEE));
	}
	
	QFile file("D:\\文档\\02_论文\\发表论文\\《一种顾及空间分布特征的大规模空间交互网络骨架提取方法》\\resource\\regression\\data.txt");
	if (!file.open(QIODevice::WriteOnly)) {
		qWarning("Cannot open file for writing.");
		return copy;
	}

	QStringList X;
	QStringList R;
	for each (QPair<int, double> v in R_Map)
	{
		X << QString::number(v.first);
		R << QString::number(v.second);
	}

	QTextStream textStream(&file);
	textStream << X.join(",") << endl;
	textStream << VVStr.join(",") << endl;
	textStream << EEStr.join(",") << endl;
	textStream << R.join(",") << endl;

	file.close();*/

	// 按照聚类簇进行骨架提取（不考虑桥边节点）
	QMap<QString, QList<QgsFeature>>::iterator mapIter = clusterMap.begin();
	QgsFeatureIds remains;
	while (mapIter != clusterMap.end())
	{
		QString clusterid = mapIter.key();
		QList<QgsFeature> features = mapIter.value();

		QList<QPair<QgsFeatureId, double>> tmp;
		for each (QgsFeature feature in features)
		{
			int index = idIndex.indexOf(feature.id());
			double k = K(0, index);
			tmp.push_back(QPair<QgsFeatureId, double>(feature.id(), k));
		}

		std::sort(tmp.begin(), tmp.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
			return a.second > b.second;
		});

		int iCount = round(rate * tmp.size());

		for (int i=0; i<iCount; i++)
		{
			remains << tmp.at(i).first;
		}

		mapIter++;
	}
	
	// 按照聚类簇进行骨架提取（考虑桥边节点）
	/*QMap<QString, QList<QgsFeature>>::iterator mapIter = clusterMap.begin();
	QgsFeatureIds remains;
	while (mapIter != clusterMap.end())
	{
		QString clusterid = mapIter.key();
		QList<QgsFeature> features = mapIter.value();

		QList<QPair<QgsFeatureId, double>> tmp;
		QList<QPair<QgsFeatureId, double>> tmp_bridge;
		for each (QgsFeature feature in features)
		{
			int index = idIndex.indexOf(feature.id());
			double k = K(0, index);
			if (isBridge(feature))
			{
				tmp_bridge.push_back(QPair<QgsFeatureId, double>(feature.id(), k));
			}else
				tmp.push_back(QPair<QgsFeatureId, double>(feature.id(), k));
		}

		std::sort(tmp.begin(), tmp.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
			return a.second > b.second;
		});

		std::sort(tmp_bridge.begin(), tmp_bridge.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
			return a.second > b.second;
		});

		int iCount = round(rate * tmp.size());
		int iCount_bridge = round(rate * tmp_bridge.size());
		for (int i=0; i<iCount; i++)
		{
			remains << tmp.at(i).first;
		}
		for (int i=0; i<iCount_bridge; i++)
		{
			remains << tmp_bridge.at(i).first;
		}

		mapIter++;
	}*/

	QList<GgsNodeProxy*> nodeList = copy->nodeLayerProxy()->nodes();
	if (mProgressBar)
	{
		mProgressBar->setRange(0, nodeList.size() - 1);
		mProgressBar->setFormat(QObject::tr("正在过滤要素...%p%"));
	}
	for (int i=0; i<nodeList.size(); i++)
	{
		GgsNodeProxy* nodeProxy = nodeList[i];
		if (!remains.contains(nodeProxy->feature().id()))
		{
			copy->removeNodeProxy(nodeProxy);

			QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
			if (mProgressBar)
				mProgressBar->setValue(i);
		}
	}

	return copy;
}

bool GgsBackbone::isBridge(const QgsFeature& feature)
{
	ogdf::List<ogdf::edge> elist;
	mGraph->nodeLayerProxy()->findNode(feature.id())->node()->adjEdges(elist);

	for (int i=0; i<elist.size(); i++)
	{
		ogdf::edge e = *elist.get(i);
		GgsEdgeProxy* edgeProxy = mGraph->edgeLayerProxy()->findEgde(e);

		QgsFeature sourceFeature = edgeProxy->fromNode()->feature(mGraph->nodeLayerProxy()->nodeLayer());
		QgsFeature targetFeature = edgeProxy->toNode()->feature(mGraph->nodeLayerProxy()->nodeLayer());
		if (sourceFeature.attribute(GgsCluster::LABEL_CLUSTER_ID).toString() !=
			targetFeature.attribute(GgsCluster::LABEL_CLUSTER_ID).toString())
		{
			return true;
		}
	}
	return false;
}

GgsGraphProxy* GgsBackbone::createByDegree(double rate)
{
	GgsGraphProxy* copy = copyGraph(QString("-Degree-%1%").arg(int(rate * 100)));

	if (!copy)
	{
		return nullptr;
	}

	QList<GgsNodeProxy*> nodes = copy->nodeLayerProxy()->nodes();
	std::sort(nodes.begin(), nodes.end(), [](GgsNodeProxy* a, GgsNodeProxy* b) {
		return a->node()->degree() < b->node()->degree();
	});

	int iCount = round((1- rate) * nodes.size());
	if (mProgressBar)
	{
		mProgressBar->setRange(0, iCount - 1);
		mProgressBar->setFormat(QObject::tr("正在过滤要素...%p%"));
	}
	for (int i=0; i<iCount; i++)
	{
		GgsNodeProxy* nodeProxy = nodes[i];
		copy->removeNodeProxy(nodeProxy);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (mProgressBar)
			mProgressBar->setValue(i);
	}

	return copy;
}

GgsGraphProxy* GgsBackbone::createByBetweenessCentrality(double rate)
{
	QgsFields fields =  mGraph->nodeLayerProxy()->nodeLayer()->fields();

	if (!fields.names().filter(QRegExp(LABEL_STAT)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("提示"), QObject::tr("在进行骨架线提取前，图层必须已经计算过中心性指标！您可以通过[统计]-[复杂网络指标统计]功能计算中心性指标。"));
		return nullptr;
	}

	GgsGraphProxy* copy = copyGraph(QString("-Betweeness-%1%").arg(int(rate * 100)));

	if (!copy)
	{
		return nullptr;
	}

	QgsVectorLayer* pNodeLayer = copy->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = copy->edgeLayerProxy()->edgeLayer();

	QgsFeatureIterator iter_nodes = pNodeLayer->getFeatures();
	QgsFeature nodeFeature;
	QList<QPair<QgsFeatureId, double>> bcList;
	while (iter_nodes.nextFeature(nodeFeature))
	{
		double bc = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_BETWEENNESS_CENTRALITY).toDouble();
		bcList.append(QPair<QgsFeatureId, double>(nodeFeature.id(), bc));
	}

	std::sort(bcList.begin(), bcList.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
		return a.second < b.second;
	});

	int iCount = round((1- rate) * bcList.size());
	if (mProgressBar)
	{
		mProgressBar->setRange(0, iCount - 1);
		mProgressBar->setFormat(QObject::tr("正在过滤要素...%p%"));
	}
	for (int i=0; i<iCount; i++)
	{
		QgsFeatureId featureid = bcList[i].first;
		GgsNodeProxy* node = copy->nodeLayerProxy()->findNode(featureid);
		copy->removeNodeProxy(node);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (mProgressBar)
			mProgressBar->setValue(i);
	}

	return copy;
}

GgsGraphProxy* GgsBackbone::createByClosenessCentrality(double rate)
{
	QgsFields fields = mGraph->nodeLayerProxy()->nodeLayer()->fields();

	if (!fields.names().filter(QRegExp(LABEL_STAT)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("提示"), QObject::tr("在进行骨架线提取前，图层必须已经计算过中心性指标！您可以通过[统计]-[复杂网络指标统计]功能计算中心性指标。"));
		return nullptr;
	}

	GgsGraphProxy* copy = copyGraph(QString("-Closeness-%1%").arg(int(rate * 100)));

	if (!copy)
	{
		return nullptr;
	}

	QgsVectorLayer* pNodeLayer = copy->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = copy->edgeLayerProxy()->edgeLayer();

	QgsFeatureIterator iter_nodes = pNodeLayer->getFeatures();
	QgsFeature nodeFeature;
	QList<QPair<QgsFeatureId, double>> bcList;
	while (iter_nodes.nextFeature(nodeFeature))
	{
		double bc = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_CLOSENESS_CENTRALITY).toDouble();
		bcList.append(QPair<QgsFeatureId, double>(nodeFeature.id(), bc));
	}

	std::sort(bcList.begin(), bcList.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
		return a.second < b.second;
	});

	int iCount = round((1 - rate) * bcList.size());
	if (mProgressBar)
	{
		mProgressBar->setRange(0, iCount - 1);
		mProgressBar->setFormat(QObject::tr("正在过滤要素...%p%"));
	}
	for (int i = 0; i < iCount; i++)
	{
		QgsFeatureId featureid = bcList[i].first;
		GgsNodeProxy* node = copy->nodeLayerProxy()->findNode(featureid);
		copy->removeNodeProxy(node);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (mProgressBar)
			mProgressBar->setValue(i);
	}

	return copy;
}

GgsGraphProxy* GgsBackbone::createByEigenvectorCentrality(double rate)
{
	QgsFields fields = mGraph->nodeLayerProxy()->nodeLayer()->fields();

	if (!fields.names().filter(QRegExp(LABEL_STAT)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("提示"), QObject::tr("在进行骨架线提取前，图层必须已经计算过中心性指标！您可以通过[统计]-[复杂网络指标统计]功能计算中心性指标。"));
		return nullptr;
	}

	GgsGraphProxy* copy = copyGraph(QString("-Eigenvector-%1%").arg(int(rate * 100)));

	if (!copy)
	{
		return nullptr;
	}

	QgsVectorLayer* pNodeLayer = copy->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = copy->edgeLayerProxy()->edgeLayer();

	QgsFeatureIterator iter_nodes = pNodeLayer->getFeatures();
	QgsFeature nodeFeature;
	QList<QPair<QgsFeatureId, double>> bcList;
	while (iter_nodes.nextFeature(nodeFeature))
	{
		double bc = nodeFeature.attribute(GgsGraphStatistic::LABEL_STAT_EIGENVECTOR_CENTRALITY).toDouble();
		bcList.append(QPair<QgsFeatureId, double>(nodeFeature.id(), bc));
	}

	std::sort(bcList.begin(), bcList.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
		return a.second < b.second;
	});

	int iCount = round((1 - rate) * bcList.size());
	if (mProgressBar)
	{
		mProgressBar->setRange(0, iCount - 1);
		mProgressBar->setFormat(QObject::tr("正在过滤要素...%p%"));
	}
	for (int i = 0; i < iCount; i++)
	{
		QgsFeatureId featureid = bcList[i].first;
		GgsNodeProxy* node = copy->nodeLayerProxy()->findNode(featureid);
		copy->removeNodeProxy(node);

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (mProgressBar)
			mProgressBar->setValue(i);
	}

	return copy;
}

QString GgsBackbone::getAlgoName(Method method)
{
	switch (method)
	{
	case GgsBackbone::Entropy:
		return "Entropy";
	case GgsBackbone::Degree:
		return "Degree";
	case GgsBackbone::BetweenessCentrality:
		return "BetweenessCentrality";
	case GgsBackbone::ClosenessCentrality:
		return "ClosenessCentrality";
	case GgsBackbone::EigenvectorCentrality:
		return "EigenvectorCentrality";
	default:
		return "";
	}
}

GgsGraphProxy* GgsBackbone::copyGraph(QString suffix)
{
	GgsGraphProxy* copy = mGraph->clone(mProgressBar);
	copy->setName(copy->getName() + suffix);
	QgsVectorLayer* copyNodeLayer = copy->nodeLayerProxy()->nodeLayer();
	copyNodeLayer->setName(copyNodeLayer->name() + suffix);
	QgsVectorLayer* copyEdgeLayer = copy->edgeLayerProxy()->edgeLayer();
	copyEdgeLayer->setName(copyEdgeLayer->name() + suffix);

	GgsGraphProject::instance()->addGraphProxy(copy);

	return copy;
}

double GgsBackbone::backbone(int &iVV,
	int &iEE, 
	QMap<QString, QList<QgsFeature>> clusterMap, 
	QList<QgsFeatureId> idIndex, 
	MatrixXd K, 
	double rate, 
	GgsGraphProxy* copy, 
	int step)
{
	// 按照聚类簇进行骨架提取
	QMap<QString, QList<QgsFeature>>::iterator mapIter = clusterMap.begin();
	QList<QPair<QgsFeatureId, double>> remains;

	QList<QPair<QgsFeatureId, double>> removed;
	while (mapIter != clusterMap.end())
	{
		QString clusterid = mapIter.key();
		QList<QgsFeature> features = mapIter.value();

		QList<QPair<QgsFeatureId, double>> tmp;
		for each (QgsFeature feature in features)
		{
			int index = idIndex.indexOf(feature.id());
			double k = K(0, index);
			tmp.push_back(QPair<QgsFeatureId, double>(feature.id(), k));
		}

		std::sort(tmp.begin(), tmp.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
			return a.second > b.second;
		});

		int iCount = round(rate * tmp.size());
		for (int i = 0; i < iCount; i++)
		{
			remains << tmp.at(i);
		}
		for (int i=iCount; i<tmp.size(); i++)
		{
			removed << tmp.at(i);
		}

		mapIter++;
	}

	std::sort(remains.begin(), remains.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
		return a.second > b.second;
	});
	std::sort(removed.begin(), removed.end(), [](QPair<QgsFeatureId, double> a, QPair<QgsFeatureId, double> b) {
		return a.second > b.second;
	});

	if (step > 0)
	{
		for (int i=0; i<step;i++)
		{
			remains.append(removed.at(i));
		}
	}
	else {
		for (int i=0; i<abs(step); i++)
		{
			remains.removeLast();
		}
	}

	// 获取子图
	GgsPython mPy;
	mPy.initialize("./python/graph/");
	PyObject* mModule = nullptr;
	mModule = mPy.importModule("subgraph");

	QgsVectorLayer* pNodeLayer = mGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = mGraph->edgeLayerProxy()->edgeLayer();

	QList<GgsNodeProxy*> nodeProxys = mGraph->nodeLayerProxy()->nodes();
	QStringList mNodesStringList;
	for each (GgsNodeProxy* n in nodeProxys)
	{
		mNodesStringList << QString::number(n->feature().id());
	}

	QList<GgsEdgeProxy*> edgeProxys = mGraph->edgeLayerProxy()->edges();
	QStringList mEdgesStringList;
	for each (GgsEdgeProxy* e in edgeProxys)
	{
		mEdgesStringList << QString::number(e->fromNode()->feature().id())
			<< QString::number(e->toNode()->feature().id());
	}

	QStringList subNodesStringList;
	for each (QPair<QgsFeatureId, double> item in remains)
	{
		subNodesStringList << QString::number(item.first);
	}

	PyObject* pFunc = mPy.getFunction(mModule, "run");

	PyObject* pArgs = PyTuple_New(3);

	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", mNodesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", mEdgesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 2, Py_BuildValue("s", subNodesStringList.join(",").toStdString().c_str()));

	PyObject* pResult = mPy.callFunction(pFunc, pArgs);

	PyObject* pRR = PyTuple_GetItem(pResult, 0);
	double d = PyFloat_AsDouble(pRR);
	PyObject* pVV = PyTuple_GetItem(pResult, 1);
	iVV = PyLong_AsLong(pVV);
	PyObject* pEE = PyTuple_GetItem(pResult, 2);
	iEE = PyLong_AsLong(pEE);

	return d;
}



