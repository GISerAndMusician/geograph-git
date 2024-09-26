#pragma once
#include <QDialog>
#include "ui_GgsClusterDialog.h"

class QgsVectorLayer;

class GgsClusterDialog: public QDialog, public Ui::Dialog
{
	Q_OBJECT
public:
	GgsClusterDialog(QWidget* parent = nullptr);
	virtual ~GgsClusterDialog();

	QgsVectorLayer* layer();

	int clusterCount();

private slots:
	void onOk();

private:
	void initComboBox();
};
