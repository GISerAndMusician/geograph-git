#pragma once
#include <QObject>
#include "qgslayertreeview.h"
#include "qgsmaplayer.h"

class QAction;

struct LegendLayerAction
{
	LegendLayerAction(QAction *a, const QString &m, bool all)
		: action(a)
		, menu(m)
		, allLayers(all)
	{}
	QAction *action = nullptr;
	QString menu;
	bool allLayers;
	QList<QgsMapLayer *> layers;
};

class QgsMapCanvas;

class GgsLayerTreeViewMenuProvider: public QObject, public QgsLayerTreeViewMenuProvider
{
	Q_OBJECT
public:
	GgsLayerTreeViewMenuProvider(QgsLayerTreeView *view, QgsMapCanvas *canvas);

	QMenu *createContextMenu() override;

	QList< LegendLayerAction > legendLayerActions(QgsMapLayerType type) const;

	void setLayerCrs(const QgsCoordinateReferenceSystem &crs);

protected:
	void addCustomLayerActions(QMenu *menu, QgsMapLayer *layer);

protected:
	QgsLayerTreeView *mView = nullptr;
	QgsMapCanvas *mCanvas = nullptr;

	QMap< QgsMapLayerType, QList< LegendLayerAction > > mLegendLayerActionMap;

private slots:
	void setSymbolLegendNodeColor(const QColor &color);
	void editSymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey);
	void copySymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey);
	void pasteSymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey);

private:
	bool removeActionEnabled();

};

