/********************************************************************************
** Form generated from reading UI file 'qgsxyzconnectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSXYZCONNECTIONDIALOG_H
#define UI_QGSXYZCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "auth/qgsauthsettingswidget.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsXyzConnectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *mGroupBox;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLineEdit *mEditReferer;
    QLabel *label_2;
    QgsSpinBox *mSpinZMax;
    QLabel *label;
    QGroupBox *mAuthGroupBox;
    QVBoxLayout *verticalLayout_3;
    QgsAuthSettingsWidget *mAuthSettings;
    QLineEdit *mEditName;
    QLabel *lblReferer;
    QLineEdit *mEditUrl;
    QCheckBox *mCheckBoxZMax;
    QCheckBox *mCheckBoxZMin;
    QgsSpinBox *mSpinZMin;
    QLabel *label_3;
    QComboBox *mComboTileResolution;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsXyzConnectionDialog)
    {
        if (QgsXyzConnectionDialog->objectName().isEmpty())
            QgsXyzConnectionDialog->setObjectName(QString::fromUtf8("QgsXyzConnectionDialog"));
        QgsXyzConnectionDialog->resize(636, 331);
        verticalLayout = new QVBoxLayout(QgsXyzConnectionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mGroupBox = new QGroupBox(QgsXyzConnectionDialog);
        mGroupBox->setObjectName(QString::fromUtf8("mGroupBox"));
        gridLayout = new QGridLayout(mGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 2, 1, 1);

        mEditReferer = new QLineEdit(mGroupBox);
        mEditReferer->setObjectName(QString::fromUtf8("mEditReferer"));

        gridLayout->addWidget(mEditReferer, 9, 2, 1, 1);

        label_2 = new QLabel(mGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        mSpinZMax = new QgsSpinBox(mGroupBox);
        mSpinZMax->setObjectName(QString::fromUtf8("mSpinZMax"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mSpinZMax->sizePolicy().hasHeightForWidth());
        mSpinZMax->setSizePolicy(sizePolicy);
        mSpinZMax->setValue(18);

        gridLayout->addWidget(mSpinZMax, 8, 2, 1, 1);

        label = new QLabel(mGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        mAuthGroupBox = new QGroupBox(mGroupBox);
        mAuthGroupBox->setObjectName(QString::fromUtf8("mAuthGroupBox"));
        verticalLayout_3 = new QVBoxLayout(mAuthGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        mAuthSettings = new QgsAuthSettingsWidget(mAuthGroupBox);
        mAuthSettings->setObjectName(QString::fromUtf8("mAuthSettings"));

        verticalLayout_3->addWidget(mAuthSettings);


        gridLayout->addWidget(mAuthGroupBox, 2, 0, 2, 3);

        mEditName = new QLineEdit(mGroupBox);
        mEditName->setObjectName(QString::fromUtf8("mEditName"));

        gridLayout->addWidget(mEditName, 0, 2, 1, 1);

        lblReferer = new QLabel(mGroupBox);
        lblReferer->setObjectName(QString::fromUtf8("lblReferer"));

        gridLayout->addWidget(lblReferer, 9, 0, 1, 2);

        mEditUrl = new QLineEdit(mGroupBox);
        mEditUrl->setObjectName(QString::fromUtf8("mEditUrl"));

        gridLayout->addWidget(mEditUrl, 1, 2, 1, 1);

        mCheckBoxZMax = new QCheckBox(mGroupBox);
        mCheckBoxZMax->setObjectName(QString::fromUtf8("mCheckBoxZMax"));
        mCheckBoxZMax->setChecked(true);

        gridLayout->addWidget(mCheckBoxZMax, 8, 0, 1, 2);

        mCheckBoxZMin = new QCheckBox(mGroupBox);
        mCheckBoxZMin->setObjectName(QString::fromUtf8("mCheckBoxZMin"));
        mCheckBoxZMin->setChecked(true);

        gridLayout->addWidget(mCheckBoxZMin, 4, 0, 1, 2);

        mSpinZMin = new QgsSpinBox(mGroupBox);
        mSpinZMin->setObjectName(QString::fromUtf8("mSpinZMin"));
        sizePolicy.setHeightForWidth(mSpinZMin->sizePolicy().hasHeightForWidth());
        mSpinZMin->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mSpinZMin, 4, 2, 1, 1);

        label_3 = new QLabel(mGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 11, 0, 1, 1);

        mComboTileResolution = new QComboBox(mGroupBox);
        mComboTileResolution->addItem(QString());
        mComboTileResolution->addItem(QString());
        mComboTileResolution->addItem(QString());
        mComboTileResolution->setObjectName(QString::fromUtf8("mComboTileResolution"));

        gridLayout->addWidget(mComboTileResolution, 11, 2, 1, 1);


        verticalLayout->addWidget(mGroupBox);

        buttonBox = new QDialogButtonBox(QgsXyzConnectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        lblReferer->setBuddy(mEditReferer);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(mEditName, mEditUrl);
        QWidget::setTabOrder(mEditUrl, mCheckBoxZMin);
        QWidget::setTabOrder(mCheckBoxZMin, mSpinZMin);
        QWidget::setTabOrder(mSpinZMin, mCheckBoxZMax);
        QWidget::setTabOrder(mCheckBoxZMax, mSpinZMax);
        QWidget::setTabOrder(mSpinZMax, mEditReferer);

        retranslateUi(QgsXyzConnectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsXyzConnectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsXyzConnectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsXyzConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsXyzConnectionDialog)
    {
        QgsXyzConnectionDialog->setWindowTitle(QApplication::translate("QgsXyzConnectionDialog", "XYZ Connection", nullptr));
        mGroupBox->setTitle(QApplication::translate("QgsXyzConnectionDialog", "Connection Details", nullptr));
#ifndef QT_NO_TOOLTIP
        mEditReferer->setToolTip(QApplication::translate("QgsXyzConnectionDialog", "Optional custom referer", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("QgsXyzConnectionDialog", "URL", nullptr));
        label->setText(QApplication::translate("QgsXyzConnectionDialog", "Name", nullptr));
        mAuthGroupBox->setTitle(QApplication::translate("QgsXyzConnectionDialog", "Authentication", nullptr));
#ifndef QT_NO_TOOLTIP
        mEditName->setToolTip(QApplication::translate("QgsXyzConnectionDialog", "Name of the new connection", nullptr));
#endif // QT_NO_TOOLTIP
        lblReferer->setText(QApplication::translate("QgsXyzConnectionDialog", "Referer", nullptr));
#ifndef QT_NO_TOOLTIP
        mEditUrl->setToolTip(QApplication::translate("QgsXyzConnectionDialog", "URL of the connection, {x}, {y}, and {z} will be replaced with actual values. Use {-y} for inverted y axis.", nullptr));
#endif // QT_NO_TOOLTIP
        mEditUrl->setPlaceholderText(QApplication::translate("QgsXyzConnectionDialog", "http://example.com/{z}/{x}/{y}.png", nullptr));
        mCheckBoxZMax->setText(QApplication::translate("QgsXyzConnectionDialog", "Max. Zoom Level", nullptr));
        mCheckBoxZMin->setText(QApplication::translate("QgsXyzConnectionDialog", "Min. Zoom Level", nullptr));
        label_3->setText(QApplication::translate("QgsXyzConnectionDialog", "Tile Resolution", nullptr));
        mComboTileResolution->setItemText(0, QApplication::translate("QgsXyzConnectionDialog", "Unknown (not scaled)", nullptr));
        mComboTileResolution->setItemText(1, QApplication::translate("QgsXyzConnectionDialog", "Standard (256x256 / 96 DPI)", nullptr));
        mComboTileResolution->setItemText(2, QApplication::translate("QgsXyzConnectionDialog", "High (512x512 / 192 DPI)", nullptr));

    } // retranslateUi

};

namespace Ui {
    class QgsXyzConnectionDialog: public Ui_QgsXyzConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSXYZCONNECTIONDIALOG_H
