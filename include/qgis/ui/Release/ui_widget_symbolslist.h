/********************************************************************************
** Form generated from reading UI file 'widget_symbolslist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SYMBOLSLIST_H
#define UI_WIDGET_SYMBOLSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"
#include "qgsopacitywidget.h"
#include "qgspropertyoverridebutton.h"
#include "qgsstyleitemslistwidget.h"
#include "qgsunitselectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SymbolsListWidget
{
public:
    QGridLayout *gridLayout_4;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *mTransparencyLabel;
    QLabel *mSymbolUnitLabel;
    QgsUnitSelectionWidget *mSymbolUnitWidget;
    QLabel *label_5;
    QgsOpacityWidget *mOpacityWidget;
    QgsColorButton *btnColor;
    QStackedWidget *stackedWidget;
    QWidget *pageMarker;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QgsDoubleSpinBox *spinSize;
    QgsPropertyOverrideButton *mSizeDDBtn;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QgsDoubleSpinBox *spinAngle;
    QgsPropertyOverrideButton *mRotationDDBtn;
    QWidget *pageLine;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QgsDoubleSpinBox *spinWidth;
    QgsPropertyOverrideButton *mWidthDDBtn;
    QWidget *pageFill;
    QHBoxLayout *horizontalLayout_2;
    QgsStyleItemsListWidget *mStyleItemsListWidget;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *SymbolsListWidget)
    {
        if (SymbolsListWidget->objectName().isEmpty())
            SymbolsListWidget->setObjectName(QString::fromUtf8("SymbolsListWidget"));
        SymbolsListWidget->resize(386, 619);
        SymbolsListWidget->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout_4 = new QGridLayout(SymbolsListWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(4);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(SymbolsListWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mTransparencyLabel = new QLabel(SymbolsListWidget);
        mTransparencyLabel->setObjectName(QString::fromUtf8("mTransparencyLabel"));

        gridLayout->addWidget(mTransparencyLabel, 1, 0, 1, 1);

        mSymbolUnitLabel = new QLabel(SymbolsListWidget);
        mSymbolUnitLabel->setObjectName(QString::fromUtf8("mSymbolUnitLabel"));

        gridLayout->addWidget(mSymbolUnitLabel, 0, 0, 1, 1);

        mSymbolUnitWidget = new QgsUnitSelectionWidget(SymbolsListWidget);
        mSymbolUnitWidget->setObjectName(QString::fromUtf8("mSymbolUnitWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mSymbolUnitWidget->sizePolicy().hasHeightForWidth());
        mSymbolUnitWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(mSymbolUnitWidget, 0, 1, 1, 1);

        label_5 = new QLabel(SymbolsListWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        mOpacityWidget = new QgsOpacityWidget(SymbolsListWidget);
        mOpacityWidget->setObjectName(QString::fromUtf8("mOpacityWidget"));
        mOpacityWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(mOpacityWidget, 1, 1, 1, 1);

        btnColor = new QgsColorButton(SymbolsListWidget);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnColor->sizePolicy().hasHeightForWidth());
        btnColor->setSizePolicy(sizePolicy1);
        btnColor->setMinimumSize(QSize(0, 0));
        btnColor->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(btnColor, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        stackedWidget = new QStackedWidget(SymbolsListWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
        pageMarker = new QWidget();
        pageMarker->setObjectName(QString::fromUtf8("pageMarker"));
        gridLayout_2 = new QGridLayout(pageMarker);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(pageMarker);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        spinSize = new QgsDoubleSpinBox(pageMarker);
        spinSize->setObjectName(QString::fromUtf8("spinSize"));
        spinSize->setDecimals(5);
        spinSize->setMaximum(99999999.989999994635582);
        spinSize->setSingleStep(0.200000000000000);
        spinSize->setValue(1.000000000000000);
        spinSize->setProperty("showClearButton", QVariant(false));

        horizontalLayout->addWidget(spinSize);

        mSizeDDBtn = new QgsPropertyOverrideButton(pageMarker);
        mSizeDDBtn->setObjectName(QString::fromUtf8("mSizeDDBtn"));

        horizontalLayout->addWidget(mSizeDDBtn);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        label_3 = new QLabel(pageMarker);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        spinAngle = new QgsDoubleSpinBox(pageMarker);
        spinAngle->setObjectName(QString::fromUtf8("spinAngle"));
        spinAngle->setWrapping(true);
        spinAngle->setDecimals(2);
        spinAngle->setMinimum(-360.000000000000000);
        spinAngle->setMaximum(360.000000000000000);
        spinAngle->setSingleStep(1.000000000000000);

        horizontalLayout_5->addWidget(spinAngle);

        mRotationDDBtn = new QgsPropertyOverrideButton(pageMarker);
        mRotationDDBtn->setObjectName(QString::fromUtf8("mRotationDDBtn"));

        horizontalLayout_5->addWidget(mRotationDDBtn);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        stackedWidget->addWidget(pageMarker);
        pageLine = new QWidget();
        pageLine->setObjectName(QString::fromUtf8("pageLine"));
        gridLayout_3 = new QGridLayout(pageLine);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(pageLine);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        spinWidth = new QgsDoubleSpinBox(pageLine);
        spinWidth->setObjectName(QString::fromUtf8("spinWidth"));
        spinWidth->setDecimals(5);
        spinWidth->setMaximum(99999.000000000000000);
        spinWidth->setSingleStep(0.200000000000000);
        spinWidth->setValue(1.000000000000000);
        spinWidth->setProperty("showClearButton", QVariant(false));

        horizontalLayout_6->addWidget(spinWidth);

        mWidthDDBtn = new QgsPropertyOverrideButton(pageLine);
        mWidthDDBtn->setObjectName(QString::fromUtf8("mWidthDDBtn"));

        horizontalLayout_6->addWidget(mWidthDDBtn);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        stackedWidget->addWidget(pageLine);
        pageFill = new QWidget();
        pageFill->setObjectName(QString::fromUtf8("pageFill"));
        horizontalLayout_2 = new QHBoxLayout(pageFill);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(pageFill);

        verticalLayout->addWidget(stackedWidget);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        mStyleItemsListWidget = new QgsStyleItemsListWidget(SymbolsListWidget);
        mStyleItemsListWidget->setObjectName(QString::fromUtf8("mStyleItemsListWidget"));

        gridLayout_4->addWidget(mStyleItemsListWidget, 2, 0, 1, 1);

        gridLayout_4->setRowStretch(2, 1);
#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(btnColor);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(mOpacityWidget, btnColor);
        QWidget::setTabOrder(btnColor, spinSize);
        QWidget::setTabOrder(spinSize, mSizeDDBtn);
        QWidget::setTabOrder(mSizeDDBtn, spinAngle);
        QWidget::setTabOrder(spinAngle, mRotationDDBtn);
        QWidget::setTabOrder(mRotationDDBtn, spinWidth);
        QWidget::setTabOrder(spinWidth, mWidthDDBtn);
        QWidget::setTabOrder(mWidthDDBtn, spinSize);
        QWidget::setTabOrder(spinSize, mSizeDDBtn);
        QWidget::setTabOrder(mSizeDDBtn, spinAngle);
        QWidget::setTabOrder(spinAngle, mRotationDDBtn);
        QWidget::setTabOrder(mRotationDDBtn, spinWidth);
        QWidget::setTabOrder(spinWidth, mWidthDDBtn);

        retranslateUi(SymbolsListWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SymbolsListWidget);
    } // setupUi

    void retranslateUi(QWidget *SymbolsListWidget)
    {
        mTransparencyLabel->setText(QApplication::translate("SymbolsListWidget", "Opacity", nullptr));
        mSymbolUnitLabel->setText(QApplication::translate("SymbolsListWidget", "Unit", nullptr));
        label_5->setText(QApplication::translate("SymbolsListWidget", "Color", nullptr));
        btnColor->setText(QString());
        label_2->setText(QApplication::translate("SymbolsListWidget", "Size", nullptr));
        mSizeDDBtn->setText(QApplication::translate("SymbolsListWidget", "\342\200\246", nullptr));
        label_3->setText(QApplication::translate("SymbolsListWidget", "Rotation", nullptr));
        spinAngle->setSuffix(QApplication::translate("SymbolsListWidget", " \302\260", nullptr));
        mRotationDDBtn->setText(QApplication::translate("SymbolsListWidget", "\342\200\246", nullptr));
        label_4->setText(QApplication::translate("SymbolsListWidget", "Width", nullptr));
        mWidthDDBtn->setText(QApplication::translate("SymbolsListWidget", "\342\200\246", nullptr));
        Q_UNUSED(SymbolsListWidget);
    } // retranslateUi

};

namespace Ui {
    class SymbolsListWidget: public Ui_SymbolsListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SYMBOLSLIST_H
