#include "GgsLayerTreeViewMenuProvider.h"
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QClipboard>
#include "qgslayertreeviewdefaultactions.h"
#include "qgsapplication.h"
#include "qgslayertreeview.h"
#include "qgslayertreemodel.h"
#include "qgslayertree.h"
#include "qgsmaplayeractionregistry.h"
#include "qgsgui.h"
#include "qgsmaplayerstylecategoriesmodel.h"
#include "qgscolorwidgets.h"
#include "qgscolorschemeregistry.h"
#include "qgscolorswatchgrid.h"
#include "qgsmessagebar.h"
#include "qgssymbolselectordialog.h"
#include "qgssymbolwidgetcontext.h"
#include "qgsstyle.h"
#include "qgsrasterlayer.h"

#include "GgsApp.h"

#pragma execution_character_set("utf-8") 

GgsLayerTreeViewMenuProvider::GgsLayerTreeViewMenuProvider(QgsLayerTreeView *view, QgsMapCanvas *canvas)
	:mView(view),
	mCanvas(canvas)
{

}

QMenu * GgsLayerTreeViewMenuProvider::createContextMenu()
{
	QMenu *menu = new QMenu;

	QgsLayerTreeViewDefaultActions *actions = mView->defaultActions();

	QModelIndex idx = mView->currentIndex();
	if (!idx.isValid()) 
	{
		// global menu
		menu->addAction(actions->actionAddGroup(menu));
		menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionExpandTree.svg")), tr("&Expand All"), mView, &QgsLayerTreeView::expandAll);
		menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionCollapseTree.svg")), tr("&Collapse All"), mView, &QgsLayerTreeView::collapseAll);
		menu->addSeparator();
	}
	else if (QgsLayerTreeNode *node = mView->layerTreeModel()->index2node(idx))
	{
		// 如果选中组
		if (QgsLayerTree::isGroup(node))
		{
			// 缩放到组
			menu->addAction(actions->actionZoomToGroup(mCanvas, menu));

			// 重命名组
			menu->addAction(actions->actionRenameGroupOrLayer(menu));
			menu->addSeparator();

			// 添加组
			menu->addAction(actions->actionAddGroup(menu));

			// 删除组
			QAction *removeAction = menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionRemoveLayer.svg")), tr("&Remove Group…"), GgsApp::instance(), &GgsApp::removeLayer);
			removeAction->setEnabled(removeActionEnabled());
			menu->addSeparator();

			// 设置组的CRS
			menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionSetCRS.png")),
				tr("&Set Group CRS…"), GgsApp::instance(), &GgsApp::legendGroupSetCrs);
			menu->addSeparator();

			// 互斥组
			menu->addAction(actions->actionMutuallyExclusiveGroup(menu));

			// 取消勾选或所有子项
			if (QAction *checkAll = actions->actionCheckAndAllChildren(menu))
				menu->addAction(checkAll);

			if (QAction *unCheckAll = actions->actionUncheckAndAllChildren(menu))
				menu->addAction(unCheckAll);

			if (!(mView->selectedNodes(true).count() == 1 && idx.row() == 0))
			{
				menu->addAction(actions->actionMoveToTop(menu));
			}

			if (!(mView->selectedNodes(true).count() == 1 && idx.row() == idx.model()->rowCount() - 1))
			{
				menu->addAction(actions->actionMoveToBottom(menu));
			}

			menu->addSeparator();

			if (mView->selectedNodes(true).count() >= 2)
				menu->addAction(actions->actionGroupSelected(menu));

			menu->addSeparator();
			// 导出
			QMenu *menuExportGroup = new QMenu(tr("Export"), menu);
			QAction *actionSaveAsDefinitionGroup = new QAction(tr("Save as Layer Definition File…"), menuExportGroup);
			connect(actionSaveAsDefinitionGroup, &QAction::triggered, GgsApp::instance(), &GgsApp::saveAsLayerDefinition);
			menuExportGroup->addAction(actionSaveAsDefinitionGroup);

			menu->addMenu(menuExportGroup);
		}
		else if (QgsLayerTree::isLayer(node)) // 如果选中图层
		{
			QgsMapLayer *layer = QgsLayerTree::toLayer(node)->layer();
			QgsRasterLayer *rlayer = qobject_cast<QgsRasterLayer *>(layer);
			QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(layer);

			if (layer && layer->isSpatial())
			{
				QAction *zoomToLayer = actions->actionZoomToLayer(mCanvas, menu);
				zoomToLayer->setEnabled(layer->isValid());
				menu->addAction(zoomToLayer);
				if (vlayer)
				{
					QAction *actionZoomSelected = actions->actionZoomToSelection(mCanvas, menu);
					actionZoomSelected->setEnabled(vlayer->isValid() && !vlayer->selectedFeatureIds().isEmpty());
					menu->addAction(actionZoomSelected);
				}
				menu->addAction(actions->actionShowInOverview(menu));
			}

			if (vlayer)
			{
				QAction *showFeatureCount = actions->actionShowFeatureCount(menu);
				menu->addAction(showFeatureCount);
				showFeatureCount->setEnabled(vlayer->isValid());
			}

			menu->addAction(actions->actionRenameGroupOrLayer(menu));

			addCustomLayerActions(menu, layer);

			if (layer && layer->type() == QgsMapLayerType::VectorLayer && static_cast<QgsVectorLayer *>(layer)->providerType() == QLatin1String("virtual"))
			{
				menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionAddVirtualLayer.svg")), tr("Edit Virtual Layer…"), GgsApp::instance(), &GgsApp::addVirtualLayer);
			}

			menu->addSeparator();

			if (node->parent() != mView->layerTreeModel()->rootGroup())
				menu->addAction(actions->actionMoveOutOfGroup(menu));

			if (!(mView->selectedNodes(true).count() == 1 && idx.row() == 0))
			{
				menu->addAction(actions->actionMoveToTop(menu));
			}

			if (!(mView->selectedNodes(true).count() == 1 && idx.row() == idx.model()->rowCount() - 1))
			{
				menu->addAction(actions->actionMoveToBottom(menu));
			}

			QAction *checkAll = actions->actionCheckAndAllParents(menu);
			if (checkAll)
				menu->addAction(checkAll);

			if (mView->selectedNodes(true).count() >= 2)
				menu->addAction(actions->actionGroupSelected(menu));

			menu->addSeparator();

			if (vlayer)
			{
				// 属性表
				QgsSettings settings;
				QgsAttributeTableFilterModel::FilterMode initialMode = settings.enumValue(QStringLiteral("qgis/attributeTableBehavior"), QgsAttributeTableFilterModel::ShowAll);
				const auto lambdaOpenAttributeTable = [=] { GgsApp::instance()->attributeTable(initialMode); };
				QAction *attributeTableAction = menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionOpenTable.svg")), tr("打开属性表(&O)"),
					GgsApp::instance(), lambdaOpenAttributeTable);
				attributeTableAction->setEnabled(vlayer->isValid());
			}

			if (vlayer || rlayer)
			{

				QAction *a = new QAction(layer->isValid() ? tr("更换数据源…") : tr("修复数据源…"), menu);
				if (!layer->isValid())
					a->setIcon(QgsApplication::getThemeIcon(QStringLiteral("mIconWarning.svg")));
				// Disable when layer is editable
				if (layer->isEditable())
				{
					a->setEnabled(false);
				}
				else
				{
					connect(a, &QAction::triggered, this, [=]
					{
						GgsApp::instance()->changeDataSource(layer);
					});
				}
				menu->addAction(a);
			}

			// 选择操作
			if (vlayer && vlayer->selectedFeatureCount() > 0)
			{
				int selectionCount = vlayer->selectedFeatureCount();
				QgsMapLayerAction::Target target;
				if (selectionCount == 1)
					target = QgsMapLayerAction::Target::SingleFeature;
				else
					target = QgsMapLayerAction::Target::MultipleFeatures;

				const QList<QgsMapLayerAction *> constRegisteredActions = QgsGui::mapLayerActionRegistry()->mapLayerActions(vlayer, target);
				if (!constRegisteredActions.isEmpty())
				{
					QMenu *actionMenu = menu->addMenu(tr("Actions on Selection (%1)").arg(selectionCount));
					for (QgsMapLayerAction *action : constRegisteredActions)
					{
						if (target == QgsMapLayerAction::Target::SingleFeature)
						{
							actionMenu->addAction(action->text(), action, [=]() { action->triggerForFeature(vlayer, vlayer->selectedFeatures().at(0)); });
						}
						else if (target == QgsMapLayerAction::Target::MultipleFeatures)
						{
							actionMenu->addAction(action->text(), action, [=]() {action->triggerForFeatures(vlayer, vlayer->selectedFeatures()); });
						}
					}
				}
			}

			menu->addSeparator();

			if (layer && layer->isSpatial())
			{	
				QMenu *menuSetCRS = new QMenu(tr("图层CRS"), menu);

				const QList<QgsLayerTreeNode *> selectedNodes = mView->selectedNodes();
				QgsCoordinateReferenceSystem layerCrs;
				bool firstLayer = true;
				bool allSameCrs = true;
				for (QgsLayerTreeNode *node : selectedNodes)
				{
					if (QgsLayerTree::isLayer(node))
					{
						QgsLayerTreeLayer *nodeLayer = QgsLayerTree::toLayer(node);
						if (nodeLayer->layer())
						{
							if (firstLayer)
							{
								layerCrs = nodeLayer->layer()->crs();
								firstLayer = false;
							}
							else if (nodeLayer->layer()->crs() != layerCrs)
							{
								allSameCrs = false;
								break;
							}
						}
					}
				}

				QAction *actionCurrentCrs = new QAction(!allSameCrs ? tr("混合CRS")
					: layer->crs().isValid() ? layer->crs().userFriendlyIdentifier()
					: tr("无CRS"), menuSetCRS);
				actionCurrentCrs->setEnabled(false);
				menuSetCRS->addAction(actionCurrentCrs);

				if (allSameCrs && layerCrs.isValid())
				{
					// assign layer crs to project
					QAction *actionSetProjectCrs = new QAction(tr("将图层的CRS设置为工程的CRS(&P)"), menuSetCRS);
					connect(actionSetProjectCrs, &QAction::triggered, GgsApp::instance(), &GgsApp::setProjectCrsFromLayer);
					menuSetCRS->addAction(actionSetProjectCrs);
				}

				const QList< QgsCoordinateReferenceSystem> recentProjections = QgsCoordinateReferenceSystem::recentCoordinateReferenceSystems();
				if (!recentProjections.isEmpty())
				{
					menuSetCRS->addSeparator();
					int i = 0;
					for (const QgsCoordinateReferenceSystem &crs : recentProjections)
					{
						if (crs == layer->crs())
							continue;

						QAction *action = menuSetCRS->addAction(tr("设置为%1").arg(crs.userFriendlyIdentifier(QgsCoordinateReferenceSystem::ShortString)));
						connect(action, &QAction::triggered, this, [=]
						{
							setLayerCrs(crs);
						});

						i++;
						if (i == 5)
							break;
					}
				}

				// set layer crs
				menuSetCRS->addSeparator();
				QAction *actionSetLayerCrs = new QAction(tr("设置图层CRS…"), menuSetCRS);
				connect(actionSetLayerCrs, &QAction::triggered, GgsApp::instance(), &GgsApp::setLayerCrs);
				menuSetCRS->addAction(actionSetLayerCrs);

				menu->addMenu(menuSetCRS);
			}

			menu->addSeparator();

			if (vlayer)
			{
				if (vlayer->isTemporary())
				{
					QAction *actionMakePermanent = new QAction(QgsApplication::getThemeIcon(QStringLiteral("mActionFileSave.svg")), tr("Make Permanent…"), menu);
					connect(actionMakePermanent, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->makeMemoryLayerPermanent(vlayer); });
					menu->addAction(actionMakePermanent);
				}
				// save as vector file
				QMenu *menuExportVector = new QMenu(tr("导出"), menu);
				QAction *actionSaveAs = new QAction(tr("要素另存为…"), menuExportVector);
				connect(actionSaveAs, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->saveAsFile(); });
				actionSaveAs->setEnabled(vlayer->isValid());
				menuExportVector->addAction(actionSaveAs);
				QAction *actionSaveSelectedFeaturesAs = new QAction(tr("选中的要素另存为…"), menuExportVector);
				connect(actionSaveSelectedFeaturesAs, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->saveAsFile(nullptr, true); });
				actionSaveSelectedFeaturesAs->setEnabled(vlayer->isValid() && vlayer->selectedFeatureCount() > 0);
				menuExportVector->addAction(actionSaveSelectedFeaturesAs);
				QAction *actionSaveAsDefinitionLayer = new QAction(tr("另存为图层定义文件…"), menuExportVector);
				connect(actionSaveAsDefinitionLayer, &QAction::triggered, GgsApp::instance(), &GgsApp::saveAsLayerDefinition);
				menuExportVector->addAction(actionSaveAsDefinitionLayer);
				if (vlayer->isSpatial())
				{
					QAction *actionSaveStyle = new QAction(tr("另存为QGIS图层样式文件…"), menuExportVector);
					connect(actionSaveStyle, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->saveStyleFile(); });
					menuExportVector->addAction(actionSaveStyle);
				}
				menu->addMenu(menuExportVector);
			}
			else if (rlayer)
			{
				QMenu *menuExportRaster = new QMenu(tr("导出"), menu);
				QAction *actionSaveAs = new QAction(tr("另存为…"), menuExportRaster);
				QAction *actionSaveAsDefinitionLayer = new QAction(tr("另存为图层定义文件…"), menuExportRaster);
				QAction *actionSaveStyle = new QAction(tr("另存为QGIS图层样式文件…"), menuExportRaster);
				connect(actionSaveAs, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->saveAsFile(); });
				menuExportRaster->addAction(actionSaveAs);
				actionSaveAs->setEnabled(rlayer->isValid());
				connect(actionSaveAsDefinitionLayer, &QAction::triggered, GgsApp::instance(), &GgsApp::saveAsLayerDefinition);
				menuExportRaster->addAction(actionSaveAsDefinitionLayer);
				connect(actionSaveStyle, &QAction::triggered, GgsApp::instance(), [=] { GgsApp::instance()->saveStyleFile(); });
				menuExportRaster->addAction(actionSaveStyle);
				menu->addMenu(menuExportRaster);
			}
			else if (layer && layer->type() == QgsMapLayerType::PluginLayer && mView->selectedLayerNodes().count() == 1)
			{
				// disable duplication of plugin layers
				//duplicateLayersAction->setEnabled(false);
			}

			menu->addSeparator();

			// 图层属性
			if (layer && QgsProject::instance()->layerIsEmbedded(layer->id()).isEmpty())
				menu->addAction(tr("属性(&P)…"), GgsApp::instance(), &GgsApp::layerProperties);
		}
	}
	else if (QgsLayerTreeModelLegendNode *node = mView->layerTreeModel()->index2legendNode(idx))
	{
		if (QgsSymbolLegendNode *symbolNode = qobject_cast<QgsSymbolLegendNode *>(node))
		{
			//  符号item
			if (symbolNode->flags() & Qt::ItemIsUserCheckable)
			{
				menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionToggleAllLayers.svg")), tr("&Toggle Items"),
					symbolNode, &QgsSymbolLegendNode::toggleAllItems);
				menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionShowAllLayers.svg")), tr("&Show All Items"),
					symbolNode, &QgsSymbolLegendNode::checkAllItems);
				menu->addAction(QgsApplication::getThemeIcon(QStringLiteral("/mActionHideAllLayers.svg")), tr("&Hide All Items"),
					symbolNode, &QgsSymbolLegendNode::uncheckAllItems);
				menu->addSeparator();
			}

			if (symbolNode->symbol())
			{
				QgsColorWheel *colorWheel = new QgsColorWheel(menu);
				colorWheel->setColor(symbolNode->symbol()->color());
				QgsColorWidgetAction *colorAction = new QgsColorWidgetAction(colorWheel, menu, menu);
				colorAction->setDismissOnColorSelection(false);
				connect(colorAction, &QgsColorWidgetAction::colorChanged, this, &GgsLayerTreeViewMenuProvider::setSymbolLegendNodeColor);
				//store the layer id and rule key in action, so we can later retrieve the corresponding
				//legend node, if it still exists
				colorAction->setProperty("layerId", symbolNode->layerNode()->layerId());
				colorAction->setProperty("ruleKey", symbolNode->data(QgsLayerTreeModelLegendNode::RuleKeyRole).toString());
				menu->addAction(colorAction);

				//add recent colors action
				QList<QgsRecentColorScheme *> recentSchemes;
				QgsApplication::colorSchemeRegistry()->schemes(recentSchemes);
				if (!recentSchemes.isEmpty())
				{
					QgsColorSwatchGridAction *recentColorAction = new QgsColorSwatchGridAction(recentSchemes.at(0), menu, QStringLiteral("symbology"), menu);
					recentColorAction->setProperty("layerId", symbolNode->layerNode()->layerId());
					recentColorAction->setProperty("ruleKey", symbolNode->data(QgsLayerTreeModelLegendNode::RuleKeyRole).toString());
					recentColorAction->setDismissOnColorSelection(false);
					menu->addAction(recentColorAction);
					connect(recentColorAction, &QgsColorSwatchGridAction::colorChanged, this, &GgsLayerTreeViewMenuProvider::setSymbolLegendNodeColor);
				}

				menu->addSeparator();
			}
			
			const QString layerId = symbolNode->layerNode()->layerId();
			const QString ruleKey = symbolNode->data(QgsLayerTreeModelLegendNode::RuleKeyRole).toString();

			QAction *editSymbolAction = new QAction(tr("编辑符号…"), menu);
			connect(editSymbolAction, &QAction::triggered, this, [this, layerId, ruleKey]
			{
				editSymbolLegendNodeSymbol(layerId, ruleKey);
			});
			menu->addAction(editSymbolAction);

			QAction *copySymbolAction = new QAction(tr("复制符号"), menu);
			connect(copySymbolAction, &QAction::triggered, this, [this, layerId, ruleKey]
			{
				copySymbolLegendNodeSymbol(layerId, ruleKey);
			});
			menu->addAction(copySymbolAction);

			bool enablePaste = false;
			std::unique_ptr< QgsSymbol > tempSymbol(QgsSymbolLayerUtils::symbolFromMimeData(QApplication::clipboard()->mimeData()));
			if (tempSymbol)
				enablePaste = true;

			QAction *pasteSymbolAction = new QAction(tr("粘贴符号"), menu);
			connect(pasteSymbolAction, &QAction::triggered, this, [this, layerId, ruleKey]
			{
				pasteSymbolLegendNodeSymbol(layerId, ruleKey);
			});
			pasteSymbolAction->setEnabled(enablePaste);
			menu->addAction(pasteSymbolAction);
		}
	}

	return menu;
}

