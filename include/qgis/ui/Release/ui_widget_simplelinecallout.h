/********************************************************************************
** Form generated from reading UI file 'widget_simplelinecallout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SIMPLELINECALLOUT_H
#define UI_WIDGET_SIMPLELINECALLOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"
#include "qgspropertyoverridebutton.h"
#include "qgssymbolbutton.h"
#include "qgsunitselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetSimpleLineCallout
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_45;
    QLabel *label;
    QLabel *mAnchorPointLbl;
    QgsUnitSelectionWidget *mOffsetFromAnchorUnitWidget;
    QgsPropertyOverrideButton *mMinCalloutLengthDDBtn;
    QLabel *label_47;
    QComboBox *mAnchorPointComboBox;
    QLabel *label_46;
    QgsSymbolButton *mCalloutLineStyleButton;
    QgsUnitSelectionWidget *mOffsetFromLabelUnitWidget;
    QgsPropertyOverrideButton *mDrawToAllPartsDDBtn;
    QgsPropertyOverrideButton *mOffsetFromLabelDDBtn;
    QgsUnitSelectionWidget *mMinCalloutWidthUnitWidget;
    QgsDoubleSpinBox *mOffsetFromAnchorSpin;
    QCheckBox *mDrawToAllPartsCheck;
    QgsPropertyOverrideButton *mOffsetFromAnchorDDBtn;
    QgsDoubleSpinBox *mMinCalloutLengthSpin;
    QgsPropertyOverrideButton *mAnchorPointDDBtn;
    QLabel *label_45;
    QgsDoubleSpinBox *mOffsetFromLabelSpin;
    QLabel *mAnchorPointLbl_2;
    QComboBox *mLabelAnchorPointComboBox;
    QgsPropertyOverrideButton *mLabelAnchorPointDDBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetSimpleLineCallout)
    {
        if (WidgetSimpleLineCallout->objectName().isEmpty())
            WidgetSimpleLineCallout->setObjectName(QString::fromUtf8("WidgetSimpleLineCallout"));
        WidgetSimpleLineCallout->resize(341, 201);
        WidgetSimpleLineCallout->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout = new QVBoxLayout(WidgetSimpleLineCallout);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_45 = new QGridLayout();
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_45->setContentsMargins(0, 0, -1, -1);
        label = new QLabel(WidgetSimpleLineCallout);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_45->addWidget(label, 0, 0, 1, 1);

        mAnchorPointLbl = new QLabel(WidgetSimpleLineCallout);
        mAnchorPointLbl->setObjectName(QString::fromUtf8("mAnchorPointLbl"));

        gridLayout_45->addWidget(mAnchorPointLbl, 5, 0, 1, 1);

        mOffsetFromAnchorUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLineCallout);
        mOffsetFromAnchorUnitWidget->setObjectName(QString::fromUtf8("mOffsetFromAnchorUnitWidget"));
        mOffsetFromAnchorUnitWidget->setMinimumSize(QSize(10, 0));
        mOffsetFromAnchorUnitWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout_45->addWidget(mOffsetFromAnchorUnitWidget, 2, 2, 1, 1);

        mMinCalloutLengthDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mMinCalloutLengthDDBtn->setObjectName(QString::fromUtf8("mMinCalloutLengthDDBtn"));

        gridLayout_45->addWidget(mMinCalloutLengthDDBtn, 1, 3, 1, 1);

        label_47 = new QLabel(WidgetSimpleLineCallout);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_45->addWidget(label_47, 3, 0, 1, 1);

        mAnchorPointComboBox = new QComboBox(WidgetSimpleLineCallout);
        mAnchorPointComboBox->setObjectName(QString::fromUtf8("mAnchorPointComboBox"));

        gridLayout_45->addWidget(mAnchorPointComboBox, 5, 1, 1, 2);

        label_46 = new QLabel(WidgetSimpleLineCallout);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_45->addWidget(label_46, 2, 0, 1, 1);

        mCalloutLineStyleButton = new QgsSymbolButton(WidgetSimpleLineCallout);
        mCalloutLineStyleButton->setObjectName(QString::fromUtf8("mCalloutLineStyleButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mCalloutLineStyleButton->sizePolicy().hasHeightForWidth());
        mCalloutLineStyleButton->setSizePolicy(sizePolicy);

        gridLayout_45->addWidget(mCalloutLineStyleButton, 0, 1, 1, 2);

        mOffsetFromLabelUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLineCallout);
        mOffsetFromLabelUnitWidget->setObjectName(QString::fromUtf8("mOffsetFromLabelUnitWidget"));
        mOffsetFromLabelUnitWidget->setMinimumSize(QSize(10, 0));
        mOffsetFromLabelUnitWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout_45->addWidget(mOffsetFromLabelUnitWidget, 3, 2, 1, 1);

        mDrawToAllPartsDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mDrawToAllPartsDDBtn->setObjectName(QString::fromUtf8("mDrawToAllPartsDDBtn"));

        gridLayout_45->addWidget(mDrawToAllPartsDDBtn, 4, 3, 1, 1);

        mOffsetFromLabelDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mOffsetFromLabelDDBtn->setObjectName(QString::fromUtf8("mOffsetFromLabelDDBtn"));

        gridLayout_45->addWidget(mOffsetFromLabelDDBtn, 3, 3, 1, 1);

        mMinCalloutWidthUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLineCallout);
        mMinCalloutWidthUnitWidget->setObjectName(QString::fromUtf8("mMinCalloutWidthUnitWidget"));
        mMinCalloutWidthUnitWidget->setMinimumSize(QSize(10, 0));
        mMinCalloutWidthUnitWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout_45->addWidget(mMinCalloutWidthUnitWidget, 1, 2, 1, 1);

        mOffsetFromAnchorSpin = new QgsDoubleSpinBox(WidgetSimpleLineCallout);
        mOffsetFromAnchorSpin->setObjectName(QString::fromUtf8("mOffsetFromAnchorSpin"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mOffsetFromAnchorSpin->sizePolicy().hasHeightForWidth());
        mOffsetFromAnchorSpin->setSizePolicy(sizePolicy1);
        mOffsetFromAnchorSpin->setDecimals(6);
        mOffsetFromAnchorSpin->setMaximum(100000.000000000000000);
        mOffsetFromAnchorSpin->setSingleStep(0.200000000000000);
        mOffsetFromAnchorSpin->setValue(0.000000000000000);
        mOffsetFromAnchorSpin->setProperty("showClearButton", QVariant(true));

        gridLayout_45->addWidget(mOffsetFromAnchorSpin, 2, 1, 1, 1);

        mDrawToAllPartsCheck = new QCheckBox(WidgetSimpleLineCallout);
        mDrawToAllPartsCheck->setObjectName(QString::fromUtf8("mDrawToAllPartsCheck"));

        gridLayout_45->addWidget(mDrawToAllPartsCheck, 4, 0, 1, 3);

        mOffsetFromAnchorDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mOffsetFromAnchorDDBtn->setObjectName(QString::fromUtf8("mOffsetFromAnchorDDBtn"));

        gridLayout_45->addWidget(mOffsetFromAnchorDDBtn, 2, 3, 1, 1);

        mMinCalloutLengthSpin = new QgsDoubleSpinBox(WidgetSimpleLineCallout);
        mMinCalloutLengthSpin->setObjectName(QString::fromUtf8("mMinCalloutLengthSpin"));
        sizePolicy1.setHeightForWidth(mMinCalloutLengthSpin->sizePolicy().hasHeightForWidth());
        mMinCalloutLengthSpin->setSizePolicy(sizePolicy1);
        mMinCalloutLengthSpin->setDecimals(6);
        mMinCalloutLengthSpin->setMaximum(100000.000000000000000);
        mMinCalloutLengthSpin->setSingleStep(0.200000000000000);
        mMinCalloutLengthSpin->setValue(1.000000000000000);
        mMinCalloutLengthSpin->setProperty("showClearButton", QVariant(true));

        gridLayout_45->addWidget(mMinCalloutLengthSpin, 1, 1, 1, 1);

        mAnchorPointDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mAnchorPointDDBtn->setObjectName(QString::fromUtf8("mAnchorPointDDBtn"));

        gridLayout_45->addWidget(mAnchorPointDDBtn, 5, 3, 1, 1);

        label_45 = new QLabel(WidgetSimpleLineCallout);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_45->addWidget(label_45, 1, 0, 1, 1);

        mOffsetFromLabelSpin = new QgsDoubleSpinBox(WidgetSimpleLineCallout);
        mOffsetFromLabelSpin->setObjectName(QString::fromUtf8("mOffsetFromLabelSpin"));
        sizePolicy1.setHeightForWidth(mOffsetFromLabelSpin->sizePolicy().hasHeightForWidth());
        mOffsetFromLabelSpin->setSizePolicy(sizePolicy1);
        mOffsetFromLabelSpin->setDecimals(6);
        mOffsetFromLabelSpin->setMaximum(100000.000000000000000);
        mOffsetFromLabelSpin->setSingleStep(0.200000000000000);
        mOffsetFromLabelSpin->setValue(0.000000000000000);
        mOffsetFromLabelSpin->setProperty("showClearButton", QVariant(true));

        gridLayout_45->addWidget(mOffsetFromLabelSpin, 3, 1, 1, 1);

        mAnchorPointLbl_2 = new QLabel(WidgetSimpleLineCallout);
        mAnchorPointLbl_2->setObjectName(QString::fromUtf8("mAnchorPointLbl_2"));

        gridLayout_45->addWidget(mAnchorPointLbl_2, 6, 0, 1, 1);

        mLabelAnchorPointComboBox = new QComboBox(WidgetSimpleLineCallout);
        mLabelAnchorPointComboBox->setObjectName(QString::fromUtf8("mLabelAnchorPointComboBox"));

        gridLayout_45->addWidget(mLabelAnchorPointComboBox, 6, 1, 1, 2);

        mLabelAnchorPointDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLineCallout);
        mLabelAnchorPointDDBtn->setObjectName(QString::fromUtf8("mLabelAnchorPointDDBtn"));

        gridLayout_45->addWidget(mLabelAnchorPointDDBtn, 6, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_45);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(mCalloutLineStyleButton, mMinCalloutLengthSpin);
        QWidget::setTabOrder(mMinCalloutLengthSpin, mMinCalloutWidthUnitWidget);
        QWidget::setTabOrder(mMinCalloutWidthUnitWidget, mMinCalloutLengthDDBtn);
        QWidget::setTabOrder(mMinCalloutLengthDDBtn, mOffsetFromAnchorSpin);
        QWidget::setTabOrder(mOffsetFromAnchorSpin, mOffsetFromAnchorUnitWidget);
        QWidget::setTabOrder(mOffsetFromAnchorUnitWidget, mOffsetFromAnchorDDBtn);
        QWidget::setTabOrder(mOffsetFromAnchorDDBtn, mOffsetFromLabelSpin);
        QWidget::setTabOrder(mOffsetFromLabelSpin, mOffsetFromLabelUnitWidget);
        QWidget::setTabOrder(mOffsetFromLabelUnitWidget, mOffsetFromLabelDDBtn);
        QWidget::setTabOrder(mOffsetFromLabelDDBtn, mDrawToAllPartsCheck);
        QWidget::setTabOrder(mDrawToAllPartsCheck, mDrawToAllPartsDDBtn);
        QWidget::setTabOrder(mDrawToAllPartsDDBtn, mAnchorPointComboBox);
        QWidget::setTabOrder(mAnchorPointComboBox, mAnchorPointDDBtn);
        QWidget::setTabOrder(mAnchorPointDDBtn, mLabelAnchorPointComboBox);
        QWidget::setTabOrder(mLabelAnchorPointComboBox, mLabelAnchorPointDDBtn);

        retranslateUi(WidgetSimpleLineCallout);

        QMetaObject::connectSlotsByName(WidgetSimpleLineCallout);
    } // setupUi

    void retranslateUi(QWidget *WidgetSimpleLineCallout)
    {
        label->setText(QApplication::translate("WidgetSimpleLineCallout", "Line style", nullptr));
        mAnchorPointLbl->setText(QApplication::translate("WidgetSimpleLineCallout", "Anchor point", nullptr));
        mMinCalloutLengthDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        label_47->setText(QApplication::translate("WidgetSimpleLineCallout", "Offset from label area", nullptr));
        label_46->setText(QApplication::translate("WidgetSimpleLineCallout", "Offset from feature", nullptr));
        mCalloutLineStyleButton->setText(QApplication::translate("WidgetSimpleLineCallout", "Symbol\342\200\246", nullptr));
        mDrawToAllPartsDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        mOffsetFromLabelDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        mDrawToAllPartsCheck->setText(QApplication::translate("WidgetSimpleLineCallout", "Draw lines to all feature parts", nullptr));
        mOffsetFromAnchorDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        mAnchorPointDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        label_45->setText(QApplication::translate("WidgetSimpleLineCallout", "Minimum length", nullptr));
        mAnchorPointLbl_2->setText(QApplication::translate("WidgetSimpleLineCallout", "Label anchor point", nullptr));
        mLabelAnchorPointDDBtn->setText(QApplication::translate("WidgetSimpleLineCallout", "\342\200\246", nullptr));
        Q_UNUSED(WidgetSimpleLineCallout);
    } // retranslateUi

};

namespace Ui {
    class WidgetSimpleLineCallout: public Ui_WidgetSimpleLineCallout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SIMPLELINECALLOUT_H
