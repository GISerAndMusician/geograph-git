#pragma once
#include <QWidget>
#include "ui_GgsGraphLegendWidget.h"

class GgsGraphProxy;

class GgsGraphLegendWidget: public QWidget, public Ui::GgsGraphLegendWidget
{
	Q_OBJECT

public:
	GgsGraphLegendWidget(QWidget* parent = 0);
	~GgsGraphLegendWidget();

public:
	void removeGraphLayer(GgsGraphProxy* pGraph);

private slots:
	void onGraphLayerAdded(GgsGraphProxy* graph);
 	void onItemChanged(QListWidgetItem* item);
 	void onItemSelectionChanged();
 	void onLinkageClicked(bool bChecked);
	void onRemoveClicked(bool bChecked);

private:
	bool mLinkage = true;
};