QList< LegendLayerAction > GgsLayerTreeViewMenuProvider::legendLayerActions(QgsMapLayerType type) const
{
	return mLegendLayerActionMap.contains(type) ? mLegendLayerActionMap.value(type) : QList< LegendLayerAction >();
}

void GgsLayerTreeViewMenuProvider::setLayerCrs(const QgsCoordinateReferenceSystem &crs)
{
	const auto constSelectedNodes = mView->selectedNodes();
	for (QgsLayerTreeNode *node : constSelectedNodes)
	{
		if (QgsLayerTree::isLayer(node))
		{
			QgsLayerTreeLayer *nodeLayer = QgsLayerTree::toLayer(node);
			if (nodeLayer->layer())
			{
				nodeLayer->layer()->setCrs(crs, true);
				nodeLayer->layer()->triggerRepaint();
			}
		}
	}
}

void GgsLayerTreeViewMenuProvider::addCustomLayerActions(QMenu *menu, QgsMapLayer *layer)
{
	if (!layer)
		return;

	// add custom layer actions - should this go at end?
	QList< LegendLayerAction > lyrActions = legendLayerActions(layer->type());

	if (!lyrActions.isEmpty())
	{
		menu->addSeparator();
		QList<QMenu *> menus;
		for (int i = 0; i < lyrActions.count(); i++)
		{
			if (lyrActions[i].allLayers || lyrActions[i].layers.contains(layer))
			{
				if (lyrActions[i].menu.isEmpty())
				{
					menu->addAction(lyrActions[i].action);
				}
				else
				{
					// find or create menu for given menu name
					// adapted from QgisApp::getPluginMenu( QString menuName )
					QString menuName = lyrActions[i].menu;

					QAction *before = nullptr;
					QMenu *newMenu = nullptr;
					QString dst = menuName;
					dst.remove(QChar('&'));
					const auto constMenus = menus;
					for (QMenu *menu : constMenus)
					{
						QString src = menu->title();
						src.remove(QChar('&'));
						int comp = dst.localeAwareCompare(src);
						if (comp < 0)
						{
							// Add item before this one
							before = menu->menuAction();
							break;
						}
						else if (comp == 0)
						{
							// Plugin menu item already exists
							newMenu = menu;
							break;
						}
					}
					if (!newMenu)
					{
						// It doesn't exist, so create
						newMenu = new QMenu(menuName);
						menus.append(newMenu);
						// Where to put it? - we worked that out above...
						menu->insertMenu(before, newMenu);
					}
					// QMenu* menu = getMenu( lyrActions[i].menu, &beforeSep, &afterSep, &menu );
					newMenu->addAction(lyrActions[i].action);
				}
			}
		}
		menu->addSeparator();
	}
}

