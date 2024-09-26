#pragma once
#include "qgsvectorlayer.h"

class GgsCluster
{
public:
	static const QString LABEL_CLUSTER_ID; // �����ǩ

	GgsCluster(QgsVectorLayer* layer);
	virtual ~GgsCluster();

	QgsVectorLayer* cluster(int c);

private:
	QgsVectorLayer* mLayer = nullptr;
};

