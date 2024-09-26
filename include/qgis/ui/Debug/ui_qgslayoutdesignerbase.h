/********************************************************************************
** Form generated from reading UI file 'qgslayoutdesignerbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSLAYOUTDESIGNERBASE_H
#define UI_QGSLAYOUTDESIGNERBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QgsLayoutDesignerBase
{
public:
    QAction *mActionClose;
    QAction *mActionPan;
    QAction *mActionZoomTool;
    QAction *mActionSelectMoveItem;
    QAction *mActionZoomAll;
    QAction *mActionZoomIn;
    QAction *mActionZoomOut;
    QAction *mActionZoomActual;
    QAction *mActionZoomToWidth;
    QAction *mActionShowRulers;
    QAction *mActionToggleFullScreen;
    QAction *mActionAddPages;
    QAction *mActionShowGrid;
    QAction *mActionSnapGrid;
    QAction *mActionManageGuides;
    QAction *mActionShowGuides;
    QAction *mActionSnapGuides;
    QAction *mActionClearGuides;
    QAction *mActionLayoutProperties;
    QAction *mActionShowBoxes;
    QAction *mActionSmartGuides;
    QAction *mActionDeselectAll;
    QAction *mActionSelectAll;
    QAction *mActionInvertSelection;
    QAction *mActionSelectNextBelow;
    QAction *mActionSelectNextAbove;
    QAction *mActionLockItems;
    QAction *mActionUnlockAll;
    QAction *mActionHidePanels;
    QAction *mActionRaiseItems;
    QAction *mActionLowerItems;
    QAction *mActionMoveItemsToTop;
    QAction *mActionMoveItemsToBottom;
    QAction *mActionAlignLeft;
    QAction *mActionAlignHCenter;
    QAction *mActionAlignRight;
    QAction *mActionAlignTop;
    QAction *mActionAlignVCenter;
    QAction *mActionAlignBottom;
    QAction *mActionDistributeLeft;
    QAction *mActionDistributeHCenter;
    QAction *mActionDistributeHSpace;
    QAction *mActionDistributeRight;
    QAction *mActionDistributeTop;
    QAction *mActionDistributeVCenter;
    QAction *mActionDistributeVSpace;
    QAction *mActionDistributeBottom;
    QAction *mActionResizeNarrowest;
    QAction *mActionResizeWidest;
    QAction *mActionResizeShortest;
    QAction *mActionResizeTallest;
    QAction *mActionDeleteSelection;
    QAction *mActionResizeToSquare;
    QAction *mActionPreviewModeOff;
    QAction *mActionPreviewModeGrayscale;
    QAction *mActionPreviewModeMono;
    QAction *mActionPreviewProtanope;
    QAction *mActionPreviewDeuteranope;
    QAction *mActionShowPage;
    QAction *mActionGroupItems;
    QAction *mActionUngroupItems;
    QAction *mActionRefreshView;
    QAction *mActionEditNodesItem;
    QAction *mActionMoveItemContent;
    QAction *mActionPasteInPlace;
    QAction *mActionSaveAsTemplate;
    QAction *mActionLoadFromTemplate;
    QAction *mActionDuplicateLayout;
    QAction *mActionSaveProject;
    QAction *mActionNewLayout;
    QAction *mActionLayoutManager;
    QAction *mActionRenameLayout;
    QAction *mActionRemoveLayout;
    QAction *mActionExportAsImage;
    QAction *mActionExportAsPDF;
    QAction *mActionExportAsSVG;
    QAction *mActionAtlasFirst;
    QAction *mActionAtlasPrev;
    QAction *mActionAtlasNext;
    QAction *mActionAtlasLast;
    QAction *mActionPrintAtlas;
    QAction *mActionExportAtlasAsImage;
    QAction *mActionExportAtlasAsSVG;
    QAction *mActionExportAtlasAsPDF;
    QAction *mActionAtlasSettings;
    QAction *mActionAtlasPreview;
    QAction *mActionExportReportAsImage;
    QAction *mActionExportReportAsSVG;
    QAction *mActionExportReportAsPDF;
    QAction *mActionReportSettings;
    QAction *mActionPrint;
    QAction *mActionPrintReport;
    QAction *mActionPageSetup;
    QAction *mActionOptions;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *mViewFrame;
    QStatusBar *mStatusBar;
    QToolBar *mLayoutToolbar;
    QToolBar *mToolsToolbar;
    QToolBar *mNavigationToolbar;
    QToolBar *mActionsToolbar;
    QToolBar *mAtlasToolbar;
    QToolBar *mReportToolbar;
    QMenuBar *mMenuBar;
    QMenu *mLayoutMenu;
    QMenu *mLayoutsMenu;
    QMenu *mItemMenu;
    QMenu *mMenuView;
    QMenu *mToolbarMenu;
    QMenu *mPanelsMenu;
    QMenu *menuPreview;
    QMenu *menuEdit;
    QMenu *menuLayout;
    QMenu *menuAlign_Items;
    QMenu *menu_Distribute_Items;
    QMenu *menuResize;
    QMenu *mMenuAtlas;
    QMenu *mMenuReport;
    QMenu *menuSettings;

    void setupUi(QMainWindow *QgsLayoutDesignerBase)
    {
        if (QgsLayoutDesignerBase->objectName().isEmpty())
            QgsLayoutDesignerBase->setObjectName(QString::fromUtf8("QgsLayoutDesignerBase"));
        QgsLayoutDesignerBase->resize(2180, 609);
        QgsLayoutDesignerBase->setMouseTracking(true);
        mActionClose = new QAction(QgsLayoutDesignerBase);
        mActionClose->setObjectName(QString::fromUtf8("mActionClose"));
        mActionPan = new QAction(QgsLayoutDesignerBase);
        mActionPan->setObjectName(QString::fromUtf8("mActionPan"));
        mActionPan->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionPan.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPan->setIcon(icon);
        mActionZoomTool = new QAction(QgsLayoutDesignerBase);
        mActionZoomTool->setObjectName(QString::fromUtf8("mActionZoomTool"));
        mActionZoomTool->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomToArea.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomTool->setIcon(icon1);
        mActionSelectMoveItem = new QAction(QgsLayoutDesignerBase);
        mActionSelectMoveItem->setObjectName(QString::fromUtf8("mActionSelectMoveItem"));
        mActionSelectMoveItem->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionSelect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectMoveItem->setIcon(icon2);
        mActionZoomAll = new QAction(QgsLayoutDesignerBase);
        mActionZoomAll->setObjectName(QString::fromUtf8("mActionZoomAll"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomFullExtent.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomAll->setIcon(icon3);
        mActionZoomIn = new QAction(QgsLayoutDesignerBase);
        mActionZoomIn->setObjectName(QString::fromUtf8("mActionZoomIn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomIn.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomIn->setIcon(icon4);
        mActionZoomOut = new QAction(QgsLayoutDesignerBase);
        mActionZoomOut->setObjectName(QString::fromUtf8("mActionZoomOut"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomOut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomOut->setIcon(icon5);
        mActionZoomActual = new QAction(QgsLayoutDesignerBase);
        mActionZoomActual->setObjectName(QString::fromUtf8("mActionZoomActual"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomActual.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomActual->setIcon(icon6);
        mActionZoomToWidth = new QAction(QgsLayoutDesignerBase);
        mActionZoomToWidth->setObjectName(QString::fromUtf8("mActionZoomToWidth"));
        mActionShowRulers = new QAction(QgsLayoutDesignerBase);
        mActionShowRulers->setObjectName(QString::fromUtf8("mActionShowRulers"));
        mActionShowRulers->setCheckable(true);
        mActionToggleFullScreen = new QAction(QgsLayoutDesignerBase);
        mActionToggleFullScreen->setObjectName(QString::fromUtf8("mActionToggleFullScreen"));
        mActionToggleFullScreen->setCheckable(true);
        mActionAddPages = new QAction(QgsLayoutDesignerBase);
        mActionAddPages->setObjectName(QString::fromUtf8("mActionAddPages"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/mActionNewPage.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAddPages->setIcon(icon7);
        mActionShowGrid = new QAction(QgsLayoutDesignerBase);
        mActionShowGrid->setObjectName(QString::fromUtf8("mActionShowGrid"));
        mActionShowGrid->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/vector_grid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowGrid->setIcon(icon8);
        mActionSnapGrid = new QAction(QgsLayoutDesignerBase);
        mActionSnapGrid->setObjectName(QString::fromUtf8("mActionSnapGrid"));
        mActionSnapGrid->setCheckable(true);
        mActionManageGuides = new QAction(QgsLayoutDesignerBase);
        mActionManageGuides->setObjectName(QString::fromUtf8("mActionManageGuides"));
        mActionShowGuides = new QAction(QgsLayoutDesignerBase);
        mActionShowGuides->setObjectName(QString::fromUtf8("mActionShowGuides"));
        mActionShowGuides->setCheckable(true);
        mActionSnapGuides = new QAction(QgsLayoutDesignerBase);
        mActionSnapGuides->setObjectName(QString::fromUtf8("mActionSnapGuides"));
        mActionSnapGuides->setCheckable(true);
        mActionClearGuides = new QAction(QgsLayoutDesignerBase);
        mActionClearGuides->setObjectName(QString::fromUtf8("mActionClearGuides"));
        mActionLayoutProperties = new QAction(QgsLayoutDesignerBase);
        mActionLayoutProperties->setObjectName(QString::fromUtf8("mActionLayoutProperties"));
        mActionShowBoxes = new QAction(QgsLayoutDesignerBase);
        mActionShowBoxes->setObjectName(QString::fromUtf8("mActionShowBoxes"));
        mActionShowBoxes->setCheckable(true);
        mActionSmartGuides = new QAction(QgsLayoutDesignerBase);
        mActionSmartGuides->setObjectName(QString::fromUtf8("mActionSmartGuides"));
        mActionSmartGuides->setCheckable(true);
        mActionDeselectAll = new QAction(QgsLayoutDesignerBase);
        mActionDeselectAll->setObjectName(QString::fromUtf8("mActionDeselectAll"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/themes/default/mActionDeselectAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDeselectAll->setIcon(icon9);
        mActionSelectAll = new QAction(QgsLayoutDesignerBase);
        mActionSelectAll->setObjectName(QString::fromUtf8("mActionSelectAll"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/themes/default/mActionSelectAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectAll->setIcon(icon10);
        mActionInvertSelection = new QAction(QgsLayoutDesignerBase);
        mActionInvertSelection->setObjectName(QString::fromUtf8("mActionInvertSelection"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/themes/default/mActionInvertSelection.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionInvertSelection->setIcon(icon11);
        mActionSelectNextBelow = new QAction(QgsLayoutDesignerBase);
        mActionSelectNextBelow->setObjectName(QString::fromUtf8("mActionSelectNextBelow"));
        mActionSelectNextAbove = new QAction(QgsLayoutDesignerBase);
        mActionSelectNextAbove->setObjectName(QString::fromUtf8("mActionSelectNextAbove"));
        mActionLockItems = new QAction(QgsLayoutDesignerBase);
        mActionLockItems->setObjectName(QString::fromUtf8("mActionLockItems"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/themes/default/mActionLockItems.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionLockItems->setIcon(icon12);
        mActionUnlockAll = new QAction(QgsLayoutDesignerBase);
        mActionUnlockAll->setObjectName(QString::fromUtf8("mActionUnlockAll"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/themes/default/mActionUnlockAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionUnlockAll->setIcon(icon13);
        mActionHidePanels = new QAction(QgsLayoutDesignerBase);
        mActionHidePanels->setObjectName(QString::fromUtf8("mActionHidePanels"));
        mActionHidePanels->setCheckable(true);
        mActionRaiseItems = new QAction(QgsLayoutDesignerBase);
        mActionRaiseItems->setObjectName(QString::fromUtf8("mActionRaiseItems"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/themes/default/mActionRaiseItems.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRaiseItems->setIcon(icon14);
        mActionLowerItems = new QAction(QgsLayoutDesignerBase);
        mActionLowerItems->setObjectName(QString::fromUtf8("mActionLowerItems"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/themes/default/mActionLowerItems.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionLowerItems->setIcon(icon15);
        mActionMoveItemsToTop = new QAction(QgsLayoutDesignerBase);
        mActionMoveItemsToTop->setObjectName(QString::fromUtf8("mActionMoveItemsToTop"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/themes/default/mActionMoveItemsToTop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionMoveItemsToTop->setIcon(icon16);
        mActionMoveItemsToBottom = new QAction(QgsLayoutDesignerBase);
        mActionMoveItemsToBottom->setObjectName(QString::fromUtf8("mActionMoveItemsToBottom"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/themes/default/mActionMoveItemsToBottom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionMoveItemsToBottom->setIcon(icon17);
        mActionAlignLeft = new QAction(QgsLayoutDesignerBase);
        mActionAlignLeft->setObjectName(QString::fromUtf8("mActionAlignLeft"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignLeft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignLeft->setIcon(icon18);
        mActionAlignHCenter = new QAction(QgsLayoutDesignerBase);
        mActionAlignHCenter->setObjectName(QString::fromUtf8("mActionAlignHCenter"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignHCenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignHCenter->setIcon(icon19);
        mActionAlignRight = new QAction(QgsLayoutDesignerBase);
        mActionAlignRight->setObjectName(QString::fromUtf8("mActionAlignRight"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignRight.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignRight->setIcon(icon20);
        mActionAlignTop = new QAction(QgsLayoutDesignerBase);
        mActionAlignTop->setObjectName(QString::fromUtf8("mActionAlignTop"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignTop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignTop->setIcon(icon21);
        mActionAlignVCenter = new QAction(QgsLayoutDesignerBase);
        mActionAlignVCenter->setObjectName(QString::fromUtf8("mActionAlignVCenter"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignVCenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignVCenter->setIcon(icon22);
        mActionAlignBottom = new QAction(QgsLayoutDesignerBase);
        mActionAlignBottom->setObjectName(QString::fromUtf8("mActionAlignBottom"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/themes/default/mActionAlignBottom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAlignBottom->setIcon(icon23);
        mActionDistributeLeft = new QAction(QgsLayoutDesignerBase);
        mActionDistributeLeft->setObjectName(QString::fromUtf8("mActionDistributeLeft"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeLeft.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeLeft->setIcon(icon24);
        mActionDistributeHCenter = new QAction(QgsLayoutDesignerBase);
        mActionDistributeHCenter->setObjectName(QString::fromUtf8("mActionDistributeHCenter"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeHCenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeHCenter->setIcon(icon25);
        mActionDistributeHSpace = new QAction(QgsLayoutDesignerBase);
        mActionDistributeHSpace->setObjectName(QString::fromUtf8("mActionDistributeHSpace"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeHSpace.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeHSpace->setIcon(icon26);
        mActionDistributeRight = new QAction(QgsLayoutDesignerBase);
        mActionDistributeRight->setObjectName(QString::fromUtf8("mActionDistributeRight"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeRight.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeRight->setIcon(icon27);
        mActionDistributeTop = new QAction(QgsLayoutDesignerBase);
        mActionDistributeTop->setObjectName(QString::fromUtf8("mActionDistributeTop"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeTop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeTop->setIcon(icon28);
        mActionDistributeVCenter = new QAction(QgsLayoutDesignerBase);
        mActionDistributeVCenter->setObjectName(QString::fromUtf8("mActionDistributeVCenter"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeVCenter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeVCenter->setIcon(icon29);
        mActionDistributeVSpace = new QAction(QgsLayoutDesignerBase);
        mActionDistributeVSpace->setObjectName(QString::fromUtf8("mActionDistributeVSpace"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeVSpace.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeVSpace->setIcon(icon30);
        mActionDistributeBottom = new QAction(QgsLayoutDesignerBase);
        mActionDistributeBottom->setObjectName(QString::fromUtf8("mActionDistributeBottom"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/images/themes/default/mActionDistributeBottom.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDistributeBottom->setIcon(icon31);
        mActionResizeNarrowest = new QAction(QgsLayoutDesignerBase);
        mActionResizeNarrowest->setObjectName(QString::fromUtf8("mActionResizeNarrowest"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/images/themes/default/mActionResizeNarrowest.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionResizeNarrowest->setIcon(icon32);
        mActionResizeWidest = new QAction(QgsLayoutDesignerBase);
        mActionResizeWidest->setObjectName(QString::fromUtf8("mActionResizeWidest"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/images/themes/default/mActionResizeWidest.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionResizeWidest->setIcon(icon33);
        mActionResizeShortest = new QAction(QgsLayoutDesignerBase);
        mActionResizeShortest->setObjectName(QString::fromUtf8("mActionResizeShortest"));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/images/themes/default/mActionResizeShortest.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionResizeShortest->setIcon(icon34);
        mActionResizeTallest = new QAction(QgsLayoutDesignerBase);
        mActionResizeTallest->setObjectName(QString::fromUtf8("mActionResizeTallest"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/images/themes/default/mActionResizeTallest.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionResizeTallest->setIcon(icon35);
        mActionDeleteSelection = new QAction(QgsLayoutDesignerBase);
        mActionDeleteSelection->setObjectName(QString::fromUtf8("mActionDeleteSelection"));
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteSelected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDeleteSelection->setIcon(icon36);
#ifndef QT_NO_SHORTCUT
        mActionDeleteSelection->setShortcut(QString::fromUtf8("Del"));
#endif // QT_NO_SHORTCUT
        mActionResizeToSquare = new QAction(QgsLayoutDesignerBase);
        mActionResizeToSquare->setObjectName(QString::fromUtf8("mActionResizeToSquare"));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/images/themes/default/mActionResizeSquare.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionResizeToSquare->setIcon(icon37);
        mActionPreviewModeOff = new QAction(QgsLayoutDesignerBase);
        mActionPreviewModeOff->setObjectName(QString::fromUtf8("mActionPreviewModeOff"));
        mActionPreviewModeOff->setCheckable(true);
        mActionPreviewModeGrayscale = new QAction(QgsLayoutDesignerBase);
        mActionPreviewModeGrayscale->setObjectName(QString::fromUtf8("mActionPreviewModeGrayscale"));
        mActionPreviewModeGrayscale->setCheckable(true);
        mActionPreviewModeMono = new QAction(QgsLayoutDesignerBase);
        mActionPreviewModeMono->setObjectName(QString::fromUtf8("mActionPreviewModeMono"));
        mActionPreviewModeMono->setCheckable(true);
        mActionPreviewProtanope = new QAction(QgsLayoutDesignerBase);
        mActionPreviewProtanope->setObjectName(QString::fromUtf8("mActionPreviewProtanope"));
        mActionPreviewProtanope->setCheckable(true);
        mActionPreviewDeuteranope = new QAction(QgsLayoutDesignerBase);
        mActionPreviewDeuteranope->setObjectName(QString::fromUtf8("mActionPreviewDeuteranope"));
        mActionPreviewDeuteranope->setCheckable(true);
        mActionShowPage = new QAction(QgsLayoutDesignerBase);
        mActionShowPage->setObjectName(QString::fromUtf8("mActionShowPage"));
        mActionShowPage->setCheckable(true);
        mActionGroupItems = new QAction(QgsLayoutDesignerBase);
        mActionGroupItems->setObjectName(QString::fromUtf8("mActionGroupItems"));
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/images/themes/default/mActionGroupItems.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionGroupItems->setIcon(icon38);
        mActionUngroupItems = new QAction(QgsLayoutDesignerBase);
        mActionUngroupItems->setObjectName(QString::fromUtf8("mActionUngroupItems"));
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/images/themes/default/mActionUngroupItems.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionUngroupItems->setIcon(icon39);
        mActionRefreshView = new QAction(QgsLayoutDesignerBase);
        mActionRefreshView->setObjectName(QString::fromUtf8("mActionRefreshView"));
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRefreshView->setIcon(icon40);
        mActionEditNodesItem = new QAction(QgsLayoutDesignerBase);
        mActionEditNodesItem->setObjectName(QString::fromUtf8("mActionEditNodesItem"));
        mActionEditNodesItem->setCheckable(true);
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/images/themes/default/mActionEditNodesItem.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionEditNodesItem->setIcon(icon41);
        mActionMoveItemContent = new QAction(QgsLayoutDesignerBase);
        mActionMoveItemContent->setObjectName(QString::fromUtf8("mActionMoveItemContent"));
        mActionMoveItemContent->setCheckable(true);
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/images/themes/default/mActionMoveItemContent.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionMoveItemContent->setIcon(icon42);
        mActionPasteInPlace = new QAction(QgsLayoutDesignerBase);
        mActionPasteInPlace->setObjectName(QString::fromUtf8("mActionPasteInPlace"));
        mActionSaveAsTemplate = new QAction(QgsLayoutDesignerBase);
        mActionSaveAsTemplate->setObjectName(QString::fromUtf8("mActionSaveAsTemplate"));
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/images/themes/default/mActionFileSaveAs.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSaveAsTemplate->setIcon(icon43);
        mActionLoadFromTemplate = new QAction(QgsLayoutDesignerBase);
        mActionLoadFromTemplate->setObjectName(QString::fromUtf8("mActionLoadFromTemplate"));
        QIcon icon44;
        icon44.addFile(QString::fromUtf8(":/images/themes/default/mActionFileOpen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionLoadFromTemplate->setIcon(icon44);
        mActionDuplicateLayout = new QAction(QgsLayoutDesignerBase);
        mActionDuplicateLayout->setObjectName(QString::fromUtf8("mActionDuplicateLayout"));
        QIcon icon45;
        icon45.addFile(QString::fromUtf8(":/images/themes/default/mActionDuplicateLayout.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDuplicateLayout->setIcon(icon45);
        mActionSaveProject = new QAction(QgsLayoutDesignerBase);
        mActionSaveProject->setObjectName(QString::fromUtf8("mActionSaveProject"));
        QIcon icon46;
        icon46.addFile(QString::fromUtf8(":/images/themes/default/mActionFileSave.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSaveProject->setIcon(icon46);
        mActionNewLayout = new QAction(QgsLayoutDesignerBase);
        mActionNewLayout->setObjectName(QString::fromUtf8("mActionNewLayout"));
        QIcon icon47;
        icon47.addFile(QString::fromUtf8(":/images/themes/default/mActionNewLayout.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionNewLayout->setIcon(icon47);
        mActionLayoutManager = new QAction(QgsLayoutDesignerBase);
        mActionLayoutManager->setObjectName(QString::fromUtf8("mActionLayoutManager"));
        QIcon icon48;
        icon48.addFile(QString::fromUtf8(":/images/themes/default/mActionLayoutManager.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionLayoutManager->setIcon(icon48);
        mActionRenameLayout = new QAction(QgsLayoutDesignerBase);
        mActionRenameLayout->setObjectName(QString::fromUtf8("mActionRenameLayout"));
        mActionRemoveLayout = new QAction(QgsLayoutDesignerBase);
        mActionRemoveLayout->setObjectName(QString::fromUtf8("mActionRemoveLayout"));
        mActionRemoveLayout->setIcon(icon36);
        mActionExportAsImage = new QAction(QgsLayoutDesignerBase);
        mActionExportAsImage->setObjectName(QString::fromUtf8("mActionExportAsImage"));
        QIcon icon49;
        icon49.addFile(QString::fromUtf8(":/images/themes/default/mActionSaveMapAsImage.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionExportAsImage->setIcon(icon49);
        mActionExportAsPDF = new QAction(QgsLayoutDesignerBase);
        mActionExportAsPDF->setObjectName(QString::fromUtf8("mActionExportAsPDF"));
        QIcon icon50;
        icon50.addFile(QString::fromUtf8(":/images/themes/default/mActionSaveAsPDF.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionExportAsPDF->setIcon(icon50);
        mActionExportAsSVG = new QAction(QgsLayoutDesignerBase);
        mActionExportAsSVG->setObjectName(QString::fromUtf8("mActionExportAsSVG"));
        QIcon icon51;
        icon51.addFile(QString::fromUtf8(":/images/themes/default/mActionSaveAsSVG.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionExportAsSVG->setIcon(icon51);
        mActionAtlasFirst = new QAction(QgsLayoutDesignerBase);
        mActionAtlasFirst->setObjectName(QString::fromUtf8("mActionAtlasFirst"));
        QIcon icon52;
        icon52.addFile(QString::fromUtf8(":/images/themes/default/mActionAtlasFirst.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasFirst->setIcon(icon52);
        mActionAtlasPrev = new QAction(QgsLayoutDesignerBase);
        mActionAtlasPrev->setObjectName(QString::fromUtf8("mActionAtlasPrev"));
        QIcon icon53;
        icon53.addFile(QString::fromUtf8(":/images/themes/default/mActionAtlasPrev.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasPrev->setIcon(icon53);
        mActionAtlasNext = new QAction(QgsLayoutDesignerBase);
        mActionAtlasNext->setObjectName(QString::fromUtf8("mActionAtlasNext"));
        QIcon icon54;
        icon54.addFile(QString::fromUtf8(":/images/themes/default/mActionAtlasNext.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasNext->setIcon(icon54);
        mActionAtlasLast = new QAction(QgsLayoutDesignerBase);
        mActionAtlasLast->setObjectName(QString::fromUtf8("mActionAtlasLast"));
        QIcon icon55;
        icon55.addFile(QString::fromUtf8(":/images/themes/default/mActionAtlasLast.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasLast->setIcon(icon55);
        mActionPrintAtlas = new QAction(QgsLayoutDesignerBase);
        mActionPrintAtlas->setObjectName(QString::fromUtf8("mActionPrintAtlas"));
        QIcon icon56;
        icon56.addFile(QString::fromUtf8(":/images/themes/default/mActionFilePrint.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPrintAtlas->setIcon(icon56);
        mActionExportAtlasAsImage = new QAction(QgsLayoutDesignerBase);
        mActionExportAtlasAsImage->setObjectName(QString::fromUtf8("mActionExportAtlasAsImage"));
        mActionExportAtlasAsImage->setIcon(icon49);
        mActionExportAtlasAsSVG = new QAction(QgsLayoutDesignerBase);
        mActionExportAtlasAsSVG->setObjectName(QString::fromUtf8("mActionExportAtlasAsSVG"));
        mActionExportAtlasAsSVG->setIcon(icon51);
        mActionExportAtlasAsPDF = new QAction(QgsLayoutDesignerBase);
        mActionExportAtlasAsPDF->setObjectName(QString::fromUtf8("mActionExportAtlasAsPDF"));
        mActionExportAtlasAsPDF->setIcon(icon50);
        mActionAtlasSettings = new QAction(QgsLayoutDesignerBase);
        mActionAtlasSettings->setObjectName(QString::fromUtf8("mActionAtlasSettings"));
        mActionAtlasSettings->setCheckable(true);
        QIcon icon57;
        icon57.addFile(QString::fromUtf8(":/images/themes/default/mActionAtlasSettings.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasSettings->setIcon(icon57);
        mActionAtlasPreview = new QAction(QgsLayoutDesignerBase);
        mActionAtlasPreview->setObjectName(QString::fromUtf8("mActionAtlasPreview"));
        mActionAtlasPreview->setCheckable(true);
        QIcon icon58;
        icon58.addFile(QString::fromUtf8(":/images/themes/default/mIconAtlas.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAtlasPreview->setIcon(icon58);
        mActionExportReportAsImage = new QAction(QgsLayoutDesignerBase);
        mActionExportReportAsImage->setObjectName(QString::fromUtf8("mActionExportReportAsImage"));
        mActionExportReportAsImage->setIcon(icon49);
        mActionExportReportAsSVG = new QAction(QgsLayoutDesignerBase);
        mActionExportReportAsSVG->setObjectName(QString::fromUtf8("mActionExportReportAsSVG"));
        mActionExportReportAsSVG->setIcon(icon51);
        mActionExportReportAsPDF = new QAction(QgsLayoutDesignerBase);
        mActionExportReportAsPDF->setObjectName(QString::fromUtf8("mActionExportReportAsPDF"));
        mActionExportReportAsPDF->setIcon(icon50);
        mActionReportSettings = new QAction(QgsLayoutDesignerBase);
        mActionReportSettings->setObjectName(QString::fromUtf8("mActionReportSettings"));
        mActionReportSettings->setCheckable(true);
        mActionReportSettings->setIcon(icon57);
        mActionPrint = new QAction(QgsLayoutDesignerBase);
        mActionPrint->setObjectName(QString::fromUtf8("mActionPrint"));
        mActionPrint->setCheckable(false);
        mActionPrint->setIcon(icon56);
        mActionPrintReport = new QAction(QgsLayoutDesignerBase);
        mActionPrintReport->setObjectName(QString::fromUtf8("mActionPrintReport"));
        mActionPrintReport->setIcon(icon56);
        mActionPageSetup = new QAction(QgsLayoutDesignerBase);
        mActionPageSetup->setObjectName(QString::fromUtf8("mActionPageSetup"));
        mActionOptions = new QAction(QgsLayoutDesignerBase);
        mActionOptions->setObjectName(QString::fromUtf8("mActionOptions"));
        QIcon icon59;
        icon59.addFile(QString::fromUtf8(":/images/themes/default/mActionOptions.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionOptions->setIcon(icon59);
        mActionOptions->setMenuRole(QAction::PreferencesRole);
        centralwidget = new QWidget(QgsLayoutDesignerBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mViewFrame = new QFrame(centralwidget);
        mViewFrame->setObjectName(QString::fromUtf8("mViewFrame"));
        mViewFrame->setMouseTracking(true);
        mViewFrame->setFrameShape(QFrame::StyledPanel);
        mViewFrame->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(mViewFrame, 0, 0, 1, 1);

        QgsLayoutDesignerBase->setCentralWidget(centralwidget);
        mStatusBar = new QStatusBar(QgsLayoutDesignerBase);
        mStatusBar->setObjectName(QString::fromUtf8("mStatusBar"));
        QgsLayoutDesignerBase->setStatusBar(mStatusBar);
        mLayoutToolbar = new QToolBar(QgsLayoutDesignerBase);
        mLayoutToolbar->setObjectName(QString::fromUtf8("mLayoutToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mLayoutToolbar);
        mToolsToolbar = new QToolBar(QgsLayoutDesignerBase);
        mToolsToolbar->setObjectName(QString::fromUtf8("mToolsToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mToolsToolbar);
        QgsLayoutDesignerBase->insertToolBarBreak(mToolsToolbar);
        mNavigationToolbar = new QToolBar(QgsLayoutDesignerBase);
        mNavigationToolbar->setObjectName(QString::fromUtf8("mNavigationToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mNavigationToolbar);
        mActionsToolbar = new QToolBar(QgsLayoutDesignerBase);
        mActionsToolbar->setObjectName(QString::fromUtf8("mActionsToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mActionsToolbar);
        mAtlasToolbar = new QToolBar(QgsLayoutDesignerBase);
        mAtlasToolbar->setObjectName(QString::fromUtf8("mAtlasToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mAtlasToolbar);
        mReportToolbar = new QToolBar(QgsLayoutDesignerBase);
        mReportToolbar->setObjectName(QString::fromUtf8("mReportToolbar"));
        QgsLayoutDesignerBase->addToolBar(Qt::TopToolBarArea, mReportToolbar);
        mMenuBar = new QMenuBar(QgsLayoutDesignerBase);
        mMenuBar->setObjectName(QString::fromUtf8("mMenuBar"));
        mMenuBar->setGeometry(QRect(0, 0, 2180, 25));
        mLayoutMenu = new QMenu(mMenuBar);
        mLayoutMenu->setObjectName(QString::fromUtf8("mLayoutMenu"));
        mLayoutsMenu = new QMenu(mLayoutMenu);
        mLayoutsMenu->setObjectName(QString::fromUtf8("mLayoutsMenu"));
        mItemMenu = new QMenu(mMenuBar);
        mItemMenu->setObjectName(QString::fromUtf8("mItemMenu"));
        mMenuView = new QMenu(mMenuBar);
        mMenuView->setObjectName(QString::fromUtf8("mMenuView"));
        mToolbarMenu = new QMenu(mMenuView);
        mToolbarMenu->setObjectName(QString::fromUtf8("mToolbarMenu"));
        mPanelsMenu = new QMenu(mMenuView);
        mPanelsMenu->setObjectName(QString::fromUtf8("mPanelsMenu"));
        menuPreview = new QMenu(mMenuView);
        menuPreview->setObjectName(QString::fromUtf8("menuPreview"));
        menuEdit = new QMenu(mMenuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuLayout = new QMenu(mMenuBar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuAlign_Items = new QMenu(menuLayout);
        menuAlign_Items->setObjectName(QString::fromUtf8("menuAlign_Items"));
        menu_Distribute_Items = new QMenu(menuLayout);
        menu_Distribute_Items->setObjectName(QString::fromUtf8("menu_Distribute_Items"));
        menuResize = new QMenu(menuLayout);
        menuResize->setObjectName(QString::fromUtf8("menuResize"));
        mMenuAtlas = new QMenu(mMenuBar);
        mMenuAtlas->setObjectName(QString::fromUtf8("mMenuAtlas"));
        mMenuReport = new QMenu(mMenuBar);
        mMenuReport->setObjectName(QString::fromUtf8("mMenuReport"));
        menuSettings = new QMenu(mMenuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        QgsLayoutDesignerBase->setMenuBar(mMenuBar);

        mLayoutToolbar->addAction(mActionSaveProject);
        mLayoutToolbar->addSeparator();
        mLayoutToolbar->addAction(mActionNewLayout);
        mLayoutToolbar->addAction(mActionDuplicateLayout);
        mLayoutToolbar->addAction(mActionLayoutManager);
        mLayoutToolbar->addAction(mActionLoadFromTemplate);
        mLayoutToolbar->addAction(mActionSaveAsTemplate);
        mLayoutToolbar->addSeparator();
        mLayoutToolbar->addAction(mActionAddPages);
        mLayoutToolbar->addSeparator();
        mLayoutToolbar->addAction(mActionPrint);
        mLayoutToolbar->addAction(mActionExportAsImage);
        mLayoutToolbar->addAction(mActionExportAsSVG);
        mLayoutToolbar->addAction(mActionExportAsPDF);
        mToolsToolbar->addAction(mActionPan);
        mToolsToolbar->addAction(mActionZoomTool);
        mToolsToolbar->addAction(mActionSelectMoveItem);
        mToolsToolbar->addAction(mActionMoveItemContent);
        mToolsToolbar->addAction(mActionEditNodesItem);
        mNavigationToolbar->addAction(mActionZoomIn);
        mNavigationToolbar->addAction(mActionZoomOut);
        mNavigationToolbar->addAction(mActionZoomActual);
        mNavigationToolbar->addAction(mActionZoomAll);
        mNavigationToolbar->addAction(mActionRefreshView);
        mActionsToolbar->addAction(mActionLockItems);
        mActionsToolbar->addAction(mActionUnlockAll);
        mActionsToolbar->addAction(mActionGroupItems);
        mActionsToolbar->addAction(mActionUngroupItems);
        mAtlasToolbar->addAction(mActionAtlasPreview);
        mAtlasToolbar->addAction(mActionAtlasFirst);
        mAtlasToolbar->addAction(mActionAtlasPrev);
        mAtlasToolbar->addAction(mActionAtlasNext);
        mAtlasToolbar->addAction(mActionAtlasLast);
        mAtlasToolbar->addAction(mActionPrintAtlas);
        mAtlasToolbar->addAction(mActionAtlasSettings);
        mReportToolbar->addAction(mActionPrintReport);
        mReportToolbar->addAction(mActionExportReportAsImage);
        mReportToolbar->addAction(mActionExportReportAsSVG);
        mReportToolbar->addAction(mActionExportReportAsPDF);
        mReportToolbar->addAction(mActionReportSettings);
        mMenuBar->addAction(mLayoutMenu->menuAction());
        mMenuBar->addAction(menuEdit->menuAction());
        mMenuBar->addAction(mMenuView->menuAction());
        mMenuBar->addAction(menuLayout->menuAction());
        mMenuBar->addAction(mItemMenu->menuAction());
        mMenuBar->addAction(mMenuAtlas->menuAction());
        mMenuBar->addAction(mMenuReport->menuAction());
        mMenuBar->addAction(menuSettings->menuAction());
        mLayoutMenu->addAction(mActionSaveProject);
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionNewLayout);
        mLayoutMenu->addAction(mActionDuplicateLayout);
        mLayoutMenu->addAction(mActionRemoveLayout);
        mLayoutMenu->addAction(mActionLayoutManager);
        mLayoutMenu->addAction(mLayoutsMenu->menuAction());
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionLayoutProperties);
        mLayoutMenu->addAction(mActionRenameLayout);
        mLayoutMenu->addAction(mActionAddPages);
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionLoadFromTemplate);
        mLayoutMenu->addAction(mActionSaveAsTemplate);
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionExportAsImage);
        mLayoutMenu->addAction(mActionExportAsSVG);
        mLayoutMenu->addAction(mActionExportAsPDF);
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionPageSetup);
        mLayoutMenu->addAction(mActionPrint);
        mLayoutMenu->addSeparator();
        mLayoutMenu->addAction(mActionClose);
        mMenuView->addAction(mActionRefreshView);
        mMenuView->addAction(menuPreview->menuAction());
        mMenuView->addSeparator();
        mMenuView->addAction(mActionZoomIn);
        mMenuView->addAction(mActionZoomOut);
        mMenuView->addAction(mActionZoomActual);
        mMenuView->addAction(mActionZoomAll);
        mMenuView->addAction(mActionZoomToWidth);
        mMenuView->addSeparator();
        mMenuView->addAction(mActionShowGrid);
        mMenuView->addAction(mActionSnapGrid);
        mMenuView->addSeparator();
        mMenuView->addAction(mActionShowGuides);
        mMenuView->addAction(mActionSnapGuides);
        mMenuView->addAction(mActionSmartGuides);
        mMenuView->addAction(mActionManageGuides);
        mMenuView->addAction(mActionClearGuides);
        mMenuView->addSeparator();
        mMenuView->addAction(mActionShowRulers);
        mMenuView->addAction(mActionShowBoxes);
        mMenuView->addAction(mActionShowPage);
        mMenuView->addSeparator();
        mMenuView->addAction(mToolbarMenu->menuAction());
        mMenuView->addAction(mPanelsMenu->menuAction());
        mMenuView->addAction(mActionToggleFullScreen);
        mMenuView->addAction(mActionHidePanels);
        menuPreview->addAction(mActionPreviewModeOff);
        menuPreview->addAction(mActionPreviewModeGrayscale);
        menuPreview->addAction(mActionPreviewModeMono);
        menuPreview->addAction(mActionPreviewProtanope);
        menuPreview->addAction(mActionPreviewDeuteranope);
        menuEdit->addSeparator();
        menuEdit->addAction(mActionDeleteSelection);
        menuEdit->addSeparator();
        menuEdit->addAction(mActionPasteInPlace);
        menuEdit->addSeparator();
        menuEdit->addAction(mActionSelectAll);
        menuEdit->addAction(mActionDeselectAll);
        menuEdit->addAction(mActionInvertSelection);
        menuEdit->addAction(mActionSelectNextBelow);
        menuEdit->addAction(mActionSelectNextAbove);
        menuEdit->addSeparator();
        menuEdit->addAction(mActionPan);
        menuEdit->addAction(mActionZoomTool);
        menuEdit->addAction(mActionSelectMoveItem);
        menuEdit->addAction(mActionMoveItemContent);
        menuEdit->addAction(mActionEditNodesItem);
        menuLayout->addAction(mActionGroupItems);
        menuLayout->addAction(mActionUngroupItems);
        menuLayout->addSeparator();
        menuLayout->addAction(mActionRaiseItems);
        menuLayout->addAction(mActionLowerItems);
        menuLayout->addAction(mActionMoveItemsToTop);
        menuLayout->addAction(mActionMoveItemsToBottom);
        menuLayout->addSeparator();
        menuLayout->addAction(mActionLockItems);
        menuLayout->addAction(mActionUnlockAll);
        menuLayout->addSeparator();
        menuLayout->addAction(menuAlign_Items->menuAction());
        menuLayout->addAction(menu_Distribute_Items->menuAction());
        menuLayout->addAction(menuResize->menuAction());
        menuAlign_Items->addAction(mActionAlignLeft);
        menuAlign_Items->addAction(mActionAlignHCenter);
        menuAlign_Items->addAction(mActionAlignRight);
        menuAlign_Items->addSeparator();
        menuAlign_Items->addAction(mActionAlignBottom);
        menuAlign_Items->addAction(mActionAlignVCenter);
        menuAlign_Items->addAction(mActionAlignTop);
        menu_Distribute_Items->addAction(mActionDistributeLeft);
        menu_Distribute_Items->addAction(mActionDistributeHCenter);
        menu_Distribute_Items->addAction(mActionDistributeHSpace);
        menu_Distribute_Items->addAction(mActionDistributeRight);
        menu_Distribute_Items->addSeparator();
        menu_Distribute_Items->addAction(mActionDistributeTop);
        menu_Distribute_Items->addAction(mActionDistributeVCenter);
        menu_Distribute_Items->addAction(mActionDistributeVSpace);
        menu_Distribute_Items->addAction(mActionDistributeBottom);
        menuResize->addAction(mActionResizeNarrowest);
        menuResize->addAction(mActionResizeWidest);
        menuResize->addSeparator();
        menuResize->addAction(mActionResizeShortest);
        menuResize->addAction(mActionResizeTallest);
        menuResize->addSeparator();
        menuResize->addAction(mActionResizeToSquare);
        mMenuAtlas->addAction(mActionAtlasPreview);
        mMenuAtlas->addSeparator();
        mMenuAtlas->addAction(mActionAtlasFirst);
        mMenuAtlas->addAction(mActionAtlasPrev);
        mMenuAtlas->addAction(mActionAtlasNext);
        mMenuAtlas->addAction(mActionAtlasLast);
        mMenuAtlas->addSeparator();
        mMenuAtlas->addAction(mActionPrintAtlas);
        mMenuAtlas->addAction(mActionExportAtlasAsImage);
        mMenuAtlas->addAction(mActionExportAtlasAsSVG);
        mMenuAtlas->addAction(mActionExportAtlasAsPDF);
        mMenuAtlas->addSeparator();
        mMenuAtlas->addAction(mActionAtlasSettings);
        mMenuReport->addAction(mActionPrintReport);
        mMenuReport->addAction(mActionExportReportAsImage);
        mMenuReport->addAction(mActionExportReportAsSVG);
        mMenuReport->addAction(mActionExportReportAsPDF);
        mMenuReport->addSeparator();
        mMenuReport->addAction(mActionReportSettings);
        menuSettings->addAction(mActionOptions);

        retranslateUi(QgsLayoutDesignerBase);

        QMetaObject::connectSlotsByName(QgsLayoutDesignerBase);
    } // setupUi

    void retranslateUi(QMainWindow *QgsLayoutDesignerBase)
    {
        QgsLayoutDesignerBase->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Main Window", nullptr));
        mActionClose->setText(QApplication::translate("QgsLayoutDesignerBase", "&Close", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionClose->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Close designer", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionClose->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPan->setText(QApplication::translate("QgsLayoutDesignerBase", "Pan Layout", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionPan->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "P", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomTool->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomTool->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Zoom", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomTool->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Z", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectMoveItem->setText(QApplication::translate("QgsLayoutDesignerBase", "Select/Move Item", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectMoveItem->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Select/Move item", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSelectMoveItem->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "V", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomAll->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom &Full", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomAll->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Zoom full", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomAll->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+0", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomIn->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom &In", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomIn->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Zoom in", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomIn->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl++", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomOut->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom &Out", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomOut->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Zoom out", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomOut->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomActual->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom to &100%", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomActual->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Zoom to 100%", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomActual->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+1", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomToWidth->setText(QApplication::translate("QgsLayoutDesignerBase", "Zoom to Width", nullptr));
        mActionShowRulers->setText(QApplication::translate("QgsLayoutDesignerBase", "Show Ru&lers", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowRulers->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Show rulers", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionShowRulers->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        mActionToggleFullScreen->setText(QApplication::translate("QgsLayoutDesignerBase", "Toggle Full Scr&een", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionToggleFullScreen->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Toggle full screen mode", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionToggleFullScreen->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "F11", nullptr));
#endif // QT_NO_SHORTCUT
        mActionAddPages->setText(QApplication::translate("QgsLayoutDesignerBase", "Add Pages\342\200\246", nullptr));
        mActionShowGrid->setText(QApplication::translate("QgsLayoutDesignerBase", "Show &Grid", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowGrid->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Show grid", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionShowGrid->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+'", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSnapGrid->setText(QApplication::translate("QgsLayoutDesignerBase", "S&nap to Grid", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSnapGrid->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Snap to grid", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSnapGrid->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+'", nullptr));
#endif // QT_NO_SHORTCUT
        mActionManageGuides->setText(QApplication::translate("QgsLayoutDesignerBase", "Manage Guides\342\200\246", nullptr));
        mActionShowGuides->setText(QApplication::translate("QgsLayoutDesignerBase", "Show G&uides", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowGuides->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Show guides", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionShowGuides->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+;", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSnapGuides->setText(QApplication::translate("QgsLayoutDesignerBase", "&Snap to Guides", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSnapGuides->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Snap to guides", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSnapGuides->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+;", nullptr));
#endif // QT_NO_SHORTCUT
        mActionClearGuides->setText(QApplication::translate("QgsLayoutDesignerBase", "&Clear Guides", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionClearGuides->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Clear guides", nullptr));
#endif // QT_NO_TOOLTIP
        mActionLayoutProperties->setText(QApplication::translate("QgsLayoutDesignerBase", "Layout Properties\342\200\246", nullptr));
        mActionShowBoxes->setText(QApplication::translate("QgsLayoutDesignerBase", "Show Bounding Boxes", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowBoxes->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Show bounding boxes", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionShowBoxes->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+B", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSmartGuides->setText(QApplication::translate("QgsLayoutDesignerBase", "S&mart Guides", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSmartGuides->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Smart guides", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSmartGuides->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Alt+;", nullptr));
#endif // QT_NO_SHORTCUT
        mActionDeselectAll->setText(QApplication::translate("QgsLayoutDesignerBase", "D&eselect All", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDeselectAll->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Deselect all", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionDeselectAll->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+A", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectAll->setText(QApplication::translate("QgsLayoutDesignerBase", "&Select All", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectAll->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Select all items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSelectAll->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        mActionInvertSelection->setText(QApplication::translate("QgsLayoutDesignerBase", "&Invert Selection", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionInvertSelection->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Invert selection", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSelectNextBelow->setText(QApplication::translate("QgsLayoutDesignerBase", "Select Next Item &Below", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectNextBelow->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Select next item below", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSelectNextBelow->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Alt+[", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectNextAbove->setText(QApplication::translate("QgsLayoutDesignerBase", "Select Next Item &Above", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectNextAbove->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Select next item above", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSelectNextAbove->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Alt+]", nullptr));
#endif // QT_NO_SHORTCUT
        mActionLockItems->setText(QApplication::translate("QgsLayoutDesignerBase", "Loc&k Selected Items", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionLockItems->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        mActionUnlockAll->setText(QApplication::translate("QgsLayoutDesignerBase", "Unl&ock All", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionUnlockAll->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Unlock All Items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionUnlockAll->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+L", nullptr));
#endif // QT_NO_SHORTCUT
        mActionHidePanels->setText(QApplication::translate("QgsLayoutDesignerBase", "Toggle Panel &Visibility", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionHidePanels->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Hide panels", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionHidePanels->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Tab", nullptr));
#endif // QT_NO_SHORTCUT
        mActionRaiseItems->setText(QApplication::translate("QgsLayoutDesignerBase", "&Raise", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRaiseItems->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Raise selected items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionRaiseItems->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+]", nullptr));
#endif // QT_NO_SHORTCUT
        mActionLowerItems->setText(QApplication::translate("QgsLayoutDesignerBase", "&Lower", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionLowerItems->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Lower selected items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionLowerItems->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+[", nullptr));
#endif // QT_NO_SHORTCUT
        mActionMoveItemsToTop->setText(QApplication::translate("QgsLayoutDesignerBase", "Bring to &Front", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionMoveItemsToTop->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Move selected items to top", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionMoveItemsToTop->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+]", nullptr));
#endif // QT_NO_SHORTCUT
        mActionMoveItemsToBottom->setText(QApplication::translate("QgsLayoutDesignerBase", "Send to &Back", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionMoveItemsToBottom->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Move selected items to bottom", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionMoveItemsToBottom->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+[", nullptr));
#endif // QT_NO_SHORTCUT
        mActionAlignLeft->setText(QApplication::translate("QgsLayoutDesignerBase", "Align &Left", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignLeft->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align selected items left", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAlignHCenter->setText(QApplication::translate("QgsLayoutDesignerBase", "Align &Center", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignHCenter->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align center horizontal", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAlignRight->setText(QApplication::translate("QgsLayoutDesignerBase", "Align &Right", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignRight->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align selected items right", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAlignTop->setText(QApplication::translate("QgsLayoutDesignerBase", "Align &Top", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignTop->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align selected items to top", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAlignVCenter->setText(QApplication::translate("QgsLayoutDesignerBase", "Align Center &Vertical", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignVCenter->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align center vertical", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAlignBottom->setText(QApplication::translate("QgsLayoutDesignerBase", "Align &Bottom", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAlignBottom->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Align selected items bottom", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeLeft->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Left Edges", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeLeft->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes left edges of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeHCenter->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute Horizontal &Centers", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeHCenter->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes horizontal centers of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeHSpace->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Horizontal Spacing Equally", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeHSpace->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes the horizontal spacing equally between all items", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeRight->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Right Edges", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeRight->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes right edges of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeTop->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Top Edges", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeTop->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes top edges of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeVCenter->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Vertical Centers", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeVCenter->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes vertical centers of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeVSpace->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute Vertical Spacing &Equally", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeVSpace->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes items equidistantly with respect to their vertical edges", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDistributeBottom->setText(QApplication::translate("QgsLayoutDesignerBase", "Distribute &Bottom Edges", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDistributeBottom->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Distributes bottom edges of items equidistantly", nullptr));
#endif // QT_NO_TOOLTIP
        mActionResizeNarrowest->setText(QApplication::translate("QgsLayoutDesignerBase", "Resize to &Narrowest", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionResizeNarrowest->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Resizes item width to match the narrowest selected item", nullptr));
#endif // QT_NO_TOOLTIP
        mActionResizeWidest->setText(QApplication::translate("QgsLayoutDesignerBase", "Resize to &Widest", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionResizeWidest->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Resizes item width to match the widest selected item", nullptr));
#endif // QT_NO_TOOLTIP
        mActionResizeShortest->setText(QApplication::translate("QgsLayoutDesignerBase", "Resize to &Shortest", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionResizeShortest->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Resizes item height to match the shortest selected item", nullptr));
#endif // QT_NO_TOOLTIP
        mActionResizeTallest->setText(QApplication::translate("QgsLayoutDesignerBase", "Resize to &Tallest", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionResizeTallest->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Resizes item height to match the tallest selected item", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDeleteSelection->setText(QApplication::translate("QgsLayoutDesignerBase", "&Delete", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDeleteSelection->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Delete selected items", nullptr));
#endif // QT_NO_TOOLTIP
        mActionResizeToSquare->setText(QApplication::translate("QgsLayoutDesignerBase", "Resize to S&quare", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionResizeToSquare->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Resizes items to squares", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPreviewModeOff->setText(QApplication::translate("QgsLayoutDesignerBase", "&Normal", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPreviewModeOff->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Normal", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPreviewModeGrayscale->setText(QApplication::translate("QgsLayoutDesignerBase", "Simulate Photocopy (&Grayscale)", nullptr));
        mActionPreviewModeMono->setText(QApplication::translate("QgsLayoutDesignerBase", "Simulate Fax (&Mono)", nullptr));
        mActionPreviewProtanope->setText(QApplication::translate("QgsLayoutDesignerBase", "Simulate Color Blindness (&Protanope)", nullptr));
        mActionPreviewDeuteranope->setText(QApplication::translate("QgsLayoutDesignerBase", "Simulate Color Blindness (&Deuteranope)", nullptr));
        mActionShowPage->setText(QApplication::translate("QgsLayoutDesignerBase", "Show Pages", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowPage->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Show pages", nullptr));
#endif // QT_NO_TOOLTIP
        mActionGroupItems->setText(QApplication::translate("QgsLayoutDesignerBase", "&Group", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionGroupItems->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Group items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionGroupItems->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+G", nullptr));
#endif // QT_NO_SHORTCUT
        mActionUngroupItems->setText(QApplication::translate("QgsLayoutDesignerBase", "&Ungroup", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionUngroupItems->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Ungroup items", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionUngroupItems->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+G", nullptr));
#endif // QT_NO_SHORTCUT
        mActionRefreshView->setText(QApplication::translate("QgsLayoutDesignerBase", "&Refresh", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRefreshView->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Refresh view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionRefreshView->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        mActionEditNodesItem->setText(QApplication::translate("QgsLayoutDesignerBase", "Edit Nodes Item", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionEditNodesItem->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Edit Nodes Item", nullptr));
#endif // QT_NO_TOOLTIP
        mActionMoveItemContent->setText(QApplication::translate("QgsLayoutDesignerBase", "Move &Content", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionMoveItemContent->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Move item content", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionMoveItemContent->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "C", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPasteInPlace->setText(QApplication::translate("QgsLayoutDesignerBase", "Paste in P&lace", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPasteInPlace->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Paste in place", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionPasteInPlace->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+V", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSaveAsTemplate->setText(QApplication::translate("QgsLayoutDesignerBase", "Save as &Template\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSaveAsTemplate->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Save as template", nullptr));
#endif // QT_NO_TOOLTIP
        mActionLoadFromTemplate->setText(QApplication::translate("QgsLayoutDesignerBase", "&Add Items from Template\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionLoadFromTemplate->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Add items from template", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDuplicateLayout->setText(QApplication::translate("QgsLayoutDesignerBase", "&Duplicate Layout\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDuplicateLayout->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Duplicate layout", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSaveProject->setText(QApplication::translate("QgsLayoutDesignerBase", "&Save Project", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSaveProject->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Save project", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSaveProject->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        mActionNewLayout->setText(QApplication::translate("QgsLayoutDesignerBase", "&New Layout\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionNewLayout->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "New layout", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionNewLayout->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        mActionLayoutManager->setText(QApplication::translate("QgsLayoutDesignerBase", "Layout &Manager\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionLayoutManager->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Layout manager", nullptr));
#endif // QT_NO_TOOLTIP
        mActionRenameLayout->setText(QApplication::translate("QgsLayoutDesignerBase", "Rename Layout\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRenameLayout->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Rename layout", nullptr));
#endif // QT_NO_TOOLTIP
        mActionRemoveLayout->setText(QApplication::translate("QgsLayoutDesignerBase", "Delete Layout\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRemoveLayout->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Delete layout", nullptr));
#endif // QT_NO_TOOLTIP
        mActionExportAsImage->setText(QApplication::translate("QgsLayoutDesignerBase", "Export as &Image\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExportAsImage->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Export as image", nullptr));
#endif // QT_NO_TOOLTIP
        mActionExportAsPDF->setText(QApplication::translate("QgsLayoutDesignerBase", "&Export as PDF\342\200\246", nullptr));
        mActionExportAsSVG->setText(QApplication::translate("QgsLayoutDesignerBase", "Export as S&VG\342\200\246", nullptr));
        mActionAtlasFirst->setText(QApplication::translate("QgsLayoutDesignerBase", "&First Feature", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionAtlasFirst->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+<", nullptr));
#endif // QT_NO_SHORTCUT
        mActionAtlasPrev->setText(QApplication::translate("QgsLayoutDesignerBase", "P&revious Feature", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionAtlasPrev->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+,", nullptr));
#endif // QT_NO_SHORTCUT
        mActionAtlasNext->setText(QApplication::translate("QgsLayoutDesignerBase", "&Next Feature", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionAtlasNext->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+.", nullptr));
#endif // QT_NO_SHORTCUT
        mActionAtlasLast->setText(QApplication::translate("QgsLayoutDesignerBase", "&Last Feature", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionAtlasLast->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+>", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPrintAtlas->setText(QApplication::translate("QgsLayoutDesignerBase", "&Print Atlas\342\200\246", nullptr));
        mActionExportAtlasAsImage->setText(QApplication::translate("QgsLayoutDesignerBase", "Export Atlas as &Images\342\200\246", nullptr));
        mActionExportAtlasAsSVG->setText(QApplication::translate("QgsLayoutDesignerBase", "Export Atlas as S&VG\342\200\246", nullptr));
        mActionExportAtlasAsPDF->setText(QApplication::translate("QgsLayoutDesignerBase", "&Export Atlas as PDF\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExportAtlasAsPDF->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Export Atlas as PDF", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAtlasSettings->setText(QApplication::translate("QgsLayoutDesignerBase", "Atlas &Settings", nullptr));
        mActionAtlasPreview->setText(QApplication::translate("QgsLayoutDesignerBase", "Preview &Atlas", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionAtlasPreview->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Alt+/", nullptr));
#endif // QT_NO_SHORTCUT
        mActionExportReportAsImage->setText(QApplication::translate("QgsLayoutDesignerBase", "Export Report as &Images\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExportReportAsImage->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Export Report as Images", nullptr));
#endif // QT_NO_TOOLTIP
        mActionExportReportAsSVG->setText(QApplication::translate("QgsLayoutDesignerBase", "Export Report as S&VG\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExportReportAsSVG->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Export Report as SVG", nullptr));
#endif // QT_NO_TOOLTIP
        mActionExportReportAsPDF->setText(QApplication::translate("QgsLayoutDesignerBase", "&Export Report as PDF\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExportReportAsPDF->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Export Report as PDF", nullptr));
#endif // QT_NO_TOOLTIP
        mActionReportSettings->setText(QApplication::translate("QgsLayoutDesignerBase", "Report &Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionReportSettings->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Report Settings", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPrint->setText(QApplication::translate("QgsLayoutDesignerBase", "&Print\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPrint->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Print Layout", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionPrint->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPrintReport->setText(QApplication::translate("QgsLayoutDesignerBase", "&Print Report\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPrintReport->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Print Report", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPageSetup->setText(QApplication::translate("QgsLayoutDesignerBase", "Pa&ge Setup\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPageSetup->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Page setup", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionPageSetup->setShortcut(QApplication::translate("QgsLayoutDesignerBase", "Ctrl+Shift+P", nullptr));
#endif // QT_NO_SHORTCUT
        mActionOptions->setText(QApplication::translate("QgsLayoutDesignerBase", "Layout &Options\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionOptions->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Layout Options", nullptr));
#endif // QT_NO_TOOLTIP
        mLayoutToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Layout Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        mLayoutToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Layout Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
        mToolsToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Toolbox", nullptr));
#ifndef QT_NO_TOOLTIP
        mToolsToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Toolbox", nullptr));
#endif // QT_NO_TOOLTIP
        mNavigationToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Navigation Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        mNavigationToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Navigation Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
        mActionsToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Actions Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionsToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Actions Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
        mAtlasToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Atlas Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        mAtlasToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Atlas Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
        mReportToolbar->setWindowTitle(QApplication::translate("QgsLayoutDesignerBase", "Report Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        mReportToolbar->setToolTip(QApplication::translate("QgsLayoutDesignerBase", "Report Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
        mLayoutMenu->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Layout", nullptr));
        mLayoutsMenu->setTitle(QApplication::translate("QgsLayoutDesignerBase", "Layouts", nullptr));
        mItemMenu->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Add Item", nullptr));
        mMenuView->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&View", nullptr));
        mToolbarMenu->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Toolbars", nullptr));
        mPanelsMenu->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Panels", nullptr));
        menuPreview->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Preview", nullptr));
        menuEdit->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Edit", nullptr));
        menuLayout->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Items", nullptr));
        menuAlign_Items->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Align Items", nullptr));
        menu_Distribute_Items->setTitle(QApplication::translate("QgsLayoutDesignerBase", "&Distribute Items", nullptr));
        menuResize->setTitle(QApplication::translate("QgsLayoutDesignerBase", "Re&size", nullptr));
        mMenuAtlas->setTitle(QApplication::translate("QgsLayoutDesignerBase", "Atlas", nullptr));
        mMenuReport->setTitle(QApplication::translate("QgsLayoutDesignerBase", "Report", nullptr));
        menuSettings->setTitle(QApplication::translate("QgsLayoutDesignerBase", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsLayoutDesignerBase: public Ui_QgsLayoutDesignerBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSLAYOUTDESIGNERBASE_H
