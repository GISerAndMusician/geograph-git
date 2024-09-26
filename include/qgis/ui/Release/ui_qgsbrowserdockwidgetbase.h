/********************************************************************************
** Form generated from reading UI file 'qgsbrowserdockwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSBROWSERDOCKWIDGETBASE_H
#define UI_QGSBROWSERDOCKWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsdockwidget.h"
#include "qgsfilterlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsBrowserDockWidgetBase
{
public:
    QAction *mActionAddLayers;
    QAction *mActionRefresh;
    QAction *mActionShowFilter;
    QAction *mActionCollapse;
    QAction *mActionPropertiesWidget;
    QWidget *mContents;
    QVBoxLayout *verticalLayout;
    QToolBar *mBrowserToolbar;
    QWidget *mWidgetFilter;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *mBtnFilterOptions;
    QgsFilterLineEdit *mLeFilter;
    QSplitter *mSplitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *mLayoutBrowser;
    QWidget *mPropertiesWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *mPropertiesLayout;

    void setupUi(QgsDockWidget *QgsBrowserDockWidgetBase)
    {
        if (QgsBrowserDockWidgetBase->objectName().isEmpty())
            QgsBrowserDockWidgetBase->setObjectName(QString::fromUtf8("QgsBrowserDockWidgetBase"));
        QgsBrowserDockWidgetBase->resize(216, 138);
        mActionAddLayers = new QAction(QgsBrowserDockWidgetBase);
        mActionAddLayers->setObjectName(QString::fromUtf8("mActionAddLayers"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionAddLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAddLayers->setIcon(icon);
        mActionRefresh = new QAction(QgsBrowserDockWidgetBase);
        mActionRefresh->setObjectName(QString::fromUtf8("mActionRefresh"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRefresh->setIcon(icon1);
        mActionShowFilter = new QAction(QgsBrowserDockWidgetBase);
        mActionShowFilter->setObjectName(QString::fromUtf8("mActionShowFilter"));
        mActionShowFilter->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionFilter2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionShowFilter->setIcon(icon2);
        mActionCollapse = new QAction(QgsBrowserDockWidgetBase);
        mActionCollapse->setObjectName(QString::fromUtf8("mActionCollapse"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionCollapseTree.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionCollapse->setIcon(icon3);
        mActionPropertiesWidget = new QAction(QgsBrowserDockWidgetBase);
        mActionPropertiesWidget->setObjectName(QString::fromUtf8("mActionPropertiesWidget"));
        mActionPropertiesWidget->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionPropertiesWidget.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPropertiesWidget->setIcon(icon4);
        mContents = new QWidget();
        mContents->setObjectName(QString::fromUtf8("mContents"));
        verticalLayout = new QVBoxLayout(mContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mBrowserToolbar = new QToolBar(mContents);
        mBrowserToolbar->setObjectName(QString::fromUtf8("mBrowserToolbar"));
        mBrowserToolbar->setIconSize(QSize(16, 16));
        mBrowserToolbar->setFloatable(false);

        verticalLayout->addWidget(mBrowserToolbar);

        mWidgetFilter = new QWidget(mContents);
        mWidgetFilter->setObjectName(QString::fromUtf8("mWidgetFilter"));
        horizontalLayout = new QHBoxLayout(mWidgetFilter);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(mWidgetFilter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 0, 2, 0);
        mBtnFilterOptions = new QToolButton(frame);
        mBtnFilterOptions->setObjectName(QString::fromUtf8("mBtnFilterOptions"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionOptions.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mBtnFilterOptions->setIcon(icon5);
        mBtnFilterOptions->setPopupMode(QToolButton::InstantPopup);
        mBtnFilterOptions->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mBtnFilterOptions->setAutoRaise(true);

        horizontalLayout_3->addWidget(mBtnFilterOptions);

        mLeFilter = new QgsFilterLineEdit(frame);
        mLeFilter->setObjectName(QString::fromUtf8("mLeFilter"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mLeFilter->sizePolicy().hasHeightForWidth());
        mLeFilter->setSizePolicy(sizePolicy1);
        mLeFilter->setMinimumSize(QSize(0, 0));
        mLeFilter->setBaseSize(QSize(0, 0));

        horizontalLayout_3->addWidget(mLeFilter);


        horizontalLayout->addWidget(frame);


        verticalLayout->addWidget(mWidgetFilter);

        mSplitter = new QSplitter(mContents);
        mSplitter->setObjectName(QString::fromUtf8("mSplitter"));
        mSplitter->setOrientation(Qt::Vertical);
        verticalLayoutWidget = new QWidget(mSplitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        mLayoutBrowser = new QVBoxLayout(verticalLayoutWidget);
        mLayoutBrowser->setObjectName(QString::fromUtf8("mLayoutBrowser"));
        mLayoutBrowser->setContentsMargins(0, 0, 0, 0);
        mSplitter->addWidget(verticalLayoutWidget);
        mPropertiesWidget = new QWidget(mSplitter);
        mPropertiesWidget->setObjectName(QString::fromUtf8("mPropertiesWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mPropertiesWidget->sizePolicy().hasHeightForWidth());
        mPropertiesWidget->setSizePolicy(sizePolicy2);
        mPropertiesWidget->setMinimumSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(mPropertiesWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mPropertiesLayout = new QVBoxLayout();
        mPropertiesLayout->setObjectName(QString::fromUtf8("mPropertiesLayout"));

        verticalLayout_3->addLayout(mPropertiesLayout);

        mSplitter->addWidget(mPropertiesWidget);

        verticalLayout->addWidget(mSplitter);

        QgsBrowserDockWidgetBase->setWidget(mContents);

        mBrowserToolbar->addAction(mActionAddLayers);
        mBrowserToolbar->addAction(mActionRefresh);
        mBrowserToolbar->addAction(mActionShowFilter);
        mBrowserToolbar->addAction(mActionCollapse);
        mBrowserToolbar->addAction(mActionPropertiesWidget);

        retranslateUi(QgsBrowserDockWidgetBase);

        QMetaObject::connectSlotsByName(QgsBrowserDockWidgetBase);
    } // setupUi

    void retranslateUi(QgsDockWidget *QgsBrowserDockWidgetBase)
    {
        QgsBrowserDockWidgetBase->setWindowTitle(QApplication::translate("QgsBrowserDockWidgetBase", "Browser", nullptr));
        mActionAddLayers->setText(QApplication::translate("QgsBrowserDockWidgetBase", "Add Layers", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAddLayers->setToolTip(QApplication::translate("QgsBrowserDockWidgetBase", "Add Selected Layers", nullptr));
#endif // QT_NO_TOOLTIP
        mActionRefresh->setText(QApplication::translate("QgsBrowserDockWidgetBase", "Refresh", nullptr));
        mActionShowFilter->setText(QApplication::translate("QgsBrowserDockWidgetBase", "Filter Browser", nullptr));
        mActionShowFilter->setIconText(QApplication::translate("QgsBrowserDockWidgetBase", "Filter Browser", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionShowFilter->setToolTip(QApplication::translate("QgsBrowserDockWidgetBase", "Filter Browser", nullptr));
#endif // QT_NO_TOOLTIP
        mActionCollapse->setText(QApplication::translate("QgsBrowserDockWidgetBase", "Collapse All", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionCollapse->setToolTip(QApplication::translate("QgsBrowserDockWidgetBase", "Collapse All", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPropertiesWidget->setText(QApplication::translate("QgsBrowserDockWidgetBase", "Show Properties", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPropertiesWidget->setToolTip(QApplication::translate("QgsBrowserDockWidgetBase", "Enable/disable properties widget", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        mBtnFilterOptions->setToolTip(QApplication::translate("QgsBrowserDockWidgetBase", "Options", nullptr));
#endif // QT_NO_TOOLTIP
        mBtnFilterOptions->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QgsBrowserDockWidgetBase: public Ui_QgsBrowserDockWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSBROWSERDOCKWIDGETBASE_H
