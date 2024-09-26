/********************************************************************************
** Form generated from reading UI file 'widget_simpleline.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SIMPLELINE_H
#define UI_WIDGET_SIMPLELINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"
#include "qgspenstylecombobox.h"
#include "qgspropertyoverridebutton.h"
#include "qgsunitselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetSimpleLine
{
public:
    QGridLayout *gridLayout;
    QLabel *label_7;
    QgsPenCapStyleComboBox *cboCapStyle;
    QgsPropertyOverrideButton *mPenStyleDDBtn;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *mChangePatternButton;
    QgsUnitSelectionWidget *mDashPatternUnitWidget;
    QSpacerItem *verticalSpacer;
    QgsPropertyOverrideButton *mCapStyleDDBtn;
    QgsColorButton *btnChangeColor;
    QgsPropertyOverrideButton *mColorDDBtn;
    QgsPropertyOverrideButton *mOffsetDDBtn;
    QLabel *mRingsLabel;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QgsDoubleSpinBox *spinPatternOffset;
    QgsUnitSelectionWidget *mPatternOffsetUnitWidget;
    QgsPropertyOverrideButton *mPenWidthDDBtn;
    QgsPropertyOverrideButton *mJoinStyleDDBtn;
    QgsPenJoinStyleComboBox *cboJoinStyle;
    QHBoxLayout *horizontalLayout_3;
    QgsDoubleSpinBox *spinOffset;
    QgsUnitSelectionWidget *mOffsetUnitWidget;
    QgsPenStyleComboBox *cboPenStyle;
    QComboBox *mRingFilterComboBox;
    QHBoxLayout *horizontalLayout_2;
    QgsDoubleSpinBox *spinWidth;
    QgsUnitSelectionWidget *mPenWidthUnitWidget;
    QgsPropertyOverrideButton *mPatternOffsetDDBtn;
    QCheckBox *mCheckAlignDash;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label;
    QCheckBox *mCustomCheckBox;
    QLabel *label_4;
    QCheckBox *mDrawInsideCheckBox;
    QLabel *label_3;
    QgsPropertyOverrideButton *mDashPatternDDBtn;
    QCheckBox *mCheckDashCorners;

    void setupUi(QWidget *WidgetSimpleLine)
    {
        if (WidgetSimpleLine->objectName().isEmpty())
            WidgetSimpleLine->setObjectName(QString::fromUtf8("WidgetSimpleLine"));
        WidgetSimpleLine->resize(325, 449);
        WidgetSimpleLine->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(WidgetSimpleLine);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(WidgetSimpleLine);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 1);

        cboCapStyle = new QgsPenCapStyleComboBox(WidgetSimpleLine);
        cboCapStyle->setObjectName(QString::fromUtf8("cboCapStyle"));

        gridLayout->addWidget(cboCapStyle, 5, 2, 1, 1);

        mPenStyleDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mPenStyleDDBtn->setObjectName(QString::fromUtf8("mPenStyleDDBtn"));

        gridLayout->addWidget(mPenStyleDDBtn, 3, 3, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer = new QSpacerItem(20, 1, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        mChangePatternButton = new QPushButton(WidgetSimpleLine);
        mChangePatternButton->setObjectName(QString::fromUtf8("mChangePatternButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mChangePatternButton->sizePolicy().hasHeightForWidth());
        mChangePatternButton->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(mChangePatternButton);

        mDashPatternUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLine);
        mDashPatternUnitWidget->setObjectName(QString::fromUtf8("mDashPatternUnitWidget"));
        mDashPatternUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_12->addWidget(mDashPatternUnitWidget);


        gridLayout->addLayout(horizontalLayout_12, 7, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 15, 0, 1, 1);

        mCapStyleDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mCapStyleDDBtn->setObjectName(QString::fromUtf8("mCapStyleDDBtn"));

        gridLayout->addWidget(mCapStyleDDBtn, 5, 3, 1, 1);

        btnChangeColor = new QgsColorButton(WidgetSimpleLine);
        btnChangeColor->setObjectName(QString::fromUtf8("btnChangeColor"));
        sizePolicy.setHeightForWidth(btnChangeColor->sizePolicy().hasHeightForWidth());
        btnChangeColor->setSizePolicy(sizePolicy);
        btnChangeColor->setMinimumSize(QSize(120, 0));
        btnChangeColor->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnChangeColor, 0, 2, 1, 1);

        mColorDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mColorDDBtn->setObjectName(QString::fromUtf8("mColorDDBtn"));

        gridLayout->addWidget(mColorDDBtn, 0, 3, 1, 1);

        mOffsetDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mOffsetDDBtn->setObjectName(QString::fromUtf8("mOffsetDDBtn"));

        gridLayout->addWidget(mOffsetDDBtn, 2, 3, 1, 1);

        mRingsLabel = new QLabel(WidgetSimpleLine);
        mRingsLabel->setObjectName(QString::fromUtf8("mRingsLabel"));

        gridLayout->addWidget(mRingsLabel, 14, 0, 1, 1);

        label_2 = new QLabel(WidgetSimpleLine);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinPatternOffset = new QgsDoubleSpinBox(WidgetSimpleLine);
        spinPatternOffset->setObjectName(QString::fromUtf8("spinPatternOffset"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinPatternOffset->sizePolicy().hasHeightForWidth());
        spinPatternOffset->setSizePolicy(sizePolicy1);
        spinPatternOffset->setStyleSheet(QString::fromUtf8(""));
        spinPatternOffset->setDecimals(6);
        spinPatternOffset->setMinimum(-100000.000000000000000);
        spinPatternOffset->setMaximum(100000.000000000000000);
        spinPatternOffset->setSingleStep(0.200000000000000);

        horizontalLayout_4->addWidget(spinPatternOffset);

        mPatternOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLine);
        mPatternOffsetUnitWidget->setObjectName(QString::fromUtf8("mPatternOffsetUnitWidget"));
        mPatternOffsetUnitWidget->setMinimumSize(QSize(0, 0));
        mPatternOffsetUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_4->addWidget(mPatternOffsetUnitWidget);


        gridLayout->addLayout(horizontalLayout_4, 10, 2, 1, 1);

        mPenWidthDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mPenWidthDDBtn->setObjectName(QString::fromUtf8("mPenWidthDDBtn"));

        gridLayout->addWidget(mPenWidthDDBtn, 1, 3, 1, 1);

        mJoinStyleDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mJoinStyleDDBtn->setObjectName(QString::fromUtf8("mJoinStyleDDBtn"));

        gridLayout->addWidget(mJoinStyleDDBtn, 4, 3, 1, 1);

        cboJoinStyle = new QgsPenJoinStyleComboBox(WidgetSimpleLine);
        cboJoinStyle->setObjectName(QString::fromUtf8("cboJoinStyle"));

        gridLayout->addWidget(cboJoinStyle, 4, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spinOffset = new QgsDoubleSpinBox(WidgetSimpleLine);
        spinOffset->setObjectName(QString::fromUtf8("spinOffset"));
        sizePolicy1.setHeightForWidth(spinOffset->sizePolicy().hasHeightForWidth());
        spinOffset->setSizePolicy(sizePolicy1);
        spinOffset->setStyleSheet(QString::fromUtf8(""));
        spinOffset->setDecimals(6);
        spinOffset->setMinimum(-100000.000000000000000);
        spinOffset->setMaximum(100000.000000000000000);
        spinOffset->setSingleStep(0.200000000000000);

        horizontalLayout_3->addWidget(spinOffset);

        mOffsetUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLine);
        mOffsetUnitWidget->setObjectName(QString::fromUtf8("mOffsetUnitWidget"));
        mOffsetUnitWidget->setMinimumSize(QSize(0, 0));
        mOffsetUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(mOffsetUnitWidget);


        gridLayout->addLayout(horizontalLayout_3, 2, 2, 1, 1);

        cboPenStyle = new QgsPenStyleComboBox(WidgetSimpleLine);
        cboPenStyle->setObjectName(QString::fromUtf8("cboPenStyle"));

        gridLayout->addWidget(cboPenStyle, 3, 2, 1, 1);

        mRingFilterComboBox = new QComboBox(WidgetSimpleLine);
        mRingFilterComboBox->setObjectName(QString::fromUtf8("mRingFilterComboBox"));

        gridLayout->addWidget(mRingFilterComboBox, 14, 2, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinWidth = new QgsDoubleSpinBox(WidgetSimpleLine);
        spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinWidth->sizePolicy().hasHeightForWidth());
        spinWidth->setSizePolicy(sizePolicy2);
        spinWidth->setDecimals(6);
        spinWidth->setMaximum(100000.000000000000000);
        spinWidth->setSingleStep(0.200000000000000);
        spinWidth->setValue(1.000000000000000);
        spinWidth->setProperty("showClearButton", QVariant(true));

        horizontalLayout_2->addWidget(spinWidth);

        mPenWidthUnitWidget = new QgsUnitSelectionWidget(WidgetSimpleLine);
        mPenWidthUnitWidget->setObjectName(QString::fromUtf8("mPenWidthUnitWidget"));
        mPenWidthUnitWidget->setMinimumSize(QSize(0, 0));
        mPenWidthUnitWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(mPenWidthUnitWidget);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        mPatternOffsetDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mPatternOffsetDDBtn->setObjectName(QString::fromUtf8("mPatternOffsetDDBtn"));

        gridLayout->addWidget(mPatternOffsetDDBtn, 10, 3, 1, 1);

        mCheckAlignDash = new QCheckBox(WidgetSimpleLine);
        mCheckAlignDash->setObjectName(QString::fromUtf8("mCheckAlignDash"));

        gridLayout->addWidget(mCheckAlignDash, 11, 0, 1, 3);

        label_5 = new QLabel(WidgetSimpleLine);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(WidgetSimpleLine);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label = new QLabel(WidgetSimpleLine);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        mCustomCheckBox = new QCheckBox(WidgetSimpleLine);
        mCustomCheckBox->setObjectName(QString::fromUtf8("mCustomCheckBox"));

        gridLayout->addWidget(mCustomCheckBox, 6, 0, 1, 3);

        label_4 = new QLabel(WidgetSimpleLine);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        mDrawInsideCheckBox = new QCheckBox(WidgetSimpleLine);
        mDrawInsideCheckBox->setObjectName(QString::fromUtf8("mDrawInsideCheckBox"));

        gridLayout->addWidget(mDrawInsideCheckBox, 13, 0, 1, 4);

        label_3 = new QLabel(WidgetSimpleLine);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        mDashPatternDDBtn = new QgsPropertyOverrideButton(WidgetSimpleLine);
        mDashPatternDDBtn->setObjectName(QString::fromUtf8("mDashPatternDDBtn"));

        gridLayout->addWidget(mDashPatternDDBtn, 7, 3, 1, 1);

        mCheckDashCorners = new QCheckBox(WidgetSimpleLine);
        mCheckDashCorners->setObjectName(QString::fromUtf8("mCheckDashCorners"));

        gridLayout->addWidget(mCheckDashCorners, 12, 0, 1, 3);

        QWidget::setTabOrder(btnChangeColor, mColorDDBtn);
        QWidget::setTabOrder(mColorDDBtn, spinWidth);
        QWidget::setTabOrder(spinWidth, mPenWidthUnitWidget);
        QWidget::setTabOrder(mPenWidthUnitWidget, mPenWidthDDBtn);
        QWidget::setTabOrder(mPenWidthDDBtn, spinOffset);
        QWidget::setTabOrder(spinOffset, mOffsetUnitWidget);
        QWidget::setTabOrder(mOffsetUnitWidget, mOffsetDDBtn);
        QWidget::setTabOrder(mOffsetDDBtn, cboPenStyle);
        QWidget::setTabOrder(cboPenStyle, mPenStyleDDBtn);
        QWidget::setTabOrder(mPenStyleDDBtn, cboJoinStyle);
        QWidget::setTabOrder(cboJoinStyle, mJoinStyleDDBtn);
        QWidget::setTabOrder(mJoinStyleDDBtn, cboCapStyle);
        QWidget::setTabOrder(cboCapStyle, mCapStyleDDBtn);
        QWidget::setTabOrder(mCapStyleDDBtn, mCustomCheckBox);
        QWidget::setTabOrder(mCustomCheckBox, mChangePatternButton);
        QWidget::setTabOrder(mChangePatternButton, mDashPatternUnitWidget);
        QWidget::setTabOrder(mDashPatternUnitWidget, mDashPatternDDBtn);
        QWidget::setTabOrder(mDashPatternDDBtn, spinPatternOffset);
        QWidget::setTabOrder(spinPatternOffset, mPatternOffsetUnitWidget);
        QWidget::setTabOrder(mPatternOffsetUnitWidget, mPatternOffsetDDBtn);
        QWidget::setTabOrder(mPatternOffsetDDBtn, mDrawInsideCheckBox);
        QWidget::setTabOrder(mDrawInsideCheckBox, mRingFilterComboBox);

        retranslateUi(WidgetSimpleLine);

        QMetaObject::connectSlotsByName(WidgetSimpleLine);
    } // setupUi

    void retranslateUi(QWidget *WidgetSimpleLine)
    {
        label_7->setText(QApplication::translate("WidgetSimpleLine", "Pattern offset", nullptr));
        mPenStyleDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        mChangePatternButton->setText(QString());
        mCapStyleDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        btnChangeColor->setText(QString());
        mColorDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        mOffsetDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        mRingsLabel->setText(QApplication::translate("WidgetSimpleLine", "Rings", nullptr));
        label_2->setText(QApplication::translate("WidgetSimpleLine", "Stroke width", nullptr));
        mPenWidthDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        mJoinStyleDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
        spinWidth->setSpecialValueText(QApplication::translate("WidgetSimpleLine", "Hairline", nullptr));
        mPatternOffsetDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckAlignDash->setToolTip(QApplication::translate("WidgetSimpleLine", "If enabled, the dash pattern sizes will be dynamically tweaked to ensure that the end of the line is represented by a complete dash element", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckAlignDash->setText(QApplication::translate("WidgetSimpleLine", "Align dash pattern to line length", nullptr));
        label_5->setText(QApplication::translate("WidgetSimpleLine", "Join style", nullptr));
        label_6->setText(QApplication::translate("WidgetSimpleLine", "Cap style", nullptr));
        label->setText(QApplication::translate("WidgetSimpleLine", "Color", nullptr));
        mCustomCheckBox->setText(QApplication::translate("WidgetSimpleLine", "Use custom dash pattern", nullptr));
        label_4->setText(QApplication::translate("WidgetSimpleLine", "Offset", nullptr));
        mDrawInsideCheckBox->setText(QApplication::translate("WidgetSimpleLine", "Draw line only inside polygon", nullptr));
        label_3->setText(QApplication::translate("WidgetSimpleLine", "Stroke style", nullptr));
        mDashPatternDDBtn->setText(QApplication::translate("WidgetSimpleLine", "\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckDashCorners->setToolTip(QApplication::translate("WidgetSimpleLine", "If enabled, the dash pattern for the line will be dynamically refined over sharp corners", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckDashCorners->setText(QApplication::translate("WidgetSimpleLine", "Tweak dash pattern at sharp corners", nullptr));
        Q_UNUSED(WidgetSimpleLine);
    } // retranslateUi

};

namespace Ui {
    class WidgetSimpleLine: public Ui_WidgetSimpleLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SIMPLELINE_H
