#include "GgsApp.h"
#include <QGridLayout>
#include <QShortcut>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopWidget>
#include "qgsapplication.h"
#include "qgisappstylesheet.h"
#include "qgslayertreeview.h"
#include "qgsmapcanvassnappingutils.h"
#include "qgsdockwidget.h"
#include "qgslayertreemodel.h"
#include "qgsmessagebar.h"
#include "qgslayertreeviewfilterindicator.h"
#include "qgslayertreeviewembeddedindicator.h"
#include "qgslayertreeviewmemoryindicator.h"
#include "qgslayertreeviewtemporalindicator.h"
#include "qgslayertreeviewnocrsindicator.h"
#include "qgslayertreeviewbadlayerindicator.h"
#include "qgsbrowserguimodel.h"
#include "qgsbrowserdockwidget.h"
#include "qgsdatasourceselectdialog.h"
#include "qgsproviderregistry.h"
#include "qgsfileutils.h"
#include "qgslayertree.h"
#include "qgslayertreeviewnonremovableindicator.h"
#include "qgssymbolselectordialog.h"
#include "qgsstyle.h"
#include "qgsrasterlayerproperties.h"
#include "qgsmeshlayerproperties.h"
#include "qgslayerstylingwidget.h"
#include "qgsattributetablefiltermodel.h"
#include "qgsattributetabledialog.h"
#include "qgsvectorlayerproperties.h"
#include "qgsauxiliarystorage.h"
#include "qgsvectortilelayerproperties.h"
#include "qgspluginlayer.h"
#include "qgspluginlayerregistry.h"
#include "qgsdatasourcemanagerdialog.h"
#include "qgsmaplayerconfigwidgetfactory.h"
#include "qgsundowidget.h"
#include "qgslayertreeregistrybridge.h"
#include "qgslayertreeutils.h"
#include "qgslayertreeviewdefaultactions.h"
#include "qgslegendfilterbutton.h"
#include "qgslayertreemapcanvasbridge.h"
#include "qgscustomlayerorderwidget.h"
#include "qgsprojectviewsettings.h"
#include "qgsstatusbar.h"
#include "qgsstatusbarcoordinateswidget.h"
#include "qgsmaptoolidentifyaction.h"
#include "qgsmaptoolselect.h"
#include "qgsmaptoolpan.h"
#include "qgsmaptoolzoom.h"
#include "qgsbearingnumericformat.h"
#include "qgsdatumtransformdialog.h"
#include "qgssublayersdialog.h"
#include "qgscoordinateutils.h"
#include "qgsprojectionselectiondialog.h"
#include "qgslayerdefinition.h"
#include "qgsvectorfilewriter.h"
#include "qgsmessageviewer.h"
#include "qgsvectorlayersaveasdialog.h"
#include "qgsgui.h"
#include "qgseditorwidgetregistry.h"
#include "qgsfieldformatterregistry.h"
#include "qgsvectorfilewritertask.h"
#include "qgsfieldformatter.h"
#include "qgsvectorlayersavestyledialog.h"
#include "qgssourceselectproviderregistry.h"
#include "qgsabstractdatasourcewidget.h"
#include "qgshandlebadlayers.h"
#include "qgsstatusbarscalewidget.h"
#include "ui_defaults.h"
#include "qgssinglesymbolrenderer.h"
#include "qgsnewmemorylayerdialog.h"
#include "qgsprojectdisplaysettings.h"
#include "qgslocaldefaultsettings.h"
#include "qgsuserinputwidget.h"

#include "GgsMapThemes.h"
#include "GgsLayerTreeViewMenuProvider.h"
#include "GgsCsvGraphImportDialog.h"
#include "GgsFdebWidget.h"
#include "GgsMingleWidget.h"
#include "GgsKdeebWidget.h"
#include "GgsGraphProxy.h"
#include "GgsGraphProject.h"
#include "GgsGraphLegendWidget.h"
#include "GgsGraphMapToolSelect.h"
#include "GgsLwoInteraction.h"
#include "GgsODDataImportDialog.h"
#include "GgsClusterDialog.h"
#include "GgsCluster.h"
#include "GgsGraphStatisticDialog.h"
#include "GgsBackbone.h"
#include "GgsKcoreDialog.h"
#include "GgsBackboneDialog.h"
#include "GgsConvexHullDialog.h"
#include "GgsSimilarityDialog.h"
#include "ogdf/fileformats/GraphIO.h"
#include "GgsGraphInfoAmount.h"
#include "GgsCsvGraphExportDialog.h"
#include "GgsLwoInteractionWidget.h"

#pragma execution_character_set("utf-8") 

const char *GgsApp::GRAPH_ORGANIZATION_NAME = "PSIS";
const char *GgsApp::GRAPH_ORGANIZATION_DOMAIN = "psis.org";
const char *GgsApp::GRAPH_APPLICATION_NAME = "geograph";

GgsApp *GgsApp::sInstance = nullptr;

GgsApp::GgsApp(QSplashScreen* splashScreen, QWidget *parent)
    : QMainWindow(parent),
	mSplashScreen(splashScreen)
{
	if (sInstance) {
		QMessageBox::critical(
			this,
			tr("运行了多个geograph实例"),
			tr("运行了多个geograph实例，请联系开发人员！"));
		abort();
	}


	sInstance = this;

    this->setupUi(this);
	mSplashScreen->showMessage(tr("正在启动程序..."), Qt::AlignHCenter | Qt::AlignBottom);
	qApp->processEvents();

	// 加载providers
	QgsApplication::initQgis();

	mStyleSheetBuilder = new QgisAppStyleSheet(this);
	connect(mStyleSheetBuilder, &QgisAppStyleSheet::appStyleSheetChanged,
		this, &GgsApp::setAppStyleSheet);

	QWidget *centralWidget = ((QMainWindow*)this)->centralWidget();
	QGridLayout *centralLayout = new QGridLayout(centralWidget);
	centralWidget->setLayout(centralLayout);
	centralLayout->setContentsMargins(0, 0, 0, 0);
	
	// 创建地图画布
	mMapCanvas = new QgsMapCanvas(centralWidget);
	mMapCanvas->setObjectName(QStringLiteral("theMapCanvas"));
	centralLayout->addWidget(mMapCanvas);

	// 设置地图画布颜色
	QgsSettings settings;
	int myRed = settings.value(QStringLiteral("qgis/default_canvas_color_red"), 255).toInt();
	int myGreen = settings.value(QStringLiteral("qgis/default_canvas_color_green"), 255).toInt();
	int myBlue = settings.value(QStringLiteral("qgis/default_canvas_color_blue"), 255).toInt();
	mMapCanvas->setCanvasColor(QColor(myRed, myGreen, myBlue));

	mMapCanvas->setProject(QgsProject::instance());
	
	mMapCanvas->setFocus();

	mInfoBar = new QgsMessageBar(centralWidget);

	// 图层控制器
	mLayerTreeView = new QgsLayerTreeView(this);
	mLayerTreeView->setObjectName(QStringLiteral("theLayerTreeView"));
	mLayerTreeView->setMessageBar(mInfoBar);

	mSnappingUtils = new QgsMapCanvasSnappingUtils(mMapCanvas, this);
	mMapCanvas->setSnappingUtils(mSnappingUtils);
	connect(QgsProject::instance(), &QgsProject::snappingConfigChanged, mSnappingUtils, &QgsSnappingUtils::setConfig);

	// 地图风格停靠窗
	mMapStylingDock = new QgsDockWidget(this);
	mMapStylingDock->setWindowTitle(tr("图层样式"));
	mMapStylingDock->setObjectName(QStringLiteral("LayerStyling"));
	QShortcut *showStylingDock = new QShortcut(QKeySequence(tr("Ctrl+3")), this);
	connect(showStylingDock, &QShortcut::activated, mMapStylingDock, &QgsDockWidget::toggleUserVisible);
	showStylingDock->setObjectName(QStringLiteral("ShowLayerStylingPanel"));
	showStylingDock->setWhatsThis(tr("显示图层样式面板"));

	mMapStyleWidget = new QgsLayerStylingWidget(mMapCanvas, mInfoBar, mMapLayerPanelFactories);
	mMapStylingDock->setWidget(mMapStyleWidget);
	//connect(mMapStyleWidget, &QgsLayerStylingWidget::styleChanged, this, &QgisApp::updateLabelToolButtons);
	connect(mMapStylingDock, &QDockWidget::visibilityChanged, mActionStyleDock, &QAction::setChecked);
	connect(mActionStyleDock, &QAction::toggled, this, &GgsApp::mapStyleDock);

	addDockWidget(Qt::RightDockWidgetArea, mMapStylingDock);
	mMapStylingDock->hide();

	// 浏览器窗口
	mBrowserModel = new QgsBrowserGuiModel(this);
	mBrowserWidget = new QgsBrowserDockWidget(tr("浏览器"), mBrowserModel, this);
	mBrowserWidget->setObjectName(QStringLiteral("Browser"));
	mBrowserWidget->setMessageBar(mInfoBar);
	QShortcut *showBrowserDock = new QShortcut(QKeySequence(tr("Ctrl+2")), this);
	connect(showBrowserDock, &QShortcut::activated, mBrowserWidget, &QgsDockWidget::toggleUserVisible);
	showBrowserDock->setObjectName(QStringLiteral("ShowBrowserPanel"));
	showBrowserDock->setWhatsThis(tr("显示浏览器面板"));

	// Only connect the first widget: the model is shared, there is no need to refresh multiple times.
	/*connect(this, &QgisApp::connectionsChanged, mBrowserWidget, [=]
	{
		if (!mBlockBrowser1Refresh && !mBlockBrowser2Refresh)
			mBrowserWidget->refresh();
	});
	connect(mBrowserWidget, &QgsBrowserDockWidget::connectionsChanged, this, [=]
	{
		mBlockBrowser1Refresh++;
		emit connectionsChanged();
		mBlockBrowser1Refresh--;
	});
	connect(mBrowserWidget, &QgsBrowserDockWidget::openFile, this, &QgisApp::openFile);
	connect(mBrowserWidget, &QgsBrowserDockWidget::handleDropUriList, this, &QgisApp::handleDropUriList);*/

	addDockWidget(Qt::LeftDockWidgetArea, mBrowserWidget);
	mBrowserWidget->hide();
	mAppBadLayersHandler = new QgsHandleBadLayersHandler();
	QgsProject::instance()->setBadLayerHandler(mAppBadLayersHandler);

	this->createMenus();
	this->createStatusBar();
	this->createActions();
	this->createCanvasTools();
	this->initLayerTreeView();
	this->setupConnections();
	applyDefaultSettingsToCanvas(mMapCanvas);

	mSplashScreen->showMessage(tr("恢复窗口状态"), Qt::AlignHCenter | Qt::AlignBottom);
	qApp->processEvents();
	restoreWindowState();

	mSplashScreen->showMessage(tr("填充已保存样式"), Qt::AlignHCenter | Qt::AlignBottom);
	QgsStyle::defaultStyle();

	mSplashScreen->showMessage(tr("geograph 准备就绪!"), Qt::AlignHCenter | Qt::AlignBottom);

	mMapCanvas->clearExtentHistory(); // reset zoomnext/zoomlast

	mBearingNumericFormat.reset(QgsLocalDefaultSettings::bearingFormat());

	connect(QgsProject::instance()->displaySettings(), &QgsProjectDisplaySettings::bearingFormatChanged, this, [=]
	{
		mBearingNumericFormat.reset(QgsProject::instance()->displaySettings()->bearingFormat()->clone());
	});
	connect(mMapCanvas, &QgsMapCanvas::panDistanceBearingChanged, this, &GgsApp::showPanMessage);

	fileNewBlank(); // prepare empty project, also skips any default templates from loading
	updateCrsStatusBar();

	mRasterFileFilter = QgsProviderRegistry::instance()->fileRasterFilters();

	// 初始化图图层管理器
	mGraphLegendDockWidget = new QgsDockWidget(tr("图"), this);
	mGraphLegendDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	mGraphLegendWgt = new GgsGraphLegendWidget(mGraphLegendDockWidget);
	mGraphLegendDockWidget->setWidget(mGraphLegendWgt);
	addDockWidget(Qt::LeftDockWidgetArea, mGraphLegendDockWidget);

	// 用户输入控件（画布）
	mUserInputDockWidget = new QgsUserInputWidget(mMapCanvas);
	mUserInputDockWidget->setObjectName(QStringLiteral("UserInputDockWidget"));
	mUserInputDockWidget->setAnchorWidget(mMapCanvas);
	mUserInputDockWidget->setAnchorWidgetPoint(QgsFloatingWidget::TopRight);
	mUserInputDockWidget->setAnchorPoint(QgsFloatingWidget::TopRight);

	// 交互-LWO
	mLWOInteraction = new GgsLwoInteraction(mMapTools.mGraphSelect);
}

GgsApp::~GgsApp()
{
	GgsGraphProject* sGraphProject = GgsGraphProject::instance();
	if (sGraphProject)
	{
		delete sGraphProject;
		sGraphProject = nullptr;
	}
}

void GgsApp::showLayerProperties(QgsMapLayer *mapLayer, const QString &page /*= QString()*/)
{
	if (!mapLayer)
		return;

	if (!QgsProject::instance()->layerIsEmbedded(mapLayer->id()).isEmpty())
	{
		return; //don't show properties of embedded layers
	}

	switch (mapLayer->type())
	{
	case QgsMapLayerType::RasterLayer:
	{
		QgsRasterLayerProperties *rasterLayerPropertiesDialog = new QgsRasterLayerProperties(mapLayer, mMapCanvas, this);
		if (!page.isEmpty())
			rasterLayerPropertiesDialog->setCurrentPage(page);
		else
			rasterLayerPropertiesDialog->restoreLastPage();

		// Cannot use exec here due to raster transparency map tool:
		// in order to pass focus to the canvas, the dialog needs to
		// be hidden and shown in non-modal mode.
		rasterLayerPropertiesDialog->setModal(true);
		rasterLayerPropertiesDialog->show();
		// Delete (later, for safety) since dialog cannot be reused without
		// updating code
		connect(rasterLayerPropertiesDialog, &QgsRasterLayerProperties::accepted, [rasterLayerPropertiesDialog]
		{
			rasterLayerPropertiesDialog->deleteLater();
		});
		connect(rasterLayerPropertiesDialog, &QgsRasterLayerProperties::rejected, [rasterLayerPropertiesDialog]
		{
			rasterLayerPropertiesDialog->deleteLater();
		});
		break;
	}

	case QgsMapLayerType::MeshLayer:
	{
		QgsMeshLayerProperties meshLayerPropertiesDialog(mapLayer, mMapCanvas, this);

		for (QgsMapLayerConfigWidgetFactory *factory : qgis::as_const(mMapLayerPanelFactories))
		{
			meshLayerPropertiesDialog.addPropertiesPageFactory(factory);
		}

		if (!page.isEmpty())
			meshLayerPropertiesDialog.setCurrentPage(page);
		else
			meshLayerPropertiesDialog.restoreLastPage();

		mMapStyleWidget->blockUpdates(true);
		if (meshLayerPropertiesDialog.exec())
		{
			activateDeactivateLayerRelatedActions(mapLayer);
			mMapStyleWidget->updateCurrentWidgetLayer();
		}
		mMapStyleWidget->blockUpdates(false); // delete since dialog cannot be reused without updating code
		break;
	}

	case QgsMapLayerType::VectorLayer:
	{
		QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(mapLayer);

		QgsVectorLayerProperties *vectorLayerPropertiesDialog = new QgsVectorLayerProperties(mMapCanvas, visibleMessageBar(), vlayer, this);
		connect(
			vectorLayerPropertiesDialog, static_cast<void (QgsVectorLayerProperties::*)(QgsMapLayer *)>(&QgsVectorLayerProperties::toggleEditing),
			this, [=](QgsMapLayer * layer) { toggleEditing(layer); }
		);
		connect(vectorLayerPropertiesDialog, &QgsVectorLayerProperties::exportAuxiliaryLayer, this, [=](QgsAuxiliaryLayer * layer)
		{
			if (layer)
			{
				std::unique_ptr<QgsVectorLayer> clone;
				clone.reset(layer->toSpatialLayer());

				saveAsFile(clone.get());
			}
		});
		for (QgsMapLayerConfigWidgetFactory *factory : qgis::as_const(mMapLayerPanelFactories))
		{
			vectorLayerPropertiesDialog->addPropertiesPageFactory(factory);
		}

		if (!page.isEmpty())
			vectorLayerPropertiesDialog->setCurrentPage(page);
		else
			vectorLayerPropertiesDialog->restoreLastPage();

		mMapStyleWidget->blockUpdates(true);
		if (vectorLayerPropertiesDialog->exec())
		{
			activateDeactivateLayerRelatedActions(mapLayer);
			mMapStyleWidget->updateCurrentWidgetLayer();
		}
		mMapStyleWidget->blockUpdates(false);

		delete vectorLayerPropertiesDialog; // delete since dialog cannot be reused without updating code
		break;
	}

	case QgsMapLayerType::VectorTileLayer:
	{
	/*	QgsVectorTileLayerProperties vectorTileLayerPropertiesDialog(qobject_cast<QgsVectorTileLayer *>(mapLayer), mMapCanvas, visibleMessageBar(), this);
		if (!page.isEmpty())
			vectorTileLayerPropertiesDialog.setCurrentPage(page);
		else
			vectorTileLayerPropertiesDialog.restoreLastPage();

		mMapStyleWidget->blockUpdates(true);
		if (vectorTileLayerPropertiesDialog.exec())
		{
			activateDeactivateLayerRelatedActions(mapLayer);
			mMapStyleWidget->updateCurrentWidgetLayer();
		}
		mMapStyleWidget->blockUpdates(false); // delete since dialog cannot be reused without updating code 
	*/
		break;
	}

	case QgsMapLayerType::PluginLayer:
	{
		QgsPluginLayer *pl = qobject_cast<QgsPluginLayer *>(mapLayer);
		if (!pl)
			return;

		QgsPluginLayerType *plt = QgsApplication::pluginLayerRegistry()->pluginLayerType(pl->pluginLayerType());
		if (!plt)
			return;

		if (!plt->showLayerProperties(pl))
		{
			visibleMessageBar()->pushMessage(tr("Warning"),
				tr("This layer doesn't have a properties dialog."),
				Qgis::Info, messageTimeout());
		}
		break;
	}

	case QgsMapLayerType::AnnotationLayer:
	{
		break;
	}

	}
}

