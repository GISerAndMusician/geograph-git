#pragma once
#include <QWidget>
#include "qgscolorramp.h"
#include "ui_GgsMingleWidget.h"
#include "GgsMingleBundler.h"
#include "GgsGraphProxy.h"

class GgsMingleWidget: public QWidget, Ui::GgsMingleWidget
{
	Q_OBJECT
public:

	GgsMingleWidget(QWidget* parent = nullptr);
	~GgsMingleWidget();

public slots:
	void refreshGraphProxys(GgsGraphProxy* graphProxy);

private slots:
	void run();
	void onProgressChanged(int iter, int current, int total);
	void onCurrentProxyChanged(int index);
	void toggleMargin(int checkState);
	void updateDeltaUiText(int value);
	void updateCurvenessUiText(int value);
	void updateAlphaUiText(int value);
	void toggleLoose(int index);

private:
	void initComboBox();
	void initUiValues();
	void initRenderComboBox();

private:
	QMap<QUuid, QList<QVariant>> mWidgetParams; // 键是代理图层的Uuid，界面参数
	QgsRandomColorRamp mRandomColorRamp;
};