void GgsLayerTreeViewMenuProvider::setSymbolLegendNodeColor(const QColor &color)
{
	QAction *action = qobject_cast<QAction *>(sender());
	if (!action)
		return;

	QString layerId = action->property("layerId").toString();
	QString ruleKey = action->property("ruleKey").toString();

	QgsSymbolLegendNode *node = qobject_cast<QgsSymbolLegendNode *>(mView->layerTreeModel()->findLegendNode(layerId, ruleKey));
	if (!node)
		return;

	const QgsSymbol *originalSymbol = node->symbol();
	if (!originalSymbol)
		return;

	std::unique_ptr< QgsSymbol > newSymbol(originalSymbol->clone());
	newSymbol->setColor(color);
	node->setSymbol(newSymbol.release());
	if (QgsVectorLayer *layer = QgsProject::instance()->mapLayer<QgsVectorLayer *>(layerId))
	{
		layer->emitStyleChanged();
	}
	QgsProject::instance()->setDirty(true);
}

void GgsLayerTreeViewMenuProvider::editSymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey)
{
	QgsSymbolLegendNode *node = qobject_cast<QgsSymbolLegendNode *>(mView->layerTreeModel()->findLegendNode(layerId, ruleKey));
	if (!node)
		return;

	const QgsSymbol *originalSymbol = node->symbol();
	if (!originalSymbol)
	{
		GgsApp::instance()->messageBar()->pushWarning(tr("No Symbol"), tr("There is no symbol associated with the rule."));
		return;
	}

	std::unique_ptr< QgsSymbol > symbol(originalSymbol->clone());
	QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(node->layerNode()->layer());
	QgsSymbolSelectorDialog dlg(symbol.get(), QgsStyle::defaultStyle(), vlayer, mView->window());
	dlg.setWindowTitle(tr("Symbol Selector"));
	QgsSymbolWidgetContext context;
	context.setMapCanvas(mCanvas);
	context.setMessageBar(GgsApp::instance()->messageBar());
	dlg.setContext(context);
	if (dlg.exec())
	{
		node->setSymbol(symbol.release());
		if (vlayer)
		{
			vlayer->emitStyleChanged();
		}
		QgsProject::instance()->setDirty(true);
	}
}

