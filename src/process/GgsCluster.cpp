#include "GgsCluster.h"
#include "GgsPython.h"

const QString GgsCluster::LABEL_CLUSTER_ID = "LABEL_CLUSTER_ID"; // 聚类标签

GgsCluster::GgsCluster(QgsVectorLayer* layer)
{
	mLayer = layer;
}

GgsCluster::~GgsCluster()
{

}

QgsVectorLayer* GgsCluster::cluster(int c)
{
	mLayer->startEditing();

	// 添加分类属性字段
	QgsField field(LABEL_CLUSTER_ID, QVariant::Int);
	mLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	mLayer->commitChanges(false);

	if (mLayer->geometryType() != QgsWkbTypes::GeometryType::PointGeometry)
	{
		return nullptr;
	}
	
	QStringList dataList;
	QgsFeatureIterator iter = mLayer->getFeatures();
	QgsFeature feature;
	int index = 0;
	QList<QgsFeatureId> tmpIds;
	while (iter.nextFeature(feature))
	{
		QgsPointXY pt = feature.geometry().asPoint();
		dataList << QString::number(index++) << QString::number(pt.x()) << QString::number(pt.y());

		tmpIds << feature.id();
	}
			
	QString data = dataList.join(",");
	
	GgsPython py;
	py.initialize("./python/cluster/");
	PyObject* pModule = py.importModule("kmeans");
	PyObject* pFunc = py.getFunction(pModule, "doKmeans");

	PyObject* pArgs = PyTuple_New(3);
	//const char* testData = "1,0.697,0.46,2,0.774,0.376,3,0.634,0.264,4,0.608,0.318,5,0.556,0.215,"
	//	"6, 0.403, 0.237, 7, 0.481, 0.149, 8, 0.437, 0.211, 9, 0.666, 0.091, 10, 0.243, 0.267,"
	//	"11, 0.245, 0.057, 12, 0.343, 0.099, 13, 0.639, 0.161, 14, 0.657, 0.198, 15, 0.36, 0.37,"
	//	"16, 0.593, 0.042, 17, 0.719, 0.103, 18, 0.359, 0.188, 19, 0.339, 0.241, 20, 0.282, 0.257,"
	//	"21, 0.748, 0.232, 22, 0.714, 0.346, 23, 0.483, 0.312, 24, 0.478, 0.437, 25, 0.525, 0.369,"
	//	"26, 0.751, 0.489, 27, 0.532, 0.472, 28, 0.473, 0.376, 29, 0.725, 0.445, 30, 0.446, 0.459";

	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", data.toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", c));
	PyTuple_SetItem(pArgs, 2, Py_BuildValue("b", true));

	PyObject* pResult = py.callFunction(pFunc, pArgs);
	PyObject* py_iter = PyObject_GetIter(pResult);

	if (!PyList_Check(pResult))
	{
		return mLayer;
	}
	
	int featurIndex = 0;
	while(true)
	{
		PyObject* next = PyIter_Next(py_iter);
		if (!next)
		{
			break;
		}
			
		int iCluster;		
		PyArg_Parse(next, "i", &iCluster);

		QgsFeatureId fid = tmpIds[featurIndex];
		QgsFeature feature = mLayer->getFeature(fid);
		
		mLayer->changeAttributeValue(fid, mLayer->fields().indexOf(LABEL_CLUSTER_ID), QVariant(iCluster));

		featurIndex++;
	}

	mLayer->commitChanges();

	return mLayer;
}
