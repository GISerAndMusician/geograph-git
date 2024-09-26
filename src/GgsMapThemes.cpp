#include "GgsMapThemes.h"
#include "qgsmapthemecollection.h"
#include "qgslayertree.h"
#include "qgslayertreemapcanvasbridge.h"
#include "qgslayertreemodel.h"
#include "qgslayertreemodellegendnode.h"
#include "qgslayertreeview.h"
#include "qgsmaplayerstylemanager.h"
#include "qgsproject.h"
#include "qgsrenderer.h"
#include "qgsvectorlayer.h"
#include "qgsnewnamedialog.h"
#include "qgshelp.h"

#include "GgsApp.h"

#include <QMessageBox>

GgsMapThemes *GgsMapThemes::sInstance;


GgsMapThemes::GgsMapThemes()
	: mMenu(new QMenu)
{

	mMenu->addAction(GgsApp::instance()->actionShowAllLayers());
	mMenu->addAction(GgsApp::instance()->actionHideAllLayers());
	mMenu->addAction(GgsApp::instance()->actionShowSelectedLayers());
	mMenu->addAction(GgsApp::instance()->actionHideSelectedLayers());
	mMenu->addAction(GgsApp::instance()->actionToggleSelectedLayers());
	mMenu->addAction(GgsApp::instance()->actionToggleSelectedLayersIndependently());
	mMenu->addAction(GgsApp::instance()->actionHideDeselectedLayers());
	mMenu->addSeparator();

	//mReplaceMenu = new QMenu(tr("Replace Theme"));
	//mMenu->addMenu(mReplaceMenu);
	//mActionRenameCurrentPreset = mMenu->addAction(tr("Rename Current Theme¡­"), this, &MapThemes::renameCurrentPreset);
	//mActionAddPreset = mMenu->addAction(tr("Add Theme¡­"), this, [=] { addPreset(); });
	//mMenuSeparator = mMenu->addSeparator();

	//mActionRemoveCurrentPreset = mMenu->addAction(tr("Remove Current Theme"), this, &MapThemes::removeCurrentPreset);

	//connect(mMenu, &QMenu::aboutToShow, this, &MapThemes::menuAboutToShow);
}


QgsMapThemeCollection::MapThemeRecord GgsMapThemes::currentState()
{
	QgsLayerTreeGroup *root = QgsProject::instance()->layerTreeRoot();
	QgsLayerTreeModel *model = GgsApp::instance()->layerTreeView()->layerTreeModel();
	return QgsMapThemeCollection::createThemeFromCurrentState(root, model);
}

GgsMapThemes *GgsMapThemes::instance()
{
	if (!sInstance)
		sInstance = new GgsMapThemes();

	return sInstance;
}

void GgsMapThemes::addPreset(const QString &name)
{
	QgsProject::instance()->mapThemeCollection()->insert(name, currentState());
}

void GgsMapThemes::updatePreset(const QString &name)
{
	QgsProject::instance()->mapThemeCollection()->update(name, currentState());
}

QMenu *GgsMapThemes::menu()
{
	return mMenu;
}


void GgsMapThemes::addPreset()
{
	QStringList existingNames = QgsProject::instance()->mapThemeCollection()->mapThemes();
	QgsNewNameDialog dlg(tr("theme"), tr("Theme"), QStringList(), existingNames, QRegExp(), Qt::CaseInsensitive, mMenu);
	dlg.setWindowTitle(tr("Map Themes"));
	dlg.setHintString(tr("Name of the new theme"));
	dlg.setOverwriteEnabled(false);
	dlg.setConflictingNameWarning(tr("A theme with this name already exists."));
	dlg.buttonBox()->addButton(QDialogButtonBox::Help);
	connect(dlg.buttonBox(), &QDialogButtonBox::helpRequested, this, &GgsMapThemes::showHelp);
	if (dlg.exec() != QDialog::Accepted || dlg.name().isEmpty())
		return;

	addPreset(dlg.name());
}


void GgsMapThemes::presetTriggered()
{
	QAction *actionPreset = qobject_cast<QAction *>(sender());
	if (!actionPreset)
		return;

	applyState(actionPreset->text());
}

