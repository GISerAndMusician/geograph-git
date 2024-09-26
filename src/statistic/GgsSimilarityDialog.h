#pragma once
#include <QDialog>
#include "ui_GgsSimilarityDialog.h"

class GgsSimilarityDialog: public QDialog, public Ui::SimilarityDialog
{
	Q_OBJECT
public:
	GgsSimilarityDialog(QWidget* parent = nullptr);
	~GgsSimilarityDialog();

private slots:
	void onOk();

private:
	void initComboBox();
};