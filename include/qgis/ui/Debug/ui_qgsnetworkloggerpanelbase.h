/********************************************************************************
** Form generated from reading UI file 'qgsnetworkloggerpanelbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSNETWORKLOGGERPANELBASE_H
#define UI_QGSNETWORKLOGGERPANELBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include "qgsfilterlineedit.h"
#include "qgspanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsNetworkLoggerPanelBase
{
public:
    QAction *mActionClear;
    QAction *mActionRecord;
    QAction *mActionShowSuccessful;
    QAction *mActionShowTimeouts;
    QAction *mActionSaveLog;
    QVBoxLayout *verticalLayout;
    QToolBar *mToolbar;
    QgsFilterLineEdit *mFilterLineEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QgsPanelWidget *QgsNetworkLoggerPanelBase)
    {
        if (QgsNetworkLoggerPanelBase->objectName().isEmpty())
            QgsNetworkLoggerPanelBase->setObjectName(QString::fromUtf8("QgsNetworkLoggerPanelBase"));
        QgsNetworkLoggerPanelBase->resize(700, 629);
        mActionClear = new QAction(QgsNetworkLoggerPanelBase);
        mActionClear->setObjectName(QString::fromUtf8("mActionClear"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteSelected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionClear->setIcon(icon);
        mActionRecord = new QAction(QgsNetworkLoggerPanelBase);
        mActionRecord->setObjectName(QString::fromUtf8("mActionRecord"));
        mActionRecord->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionRecord.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRecord->setIcon(icon1);
        mActionShowSuccessful = new QAction(QgsNetworkLoggerPanelBase);
        mActionShowSuccessful->setObjectName(QString::fromUtf8("mActionShowSuccessful"));
        mActionShowSuccessful->setCheckable(true);
        mActionShowTimeouts = new QAction(QgsNetworkLoggerPanelBase);
        mActionShowTimeouts->setObjectName(QString::fromUtf8("mActionShowTimeouts"));
        mActionShowTimeouts->setCheckable(true);
        mActionSaveLog = new QAction(QgsNetworkLoggerPanelBase);
        mActionSaveLog->setObjectName(QString::fromUtf8("mActionSaveLog"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionFileSave.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSaveLog->setIcon(icon2);
        verticalLayout = new QVBoxLayout(QgsNetworkLoggerPanelBase);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mToolbar = new QToolBar(QgsNetworkLoggerPanelBase);
        mToolbar->setObjectName(QString::fromUtf8("mToolbar"));
        mToolbar->setIconSize(QSize(24, 24));
        mToolbar->setFloatable(false);

        verticalLayout->addWidget(mToolbar);

        mFilterLineEdit = new QgsFilterLineEdit(QgsNetworkLoggerPanelBase);
        mFilterLineEdit->setObjectName(QString::fromUtf8("mFilterLineEdit"));

        verticalLayout->addWidget(mFilterLineEdit);

        verticalSpacer = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        mToolbar->addAction(mActionRecord);
        mToolbar->addAction(mActionClear);
        mToolbar->addAction(mActionSaveLog);
        mToolbar->addSeparator();

        retranslateUi(QgsNetworkLoggerPanelBase);

        QMetaObject::connectSlotsByName(QgsNetworkLoggerPanelBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsNetworkLoggerPanelBase)
    {
        mActionClear->setText(QApplication::translate("QgsNetworkLoggerPanelBase", "Clear", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionClear->setToolTip(QApplication::translate("QgsNetworkLoggerPanelBase", "Clear Log", nullptr));
#endif // QT_NO_TOOLTIP
        mActionRecord->setText(QApplication::translate("QgsNetworkLoggerPanelBase", "Record Log", nullptr));
        mActionShowSuccessful->setText(QApplication::translate("QgsNetworkLoggerPanelBase", "Show Successful Requests", nullptr));
        mActionShowTimeouts->setText(QApplication::translate("QgsNetworkLoggerPanelBase", "Show Timeouts", nullptr));
        mActionSaveLog->setText(QApplication::translate("QgsNetworkLoggerPanelBase", "Save Log\342\200\246", nullptr));
        Q_UNUSED(QgsNetworkLoggerPanelBase);
    } // retranslateUi

};

namespace Ui {
    class QgsNetworkLoggerPanelBase: public Ui_QgsNetworkLoggerPanelBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSNETWORKLOGGERPANELBASE_H
