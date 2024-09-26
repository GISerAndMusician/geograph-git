#include "GgsGraphStatistic.h"

#include "GgsPython.h"

const QString GgsGraphStatistic::LABEL_STAT_DEGREE_CENTRALITY = "LABEL_STAT_DEGREE_CENTRALITY"; // 度中心性
const QString GgsGraphStatistic::LABEL_STAT_BETWEENNESS_CENTRALITY = "LABEL_STAT_BETWEENNESS_CENTRALITY"; // 介数中心性
const QString GgsGraphStatistic::LABEL_STAT_CLOSENESS_CENTRALITY = "LABEL_STAT_CLOSENESS_CENTRALITY"; // 接近中心性
const QString GgsGraphStatistic::LABEL_STAT_EIGENVECTOR_CENTRALITY = "LABEL_STAT_EIGENVECTOR_CENTRALITY"; // 特征向量中心性

GgsGraphStatistic::GgsGraphStatistic(QList<GgsGraphProxy*> graphs,
	QStringList labelNames,
	QStringList pointSymbols,
	QStringList lineSymbols,
	QStringList colors,
	QStringList opacities
	):
	mGraphs(graphs),
	mLabelNames(labelNames),
    mPointSymbols(pointSymbols),
    mLineSymbols(lineSymbols),
    mColors(colors),
    mOpacities(opacities)
{
	
}

GgsGraphStatistic::~GgsGraphStatistic()
{

}

void GgsGraphStatistic::statistic(bool bCoverData)
{
	QStringList graphs_nodes, graphs_edges;
	for each (GgsGraphProxy* graph in mGraphs)
	{
		QgsVectorLayer* pNodeLayer = graph->nodeLayerProxy()->nodeLayer();
		QgsVectorLayer* pEdgeLayer = graph->edgeLayerProxy()->edgeLayer();

		if (bCoverData)
		{
			pNodeLayer->startEditing();

			// 添加属性字段
			QgsFields fields = pNodeLayer->fields();
			if (!fields.names().contains(LABEL_STAT_DEGREE_CENTRALITY))
			{
				QgsField field(LABEL_STAT_DEGREE_CENTRALITY, QVariant::Double);
				pNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
			}

			if (!fields.names().contains(LABEL_STAT_BETWEENNESS_CENTRALITY))
			{
				QgsField field(LABEL_STAT_BETWEENNESS_CENTRALITY, QVariant::Double);
				pNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
			}

			if (!fields.names().contains(LABEL_STAT_CLOSENESS_CENTRALITY))
			{
				QgsField field(LABEL_STAT_CLOSENESS_CENTRALITY, QVariant::Double);
				pNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
			}

			if (!fields.names().contains(LABEL_STAT_EIGENVECTOR_CENTRALITY))
			{
				QgsField field(LABEL_STAT_EIGENVECTOR_CENTRALITY, QVariant::Double);
				pNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
			}

			pNodeLayer->commitChanges(false);
		}

		QStringList nodesStringList;
		QList<GgsNodeProxy*> nodeProxys = graph->nodeLayerProxy()->nodes();
		for each (GgsNodeProxy* n in nodeProxys)
		{
			nodesStringList << QString::number(n->feature().id());
		}

		graphs_nodes << nodesStringList.join(",");

		QStringList edgesStringList;
		QList<GgsEdgeProxy*> edgeProxys = graph->edgeLayerProxy()->edges();
		for each (GgsEdgeProxy* e in edgeProxys)
		{
			edgesStringList << QString::number(e->fromNode()->feature().id())
				<< QString::number(e->toNode()->feature().id());
		}

		graphs_edges << edgesStringList.join(",");
	}

	GgsPython py;
	py.initialize("./python/graph/");
	PyObject* pModule = py.importModule("statistic");
	PyObject* pFunc = py.getFunction(pModule, "run");

	PyObject* pArgs = PyTuple_New(7);
	
	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", graphs_nodes.join("\n").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", graphs_edges.join("\n").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 2, Py_BuildValue("s", mLabelNames.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 3, Py_BuildValue("s", mPointSymbols.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 4, Py_BuildValue("s", mLineSymbols.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 5, Py_BuildValue("s", mColors.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 6, Py_BuildValue("s", mOpacities.join(",").toStdString().c_str()));

	
	PyObject* pResult = py.callFunction(pFunc, pArgs);

	if (!pResult)
	{
		PyErr_Print();
		return;
	}

	for (int i = 0; i < mGraphs.size(); i++)
	{
		GgsGraphProxy* graph = mGraphs[i];
		QgsVectorLayer* pNodeLayer = graph->nodeLayerProxy()->nodeLayer();
		QgsVectorLayer* pEdgeLayer = graph->edgeLayerProxy()->edgeLayer();

		PyObject* dc_list = PyTuple_GetItem(pResult, 0);
		PyObject* bc_list = PyTuple_GetItem(pResult, 1);
		PyObject* cc_list = PyTuple_GetItem(pResult, 2);
		PyObject* ec_list = PyTuple_GetItem(pResult, 3);

		if (bCoverData)
		{
			PyObject* dc = PyList_GetItem(dc_list, i);
			PyObject* bc = PyList_GetItem(bc_list, i);
			PyObject* cc = PyList_GetItem(cc_list, i);
			PyObject* ec = PyList_GetItem(ec_list, i);

			if (PyDict_Check(dc))
			{
				int iSize = PyDict_Size(dc);
				PyObject* pValue;
				PyObject* pKey;
				for (int i = 0; i < iSize; i++)
				{
					Py_ssize_t py_i = i;
					PyDict_Next(dc, &py_i, &pKey, &pValue);

					int key = -1;
					PyArg_Parse(pKey, "i", &key);
					double value = 0.0;
					PyArg_Parse(pValue, "d", &value);

					pNodeLayer->changeAttributeValue(key, pNodeLayer->fields().indexOf(LABEL_STAT_DEGREE_CENTRALITY), QVariant(value));
				}
			}

			if (PyDict_Check(bc))
			{
				int iSize = PyDict_Size(bc);
				PyObject* pValue;
				PyObject* pKey;
				for (int i = 0; i < iSize; i++)
				{
					Py_ssize_t py_i = i;
					PyDict_Next(bc, &py_i, &pKey, &pValue);

					int key = -1;
					PyArg_Parse(pKey, "i", &key);
					double value = 0.0;
					PyArg_Parse(pValue, "d", &value);

					pNodeLayer->changeAttributeValue(key, pNodeLayer->fields().indexOf(LABEL_STAT_BETWEENNESS_CENTRALITY), QVariant(value));
				}
			}

			if (PyDict_Check(cc))
			{
				int iSize = PyDict_Size(cc);
				PyObject* pValue;
				PyObject* pKey;
				for (int i = 0; i < iSize; i++)
				{
					Py_ssize_t py_i = i;
					PyDict_Next(cc, &py_i, &pKey, &pValue);

					int key = -1;
					PyArg_Parse(pKey, "i", &key);
					double value = 0.0;
					PyArg_Parse(pValue, "d", &value);

					pNodeLayer->changeAttributeValue(key, pNodeLayer->fields().indexOf(LABEL_STAT_CLOSENESS_CENTRALITY), QVariant(value));
				}
			}

			if (PyDict_Check(ec))
			{
				int iSize = PyDict_Size(ec);
				PyObject* pValue;
				PyObject* pKey;
				for (int i = 0; i < iSize; i++)
				{
					Py_ssize_t py_i = i;
					PyDict_Next(ec, &py_i, &pKey, &pValue);

					int key = -1;
					PyArg_Parse(pKey, "i", &key);
					double value = 0.0;
					PyArg_Parse(pValue, "d", &value);

					pNodeLayer->changeAttributeValue(key, pNodeLayer->fields().indexOf(LABEL_STAT_EIGENVECTOR_CENTRALITY), QVariant(value));
				}
			}

			pNodeLayer->commitChanges();
		}
	}

	

}