QgsMapLayer * GgsApp::activeLayer()
{
	return mLayerTreeView ? mLayerTreeView->currentLayer() : nullptr;
}

void GgsApp::attributeTable(QgsAttributeTableFilterModel::FilterMode filter /*= QgsAttributeTableFilterModel::ShowAll*/)
{
	QgsVectorLayer *myLayer = qobject_cast<QgsVectorLayer *>(activeLayer());
	if (!myLayer || !myLayer->dataProvider())
	{
		return;
	}

	if (myLayer->isEditable())
	{
		QMessageBox::StandardButton reply = 
			QMessageBox::question(this, tr("提示"), tr("目前图层正处于编辑状态，是否关闭编辑状态？"), QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			myLayer->commitChanges();
		}else
			return;
	}

// 	QgsAttributeTableDialog *mDialog = new QgsAttributeTableDialog(myLayer, filter);
// 	mDialog->show();

	QDialog dialog(this);
	dialog.setWindowTitle(QString("图层'%1'的属性表").arg(myLayer->name()));
	QGridLayout* pLayout = new QGridLayout;
	QgsDualView* pView = new QgsDualView(&dialog);
	pLayout->addWidget(pView);
	dialog.setLayout(pLayout);
	pView->init(myLayer, mMapCanvas);
	dialog.exec();
}

void GgsApp::mapStyleDock(bool enabled)
{
	mMapStylingDock->setUserVisible(enabled);
	setMapStyleDockLayer(activeLayer());
}

void GgsApp::setMapStyleDockLayer(QgsMapLayer *layer)
{
	if (!layer)
	{
		return;
	}

	mMapStyleWidget->setEnabled(true);
	// We don't set the layer if the dock isn't open mainly to save
	// the extra work if it's not needed
	if (mMapStylingDock->isVisible())
	{
		mMapStyleWidget->setLayer(layer);
	}
}

bool GgsApp::toggleEditing(QgsMapLayer *layer, bool allowCancel /*= true*/)
{
	QMessageBox::information(this, tr("info"), tr("toggleEditing"));
	return true;
}

QgsMessageBar * GgsApp::visibleMessageBar()
{
	if (mDataSourceManagerDialog &&
		mDataSourceManagerDialog->isVisible() &&
		mDataSourceManagerDialog->isModal())
	{
		return mDataSourceManagerDialog->messageBar();
	}
	else
	{
		return messageBar();
	}
}

QList< QgsMapCanvas * > GgsApp::mapCanvases()
{
	// filter out browser canvases -- they are children of app, but a different
    // kind of beast, and here we only want the main canvas or dock canvases
	auto canvases = findChildren< QgsMapCanvas * >();
	canvases.erase(std::remove_if(canvases.begin(), canvases.end(),
		[](QgsMapCanvas * canvas)
	{
		return !canvas || canvas->property("browser_canvas").toBool();
	}), canvases.end());
	return canvases;
}

int GgsApp::messageTimeout()
{
	QgsSettings settings;
	return settings.value(QStringLiteral("qgis/messageTimeout"), 5).toInt();
}

void GgsApp::updateUndoActions()
{
	QMessageBox::information(this, tr("info"), tr("updateUndoActions"));
}

QgsLayerTreeRegistryBridge::InsertionPoint GgsApp::layerTreeInsertionPoint() const
{
	// defaults
	QgsLayerTreeGroup *insertGroup = mLayerTreeView->layerTreeModel()->rootGroup();
	QModelIndex current = mLayerTreeView->currentIndex();

	int index = 0;

	if (current.isValid())
	{
		index = current.row();

		QgsLayerTreeNode *currentNode = mLayerTreeView->currentNode();
		if (currentNode)
		{
			// if the insertion point is actually a group, insert new layers into the group
			if (QgsLayerTree::isGroup(currentNode))
			{
				// if the group is embedded go to the first non-embedded group, at worst the top level item
				QgsLayerTreeGroup *insertGroup = QgsLayerTreeUtils::firstGroupWithoutCustomProperty(QgsLayerTree::toGroup(currentNode), QStringLiteral("embedded"));

				return QgsLayerTreeRegistryBridge::InsertionPoint(insertGroup, 0);
			}

			// otherwise just set the insertion point in front of the current node
			QgsLayerTreeNode *parentNode = currentNode->parent();
			if (QgsLayerTree::isGroup(parentNode))
			{
				// if the group is embedded go to the first non-embedded group, at worst the top level item
				QgsLayerTreeGroup *parentGroup = QgsLayerTree::toGroup(parentNode);
				insertGroup = QgsLayerTreeUtils::firstGroupWithoutCustomProperty(parentGroup, QStringLiteral("embedded"));
				if (parentGroup != insertGroup)
					index = 0;
			}
		}
	}
	return QgsLayerTreeRegistryBridge::InsertionPoint(insertGroup, index);
}

QgsLayerTreeView * GgsApp::layerTreeView()
{
	Q_ASSERT(mLayerTreeView);
	return mLayerTreeView;
}

QSize GgsApp::iconSize(bool dockedToolbar /*= false*/) const
{
	return QgsGuiUtils::iconSize(dockedToolbar);
}

