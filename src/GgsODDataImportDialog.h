#pragma once
#include <QDialog>
#include "ui_GgsODDataDialog.h"

class GgsCsvParser;
class QgsVectorLayer;

class GgsODDataImportDialog: public QDialog, public Ui::ODDataDialog
{
public:
	GgsODDataImportDialog(QWidget* parent = nullptr);

	QgsVectorLayer* nodeLayer() { return mNodeLayer; }
	QgsVectorLayer* edgeLayer() { return mEdgeLayer; }

private slots:
	void explore();
	void spliterChanged(int index);
	void selectCRS();
	void importOD();

private:
	void initSplitterComboBox();
	void loadCSVFile(const QString& filepath);

private:
	GgsCsvParser* mFileParser = nullptr;
	QgsVectorLayer* mNodeLayer = nullptr;
	QgsVectorLayer* mEdgeLayer = nullptr;
};

