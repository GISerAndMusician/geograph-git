#pragma once
#include "GgsGraphProxy.h"
#include <Eigen/Dense>

using namespace Eigen;

class GgsBackbone
{
public:
	enum Method
	{
		Entropy,
		Degree,
		BetweenessCentrality,
		ClosenessCentrality,
		EigenvectorCentrality
	};

	GgsBackbone(GgsGraphProxy* pGraph);

	GgsGraphProxy* create(Method m, double rate);

	GgsGraphProxy* createByEntropy(double rate);
	GgsGraphProxy* createByDegree(double rate);
	GgsGraphProxy* createByBetweenessCentrality(double rate);
	GgsGraphProxy* createByClosenessCentrality(double rate);
	GgsGraphProxy* createByEigenvectorCentrality(double rate);

	void setProgressBar(QProgressBar* progressBar) { mProgressBar = progressBar; };

	QString getAlgoName(Method method);

private:
	GgsGraphProxy* copyGraph(QString suffix);

	double backbone(
		int &iVV,
		int &iEE,
		QMap<QString, QList<QgsFeature>> clusterMap, 
		QList<QgsFeatureId> idIndex, 
		MatrixXd K,double rate, 
		GgsGraphProxy* copy,
		int step = 0);

	bool isBridge(const QgsFeature& feature);

private:
	GgsGraphProxy* mGraph;
	QProgressBar* mProgressBar = nullptr;
};