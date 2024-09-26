#pragma once
#include <QDialog>
#include <QColorDialog>
#include <QToolButton>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include "ui_GgsGraphStatisticDialog.h"

class GgsGraphProxy;
class GgsGraphStatisticDialog: public QDialog, public Ui::GraphStatisticDialog
{
	Q_OBJECT
public:
	GgsGraphStatisticDialog(QList<GgsGraphProxy*> graphs, QWidget* parent = nullptr);

private slots:
	void onColor();
	void onOK();

private:
	void initStyleUi();

private:
	QList<GgsGraphProxy*> mGraphs;
	QList<QLineEdit*> mLabelNames;
	QList<QColorDialog*> mColorDialog;
	QList<QToolButton*> mColorToolButtons;
	QList<QComboBox*> mPointSymbols;
	QList<QComboBox*> mLineSymbols;
	QList<QSpinBox*> mOpacities;
};