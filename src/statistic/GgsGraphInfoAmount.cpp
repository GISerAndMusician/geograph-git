#include "GgsGraphInfoAmount.h"
#include <QMessageBox>
#include <QApplication>
#include "GgsEntropyWeight.h"
#include "GgsGraphStatistic.h"

const QString LABEL_STAT = "LABEL_STAT"; // �����ж�ͼ���Ƿ��Ѿ�������ͳ�Ʋ���
const QString LABEL_CLUSTER = "LABEL_CLUSTER"; // �����ж�ͼ���Ƿ��Ѿ������˾������

GgsGraphInfoAmount::GgsGraphInfoAmount(GgsGraphProxy* graph)
{
	mGraph = graph;
}

GgsGraphInfoAmount::~GgsGraphInfoAmount()
{

}

double GgsGraphInfoAmount::calcInfoAmount()
{
	/*QStringList nodesStringList;
	QList<GgsNodeProxy*> nodeProxys = mGraph->nodeLayerProxy()->nodes();
	for each (GgsNodeProxy* n in nodeProxys)
	{
		nodesStringList << QString::number(n->feature().id());
	}

	QStringList edgesStringList;
	QList<GgsEdgeProxy*> edgeProxys = mGraph->edgeLayerProxy()->edges();
	for each (GgsEdgeProxy* e in edgeProxys)
	{
		edgesStringList << QString::number(e->fromNode()->feature().id())
			<< QString::number(e->toNode()->feature().id());
	}

	GgsPython py;
	py.initialize("./python/graph/");
	PyObject* pModule = py.importModule("information");
	PyObject* pFunc = py.getFunction(pModule, "run");

	PyObject* pArgs = PyTuple_New(2);

	// ���ò���
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", nodesStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", edgesStringList.join(",").toStdString().c_str()));

	PyObject* pResult = py.callFunction(pFunc, pArgs);

	if (!pResult)
	{
		PyErr_Print();
		return 0;
	}

	double infoAmount = PyFloat_AsDouble(pResult);*/

	QgsFields fields = mGraph->nodeLayerProxy()->nodeLayer()->fields();

	if (!fields.names().filter(QRegExp(LABEL_STAT)).size())
	{
		QMessageBox::information(nullptr, QObject::tr("��ʾ"), QObject::tr("�ڽ��йǼ�����ȡǰ��ͼ������Ѿ������������ָ�꣡������ͨ��[ͳ��]-[��������ָ��ͳ��]���ܼ���������ָ�ꡣ"));
		return -1;
	}

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

	// 1*n Ȩ������
	MatrixXd V = W.transpose() * matrix;
	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	std::cout << V.format(HeavyFmt) << std::endl;

	// �ڵ���Ҫ��
	MatrixXd K(1, V.cols());
	for (int i = 0; i < V.cols(); i++)
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

			std::cout << "adj:" << adjIndex << std::endl;
			iter++;
		}

		K(0, i) = V(0, i) + adjV;

		std::cout << i << std::endl;
	}

	std::cout << K.format(HeavyFmt) << std::endl;

	double infoAmount = 0;
	iter_nodes = pNodeLayer->getFeatures();
	while (iter_nodes.nextFeature(nodeFeature))
	{
		int index = idIndex.indexOf(nodeFeature.id());
		double k = K(0, index);

		double n_information = k*1.0 / K.sum();

		infoAmount += -n_information * std::log(n_information);
	}
	return infoAmount;
}
