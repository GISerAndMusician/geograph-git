#include "GgsConvexHullDialog.h"
#include "qgsproject.h"
#include "qgsmaplayer.h"
#include "qgsvectorlayer.h"
#include "GgsConvexHull.h"
#include "GgsPython.h"

#pragma execution_character_set("utf-8") 

const QString ALPHA_SHAPE = "Alpha Shape";
const QString GRAHANM_SCAN = "Grahanm's Scan";

GgsConvexHullDialog::GgsConvexHullDialog(QWidget* parent /*= nullptr*/)
	:QDialog(parent)
{
	setupUi(this);
	initComboBox();
	connect(this->pushButtonOK, &QPushButton::clicked, this, &GgsConvexHullDialog::onOK);
	connect(this->pushButtonCancel, &QPushButton::clicked, this, &QDialog::accepted);
	connect(this->comboBoxAlgo, SIGNAL(currentIndexChanged(int)), this, SLOT(onAlgoChanged(int)));
}

GgsConvexHullDialog::~GgsConvexHullDialog()
{

}

void GgsConvexHullDialog::onOK()
{
	QgsVectorLayer* pCurrentLayer = comboBox->currentData(Qt::UserRole).value<QgsVectorLayer*>();
	if (pCurrentLayer)
	{
		QgsFeatureIterator iter =  pCurrentLayer->getFeatures();
		QgsFeature featrue;
		QVector<QgsPointXY> pts;
		while (iter.nextFeature(featrue))
		{
			QgsPointXY pt = featrue.geometry().asPoint();
			pts << pt;
		}

		// 创建图层
		QString convexHullLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
			arg("Polygon").
			arg(pCurrentLayer->crs().authid()).
			arg(QUuid::createUuid().toString());    // 几何类型

		QgsVectorLayer* pConvexHullLayer = new QgsVectorLayer(
			convexHullLayerProperties,
			pCurrentLayer->name() + "-" + "凸包",
			"memory");

		QList< QgsMapLayer * > layers;
		layers << pConvexHullLayer;
		QgsProject::instance()->addMapLayers(layers);

		QString algo = comboBoxAlgo->currentText();
		pConvexHullLayer->startEditing();
		if (algo == GRAHANM_SCAN)
		{
			QVector<QgsPointXY> convexHullPts = convexHull(pts);
			QgsPolylineXY polyline(convexHullPts);
			polyline << convexHullPts.first();
			QgsPolygonXY polygon;
			polygon.append(polyline);
			QgsFeature newFeature;
			newFeature.setGeometry(QgsGeometry::fromPolygonXY(polygon));

			pConvexHullLayer->dataProvider()->addFeature(newFeature);
		}else if (algo == ALPHA_SHAPE)
		{
			QgsMultiPolygonXY multiPolygon = convexHullByAlphShape(pts);
			
			QgsFeature newFeature;
			newFeature.setGeometry(QgsGeometry::fromMultiPolygonXY(multiPolygon));
			pConvexHullLayer->dataProvider()->addFeature(newFeature);
			/*for each (QgsPolylineXY edge in edges)
			{
				QgsFeature newFeature;
				newFeature.setGeometry(QgsGeometry::fromPolylineXY(edge));

				pConvexHullLayer->dataProvider()->addFeature(newFeature);
			}*/
		}		

		pConvexHullLayer->commitChanges();

		pConvexHullLayer->updateExtents();
	}

	this->accept();
}

void GgsConvexHullDialog::onAlgoChanged(int index)
{
	if (this->comboBoxAlgo->itemText(index) != ALPHA_SHAPE)
	{
		this->doubleSpinBox_alpha->setEnabled(false);
	}
	else {
		this->doubleSpinBox_alpha->setEnabled(true);
	}
}

void GgsConvexHullDialog::initComboBox()
{
	QList<QgsMapLayer*> layers = QgsProject::instance()->mapLayers().values();
	for each (QgsMapLayer* layer in layers)
	{
		QgsVectorLayer* vectorLayer = dynamic_cast<QgsVectorLayer*>(layer);
		if (!vectorLayer)
		{
			continue;
		}

		if (vectorLayer->geometryType() == QgsWkbTypes::GeometryType::PointGeometry)
		{
			this->comboBox->insertItem(0, vectorLayer->name(), QVariant::fromValue(vectorLayer));
		}
	}

	comboBoxAlgo->insertItem(0, ALPHA_SHAPE);
	comboBoxAlgo->insertItem(1, GRAHANM_SCAN);
}

QgsMultiPolygonXY GgsConvexHullDialog::convexHullByAlphShape(QVector<QgsPointXY> pts)
{
	QStringList mCoordStringList;

	for each (QgsPointXY pt in pts)
	{
		mCoordStringList << QString::number(pt.x()) << QString::number(pt.y());
	}

	GgsPython mPy;
	PyObject* mModule = nullptr;

	mPy.initialize("./python/graph/");
	mModule = mPy.importModule("AlphaShape");

	PyObject* pFunc = mPy.getFunction(mModule, "run");

	PyObject* pArgs = PyTuple_New(2);
	// 设置参数
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", mCoordStringList.join(",").toStdString().c_str()));
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("d", this->doubleSpinBox_alpha->value()));

	PyObject* pResult = mPy.callFunction(pFunc, pArgs);

	if (!pResult)
	{
		PyErr_Print();
		this->accept();
		return QgsMultiPolygonXY();
	}

	QgsMultiPolygonXY multiPolygon;
	int iPolygonCount =  PyList_Size(pResult);
	for (int i=0 ;i< iPolygonCount; i++)
	{
		QgsPolygonXY polygon;
		PyObject* item =  PyList_GetItem(pResult, i);

		int iPointsCount = PyList_Size(item);
		QgsPolylineXY polyline;
		for (int j=0; j< iPointsCount; j++)
		{
			PyObject* pt = PyList_GetItem(item, j);
			PyObject* pX = PyTuple_GetItem(pt, 0);
			PyObject* pY = PyTuple_GetItem(pt, 1);

			double x = PyFloat_AsDouble(pX);
			double y = PyFloat_AsDouble(pY);

			polyline.append(QgsPointXY(x, y));
		}
		polygon.append(polyline);
		multiPolygon.append(polygon);
	}

	return multiPolygon;
}
