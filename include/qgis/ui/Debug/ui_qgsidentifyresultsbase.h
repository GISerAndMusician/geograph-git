/********************************************************************************
** Form generated from reading UI file 'qgsidentifyresultsbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSIDENTIFYRESULTSBASE_H
#define UI_QGSIDENTIFYRESULTSBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_QgsIdentifyResultsBase
{
public:
    QAction *mExpandAction;
    QAction *mCollapseAction;
    QAction *mExpandNewAction;
    QAction *mOpenFormAction;
    QAction *mClearResultsAction;
    QAction *mActionCopy;
    QAction *mActionPrint;
    QAction *mActionSelectFeatures;
    QAction *mActionSelectPolygon;
    QAction *mActionSelectFreehand;
    QAction *mActionSelectRadius;
    QAction *mActionAutoFeatureForm;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *verticalLayout;
    QToolBar *mIdentifyToolbar;
    QTreeWidget *lstResults;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblIdentifyMode;
    QComboBox *cmbIdentifyMode;
    QWidget *stackedWidgetPage2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tblResults;
    QWidget *stackedWidgetPage3;
    QVBoxLayout *verticalLayout_3;
    QwtPlot *mPlot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblViewMode;
    QComboBox *cmbViewMode;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *mHelpToolButton;

    void setupUi(QDialog *QgsIdentifyResultsBase)
    {
        if (QgsIdentifyResultsBase->objectName().isEmpty())
            QgsIdentifyResultsBase->setObjectName(QString::fromUtf8("QgsIdentifyResultsBase"));
        QgsIdentifyResultsBase->resize(465, 490);
        mExpandAction = new QAction(QgsIdentifyResultsBase);
        mExpandAction->setObjectName(QString::fromUtf8("mExpandAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionExpandTree.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mExpandAction->setIcon(icon);
        mCollapseAction = new QAction(QgsIdentifyResultsBase);
        mCollapseAction->setObjectName(QString::fromUtf8("mCollapseAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionCollapseTree.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mCollapseAction->setIcon(icon1);
        mExpandNewAction = new QAction(QgsIdentifyResultsBase);
        mExpandNewAction->setObjectName(QString::fromUtf8("mExpandNewAction"));
        mExpandNewAction->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionExpandNewTree.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mExpandNewAction->setIcon(icon2);
        mOpenFormAction = new QAction(QgsIdentifyResultsBase);
        mOpenFormAction->setObjectName(QString::fromUtf8("mOpenFormAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionFormView.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mOpenFormAction->setIcon(icon3);
        mClearResultsAction = new QAction(QgsIdentifyResultsBase);
        mClearResultsAction->setObjectName(QString::fromUtf8("mClearResultsAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionDeselectAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mClearResultsAction->setIcon(icon4);
        mActionCopy = new QAction(QgsIdentifyResultsBase);
        mActionCopy->setObjectName(QString::fromUtf8("mActionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionCopy->setIcon(icon5);
        mActionPrint = new QAction(QgsIdentifyResultsBase);
        mActionPrint->setObjectName(QString::fromUtf8("mActionPrint"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/mActionFilePrint.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPrint->setIcon(icon6);
        mActionSelectFeatures = new QAction(QgsIdentifyResultsBase);
        mActionSelectFeatures->setObjectName(QString::fromUtf8("mActionSelectFeatures"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/mActionIdentifyByRectangle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFeatures->setIcon(icon7);
        mActionSelectPolygon = new QAction(QgsIdentifyResultsBase);
        mActionSelectPolygon->setObjectName(QString::fromUtf8("mActionSelectPolygon"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/mActionIdentifyByPolygon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectPolygon->setIcon(icon8);
        mActionSelectFreehand = new QAction(QgsIdentifyResultsBase);
        mActionSelectFreehand->setObjectName(QString::fromUtf8("mActionSelectFreehand"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/themes/default/mActionIdentifyByFreehand.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectFreehand->setIcon(icon9);
        mActionSelectRadius = new QAction(QgsIdentifyResultsBase);
        mActionSelectRadius->setObjectName(QString::fromUtf8("mActionSelectRadius"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/themes/default/mActionIdentifyByRadius.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectRadius->setIcon(icon10);
        mActionAutoFeatureForm = new QAction(QgsIdentifyResultsBase);
        mActionAutoFeatureForm->setObjectName(QString::fromUtf8("mActionAutoFeatureForm"));
        mActionAutoFeatureForm->setCheckable(true);
        verticalLayout_4 = new QVBoxLayout(QgsIdentifyResultsBase);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(QgsIdentifyResultsBase);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QString::fromUtf8("stackedWidgetPage1"));
        verticalLayout = new QVBoxLayout(stackedWidgetPage1);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mIdentifyToolbar = new QToolBar(stackedWidgetPage1);
        mIdentifyToolbar->setObjectName(QString::fromUtf8("mIdentifyToolbar"));
        mIdentifyToolbar->setIconSize(QSize(16, 16));
        mIdentifyToolbar->setFloatable(false);

        verticalLayout->addWidget(mIdentifyToolbar);

        lstResults = new QTreeWidget(stackedWidgetPage1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        lstResults->setHeaderItem(__qtreewidgetitem);
        lstResults->setObjectName(QString::fromUtf8("lstResults"));
        lstResults->setLineWidth(2);
        lstResults->setAlternatingRowColors(true);
        lstResults->setSortingEnabled(true);

        verticalLayout->addWidget(lstResults);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, -1);
        lblIdentifyMode = new QLabel(stackedWidgetPage1);
        lblIdentifyMode->setObjectName(QString::fromUtf8("lblIdentifyMode"));

        horizontalLayout_2->addWidget(lblIdentifyMode);

        cmbIdentifyMode = new QComboBox(stackedWidgetPage1);
        cmbIdentifyMode->setObjectName(QString::fromUtf8("cmbIdentifyMode"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbIdentifyMode->sizePolicy().hasHeightForWidth());
        cmbIdentifyMode->setSizePolicy(sizePolicy);
        cmbIdentifyMode->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        cmbIdentifyMode->setMinimumContentsLength(6);

        horizontalLayout_2->addWidget(cmbIdentifyMode);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QString::fromUtf8("stackedWidgetPage2"));
        verticalLayout_2 = new QVBoxLayout(stackedWidgetPage2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tblResults = new QTableWidget(stackedWidgetPage2);
        if (tblResults->columnCount() < 4)
            tblResults->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblResults->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblResults->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblResults->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblResults->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblResults->setObjectName(QString::fromUtf8("tblResults"));
        tblResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblResults->setSortingEnabled(false);

        verticalLayout_2->addWidget(tblResults);

        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QString::fromUtf8("stackedWidgetPage3"));
        verticalLayout_3 = new QVBoxLayout(stackedWidgetPage3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mPlot = new QwtPlot(stackedWidgetPage3);
        mPlot->setObjectName(QString::fromUtf8("mPlot"));

        verticalLayout_3->addWidget(mPlot);

        stackedWidget->addWidget(stackedWidgetPage3);

        verticalLayout_4->addWidget(stackedWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, -1, 5, -1);
        lblViewMode = new QLabel(QgsIdentifyResultsBase);
        lblViewMode->setObjectName(QString::fromUtf8("lblViewMode"));

        horizontalLayout_3->addWidget(lblViewMode);

        cmbViewMode = new QComboBox(QgsIdentifyResultsBase);
        cmbViewMode->setObjectName(QString::fromUtf8("cmbViewMode"));

        horizontalLayout_3->addWidget(cmbViewMode);

        horizontalSpacer_2 = new QSpacerItem(58, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        mHelpToolButton = new QToolButton(QgsIdentifyResultsBase);
        mHelpToolButton->setObjectName(QString::fromUtf8("mHelpToolButton"));
        mHelpToolButton->setEnabled(true);
        mHelpToolButton->setCheckable(false);

        horizontalLayout_3->addWidget(mHelpToolButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        mIdentifyToolbar->addAction(mOpenFormAction);
        mIdentifyToolbar->addSeparator();
        mIdentifyToolbar->addAction(mExpandAction);
        mIdentifyToolbar->addAction(mCollapseAction);
        mIdentifyToolbar->addAction(mExpandNewAction);
        mIdentifyToolbar->addSeparator();
        mIdentifyToolbar->addAction(mClearResultsAction);
        mIdentifyToolbar->addSeparator();
        mIdentifyToolbar->addAction(mActionCopy);
        mIdentifyToolbar->addAction(mActionPrint);
        mIdentifyToolbar->addSeparator();

        retranslateUi(QgsIdentifyResultsBase);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsIdentifyResultsBase);
    } // setupUi

    void retranslateUi(QDialog *QgsIdentifyResultsBase)
    {
        QgsIdentifyResultsBase->setWindowTitle(QApplication::translate("QgsIdentifyResultsBase", "Identify Results", nullptr));
        mExpandAction->setText(QApplication::translate("QgsIdentifyResultsBase", "Expand Tree", nullptr));
        mCollapseAction->setText(QApplication::translate("QgsIdentifyResultsBase", "Collapse Tree", nullptr));
#ifndef QT_NO_TOOLTIP
        mCollapseAction->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Collapse Tree", nullptr));
#endif // QT_NO_TOOLTIP
        mExpandNewAction->setText(QApplication::translate("QgsIdentifyResultsBase", "Expand New Results", nullptr));
#ifndef QT_NO_TOOLTIP
        mExpandNewAction->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Expand New Results by Default", nullptr));
#endif // QT_NO_TOOLTIP
        mOpenFormAction->setText(QApplication::translate("QgsIdentifyResultsBase", "Open Form", nullptr));
#ifndef QT_NO_TOOLTIP
        mOpenFormAction->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Open Form", nullptr));
#endif // QT_NO_TOOLTIP
        mClearResultsAction->setText(QApplication::translate("QgsIdentifyResultsBase", "Clear Results", nullptr));
#ifndef QT_NO_TOOLTIP
        mClearResultsAction->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Clear Results", nullptr));
#endif // QT_NO_TOOLTIP
        mActionCopy->setText(QApplication::translate("QgsIdentifyResultsBase", "Copy Feature", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionCopy->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Copy the Identified Feature to Clipboard", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPrint->setText(QApplication::translate("QgsIdentifyResultsBase", "Print Response", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPrint->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Print Selected HTML Response", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSelectFeatures->setText(QApplication::translate("QgsIdentifyResultsBase", "Identify Feature(s)", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectFeatures->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Identify Features by area or single click", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSelectPolygon->setText(QApplication::translate("QgsIdentifyResultsBase", "Identify Features by Polygon", nullptr));
        mActionSelectFreehand->setText(QApplication::translate("QgsIdentifyResultsBase", "Identify Features by Freehand", nullptr));
        mActionSelectRadius->setText(QApplication::translate("QgsIdentifyResultsBase", "Identify Features by Radius", nullptr));
        mActionAutoFeatureForm->setText(QApplication::translate("QgsIdentifyResultsBase", "Auto open form for single feature results", nullptr));
#ifndef QT_NO_TOOLTIP
        lblIdentifyMode->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Select identify mode", nullptr));
#endif // QT_NO_TOOLTIP
        lblIdentifyMode->setText(QApplication::translate("QgsIdentifyResultsBase", "Mode", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblResults->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QgsIdentifyResultsBase", "Layer", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblResults->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QgsIdentifyResultsBase", "FID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblResults->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("QgsIdentifyResultsBase", "Attribute", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblResults->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("QgsIdentifyResultsBase", "Value", nullptr));
#ifndef QT_NO_TOOLTIP
        lblViewMode->setToolTip(QApplication::translate("QgsIdentifyResultsBase", "Select view mode for raster layers", nullptr));
#endif // QT_NO_TOOLTIP
        lblViewMode->setText(QApplication::translate("QgsIdentifyResultsBase", "View", nullptr));
        mHelpToolButton->setText(QApplication::translate("QgsIdentifyResultsBase", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsIdentifyResultsBase: public Ui_QgsIdentifyResultsBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSIDENTIFYRESULTSBASE_H
