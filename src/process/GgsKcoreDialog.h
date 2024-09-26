#pragma once
#include <QDialog>
#include "ui_GgsKcoreDialog.h"
#include "GgsGraphProxy.h"
#include "GgsPython.h"

class GgsKcoreDialog: public QDialog, Ui::Form
{
	Q_OBJECT
public:
	GgsKcoreDialog(GgsGraphProxy* graph, QWidget* parent = nullptr);
	~GgsKcoreDialog();

private slots:
	void onOk();

private:
	void initSpinBox();

private:
	GgsGraphProxy* mGraph = nullptr;
	GgsGraphProxy* mKcoreGraphProxy = nullptr;
	GgsPython mPy;
	PyObject* mModule = nullptr;
	QStringList mNodesStringList;
	QStringList mEdgesStringList;
};
