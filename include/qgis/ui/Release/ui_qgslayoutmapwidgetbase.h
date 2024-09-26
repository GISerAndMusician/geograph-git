/********************************************************************************
** Form generated from reading UI file 'qgslayoutmapwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSLAYOUTMAPWIDGETBASE_H
#define UI_QGSLAYOUTMAPWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qgscollapsiblegroupbox.h>
#include <qgsmaplayercombobox.h>
#include "qgsblendmodecombobox.h"
#include "qgsdoublespinbox.h"
#include "qgslayoutitemcombobox.h"
#include "qgsprojectionselectionwidget.h"
#include "qgspropertyoverridebutton.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"
#include "qgssymbolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsLayoutMapWidgetBase
{
public:
    QAction *mActionUpdatePreview;
    QAction *mActionSetToCanvasExtent;
    QAction *mActionViewExtentInCanvas;
    QAction *mActionMoveContent;
    QAction *mActionViewScaleInCanvas;
    QAction *mActionSetToCanvasScale;
    QAction *mActionLabelSettings;
    QAction *mActionClipSettings;
    QVBoxLayout *verticalLayout_2;
    QLabel *mLabel;
    QToolBar *mDockToolbar;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *mainLayout;
    QgsCollapsibleGroupBoxBasic *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *mScaleLabel;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *mScaleLineEdit;
    QgsPropertyOverrideButton *mScaleDDBtn;
    QHBoxLayout *horizontalLayout_7;
    QgsDoubleSpinBox *mMapRotationSpinBox;
    QgsPropertyOverrideButton *mMapRotationDDBtn;
    QHBoxLayout *horizontalLayout_2;
    QgsProjectionSelectionWidget *mCrsSelector;
    QgsPropertyOverrideButton *mCRSDDBtn;
    QLabel *mMapRotationLabel;
    QLabel *mCrsLabel;
    QCheckBox *mDrawCanvasItemsCheckBox;
    QgsCollapsibleGroupBoxBasic *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *mFollowVisibilityPresetCheckBox;
    QComboBox *mFollowVisibilityPresetCombo;
    QgsPropertyOverrideButton *mStylePresetsDDBtn;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *mKeepLayerListCheckBox;
    QSpacerItem *horizontalSpacer;
    QToolButton *mLayerListFromPresetButton;
    QgsPropertyOverrideButton *mLayersDDBtn;
    QCheckBox *mKeepLayerStylesCheckBox;
    QgsCollapsibleGroupBoxBasic *mExtentsCheckBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *mYMinLineEdit;
    QgsPropertyOverrideButton *mYMinDDBtn;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *mXMaxLineEdit;
    QgsPropertyOverrideButton *mXMaxDDBtn;
    QLabel *mYMinLabel;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *mYMaxLineEdit;
    QgsPropertyOverrideButton *mYMaxDDBtn;
    QLabel *mXMaxLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *mXMinLineEdit;
    QgsPropertyOverrideButton *mXMinDDBtn;
    QLabel *mXMinLabel;
    QLabel *mYMaxLabel;
    QgsCollapsibleGroupBoxBasic *mTemporalCheckBox;
    QGridLayout *gridLayout_5;
    QLabel *mStartDateTimeLabel;
    QDateTimeEdit *mStartDateTime;
    QgsPropertyOverrideButton *mStartDateTimeDDBtn;
    QLabel *mEndDateTimeLabel;
    QDateTimeEdit *mEndDateTime;
    QgsPropertyOverrideButton *mEndDateTimeDDBtn;
    QgsCollapsibleGroupBoxBasic *mAtlasCheckBox;
    QGridLayout *gridLayout_2;
    QRadioButton *mAtlasMarginRadio;
    QHBoxLayout *horizontalLayout_11;
    QgsSpinBox *mAtlasMarginSpinBox;
    QgsPropertyOverrideButton *mAtlasMarginDDBtn;
    QRadioButton *mAtlasPredefinedScaleRadio;
    QRadioButton *mAtlasFixedScaleRadio;
    QgsCollapsibleGroupBoxBasic *mGridGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *mAddGridPushButton;
    QPushButton *mRemoveGridPushButton;
    QPushButton *mGridUpButton;
    QPushButton *mGridDownButton;
    QListWidget *mGridListWidget;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *mGridPropertiesButton;
    QgsCollapsibleGroupBoxBasic *mOverviewsGroupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *mAddOverviewPushButton;
    QPushButton *mRemoveOverviewPushButton;
    QPushButton *mOverviewUpButton;
    QPushButton *mOverviewDownButton;
    QListWidget *mOverviewListWidget;
    QgsCollapsibleGroupBoxBasic *mOverviewCheckBox;
    QGridLayout *gridLayout_8;
    QComboBox *mOverviewPositionComboBox;
    QLabel *mOverviewPositionLabel;
    QgsSymbolButton *mOverviewFrameStyleButton;
    QgsBlendModeComboBox *mOverviewBlendModeComboBox;
    QCheckBox *mOverviewInvertCheckbox;
    QLabel *mOverviewBlendModeLabel;
    QLabel *mOverviewFrameStyleLabel;
    QLabel *mOverviewFrameMapLabel;
    QCheckBox *mOverviewCenterCheckbox;
    QgsLayoutItemComboBox *mOverviewFrameMapComboBox;
    QgsMapLayerComboBox *mOverviewStackingLayerComboBox;
    QLabel *label;

    void setupUi(QWidget *QgsLayoutMapWidgetBase)
    {
        if (QgsLayoutMapWidgetBase->objectName().isEmpty())
            QgsLayoutMapWidgetBase->setObjectName(QString::fromUtf8("QgsLayoutMapWidgetBase"));
        QgsLayoutMapWidgetBase->resize(564, 749);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QgsLayoutMapWidgetBase->sizePolicy().hasHeightForWidth());
        QgsLayoutMapWidgetBase->setSizePolicy(sizePolicy);
        mActionUpdatePreview = new QAction(QgsLayoutMapWidgetBase);
        mActionUpdatePreview->setObjectName(QString::fromUtf8("mActionUpdatePreview"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionUpdatePreview->setIcon(icon);
        mActionSetToCanvasExtent = new QAction(QgsLayoutMapWidgetBase);
        mActionSetToCanvasExtent->setObjectName(QString::fromUtf8("mActionSetToCanvasExtent"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionSetToCanvasExtent.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSetToCanvasExtent->setIcon(icon1);
        mActionViewExtentInCanvas = new QAction(QgsLayoutMapWidgetBase);
        mActionViewExtentInCanvas->setObjectName(QString::fromUtf8("mActionViewExtentInCanvas"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionViewExtentInCanvas.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionViewExtentInCanvas->setIcon(icon2);
        mActionMoveContent = new QAction(QgsLayoutMapWidgetBase);
        mActionMoveContent->setObjectName(QString::fromUtf8("mActionMoveContent"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionMoveItemContent.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionMoveContent->setIcon(icon3);
        mActionViewScaleInCanvas = new QAction(QgsLayoutMapWidgetBase);
        mActionViewScaleInCanvas->setObjectName(QString::fromUtf8("mActionViewScaleInCanvas"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionViewScaleInCanvas.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionViewScaleInCanvas->setIcon(icon4);
        mActionSetToCanvasScale = new QAction(QgsLayoutMapWidgetBase);
        mActionSetToCanvasScale->setObjectName(QString::fromUtf8("mActionSetToCanvasScale"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionSetToCanvasScale.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSetToCanvasScale->setIcon(icon5);
        mActionLabelSettings = new QAction(QgsLayoutMapWidgetBase);
        mActionLabelSettings->setObjectName(QString::fromUtf8("mActionLabelSettings"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/labelingSingle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionLabelSettings->setIcon(icon6);
        mActionClipSettings = new QAction(QgsLayoutMapWidgetBase);
        mActionClipSettings->setObjectName(QString::fromUtf8("mActionClipSettings"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/algorithms/mAlgorithmClip.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionClipSettings->setIcon(icon7);
        verticalLayout_2 = new QVBoxLayout(QgsLayoutMapWidgetBase);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mLabel = new QLabel(QgsLayoutMapWidgetBase);
        mLabel->setObjectName(QString::fromUtf8("mLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mLabel->sizePolicy().hasHeightForWidth());
        mLabel->setSizePolicy(sizePolicy1);
        mLabel->setStyleSheet(QString::fromUtf8("padding: 2px; font-weight: bold; background-color: rgb(200, 200, 200);"));

        verticalLayout_2->addWidget(mLabel);

        mDockToolbar = new QToolBar(QgsLayoutMapWidgetBase);
        mDockToolbar->setObjectName(QString::fromUtf8("mDockToolbar"));
        mDockToolbar->setIconSize(QSize(16, 16));
        mDockToolbar->setFloatable(false);

        verticalLayout_2->addWidget(mDockToolbar);

        scrollArea = new QgsScrollArea(QgsLayoutMapWidgetBase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 548, 1284));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        mainLayout = new QVBoxLayout(scrollAreaWidgetContents);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        groupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFocusPolicy(Qt::StrongFocus);
        groupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        groupBox->setProperty("collapsed", QVariant(false));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mScaleLabel = new QLabel(groupBox);
        mScaleLabel->setObjectName(QString::fromUtf8("mScaleLabel"));

        gridLayout_4->addWidget(mScaleLabel, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mScaleLineEdit = new QLineEdit(groupBox);
        mScaleLineEdit->setObjectName(QString::fromUtf8("mScaleLineEdit"));

        horizontalLayout_6->addWidget(mScaleLineEdit);

        mScaleDDBtn = new QgsPropertyOverrideButton(groupBox);
        mScaleDDBtn->setObjectName(QString::fromUtf8("mScaleDDBtn"));

        horizontalLayout_6->addWidget(mScaleDDBtn);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        mMapRotationSpinBox = new QgsDoubleSpinBox(groupBox);
        mMapRotationSpinBox->setObjectName(QString::fromUtf8("mMapRotationSpinBox"));
        mMapRotationSpinBox->setWrapping(true);
        mMapRotationSpinBox->setMinimum(-360.000000000000000);
        mMapRotationSpinBox->setMaximum(360.000000000000000);

        horizontalLayout_7->addWidget(mMapRotationSpinBox);

        mMapRotationDDBtn = new QgsPropertyOverrideButton(groupBox);
        mMapRotationDDBtn->setObjectName(QString::fromUtf8("mMapRotationDDBtn"));

        horizontalLayout_7->addWidget(mMapRotationDDBtn);


        gridLayout_3->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mCrsSelector = new QgsProjectionSelectionWidget(groupBox);
        mCrsSelector->setObjectName(QString::fromUtf8("mCrsSelector"));
        mCrsSelector->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_2->addWidget(mCrsSelector);

        mCRSDDBtn = new QgsPropertyOverrideButton(groupBox);
        mCRSDDBtn->setObjectName(QString::fromUtf8("mCRSDDBtn"));

        horizontalLayout_2->addWidget(mCRSDDBtn);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 3, 1);

        mMapRotationLabel = new QLabel(groupBox);
        mMapRotationLabel->setObjectName(QString::fromUtf8("mMapRotationLabel"));

        gridLayout_4->addWidget(mMapRotationLabel, 1, 0, 1, 1);

        mCrsLabel = new QLabel(groupBox);
        mCrsLabel->setObjectName(QString::fromUtf8("mCrsLabel"));

        gridLayout_4->addWidget(mCrsLabel, 2, 0, 1, 1);

        mDrawCanvasItemsCheckBox = new QCheckBox(groupBox);
        mDrawCanvasItemsCheckBox->setObjectName(QString::fromUtf8("mDrawCanvasItemsCheckBox"));

        gridLayout_4->addWidget(mDrawCanvasItemsCheckBox, 3, 0, 1, 2);


        mainLayout->addWidget(groupBox);

        groupBox_2 = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        mFollowVisibilityPresetCheckBox = new QCheckBox(groupBox_2);
        mFollowVisibilityPresetCheckBox->setObjectName(QString::fromUtf8("mFollowVisibilityPresetCheckBox"));

        horizontalLayout_12->addWidget(mFollowVisibilityPresetCheckBox);

        mFollowVisibilityPresetCombo = new QComboBox(groupBox_2);
        mFollowVisibilityPresetCombo->setObjectName(QString::fromUtf8("mFollowVisibilityPresetCombo"));

        horizontalLayout_12->addWidget(mFollowVisibilityPresetCombo);

        mStylePresetsDDBtn = new QgsPropertyOverrideButton(groupBox_2);
        mStylePresetsDDBtn->setObjectName(QString::fromUtf8("mStylePresetsDDBtn"));

        horizontalLayout_12->addWidget(mStylePresetsDDBtn);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        mKeepLayerListCheckBox = new QCheckBox(groupBox_2);
        mKeepLayerListCheckBox->setObjectName(QString::fromUtf8("mKeepLayerListCheckBox"));
        sizePolicy1.setHeightForWidth(mKeepLayerListCheckBox->sizePolicy().hasHeightForWidth());
        mKeepLayerListCheckBox->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(mKeepLayerListCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        mLayerListFromPresetButton = new QToolButton(groupBox_2);
        mLayerListFromPresetButton->setObjectName(QString::fromUtf8("mLayerListFromPresetButton"));
        mLayerListFromPresetButton->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout_10->addWidget(mLayerListFromPresetButton);

        mLayersDDBtn = new QgsPropertyOverrideButton(groupBox_2);
        mLayersDDBtn->setObjectName(QString::fromUtf8("mLayersDDBtn"));

        horizontalLayout_10->addWidget(mLayersDDBtn);


        verticalLayout_4->addLayout(horizontalLayout_10);

        mKeepLayerStylesCheckBox = new QCheckBox(groupBox_2);
        mKeepLayerStylesCheckBox->setObjectName(QString::fromUtf8("mKeepLayerStylesCheckBox"));

        verticalLayout_4->addWidget(mKeepLayerStylesCheckBox);


        mainLayout->addWidget(groupBox_2);

        mExtentsCheckBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mExtentsCheckBox->setObjectName(QString::fromUtf8("mExtentsCheckBox"));
        mExtentsCheckBox->setFocusPolicy(Qt::StrongFocus);
        mExtentsCheckBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mExtentsCheckBox->setProperty("collapsed", QVariant(false));
        gridLayout = new QGridLayout(mExtentsCheckBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        mYMinLineEdit = new QLineEdit(mExtentsCheckBox);
        mYMinLineEdit->setObjectName(QString::fromUtf8("mYMinLineEdit"));

        horizontalLayout_3->addWidget(mYMinLineEdit);

        mYMinDDBtn = new QgsPropertyOverrideButton(mExtentsCheckBox);
        mYMinDDBtn->setObjectName(QString::fromUtf8("mYMinDDBtn"));

        horizontalLayout_3->addWidget(mYMinDDBtn);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        mXMaxLineEdit = new QLineEdit(mExtentsCheckBox);
        mXMaxLineEdit->setObjectName(QString::fromUtf8("mXMaxLineEdit"));

        horizontalLayout_4->addWidget(mXMaxLineEdit);

        mXMaxDDBtn = new QgsPropertyOverrideButton(mExtentsCheckBox);
        mXMaxDDBtn->setObjectName(QString::fromUtf8("mXMaxDDBtn"));

        horizontalLayout_4->addWidget(mXMaxDDBtn);


        gridLayout->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        mYMinLabel = new QLabel(mExtentsCheckBox);
        mYMinLabel->setObjectName(QString::fromUtf8("mYMinLabel"));
        mYMinLabel->setWordWrap(false);

        gridLayout->addWidget(mYMinLabel, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        mYMaxLineEdit = new QLineEdit(mExtentsCheckBox);
        mYMaxLineEdit->setObjectName(QString::fromUtf8("mYMaxLineEdit"));

        horizontalLayout_5->addWidget(mYMaxLineEdit);

        mYMaxDDBtn = new QgsPropertyOverrideButton(mExtentsCheckBox);
        mYMaxDDBtn->setObjectName(QString::fromUtf8("mYMaxDDBtn"));

        horizontalLayout_5->addWidget(mYMaxDDBtn);


        gridLayout->addLayout(horizontalLayout_5, 3, 1, 1, 1);

        mXMaxLabel = new QLabel(mExtentsCheckBox);
        mXMaxLabel->setObjectName(QString::fromUtf8("mXMaxLabel"));
        mXMaxLabel->setWordWrap(false);

        gridLayout->addWidget(mXMaxLabel, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mXMinLineEdit = new QLineEdit(mExtentsCheckBox);
        mXMinLineEdit->setObjectName(QString::fromUtf8("mXMinLineEdit"));

        horizontalLayout->addWidget(mXMinLineEdit);

        mXMinDDBtn = new QgsPropertyOverrideButton(mExtentsCheckBox);
        mXMinDDBtn->setObjectName(QString::fromUtf8("mXMinDDBtn"));

        horizontalLayout->addWidget(mXMinDDBtn);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        mXMinLabel = new QLabel(mExtentsCheckBox);
        mXMinLabel->setObjectName(QString::fromUtf8("mXMinLabel"));
        mXMinLabel->setEnabled(true);
        mXMinLabel->setWordWrap(false);

        gridLayout->addWidget(mXMinLabel, 0, 0, 1, 1);

        mYMaxLabel = new QLabel(mExtentsCheckBox);
        mYMaxLabel->setObjectName(QString::fromUtf8("mYMaxLabel"));
        mYMaxLabel->setWordWrap(false);

        gridLayout->addWidget(mYMaxLabel, 3, 0, 1, 1);


        mainLayout->addWidget(mExtentsCheckBox);

        mTemporalCheckBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mTemporalCheckBox->setObjectName(QString::fromUtf8("mTemporalCheckBox"));
        mTemporalCheckBox->setCheckable(true);
        mTemporalCheckBox->setChecked(false);
        mTemporalCheckBox->setProperty("collapsed", QVariant(true));
        mTemporalCheckBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        gridLayout_5 = new QGridLayout(mTemporalCheckBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        mStartDateTimeLabel = new QLabel(mTemporalCheckBox);
        mStartDateTimeLabel->setObjectName(QString::fromUtf8("mStartDateTimeLabel"));
        mStartDateTimeLabel->setEnabled(true);
        mStartDateTimeLabel->setWordWrap(false);

        gridLayout_5->addWidget(mStartDateTimeLabel, 0, 0, 1, 1);

        mStartDateTime = new QDateTimeEdit(mTemporalCheckBox);
        mStartDateTime->setObjectName(QString::fromUtf8("mStartDateTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mStartDateTime->sizePolicy().hasHeightForWidth());
        mStartDateTime->setSizePolicy(sizePolicy2);
        mStartDateTime->setTimeSpec(Qt::UTC);

        gridLayout_5->addWidget(mStartDateTime, 0, 1, 1, 1);

        mStartDateTimeDDBtn = new QgsPropertyOverrideButton(mTemporalCheckBox);
        mStartDateTimeDDBtn->setObjectName(QString::fromUtf8("mStartDateTimeDDBtn"));

        gridLayout_5->addWidget(mStartDateTimeDDBtn, 0, 2, 1, 1);

        mEndDateTimeLabel = new QLabel(mTemporalCheckBox);
        mEndDateTimeLabel->setObjectName(QString::fromUtf8("mEndDateTimeLabel"));
        mEndDateTimeLabel->setEnabled(true);
        mEndDateTimeLabel->setWordWrap(false);

        gridLayout_5->addWidget(mEndDateTimeLabel, 1, 0, 1, 1);

        mEndDateTime = new QDateTimeEdit(mTemporalCheckBox);
        mEndDateTime->setObjectName(QString::fromUtf8("mEndDateTime"));
        sizePolicy2.setHeightForWidth(mEndDateTime->sizePolicy().hasHeightForWidth());
        mEndDateTime->setSizePolicy(sizePolicy2);
        mEndDateTime->setTimeSpec(Qt::UTC);

        gridLayout_5->addWidget(mEndDateTime, 1, 1, 1, 1);

        mEndDateTimeDDBtn = new QgsPropertyOverrideButton(mTemporalCheckBox);
        mEndDateTimeDDBtn->setObjectName(QString::fromUtf8("mEndDateTimeDDBtn"));

        gridLayout_5->addWidget(mEndDateTimeDDBtn, 1, 2, 1, 1);


        mainLayout->addWidget(mTemporalCheckBox);

        mAtlasCheckBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mAtlasCheckBox->setObjectName(QString::fromUtf8("mAtlasCheckBox"));
        mAtlasCheckBox->setCheckable(true);
        mAtlasCheckBox->setChecked(false);
        mAtlasCheckBox->setProperty("collapsed", QVariant(true));
        mAtlasCheckBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        gridLayout_2 = new QGridLayout(mAtlasCheckBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mAtlasMarginRadio = new QRadioButton(mAtlasCheckBox);
        mAtlasMarginRadio->setObjectName(QString::fromUtf8("mAtlasMarginRadio"));
        mAtlasMarginRadio->setEnabled(false);

        gridLayout_2->addWidget(mAtlasMarginRadio, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        mAtlasMarginSpinBox = new QgsSpinBox(mAtlasCheckBox);
        mAtlasMarginSpinBox->setObjectName(QString::fromUtf8("mAtlasMarginSpinBox"));
        mAtlasMarginSpinBox->setEnabled(false);
        sizePolicy2.setHeightForWidth(mAtlasMarginSpinBox->sizePolicy().hasHeightForWidth());
        mAtlasMarginSpinBox->setSizePolicy(sizePolicy2);
        mAtlasMarginSpinBox->setMaximum(9999);
        mAtlasMarginSpinBox->setValue(10);

        horizontalLayout_11->addWidget(mAtlasMarginSpinBox);

        mAtlasMarginDDBtn = new QgsPropertyOverrideButton(mAtlasCheckBox);
        mAtlasMarginDDBtn->setObjectName(QString::fromUtf8("mAtlasMarginDDBtn"));

        horizontalLayout_11->addWidget(mAtlasMarginDDBtn);


        gridLayout_2->addLayout(horizontalLayout_11, 0, 1, 1, 1);

        mAtlasPredefinedScaleRadio = new QRadioButton(mAtlasCheckBox);
        mAtlasPredefinedScaleRadio->setObjectName(QString::fromUtf8("mAtlasPredefinedScaleRadio"));

        gridLayout_2->addWidget(mAtlasPredefinedScaleRadio, 1, 0, 1, 1);

        mAtlasFixedScaleRadio = new QRadioButton(mAtlasCheckBox);
        mAtlasFixedScaleRadio->setObjectName(QString::fromUtf8("mAtlasFixedScaleRadio"));
        mAtlasFixedScaleRadio->setEnabled(false);

        gridLayout_2->addWidget(mAtlasFixedScaleRadio, 2, 0, 1, 1);


        mainLayout->addWidget(mAtlasCheckBox);

        mGridGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mGridGroupBox->setObjectName(QString::fromUtf8("mGridGroupBox"));
        mGridGroupBox->setFocusPolicy(Qt::StrongFocus);
        mGridGroupBox->setProperty("collapsed", QVariant(true));
        mGridGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        verticalLayout_3 = new QVBoxLayout(mGridGroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        mAddGridPushButton = new QPushButton(mGridGroupBox);
        mAddGridPushButton->setObjectName(QString::fromUtf8("mAddGridPushButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/symbologyAdd.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mAddGridPushButton->setIcon(icon8);

        horizontalLayout_8->addWidget(mAddGridPushButton);

        mRemoveGridPushButton = new QPushButton(mGridGroupBox);
        mRemoveGridPushButton->setObjectName(QString::fromUtf8("mRemoveGridPushButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/themes/default/symbologyRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mRemoveGridPushButton->setIcon(icon9);

        horizontalLayout_8->addWidget(mRemoveGridPushButton);

        mGridUpButton = new QPushButton(mGridGroupBox);
        mGridUpButton->setObjectName(QString::fromUtf8("mGridUpButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/themes/default/mActionArrowUp.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mGridUpButton->setIcon(icon10);

        horizontalLayout_8->addWidget(mGridUpButton);

        mGridDownButton = new QPushButton(mGridGroupBox);
        mGridDownButton->setObjectName(QString::fromUtf8("mGridDownButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/themes/default/mActionArrowDown.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mGridDownButton->setIcon(icon11);

        horizontalLayout_8->addWidget(mGridDownButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        mGridListWidget = new QListWidget(mGridGroupBox);
        mGridListWidget->setObjectName(QString::fromUtf8("mGridListWidget"));
        sizePolicy.setHeightForWidth(mGridListWidget->sizePolicy().hasHeightForWidth());
        mGridListWidget->setSizePolicy(sizePolicy);
        mGridListWidget->setMaximumSize(QSize(16777215, 90));

        verticalLayout_3->addWidget(mGridListWidget);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        mGridPropertiesButton = new QPushButton(mGridGroupBox);
        mGridPropertiesButton->setObjectName(QString::fromUtf8("mGridPropertiesButton"));

        horizontalLayout_13->addWidget(mGridPropertiesButton);


        verticalLayout_3->addLayout(horizontalLayout_13);


        mainLayout->addWidget(mGridGroupBox);

        mOverviewsGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mOverviewsGroupBox->setObjectName(QString::fromUtf8("mOverviewsGroupBox"));
        mOverviewsGroupBox->setFocusPolicy(Qt::StrongFocus);
        mOverviewsGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mOverviewsGroupBox->setProperty("collapsed", QVariant(true));
        verticalLayout = new QVBoxLayout(mOverviewsGroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        mAddOverviewPushButton = new QPushButton(mOverviewsGroupBox);
        mAddOverviewPushButton->setObjectName(QString::fromUtf8("mAddOverviewPushButton"));
        mAddOverviewPushButton->setIcon(icon8);

        horizontalLayout_9->addWidget(mAddOverviewPushButton);

        mRemoveOverviewPushButton = new QPushButton(mOverviewsGroupBox);
        mRemoveOverviewPushButton->setObjectName(QString::fromUtf8("mRemoveOverviewPushButton"));
        mRemoveOverviewPushButton->setIcon(icon9);

        horizontalLayout_9->addWidget(mRemoveOverviewPushButton);

        mOverviewUpButton = new QPushButton(mOverviewsGroupBox);
        mOverviewUpButton->setObjectName(QString::fromUtf8("mOverviewUpButton"));
        mOverviewUpButton->setIcon(icon10);

        horizontalLayout_9->addWidget(mOverviewUpButton);

        mOverviewDownButton = new QPushButton(mOverviewsGroupBox);
        mOverviewDownButton->setObjectName(QString::fromUtf8("mOverviewDownButton"));
        mOverviewDownButton->setIcon(icon11);

        horizontalLayout_9->addWidget(mOverviewDownButton);


        verticalLayout->addLayout(horizontalLayout_9);

        mOverviewListWidget = new QListWidget(mOverviewsGroupBox);
        mOverviewListWidget->setObjectName(QString::fromUtf8("mOverviewListWidget"));
        sizePolicy.setHeightForWidth(mOverviewListWidget->sizePolicy().hasHeightForWidth());
        mOverviewListWidget->setSizePolicy(sizePolicy);
        mOverviewListWidget->setMaximumSize(QSize(16777215, 90));

        verticalLayout->addWidget(mOverviewListWidget);

        mOverviewCheckBox = new QgsCollapsibleGroupBoxBasic(mOverviewsGroupBox);
        mOverviewCheckBox->setObjectName(QString::fromUtf8("mOverviewCheckBox"));
        mOverviewCheckBox->setCheckable(true);
        mOverviewCheckBox->setChecked(true);
        mOverviewCheckBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composermapoverview")));
        mOverviewCheckBox->setProperty("collapsed", QVariant(false));
        gridLayout_8 = new QGridLayout(mOverviewCheckBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        mOverviewPositionComboBox = new QComboBox(mOverviewCheckBox);
        mOverviewPositionComboBox->setObjectName(QString::fromUtf8("mOverviewPositionComboBox"));

        gridLayout_8->addWidget(mOverviewPositionComboBox, 5, 1, 1, 1);

        mOverviewPositionLabel = new QLabel(mOverviewCheckBox);
        mOverviewPositionLabel->setObjectName(QString::fromUtf8("mOverviewPositionLabel"));

        gridLayout_8->addWidget(mOverviewPositionLabel, 5, 0, 1, 1);

        mOverviewFrameStyleButton = new QgsSymbolButton(mOverviewCheckBox);
        mOverviewFrameStyleButton->setObjectName(QString::fromUtf8("mOverviewFrameStyleButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mOverviewFrameStyleButton->sizePolicy().hasHeightForWidth());
        mOverviewFrameStyleButton->setSizePolicy(sizePolicy3);

        gridLayout_8->addWidget(mOverviewFrameStyleButton, 1, 1, 1, 1);

        mOverviewBlendModeComboBox = new QgsBlendModeComboBox(mOverviewCheckBox);
        mOverviewBlendModeComboBox->setObjectName(QString::fromUtf8("mOverviewBlendModeComboBox"));

        gridLayout_8->addWidget(mOverviewBlendModeComboBox, 2, 1, 1, 1);

        mOverviewInvertCheckbox = new QCheckBox(mOverviewCheckBox);
        mOverviewInvertCheckbox->setObjectName(QString::fromUtf8("mOverviewInvertCheckbox"));

        gridLayout_8->addWidget(mOverviewInvertCheckbox, 3, 0, 1, 2);

        mOverviewBlendModeLabel = new QLabel(mOverviewCheckBox);
        mOverviewBlendModeLabel->setObjectName(QString::fromUtf8("mOverviewBlendModeLabel"));

        gridLayout_8->addWidget(mOverviewBlendModeLabel, 2, 0, 1, 1);

        mOverviewFrameStyleLabel = new QLabel(mOverviewCheckBox);
        mOverviewFrameStyleLabel->setObjectName(QString::fromUtf8("mOverviewFrameStyleLabel"));

        gridLayout_8->addWidget(mOverviewFrameStyleLabel, 1, 0, 1, 1);

        mOverviewFrameMapLabel = new QLabel(mOverviewCheckBox);
        mOverviewFrameMapLabel->setObjectName(QString::fromUtf8("mOverviewFrameMapLabel"));

        gridLayout_8->addWidget(mOverviewFrameMapLabel, 0, 0, 1, 1);

        mOverviewCenterCheckbox = new QCheckBox(mOverviewCheckBox);
        mOverviewCenterCheckbox->setObjectName(QString::fromUtf8("mOverviewCenterCheckbox"));

        gridLayout_8->addWidget(mOverviewCenterCheckbox, 4, 0, 1, 2);

        mOverviewFrameMapComboBox = new QgsLayoutItemComboBox(mOverviewCheckBox);
        mOverviewFrameMapComboBox->setObjectName(QString::fromUtf8("mOverviewFrameMapComboBox"));

        gridLayout_8->addWidget(mOverviewFrameMapComboBox, 0, 1, 1, 1);

        mOverviewStackingLayerComboBox = new QgsMapLayerComboBox(mOverviewCheckBox);
        mOverviewStackingLayerComboBox->setObjectName(QString::fromUtf8("mOverviewStackingLayerComboBox"));
        sizePolicy2.setHeightForWidth(mOverviewStackingLayerComboBox->sizePolicy().hasHeightForWidth());
        mOverviewStackingLayerComboBox->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(mOverviewStackingLayerComboBox, 6, 1, 1, 1);

        label = new QLabel(mOverviewCheckBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_8->addWidget(label, 6, 0, 1, 1);


        verticalLayout->addWidget(mOverviewCheckBox);


        mainLayout->addWidget(mOverviewsGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

#ifndef QT_NO_SHORTCUT
        mScaleLabel->setBuddy(mScaleLineEdit);
        mYMinLabel->setBuddy(mYMinLineEdit);
        mXMaxLabel->setBuddy(mXMaxLineEdit);
        mXMinLabel->setBuddy(mXMinLineEdit);
        mYMaxLabel->setBuddy(mYMaxLineEdit);
        mStartDateTimeLabel->setBuddy(mStartDateTime);
        mEndDateTimeLabel->setBuddy(mEndDateTime);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(scrollArea, groupBox);
        QWidget::setTabOrder(groupBox, mScaleLineEdit);
        QWidget::setTabOrder(mScaleLineEdit, mScaleDDBtn);
        QWidget::setTabOrder(mScaleDDBtn, mMapRotationSpinBox);
        QWidget::setTabOrder(mMapRotationSpinBox, mMapRotationDDBtn);
        QWidget::setTabOrder(mMapRotationDDBtn, mCrsSelector);
        QWidget::setTabOrder(mCrsSelector, mDrawCanvasItemsCheckBox);
        QWidget::setTabOrder(mDrawCanvasItemsCheckBox, mFollowVisibilityPresetCheckBox);
        QWidget::setTabOrder(mFollowVisibilityPresetCheckBox, mFollowVisibilityPresetCombo);
        QWidget::setTabOrder(mFollowVisibilityPresetCombo, mStylePresetsDDBtn);
        QWidget::setTabOrder(mStylePresetsDDBtn, mKeepLayerListCheckBox);
        QWidget::setTabOrder(mKeepLayerListCheckBox, mLayerListFromPresetButton);
        QWidget::setTabOrder(mLayerListFromPresetButton, mLayersDDBtn);
        QWidget::setTabOrder(mLayersDDBtn, mKeepLayerStylesCheckBox);
        QWidget::setTabOrder(mKeepLayerStylesCheckBox, mExtentsCheckBox);
        QWidget::setTabOrder(mExtentsCheckBox, mXMinLineEdit);
        QWidget::setTabOrder(mXMinLineEdit, mXMinDDBtn);
        QWidget::setTabOrder(mXMinDDBtn, mYMinLineEdit);
        QWidget::setTabOrder(mYMinLineEdit, mYMinDDBtn);
        QWidget::setTabOrder(mYMinDDBtn, mXMaxLineEdit);
        QWidget::setTabOrder(mXMaxLineEdit, mXMaxDDBtn);
        QWidget::setTabOrder(mXMaxDDBtn, mYMaxLineEdit);
        QWidget::setTabOrder(mYMaxLineEdit, mYMaxDDBtn);
        QWidget::setTabOrder(mYMaxDDBtn, mAtlasCheckBox);
        QWidget::setTabOrder(mAtlasCheckBox, mAtlasMarginRadio);
        QWidget::setTabOrder(mAtlasMarginRadio, mAtlasMarginSpinBox);
        QWidget::setTabOrder(mAtlasMarginSpinBox, mAtlasMarginDDBtn);
        QWidget::setTabOrder(mAtlasMarginDDBtn, mAtlasPredefinedScaleRadio);
        QWidget::setTabOrder(mAtlasPredefinedScaleRadio, mAtlasFixedScaleRadio);
        QWidget::setTabOrder(mAtlasFixedScaleRadio, mGridGroupBox);
        QWidget::setTabOrder(mGridGroupBox, mAddGridPushButton);
        QWidget::setTabOrder(mAddGridPushButton, mRemoveGridPushButton);
        QWidget::setTabOrder(mRemoveGridPushButton, mGridUpButton);
        QWidget::setTabOrder(mGridUpButton, mGridDownButton);
        QWidget::setTabOrder(mGridDownButton, mGridListWidget);
        QWidget::setTabOrder(mGridListWidget, mGridPropertiesButton);
        QWidget::setTabOrder(mGridPropertiesButton, mGridPropertiesButton);
        QWidget::setTabOrder(mGridPropertiesButton, mOverviewsGroupBox);
        QWidget::setTabOrder(mOverviewsGroupBox, mAddOverviewPushButton);
        QWidget::setTabOrder(mAddOverviewPushButton, mRemoveOverviewPushButton);
        QWidget::setTabOrder(mRemoveOverviewPushButton, mOverviewUpButton);
        QWidget::setTabOrder(mOverviewUpButton, mOverviewDownButton);
        QWidget::setTabOrder(mOverviewDownButton, mOverviewListWidget);
        QWidget::setTabOrder(mOverviewListWidget, mOverviewCheckBox);
        QWidget::setTabOrder(mOverviewCheckBox, mOverviewFrameMapComboBox);
        QWidget::setTabOrder(mOverviewFrameMapComboBox, mOverviewFrameStyleButton);
        QWidget::setTabOrder(mOverviewFrameStyleButton, mOverviewBlendModeComboBox);
        QWidget::setTabOrder(mOverviewBlendModeComboBox, mOverviewInvertCheckbox);
        QWidget::setTabOrder(mOverviewInvertCheckbox, mOverviewCenterCheckbox);
        QWidget::setTabOrder(mOverviewCenterCheckbox, mOverviewPositionComboBox);
        QWidget::setTabOrder(mOverviewPositionComboBox, mOverviewStackingLayerComboBox);

        mDockToolbar->addAction(mActionUpdatePreview);
        mDockToolbar->addSeparator();
        mDockToolbar->addAction(mActionSetToCanvasExtent);
        mDockToolbar->addAction(mActionViewExtentInCanvas);
        mDockToolbar->addSeparator();
        mDockToolbar->addAction(mActionSetToCanvasScale);
        mDockToolbar->addAction(mActionViewScaleInCanvas);
        mDockToolbar->addSeparator();
        mDockToolbar->addAction(mActionMoveContent);
        mDockToolbar->addSeparator();
        mDockToolbar->addAction(mActionLabelSettings);
        mDockToolbar->addAction(mActionClipSettings);

        retranslateUi(QgsLayoutMapWidgetBase);

        QMetaObject::connectSlotsByName(QgsLayoutMapWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsLayoutMapWidgetBase)
    {
        QgsLayoutMapWidgetBase->setWindowTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Map Options", nullptr));
        mActionUpdatePreview->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Update Preview", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionUpdatePreview->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Update Map Preview", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSetToCanvasExtent->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Set to Map Canvas Extent", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSetToCanvasExtent->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Set Map Extent to Match Main Canvas Extent", nullptr));
#endif // QT_NO_TOOLTIP
        mActionViewExtentInCanvas->setText(QApplication::translate("QgsLayoutMapWidgetBase", "View Extent in Map Canvas", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionViewExtentInCanvas->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "View Current Map Extent in Main Canvas", nullptr));
#endif // QT_NO_TOOLTIP
        mActionMoveContent->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Move Map Content", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionMoveContent->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Interactively Edit Map Extent", nullptr));
#endif // QT_NO_TOOLTIP
        mActionViewScaleInCanvas->setText(QApplication::translate("QgsLayoutMapWidgetBase", "View Scale in Map Canvas", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionViewScaleInCanvas->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Set Main Canvas to Match Current Map Scale", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSetToCanvasScale->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Set to Map Canvas Scale", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSetToCanvasScale->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Set Map Scale to Match Main Canvas Scale", nullptr));
#endif // QT_NO_TOOLTIP
        mActionLabelSettings->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Label Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionLabelSettings->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Labeling Settings", nullptr));
#endif // QT_NO_TOOLTIP
        mActionClipSettings->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Clipping Settings", nullptr));
        mLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Map", nullptr));
        groupBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Main Properties", nullptr));
        mScaleLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Scale", nullptr));
        mScaleLineEdit->setInputMask(QString());
        mScaleDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mMapRotationSpinBox->setSuffix(QApplication::translate("QgsLayoutMapWidgetBase", " \302\260", nullptr));
        mMapRotationDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mMapRotationLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Map rotation", nullptr));
        mCrsLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "CRS", nullptr));
        mDrawCanvasItemsCheckBox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Draw map canvas items", nullptr));
        groupBox_2->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Layers", nullptr));
        mFollowVisibilityPresetCheckBox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Follow map theme", nullptr));
        mStylePresetsDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mKeepLayerListCheckBox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Lock layers", nullptr));
        mLayerListFromPresetButton->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mLayersDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mKeepLayerStylesCheckBox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Lock styles for layers", nullptr));
        mExtentsCheckBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Extents", nullptr));
        mYMinDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mXMaxDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mYMinLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Y min", nullptr));
        mYMaxDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mXMaxLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "X max", nullptr));
        mXMinDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mXMinLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "X min", nullptr));
        mYMaxLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Y max", nullptr));
        mTemporalCheckBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Temporal Range", nullptr));
        mStartDateTimeLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Start", nullptr));
        mStartDateTime->setDisplayFormat(QApplication::translate("QgsLayoutMapWidgetBase", "M/d/yyyy h:mm AP", nullptr));
        mStartDateTimeDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mEndDateTimeLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "End", nullptr));
        mEndDateTime->setDisplayFormat(QApplication::translate("QgsLayoutMapWidgetBase", "M/d/yyyy h:mm AP", nullptr));
        mEndDateTimeDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
        mAtlasCheckBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Controlled by Atlas", nullptr));
        mAtlasMarginRadio->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Margin around feature", nullptr));
        mAtlasMarginSpinBox->setSuffix(QApplication::translate("QgsLayoutMapWidgetBase", "%", nullptr));
        mAtlasMarginDDBtn->setText(QApplication::translate("QgsLayoutMapWidgetBase", "\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mAtlasPredefinedScaleRadio->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Use one of the predefined scales of the project where the atlas feature best fits.", nullptr));
#endif // QT_NO_TOOLTIP
        mAtlasPredefinedScaleRadio->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Predefined scale (best fit)", nullptr));
        mAtlasFixedScaleRadio->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Fixed scale", nullptr));
        mGridGroupBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Grids", nullptr));
#ifndef QT_NO_TOOLTIP
        mAddGridPushButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Add a new grid", nullptr));
#endif // QT_NO_TOOLTIP
        mAddGridPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mRemoveGridPushButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Remove selected grid", nullptr));
#endif // QT_NO_TOOLTIP
        mRemoveGridPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mGridUpButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Move selected grid up", nullptr));
#endif // QT_NO_TOOLTIP
        mGridUpButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mGridDownButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Move selected grid down", nullptr));
#endif // QT_NO_TOOLTIP
        mGridDownButton->setText(QString());
        mGridPropertiesButton->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Modify Grid\342\200\246", nullptr));
        mOverviewsGroupBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Overviews", nullptr));
#ifndef QT_NO_TOOLTIP
        mAddOverviewPushButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Add a new overview", nullptr));
#endif // QT_NO_TOOLTIP
        mAddOverviewPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mRemoveOverviewPushButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Remove selected overview", nullptr));
#endif // QT_NO_TOOLTIP
        mRemoveOverviewPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mOverviewUpButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Move selected overview up", nullptr));
#endif // QT_NO_TOOLTIP
        mOverviewUpButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mOverviewDownButton->setToolTip(QApplication::translate("QgsLayoutMapWidgetBase", "Move selected overview down", nullptr));
#endif // QT_NO_TOOLTIP
        mOverviewDownButton->setText(QString());
        mOverviewCheckBox->setTitle(QApplication::translate("QgsLayoutMapWidgetBase", "Draw overview", nullptr));
        mOverviewPositionLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Position", nullptr));
        mOverviewFrameStyleButton->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Change\342\200\246", nullptr));
        mOverviewInvertCheckbox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Invert overview", nullptr));
        mOverviewBlendModeLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Blending mode", nullptr));
        mOverviewFrameStyleLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Frame style", nullptr));
        mOverviewFrameMapLabel->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Map frame", nullptr));
        mOverviewCenterCheckbox->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Center on overview", nullptr));
        label->setText(QApplication::translate("QgsLayoutMapWidgetBase", "Stacking layer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsLayoutMapWidgetBase: public Ui_QgsLayoutMapWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSLAYOUTMAPWIDGETBASE_H
