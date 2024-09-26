#pragma once
#include <QWidget>
#include "ui_GgsKdeebWidget.h"

#include "qgsmapcanvas.h"
#include "GgsGraphProxy.h"

class GgsKdeebWidget: public QWidget, public Ui::GgsKdeebWidget
{
	Q_OBJECT

public:
	GgsKdeebWidget(QgsMapCanvas* mapCanvas, QWidget* parent = nullptr);
	~GgsKdeebWidget();

public slots:
	void refreshGraphProxys(GgsGraphProxy* graphProxy);

private slots:
	void run();
	void updateProgress(int current, int total);

private:
	void initComboBox();

private:
	QgsMapCanvas* mMapCanvas;
};