void GgsMapThemes::replaceTriggered()
{
	QAction *actionPreset = qobject_cast<QAction *>(sender());
	if (!actionPreset)
		return;

	int res = QMessageBox::question(GgsApp::instance(), tr("Replace Theme"),
		tr("Are you sure you want to replace the existing theme ¡°%1¡±?").arg(actionPreset->text()),
		QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (res != QMessageBox::Yes)
		return;

	//adding preset with same name is effectively a replace
	addPreset(actionPreset->text());
}


void GgsMapThemes::applyState(const QString &presetName)
{
	if (!QgsProject::instance()->mapThemeCollection()->hasMapTheme(presetName))
		return;

	QgsLayerTreeGroup *root = QgsProject::instance()->layerTreeRoot();
	QgsLayerTreeModel *model = GgsApp::instance()->layerTreeView()->layerTreeModel();
	QgsProject::instance()->mapThemeCollection()->applyTheme(presetName, root, model);
}

void GgsMapThemes::renameCurrentPreset()
{
	QgsMapThemeCollection::MapThemeRecord mapTheme = currentState();
	QStringList existingNames = QgsProject::instance()->mapThemeCollection()->mapThemes();

	for (QAction *actionPreset : qgis::as_const(mMenuPresetActions))
	{
		if (actionPreset->isChecked())
		{
			QgsNewNameDialog dlg(
				tr("theme"),
				tr("%1").arg(actionPreset->text()),
				QStringList(), existingNames, QRegExp(), Qt::CaseInsensitive, mMenu);

			dlg.setWindowTitle(tr("Rename Map Theme"));
			dlg.setHintString(tr("Enter the new name of the map theme"));
			dlg.setOverwriteEnabled(false);
			dlg.setConflictingNameWarning(tr("A theme with this name already exists."));
			dlg.buttonBox()->addButton(QDialogButtonBox::Help);
			connect(dlg.buttonBox(), &QDialogButtonBox::helpRequested, this, &GgsMapThemes::showHelp);
			if (dlg.exec() != QDialog::Accepted || dlg.name().isEmpty())
				return;

			QgsProject::instance()->mapThemeCollection()->renameMapTheme(actionPreset->text(), dlg.name());
		}
	}
}

void GgsMapThemes::removeCurrentPreset()
{
	for (QAction *actionPreset : qgis::as_const(mMenuPresetActions))
	{
		if (actionPreset->isChecked())
		{
			int res = QMessageBox::question(GgsApp::instance(), tr("Remove Theme"),
				tr("Are you sure you want to remove the existing theme ¡°%1¡±?").arg(actionPreset->text()),
				QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
			if (res == QMessageBox::Yes)
				QgsProject::instance()->mapThemeCollection()->removeMapTheme(actionPreset->text());
			break;
		}
	}
}

void GgsMapThemes::menuAboutToShow()
{
	qDeleteAll(mMenuPresetActions);
	mMenuPresetActions.clear();
	mReplaceMenu->clear();
	qDeleteAll(mMenuReplaceActions);
	mMenuReplaceActions.clear();

	QgsMapThemeCollection::MapThemeRecord rec = currentState();
	bool hasCurrent = false;

	const auto constMapThemes = QgsProject::instance()->mapThemeCollection()->mapThemes();
	for (const QString &grpName : constMapThemes)
	{
		QAction *a = new QAction(grpName, mMenu);
		a->setCheckable(true);
		if (!hasCurrent && rec == QgsProject::instance()->mapThemeCollection()->mapThemeState(grpName))
		{
			a->setChecked(true);
			hasCurrent = true;
		}
		connect(a, &QAction::triggered, this, &GgsMapThemes::presetTriggered);
		mMenuPresetActions.append(a);

		QAction *replaceAction = new QAction(grpName, mReplaceMenu);
		connect(replaceAction, &QAction::triggered, this, &GgsMapThemes::replaceTriggered);
		mReplaceMenu->addAction(replaceAction);
	}
	mMenu->insertActions(mMenuSeparator, mMenuPresetActions);
	mReplaceMenu->addActions(mMenuReplaceActions);

	mActionAddPreset->setEnabled(!hasCurrent);
	mActionRemoveCurrentPreset->setEnabled(hasCurrent);
	mActionRenameCurrentPreset->setEnabled(hasCurrent);
}

void GgsMapThemes::showHelp()
{
	QgsHelp::openHelp(QStringLiteral("introduction/general_tools.html#configuring-map-themes"));
}