void GgsApp::removeLayers(QList<QgsMapLayer *> layers)
{
	QStringList nonRemovableLayerNames;
	for (QgsMapLayer *layer : layers)
	{
		if (!layer->flags().testFlag(QgsMapLayer::Removable))
			nonRemovableLayerNames << layer->name();
	}
	if (!nonRemovableLayerNames.isEmpty())
	{
		QMessageBox::warning(this, tr("Required Layers"),
			tr("The following layers are marked as required by the project:\n\n%1\n\nPlease deselect them (or unmark as required) and retry.").arg(nonRemovableLayerNames.join(QLatin1Char('\n'))));
		return;
	}

	for (QgsMapLayer *layer : layers)
	{
		QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(layer);
		if (vlayer && vlayer->isEditable() && !toggleEditing(vlayer, true))
			return;
	}

	QStringList activeTaskDescriptions;
	for (QgsMapLayer *layer : layers)
	{
		QList< QgsTask * > tasks = QgsApplication::taskManager()->tasksDependentOnLayer(layer);
		if (!tasks.isEmpty())
		{
			const auto constTasks = tasks;
			for (QgsTask *task : constTasks)
			{
				activeTaskDescriptions << tr(" • %1").arg(task->description());
			}
		}
	}

	if (!activeTaskDescriptions.isEmpty())
	{
		QMessageBox::warning(this, tr("Active Tasks"),
			tr("The following tasks are currently running which depend on this layer:\n\n%1\n\nPlease cancel these tasks and retry.").arg(activeTaskDescriptions.join(QLatin1Char('\n'))));
		return;
	}

	QList<QgsLayerTreeNode *> selectedNodes = mLayerTreeView->selectedNodes(true);

	//validate selection
	if (selectedNodes.isEmpty())
	{
		visibleMessageBar()->pushMessage(tr("No legend entries selected"),
			tr("Select the layers and groups you want to remove in the legend."),
			Qgis::Info, messageTimeout());
		return;
	}

	bool promptConfirmation = QgsSettings().value(QStringLiteral("qgis/askToDeleteLayers"), true).toBool();

	// Don't show prompt to remove a empty group.
	if (selectedNodes.count() == 1
		&& selectedNodes.at(0)->nodeType() == QgsLayerTreeNode::NodeGroup
		&& selectedNodes.at(0)->children().count() == 0)
	{
		promptConfirmation = false;
	}

	bool shiftHeld = QApplication::queryKeyboardModifiers().testFlag(Qt::ShiftModifier);
	//display a warning
	if (!shiftHeld && promptConfirmation && QMessageBox::warning(this, tr("Remove layers and groups"), tr("Remove %n legend entries?", "number of legend items to remove", selectedNodes.count()), QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
	{
		return;
	}

	const auto constSelectedNodes = selectedNodes;
	for (QgsLayerTreeNode *node : constSelectedNodes)
	{
		QgsLayerTreeGroup *parentGroup = qobject_cast<QgsLayerTreeGroup *>(node->parent());
		if (parentGroup)
			parentGroup->removeChildNode(node);
	}

	showStatusMessage(tr("%n legend entries removed.", "number of removed legend entries", selectedNodes.count()));

	refreshMapCanvas();
}

void GgsApp::addUserInputWidget(QWidget* widget)
{
	mUserInputDockWidget->addUserInputWidget(widget);
}

QString GgsApp::saveAsFile(QgsMapLayer *layer /*= nullptr*/, bool onlySelected /*= false*/, bool defaultToAddToMap /*= true*/)
{
	if (!layer)
		layer = activeLayer();

	if (!layer)
		return QString();

	QgsMapLayerType layerType = layer->type();
	switch (layerType)
	{
	case QgsMapLayerType::RasterLayer:
		return saveAsRasterFile(qobject_cast<QgsRasterLayer *>(layer), defaultToAddToMap);

	case QgsMapLayerType::VectorLayer:
		return saveAsVectorFileGeneral(qobject_cast<QgsVectorLayer *>(layer), true, onlySelected, defaultToAddToMap);

	case QgsMapLayerType::MeshLayer:
	case QgsMapLayerType::VectorTileLayer:
	case QgsMapLayerType::PluginLayer:
	case QgsMapLayerType::AnnotationLayer:
		return QString();
	}
	return QString();
}

QString GgsApp::saveAsRasterFile(QgsRasterLayer *layer /*= nullptr*/, bool defaultAddToCanvas /*= true*/)
{
	QMessageBox::information(this, tr("info"), tr("saveAsRasterFile"));

	return QString();
}

QString GgsApp::saveAsVectorFileGeneral(QgsVectorLayer *vlayer, bool symbologyOption, bool onlySelected, bool defaultToAddToMap)
{
	if (!vlayer)
	{
		vlayer = qobject_cast<QgsVectorLayer *>(activeLayer()); // FIXME: output of multiple layers at once?
	}

	if (!vlayer)
		return QString();

	const QString layerId = vlayer->id();

	auto onSuccess = [this, layerId](const QString & newFilename,
		bool addToCanvas,
		const QString & layerName,
		const QString & encoding,
		const QString & vectorFileName)
	{
		if (addToCanvas)
		{
			QString uri(newFilename);
			if (!layerName.isEmpty())
				uri += "|layername=" + layerName;
			this->addVectorLayers(QStringList(uri), encoding, QStringLiteral("file"));
		}

		// We need to re-retrieve the map layer here, in case it's been deleted during the lifetime of the task
		if (QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(QgsProject::instance()->mapLayer(layerId)))
			this->emit layerSavedAs(vlayer, vectorFileName);

		this->visibleMessageBar()->pushMessage(tr("Layer Exported"),
			tr("Successfully saved vector layer to <a href=\"%1\">%2</a>").arg(QUrl::fromLocalFile(newFilename).toString(), QDir::toNativeSeparators(newFilename)),
			Qgis::Success, messageTimeout());
	};

	auto onFailure = [](int error, const QString & errorMessage)
	{
		if (error != QgsVectorFileWriter::Canceled)
		{
			QgsMessageViewer *m = new QgsMessageViewer(nullptr);
			m->setWindowTitle(tr("Save Error"));
			m->setMessageAsPlainText(tr("Export to vector file failed.\nError: %1").arg(errorMessage));
			m->exec();
		}
	};

	return saveAsVectorFileGeneral(vlayer, symbologyOption, onlySelected, defaultToAddToMap, onSuccess, onFailure);
}

/**
 * Field value converter for export as vector layer
 * \note Not available in Python bindings
 */
class QgisAppFieldValueConverter : public QgsVectorFileWriter::FieldValueConverter
{
public:
	QgisAppFieldValueConverter(QgsVectorLayer *vl, const QgsAttributeList &attributesAsDisplayedValues);

	QgsField fieldDefinition(const QgsField &field) override;

	QVariant convert(int idx, const QVariant &value) override;

	QgisAppFieldValueConverter *clone() const override;

private:
	QPointer< QgsVectorLayer > mLayer;
	QgsAttributeList mAttributesAsDisplayedValues;
};

QgisAppFieldValueConverter::QgisAppFieldValueConverter(QgsVectorLayer *vl, const QgsAttributeList &attributesAsDisplayedValues)
	: mLayer(vl)
	, mAttributesAsDisplayedValues(attributesAsDisplayedValues)
{
}

QgsField QgisAppFieldValueConverter::fieldDefinition(const QgsField &field)
{
	if (!mLayer)
		return field;

	int idx = mLayer->fields().indexFromName(field.name());
	if (mAttributesAsDisplayedValues.contains(idx))
	{
		return QgsField(field.name(), QVariant::String);
	}
	return field;
}

QVariant QgisAppFieldValueConverter::convert(int idx, const QVariant &value)
{
	if (!mLayer || !mAttributesAsDisplayedValues.contains(idx))
	{
		return value;
	}
	const QgsEditorWidgetSetup setup = QgsGui::editorWidgetRegistry()->findBest(mLayer, mLayer->fields().field(idx).name());
	QgsFieldFormatter *fieldFormatter = QgsApplication::fieldFormatterRegistry()->fieldFormatter(setup.type());
	return fieldFormatter->representValue(mLayer, idx, setup.config(), QVariant(), value);
}

QgisAppFieldValueConverter *QgisAppFieldValueConverter::clone() const
{
	return new QgisAppFieldValueConverter(*this);
}

QString GgsApp::saveAsVectorFileGeneral(QgsVectorLayer *vlayer, bool symbologyOption, bool onlySelected, bool defaultToAddToMap, const std::function<void(const QString &, bool, const QString &, const QString &, const QString &)> &onSuccess, const std::function<void(int, const QString &)> &onFailure, int options, const QString &dialogTitle)
{
	QgsCoordinateReferenceSystem destCRS;

	if (!symbologyOption)
	{
		options &= ~QgsVectorLayerSaveAsDialog::Symbology;
	}

	QgsVectorLayerSaveAsDialog *dialog = new QgsVectorLayerSaveAsDialog(vlayer, options, this);
	if (!dialogTitle.isEmpty())
		dialog->setWindowTitle(dialogTitle);

	dialog->setMapCanvas(mMapCanvas);
	dialog->setIncludeZ(QgsWkbTypes::hasZ(vlayer->wkbType()));
	dialog->setOnlySelected(onlySelected);
	dialog->setAddToCanvas(defaultToAddToMap);

	QString vectorFilename;
	if (dialog->exec() == QDialog::Accepted)
	{
		QString encoding = dialog->encoding();
		vectorFilename = dialog->filename();
		QString format = dialog->format();
		QStringList datasourceOptions = dialog->datasourceOptions();
		bool autoGeometryType = dialog->automaticGeometryType();
		QgsWkbTypes::Type forcedGeometryType = dialog->geometryType();

		QgsCoordinateTransform ct;
		destCRS = dialog->crsObject();

		if (destCRS.isValid())
		{
			QgsDatumTransformDialog::run(vlayer->crs(), destCRS, this, mMapCanvas);
			ct = QgsCoordinateTransform(vlayer->crs(), destCRS, QgsProject::instance());
		}

		QgsRectangle filterExtent = dialog->filterExtent();
		QgisAppFieldValueConverter converter(vlayer, dialog->attributesAsDisplayedValues());
		QgisAppFieldValueConverter *converterPtr = nullptr;
		// No need to use the converter if there is nothing to convert
		if (!dialog->attributesAsDisplayedValues().isEmpty())
			converterPtr = &converter;

		QgsVectorFileWriter::SaveVectorOptions options;
		options.driverName = format;
		options.layerName = dialog->layername();
		options.actionOnExistingFile = dialog->creationActionOnExistingFile();
		options.fileEncoding = encoding;
		options.ct = ct;
		options.onlySelectedFeatures = dialog->onlySelected();
		options.datasourceOptions = datasourceOptions;
		options.layerOptions = dialog->layerOptions();
		options.skipAttributeCreation = dialog->selectedAttributes().isEmpty();
		options.symbologyExport = static_cast<QgsVectorFileWriter::SymbologyExport>(dialog->symbologyExport());
		options.symbologyScale = dialog->scale();
		if (dialog->hasFilterExtent())
			options.filterExtent = filterExtent;
		options.overrideGeometryType = autoGeometryType ? QgsWkbTypes::Unknown : forcedGeometryType;
		options.forceMulti = dialog->forceMulti();
		options.includeZ = dialog->includeZ();
		options.attributes = dialog->selectedAttributes();
		options.fieldValueConverter = converterPtr;

		bool addToCanvas = dialog->addToCanvas();
		QgsVectorFileWriterTask *writerTask = new QgsVectorFileWriterTask(vlayer, vectorFilename, options);

		// when writer is successful:
		connect(writerTask, &QgsVectorFileWriterTask::completed, this, [onSuccess, addToCanvas, encoding, vectorFilename](const QString & newFilename, const QString & newLayer)
		{
			onSuccess(newFilename, addToCanvas, newLayer, encoding, vectorFilename);
		});

		// when an error occurs:
		connect(writerTask, &QgsVectorFileWriterTask::errorOccurred, this, [onFailure](int error, const QString & errorMessage)
		{
			onFailure(error, errorMessage);
		});

		QgsApplication::taskManager()->addTask(writerTask);
	}

	delete dialog;
	return vectorFilename;
}

bool GgsApp::checkTasksDependOnProject()
{
	QSet< QString > activeTaskDescriptions;
	QMap<QString, QgsMapLayer *> layers = QgsProject::instance()->mapLayers();
	QMap<QString, QgsMapLayer *>::const_iterator layerIt = layers.constBegin();

	for (; layerIt != layers.constEnd(); ++layerIt)
	{
		QList< QgsTask * > tasks = QgsApplication::taskManager()->tasksDependentOnLayer(layerIt.value());
		if (!tasks.isEmpty())
		{
			const auto constTasks = tasks;
			for (QgsTask *task : constTasks)
			{
				activeTaskDescriptions.insert(tr(" • %1").arg(task->description()));
			}
		}
	}

	if (!activeTaskDescriptions.isEmpty())
	{
		QMessageBox::warning(this, tr("Active Tasks"),
			tr("The following tasks are currently running which depend on layers in this project:\n\n%1\n\nPlease cancel these tasks and retry.").arg(qgis::setToList(activeTaskDescriptions).join(QLatin1Char('\n'))));
		return true;
	}
	return false;
}

bool GgsApp::checkUnsavedLayerEdits()
{
	return true;
}

void GgsApp::saveStyleFile(QgsMapLayer *layer /*= nullptr */)
{
	if (!layer)
	{
		layer = activeLayer();
	}

	if (!layer || !layer->dataProvider())
		return;

	switch (layer->type())
	{

	case QgsMapLayerType::VectorLayer:
	{
		QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(layer);
		QgsVectorLayerSaveStyleDialog dlg(vlayer, this);

		if (dlg.exec())
		{
			bool resultFlag = false;

			QgsVectorLayerProperties::StyleType type = dlg.currentStyleType();
			switch (type)
			{
			case QgsVectorLayerProperties::QML:
			case QgsVectorLayerProperties::SLD:
			{
				QString message;
				QString filePath = dlg.outputFilePath();
				if (type == QgsVectorLayerProperties::QML)
					message = vlayer->saveNamedStyle(filePath, resultFlag, dlg.styleCategories());
				else
					message = vlayer->saveSldStyle(filePath, resultFlag);

				if (resultFlag)
				{
					mInfoBar->pushMessage(tr("Style saved"), tr("Successfully exported style to <a href=\"%1\">%2</a>").arg(QUrl::fromLocalFile(filePath).toString(), QDir::toNativeSeparators(filePath)), Qgis::Success);
				}
				else
				{
					mInfoBar->pushMessage(tr("Save Style"), message, Qgis::Warning);
				}

				break;
			}
			case QgsVectorLayerProperties::DB:
			{
				QString infoWindowTitle = QObject::tr("Save style to DB (%1)").arg(vlayer->providerType());
				QString msgError;

				QgsVectorLayerSaveStyleDialog::SaveToDbSettings dbSettings = dlg.saveToDbSettings();

				vlayer->saveStyleToDatabase(dbSettings.name, dbSettings.description, dbSettings.isDefault, dbSettings.uiFileContent, msgError);

				if (!msgError.isNull())
				{
					mInfoBar->pushMessage(infoWindowTitle, msgError, Qgis::Warning);
				}
				else
				{
					mInfoBar->pushMessage(infoWindowTitle, tr("Style saved"), Qgis::Success);
				}
				break;
			}
			}
		}
		break;
	}

	case QgsMapLayerType::RasterLayer:
	case QgsMapLayerType::MeshLayer:
	{
		QgsSettings settings;
		QString lastUsedDir = settings.value(QStringLiteral("style/lastStyleDir"), QDir::homePath()).toString();
		QString filename = QFileDialog::getSaveFileName(this,
			tr("Save as QGIS Layer Style File"),
			lastUsedDir,
			tr("QGIS Layer Style File") + " (*.qml)");
		if (filename.isEmpty())
			return;

		if (!filename.endsWith(QLatin1String(".qml")))
		{
			filename += QLatin1String(".qml");
		}

		bool defaultLoadedFlag;
		layer->saveNamedStyle(filename, defaultLoadedFlag);

		settings.setValue(QStringLiteral("style/lastStyleDir"), filename);
		break;
	}

	case QgsMapLayerType::VectorTileLayer:
	case QgsMapLayerType::AnnotationLayer:
	case QgsMapLayerType::PluginLayer:
		break;

	}
}

void GgsApp::makeMemoryLayerPermanent(QgsVectorLayer *layer)
{
	if (!layer)
		return;

	const QString layerId = layer->id();

	auto onSuccess = [this, layerId](const QString & newFilename,
		bool,
		const QString & newLayerName,
		const QString &,
		const QString &)
	{
		// we have to re-retrieve the layer, in case it's been removed during the lifetime of the writer task
		QgsVectorLayer *vl = qobject_cast<QgsVectorLayer *>(QgsProject::instance()->mapLayer(layerId));
		if (vl)
		{
			QgsDataProvider::ProviderOptions options;
			QString source = newFilename;
			if (!newLayerName.isEmpty())
				source += QStringLiteral("|layername=%1").arg(newLayerName);
			vl->setDataSource(source, vl->name(), QStringLiteral("ogr"), options);
			vl->triggerRepaint();
			this->visibleMessageBar()->pushMessage(tr("Layer Saved"),
				tr("Successfully saved scratch layer to <a href=\"%1\">%2</a>").arg(QUrl::fromLocalFile(newFilename).toString(), QDir::toNativeSeparators(newFilename)),
				Qgis::Success, messageTimeout());
		}
	};

	auto onFailure = [](int error, const QString & errorMessage)
	{
		if (error != QgsVectorFileWriter::Canceled)
		{
			QgsMessageViewer *m = new QgsMessageViewer(nullptr);
			m->setWindowTitle(tr("Save Error"));
			m->setMessageAsPlainText(tr("Could not make temporary scratch layer permanent.\nError: %1").arg(errorMessage));
			m->exec();
		}
	};

	saveAsVectorFileGeneral(layer, true, false, true, onSuccess, onFailure, 0, tr("Save Scratch Layer"));
}

void GgsApp::layerProperties()
{
	showLayerProperties(activeLayer());
}

QgsMessageBar * GgsApp::messageBar()
{
	return mInfoBar;
}

void GgsApp::updateNewLayerInsertionPoint()
{
	QgsLayerTreeRegistryBridge::InsertionPoint insertionPoint = layerTreeInsertionPoint();
	QgsProject::instance()->layerTreeRegistryBridge()->setLayerInsertionPoint(insertionPoint);
}

void GgsApp::autoSelectAddedLayer(QList<QgsMapLayer *> layers)
{
	if (!layers.isEmpty())
	{
		QgsLayerTreeLayer *nodeLayer = QgsProject::instance()->layerTreeRoot()->findLayer(layers[0]->id());

		if (!nodeLayer)
			return;

		QModelIndex index = mLayerTreeView->layerTreeModel()->node2index(nodeLayer);
		mLayerTreeView->setCurrentIndex(index);
	}
}

QgsMapCanvas * GgsApp::mapCanvas()
{
	Q_ASSERT(mMapCanvas);
	return mMapCanvas;
}

bool GgsApp::askUserForDatumTransform(const QgsCoordinateReferenceSystem &sourceCrs, const QgsCoordinateReferenceSystem &destinationCrs, const QgsMapLayer *layer /*= nullptr*/)
{
	Q_ASSERT(qApp->thread() == QThread::currentThread());

	QString title;
	if (layer)
	{
		// try to make a user-friendly (short!) identifier for the layer
		QString layerIdentifier;
		if (!layer->name().isEmpty())
		{
			layerIdentifier = layer->name();
		}
		else
		{
			const QVariantMap parts = QgsProviderRegistry::instance()->decodeUri(layer->providerType(), layer->source());
			if (parts.contains(QStringLiteral("path")))
			{
				const QFileInfo fi(parts.value(QStringLiteral("path")).toString());
				layerIdentifier = fi.fileName();
			}
			else if (layer->dataProvider())
			{
				const QgsDataSourceUri uri(layer->source());
				layerIdentifier = uri.table();
			}
		}
		if (!layerIdentifier.isEmpty())
			title = tr("Select Transformation for %1").arg(layerIdentifier);
	}

	return QgsDatumTransformDialog::run(sourceCrs, destinationCrs, this, mMapCanvas, title);
}

static QStringList splitSubLayerDef(const QString &subLayerDef)
{
	return subLayerDef.split(QgsDataProvider::sublayerSeparator());
}

QList< QgsMapLayer * > GgsApp::askUserForOGRSublayers(QgsVectorLayer *&parentLayer, const QStringList &sublayers)
{
	QList<QgsMapLayer *> result;
	
	QgsSublayersDialog::LayerDefinitionList list;
	QMap< QString, int > mapLayerNameToCount;
	bool uniqueNames = true;
	int lastLayerId = -1;
	const auto constSublayers = sublayers;
	for (const QString &sublayer : constSublayers)
	{
		// OGR provider returns items in this format:
		// <layer_index>:<name>:<feature_count>:<geom_type>

		QStringList elements = splitSubLayerDef(sublayer);
		if (elements.count() >= 4)
		{
			QgsSublayersDialog::LayerDefinition def;
			def.layerId = elements[0].toInt();
			def.layerName = elements[1];
			def.count = elements[2].toInt();
			def.type = elements[3];
			// ignore geometry column name at elements[4]
			if (elements.count() >= 6)
				def.description = elements[5];
			if (lastLayerId != def.layerId)
			{
				int count = ++mapLayerNameToCount[def.layerName];
				if (count > 1 || def.layerName.isEmpty())
					uniqueNames = false;
				lastLayerId = def.layerId;
			}
			list << def;
		}
		else
		{
			QgsDebugMsg("Unexpected output from OGR provider's subLayers()! " + sublayer);
		}
	}

	// Check if the current layer uri contains the

	// We initialize a selection dialog and display it.
	QgsSublayersDialog chooseSublayersDialog(QgsSublayersDialog::Ogr, QStringLiteral("ogr"), this, Qt::WindowFlags(), parentLayer->dataProvider()->dataSourceUri());
	chooseSublayersDialog.setShowAddToGroupCheckbox(true);
	chooseSublayersDialog.populateLayerTable(list);

	if (!chooseSublayersDialog.exec())
	{
		delete parentLayer;
		parentLayer = nullptr;
		return result;
	}

	const bool addToGroup = chooseSublayersDialog.addToGroupCheckbox();

	QString name = parentLayer->name();

	auto uriParts = QgsProviderRegistry::instance()->decodeUri(
		parentLayer->providerType(), parentLayer->dataProvider()->dataSourceUri());
	QString uri(uriParts.value(QStringLiteral("path")).toString());
	QStringList openOptions(uriParts.value(QStringLiteral("openOptions")).toStringList());

	// The uri must contain the actual uri of the vectorLayer from which we are
	// going to load the sublayers.
	QString fileName = QFileInfo(uri).baseName();
	const auto constSelection = chooseSublayersDialog.selection();
	const QString providerType = parentLayer->providerType();

	if (name.isEmpty())
	{
		name = fileName;
	}

	// We delete the parent layer now, to be sure in the GeoPackage case that
	// when several sublayers are selected, they will use the same GDAL dataset
	// This is critical to make project transactions work, as in
	// https://github.com/qgis/QGIS/issues/39431#issuecomment-713460189
	delete parentLayer;
	parentLayer = nullptr;

	for (const QgsSublayersDialog::LayerDefinition &def : constSelection)
	{
		QVariantMap newUriParts;
		newUriParts.insert(QStringLiteral("path"), uri);
		QString layerGeometryType = def.type;
		if (uniqueNames)
		{
			newUriParts.insert(QStringLiteral("layerName"), def.layerName);
		}
		else
		{
			// Only use layerId if there are ambiguities with names
			newUriParts.insert(QStringLiteral("layerId"), QString::number(def.layerId));
		}

		if (!layerGeometryType.isEmpty())
		{
			newUriParts.insert(QStringLiteral("geometryType"), layerGeometryType);
		}
		if (!openOptions.isEmpty())
		{
			newUriParts.insert(QStringLiteral("openOptions"), openOptions);
		}

		QString composedURI = QgsProviderRegistry::instance()->encodeUri(
			providerType, newUriParts);
		QgsDebugMsgLevel("Creating new vector layer using " + composedURI, 2);

		// if user has opted to add sublayers to a group, then we don't need to include the
		// filename in the layer's name, because the group is already titled with the filename.
		// But otherwise, we DO include the file name so that users can differentiate the source
		// when multiple layers are loaded from a GPX file or similar (refs https://github.com/qgis/QGIS/issues/37551)
		const QString name = addToGroup ? def.layerName : fileName + " " + def.layerName;

		QgsVectorLayer::LayerOptions options{ QgsProject::instance()->transformContext() };
		options.loadDefaultStyle = false;
		QgsVectorLayer *layer = new QgsVectorLayer(composedURI, name, QStringLiteral("ogr"), options);
		if (layer && layer->isValid())
		{
			result << layer;
		}
		else
		{
			QString msg = tr("%1 is not a valid or recognized data source").arg(composedURI);
			visibleMessageBar()->pushMessage(tr("Invalid Data Source"), msg, Qgis::Critical, messageTimeout());
			delete layer;
		}
	}

	if (!result.isEmpty())
	{
		QgsSettings settings;
		bool newLayersVisible = settings.value(QStringLiteral("/qgis/new_layers_visible"), true).toBool();
		QgsLayerTreeGroup *group = nullptr;
		if (addToGroup)
			group = QgsProject::instance()->layerTreeRoot()->insertGroup(0, name);

		QgsProject::instance()->addMapLayers(result, !addToGroup);
		for (QgsMapLayer *l : qgis::as_const(result))
		{
			bool ok;
			l->loadDefaultStyle(ok);
			l->loadDefaultMetadata(ok);
			if (addToGroup)
				group->addLayer(l);
		}

		// Respect if user don't want the new group of layers visible.
		if (addToGroup && !newLayersVisible)
			group->setItemVisibilityCheckedRecursive(newLayersVisible);
	}
	return result;
}

bool GgsApp::askUserForZipItemLayers(const QString &path)
{
	bool ok = false;
	QVector<QgsDataItem *> childItems;
	QgsZipItem *zipItem = nullptr;
	QgsSettings settings;
	QgsSublayersDialog::PromptMode promptLayers = settings.enumValue(QStringLiteral("qgis/promptForSublayers"), QgsSublayersDialog::PromptAlways);

	QgsDebugMsgLevel("askUserForZipItemLayers( " + path + ')', 2);

	// if scanZipBrowser == no: skip to the next file
	if (settings.value(QStringLiteral("qgis/scanZipInBrowser2"), "basic").toString() == QLatin1String("no"))
	{
		return false;
	}

	zipItem = new QgsZipItem(nullptr, path, path);
	if (!zipItem)
		return false;

	zipItem->populate(true);
	QgsDebugMsgLevel(QStringLiteral("Path= %1 got zipitem with %2 children").arg(path).arg(zipItem->rowCount()), 2);

	// if 1 or 0 child found, exit so a normal item is created by gdal or ogr provider
	if (zipItem->rowCount() <= 1)
	{
		delete zipItem;
		return false;
	}

	switch (promptLayers)
	{
		// load all layers without prompting
	case QgsSublayersDialog::PromptLoadAll:
		childItems = zipItem->children();
		break;
		// return because we should not prompt at all
	case QgsSublayersDialog::PromptNever:
		delete zipItem;
		return false;
		// initialize a selection dialog and display it.
	case QgsSublayersDialog::PromptAlways:
	case QgsSublayersDialog::PromptIfNeeded:
		QgsSublayersDialog chooseSublayersDialog(QgsSublayersDialog::Vsifile, QStringLiteral("vsi"), this, Qt::WindowFlags(), path);
		QgsSublayersDialog::LayerDefinitionList layers;

		for (int i = 0; i < zipItem->children().size(); i++)
		{
			QgsDataItem *item = zipItem->children().at(i);
			QgsLayerItem *layerItem = qobject_cast<QgsLayerItem *>(item);
			if (!layerItem)
				continue;

			QgsDebugMsgLevel(QStringLiteral("item path=%1 provider=%2").arg(item->path(), layerItem->providerKey()), 2);

			QgsSublayersDialog::LayerDefinition def;
			def.layerId = i;
			def.layerName = item->name();
			if (layerItem->providerKey() == QLatin1String("gdal"))
			{
				def.type = tr("Raster");
			}
			else if (layerItem->providerKey() == QLatin1String("ogr"))
			{
				def.type = tr("Vector");
			}
			layers << def;
		}

		chooseSublayersDialog.populateLayerTable(layers);

		if (chooseSublayersDialog.exec())
		{
			const auto constSelection = chooseSublayersDialog.selection();
			for (const QgsSublayersDialog::LayerDefinition &def : constSelection)
			{
				childItems << zipItem->children().at(def.layerId);
			}
		}

		break;
	}

	if (childItems.isEmpty())
	{
		// return true so dialog doesn't popup again (#6225) - hopefully this doesn't create other trouble
		ok = true;
	}

	// add childItems
	const auto constChildItems = childItems;
	for (QgsDataItem *item : constChildItems)
	{
		QgsLayerItem *layerItem = qobject_cast<QgsLayerItem *>(item);
		if (!layerItem)
			continue;

		QgsDebugMsgLevel(QStringLiteral("item path=%1 provider=%2").arg(item->path(), layerItem->providerKey()), 2);
		if (layerItem->providerKey() == QLatin1String("gdal"))
		{
			if (addRasterLayer(item->path(), QFileInfo(item->name()).completeBaseName()))
				ok = true;
		}
		else if (layerItem->providerKey() == QLatin1String("ogr"))
		{
			if (addVectorLayers(QStringList(item->path()), QString(), QStringLiteral("file")))
				ok = true;
		}
	}

	delete zipItem;
	return ok;
}

bool GgsApp::shouldAskUserForGDALSublayers(QgsRasterLayer *layer)
{
	// return false if layer is empty or raster has no sublayers
	if (!layer || layer->providerType() != QLatin1String("gdal") || layer->subLayers().empty())
		return false;

	QgsSettings settings;
	QgsSublayersDialog::PromptMode promptLayers = settings.enumValue(QStringLiteral("qgis/promptForSublayers"), QgsSublayersDialog::PromptAlways);

	return  promptLayers == QgsSublayersDialog::PromptAlways ||
		promptLayers == QgsSublayersDialog::PromptLoadAll ||
		(promptLayers == QgsSublayersDialog::PromptIfNeeded && layer->bandCount() == 0);
}

QList< QgsMapLayer * > GgsApp::askUserForGDALSublayers(QgsRasterLayer *layer)
{
	QList< QgsMapLayer * > result;
	if (!layer)
		return result;

	QStringList sublayers = layer->subLayers();
	QgsDebugMsgLevel(QStringLiteral("raster has %1 sublayers").arg(layer->subLayers().size()), 2);

	if (sublayers.empty())
		return result;

	// if promptLayers=Load all, load all sublayers without prompting
	QgsSettings settings;
	if (settings.enumValue(QStringLiteral("qgis/promptForSublayers"), QgsSublayersDialog::PromptAlways) == QgsSublayersDialog::PromptLoadAll)
	{
		result.append(loadGDALSublayers(layer->source(), sublayers));
		return result;
	}

	// We initialize a selection dialog and display it.
	QgsSublayersDialog chooseSublayersDialog(QgsSublayersDialog::Gdal, QStringLiteral("gdal"), this, Qt::WindowFlags(), layer->dataProvider()->dataSourceUri());
	chooseSublayersDialog.setShowAddToGroupCheckbox(true);

	QgsSublayersDialog::LayerDefinitionList layers;
	QStringList names;
	names.reserve(sublayers.size());
	layers.reserve(sublayers.size());
	for (int i = 0; i < sublayers.size(); i++)
	{
		// simplify raster sublayer name - should add a function in gdal provider for this?
		// code is copied from QgsGdalLayerItem::createChildren
		QString name = sublayers[i];
		QString path = layer->source();
		// if netcdf/hdf use all text after filename
		// for hdf4 it would be best to get description, because the subdataset_index is not very practical
		if (name.startsWith(QLatin1String("netcdf"), Qt::CaseInsensitive) ||
			name.startsWith(QLatin1String("hdf"), Qt::CaseInsensitive))
		{
			name = name.mid(name.indexOf(path) + path.length() + 1);
		}
		else if (name.startsWith(QLatin1String("GPKG"), Qt::CaseInsensitive))
		{
			const auto parts{ name.split(':') };
			if (parts.count() >= 3)
			{
				name = parts.at(parts.count() - 1);
			}
		}
		else
		{
			// remove driver name and file name
			name.remove(name.split(QgsDataProvider::sublayerSeparator())[0]);
			name.remove(path);
		}
		// remove any : or " left over
		if (name.startsWith(':'))
			name.remove(0, 1);

		if (name.startsWith('\"'))
			name.remove(0, 1);

		if (name.endsWith(':'))
			name.chop(1);

		if (name.endsWith('\"'))
			name.chop(1);

		names << name;

		QgsSublayersDialog::LayerDefinition def;
		def.layerId = i;
		def.layerName = name;
		layers << def;
	}

	chooseSublayersDialog.populateLayerTable(layers);

	if (chooseSublayersDialog.exec())
	{
		// create more informative layer names, containing filename as well as sublayer name
		QRegExp rx("\"(.*)\"");
		QString uri, name;

		QgsLayerTreeGroup *group = nullptr;
		bool addToGroup = settings.value(QStringLiteral("/qgis/openSublayersInGroup"), true).toBool();
		bool newLayersVisible = settings.value(QStringLiteral("/qgis/new_layers_visible"), true).toBool();
		if (addToGroup)
		{
			group = QgsProject::instance()->layerTreeRoot()->insertGroup(0, layer->name());
		}

		const auto constSelection = chooseSublayersDialog.selection();
		for (const QgsSublayersDialog::LayerDefinition &def : constSelection)
		{
			int i = def.layerId;
			if (rx.indexIn(sublayers[i]) != -1)
			{
				uri = rx.cap(1);
				name = sublayers[i];
				name.replace(uri, QFileInfo(uri).completeBaseName());
			}
			else
			{
				name = names[i];
			}

			QgsRasterLayer *rlayer = new QgsRasterLayer(sublayers[i], name);
			if (rlayer && rlayer->isValid())
			{
				if (addToGroup)
				{
					QgsProject::instance()->addMapLayer(rlayer, false);
					group->addLayer(rlayer);
				}
				else
				{
					addRasterLayer(rlayer);
				}
				result << rlayer;
			}
		}

		// Respect if user don't want the new group of layers visible.
		if (addToGroup && !newLayersVisible)
			group->setItemVisibilityCheckedRecursive(newLayersVisible);
	}
	return result;
}

QList<QgsMapLayer *> GgsApp::loadGDALSublayers(const QString &uri, const QStringList &list)
{
	QList< QgsMapLayer * > result;
	QString path, name;
	QgsRasterLayer *subLayer = nullptr;
	QgsSettings settings;
	QgsLayerTreeGroup *group = nullptr;
	bool addToGroup = settings.value(QStringLiteral("/qgis/openSublayersInGroup"), true).toBool();
	if (addToGroup)
		group = QgsProject::instance()->layerTreeRoot()->insertGroup(0, QFileInfo(uri).completeBaseName());

	//add layers in reverse order so they appear in the right order in the layer dock
	for (int i = list.size() - 1; i >= 0; i--)
	{
		path = list[i];
		// shorten name by replacing complete path with filename
		name = path;
		name.replace(uri, QFileInfo(uri).completeBaseName());
		subLayer = new QgsRasterLayer(path, name);
		if (subLayer)
		{
			if (subLayer->isValid())
			{
				if (addToGroup)
				{
					QgsProject::instance()->addMapLayer(subLayer, false);
					group->addLayer(subLayer);
				}
				else
				{
					addRasterLayer(subLayer);
				}
				result << subLayer;
			}
			else
				delete subLayer;
		}

	}
	return result;
}

void GgsApp::freezeCanvases(bool frozen /*= true*/)
{
	const auto canvases = mapCanvases();
	for (QgsMapCanvas *canvas : canvases)
	{
		canvas->freeze(frozen);
	}
}

void GgsApp::showStatusMessage(const QString &message)
{
	mStatusBar->showMessage(message);
}

void GgsApp::dataSourceManager(const QString &pageName /*= QString()*/)
{
	if (!mDataSourceManagerDialog)
	{
		mDataSourceManagerDialog = new QgsDataSourceManagerDialog(mBrowserModel, this, mapCanvas());
		connect(this, &GgsApp::connectionsChanged, mDataSourceManagerDialog, &QgsDataSourceManagerDialog::refresh);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::connectionsChanged, this, &GgsApp::connectionsChanged);
		connect(mDataSourceManagerDialog, SIGNAL(addRasterLayer(QString const &, QString const &, QString const &)),
			this, SLOT(addRasterLayer(QString const &, QString const &, QString const &)));
		connect(mDataSourceManagerDialog, SIGNAL(addVectorLayer(QString const &, QString const &, QString const &)),
			this, SLOT(addVectorLayer(QString const &, QString const &, QString const &)));
		connect(mDataSourceManagerDialog, SIGNAL(addVectorLayers(QStringList const &, QString const &, QString const &)),
			this, SLOT(addVectorLayers(QStringList const &, QString const &, QString const &)));
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::addVectorTileLayer, this, &GgsApp::addVectorTileLayer);
		connect(mDataSourceManagerDialog, static_cast<void (QgsDataSourceManagerDialog::*)()>(&QgsDataSourceManagerDialog::addRasterLayer), 
			this, static_cast<void (GgsApp::*)()>(&GgsApp::addRasterLayer));
		/*connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::addMeshLayer, this, &QgisApp::addMeshLayer);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::showStatusMessage, this, &QgisApp::showStatusMessage);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::addDatabaseLayers, this, &QgisApp::addDatabaseLayers);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::replaceSelectedVectorLayer, this, &QgisApp::replaceSelectedVectorLayer);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::handleDropUriList, this, &QgisApp::handleDropUriList);
		connect(this, &QgisApp::newProject, mDataSourceManagerDialog, &QgsDataSourceManagerDialog::updateProjectHome);
		connect(mDataSourceManagerDialog, &QgsDataSourceManagerDialog::openFile, this, &QgisApp::openFile);*/

	}
	else
	{
		mDataSourceManagerDialog->reset();
	}
	// Try to open the dialog on a particular page
	if (!pageName.isEmpty())
	{
		mDataSourceManagerDialog->openPage(pageName);
	}
	if (QgsSettings().value(QStringLiteral("/qgis/dataSourceManagerNonModal"), true).toBool())
	{
		mDataSourceManagerDialog->show();
	}
	else
	{
		mDataSourceManagerDialog->exec();
	}
}

void GgsApp::setAppStyleSheet(const QString &stylesheet)
{
	setStyleSheet(stylesheet);
}

void GgsApp::layerTreeViewDoubleClicked(const QModelIndex &index)
{
	QgsSettings settings;
	switch (settings.value(QStringLiteral("qgis/legendDoubleClickAction"), 0).toInt())
	{
	case 0:
	{
		//show properties
		if (mLayerTreeView)
		{
			// if it's a legend node, open symbol editor directly
			if (QgsSymbolLegendNode *node = qobject_cast<QgsSymbolLegendNode *>(mLayerTreeView->currentLegendNode()))
			{
				const QgsSymbol *originalSymbol = node->symbol();
				if (!originalSymbol)
					return;

				std::unique_ptr< QgsSymbol > symbol(originalSymbol->clone());
				QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(node->layerNode()->layer());
				QgsSymbolSelectorDialog dlg(symbol.get(), QgsStyle::defaultStyle(), vlayer, this);
				QgsSymbolWidgetContext context;
				context.setMapCanvas(mMapCanvas);
				context.setMessageBar(mInfoBar);
				dlg.setContext(context);
				if (dlg.exec())
				{
					node->setSymbol(symbol.release());
				}

				return;
			}
		}
		this->layerProperties();
		break;
	}
	case 1:
	{
		QgsSettings settings;
		QgsAttributeTableFilterModel::FilterMode initialMode = settings.enumValue(QStringLiteral("qgis/attributeTableBehavior"), QgsAttributeTableFilterModel::ShowAll);
		this->attributeTable(initialMode);
		break;
	}
	case 2:
		mapStyleDock(true);
		break;
	default:
		break;
	}
}

void GgsApp::activateDeactivateLayerRelatedActions(QgsMapLayer *layer)
{
	// 功能可用切换处理
}

void GgsApp::onActiveLayerChanged(QgsMapLayer *layer)
{
	if (mBlockActiveLayerChanged)
		return;

	const QList< QgsMapCanvas * > canvases = mapCanvases();
	for (QgsMapCanvas *canvas : canvases)
		canvas->setCurrentLayer(layer);

	if (mUndoWidget)
	{
		if (layer)
		{
			mUndoWidget->setUndoStack(layer->undoStack());
		}
		else
		{
			mUndoWidget->unsetStack();
		}
		updateUndoActions();
	}

	emit activeLayerChanged(layer);
}

void GgsApp::updateFilterLegend()
{
	bool hasExpressions = mLegendExpressionFilterButton->isChecked() && QgsLayerTreeUtils::hasLegendFilterExpression(*mLayerTreeView->layerTreeModel()->rootGroup());
	if (mActionFilterLegend->isChecked() || hasExpressions)
	{
		layerTreeView()->layerTreeModel()->setLegendFilter(&mMapCanvas->mapSettings(),
			/* useExtent */ mActionFilterLegend->isChecked(),
			/* polygon */ QgsGeometry(),
			hasExpressions);
	}
	else
	{
		layerTreeView()->layerTreeModel()->setLegendFilterByMap(nullptr);
	}
}

void GgsApp::toggleFilterLegendByExpression(bool checked)
{
	QgsLayerTreeNode *node = mLayerTreeView->currentNode();
	if (!node)
		return;

	if (QgsLayerTree::isLayer(node))
	{
		QString e = mLegendExpressionFilterButton->expressionText();
		QgsLayerTreeUtils::setLegendFilterByExpression(*QgsLayerTree::toLayer(node), e, checked);
	}

	updateFilterLegend();
}

void GgsApp::zoomIn()
{
	mMapCanvas->setMapTool(mMapTools.mZoomIn);
}

void GgsApp::zoomOut()
{
	mMapCanvas->setMapTool(mMapTools.mZoomOut);
}

void GgsApp::pan()
{
	mMapCanvas->setMapTool(mMapTools.mPan);
}

void GgsApp::identify()
{
	QMessageBox::information(this, tr("提示信息"), tr("identify功能暂不可用"));
	// 功能暂不可用，需要用到QgsIdentifyResultsDialog，里面涉及到QgisApp的方法
	// mMapCanvas->setMapTool(mMapTools.mIdentify);  
}

void GgsApp::selectFeatures()
{
	mMapCanvas->setMapTool(mMapTools.mSelectFeatures);
}

void GgsApp::selectByPolygon()
{
	mMapCanvas->setMapTool(mMapTools.mSelectPolygon);
}

void GgsApp::selectByFreehand()
{
	mMapCanvas->setMapTool(mMapTools.mSelectFreehand);
}

void GgsApp::selectByRadius()
{
	QMessageBox::information(this, tr("提示"), tr("该功能暂不可用！"));
	//mMapCanvas->setMapTool(mMapTools.mSelectRadius);
}

void GgsApp::showPanMessage(double distance, QgsUnitTypes::DistanceUnit unit, double bearing)
{
	const bool showMessage = QgsSettings().value(QStringLiteral("showPanDistanceInStatusBar"), true, QgsSettings::App).toBool();
	if (!showMessage)
		return;

	const double distanceInProjectUnits = distance * QgsUnitTypes::fromUnitToUnitFactor(unit, QgsProject::instance()->distanceUnits());
	const int distanceDecimalPlaces = QgsSettings().value(QStringLiteral("qgis/measure/decimalplaces"), "3").toInt();
	const QString distanceString = QgsDistanceArea::formatDistance(distanceInProjectUnits, distanceDecimalPlaces, QgsProject::instance()->distanceUnits());
	const QString bearingString = mBearingNumericFormat->formatDouble(bearing, QgsNumericFormatContext());
	mStatusBar->showMessage(tr("平移距离 %1 (%2)").arg(distanceString, bearingString), 2000);
}

void GgsApp::selectionModeChanged(QgsMapToolSelect::Mode mode)
{
	switch (mode)
	{
	case QgsMapToolSelect::GeometryIntersectsSetSelection:
		mStatusBar->showMessage(QString());
		break;
	case QgsMapToolSelect::GeometryIntersectsAddToSelection:
		mStatusBar->showMessage(tr("Add to the current selection"));
		break;

	case QgsMapToolSelect::GeometryIntersectsSubtractFromSelection:
		mStatusBar->showMessage(tr("Subtract from the current selection"));
		break;

	case QgsMapToolSelect::GeometryIntersectsIntersectWithSelection:
		mStatusBar->showMessage(tr("Intersect with the current selection"));
		break;

	case QgsMapToolSelect::GeometryWithinSetSelection:
		mStatusBar->showMessage(tr("Select features completely within"));
		break;

	case QgsMapToolSelect::GeometryWithinAddToSelection:
		mStatusBar->showMessage(tr("Add features completely within to the current selection"));
		break;

	case QgsMapToolSelect::GeometryWithinSubtractFromSelection:
		mStatusBar->showMessage(tr("Subtract features completely within from the current selection"));
		break;

	case QgsMapToolSelect::GeometryWithinIntersectWithSelection:
		mStatusBar->showMessage(tr("Intersect features completely within with the current selection"));
		break;

	}
}

void GgsApp::SelectNode(bool bChecked)
{
	if (bChecked) {
		mLWOInteraction->mute();
		mMapTools.mGraphSelect->setSelectionMode(GgsGraphMapToolSelectionHandler::SelectSimple);
		mMapTools.mGraphSelect->setSelectionFeatureMode(GgsGraphMapToolSelect::NodeOnly);
		mMapCanvas->setMapTool(mMapTools.mGraphSelect);

		GgsGraphProject::instance()->currentSelection();

		actionSelectEdge->setChecked(!bChecked);
		actionSelectNodeAndEdge->setChecked(!bChecked);
		actionSelectNodeAndAdjEdges->setChecked(!bChecked);
	}
	else {
		deselectAll();
		mMapCanvas->setMapTool(mMapTools.mPan);
	}
}

void GgsApp::selectEdge(bool bChecked)
{
	if (bChecked) {
		mLWOInteraction->mute();
		mMapTools.mGraphSelect->setSelectionMode(GgsGraphMapToolSelectionHandler::SelectSimple);
		mMapTools.mGraphSelect->setSelectionFeatureMode(GgsGraphMapToolSelect::EdgeOnly);
		mMapCanvas->setMapTool(mMapTools.mGraphSelect);

		GgsGraphProject::instance()->currentSelection();

		actionSelectNode->setChecked(!bChecked);
		actionSelectNodeAndEdge->setChecked(!bChecked);
		actionSelectNodeAndAdjEdges->setChecked(!bChecked);
	}
	else {
		deselectAll();
		mMapCanvas->setMapTool(mMapTools.mPan);
	}
}

void GgsApp::selectNodeAndEdge(bool bChecked)
{
	if (bChecked) {
		mLWOInteraction->mute();
		mMapTools.mGraphSelect->setSelectionMode(GgsGraphMapToolSelectionHandler::SelectSimple);
		mMapTools.mGraphSelect->setSelectionFeatureMode(GgsGraphMapToolSelect::NodeAndEdge);
		mMapCanvas->setMapTool(mMapTools.mGraphSelect);

		GgsGraphProject::instance()->currentSelection();

		actionSelectNode->setChecked(!bChecked);
		actionSelectEdge->setChecked(!bChecked);
		actionSelectNodeAndAdjEdges->setChecked(!bChecked);
	}
	else {
		deselectAll();
		mMapCanvas->setMapTool(mMapTools.mPan);
	}
}

void GgsApp::selectNodeAndAdjEdges(bool bChecked)
{
	if (bChecked) {
		mLWOInteraction->mute();
		mMapTools.mGraphSelect->setSelectionMode(GgsGraphMapToolSelectionHandler::SelectSimple);
		mMapTools.mGraphSelect->setSelectionFeatureMode(GgsGraphMapToolSelect::NodeAndAdjEdges);
		mMapCanvas->setMapTool(mMapTools.mGraphSelect);

		GgsGraphProject::instance()->currentSelection();

		actionSelectNode->setChecked(!bChecked);
		actionSelectEdge->setChecked(!bChecked);
		actionSelectNodeAndEdge->setChecked(!bChecked);
	}
	else {
		deselectAll();
		mMapCanvas->setMapTool(mMapTools.mPan);
	}
}

void GgsApp::clearSelection()
{
	deselectAll();
}

void GgsApp::refreshMapCanvas(bool redrawAllLayers /*= false*/)
{
	const auto canvases = mapCanvases();
	for (QgsMapCanvas *canvas : canvases)
	{
		//stop any current rendering
		canvas->stopRendering();
		if (redrawAllLayers)
			canvas->refreshAllLayers();
		else
			canvas->refresh();
	}
}

void GgsApp::updateMouseCoordinatePrecision()
{
	mCoordsEdit->setMouseCoordinatesPrecision(QgsCoordinateUtils::calculateCoordinatePrecision(mapCanvas()->mapUnitsPerPixel(), mapCanvas()->mapSettings().destinationCrs()));
}

static void setTitleBarText_(QWidget &qgisApp)
{
	QString caption;
	if (QgsProject::instance()->title().isEmpty())
	{
		if (QgsProject::instance()->fileName().isEmpty())
		{
			// new project
			caption = GgsApp::tr("未命名工程");
		}
		else
		{
			caption = QgsProject::instance()->baseName();
		}
	}
	else
	{
		caption = QgsProject::instance()->title();
	}
	if (!caption.isEmpty())
	{
		caption += QStringLiteral(" %1 ").arg(QChar(0x2014));
	}
	if (QgsProject::instance()->isDirty())
		caption.prepend('*');

	caption += GgsApp::tr("geograph");

	if (Qgis::version().endsWith(QLatin1String("Master")))
	{
		caption += QStringLiteral(" %1").arg(Qgis::devVersion());
	}

	/*if (GraphBundling::instance()->userProfileManager()->allProfiles().count() > 1)
	{
		// add current profile (if it's not the default one)
		QgsUserProfile *profile = QgisApp::instance()->userProfileManager()->userProfile();
		if (profile->name() != QLatin1String("default"))
			caption += QStringLiteral(" [%1]").arg(profile->name());
	}*/

	qgisApp.setWindowTitle(caption);
}

bool GgsApp::fileNew(bool promptToSaveFlag, bool forceBlank /*= false*/)
{
	if (checkTasksDependOnProject())
		return false;

	/*if (promptToSaveFlag)
	{
		if (!checkUnsavedLayerEdits() || !checkMemoryLayers() || !saveDirty())
		{
			return false; //cancel pressed
		}
	}*/

	mProjectLastModified = QDateTime();

	QgsSettings settings;

	MAYBE_UNUSED QgsProjectDirtyBlocker dirtyBlocker(QgsProject::instance());
	QgsCanvasRefreshBlocker refreshBlocker;
	//closeProject();

	QgsProject *prj = QgsProject::instance();
	prj->layerTreeRegistryBridge()->setNewLayersVisible(settings.value(QStringLiteral("qgis/new_layers_visible"), true).toBool());

	//set the canvas to the default project background color
	//mOverviewCanvas->setBackgroundColor(prj->backgroundColor());
	//applyProjectSettingsToCanvas(mMapCanvas);

	prj->setDirty(false);

	setTitleBarText_(*this);

	// emit signal so listeners know we have a new project
	emit newProject();

	mMapCanvas->clearExtentHistory();
	mMapCanvas->setRotation(0.0);
	//mScaleWidget->updateScales();

	// set project CRS
	const QgsCoordinateReferenceSystem srs = QgsCoordinateReferenceSystem(settings.value(QStringLiteral("/projections/defaultProjectCrs"), geoEpsgCrsAuthId(), QgsSettings::App).toString());
	// write the projections _proj string_ to project settings
	const bool planimetric = settings.value(QStringLiteral("measure/planimetric"), true, QgsSettings::Core).toBool();
	prj->setCrs(srs, !planimetric); // If the default ellipsoid is not planimetric, set it from the default crs
	if (planimetric)
		prj->setEllipsoid(geoNone());

	/* New Empty Project Created
		(before attempting to load custom project templates/filepaths) */

		// load default template
		/* NOTE: don't open default template on launch until after initialization,
				 in case a project was defined via command line */

				 // don't open template if last auto-opening of a project failed
	if (!forceBlank)
	{
		forceBlank = !settings.value(QStringLiteral("qgis/projOpenedOKAtLaunch"), QVariant(true)).toBool();
	}

	/*if (!forceBlank && settings.value(QStringLiteral("qgis/newProjectDefault"), QVariant(false)).toBool())
	{
		fileNewFromDefaultTemplate();
	}*/

	// set the initial map tool
	mMapCanvas->setMapTool(mMapTools.mPan);
	//mNonEditMapTool = mMapTools.mPan;  // signals are not yet setup to catch this

	prj->setDirty(false);
	return true;
}

void GgsApp::addCSVGraphLayer()
{

	GgsCsvGraphImportDialog dialog(this);
	if (dialog.exec() != QDialog::Accepted) {
		return;
	}

	QgsVectorLayer* nodeLayer = dialog.nodeLayer();
	if (nodeLayer)
	{
		askUserForDatumTransform(nodeLayer->crs(), QgsProject::instance()->crs(), nodeLayer);
		mLayerTreeView->setCurrentLayer(nodeLayer);
	}

	QgsVectorLayer* edgeLayer = dialog.edgeLayer();
	if (edgeLayer)
	{
		askUserForDatumTransform(edgeLayer->crs(), QgsProject::instance()->crs(), edgeLayer);
		mLayerTreeView->setCurrentLayer(edgeLayer);
	}

	GgsGraphProject::instance()->addGraphProxy(dialog.graph());
	this->mapCanvas()->zoomToFullExtent();
}

void GgsApp::addODDataLayer()
{
	GgsODDataImportDialog dialog(this);
	if (dialog.exec() != QDialog::Accepted) {
		return;
	}

	QgsVectorLayer* nodeLayer = dialog.nodeLayer();
	if (nodeLayer)
	{
		askUserForDatumTransform(nodeLayer->crs(), QgsProject::instance()->crs(), nodeLayer);
		mLayerTreeView->setCurrentLayer(nodeLayer);
	}

	QgsVectorLayer* edgeLayer = dialog.edgeLayer();
	if (edgeLayer)
	{
		askUserForDatumTransform(edgeLayer->crs(), QgsProject::instance()->crs(), edgeLayer);
		mLayerTreeView->setCurrentLayer(edgeLayer);
	}

	this->mapCanvas()->zoomToFullExtent();
}

void GgsApp::exportGraphFile()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastCSVGraphDir"), QDir::homePath()).toString();

	QStringList fileFilters;
	fileFilters << tr("GML文件") + QStringLiteral(" (*.gml)")
				<< tr("GraphML文件") + QStringLiteral(" (*.graphml)")
				<< tr("GEXF文件") + QStringLiteral(" (*.gexf)");

	QString saveFileName = QFileDialog::getSaveFileName(this, 
		tr("选择导出的图文件路径"),
		lastUsedDir,
		fileFilters.join(QLatin1String(";;"))
		);

	if (saveFileName.isEmpty())
	{
		return;
	}

	GgsGraphProxy* current = GgsGraphProject::instance()->currentSelection();
	if (!current)
	{
		QMessageBox::information(this, tr("提示"), tr("请选择要导出的图图层！"));
		return;
	}
	else {
		bool bSuccess = ogdf::GraphIO::write(*(current->graphAttributes()), saveFileName.toStdString());
		if (bSuccess)
		{
			QMessageBox::information(this, tr("提示"), tr("导出成功！"));
		}
		else {
			QMessageBox::information(this, tr("提示"), tr("导出失败！请检查路径中是否包含中文！"));
		}
	}
}

void GgsApp::exportCSVGraphFile()
{
	GgsGraphProxy* g = GgsGraphProject::instance()->currentSelection();
	if (!g)
	{
		QMessageBox::information(this, tr("提示"), tr("请选择需要导出的图图层！"));
		return;
	}
	GgsCsvGraphExportDialog dialog(g, this);
	dialog.exec();
}

void GgsApp::showAllLayers()
{
	QgsDebugMsgLevel(QStringLiteral("Showing all layers!"), 3);
	mLayerTreeView->layerTreeModel()->rootGroup()->setItemVisibilityCheckedRecursive(true);
}

void GgsApp::hideAllLayers()
{
	QgsDebugMsgLevel(QStringLiteral("hiding all layers!"), 3);

	const auto constChildren = mLayerTreeView->layerTreeModel()->rootGroup()->children();
	for (QgsLayerTreeNode *node : constChildren)
	{
		node->setItemVisibilityCheckedRecursive(false);
	}
}

void GgsApp::showSelectedLayers()
{
	QgsDebugMsgLevel(QStringLiteral("show selected layers!"), 3);

	const auto constSelectedNodes = mLayerTreeView->selectedNodes();
	for (QgsLayerTreeNode *node : constSelectedNodes)
	{
		QgsLayerTreeNode *nodeIter = node;
		while (nodeIter)
		{
			nodeIter->setItemVisibilityChecked(true);
			nodeIter = nodeIter->parent();
		}
	}
}

void GgsApp::hideSelectedLayers()
{
	QgsDebugMsgLevel(QStringLiteral("hiding selected layers!"), 3);

	const auto constSelectedNodes = mLayerTreeView->selectedNodes();
	for (QgsLayerTreeNode *node : constSelectedNodes)
	{
		node->setItemVisibilityChecked(false);
	}
}

void GgsApp::toggleSelectedLayers()
{
	QgsDebugMsgLevel(QStringLiteral("toggling selected layers!"), 3);

	const auto constSelectedNodes = mLayerTreeView->selectedNodes();
	if (!constSelectedNodes.isEmpty())
	{
		bool isFirstNodeChecked = constSelectedNodes[0]->itemVisibilityChecked();
		for (QgsLayerTreeNode *node : constSelectedNodes)
		{
			node->setItemVisibilityChecked(!isFirstNodeChecked);
		}
	}
}

void GgsApp::toggleSelectedLayersIndependently()
{
	QgsDebugMsgLevel(QStringLiteral("toggling selected layers independently!"), 3);

	const auto constSelectedNodes = mLayerTreeView->selectedNodes();
	if (!constSelectedNodes.isEmpty())
	{
		for (QgsLayerTreeNode *node : constSelectedNodes)
		{
			node->setItemVisibilityChecked(!node->itemVisibilityChecked());
		}
	}
}

void GgsApp::hideDeselectedLayers()
{
	QList<QgsLayerTreeLayer *> selectedLayerNodes = mLayerTreeView->selectedLayerNodes();

	const auto constFindLayers = mLayerTreeView->layerTreeModel()->rootGroup()->findLayers();
	for (QgsLayerTreeLayer *nodeLayer : constFindLayers)
	{
		if (selectedLayerNodes.contains(nodeLayer))
			continue;
		nodeLayer->setItemVisibilityChecked(false);
	}
}

void GgsApp::removeGraphElements()
{
	GgsGraphProxy* current = GgsGraphProject::instance()->currentSelection();

	QgsFeatureList edgeFeatureList = current->edgeLayerProxy()->edgeLayer()->selectedFeatures();
	for each (QgsFeature feature in edgeFeatureList)
	{
		GgsEdgeProxy* pEdge = current->edgeLayerProxy()->findEdge(feature.id());
		current->removeEdgeProxy(pEdge);
	}

	QgsFeatureList nodeFeatureList = current->nodeLayerProxy()->nodeLayer()->selectedFeatures();
	for each (QgsFeature feature in nodeFeatureList)
	{
		GgsNodeProxy* pNode = current->nodeLayerProxy()->findNode(feature.id());
		current->removeNodeProxy(pNode);
	}
}

void GgsApp::showFDEBDockWidget()
{
	if (!mFDEBDockWidget)
	{
		mFDEBDockWidget = new QgsDockWidget(tr("FDEB"), this);
		mFDEBDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
		mFDEBWidget = new GgsFdebWidget(mFDEBDockWidget);
		mFDEBDockWidget->setWidget(mFDEBWidget);
		this->addDockWidget(Qt::RightDockWidgetArea, mFDEBDockWidget);
	}
	else
	{
		mFDEBDockWidget->setUserVisible(true);
	}
}

void GgsApp::showMINGLEDockWidget()
{
	if (!mMINGLEDockWidget)
	{
		mMINGLEDockWidget = new QgsDockWidget(tr("MINGLE"), this);
		mMINGLEDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
		mMINGLEWidget = new GgsMingleWidget(mMINGLEDockWidget);
		mMINGLEDockWidget->setWidget(mMINGLEWidget);
		this->addDockWidget(Qt::RightDockWidgetArea, mMINGLEDockWidget);
	}
	else
	{
		mMINGLEDockWidget->setUserVisible(true);
	}
}

void GgsApp::showKDEEBDockWidget()
{
	if (!mKDEEBDockWidget)
	{
		mKDEEBDockWidget = new QgsDockWidget(tr("KDEEB"), this);
		mKDEEBDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
		mKDEEBWidget = new GgsKdeebWidget(mMapCanvas, mKDEEBDockWidget);
		mKDEEBDockWidget->setWidget(mKDEEBWidget);
		this->addDockWidget(Qt::RightDockWidgetArea, mKDEEBDockWidget);
	}
	else
	{
		mKDEEBDockWidget->setUserVisible(true);
	}
}

void GgsApp::onLocalWindowTriggered(bool bChecked)
{
	if (bChecked) {

		if (!mLwoInteractionWidget)
		{
			mLwoInteractionDockWidget = new QgsDockWidget(tr("LWO Interaction"), this);
			mLwoInteractionDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
			mLwoInteractionWidget = new GgsLwoInteractionWidget(mLWOInteraction, mKDEEBDockWidget);
			mLwoInteractionDockWidget->setWidget(mLwoInteractionWidget);
			this->addDockWidget(Qt::RightDockWidgetArea, mLwoInteractionDockWidget);
		}
		else
		{
			mLwoInteractionDockWidget->setUserVisible(true);
		}

		mLWOInteraction->listen();
		mMapTools.mGraphSelect->setSelectionMode(GgsGraphMapToolSelectionHandler::SelectRadius);
		mMapCanvas->setMapTool(mMapTools.mGraphSelect);
	}
	else {
		deselectAll();
		mMapCanvas->setMapTool(mMapTools.mPan);
		mLWOInteraction->recover();
	}

	mLwoInteractionDockWidget->setUserVisible(bChecked);
}

void GgsApp::cluster()
{
	GgsClusterDialog dialog(this);
	if (dialog.exec() == QDialog::Accepted)
	{
		GgsCluster cluster(dialog.layer());
		
		QgsVectorLayer* pLayer = cluster.cluster(dialog.clusterCount());

		//QgsProject::instance()->addMapLayers(QList<QgsMapLayer *>() << pLayer);
	}
}

void GgsApp::aggregation()
{
	mMapCanvas->mapUnits();
}

void GgsApp::graphStatistic()
{
	QList<GgsGraphProxy*> graphs = GgsGraphProject::instance()->selections();
	if (!graphs.size())
	{
		QMessageBox::information(this, tr("提示"), tr("请选择需要进行分析的图图层！"));
		return;
	}

	GgsGraphStatisticDialog dialog(graphs, this);
	dialog.exec();
}

void GgsApp::similarity()
{
	GgsSimilarityDialog dialog(this);
	dialog.exec();
}

void GgsApp::infoAmount()
{
	GgsGraphProxy* g = GgsGraphProject::instance()->currentSelection();
	if (!g)
	{
		QMessageBox::information(this, tr("提示"), tr("请选择需要计算信息量的图图层！"));
		return;
	}

	GgsGraphInfoAmount amount(g);
	double val = amount.calcInfoAmount();
	QMessageBox::information(this, tr("提示"), tr("图信息量为：%1").arg(QString::number(val)));
}

void GgsApp::backbone()
{
	GgsGraphProxy* g = GgsGraphProject::instance()->currentSelection();
	if (!g)
	{
		QMessageBox::information(this, tr("提示"), tr("请选择需要进行处理的图图层！"));
		return;
	}

	GgsBackboneDialog dialog(g, this);
	dialog.exec();
}

void GgsApp::kcore()
{
	GgsGraphProxy* g = GgsGraphProject::instance()->currentSelection();
	if (!g)
	{
		QMessageBox::information(this, tr("提示"), tr("请选择需要进行处理的图图层！"));
		return;
	}

	GgsKcoreDialog dialog(g, this);
	dialog.exec();
}

void GgsApp::convexHull()
{
	GgsConvexHullDialog dialog(this);
	dialog.exec();
}

bool GgsApp::addRasterLayer(QgsRasterLayer *rasterLayer)
{
	Q_CHECK_PTR(rasterLayer);

	if (!rasterLayer)
	{
		return false;
	}

	if (!rasterLayer->isValid())
	{
		delete rasterLayer;
		return false;
	}

	// register this layer with the central layers registry
	QList<QgsMapLayer *> myList;
	myList << rasterLayer;
	QgsProject::instance()->addMapLayers(myList);

	askUserForDatumTransform(rasterLayer->crs(), QgsProject::instance()->crs(), rasterLayer);

	return true;
}

