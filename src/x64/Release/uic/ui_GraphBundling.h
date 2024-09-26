/********************************************************************************
** Form generated from reading UI file 'GraphBundling.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHBUNDLING_H
#define UI_GRAPHBUNDLING_H

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

class Ui_GraphBundlingClass
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
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuAddLayer;
    QMenu *menu_2;
    QMenu *menu_V;
    QMenu *menuPanel;
    QMenu *menu_L;
    QMenu *menu_B;
    QMenu *menu_I;
    QToolBar *FileToolBar;
    QStatusBar *statusBar;
    QToolBar *ViewToolBar;
    QToolBar *LayersToolBar;
    QToolBar *BundlingToolBar;
    QToolBar *InteractionToolBar;

    void setupUi(QMainWindow *GraphBundlingClass)
    {
        if (GraphBundlingClass->objectName().isEmpty())
            GraphBundlingClass->setObjectName(QString::fromUtf8("GraphBundlingClass"));
        GraphBundlingClass->resize(771, 778);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graph/bundling/graphbundling.png"), QSize(), QIcon::Normal, QIcon::Off);
        GraphBundlingClass->setWindowIcon(icon);
        actionAddVectoLayer = new QAction(GraphBundlingClass);
        actionAddVectoLayer->setObjectName(QString::fromUtf8("actionAddVectoLayer"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qgis/themes/default/mActionAddOgrLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddVectoLayer->setIcon(icon1);
        mActionStyleDock = new QAction(GraphBundlingClass);
        mActionStyleDock->setObjectName(QString::fromUtf8("mActionStyleDock"));
        mActionStyleDock->setCheckable(true);
        mActionZoomIn = new QAction(GraphBundlingClass);
        mActionZoomIn->setObjectName(QString::fromUtf8("mActionZoomIn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qgis/themes/default/mActionZoomIn.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomIn->setIcon(icon2);
        mActionZoomOut = new QAction(GraphBundlingClass);
        mActionZoomOut->setObjectName(QString::fromUtf8("mActionZoomOut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qgis/themes/default/mActionZoomOut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomOut->setIcon(icon3);
        mActionPan = new QAction(GraphBundlingClass);
        mActionPan->setObjectName(QString::fromUtf8("mActionPan"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qgis/themes/default/mActionPan.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPan->setIcon(icon4);
        mActionIdentify = new QAction(GraphBundlingClass);
        mActionIdentify->setObjectName(QString::fromUtf8("mActionIdentify"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qgis/themes/default/mActionIdentify.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionIdentify->setIcon(icon5);
        mActionSelectFeatures = new QAction(GraphBundlingClass);
        mActionSelectFeatures->setObjectName(QString::fromUtf8("mActionSelectFeatures"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFeatures->setIcon(icon6);
        mActionSelectPolygon = new QAction(GraphBundlingClass);
        mActionSelectPolygon->setObjectName(QString::fromUtf8("mActionSelectPolygon"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectPolygon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectPolygon->setIcon(icon7);
        mActionSelectFreehand = new QAction(GraphBundlingClass);
        mActionSelectFreehand->setObjectName(QString::fromUtf8("mActionSelectFreehand"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectFreehand.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFreehand->setIcon(icon8);
        mActionSelectRadius = new QAction(GraphBundlingClass);
        mActionSelectRadius->setObjectName(QString::fromUtf8("mActionSelectRadius"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/qgis/themes/default/mActionSelectRadius.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectRadius->setIcon(icon9);
        mActionRemoveLayer = new QAction(GraphBundlingClass);
        mActionRemoveLayer->setObjectName(QString::fromUtf8("mActionRemoveLayer"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/qgis/themes/default/mActionRemoveLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRemoveLayer->setIcon(icon10);
        mActionShowAllLayers = new QAction(GraphBundlingClass);
        mActionShowAllLayers->setObjectName(QString::fromUtf8("mActionShowAllLayers"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/qgis/themes/default/mActionShowAllLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowAllLayers->setIcon(icon11);
        mActionHideAllLayers = new QAction(GraphBundlingClass);
        mActionHideAllLayers->setObjectName(QString::fromUtf8("mActionHideAllLayers"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideAllLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideAllLayers->setIcon(icon12);
        mActionShowSelectedLayers = new QAction(GraphBundlingClass);
        mActionShowSelectedLayers->setObjectName(QString::fromUtf8("mActionShowSelectedLayers"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/qgis/themes/default/mActionShowSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowSelectedLayers->setIcon(icon13);
        mActionHideSelectedLayers = new QAction(GraphBundlingClass);
        mActionHideSelectedLayers->setObjectName(QString::fromUtf8("mActionHideSelectedLayers"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideSelectedLayers->setIcon(icon14);
        mActionToggleSelectedLayers = new QAction(GraphBundlingClass);
        mActionToggleSelectedLayers->setObjectName(QString::fromUtf8("mActionToggleSelectedLayers"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/qgis/themes/default/mActionToggleSelectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionToggleSelectedLayers->setIcon(icon15);
        mActionToggleSelectedLayersIndependently = new QAction(GraphBundlingClass);
        mActionToggleSelectedLayersIndependently->setObjectName(QString::fromUtf8("mActionToggleSelectedLayersIndependently"));
        mActionHideDeselectedLayers = new QAction(GraphBundlingClass);
        mActionHideDeselectedLayers->setObjectName(QString::fromUtf8("mActionHideDeselectedLayers"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/qgis/themes/default/mActionHideDeselectedLayers.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionHideDeselectedLayers->setIcon(icon16);
        action_2 = new QAction(GraphBundlingClass);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionFDEB = new QAction(GraphBundlingClass);
        actionFDEB->setObjectName(QString::fromUtf8("actionFDEB"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/graph/bundling/FDEB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFDEB->setIcon(icon17);
        actionAddCSVGraphLayer = new QAction(GraphBundlingClass);
        actionAddCSVGraphLayer->setObjectName(QString::fromUtf8("actionAddCSVGraphLayer"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/qgis/themes/default/mActionAddDelimitedTextLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddCSVGraphLayer->setIcon(icon18);
        actionMINGLE = new QAction(GraphBundlingClass);
        actionMINGLE->setObjectName(QString::fromUtf8("actionMINGLE"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/graph/bundling/MINGLE.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMINGLE->setIcon(icon19);
        actionKDEEB = new QAction(GraphBundlingClass);
        actionKDEEB->setObjectName(QString::fromUtf8("actionKDEEB"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/graph/bundling/KDEEB.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKDEEB->setIcon(icon20);
        actionLocalWindow = new QAction(GraphBundlingClass);
        actionLocalWindow->setObjectName(QString::fromUtf8("actionLocalWindow"));
        actionLocalWindow->setCheckable(true);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/graph/bundling/LWO.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocalWindow->setIcon(icon21);
        actionMoleView = new QAction(GraphBundlingClass);
        actionMoleView->setObjectName(QString::fromUtf8("actionMoleView"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/graph/bundling/MoleView.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMoleView->setIcon(icon22);
        centralWidget = new QWidget(GraphBundlingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GraphBundlingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphBundlingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 771, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuAddLayer = new QMenu(menu);
        menuAddLayer->setObjectName(QString::fromUtf8("menuAddLayer"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
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
        GraphBundlingClass->setMenuBar(menuBar);
        FileToolBar = new QToolBar(GraphBundlingClass);
        FileToolBar->setObjectName(QString::fromUtf8("FileToolBar"));
        GraphBundlingClass->addToolBar(Qt::TopToolBarArea, FileToolBar);
        statusBar = new QStatusBar(GraphBundlingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphBundlingClass->setStatusBar(statusBar);
        ViewToolBar = new QToolBar(GraphBundlingClass);
        ViewToolBar->setObjectName(QString::fromUtf8("ViewToolBar"));
        GraphBundlingClass->addToolBar(Qt::TopToolBarArea, ViewToolBar);
        LayersToolBar = new QToolBar(GraphBundlingClass);
        LayersToolBar->setObjectName(QString::fromUtf8("LayersToolBar"));
        GraphBundlingClass->addToolBar(Qt::TopToolBarArea, LayersToolBar);
        BundlingToolBar = new QToolBar(GraphBundlingClass);
        BundlingToolBar->setObjectName(QString::fromUtf8("BundlingToolBar"));
        GraphBundlingClass->addToolBar(Qt::TopToolBarArea, BundlingToolBar);
        InteractionToolBar = new QToolBar(GraphBundlingClass);
        InteractionToolBar->setObjectName(QString::fromUtf8("InteractionToolBar"));
        GraphBundlingClass->addToolBar(Qt::TopToolBarArea, InteractionToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_L->menuAction());
        menuBar->addAction(menu_B->menuAction());
        menuBar->addAction(menu_I->menuAction());
        menu->addAction(menuAddLayer->menuAction());
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menuAddLayer->addAction(actionAddVectoLayer);
        menu_2->addAction(actionAddCSVGraphLayer);
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
        menu_B->addAction(actionFDEB);
        menu_B->addAction(actionMINGLE);
        menu_B->addAction(actionKDEEB);
        menu_I->addAction(actionLocalWindow);
        menu_I->addAction(actionMoleView);
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

        retranslateUi(GraphBundlingClass);

        QMetaObject::connectSlotsByName(GraphBundlingClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphBundlingClass)
    {
        GraphBundlingClass->setWindowTitle(QApplication::translate("GraphBundlingClass", "GraphBundling", nullptr));
        actionAddVectoLayer->setText(QApplication::translate("GraphBundlingClass", "\346\267\273\345\212\240\347\237\242\351\207\217\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAddVectoLayer->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Shift+V", nullptr));
#endif // QT_NO_SHORTCUT
        mActionStyleDock->setText(QApplication::translate("GraphBundlingClass", "\345\233\276\345\261\202\346\240\267\345\274\217", nullptr));
        mActionZoomIn->setText(QApplication::translate("GraphBundlingClass", "\346\224\276\345\244\247", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionZoomIn->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomOut->setText(QApplication::translate("GraphBundlingClass", "\347\274\251\345\260\217", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionZoomOut->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Alt+O", nullptr));
#endif // QT_NO_SHORTCUT
        mActionPan->setText(QApplication::translate("GraphBundlingClass", "\345\271\263\347\247\273", nullptr));
        mActionIdentify->setText(QApplication::translate("GraphBundlingClass", "identity", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionIdentify->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Shift+I", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectFeatures->setText(QApplication::translate("GraphBundlingClass", "\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectPolygon->setText(QApplication::translate("GraphBundlingClass", "\346\214\211\345\244\232\350\276\271\345\275\242\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectFreehand->setText(QApplication::translate("GraphBundlingClass", "\350\207\252\347\224\261\346\211\213\347\273\230\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionSelectRadius->setText(QApplication::translate("GraphBundlingClass", "\346\214\211\345\215\212\345\276\204\351\200\211\346\213\251\350\246\201\347\264\240", nullptr));
        mActionRemoveLayer->setText(QApplication::translate("GraphBundlingClass", "\347\247\273\351\231\244\345\233\276\345\261\202/\347\273\204", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionRemoveLayer->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        mActionShowAllLayers->setText(QApplication::translate("GraphBundlingClass", "\346\230\276\347\244\272\346\211\200\346\234\211\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionShowAllLayers->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Shift+U", nullptr));
#endif // QT_NO_SHORTCUT
        mActionHideAllLayers->setText(QApplication::translate("GraphBundlingClass", "\351\232\220\350\227\217\346\211\200\346\234\211\345\233\276\345\261\202", nullptr));
#ifndef QT_NO_SHORTCUT
        mActionHideAllLayers->setShortcut(QApplication::translate("GraphBundlingClass", "Ctrl+Shift+H", nullptr));
#endif // QT_NO_SHORTCUT
        mActionShowSelectedLayers->setText(QApplication::translate("GraphBundlingClass", "\346\230\276\347\244\272\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionHideSelectedLayers->setText(QApplication::translate("GraphBundlingClass", "\351\232\220\350\227\217\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionToggleSelectedLayers->setText(QApplication::translate("GraphBundlingClass", "\345\210\207\346\215\242\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        mActionToggleSelectedLayersIndependently->setText(QApplication::translate("GraphBundlingClass", "\347\213\254\347\253\213\345\210\207\346\215\242\351\200\211\344\270\255\345\233\276\345\261\202", nullptr));
        mActionHideDeselectedLayers->setText(QApplication::translate("GraphBundlingClass", "\351\232\220\350\227\217\346\234\252\351\200\211\344\270\255\347\232\204\345\233\276\345\261\202", nullptr));
        action_2->setText(QApplication::translate("GraphBundlingClass", "sff...", nullptr));
        actionFDEB->setText(QApplication::translate("GraphBundlingClass", "Force Directed Edge Bundling", nullptr));
        actionAddCSVGraphLayer->setText(QApplication::translate("GraphBundlingClass", "\345\257\274\345\205\245CSV\346\240\274\345\274\217\345\233\276\346\225\260\346\215\256", nullptr));
        actionMINGLE->setText(QApplication::translate("GraphBundlingClass", "Multilevel Agglomerative Edge Bundling", nullptr));
        actionKDEEB->setText(QApplication::translate("GraphBundlingClass", "Kernel Density Estimation Edge Bundling", nullptr));
        actionLocalWindow->setText(QApplication::translate("GraphBundlingClass", "Local Window Open", nullptr));
        actionMoleView->setText(QApplication::translate("GraphBundlingClass", "Mole View Open", nullptr));
        menu->setTitle(QApplication::translate("GraphBundlingClass", "\346\226\207\344\273\266(&F)", nullptr));
        menuAddLayer->setTitle(QApplication::translate("GraphBundlingClass", "\346\267\273\345\212\240\345\233\276\345\261\202", nullptr));
        menu_2->setTitle(QApplication::translate("GraphBundlingClass", "\345\257\274\345\205\245\345\233\276\346\225\260\346\215\256", nullptr));
        menu_V->setTitle(QApplication::translate("GraphBundlingClass", "\350\247\206\345\233\276(&V)", nullptr));
        menuPanel->setTitle(QApplication::translate("GraphBundlingClass", "\351\235\242\346\235\277", nullptr));
        menu_L->setTitle(QApplication::translate("GraphBundlingClass", "\345\233\276\345\261\202(&L)", nullptr));
        menu_B->setTitle(QApplication::translate("GraphBundlingClass", "\346\215\206\347\273\221(&B)", nullptr));
        menu_I->setTitle(QApplication::translate("GraphBundlingClass", "\344\272\244\344\272\222(&I)", nullptr));
        ViewToolBar->setWindowTitle(QApplication::translate("GraphBundlingClass", "toolBar", nullptr));
        LayersToolBar->setWindowTitle(QApplication::translate("GraphBundlingClass", "toolBar", nullptr));
        BundlingToolBar->setWindowTitle(QApplication::translate("GraphBundlingClass", "toolBar", nullptr));
        InteractionToolBar->setWindowTitle(QApplication::translate("GraphBundlingClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphBundlingClass: public Ui_GraphBundlingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHBUNDLING_H
