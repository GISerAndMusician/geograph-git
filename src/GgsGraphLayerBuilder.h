#pragma once
#include <QMap>
#include <QProgressBar>
#include "qgsvectorlayer.h"

class QgsCoordinateReferenceSystem;
class GgsGraphProxy;

class GgsGraphLayerBuilder
{
public:
	GgsGraphLayerBuilder();
	~GgsGraphLayerBuilder();

	static void buildNodeLayer(
		GgsGraphProxy* graphProxy,
		const QMap<QString, QStringList>& data,
		const QString& XLabel,
		const QString& YLabel,
		const QString& IDLabel,
		const QStringList& fieldLabels,
		QMap<QString, QgsFeatureId>& idMap,
		QProgressBar* progressBar = nullptr
	);

	static void buildEdgeLayer(
		GgsGraphProxy* graphProxy,
		const QMap<QString, QStringList>& data,
		const QMap<QString, QgsFeatureId>& idMap,
		const QString& sourceLabel,
		const QString& targetLabel,
		const QStringList& fieldLabels,
		QProgressBar* progressBar = nullptr
	);

	// 判断属性值是否为数值
	static bool isNumber(const QString& d);

	static QString buildFieldPropertyString(const QMap<QString, QStringList>& data);

	static QgsFields buildFields(const QMap<QString, QStringList>& data);
};

