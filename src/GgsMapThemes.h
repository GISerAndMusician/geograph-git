#ifndef QGSMAPTHEMES_H
#define QGSMAPTHEMES_H

#include "qgsmapthemecollection.h"
#include <QMap>
#include <QObject>
#include <QSet>
#include <QStringList>
#include "GgsApp.h"

class QAction;
class QDomDocument;
class QMenu;

class QgsLayerTreeNode;
class QgsLayerTreeGroup;

/**
 * Contains methods for app-specific map theme functions.
 */
class GgsMapThemes : public QObject
{
	Q_OBJECT
public:

	/**
	 * Returns the instance QgsVisibilityPresets.
	 */
	static GgsMapThemes *instance();

	//! Add a new preset using the current state of project's layer tree
	void addPreset(const QString &name);
	//! Update existing preset using the current state of project's layer tree
	void updatePreset(const QString &name);

	//! Convenience menu that lists available presets and actions for management
	QMenu *menu();

protected slots:

	//! Handles adding a preset to the project's collection
	void addPreset();

	//! Handles apply a preset to the map canvas
	void presetTriggered();

	//! Handles replacing a preset's state
	void replaceTriggered();

	//! Handles removal of current preset from the project's collection
	void removeCurrentPreset();

	//! Handles renaming of the current map theme
	void renameCurrentPreset();

	//! Handles creation of preset menu
	void menuAboutToShow();

private slots:
	void showHelp();

protected:
	GgsMapThemes(); // singleton

	//! Applies current layer state to a preset record
	void applyStateToLayerTreeGroup(QgsLayerTreeGroup *parent, const QgsMapThemeCollection::MapThemeRecord &rec);
	//! Applies layer checked legend symbols to a preset record
	void addPerLayerCheckedLegendSymbols(QgsMapThemeCollection::MapThemeRecord &rec);
	//! Applies current layer styles to a preset record
	void addPerLayerCurrentStyle(QgsMapThemeCollection::MapThemeRecord &rec);

	//! Returns the current state of the map canvas as a preset record
	QgsMapThemeCollection::MapThemeRecord currentState();

	//! Applies a preset for the project's collection to the canvas
	void applyState(const QString &presetName);

	static GgsMapThemes *sInstance;

	QMenu *mMenu = nullptr;
	QMenu *mReplaceMenu = nullptr;
	QAction *mMenuSeparator = nullptr;
	QAction *mActionAddPreset = nullptr;
	QAction *mActionRemoveCurrentPreset = nullptr;
	QAction *mActionRenameCurrentPreset = nullptr;
	QList<QAction *> mMenuPresetActions;
	QList<QAction *> mMenuReplaceActions;
};


#endif // QGSMAPTHEMES_H
