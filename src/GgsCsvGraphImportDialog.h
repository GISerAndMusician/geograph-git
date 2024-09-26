#pragma once
#include "ui_GgsCsvGraphImportDialog.h"

class GgsCsvParser;
class QgsVectorLayer;
class GgsGraphProxy;

class GgsCsvGraphImportDialog: public QDialog, public Ui::GgsCsvGraphDialog
{
	Q_OBJECT

public:
	GgsCsvGraphImportDialog(QWidget* parent = nullptr);
	~GgsCsvGraphImportDialog();

	QgsVectorLayer* nodeLayer() { return mNodeLayer; }
	QgsVectorLayer* edgeLayer() { return mEdgeLayer; }

	GgsGraphProxy* graph() { return mGraphProxy; }

private:
	void initSplitterComboBox();

	void loadNodeCSVFile(const QString& filePath);
	void loadEdgeCSVFile(const QString& filePath);

private slots:
	void browserNodeFile();
	void browserEgdeFile();
	void selectCRS();
	void nodeFilterSpliterChanged(int index);
	void edgeFilterSpliterChanged(int index);
	void toggleSelectAllNodeHeaders(int status);
	void toggleSelectAllEdgeHeaders(int status);
	void askIfSelectAllNodeHeaders(int status);
	void askIfSelectAllEdgeHeaders(int status);
	void createLayers();

private:
	GgsCsvParser* mNodeFileParser = nullptr;
	GgsCsvParser* mEdgeFileParser = nullptr;

	bool mListWidgetNodeSelect = false;
	bool mCheckBoxAllNodeHeaders = false;
	bool mListWidgetEdgeSelect = false;
	bool mCheckBoxAllEdgeHeaders = false;

	QgsVectorLayer* mNodeLayer = nullptr;
	QgsVectorLayer* mEdgeLayer = nullptr;

	GgsGraphProxy* mGraphProxy = nullptr;
};