QgsRasterLayer * GgsApp::addRasterLayer(const QString &rasterFile, const QString &baseName, bool guiWarning /*= true*/)
{
	return addRasterLayerPrivate(rasterFile, baseName, QString(), guiWarning, true);
}

void GgsApp::addRasterLayer()
{
	QStringList selectedFiles;
	QString e;//only for parameter correctness
	QString title = tr("Open a GDAL Supported Raster Data Source");
	QgsGuiUtils::openFilesRememberingFilter(QStringLiteral("lastRasterFileFilter"), mRasterFileFilter, selectedFiles, e,
		title);

	if (selectedFiles.isEmpty())
	{
		// no files were selected, so just bail
		return;
	}

	addRasterLayers(selectedFiles);
}

QgsRasterLayer * GgsApp::addRasterLayer(QString const &uri, QString const &baseName, QString const &providerKey)
{
	return addRasterLayerPrivate(uri, baseName, providerKey, true, true);
}

bool GgsApp::addRasterLayers(const QStringList &fileNameQStringList, bool guiWarning /*= true*/)
{
	if (fileNameQStringList.empty())
	{
		// no files selected so bail out, but
		// allow mMapCanvas to handle events
		// first
		return false;
	}

	QgsCanvasRefreshBlocker refreshBlocker;

	// this is messy since some files in the list may be rasters and others may
	// be ogr layers. We'll set returnValue to false if one or more layers fail
	// to load.
	bool returnValue = true;
	for (QStringList::ConstIterator myIterator = fileNameQStringList.begin();
		myIterator != fileNameQStringList.end();
		++myIterator)
	{
		QString errMsg;
		bool ok = false;

		// if needed prompt for zipitem layers
		QString vsiPrefix = QgsZipItem::vsiPrefix(*myIterator);
		if (!myIterator->startsWith(QLatin1String("/vsi"), Qt::CaseInsensitive) &&
			(vsiPrefix == QLatin1String("/vsizip/") || vsiPrefix == QLatin1String("/vsitar/")))
		{
			if (askUserForZipItemLayers(*myIterator))
				continue;
		}

		if (QgsRasterLayer::isValidRasterFileName(*myIterator, errMsg))
		{
			QFileInfo myFileInfo(*myIterator);

			// set the layer name to the file base name...
			QString layerName = myFileInfo.completeBaseName();

			// ...unless provided explicitly
			const QVariantMap uriDetails = QgsProviderRegistry::instance()->decodeUri(QStringLiteral("gdal"), *myIterator);
			if (!uriDetails[QStringLiteral("layerName")].toString().isEmpty())
			{
				layerName = uriDetails[QStringLiteral("layerName")].toString();
			}

			// try to create the layer
			QgsRasterLayer *layer = addRasterLayerPrivate(*myIterator, layerName,
				QString(), guiWarning, true);
			if (layer && layer->isValid())
			{
				//only allow one copy of a ai grid file to be loaded at a
				//time to prevent the user selecting all adfs in 1 dir which
				//actually represent 1 coverate,

				if (myFileInfo.fileName().endsWith(QLatin1String(".adf"), Qt::CaseInsensitive))
				{
					break;
				}
			}
			// if layer is invalid addRasterLayerPrivate() will show the error

		} // valid raster filename
		else
		{
			ok = false;

			// Issue message box warning unless we are loading from cmd line since
			// non-rasters are passed to this function first and then successfully
			// loaded afterwards (see main.cpp)
			if (guiWarning)
			{
				QString msg = tr("%1 is not a supported raster data source").arg(*myIterator);
				if (!errMsg.isEmpty())
					msg += '\n' + errMsg;

				visibleMessageBar()->pushMessage(tr("Unsupported Data Source"), msg, Qgis::Critical, messageTimeout());
			}
		}
		if (!ok)
		{
			returnValue = false;
		}
	}

	// Let render() do its own cursor management
	//  QApplication::restoreOverrideCursor();

	return returnValue;
}

QgsVectorTileLayer * GgsApp::addVectorTileLayerPrivate(const QString &url, const QString &baseName, bool guiWarning /*= true*/)
{
	QgsCanvasRefreshBlocker refreshBlocker;
	QgsSettings settings;

	QString base(baseName);

	if (settings.value(QStringLiteral("qgis/formatLayerName"), false).toBool())
	{
		base = QgsMapLayer::formatLayerName(base);
	}

	QgsDebugMsgLevel("completeBaseName: " + base, 2);

	// create the layer
	std::unique_ptr<QgsVectorTileLayer> layer(new QgsVectorTileLayer(url, base));

	if (!layer || !layer->isValid())
	{
		if (guiWarning)
		{
			QString msg = tr("%1 is not a valid or recognized data source.").arg(url);
			visibleMessageBar()->pushMessage(tr("Invalid Data Source"), msg, Qgis::Critical, messageTimeout());
		}

		// since the layer is bad, stomp on it
		return nullptr;
	}
	bool ok = false;
	QString error = layer->loadDefaultStyle(ok);
	if (!ok)
		visibleMessageBar()->pushMessage(tr("Error loading style"), error, Qgis::Warning, messageTimeout());
	error = layer->loadDefaultMetadata(ok);
	if (!ok)
		visibleMessageBar()->pushMessage(tr("Error loading layer metadata"), error, Qgis::Warning, messageTimeout());

	QgsProject::instance()->addMapLayer(layer.get());
	activateDeactivateLayerRelatedActions(activeLayer());

	return layer.release();
}

QgsVectorLayer * GgsApp::addVectorLayer(const QString &vectorLayerPath, const QString &name, const QString &providerKey)
{
	return addVectorLayerPrivate(vectorLayerPath, name, providerKey);
}

bool GgsApp::addVectorLayers(const QStringList &layerQStringList, const QString &enc, const QString &dataSourceType)
{
	return addVectorLayersPrivate(layerQStringList, enc, dataSourceType);
}

QgsVectorTileLayer * GgsApp::addVectorTileLayer(const QString &url, const QString &baseName)
{
	return addVectorTileLayerPrivate(url, baseName);
}

void GgsApp::changeDataSource(QgsMapLayer *layer)
{
	QgsMapLayerType layerType(layer->type());

	QgsDataSourceSelectDialog dlg(mBrowserModel, true, layerType);
	if (!layer->isValid())
		dlg.setWindowTitle(tr("Repair Data Source"));

	const QVariantMap sourceParts = QgsProviderRegistry::instance()->decodeUri(layer->providerType(), layer->publicSource());
	QString source = layer->publicSource();
	if (sourceParts.contains(QStringLiteral("path")))
	{
		const QString path = sourceParts.value(QStringLiteral("path")).toString();
		const QString closestPath = QFile::exists(path) ? path : QgsFileUtils::findClosestExistingPath(path);
		source.replace(path, QStringLiteral("<a href=\"%1\">%2</a>").arg(QUrl::fromLocalFile(closestPath).toString(),
			path));
	}
	dlg.setDescription(tr("Original source URI: %1").arg(source));

	const QVariantMap originalSourceParts = QgsProviderRegistry::instance()->decodeUri(layer->providerType(), layer->source());

	if (dlg.exec() == QDialog::Accepted)
	{
		QgsMimeDataUtils::Uri uri(dlg.uri());
		if (uri.isValid())
		{
			auto fixLayer = [this](QgsMapLayer * layer, const QgsMimeDataUtils::Uri & uri)
			{
				bool layerWasValid(layer->isValid());
				// Store subset string from vlayer if we are fixing a bad layer
				QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(layer);
				QString subsetString;
				// Get the subset string directly from the data provider because
				// layer's method will return a null string from invalid layers
				if (vlayer && vlayer->dataProvider() &&
					vlayer->dataProvider()->supportsSubsetString() &&
					!vlayer->dataProvider()->subsetString().isEmpty())
				{
					subsetString = vlayer->dataProvider()->subsetString();
				}
				if (vlayer && subsetString.isEmpty())
				{
					// actually -- the above isn't true in all situations. If a layer was invalid at the time
					// that the subset string was set, then ONLY the layer has knowledge of this subset string!
					subsetString = vlayer->subsetString();
				}

				layer->setDataSource(uri.uri, layer->name(), uri.providerKey, QgsDataProvider::ProviderOptions());
				// Re-apply original style and subset string  when fixing bad layers
				if (!(layerWasValid || layer->originalXmlProperties().isEmpty()))
				{
					if (!subsetString.isEmpty())
					{
						vlayer->setSubsetString(subsetString);
					}
					QgsReadWriteContext context;
					context.setPathResolver(QgsProject::instance()->pathResolver());
					context.setProjectTranslator(QgsProject::instance());
					QString errorMsg;
					QDomDocument doc;
					if (doc.setContent(layer->originalXmlProperties()))
					{
						QDomNode layer_node(doc.firstChild());
						if (!layer->readSymbology(layer_node, errorMsg, context))
						{
							QgsDebugMsg(QStringLiteral("Failed to restore original layer style from stored XML for layer %1: %2")
								.arg(layer->name())
								.arg(errorMsg));
						}
					}
					else
					{
						QgsDebugMsg(QStringLiteral("Failed to create XML QDomDocument for layer %1: %2")
							.arg(layer->name())
							.arg(errorMsg));
					}
				}
				else if (!subsetString.isEmpty())
				{
					vlayer->setSubsetString(subsetString);
				}

				if (vlayer)
					vlayer->updateExtents();

				// All the following code is necessary to refresh the layer
				QgsLayerTreeModel *model = qobject_cast<QgsLayerTreeModel *>(mLayerTreeView->model());
				if (model)
				{
					QgsLayerTreeLayer *tl(model->rootGroup()->findLayer(layer->id()));
					if (tl && tl->itemVisibilityChecked())
					{
						tl->setItemVisibilityChecked(false);
						tl->setItemVisibilityChecked(true);
					}
				}

				// Tell the bridge that we have fixed a layer
				if (!layerWasValid && layer->isValid())
				{
					QgsProject::instance()->layerTreeRoot()->customLayerOrderChanged();
				}
			};

			fixLayer(layer, uri);
			const QVariantMap fixedUriParts = QgsProviderRegistry::instance()->decodeUri(layer->providerType(), layer->source());

			// next, we loop through to see if we can auto-fix any other layers with the same source
			if (originalSourceParts.contains(QStringLiteral("path")))
			{
				const QString originalPath = originalSourceParts.value(QStringLiteral("path")).toString();
				const QFileInfo originalPathFi(originalPath);

				const QMap< QString, QgsMapLayer * > layers = QgsProject::instance()->mapLayers(false);
				for (auto it = layers.begin(); it != layers.end(); ++it)
				{
					if (it.value()->isValid())
						continue;

					QVariantMap thisParts = QgsProviderRegistry::instance()->decodeUri(it.value()->providerType(), it.value()->source());
					if (thisParts.contains(QStringLiteral("path")))
					{
						const QString thisBrokenPath = thisParts.value(QStringLiteral("path")).toString();
						QString fixedPath;

						const QFileInfo thisBrokenPathFi(thisBrokenPath);
						if (thisBrokenPath == originalPath)
						{
							// found a broken layer with the same original path, fix this one too
							fixedPath = fixedUriParts.value(QStringLiteral("path")).toString();
						}
						else if (thisBrokenPathFi.path() == originalPathFi.path())
						{
							// file from same original directory
							QDir fixedDir = QFileInfo(fixedUriParts.value(QStringLiteral("path")).toString()).dir();
							const QString newCandidatePath = fixedDir.filePath(thisBrokenPathFi.fileName());
							if (QFileInfo::exists(newCandidatePath))
								fixedPath = newCandidatePath;
						}

						if (!fixedPath.isEmpty())
						{
							uri.uri = it.value()->source().replace(thisBrokenPath, fixedPath);
							uri.providerKey = it.value()->providerType();
							fixLayer(it.value(), uri);
						}
					}
				}
			}
		}
	}
}

void GgsApp::addVirtualLayer()
{
	QMessageBox::information(this, tr("提示"), tr("addVirtualLayer暂未提供！"));
	/*QDialog *dts = dynamic_cast<QDialog *>(QgsGui::sourceSelectProviderRegistry()->createSelectionWidget(QStringLiteral("virtual"), this, Qt::Widget, QgsProviderRegistry::WidgetMode::Embedded));
	if (!dts)
	{
		QMessageBox::warning(this, tr("Add Virtual Layer"), tr("Cannot get virtual layer select dialog from provider."));
		return;
	}
	connect(dts, SIGNAL(addVectorLayer(QString, QString, QString)),
		this, SLOT(onVirtualLayerAdded(QString, QString)));
	connect(dts, SIGNAL(replaceVectorLayer(QString, QString, QString, QString)),
		this, SLOT(replaceSelectedVectorLayer(QString, QString, QString, QString)));
	dts->exec();
	delete dts;*/
}

void GgsApp::removeLayer()
{
	if (!mLayerTreeView)
	{
		return;
	}

	// look for layers recursively so we catch also those that are within selected groups
	const QList<QgsMapLayer *> selectedLayers = mLayerTreeView->selectedLayersRecursive();

	removeLayers(selectedLayers);
}

void GgsApp::legendGroupSetCrs()
{
	if (!mMapCanvas)
	{
		return;
	}

	QgsLayerTreeGroup *currentGroup = mLayerTreeView->currentGroupNode();
	if (!currentGroup)
		return;

	QgsProjectionSelectionDialog mySelector(this);
	if (!mySelector.exec())
	{
		QApplication::restoreOverrideCursor();
		return;
	}

	QgsCoordinateReferenceSystem crs = mySelector.crs();
	const auto constFindLayers = currentGroup->findLayers();
	for (QgsLayerTreeLayer *nodeLayer : constFindLayers)
	{
		if (nodeLayer->layer())
		{
			nodeLayer->layer()->setCrs(crs);
			nodeLayer->layer()->triggerRepaint();
		}
	}
}

void GgsApp::saveAsLayerDefinition()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastQLRDir"), QDir::homePath()).toString();

	QString path = QFileDialog::getSaveFileName(this, QStringLiteral("Save as Layer Definition File"), lastUsedDir, QStringLiteral("*.qlr"));
	QgsDebugMsgLevel(path, 2);
	if (path.isEmpty())
		return;

	QString errorMessage;
	bool saved = QgsLayerDefinition::exportLayerDefinition(path, mLayerTreeView->selectedNodes(), errorMessage);
	if (!saved)
	{
		visibleMessageBar()->pushMessage(tr("Error saving layer definition file"), errorMessage, Qgis::Warning);
	}

	QFileInfo fi(path);
	settings.setValue(QStringLiteral("UI/lastQLRDir"), fi.path());
}

void GgsApp::setProjectCrsFromLayer()
{
	if (!(mLayerTreeView && mLayerTreeView->currentLayer()))
	{
		return;
	}

	QgsCoordinateReferenceSystem crs = mLayerTreeView->currentLayer()->crs();
	QgsCanvasRefreshBlocker refreshBlocker;
	QgsProject::instance()->setCrs(crs);
}

void GgsApp::setLayerCrs()
{
	if (!(mLayerTreeView && mLayerTreeView->currentLayer()))
	{
		return;
	}

	QgsProjectionSelectionDialog mySelector(this);
	mySelector.setWindowIcon(this->windowIcon());
	mySelector.setCrs(mLayerTreeView->currentLayer()->crs());

	if (!mLayerTreeView->currentLayer()->crs().isValid())
		mySelector.showNoCrsForLayerMessage();

	if (!mySelector.exec())
	{
		QApplication::restoreOverrideCursor();
		return;
	}

	QgsCoordinateReferenceSystem crs = mySelector.crs();

	const auto constSelectedNodes = mLayerTreeView->selectedNodes();
	for (QgsLayerTreeNode *node : constSelectedNodes)
	{
		if (QgsLayerTree::isGroup(node))
		{
			const auto constFindLayers = QgsLayerTree::toGroup(node)->findLayers();
			for (QgsLayerTreeLayer *child : constFindLayers)
			{
				if (child->layer())
				{
					askUserForDatumTransform(crs, QgsProject::instance()->crs(), child->layer());
					child->layer()->setCrs(crs);
					child->layer()->triggerRepaint();
				}
			}
		}
		else if (QgsLayerTree::isLayer(node))
		{
			QgsLayerTreeLayer *nodeLayer = QgsLayerTree::toLayer(node);
			if (nodeLayer->layer())
			{
				askUserForDatumTransform(crs, QgsProject::instance()->crs(), nodeLayer->layer());
				nodeLayer->layer()->setCrs(crs);
				nodeLayer->layer()->triggerRepaint();
			}
		}
	}

	refreshMapCanvas();
}

void GgsApp::deselectAll()
{
	QMap<QString, QgsMapLayer *> layers = QgsProject::instance()->mapLayers();
	for (QMap<QString, QgsMapLayer *>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		QgsVectorLayer *vl = qobject_cast<QgsVectorLayer *>(it.value());
		if (!vl)
			continue;

		vl->removeSelection();
	}
}

void GgsApp::createMenus()
{

}

