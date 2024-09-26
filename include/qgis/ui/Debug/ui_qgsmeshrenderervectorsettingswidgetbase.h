/********************************************************************************
** Form generated from reading UI file 'qgsmeshrenderervectorsettingswidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSMESHRENDERERVECTORSETTINGSWIDGETBASE_H
#define UI_QGSMESHRENDERERVECTORSETTINGSWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"
#include "qgsspinbox.h"
#include "qgsunitselectionwidget.h"
#include "raster/qgscolorrampshaderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsMeshRendererVectorSettingsWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *mSymbologyGroupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *mSymbologyVectorComboBox;
    QGroupBox *arrowWidthColorGroupBox;
    QGridLayout *gridLayout_3;
    QComboBox *mColoringMethodComboBox;
    QSpacerItem *horizontalSpacer;
    QgsDoubleSpinBox *mLineWidthSpinBox;
    QLabel *label_4;
    QgsCollapsibleGroupBox *mColorRampShaderGroupBox;
    QGridLayout *gridLayout_5;
    QPushButton *mColorRampShaderLoadButton;
    QFrame *line;
    QLabel *label_5;
    QLineEdit *mColorRampShaderMaximumEditLine;
    QLabel *label;
    QLineEdit *mColorRampShaderMinimumEditLine;
    QgsColorRampShaderWidget *mColorRampShaderWidget;
    QgsColorButton *mColorWidget;
    QLabel *mSimgleColorLabel;
    QGroupBox *mFilterByMagGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *minimumMagLabel;
    QLineEdit *mMinMagLineEdit;
    QLabel *maximumMagLabel;
    QLineEdit *mMaxMagLineEdit;
    QGroupBox *mDisplayVectorsOnGridGroupBox;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *xSpacingLabel;
    QLabel *ySpacingLabel;
    QgsSpinBox *mXSpacingSpinBox;
    QgsSpinBox *mYSpacingSpinBox;
    QWidget *mArrowWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *headOptionsGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *headWidthLabel;
    QLineEdit *mHeadWidthLineEdit;
    QLabel *percShaftLenLabel;
    QLabel *headLengthLabel;
    QLineEdit *mHeadLengthLineEdit;
    QLabel *percShaftLenLabel_2;
    QGroupBox *generalOptionsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *mShaftLengthComboBox;
    QStackedWidget *mShaftOptionsStackedWidget;
    QWidget *page;
    QFormLayout *formLayout;
    QLabel *minimumShaftLabel;
    QLineEdit *mMinimumShaftLineEdit;
    QLabel *maximumShaftLabel;
    QLineEdit *mMaximumShaftLineEdit;
    QWidget *page_2;
    QFormLayout *formLayout_2;
    QLabel *scaleByFactorOfLabel;
    QLineEdit *mScaleShaftByFactorOfLineEdit;
    QWidget *page_3;
    QFormLayout *formLayout_3;
    QLabel *LengthLabel;
    QLineEdit *mShaftLengthLineEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *mStreamlineWidget;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *mStreamlinesSeedingMethodComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *mStreamlinesDensityLabel;
    QgsDoubleSpinBox *mStreamlinesDensitySpinBox;
    QGroupBox *mTracesGroupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QgsSpinBox *mTracesParticlesCountSpinBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QgsDoubleSpinBox *mTracesMaxLengthSpinBox;
    QgsUnitSelectionWidget *mTracesTailLengthMapUnitWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QgsMeshRendererVectorSettingsWidgetBase)
    {
        if (QgsMeshRendererVectorSettingsWidgetBase->objectName().isEmpty())
            QgsMeshRendererVectorSettingsWidgetBase->setObjectName(QString::fromUtf8("QgsMeshRendererVectorSettingsWidgetBase"));
        QgsMeshRendererVectorSettingsWidgetBase->resize(376, 1000);
        QgsMeshRendererVectorSettingsWidgetBase->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout = new QVBoxLayout(QgsMeshRendererVectorSettingsWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mSymbologyGroupBox = new QGroupBox(QgsMeshRendererVectorSettingsWidgetBase);
        mSymbologyGroupBox->setObjectName(QString::fromUtf8("mSymbologyGroupBox"));
        mSymbologyGroupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(mSymbologyGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mSymbologyVectorComboBox = new QComboBox(mSymbologyGroupBox);
        mSymbologyVectorComboBox->addItem(QString());
        mSymbologyVectorComboBox->addItem(QString());
        mSymbologyVectorComboBox->addItem(QString());
        mSymbologyVectorComboBox->setObjectName(QString::fromUtf8("mSymbologyVectorComboBox"));

        verticalLayout_3->addWidget(mSymbologyVectorComboBox);


        verticalLayout->addWidget(mSymbologyGroupBox);

        arrowWidthColorGroupBox = new QGroupBox(QgsMeshRendererVectorSettingsWidgetBase);
        arrowWidthColorGroupBox->setObjectName(QString::fromUtf8("arrowWidthColorGroupBox"));
        gridLayout_3 = new QGridLayout(arrowWidthColorGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mColoringMethodComboBox = new QComboBox(arrowWidthColorGroupBox);
        mColoringMethodComboBox->setObjectName(QString::fromUtf8("mColoringMethodComboBox"));

        gridLayout_3->addWidget(mColoringMethodComboBox, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        mLineWidthSpinBox = new QgsDoubleSpinBox(arrowWidthColorGroupBox);
        mLineWidthSpinBox->setObjectName(QString::fromUtf8("mLineWidthSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLineWidthSpinBox->sizePolicy().hasHeightForWidth());
        mLineWidthSpinBox->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(mLineWidthSpinBox, 0, 0, 1, 1);

        label_4 = new QLabel(arrowWidthColorGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 2, 1, 1);

        mColorRampShaderGroupBox = new QgsCollapsibleGroupBox(arrowWidthColorGroupBox);
        mColorRampShaderGroupBox->setObjectName(QString::fromUtf8("mColorRampShaderGroupBox"));
        gridLayout_5 = new QGridLayout(mColorRampShaderGroupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        mColorRampShaderLoadButton = new QPushButton(mColorRampShaderGroupBox);
        mColorRampShaderLoadButton->setObjectName(QString::fromUtf8("mColorRampShaderLoadButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mColorRampShaderLoadButton->setIcon(icon);

        gridLayout_5->addWidget(mColorRampShaderLoadButton, 0, 4, 1, 1);

        line = new QFrame(mColorRampShaderGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 1, 0, 1, 5);

        label_5 = new QLabel(mColorRampShaderGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 2, 1, 1);

        mColorRampShaderMaximumEditLine = new QLineEdit(mColorRampShaderGroupBox);
        mColorRampShaderMaximumEditLine->setObjectName(QString::fromUtf8("mColorRampShaderMaximumEditLine"));

        gridLayout_5->addWidget(mColorRampShaderMaximumEditLine, 0, 3, 1, 1);

        label = new QLabel(mColorRampShaderGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        mColorRampShaderMinimumEditLine = new QLineEdit(mColorRampShaderGroupBox);
        mColorRampShaderMinimumEditLine->setObjectName(QString::fromUtf8("mColorRampShaderMinimumEditLine"));

        gridLayout_5->addWidget(mColorRampShaderMinimumEditLine, 0, 1, 1, 1);

        mColorRampShaderWidget = new QgsColorRampShaderWidget(mColorRampShaderGroupBox);
        mColorRampShaderWidget->setObjectName(QString::fromUtf8("mColorRampShaderWidget"));
        mColorRampShaderWidget->setMinimumSize(QSize(0, 0));

        gridLayout_5->addWidget(mColorRampShaderWidget, 2, 0, 1, 5);


        gridLayout_3->addWidget(mColorRampShaderGroupBox, 2, 0, 2, 4);

        mColorWidget = new QgsColorButton(arrowWidthColorGroupBox);
        mColorWidget->setObjectName(QString::fromUtf8("mColorWidget"));

        gridLayout_3->addWidget(mColorWidget, 1, 3, 1, 1);

        mSimgleColorLabel = new QLabel(arrowWidthColorGroupBox);
        mSimgleColorLabel->setObjectName(QString::fromUtf8("mSimgleColorLabel"));

        gridLayout_3->addWidget(mSimgleColorLabel, 1, 1, 1, 2);


        verticalLayout->addWidget(arrowWidthColorGroupBox);

        mFilterByMagGroupBox = new QGroupBox(QgsMeshRendererVectorSettingsWidgetBase);
        mFilterByMagGroupBox->setObjectName(QString::fromUtf8("mFilterByMagGroupBox"));
        mFilterByMagGroupBox->setChecked(false);
        horizontalLayout_2 = new QHBoxLayout(mFilterByMagGroupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        minimumMagLabel = new QLabel(mFilterByMagGroupBox);
        minimumMagLabel->setObjectName(QString::fromUtf8("minimumMagLabel"));

        horizontalLayout_2->addWidget(minimumMagLabel);

        mMinMagLineEdit = new QLineEdit(mFilterByMagGroupBox);
        mMinMagLineEdit->setObjectName(QString::fromUtf8("mMinMagLineEdit"));

        horizontalLayout_2->addWidget(mMinMagLineEdit);

        maximumMagLabel = new QLabel(mFilterByMagGroupBox);
        maximumMagLabel->setObjectName(QString::fromUtf8("maximumMagLabel"));

        horizontalLayout_2->addWidget(maximumMagLabel);

        mMaxMagLineEdit = new QLineEdit(mFilterByMagGroupBox);
        mMaxMagLineEdit->setObjectName(QString::fromUtf8("mMaxMagLineEdit"));

        horizontalLayout_2->addWidget(mMaxMagLineEdit);


        verticalLayout->addWidget(mFilterByMagGroupBox);

        mDisplayVectorsOnGridGroupBox = new QGroupBox(QgsMeshRendererVectorSettingsWidgetBase);
        mDisplayVectorsOnGridGroupBox->setObjectName(QString::fromUtf8("mDisplayVectorsOnGridGroupBox"));
        mDisplayVectorsOnGridGroupBox->setCheckable(true);
        mDisplayVectorsOnGridGroupBox->setChecked(false);
        gridLayout_2 = new QGridLayout(mDisplayVectorsOnGridGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        xSpacingLabel = new QLabel(mDisplayVectorsOnGridGroupBox);
        xSpacingLabel->setObjectName(QString::fromUtf8("xSpacingLabel"));

        gridLayout->addWidget(xSpacingLabel, 0, 0, 1, 1);

        ySpacingLabel = new QLabel(mDisplayVectorsOnGridGroupBox);
        ySpacingLabel->setObjectName(QString::fromUtf8("ySpacingLabel"));

        gridLayout->addWidget(ySpacingLabel, 1, 0, 1, 1);

        mXSpacingSpinBox = new QgsSpinBox(mDisplayVectorsOnGridGroupBox);
        mXSpacingSpinBox->setObjectName(QString::fromUtf8("mXSpacingSpinBox"));
        mXSpacingSpinBox->setMinimum(1);
        mXSpacingSpinBox->setMaximum(8000);
        mXSpacingSpinBox->setSingleStep(10);
        mXSpacingSpinBox->setValue(10);

        gridLayout->addWidget(mXSpacingSpinBox, 0, 1, 1, 1);

        mYSpacingSpinBox = new QgsSpinBox(mDisplayVectorsOnGridGroupBox);
        mYSpacingSpinBox->setObjectName(QString::fromUtf8("mYSpacingSpinBox"));
        mYSpacingSpinBox->setMinimum(1);
        mYSpacingSpinBox->setMaximum(5000);
        mYSpacingSpinBox->setSingleStep(10);
        mYSpacingSpinBox->setValue(10);

        gridLayout->addWidget(mYSpacingSpinBox, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addWidget(mDisplayVectorsOnGridGroupBox);

        mArrowWidget = new QWidget(QgsMeshRendererVectorSettingsWidgetBase);
        mArrowWidget->setObjectName(QString::fromUtf8("mArrowWidget"));
        verticalLayout_4 = new QVBoxLayout(mArrowWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        headOptionsGroupBox = new QGroupBox(mArrowWidget);
        headOptionsGroupBox->setObjectName(QString::fromUtf8("headOptionsGroupBox"));
        gridLayout_4 = new QGridLayout(headOptionsGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        headWidthLabel = new QLabel(headOptionsGroupBox);
        headWidthLabel->setObjectName(QString::fromUtf8("headWidthLabel"));

        gridLayout_4->addWidget(headWidthLabel, 0, 0, 1, 1);

        mHeadWidthLineEdit = new QLineEdit(headOptionsGroupBox);
        mHeadWidthLineEdit->setObjectName(QString::fromUtf8("mHeadWidthLineEdit"));

        gridLayout_4->addWidget(mHeadWidthLineEdit, 0, 1, 1, 1);

        percShaftLenLabel = new QLabel(headOptionsGroupBox);
        percShaftLenLabel->setObjectName(QString::fromUtf8("percShaftLenLabel"));

        gridLayout_4->addWidget(percShaftLenLabel, 0, 2, 1, 1);

        headLengthLabel = new QLabel(headOptionsGroupBox);
        headLengthLabel->setObjectName(QString::fromUtf8("headLengthLabel"));

        gridLayout_4->addWidget(headLengthLabel, 1, 0, 1, 1);

        mHeadLengthLineEdit = new QLineEdit(headOptionsGroupBox);
        mHeadLengthLineEdit->setObjectName(QString::fromUtf8("mHeadLengthLineEdit"));

        gridLayout_4->addWidget(mHeadLengthLineEdit, 1, 1, 1, 1);

        percShaftLenLabel_2 = new QLabel(headOptionsGroupBox);
        percShaftLenLabel_2->setObjectName(QString::fromUtf8("percShaftLenLabel_2"));

        gridLayout_4->addWidget(percShaftLenLabel_2, 1, 2, 1, 1);


        verticalLayout_4->addWidget(headOptionsGroupBox);

        generalOptionsGroupBox = new QGroupBox(mArrowWidget);
        generalOptionsGroupBox->setObjectName(QString::fromUtf8("generalOptionsGroupBox"));
        verticalLayout_2 = new QVBoxLayout(generalOptionsGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mShaftLengthComboBox = new QComboBox(generalOptionsGroupBox);
        mShaftLengthComboBox->addItem(QString());
        mShaftLengthComboBox->addItem(QString());
        mShaftLengthComboBox->addItem(QString());
        mShaftLengthComboBox->setObjectName(QString::fromUtf8("mShaftLengthComboBox"));
        mShaftLengthComboBox->setMinimumSize(QSize(0, 0));
        mShaftLengthComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        verticalLayout_2->addWidget(mShaftLengthComboBox);

        mShaftOptionsStackedWidget = new QStackedWidget(generalOptionsGroupBox);
        mShaftOptionsStackedWidget->setObjectName(QString::fromUtf8("mShaftOptionsStackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        formLayout = new QFormLayout(page);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        minimumShaftLabel = new QLabel(page);
        minimumShaftLabel->setObjectName(QString::fromUtf8("minimumShaftLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, minimumShaftLabel);

        mMinimumShaftLineEdit = new QLineEdit(page);
        mMinimumShaftLineEdit->setObjectName(QString::fromUtf8("mMinimumShaftLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mMinimumShaftLineEdit);

        maximumShaftLabel = new QLabel(page);
        maximumShaftLabel->setObjectName(QString::fromUtf8("maximumShaftLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, maximumShaftLabel);

        mMaximumShaftLineEdit = new QLineEdit(page);
        mMaximumShaftLineEdit->setObjectName(QString::fromUtf8("mMaximumShaftLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, mMaximumShaftLineEdit);

        mShaftOptionsStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        formLayout_2 = new QFormLayout(page_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        scaleByFactorOfLabel = new QLabel(page_2);
        scaleByFactorOfLabel->setObjectName(QString::fromUtf8("scaleByFactorOfLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, scaleByFactorOfLabel);

        mScaleShaftByFactorOfLineEdit = new QLineEdit(page_2);
        mScaleShaftByFactorOfLineEdit->setObjectName(QString::fromUtf8("mScaleShaftByFactorOfLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mScaleShaftByFactorOfLineEdit);

        mShaftOptionsStackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        formLayout_3 = new QFormLayout(page_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        LengthLabel = new QLabel(page_3);
        LengthLabel->setObjectName(QString::fromUtf8("LengthLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, LengthLabel);

        mShaftLengthLineEdit = new QLineEdit(page_3);
        mShaftLengthLineEdit->setObjectName(QString::fromUtf8("mShaftLengthLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, mShaftLengthLineEdit);

        mShaftOptionsStackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(mShaftOptionsStackedWidget);


        verticalLayout_4->addWidget(generalOptionsGroupBox);


        verticalLayout->addWidget(mArrowWidget);

        widget = new QWidget(QgsMeshRendererVectorSettingsWidgetBase);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        mStreamlineWidget = new QGroupBox(widget);
        mStreamlineWidget->setObjectName(QString::fromUtf8("mStreamlineWidget"));
        horizontalLayout_4 = new QHBoxLayout(mStreamlineWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mStreamlinesSeedingMethodComboBox = new QComboBox(mStreamlineWidget);
        mStreamlinesSeedingMethodComboBox->addItem(QString());
        mStreamlinesSeedingMethodComboBox->addItem(QString());
        mStreamlinesSeedingMethodComboBox->setObjectName(QString::fromUtf8("mStreamlinesSeedingMethodComboBox"));

        horizontalLayout_4->addWidget(mStreamlinesSeedingMethodComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        mStreamlinesDensityLabel = new QLabel(mStreamlineWidget);
        mStreamlinesDensityLabel->setObjectName(QString::fromUtf8("mStreamlinesDensityLabel"));

        horizontalLayout->addWidget(mStreamlinesDensityLabel);

        mStreamlinesDensitySpinBox = new QgsDoubleSpinBox(mStreamlineWidget);
        mStreamlinesDensitySpinBox->setObjectName(QString::fromUtf8("mStreamlinesDensitySpinBox"));
        mStreamlinesDensitySpinBox->setDecimals(1);
        mStreamlinesDensitySpinBox->setValue(5.000000000000000);

        horizontalLayout->addWidget(mStreamlinesDensitySpinBox);

        horizontalLayout->setStretch(0, 1);

        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 2);

        verticalLayout_5->addWidget(mStreamlineWidget);


        verticalLayout->addWidget(widget);

        mTracesGroupBox = new QGroupBox(QgsMeshRendererVectorSettingsWidgetBase);
        mTracesGroupBox->setObjectName(QString::fromUtf8("mTracesGroupBox"));
        verticalLayout_6 = new QVBoxLayout(mTracesGroupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(mTracesGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        mTracesParticlesCountSpinBox = new QgsSpinBox(mTracesGroupBox);
        mTracesParticlesCountSpinBox->setObjectName(QString::fromUtf8("mTracesParticlesCountSpinBox"));
        mTracesParticlesCountSpinBox->setMaximum(1000000);
        mTracesParticlesCountSpinBox->setSingleStep(100);
        mTracesParticlesCountSpinBox->setValue(1000);

        horizontalLayout_6->addWidget(mTracesParticlesCountSpinBox);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(mTracesGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        mTracesMaxLengthSpinBox = new QgsDoubleSpinBox(mTracesGroupBox);
        mTracesMaxLengthSpinBox->setObjectName(QString::fromUtf8("mTracesMaxLengthSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mTracesMaxLengthSpinBox->sizePolicy().hasHeightForWidth());
        mTracesMaxLengthSpinBox->setSizePolicy(sizePolicy1);
        mTracesMaxLengthSpinBox->setMinimumSize(QSize(0, 0));
        mTracesMaxLengthSpinBox->setMaximumSize(QSize(16777215, 16777215));
        mTracesMaxLengthSpinBox->setMinimum(1.000000000000000);
        mTracesMaxLengthSpinBox->setMaximum(99999999999999.000000000000000);
        mTracesMaxLengthSpinBox->setSingleStep(10.000000000000000);
        mTracesMaxLengthSpinBox->setValue(10.000000000000000);

        horizontalLayout_7->addWidget(mTracesMaxLengthSpinBox);

        mTracesTailLengthMapUnitWidget = new QgsUnitSelectionWidget(mTracesGroupBox);
        mTracesTailLengthMapUnitWidget->setObjectName(QString::fromUtf8("mTracesTailLengthMapUnitWidget"));

        horizontalLayout_7->addWidget(mTracesTailLengthMapUnitWidget);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(mTracesGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(QgsMeshRendererVectorSettingsWidgetBase);

        mShaftOptionsStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsMeshRendererVectorSettingsWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsMeshRendererVectorSettingsWidgetBase)
    {
        mSymbologyGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Symbology", nullptr));
        mSymbologyVectorComboBox->setItemText(0, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Arrows", nullptr));
        mSymbologyVectorComboBox->setItemText(1, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Streamlines", nullptr));
        mSymbologyVectorComboBox->setItemText(2, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Traces", nullptr));

        arrowWidthColorGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Line Width and Color", nullptr));
        label_4->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Coloring Method", nullptr));
        mColorRampShaderGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Color Ramp Shader", nullptr));
        mColorRampShaderLoadButton->setText(QString());
        label_5->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Max", nullptr));
        label->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Min", nullptr));
        mSimgleColorLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Color", nullptr));
        mFilterByMagGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Filter by Magnitude", nullptr));
        minimumMagLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Min", nullptr));
        maximumMagLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Max", nullptr));
        mDisplayVectorsOnGridGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Display on User Grid", nullptr));
        xSpacingLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "X Spacing", nullptr));
        ySpacingLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Y Spacing", nullptr));
        mXSpacingSpinBox->setSuffix(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", " px", nullptr));
        mYSpacingSpinBox->setSuffix(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", " px", nullptr));
        headOptionsGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Head Options", nullptr));
        headWidthLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Width", nullptr));
        percShaftLenLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "% of shaft length", nullptr));
        headLengthLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Length", nullptr));
        percShaftLenLabel_2->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "% of shaft length", nullptr));
        generalOptionsGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Arrow Length", nullptr));
        mShaftLengthComboBox->setItemText(0, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Defined by Min and Max", nullptr));
        mShaftLengthComboBox->setItemText(1, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Scaled to Magnitude", nullptr));
        mShaftLengthComboBox->setItemText(2, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Fixed", nullptr));

        minimumShaftLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Minimum", nullptr));
        maximumShaftLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Maximum", nullptr));
        scaleByFactorOfLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Scale by a factor of", nullptr));
        LengthLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Length", nullptr));
        mStreamlineWidget->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Streamlines Seeding Method", nullptr));
        mStreamlinesSeedingMethodComboBox->setItemText(0, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "On Mesh/Grid", nullptr));
        mStreamlinesSeedingMethodComboBox->setItemText(1, QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Randomly", nullptr));

        mStreamlinesDensityLabel->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Density", nullptr));
        mStreamlinesDensitySpinBox->setSuffix(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "%", nullptr));
        mTracesGroupBox->setTitle(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Traces", nullptr));
        label_2->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Particles count", nullptr));
        label_3->setText(QApplication::translate("QgsMeshRendererVectorSettingsWidgetBase", "Max tail length", nullptr));
        Q_UNUSED(QgsMeshRendererVectorSettingsWidgetBase);
    } // retranslateUi

};

namespace Ui {
    class QgsMeshRendererVectorSettingsWidgetBase: public Ui_QgsMeshRendererVectorSettingsWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSMESHRENDERERVECTORSETTINGSWIDGETBASE_H
