#pragma once
#include <QString>
#include "GgsGraphProxy.h"

class GgsGraphProxy;
class GgsGraphStatistic
{
public:

	static const QString LABEL_STAT_DEGREE_CENTRALITY; // 度中心性
	static const QString LABEL_STAT_BETWEENNESS_CENTRALITY; // 介数中心性
	static const QString LABEL_STAT_CLOSENESS_CENTRALITY; // 接近中心性
	static const QString LABEL_STAT_EIGENVECTOR_CENTRALITY; // 特征向量中心性

	GgsGraphStatistic(QList<GgsGraphProxy*> graphs,
		QStringList labelNames, 
		QStringList pointSymbols,
		QStringList lineSymbols,
		QStringList colors,
		QStringList opacities
	);
	virtual ~GgsGraphStatistic();

	void statistic(bool bCoverData = false);

private:
	QList<GgsGraphProxy*> mGraphs;
	QStringList mLabelNames;
	QStringList mPointSymbols;
	QStringList mLineSymbols;
	QStringList mColors;
	QStringList mOpacities;
};
