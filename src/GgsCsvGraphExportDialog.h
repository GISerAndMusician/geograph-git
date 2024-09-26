#pragma once
#include <QDialog>
#include "ui_GgsCsvGraphExportDialog.h"
#include "GgsGraphProxy.h"

class GgsCsvGraphExportDialog: public QDialog, public Ui::GgsCsvGraphExportDialog
{
	Q_OBJECT
	
public:
	GgsCsvGraphExportDialog(GgsGraphProxy* graph, QWidget* parent = nullptr);
	~GgsCsvGraphExportDialog();

private slots:
	void onOK();
	void onFilePath();

private:
	GgsGraphProxy* mGraph = nullptr;
};