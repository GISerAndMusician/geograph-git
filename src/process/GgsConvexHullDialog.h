#pragma once
#include <QDialog>
#include <QVector>
#include <qgsgeometry.h>
#include "ui_GgsConvexHullDialog.h"

class GgsConvexHullDialog : public QDialog, public Ui::ConvexHullDialog
{
	Q_OBJECT
public:
	GgsConvexHullDialog(QWidget* parent = nullptr);
	~GgsConvexHullDialog();

private slots:
	void onOK();
	void onAlgoChanged(int index);
private:
	void initComboBox();
	QgsMultiPolygonXY convexHullByAlphShape(QVector<QgsPointXY> pts);
};
