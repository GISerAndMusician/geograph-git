#pragma once
#include "ui_GgsBackboneDialog.h"
#include <QDialog>
#include "GgsBackbone.h"

class GgsGraphProxy;

class GgsBackboneDialog: public QDialog, public Ui::BackboneDialog
{
	Q_OBJECT
public:
	GgsBackboneDialog(GgsGraphProxy* graph, QWidget* parent = nullptr);
	~GgsBackboneDialog();

private slots:
	void onOk();

private:
	void initCombBox();

private:
	GgsGraphProxy* mGraph = nullptr;
	GgsBackbone mBackboneAlgo;
};
