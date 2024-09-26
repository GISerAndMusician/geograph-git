#pragma once
#include <QDockWidget>
#include "ui_GgsFdebWidget.h"
#include "GgsGraphProxy.h"
#include "GgsFdebEdge.hpp"


class GgsFdebWidget: public QWidget, public Ui::GgsFDEBWidget
{
	Q_OBJECT
public:
	GgsFdebWidget(QWidget* parent = nullptr);
	~GgsFdebWidget();

public slots:
	void refreshGraphProxys(GgsGraphProxy* graphProxy);

private:
	void initComboBox();
	void initUiValues();

	void createVectorLayer(std::vector<GgsFdebEdge> edges, GgsGraphProxy* graphProxy);

private slots:
	void run();

private:
	double mCoordScale = 10.0;
	double mK = 0.1;
	int mCycles = 5;
	int mI = 90;
	double mCompat = 0.6;
	double mSignma = 3.0;
	double mEdgeWeight = -0.1;
	double mEdgePercentage = -0.1;
	double mS = 2.4;
	double mEpsilon = 0.0001;
	double mGravityExponent = 1.0;
};

