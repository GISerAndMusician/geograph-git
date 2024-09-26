/********************************************************************************
** Form generated from reading UI file 'GgsApp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSAPP_H
#define UI_GGSAPP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GgsAppClass
{
public:
    QAction *actionAddVectoLayer;
    QAction *mActionStyleDock;
    QAction *mActionZoomIn;
    QAction *mActionZoomOut;
    QAction *mActionPan;
    QAction *mActionIdentify;
    QAction *mActionSelectFeatures;
    QAction *mActionSelectPolygon;
    QAction *mActionSelectFreehand;
    QAction *mActionSelectRadius;
    QAction *mActionRemoveLayer;
    QAction *mActionShowAllLayers;
    QAction *mActionHideAllLayers;
    QAction *mActionShowSelectedLayers;
    QAction *mActionHideSelectedLayers;
    QAction *mActionToggleSelectedLayers;
    QAction *mActionToggleSelectedLayersIndependently;
    QAction *mActionHideDeselectedLayers;
    QAction *action_2;
    QAction *actionFDEB;
    QAction *actionAddCSVGraphLayer;
    QAction *actionMINGLE;
    QAction *actionKDEEB;
    QAction *actionLocalWindow;
    QAction *actionMoleView;
    QAction *actionAggregation;
    QAction *actionAddODLayer;
    QAction *actionCluster;
    QAction *actionGraphStatistic;
    QAction *actionBackbone;
    QAction *actionSelectNode;
    QAction *actionSelectNodeAndAdjEdges;
    QAction *actionSelectEdge;
    QAction *actionRemoveGraphElements;
    QAction *actionSelectNodeAndEdge;
    QAction *actionClearSelection;
    QAction *actionExportGraphFile;
    QAction *actionKcore;
    QAction *actionConvexHull;
    QAction *actionSimilarity;
    QAction *actionInfoAmount;
    QAction *actionactionExportCSVGraphLayer;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuAddLayer;
    QMenu *menu_2;
    QMenu *menu_4;
    QMenu *menu_V;
    QMenu *menuPanel;
    QMenu *menu_L;
    QMenu *menu_B;
    QMenu *menu_I;
    QMenu *menu_P;
    QMenu *menu_3;
    QToolBar *FileToolBar;
    QStatusBar *statusBar;
    QToolBar *ViewToolBar;
    QToolBar *LayersToolBar;
    QToolBar *BundlingToolBar;
    QToolBar *InteractionToolBar;

    void setupUi(QMainWindow *GgsAppClass)
    {
        if (GgsAppClass->objectName().isEmpty())
            GgsAppClass->setObjectName(QString::fromUtf8("GgsAppClass"));
        GgsAppClass->resize(853, 778);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graph/bundling/graphbundling.png"), QSize(), QIcon::Normal, QIcon::Off);
        GgsAppClass->setWindowIcon(icon);
        actionAddVectoLayer = new QAction(GgsAppClass);
        actionAddVectoLayer->setObjectName(QString::fromUtf8("actionAddVectoLayer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qgis/themes/default/mActionAddOgrLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddVectoLayer->setIcon(icon1);
        mActionStyleDock = new QAction(GgsAppClass);
        mActionStyleDock->setObjectName(QString::fromUtf8("mActionStyleDock"));
        mActionStyleDock->setCheckable(true);
        mActionZoomIn = new QAction(GgsAppClass);
        mActionZoomIn->setObjectName(QString::fromUtf8("mActionZoomIn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qgis/themes/default/mActionZoomIn.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomIn->setIcon(icon2);
        mActionZoomOut = new QAction(GgsAppClass);
        mActionZoomOut->setObjectName(QString::fromUtf8("mActionZoomOut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qgis/themes/default/mActionZoomOut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomOut->setIcon(icon3);
        mActionPan = new QAction(GgsAppClass);
        mActionPan->setObjectName(QString::fromUtf8("mActionPan"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qgis/themes/default/mActionPan.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPan->setIcon(icon4);
        mActionIdentify = new QAction(GgsAppClass);
        mActionIdentify->setObjectName(QString::fromUtf8("mActionIdentify"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qgis/themes/default/mActionIdentify.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionIdentify->setIcon(icon5);
        mActionSelectFeatures = new QAction(GgsAppClass);
        mActionSelectFeatures->setObjectName(QString::fromUtf8("mActionSelectFeatures"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFeatures->setIcon(icon6);
        mActionSelectPolygon = new QAction(GgsAppClass);
        mActionSelectPolygon->setObjectName(QString::fromUtf8("mActionSelectPolygon"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectPolygon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectPolygon->setIcon(icon7);
        mActionSelectFreehand = new QAction(GgsAppClass);
        mActionSelectFreehand->setObjectName(QString::fromUtf8("mActionSelectFreehand"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectFreehand.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFreehand->setIcon(icon8);
        mActionSelectRadius = new QAction(GgsAppClass);
        mActionSelectRadius->setObjectName(QString::fromUtf8("mActionSelectRadius"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectRadius.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectRadius->setIcon(icon9);
        mActionRemoveLayer = new QAction(GgsAppClass);
        mActionRemoveLayer->setObjectName(QString::fromUtf8("mActionRemoveLayer"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/qgis/themes/default/mActionRemoveLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRemoveLayer->setIcon(icon10);
        mActionShowAllLayers = new QAction(GgsAppClass);
        mActionShowAllLayers->setObjectName(QString::fromUtf8("mActionShowAllLayers"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/qgis/themes/default/mActionShowAllLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowAllLayers->setIcon(icon11);
        mActionHideAllLayers = new QAction(GgsAppClass);
        mActionHideAllLayers->setObjectName(QString::fromUtf8("mActionHideAllLayers"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideAllLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideAllLayers->setIcon(icon12);
        mActionShowSelectedLayers = new QAction(GgsAppClass);
        mActionShowSelectedLayers->setObjectName(QString::fromUtf8("mActionShowSelectedLayers"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/qgis/themes/default/mActionShowSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowSelectedLayers->setIcon(icon13);
        mActionHideSelectedLayers = new QAction(GgsAppClass);
        mActionHideSelectedLayers->setObjectName(QString::fromUtf8("mActionHideSelectedLayers"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideSelectedLayers->setIcon(icon14);
        mActionToggleSelectedLayers = new QAction(GgsAppClass);
        mActionToggleSelectedLayers->setObjectName(QString::fromUtf8("mActionToggleSelectedLayers"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/qgis/themes/default/mActionToggleSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionToggleSelectedLayers->setIcon(icon15);
        mActionToggleSelectedLayersIndependently = new QAction(GgsAppClass);
        mActionToggleSelectedLayersIndependently->setObjectName(QString::fromUtf8("mActionToggleSelectedLayersIndependently"));
        mActionHideDeselectedLayers = new QAction(GgsAppClass);
        mActionHideDeselectedLayers->setObjectName(QString::fromUtf8("mActionHideDeselectedLayers"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideDeselectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideDeselectedLayers->setIcon(icon16);
        action_2 = new QAction(GgsAppClass);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionFDEB = new QAction(GgsAppClass);
        actionFDEB->setObjectName(QString::fromUtf8("actionFDEB"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/graph/bundling/FDEB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFDEB->setIcon(icon17);
        actionAddCSVGraphLayer = new QAction(GgsAppClass);
        actionAddCSVGraphLayer->setObjectName(QString::fromUtf8("actionAddCSVGraphLayer"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/qgis/themes/default/mActionAddDelimitedTextLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddCSVGraphLayer->setIcon(icon18);
        actionMINGLE = new QAction(GgsAppClass);
        actionMINGLE->setObjectName(QString::fromUtf8("actionMINGLE"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/graph/bundling/MINGLE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMINGLE->setIcon(icon19);
        actionKDEEB = new QAction(GgsAppClass);
        actionKDEEB->setObjectName(QString::fromUtf8("actionKDEEB"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/graph/bundling/KDEEB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKDEEB->setIcon(icon20);
        actionLocalWindow = new QAction(GgsAppClass);
        actionLocalWindow->setObjectName(QString::fromUtf8("actionLocalWindow"));
        actionLocalWindow->setCheckable(true);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/graph/bundling/LWO.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocalWindow->setIcon(icon21);
        actionMoleView = new QAction(GgsAppClass);
        actionMoleView->setObjectName(QString::fromUtf8("actionMoleView"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/graph/bundling/MoleView.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMoleView->setIcon(icon22);
        actionAggregation = new QAction(GgsAppClass);
        actionAggregation->setObjectName(QString::fromUtf8("actionAggregation"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/graph/bundling/aggregation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAggregation->setIcon(icon23);
        actionAddODLayer = new QAction(GgsAppClass);
        actionAddODLayer->setObjectName(QString::fromUtf8("actionAddODLayer"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/graph/bundling/ODData.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddODLayer->setIcon(icon24);
        actionCluster = new QAction(GgsAppClass);
        actionCluster->setObjectName(QString::fromUtf8("actionCluster"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/graph/bundling/cluster.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCluster->setIcon(icon25);
        actionGraphStatistic = new QAction(GgsAppClass);
        actionGraphStatistic->setObjectName(QString::fromUtf8("actionGraphStatistic"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/graph/bundling/degreeDistribution.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraphStatistic->setIcon(icon26);
        actionBackbone = new QAction(GgsAppClass);
        actionBackbone->setObjectName(QString::fromUtf8("actionBackbone"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/graph/bundling/backboneExtraction.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackbone->setIcon(icon27);
        actionSelectNode = new QAction(GgsAppClass);
        actionSelectNode->setObjectName(QString::fromUtf8("actionSelectNode"));
        actionSelectNode->setCheckable(true);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/graph/bundling/selectnodes.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectNode->setIcon(icon28);
        actionSelectNodeAndAdjEdges = new QAction(GgsAppClass);
        actionSelectNodeAndAdjEdges->setObjectName(QString::fromUtf8("actionSelectNodeAndAdjEdges"));
        actionSelectNodeAndAdjEdges->setCheckable(true);
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/graph/bundling/selectnodeandadjedge.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectNodeAndAdjEdges->setIcon(icon29);
        actionSelectEdge = new QAction(GgsAppClass);
        actionSelectEdge->setObjectName(QString::fromUtf8("actionSelectEdge"));
        actionSelectEdge->setCheckable(true);
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/graph/bundling/selectedges.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectEdge->setIcon(icon30);
        actionRemoveGraphElements = new QAction(GgsAppClass);
        actionRemoveGraphElements->setObjectName(QString::fromUtf8("actionRemoveGraphElements"));
        actionSelectNodeAndEdge = new QAction(GgsAppClass);
        actionSelectNodeAndEdge->setObjectName(QString::fromUtf8("actionSelectNodeAndEdge"));
        actionSelectNodeAndEdge->setCheckable(true);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/graph/bundling/selectnodeandedge.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectNodeAndEdge->setIcon(icon31);
        actionClearSelection = new QAction(GgsAppClass);
        actionClearSelection->setObjectName(QString::fromUtf8("actionClearSelection"));
        actionExportGraphFile = new QAction(GgsAppClass);
        actionExportGraphFile->setObjectName(QString::fromUtf8("actionExportGraphFile"));
        actionKcore = new QAction(GgsAppClass);
        actionKcore->setObjectName(QString::fromUtf8("actionKcore"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/graph/bundling/kcore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKcore->setIcon(icon32);
        actionConvexHull = new QAction(GgsAppClass);
        actionConvexHull->setObjectName(QString::fromUtf8("actionConvexHull"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/graph/bundling/convexHull.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvexHull->setIcon(icon33);
        actionSimilarity = new QAction(GgsAppClass);
        actionSimilarity->setObjectName(QString::fromUtf8("actionSimilarity"));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/graph/bundling/similarity.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSimilarity->setIcon(icon34);
        actionInfoAmount = new QAction(GgsAppClass);
        actionInfoAmount->setObjectName(QString::fromUtf8("actionInfoAmount"));
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/graph/bundling/infoamount.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfoAmount->setIcon(icon35);
        actionactionExportCSVGraphLayer = new QAction(GgsAppClass);
        actionactionExportCSVGraphLayer->setObjectName(QString::fromUtf8("actionactionExportCSVGraphLayer"));
        centralWidget = new QWidget(GgsAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GgsAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GgsAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 853, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuAddLayer = new QMenu(menu);
        menuAddLayer->setObjectName(QString::fromUtf8("menuAddLayer"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_4 = new QMenu(menu);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QString::fromUtf8("menu_V"));
        menuPanel = new QMenu(menu_V);
        menuPanel->setObjectName(QString::fromUtf8("menuPanel"));
        menu_L = new QMenu(menuBar);
        menu_L->setObjectName(QString::fromUtf8("menu_L"));
        menu_B = new QMenu(menuBar);
        menu_B->setObjectName(QString::fromUtf8("menu_B"));
        menu_I = new QMenu(menuBar);
        menu_I->setObjectName(QString::fromUtf8("menu_I"));
        menu_P = new QMenu(menuBar);
        menu_P->setObjectName(QString::fromUtf8("menu_P"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        GgsAppClass->setMenuBar(menuBar);
        FileToolBar = new QToolBar(GgsAppClass);
        FileToolBar->setObjectName(QString::fromUtf8("FileToolBar"));
        GgsAppClass->addToolBar(Qt::TopToolBarArea, FileToolBar);
        statusBar = new QStatusBar(GgsAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GgsAppClass->setStatusBar(statusBar);
        ViewToolBar = new QToolBar(GgsAppClass);
        ViewToolBar->setObjectName(QString::fromUtf8("ViewToolBar"));
        GgsAppClass->addToolBar(Qt::TopToolBarArea, ViewToolBar);
        LayersToolBar = new QToolBar(GgsAppClass);
        LayersToolBar->setObjectName(QString::fromUtf8("LayersToolBar"));
        GgsAppClass->addToolBar(Qt::TopToolBarArea, LayersToolBar);
        BundlingToolBar = new QToolBar(GgsAppClass);
        BundlingToolBar->setObjectName(QString::fromUtf8("BundlingToolBar"));
        GgsAppClass->addToolBar(Qt::TopToolBarArea, BundlingToolBar);
        InteractionToolBar = new QToolBar(GgsAppClass);
        InteractionToolBar->setObjectName(QString::fromUtf8("InteractionToolBar"));
        GgsAppClass->addToolBar(Qt::TopToolBarArea, InteractionToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_P->menuAction());
        menuBar->addAction(menu_L->menuAction());
        menuBar->addAction(menu_B->menuAction());
        menuBar->addAction(menu_I->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(menuAddLayer->menuAction());
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menu->addAction(menu_4->menuAction());
        menuAddLayer->addAction(actionAddVectoLayer);
        menuAddLayer->addAction(actionAddODLayer);
        menu_2->addAction(actionAddCSVGraphLayer);
        menu_4->addAction(actionExportGraphFile);
        menu_4->addAction(actionactionExportCSVGraphLayer);
        menu_V->addAction(menuPanel->menuAction());
        menu_V->addSeparator();
        menu_V->addAction(mActionPan);
        menu_V->addAction(mActionZoomIn);
        menu_V->addAction(mActionZoomOut);
        menu_V->addAction(mActionIdentify);
        menu_V->addSeparator();
        menu_V->addAction(mActionSelectFeatures);
        menu_V->addAction(mActionSelectPolygon);
        menu_V->addAction(mActionSelectFreehand);
        menu_V->addAction(mActionSelectRadius);
        menu_V->addSeparator();
        menu_V->addAction(actionSelectNode);
        menu_V->addAction(actionSelectEdge);
        menu_V->addAction(actionSelectNodeAndEdge);
        menu_V->addAction(actionSelectNodeAndAdjEdges);
        menu_V->addSeparator();
        menu_V->addAction(actionClearSelection);
        menuPanel->addAction(mActionStyleDock);
        menu_L->addAction(mActionShowAllLayers);
        menu_L->addAction(mActionHideAllLayers);
        menu_L->addAction(mActionShowSelectedLayers);
        menu_L->addAction(mActionHideSelectedLayers);
        menu_L->addAction(mActionToggleSelectedLayers);
        menu_L->addAction(mActionToggleSelectedLayersIndependently);
        menu_L->addSeparator();
        menu_L->addAction(mActionRemoveLayer);
        menu_L->addAction(mActionHideDeselectedLayers);
        menu_L->addSeparator();
        menu_L->addAction(actionRemoveGraphElements);
        menu_B->addAction(actionFDEB);
        menu_B->addAction(actionMINGLE);
        menu_B->addAction(actionKDEEB);
        menu_I->addAction(actionLocalWindow);
        menu_I->addAction(actionMoleView);
        menu_P->addAction(actionCluster);
        menu_P->addAction(actionKcore);
        menu_P->addAction(actionBackbone);
        menu_P->addAction(actionAggregation);
        menu_P->addSeparator();
        menu_P->addAction(actionConvexHull);
        menu_3->addAction(actionGraphStatistic);
        menu_3->addAction(actionSimilarity);
        menu_3->addAction(actionInfoAmount);
        FileToolBar->addAction(actionAddVectoLayer);
        FileToolBar->addSeparator();
        FileToolBar->addAction(actionAddCSVGraphLayer);
        ViewToolBar->addAction(mActionPan);
        ViewToolBar->addAction(mActionZoomIn);
        ViewToolBar->addAction(mActionZoomOut);
        ViewToolBar->addAction(mActionIdentify);
        ViewToolBar->addSeparator();
        ViewToolBar->addAction(mActionSelectFeatures);
        LayersToolBar->addAction(mActionShowAllLayers);
        LayersToolBar->addAction(mActionHideAllLayers);
        LayersToolBar->addAction(mActionShowSelectedLayers);
        LayersToolBar->addAction(mActionHideSelectedLayers);
        LayersToolBar->addSeparator();
        LayersToolBar->addAction(mActionRemoveLayer);
        BundlingToolBar->addAction(actionFDEB);
        BundlingToolBar->addAction(actionMINGLE);
        BundlingToolBar->addAction(actionKDEEB);
        InteractionToolBar->addAction(actionLocalWindow);
        InteractionToolBar->addAction(actionMoleView);

        retranslateUi(GgsAppClass);

        QMetaObject::connectSlotsByName(GgsAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *GgsAppClass)
    {
        GgsAppClass->setWindowTitle(QApplication::translate("GgsAppClass", "geograph", nullptr));
        actionAddVectoLayer->setText(QApplication::translate("GgsAppClass", "\346\267\273\345\212\240\347\237\242\351\207\217\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAddVectoLayer->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Shift+V", nullptr));
#endif // QT_NO_SHORTCUT
        mActionStyleDock->setText(QApplication::translate("GgsAppClass", "\345\233\276\345\261\202\346\240\267\345\274\217", nullptr));
        mActionZoomIn->setText(QApplication::translate("GgsAppClass", "\346\224\276\345\244\247", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionZoomIn->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomOut->setText(QApplication::translate("GgsAppClass", "\347\274\251\345\260\217", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionZoomOut->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPan->setText(QApplication::translate("GgsAppClass", "\345\271\263\347\247\273", nullptr));
        mActionIdentify->setText(QApplication::translate("GgsAppClass", "identity", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionIdentify->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Shift+I", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectFeatures->setText(QApplication::translate("GgsAppClass", "\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectPolygon->setText(QApplication::translate("GgsAppClass", "\346\214\211\345\244\232\350\276\271\345\275\242\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectFreehand->setText(QApplication::translate("GgsAppClass", "\350\207\252\347\224\261\346\211\213\347\273\230\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectRadius->setText(QApplication::translate("GgsAppClass", "\346\214\211\345\215\212\345\276\204\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionRemoveLayer->setText(QApplication::translate("GgsAppClass", "\347\247\273\351\231\244\345\233\276\345\261\202/\347\273\204", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionRemoveLayer->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        mActionShowAllLayers->setText(QApplication::translate("GgsAppClass", "\346\230\276\347\244\272\346\211\200\346\234\211\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionShowAllLayers->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Shift+U", nullptr));
#endif // QT_NO_SHORTCUT
        mActionHideAllLayers->setText(QApplication::translate("GgsAppClass", "\351\232\220\350\227\217\346\211\200\346\234\211\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionHideAllLayers->setShortcut(QApplication::translate("GgsAppClass", "Ctrl+Shift+H", nullptr));
#endif // QT_NO_SHORTCUT
        mActionShowSelectedLayers->setText(QApplication::translate("GgsAppClass", "\346\230\276\347\244\272\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionHideSelectedLayers->setText(QApplication::translate("GgsAppClass", "\351\232\220\350\227\217\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionToggleSelectedLayers->setText(QApplication::translate("GgsAppClass", "\345\210\207\346\215\242\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionToggleSelectedLayersIndependently->setText(QApplication::translate("GgsAppClass", "\347\213\254\347\253\213\345\210\207\346\215\242\351\200\211\344\270\255\345\233\276\345\261\202", nullptr));
        mActionHideDeselectedLayers->setText(QApplication::translate("GgsAppClass", "\351\232\220\350\227\217\346\234\252\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        action_2->setText(QApplication::translate("GgsAppClass", "sff...", nullptr));
        actionFDEB->setText(QApplication::translate("GgsAppClass", "Force Directed Edge Bundling", nullptr));
        actionAddCSVGraphLayer->setText(QApplication::translate("GgsAppClass", "\345\257\274\345\205\245CSV\346\240\274\345\274\217\345\233\276\346\225\260\346\215\256", nullptr));
        actionMINGLE->setText(QApplication::translate("GgsAppClass", "Multilevel Agglomerative Edge Bundling", nullptr));
        actionKDEEB->setText(QApplication::translate("GgsAppClass", "Kernel Density Estimation Edge Bundling", nullptr));
        actionLocalWindow->setText(QApplication::translate("GgsAppClass", "Local Window Open", nullptr));
        actionMoleView->setText(QApplication::translate("GgsAppClass", "Mole View Open", nullptr));
        actionAggregation->setText(QApplication::translate("GgsAppClass", "\350\201\232\345\220\210", nullptr));
        actionAddODLayer->setText(QApplication::translate("GgsAppClass", "\346\267\273\345\212\240OD\346\225\260\346\215\256\345\233\276\345\261\202", nullptr));
        actionCluster->setText(QApplication::translate("GgsAppClass", "\350\201\232\347\261\273", nullptr));
        actionGraphStatistic->setText(QApplication::translate("GgsAppClass", "\345\244\215\346\235\202\347\275\221\347\273\234\346\214\207\346\240\207\347\273\237\350\256\241", nullptr));
        actionBackbone->setText(QApplication::translate("GgsAppClass", "\347\275\221\347\273\234\351\252\250\346\236\266\346\217\220\345\217\226", nullptr));
        actionSelectNode->setText(QApplication::translate("GgsAppClass", "\351\200\211\346\213\251\350\212\202\347\202\271", nullptr));
        actionSelectNodeAndAdjEdges->setText(QApplication::translate("GgsAppClass", "\351\200\211\346\213\251\350\212\202\347\202\271\345\217\212\345\205\266\351\202\273\346\216\245\350\277\236\350\276\271", nullptr));
        actionSelectEdge->setText(QApplication::translate("GgsAppClass", "\351\200\211\346\213\251\350\277\236\350\276\271", nullptr));
        actionRemoveGraphElements->setText(QApplication::translate("GgsAppClass", "\345\210\240\351\231\244\351\200\211\344\270\255\347\232\204\345\233\276\345\205\203\347\264\240", nullptr));
        actionSelectNodeAndEdge->setText(QApplication::translate("GgsAppClass", "\351\200\211\346\213\251\350\212\202\347\202\271\345\222\214\350\277\236\350\276\271", nullptr));
        actionClearSelection->setText(QApplication::translate("GgsAppClass", "\346\270\205\351\231\244\346\211\200\346\234\211\351\200\211\346\213\251", nullptr));
        actionExportGraphFile->setText(QApplication::translate("GgsAppClass", "\345\257\274\345\207\272\346\210\220\345\233\276\346\226\207\344\273\266\346\240\274\345\274\217", nullptr));
        actionKcore->setText(QApplication::translate("GgsAppClass", "K\346\240\270\345\210\206\350\247\243", nullptr));
        actionConvexHull->setText(QApplication::translate("GgsAppClass", "\347\202\271\347\276\244\345\207\270\345\214\205\350\256\241\347\256\227", nullptr));
        actionSimilarity->setText(QApplication::translate("GgsAppClass", "\347\233\270\344\274\274\345\272\246\350\256\241\347\256\227", nullptr));
        actionInfoAmount->setText(QApplication::translate("GgsAppClass", "\345\233\276\344\277\241\346\201\257\351\207\217\350\256\241\347\256\227", nullptr));
        actionactionExportCSVGraphLayer->setText(QApplication::translate("GgsAppClass", "\345\257\274\345\207\272CSV\346\240\274\345\274\217\345\233\276\346\226\207\344\273\266", nullptr));
        menu->setTitle(QApplication::translate("GgsAppClass", "\346\226\207\344\273\266(&F)", nullptr));
        menuAddLayer->setTitle(QApplication::translate("GgsAppClass", "\346\267\273\345\212\240\345\233\276\345\261\202", nullptr));
        menu_2->setTitle(QApplication::translate("GgsAppClass", "\345\257\274\345\205\245\345\233\276\346\225\260\346\215\256", nullptr));
        menu_4->setTitle(QApplication::translate("GgsAppClass", "\345\257\274\345\207\272\345\233\276\346\225\260\346\215\256", nullptr));
        menu_V->setTitle(QApplication::translate("GgsAppClass", "\350\247\206\345\233\276(&V)", nullptr));
        menuPanel->setTitle(QApplication::translate("GgsAppClass", "\351\235\242\346\235\277", nullptr));
        menu_L->setTitle(QApplication::translate("GgsAppClass", "\345\233\276\345\261\202(&L)", nullptr));
        menu_B->setTitle(QApplication::translate("GgsAppClass", "\346\215\206\347\273\221(&B)", nullptr));
        menu_I->setTitle(QApplication::translate("GgsAppClass", "\344\272\244\344\272\222(&I)", nullptr));
        menu_P->setTitle(QApplication::translate("GgsAppClass", "\345\244\204\347\220\206(&P)", nullptr));
        menu_3->setTitle(QApplication::translate("GgsAppClass", "\347\273\237\350\256\241(&S)", nullptr));
        ViewToolBar->setWindowTitle(QApplication::translate("GgsAppClass", "toolBar", nullptr));
        LayersToolBar->setWindowTitle(QApplication::translate("GgsAppClass", "toolBar", nullptr));
        BundlingToolBar->setWindowTitle(QApplication::translate("GgsAppClass", "toolBar", nullptr));
        InteractionToolBar->setWindowTitle(QApplication::translate("GgsAppClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GgsAppClass: public Ui_GgsAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSAPP_H