void GgsApp::createActions()
{
	connect(actionAddVectoLayer, &QAction::triggered, this, [=] { dataSourceManager(QStringLiteral("ogr")); });

	// 视图
	connect(mActionPan, &QAction::triggered, this, &GgsApp::pan);
	connect(mActionZoomIn, &QAction::triggered, this, &GgsApp::zoomIn);
	connect(mActionZoomOut, &QAction::triggered, this, &GgsApp::zoomOut);
	connect(mActionIdentify, &QAction::triggered, this, &GgsApp::identify);
	connect(mActionSelectFeatures, &QAction::triggered, this, &GgsApp::selectFeatures);
	connect(mActionSelectPolygon, &QAction::triggered, this, &GgsApp::selectByPolygon);
	connect(mActionSelectFreehand, &QAction::triggered, this, &GgsApp::selectByFreehand);
	connect(mActionSelectRadius, &QAction::triggered, this, &GgsApp::selectByRadius);

	connect(mActionShowAllLayers, &QAction::triggered, this, &GgsApp::showAllLayers);
	connect(mActionHideAllLayers, &QAction::triggered, this, &GgsApp::hideAllLayers);
	connect(mActionShowSelectedLayers, &QAction::triggered, this, &GgsApp::showSelectedLayers);
	connect(mActionHideSelectedLayers, &QAction::triggered, this, &GgsApp::hideSelectedLayers);
	connect(mActionToggleSelectedLayers, &QAction::triggered, this, &GgsApp::toggleSelectedLayers);
	connect(mActionToggleSelectedLayersIndependently, &QAction::triggered, this, &GgsApp::toggleSelectedLayersIndependently);
	connect(mActionHideDeselectedLayers, &QAction::triggered, this, &GgsApp::hideDeselectedLayers);
	connect(mActionRemoveLayer, &QAction::triggered, this, &GgsApp::removeLayer);

	connect(actionSelectNode, &QAction::triggered, this, &GgsApp::SelectNode);
	connect(actionSelectEdge, &QAction::triggered, this, &GgsApp::selectEdge);
	connect(actionSelectNodeAndEdge, &QAction::triggered, this, &GgsApp::selectNodeAndEdge);
	connect(actionSelectNodeAndAdjEdges, &QAction::triggered, this, &GgsApp::selectNodeAndAdjEdges);
	connect(actionClearSelection, &QAction::triggered, this, &GgsApp::clearSelection);

	// 编辑
	connect(actionRemoveGraphElements, &QAction::triggered, this, &GgsApp::removeGraphElements);

	// 文件
	connect(actionAddCSVGraphLayer, &QAction::triggered, this, &GgsApp::addCSVGraphLayer);
	connect(actionAddODLayer, &QAction::triggered, this, &GgsApp::addODDataLayer);
	connect(actionExportGraphFile, &QAction::triggered, this, &GgsApp::exportGraphFile);
	connect(actionactionExportCSVGraphLayer, &QAction::triggered, this, &GgsApp::exportCSVGraphFile);

	// 处理
	connect(actionAggregation, &QAction::triggered, this, &GgsApp::aggregation);
	connect(actionCluster, &QAction::triggered, this, &GgsApp::cluster);
	connect(actionBackbone, &QAction::triggered, this, &GgsApp::backbone);
	connect(actionKcore, &QAction::triggered, this, &GgsApp::kcore);
	connect(actionConvexHull, &QAction::triggered, this, &GgsApp::convexHull);

	// 捆绑
	connect(actionFDEB, &QAction::triggered, this, &GgsApp::showFDEBDockWidget);
	connect(actionMINGLE, &QAction::triggered, this, &GgsApp::showMINGLEDockWidget);
	connect(actionKDEEB, &QAction::triggered, this, &GgsApp::showKDEEBDockWidget);

	// 交互
	connect(actionLocalWindow, &QAction::triggered, this, &GgsApp::onLocalWindowTriggered);

	// 统计
	connect(actionGraphStatistic, &QAction::triggered, this, &GgsApp::graphStatistic);
	connect(actionSimilarity, &QAction::triggered, this, &GgsApp::similarity);
	connect(actionInfoAmount, &QAction::triggered, this, &GgsApp::infoAmount);
}

void GgsApp::createCanvasTools()
{
	mMapTools.mZoomIn = new QgsMapToolZoom(mMapCanvas, false /* zoomIn */);
	mMapTools.mZoomIn->setAction(mActionZoomIn);
	mMapTools.mZoomOut = new QgsMapToolZoom(mMapCanvas, true /* zoomOut */);
	mMapTools.mZoomOut->setAction(mActionZoomOut);
	mMapTools.mPan = new QgsMapToolPan(mMapCanvas);
	connect(static_cast<QgsMapToolPan *>(mMapTools.mPan), &QgsMapToolPan::panDistanceBearingChanged, this, &GgsApp::showPanMessage);
	mMapTools.mPan->setAction(mActionPan);
	mMapTools.mIdentify = new QgsMapToolIdentifyAction(mMapCanvas);
	mMapTools.mIdentify->setAction(mActionIdentify);
	//connect(mMapTools.mIdentify, &QgsMapToolIdentifyAction::copyToClipboard, this, &QgisApp::copyFeatures);
	mMapTools.mSelectFeatures = new QgsMapToolSelect(mMapCanvas);
	mMapTools.mSelectFeatures->setAction(mActionSelectFeatures);
	mMapTools.mSelectFeatures->setSelectionMode(QgsMapToolSelectionHandler::SelectSimple);
	connect(mMapTools.mSelectFeatures, &QgsMapToolSelect::modeChanged, this, &GgsApp::selectionModeChanged);
	mMapTools.mSelectPolygon = new QgsMapToolSelect(mMapCanvas);
	mMapTools.mSelectPolygon->setAction(mActionSelectPolygon);
	mMapTools.mSelectPolygon->setSelectionMode(QgsMapToolSelectionHandler::SelectPolygon);
	connect(mMapTools.mSelectPolygon, &QgsMapToolSelect::modeChanged, this, &GgsApp::selectionModeChanged);
	mMapTools.mSelectFreehand = new QgsMapToolSelect(mMapCanvas);
	mMapTools.mSelectFreehand->setAction(mActionSelectFreehand);
	mMapTools.mSelectFreehand->setSelectionMode(QgsMapToolSelectionHandler::SelectFreehand);
	connect(mMapTools.mSelectFreehand, &QgsMapToolSelect::modeChanged, this, &GgsApp::selectionModeChanged);
	mMapTools.mSelectRadius = new QgsMapToolSelect(mMapCanvas);
	mMapTools.mSelectRadius->setAction(mActionSelectRadius);
	mMapTools.mSelectRadius->setSelectionMode(QgsMapToolSelectionHandler::SelectRadius);
	connect(mMapTools.mSelectRadius, &QgsMapToolSelect::modeChanged, this, &GgsApp::selectionModeChanged);

	mMapTools.mGraphSelect = new GgsGraphMapToolSelect(mMapCanvas);
}

void GgsApp::createStatusBar()
{
	((QMainWindow*)this)->statusBar()->setStyleSheet(QStringLiteral("QStatusBar::item {border: none;}"));

	QFont statusBarFont = font();
	int fontSize = statusBarFont.pointSize();

	statusBarFont.setPointSize(fontSize);
	((QMainWindow*)this)->statusBar()->setFont(statusBarFont);

	mStatusBar = new QgsStatusBar();
	mStatusBar->setParentStatusBar(QMainWindow::statusBar());
	mStatusBar->setFont(statusBarFont);

	((QMainWindow*)this)->statusBar()->addPermanentWidget(mStatusBar, 10);

	//坐标状态栏
	mCoordsEdit = new QgsStatusBarCoordinatesWidget(mStatusBar);
	mCoordsEdit->setObjectName(QStringLiteral("mCoordsEdit"));
	mCoordsEdit->setMapCanvas(mMapCanvas);
	mCoordsEdit->setFont(statusBarFont);
	mStatusBar->addPermanentWidget(mCoordsEdit, 0);

	mScaleWidget = new QgsStatusBarScaleWidget(mMapCanvas, mStatusBar);
	mScaleWidget->setObjectName(QStringLiteral("mScaleWidget"));
	mScaleWidget->setFont(statusBarFont);
	mStatusBar->addPermanentWidget(mScaleWidget, 0);

	mOnTheFlyProjectionStatusButton = new QToolButton(mStatusBar);
	mOnTheFlyProjectionStatusButton->setAutoRaise(true);
	mOnTheFlyProjectionStatusButton->setFont(statusBarFont);
	mOnTheFlyProjectionStatusButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	mOnTheFlyProjectionStatusButton->setObjectName(QStringLiteral("mOntheFlyProjectionStatusButton"));
	// Maintain uniform widget height in status bar by setting button height same as labels
	// For Qt/Mac 3.3, the default toolbutton height is 30 and labels were expanding to match
	mOnTheFlyProjectionStatusButton->setMaximumHeight(mScaleWidget->height());
	mOnTheFlyProjectionStatusButton->setIcon(QgsApplication::getThemeIcon(QStringLiteral("mIconProjectionEnabled.svg")));
	mOnTheFlyProjectionStatusButton->setToolTip(tr("CRS status - Click "
		"to open coordinate reference system dialog"));
	/*connect(mOnTheFlyProjectionStatusButton, &QAbstractButton::clicked,
		this, &QgisApp::projectPropertiesProjections);//bring up the project props dialog when clicked */
	mStatusBar->addPermanentWidget(mOnTheFlyProjectionStatusButton, 0);
	mStatusBar->showMessage(tr("就绪"));

	// 其它的有需要再加
	// ......

}

void GgsApp::setupConnections()
{
	connect(mMapCanvas, &QgsMapCanvas::scaleChanged, this, &GgsApp::updateMouseCoordinatePrecision);

}

void GgsApp::restoreWindowState()
{
	// restore the toolbar and dock widgets positions using Qt4 settings API
	QgsSettings settings;

	if (!restoreState(settings.value(QStringLiteral("UI/state"), QByteArray::fromRawData(reinterpret_cast<const char *>(defaultUIstate), sizeof defaultUIstate)).toByteArray()))
	{
		QgsDebugMsg(QStringLiteral("restore of UI state failed"));
	}

	if (settings.value(QStringLiteral("UI/hidebrowser"), false).toBool())
	{
		mBrowserWidget->hide();
		//mBrowserWidget2->hide();
		settings.remove(QStringLiteral("UI/hidebrowser"));
	}

	// restore window geometry
	if (!restoreGeometry(settings.value(QStringLiteral("UI/geometry")).toByteArray()))
	{
		QgsDebugMsg(QStringLiteral("restore of UI geometry failed"));
		// default to 80% of screen size, at 10% from top left corner
		resize(QDesktopWidget().availableGeometry(this).size() * 0.8);
		QSize pos = QDesktopWidget().availableGeometry(this).size() * 0.1;
		move(pos.width(), pos.height());
	}
}

bool GgsApp::fileNewBlank()
{
	return fileNew(true, true);
}

void GgsApp::updateCrsStatusBar()
{
	const QgsCoordinateReferenceSystem projectCrs = QgsProject::instance()->crs();
	if (projectCrs.isValid())
	{
		if (!projectCrs.authid().isEmpty())
			mOnTheFlyProjectionStatusButton->setText(projectCrs.authid());
		else
			mOnTheFlyProjectionStatusButton->setText(QObject::tr("Unknown CRS"));

		mOnTheFlyProjectionStatusButton->setToolTip(
			tr("Current CRS: %1").arg(projectCrs.userFriendlyIdentifier()));
		mOnTheFlyProjectionStatusButton->setIcon(QgsApplication::getThemeIcon(QStringLiteral("mIconProjectionEnabled.svg")));
	}
	else
	{
		mOnTheFlyProjectionStatusButton->setText(QString());
		mOnTheFlyProjectionStatusButton->setToolTip(tr("No projection"));
		mOnTheFlyProjectionStatusButton->setIcon(QgsApplication::getThemeIcon(QStringLiteral("mIconProjectionDisabled.svg")));
	}
}

void GgsApp::applyDefaultSettingsToCanvas(QgsMapCanvas *canvas)
{
	QgsSettings settings;
	canvas->enableAntiAliasing(settings.value(QStringLiteral("qgis/enable_anti_aliasing"), true).toBool());
	double zoomFactor = settings.value(QStringLiteral("qgis/zoom_factor"), 2).toDouble();
	canvas->setWheelFactor(zoomFactor);
	canvas->setCachingEnabled(settings.value(QStringLiteral("qgis/enable_render_caching"), true).toBool());
	canvas->setParallelRenderingEnabled(settings.value(QStringLiteral("qgis/parallel_rendering"), true).toBool());
	canvas->setMapUpdateInterval(settings.value(QStringLiteral("qgis/map_update_interval"), 250).toInt());
	canvas->setSegmentationTolerance(settings.value(QStringLiteral("qgis/segmentationTolerance"), "0.01745").toDouble());
	canvas->setSegmentationToleranceType(QgsAbstractGeometry::SegmentationToleranceType(settings.enumValue(QStringLiteral("qgis/segmentationToleranceType"), QgsAbstractGeometry::MaximumAngle)));
}

void GgsApp::initLayerTreeView()
{
	mLayerTreeDock = new QgsDockWidget(tr("图层"), this);
	mLayerTreeDock->setObjectName(QStringLiteral("Layers"));
	mLayerTreeDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

	QShortcut *showLayersTreeDock = new QShortcut(QKeySequence(tr("Ctrl+1")), this);
	connect(showLayersTreeDock, &QShortcut::activated, mLayerTreeDock, &QgsDockWidget::toggleUserVisible);
	showLayersTreeDock->setObjectName(QStringLiteral("ShowLayersPanel"));
	showLayersTreeDock->setWhatsThis(tr("Show Layers Panel"));

	QgsLayerTreeModel *model = new QgsLayerTreeModel(QgsProject::instance()->layerTreeRoot(), this);

	model->setFlag(QgsLayerTreeModel::AllowNodeReorder);
	model->setFlag(QgsLayerTreeModel::AllowNodeRename);
	model->setFlag(QgsLayerTreeModel::AllowNodeChangeVisibility);
	model->setFlag(QgsLayerTreeModel::ShowLegendAsTree);
	model->setFlag(QgsLayerTreeModel::UseEmbeddedWidgets);
	model->setFlag(QgsLayerTreeModel::UseTextFormatting);
	model->setAutoCollapseLegendNodes(10);

	mLayerTreeView->setModel(model);
	mLayerTreeView->setMessageBar(mInfoBar);

	mLayerTreeView->setMenuProvider(new GgsLayerTreeViewMenuProvider(mLayerTreeView, mMapCanvas));
	new QgsLayerTreeViewFilterIndicatorProvider(mLayerTreeView);  // gets parented to the layer view
	new QgsLayerTreeViewEmbeddedIndicatorProvider(mLayerTreeView);  // gets parented to the layer view
	new QgsLayerTreeViewMemoryIndicatorProvider(mLayerTreeView);  // gets parented to the layer view
	new QgsLayerTreeViewTemporalIndicatorProvider(mLayerTreeView); // gets parented to the layer view
	new QgsLayerTreeViewNoCrsIndicatorProvider(mLayerTreeView);  // gets parented to the layer view
	QgsLayerTreeViewBadLayerIndicatorProvider *badLayerIndicatorProvider = new QgsLayerTreeViewBadLayerIndicatorProvider(mLayerTreeView);  // gets parented to the layer view
	connect(badLayerIndicatorProvider, &QgsLayerTreeViewBadLayerIndicatorProvider::requestChangeDataSource, this, &GgsApp::changeDataSource);
	new QgsLayerTreeViewNonRemovableIndicatorProvider(mLayerTreeView);  // gets parented to the layer view

	setupLayerTreeViewFromSettings();

	connect(mLayerTreeView, &QAbstractItemView::doubleClicked, this, &GgsApp::layerTreeViewDoubleClicked);
	connect(mLayerTreeView, &QgsLayerTreeView::currentLayerChanged, this, &GgsApp::onActiveLayerChanged);
	connect(mLayerTreeView->selectionModel(), &QItemSelectionModel::currentChanged, this, &GgsApp::updateNewLayerInsertionPoint);
	connect(QgsProject::instance()->layerTreeRegistryBridge(), &QgsLayerTreeRegistryBridge::addedLayersToLayerTree,
		this, &GgsApp::autoSelectAddedLayer);

	// add group action
	QAction *actionAddGroup = new QAction(tr("添加组"), this);
	actionAddGroup->setIcon(QgsApplication::getThemeIcon(QStringLiteral("/mActionAddGroup.svg")));
	actionAddGroup->setToolTip(tr("添加组"));
	connect(actionAddGroup, &QAction::triggered, mLayerTreeView->defaultActions(), &QgsLayerTreeViewDefaultActions::addGroup);

	// visibility groups tool button
	QToolButton *btnVisibilityPresets = new QToolButton;
	btnVisibilityPresets->setAutoRaise(true);
	btnVisibilityPresets->setToolTip(tr("管理地图主题"));
	btnVisibilityPresets->setIcon(QgsApplication::getThemeIcon(QStringLiteral("/mActionShowAllLayers.svg")));
	btnVisibilityPresets->setPopupMode(QToolButton::InstantPopup);
	btnVisibilityPresets->setMenu(GgsMapThemes::instance()->menu());

	// filter legend action
	mActionFilterLegend = new QAction(tr("按地图内容过滤图例"), this);
	mActionFilterLegend->setCheckable(true);
	mActionFilterLegend->setToolTip(tr("按地图内容过滤图例"));
	mActionFilterLegend->setIcon(QgsApplication::getThemeIcon(QStringLiteral("/mActionFilter2.svg")));
	connect(mActionFilterLegend, &QAction::toggled, this, &GgsApp::updateFilterLegend);

	mLegendExpressionFilterButton = new QgsLegendFilterButton(this);
	mLegendExpressionFilterButton->setToolTip(tr("按表达式过滤图例"));
	connect(mLegendExpressionFilterButton, &QAbstractButton::toggled, this, &GgsApp::toggleFilterLegendByExpression);

	mActionStyleDock = new QAction(tr("图层样式"), this);
	mActionStyleDock->setCheckable(true);
	mActionStyleDock->setToolTip(tr("打开图层样式面板"));
	mActionStyleDock->setShortcut(QStringLiteral("F7"));
	mActionStyleDock->setIcon(QgsApplication::getThemeIcon(QStringLiteral("propertyicons/symbology.svg")));

	connect(mActionStyleDock, &QAction::toggled, this, &GgsApp::mapStyleDock);
	// expand / collapse tool buttons
	QAction *actionExpandAll = new QAction(tr("全部展开"), this);
	actionExpandAll->setIcon(QgsApplication::getThemeIcon(QStringLiteral("/mActionExpandTree.svg")));
	actionExpandAll->setToolTip(tr("全部展开"));
	connect(actionExpandAll, &QAction::triggered, mLayerTreeView, &QgsLayerTreeView::expandAllNodes);
	QAction *actionCollapseAll = new QAction(tr("全部折叠"), this);
	actionCollapseAll->setIcon(QgsApplication::getThemeIcon(QStringLiteral("/mActionCollapseTree.svg")));
	actionCollapseAll->setToolTip(tr("全部折叠"));
	connect(actionCollapseAll, &QAction::triggered, mLayerTreeView, &QgsLayerTreeView::collapseAllNodes);

	QToolBar *toolbar = new QToolBar();
	toolbar->setIconSize(iconSize(true));
	toolbar->addAction(mActionStyleDock);
	toolbar->addAction(actionAddGroup);
	toolbar->addWidget(btnVisibilityPresets);
	toolbar->addAction(mActionFilterLegend);
	toolbar->addWidget(mLegendExpressionFilterButton);
	toolbar->addAction(actionExpandAll);
	toolbar->addAction(actionCollapseAll);
	toolbar->addAction(mActionRemoveLayer); 

	QVBoxLayout *vboxLayout = new QVBoxLayout;
	vboxLayout->setContentsMargins(0, 0, 0, 0);
	vboxLayout->setSpacing(0);
	vboxLayout->addWidget(toolbar);
	vboxLayout->addWidget(mLayerTreeView);

	QWidget *w = new QWidget;
	w->setLayout(vboxLayout);
	mLayerTreeDock->setWidget(w);
	addDockWidget(Qt::LeftDockWidgetArea, mLayerTreeDock);

	mLayerTreeCanvasBridge = new QgsLayerTreeMapCanvasBridge(QgsProject::instance()->layerTreeRoot(), mMapCanvas, this);

	mMapLayerOrder = new QgsCustomLayerOrderWidget(mLayerTreeCanvasBridge, this);
	mMapLayerOrder->setObjectName(QStringLiteral("theMapLayerOrder"));

	mLayerOrderDock = new QgsDockWidget(tr("图层顺序"), this);
	mLayerOrderDock->setObjectName(QStringLiteral("LayerOrder"));
	mLayerOrderDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

	QShortcut *showLayerOrderDock = new QShortcut(QKeySequence(tr("Ctrl+9")), this);
	connect(showLayerOrderDock, &QShortcut::activated, mLayerOrderDock, &QgsDockWidget::toggleUserVisible);
	showLayerOrderDock->setObjectName(QStringLiteral("显示图层顺序面板"));
	showLayerOrderDock->setWhatsThis(tr("显示图层顺序面板"));

	mLayerOrderDock->setWidget(mMapLayerOrder);
	addDockWidget(Qt::LeftDockWidgetArea, mLayerOrderDock);
	mLayerOrderDock->hide();

	connect(mMapCanvas, &QgsMapCanvas::mapCanvasRefreshed, this, &GgsApp::updateFilterLegend);
	connect(mMapCanvas, &QgsMapCanvas::renderErrorOccurred, badLayerIndicatorProvider, &QgsLayerTreeViewBadLayerIndicatorProvider::reportLayerError);
}

void GgsApp::setupLayerTreeViewFromSettings()
{
	QgsSettings s;

	QgsLayerTreeModel *model = mLayerTreeView->layerTreeModel();
	QFont fontLayer, fontGroup;
	fontLayer.setBold(true);
	fontGroup.setBold(false);
	model->setLayerTreeNodeFont(QgsLayerTreeNode::NodeLayer, fontLayer);
	model->setLayerTreeNodeFont(QgsLayerTreeNode::NodeGroup, fontGroup);
}

static void setupVectorLayer(const QString &vectorLayerPath,
	const QStringList &sublayers,
	QgsVectorLayer *&layer,
	const QString &providerKey,
	QgsVectorLayer::LayerOptions options)
{
	//set friendly name for datasources with only one layer
	QgsSettings settings;
	QStringList elements = splitSubLayerDef(sublayers.at(0));
	QString rawLayerName = elements.size() >= 2 ? elements.at(1) : QString();
	QString subLayerNameFormatted = rawLayerName;
	if (settings.value(QStringLiteral("qgis/formatLayerName"), false).toBool())
	{
		subLayerNameFormatted = QgsMapLayer::formatLayerName(subLayerNameFormatted);
	}

	if (elements.size() >= 4 && layer->name().compare(rawLayerName, Qt::CaseInsensitive) != 0
		&& layer->name().compare(subLayerNameFormatted, Qt::CaseInsensitive) != 0)
	{
		layer->setName(QStringLiteral("%1 %2").arg(layer->name(), rawLayerName));
	}

	// Systematically add a layername= option to OGR datasets in case
	// the current single layer dataset becomes layer a multi-layer one.
	// Except for a few select extensions, known to be always single layer dataset.
	QFileInfo fi(vectorLayerPath);
	QString ext = fi.suffix().toLower();
	if (providerKey == QLatin1String("ogr") &&
		ext != QLatin1String("shp") &&
		ext != QLatin1String("mif") &&
		ext != QLatin1String("tab") &&
		ext != QLatin1String("csv") &&
		ext != QLatin1String("geojson") &&
		!vectorLayerPath.contains(QStringLiteral("layerid=")) &&
		!vectorLayerPath.contains(QStringLiteral("layername=")))
	{
		auto uriParts = QgsProviderRegistry::instance()->decodeUri(
			layer->providerType(), layer->dataProvider()->dataSourceUri());
		uriParts.insert(QStringLiteral("layerName"), rawLayerName);
		QString composedURI = QgsProviderRegistry::instance()->encodeUri(
			layer->providerType(), uriParts);

		auto newLayer = qgis::make_unique<QgsVectorLayer>(composedURI, layer->name(), QStringLiteral("ogr"), options);
		if (newLayer && newLayer->isValid())
		{
			delete layer;
			layer = newLayer.release();
		}
	}
}

bool GgsApp::addVectorLayersPrivate(const QStringList &layerQStringList, const QString &enc, const QString &dataSourceType, bool guiWarning /*= true*/)
{
	QList<QgsMapLayer *> layersToAdd;
	QList<QgsMapLayer *> addedLayers;
	QgsSettings settings;
	bool userAskedToAddLayers = false;

	for (QString src : layerQStringList)
	{
		src = src.trimmed();
		QString baseName;
		if (dataSourceType == QLatin1String("file"))
		{
			QString srcWithoutLayername(src);
			int posPipe = srcWithoutLayername.indexOf('|');
			if (posPipe >= 0)
				srcWithoutLayername.resize(posPipe);
			QFileInfo fi(srcWithoutLayername);
			baseName = fi.completeBaseName();

			// if needed prompt for zipitem layers
			QString vsiPrefix = QgsZipItem::vsiPrefix(src);
			if (!src.startsWith(QLatin1String("/vsi"), Qt::CaseInsensitive) &&
				(vsiPrefix == QLatin1String("/vsizip/") || vsiPrefix == QLatin1String("/vsitar/")))
			{
				if (askUserForZipItemLayers(src))
					continue;
			}
		}
		else if (dataSourceType == QLatin1String("database"))
		{
			// Try to extract the database name and use it as base name
			// sublayers names (if any) will be appended to the layer name
			auto parts(QgsProviderRegistry::instance()->decodeUri(QStringLiteral("ogr"), src));
			if (parts.value(QStringLiteral("databaseName")).isValid())
				baseName = parts.value(QStringLiteral("databaseName")).toString();
			else
				baseName = src;
		}
		else //directory //protocol
		{
			QFileInfo fi(src);
			baseName = fi.completeBaseName();
		}
		if (settings.value(QStringLiteral("qgis/formatLayerName"), false).toBool())
		{
			baseName = QgsMapLayer::formatLayerName(baseName);
		}

		QgsDebugMsgLevel("completeBaseName: " + baseName, 2);
		const bool isVsiCurl{ src.startsWith(QLatin1String("/vsicurl"), Qt::CaseInsensitive) };
		const auto scheme{ QUrl(src).scheme() };
		const bool isRemoteUrl{ scheme.startsWith(QLatin1String("http")) || scheme == QLatin1String("ftp") };

		// create the layer
		QgsVectorLayer::LayerOptions options{ QgsProject::instance()->transformContext() };
		options.loadDefaultStyle = false;
		if (isVsiCurl || isRemoteUrl)
		{
			visibleMessageBar()->pushInfo(tr("Remote layer"), tr("loading %1, please wait …").arg(src));
			QApplication::setOverrideCursor(Qt::WaitCursor);
			qApp->processEvents();
		}
		QgsVectorLayer *layer = new QgsVectorLayer(src, baseName, QStringLiteral("ogr"), options);
		Q_CHECK_PTR(layer);
		if (isVsiCurl || isRemoteUrl)
		{
			QApplication::restoreOverrideCursor();
		}
		if (!layer)
		{
			// Let render() do its own cursor management
			//      QApplication::restoreOverrideCursor();

			// XXX insert meaningful whine to the user here
			return false;
		}

		if (layer->isValid())
		{
			userAskedToAddLayers = true;
			if (!enc.isEmpty())
				layer->setProviderEncoding(enc);

			QStringList sublayers = layer->dataProvider()->subLayers();
			QgsDebugMsgLevel(QStringLiteral("got valid layer with %1 sublayers").arg(sublayers.count()), 2);

			// If the newly created layer has more than 1 layer of data available, we show the
			// sublayers selection dialog so the user can select the sublayers to actually load.
			if (sublayers.count() > 1)
			{
				addedLayers.append(askUserForOGRSublayers(layer, sublayers));
				// layer is no longer valid and has been nullified

				for (QgsMapLayer *l : addedLayers)
					askUserForDatumTransform(l->crs(), QgsProject::instance()->crs(), l);
			}
			else if (!sublayers.isEmpty()) // there is 1 layer of data available
			{
				setupVectorLayer(src, sublayers, layer,
					QStringLiteral("ogr"), options);

				layersToAdd << layer;
			}
			else
			{
				if (guiWarning)
				{
					QString msg = tr("%1 doesn't have any layers.").arg(src);
					visibleMessageBar()->pushMessage(tr("Invalid Data Source"), msg, Qgis::Critical, messageTimeout());
				}
				delete layer;
			}
		}
		else
		{
			// since the layer is bad, stomp on it
			delete layer;
			QString msg = tr("%1 is not a valid or recognized data source.").arg(src);
			// If the failed layer was a vsicurl type, give the user a chance to try the normal download.
			if (isVsiCurl &&
				QMessageBox::question(this, tr("Invalid Data Source"),
					tr("Download with \"Protocol\" source type has failed, do you want to try the \"File\" source type?")) == QMessageBox::Yes)
			{
				return addVectorLayersPrivate(QStringList() << src.replace(QLatin1String("/vsicurl/"), " "), enc, dataSourceType, guiWarning);
			}
			else if (guiWarning)
			{
				visibleMessageBar()->pushMessage(tr("Invalid Data Source"), msg, Qgis::Critical, messageTimeout());
			}
		}
	}

	// make sure at least one layer was successfully added
	if (layersToAdd.isEmpty())
	{
		// we also return true if we asked the user for sublayers, but they choose none. In this case nothing
		// went wrong, so we shouldn't return false and cause GUI warnings to appear
		return userAskedToAddLayers || !addedLayers.isEmpty();
	}

	// Register this layer with the layers registry
	QgsProject::instance()->addMapLayers(layersToAdd);
	for (QgsMapLayer *l : qgis::as_const(layersToAdd))
	{
		bool ok;
		l->loadDefaultStyle(ok);
		l->loadDefaultMetadata(ok);
		askUserForDatumTransform(l->crs(), QgsProject::instance()->crs(), l);
	}
	activateDeactivateLayerRelatedActions(activeLayer());

	return true;
}

QgsVectorLayer * GgsApp::addVectorLayerPrivate(const QString &vectorLayerPath, const QString &name, const QString &providerKey, bool guiWarning /*= true*/)
{
	QgsSettings settings;
	QgsCanvasRefreshBlocker refreshBlocker;

	QString baseName = settings.value(QStringLiteral("qgis/formatLayerName"), false).toBool() ? QgsMapLayer::formatLayerName(name) : name;

	// create the layer
	QgsVectorLayer::LayerOptions options{ QgsProject::instance()->transformContext() };
	// Default style is loaded later in this method
	options.loadDefaultStyle = false;
	QgsVectorLayer *layer = new QgsVectorLayer(vectorLayerPath, baseName, providerKey, options);

	if (layer->isValid())
	{
		const bool layerIsSpecified = vectorLayerPath.contains(QLatin1String("layerid=")) ||
			vectorLayerPath.contains(QLatin1String("layername="));

		const QStringList sublayers = layer->dataProvider()->subLayers();
		if (!layerIsSpecified)
		{
			QgsDebugMsgLevel(QStringLiteral("got valid layer with %1 sublayers").arg(sublayers.count()), 2);
		}

		if (!layerIsSpecified && sublayers.count() > 1)
		{
			QList< QgsMapLayer * > addedLayers = askUserForOGRSublayers(layer, sublayers);
			// layer is no longer valid and has been nullified

			layer = addedLayers.isEmpty() ? nullptr : qobject_cast<QgsVectorLayer *>(addedLayers.at(0));
			for (QgsMapLayer *l : addedLayers)
				askUserForDatumTransform(l->crs(), QgsProject::instance()->crs(), l);
		}
		else
		{
			// Register this layer with the layers registry
			QList<QgsMapLayer *> myList;

			//set friendly name for datasources with only one layer
			if (!sublayers.isEmpty())
			{
				setupVectorLayer(vectorLayerPath, sublayers, layer,
					providerKey, options);
			}

			myList << layer;
			QgsProject::instance()->addMapLayers(myList);

			askUserForDatumTransform(layer->crs(), QgsProject::instance()->crs(), layer);

			bool ok;
			layer->loadDefaultStyle(ok);
			layer->loadDefaultMetadata(ok);
		}
	}
	else
	{
		if (guiWarning)
		{
			QString message = layer->dataProvider() ? layer->dataProvider()->error().message(QgsErrorMessage::Text) : tr("Invalid provider");
			QString msg = tr("The layer %1 is not a valid layer and can not be added to the map. Reason: %2").arg(vectorLayerPath, message);
			visibleMessageBar()->pushMessage(tr("Layer is not valid"), msg, Qgis::Critical, messageTimeout());
		}

		delete layer;
		return nullptr;
	}

	// Let render() do its own cursor management
	//  QApplication::restoreOverrideCursor();

	return layer;
}

QgsRasterLayer * GgsApp::addRasterLayerPrivate(const QString &uri, const QString &name, const QString &providerKey, bool guiWarning, bool guiUpdate)
{
	std::unique_ptr< QgsCanvasRefreshBlocker > refreshBlocker;
	if (guiUpdate)
	{
		// let the user know we're going to possibly be taking a while
		// QApplication::setOverrideCursor( Qt::WaitCursor );
		refreshBlocker = qgis::make_unique< QgsCanvasRefreshBlocker >();
	}

	QString shortName = name;
	QRegularExpression reRasterFile(QStringLiteral("^/vsi(.+/)*([^ ]+)( .+)?$"), QRegularExpression::CaseInsensitiveOption);
	QRegularExpressionMatch matchRasterFile = reRasterFile.match(name);

	if (matchRasterFile.hasMatch())
	{
		if (!matchRasterFile.captured(2).isEmpty())
		{
			shortName = matchRasterFile.captured(2);
		}
	}

	QgsSettings settings;
	QString baseName = settings.value(QStringLiteral("qgis/formatLayerName"), false).toBool() ? QgsMapLayer::formatLayerName(shortName) : shortName;

	QgsDebugMsgLevel("Creating new raster layer using " + uri
		+ " with baseName of " + baseName, 2);

	QgsRasterLayer *layer = nullptr;
	// XXX ya know QgsRasterLayer can snip out the basename on its own;
	// XXX why do we have to pass it in for it?
	// ET : we may not be getting "normal" files here, so we still need the baseName argument
	if (!providerKey.isEmpty() && uri.endsWith(QLatin1String(".adf"), Qt::CaseInsensitive))
	{
		QFileInfo fileInfo(uri);
		QString dirName = fileInfo.path();
		layer = new QgsRasterLayer(dirName, QFileInfo(dirName).completeBaseName(), QStringLiteral("gdal"));
	}
	else if (providerKey.isEmpty())
		layer = new QgsRasterLayer(uri, baseName); // fi.completeBaseName());
	else
		layer = new QgsRasterLayer(uri, baseName, providerKey);

	QgsDebugMsgLevel(QStringLiteral("Constructed new layer"), 2);

	QgsError error;
	QString title;
	bool ok = false;

	if (!layer->isValid())
	{
		error = layer->error();
		title = tr("Invalid Layer");

		if (shouldAskUserForGDALSublayers(layer))
		{
			QList< QgsMapLayer * > subLayers = askUserForGDALSublayers(layer);
			ok = true;

			// The first layer loaded is not useful in that case. The user can select it in
			// the list if he wants to load it.
			delete layer;
			for (QgsMapLayer *l : qgis::as_const(subLayers))
				askUserForDatumTransform(l->crs(), QgsProject::instance()->crs(), l);
			layer = !subLayers.isEmpty() ? qobject_cast<QgsRasterLayer *>(subLayers.at(0)) : nullptr;
		}
	}
	else
	{
		ok = addRasterLayer(layer);
		if (!ok)
		{
			error.append(QGS_ERROR_MESSAGE(tr("Error adding valid layer to map canvas"),
				tr("Raster layer")));
			title = tr("Error");
		}
	}

	if (!ok)
	{
		// don't show the gui warning if we are loading from command line
		if (guiWarning)
		{
			visibleMessageBar()->pushMessage(title, error.message(QgsErrorMessage::Text),
				Qgis::Critical, messageTimeout());
		}

		if (layer)
		{
			delete layer;
			layer = nullptr;
		}
	}

	if (layer)
		layer->loadDefaultMetadata(ok);

	return layer;
}