void GgsLayerTreeViewMenuProvider::copySymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey)
{
	QgsSymbolLegendNode *node = qobject_cast<QgsSymbolLegendNode *>(mView->layerTreeModel()->findLegendNode(layerId, ruleKey));
	if (!node)
		return;

	const QgsSymbol *originalSymbol = node->symbol();
	if (!originalSymbol)
		return;

	QApplication::clipboard()->setMimeData(QgsSymbolLayerUtils::symbolToMimeData(originalSymbol));
}

void GgsLayerTreeViewMenuProvider::pasteSymbolLegendNodeSymbol(const QString &layerId, const QString &ruleKey)
{
	QgsSymbolLegendNode *node = qobject_cast<QgsSymbolLegendNode *>(mView->layerTreeModel()->findLegendNode(layerId, ruleKey));
	if (!node)
		return;

	const QgsSymbol *originalSymbol = node->symbol();
	if (!originalSymbol)
		return;

	QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>(node->layerNode()->layer());

	std::unique_ptr< QgsSymbol > tempSymbol(QgsSymbolLayerUtils::symbolFromMimeData(QApplication::clipboard()->mimeData()));
	if (tempSymbol && tempSymbol->type() == originalSymbol->type())
	{
		node->setSymbol(tempSymbol.release());
		if (vlayer)
		{
			vlayer->emitStyleChanged();
		}
		QgsProject::instance()->setDirty(true);
	}
}

bool GgsLayerTreeViewMenuProvider::removeActionEnabled()
{
	const QList<QgsLayerTreeLayer *> selectedLayers = mView->selectedLayerNodes();
	for (QgsLayerTreeLayer *nodeLayer : selectedLayers)
	{
		// be careful with the logic here -- if nodeLayer->layer() is false, will still must return true
		// to allow the broken layer to be removed from the project
		if (nodeLayer->layer() && !nodeLayer->layer()->flags().testFlag(QgsMapLayer::Removable))
			return false;
	}
	return true;
}
