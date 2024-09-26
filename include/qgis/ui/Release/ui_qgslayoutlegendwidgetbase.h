/********************************************************************************
** Form generated from reading UI file 'qgslayoutlegendwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSLAYOUTLEGENDWIDGETBASE_H
#define UI_QGSLAYOUTLEGENDWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qgscollapsiblegroupbox.h>
#include <qgslegendfilterbutton.h>
#include "qgsalignmentcombobox.h"
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"
#include "qgsfontbutton.h"
#include "qgslayertreeview.h"
#include "qgslayoutitemcombobox.h"
#include "qgspropertyoverridebutton.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsLayoutLegendWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_11;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *mainLayout;
    QgsCollapsibleGroupBoxBasic *mMainPropertiesColGroupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *mTitleLineEdit;
    QLabel *label;
    QLineEdit *mWrapCharLineEdit;
    QgsPropertyOverrideButton *mLegendTitleDDBtn;
    QCheckBox *mCheckboxResizeContents;
    QLabel *mMapLabel;
    QLabel *mTitleLabel;
    QgsLayoutItemComboBox *mMapComboBox;
    QgsAlignmentComboBox *mArrangementCombo;
    QLabel *label_15;
    QgsCollapsibleGroupBoxBasic *mLegendItemColGroupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *mCheckBoxAutoUpdate;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *mUpdateAllPushButton;
    QgsLayerTreeView *mItemTreeView;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *mMoveDownToolButton;
    QToolButton *mMoveUpToolButton;
    QToolButton *mAddGroupToolButton;
    QToolButton *mAddToolButton;
    QToolButton *mRemoveToolButton;
    QToolButton *mEditPushButton;
    QToolButton *mLayerExpressionButton;
    QToolButton *mCountToolButton;
    QSpacerItem *horizontalSpacer_4;
    QgsLegendFilterButton *mExpressionFilterButton;
    QCheckBox *mFilterByMapCheckBox;
    QCheckBox *mFilterLegendByAtlasCheckBox;
    QgsCollapsibleGroupBoxBasic *mFontsColGroupBox;
    QGridLayout *gridLayout_4;
    QgsFontButton *mLayerFontButton;
    QgsFontButton *mTitleFontButton;
    QLabel *label_25;
    QLabel *label_18_alignment;
    QgsColorButton *mFontColorButton;
    QLabel *label_26;
    QgsAlignmentComboBox *mItemAlignCombo;
    QLabel *label_28;
    QLabel *label_27;
    QLabel *label_19_alignment;
    QgsFontButton *mItemFontButton;
    QgsAlignmentComboBox *mTitleAlignCombo;
    QLabel *label_21;
    QLabel *label_20;
    QgsAlignmentComboBox *mSubgroupAlignCombo;
    QLabel *label_24;
    QLabel *label_23;
    QLabel *label_16;
    QgsAlignmentComboBox *mGroupAlignCombo;
    QLabel *label_22;
    QgsFontButton *mGroupFontButton;
    QLabel *label_29;
    QgsCollapsibleGroupBoxBasic *mColumnsColGroupBox;
    QGridLayout *gridLayout_3;
    QgsSpinBox *mColumnCountSpinBox;
    QLabel *label_2;
    QgsPropertyOverrideButton *mColumnsDDBtn;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *mEqualColumnWidthCheckBox;
    QCheckBox *mSplitLayerCheckBox;
    QgsCollapsibleGroupBoxBasic *mSymbolsColGroupBox;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QgsDoubleSpinBox *mSymbolWidthSpinBox;
    QLabel *label_4;
    QgsDoubleSpinBox *mSymbolHeightSpinBox;
    QgsCollapsibleGroupBoxBasic *mRasterStrokeGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_6;
    QgsColorButton *mRasterStrokeColorButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *mStrokeWidthLabel;
    QgsDoubleSpinBox *mRasterStrokeWidthSpinBox;
    QgsDoubleSpinBox *mMaxSymbolSizeSpinBox;
    QLabel *mMaxSymbolSizeLabel;
    QLabel *mMinSymbolSizeLabel;
    QgsDoubleSpinBox *mMinSymbolSizeSpinBox;
    QgsCollapsibleGroupBoxBasic *mSymbolsColGroupBox_2;
    QFormLayout *formLayout_5;
    QLabel *label_13;
    QgsDoubleSpinBox *mWmsLegendWidthSpinBox;
    QLabel *label_14;
    QgsDoubleSpinBox *mWmsLegendHeightSpinBox;
    QgsCollapsibleGroupBoxBasic *mSpacingColGroupBox;
    QGridLayout *gridLayout_5;
    QgsDoubleSpinBox *mSubgroupSideSpinBox;
    QgsDoubleSpinBox *mBoxSpaceSpinBox;
    QLabel *label_34;
    QgsDoubleSpinBox *mSpaceBelowSubgroupHeadingSpinBox;
    QgsDoubleSpinBox *mTitleSpaceBottomSpinBox;
    QgsDoubleSpinBox *mColumnSpaceSpinBox;
    QLabel *label_6;
    QgsDoubleSpinBox *mIconLabelSpaceSpinBox;
    QLabel *label_18;
    QLabel *label_30;
    QLabel *label_5;
    QLabel *label_36;
    QgsDoubleSpinBox *mLineSpacingSpinBox;
    QLabel *label_8;
    QLabel *label_33;
    QLabel *label_35;
    QLabel *label_32;
    QgsDoubleSpinBox *mGroupSpaceSpinBox;
    QgsDoubleSpinBox *mSymbolSpaceSpinBox;
    QLabel *label_37;
    QLabel *label_31;
    QgsDoubleSpinBox *mSpaceBelowGroupHeadingSpinBox;
    QgsDoubleSpinBox *mLayerSpaceSpinBox;
    QLabel *label_7;
    QgsDoubleSpinBox *mGroupSideSpinBox;
    QLabel *label_121;
    QLabel *label_31s;
    QLabel *label_19;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_38;
    QgsDoubleSpinBox *mSymbolSideSpaceSpinBox;

    void setupUi(QWidget *QgsLayoutLegendWidgetBase)
    {
        if (QgsLayoutLegendWidgetBase->objectName().isEmpty())
            QgsLayoutLegendWidgetBase->setObjectName(QString::fromUtf8("QgsLayoutLegendWidgetBase"));
        QgsLayoutLegendWidgetBase->resize(375, 995);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QgsLayoutLegendWidgetBase->sizePolicy().hasHeightForWidth());
        QgsLayoutLegendWidgetBase->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(QgsLayoutLegendWidgetBase);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(QgsLayoutLegendWidgetBase);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);
        label_11->setStyleSheet(QString::fromUtf8("padding: 2px; font-weight: bold; background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(label_11);

        scrollArea = new QgsScrollArea(QgsLayoutLegendWidgetBase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 425, 2042));
        mainLayout = new QVBoxLayout(scrollAreaWidgetContents);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mMainPropertiesColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mMainPropertiesColGroupBox->setObjectName(QString::fromUtf8("mMainPropertiesColGroupBox"));
        mMainPropertiesColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mMainPropertiesColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mMainPropertiesColGroupBox->setProperty("collapsed", QVariant(false));
        gridLayout_2 = new QGridLayout(mMainPropertiesColGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mTitleLineEdit = new QLineEdit(mMainPropertiesColGroupBox);
        mTitleLineEdit->setObjectName(QString::fromUtf8("mTitleLineEdit"));

        gridLayout_2->addWidget(mTitleLineEdit, 0, 1, 1, 1);

        label = new QLabel(mMainPropertiesColGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        mWrapCharLineEdit = new QLineEdit(mMainPropertiesColGroupBox);
        mWrapCharLineEdit->setObjectName(QString::fromUtf8("mWrapCharLineEdit"));
        mWrapCharLineEdit->setFrame(true);

        gridLayout_2->addWidget(mWrapCharLineEdit, 2, 1, 1, 2);

        mLegendTitleDDBtn = new QgsPropertyOverrideButton(mMainPropertiesColGroupBox);
        mLegendTitleDDBtn->setObjectName(QString::fromUtf8("mLegendTitleDDBtn"));

        gridLayout_2->addWidget(mLegendTitleDDBtn, 0, 2, 1, 1);

        mCheckboxResizeContents = new QCheckBox(mMainPropertiesColGroupBox);
        mCheckboxResizeContents->setObjectName(QString::fromUtf8("mCheckboxResizeContents"));

        gridLayout_2->addWidget(mCheckboxResizeContents, 4, 0, 1, 2);

        mMapLabel = new QLabel(mMainPropertiesColGroupBox);
        mMapLabel->setObjectName(QString::fromUtf8("mMapLabel"));

        gridLayout_2->addWidget(mMapLabel, 1, 0, 1, 1);

        mTitleLabel = new QLabel(mMainPropertiesColGroupBox);
        mTitleLabel->setObjectName(QString::fromUtf8("mTitleLabel"));

        gridLayout_2->addWidget(mTitleLabel, 0, 0, 1, 1);

        mMapComboBox = new QgsLayoutItemComboBox(mMainPropertiesColGroupBox);
        mMapComboBox->setObjectName(QString::fromUtf8("mMapComboBox"));

        gridLayout_2->addWidget(mMapComboBox, 1, 1, 1, 2);

        mArrangementCombo = new QgsAlignmentComboBox(mMainPropertiesColGroupBox);
        mArrangementCombo->setObjectName(QString::fromUtf8("mArrangementCombo"));

        gridLayout_2->addWidget(mArrangementCombo, 3, 1, 1, 2);

        label_15 = new QLabel(mMainPropertiesColGroupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 3, 0, 1, 1);


        mainLayout->addWidget(mMainPropertiesColGroupBox);

        mLegendItemColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mLegendItemColGroupBox->setObjectName(QString::fromUtf8("mLegendItemColGroupBox"));
        mLegendItemColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mLegendItemColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mLegendItemColGroupBox->setProperty("collapsed", QVariant(false));
        verticalLayout_2 = new QVBoxLayout(mLegendItemColGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mCheckBoxAutoUpdate = new QCheckBox(mLegendItemColGroupBox);
        mCheckBoxAutoUpdate->setObjectName(QString::fromUtf8("mCheckBoxAutoUpdate"));
        mCheckBoxAutoUpdate->setChecked(true);

        horizontalLayout->addWidget(mCheckBoxAutoUpdate);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        mUpdateAllPushButton = new QToolButton(mLegendItemColGroupBox);
        mUpdateAllPushButton->setObjectName(QString::fromUtf8("mUpdateAllPushButton"));

        horizontalLayout->addWidget(mUpdateAllPushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        mItemTreeView = new QgsLayerTreeView(mLegendItemColGroupBox);
        mItemTreeView->setObjectName(QString::fromUtf8("mItemTreeView"));
        mItemTreeView->setMinimumSize(QSize(0, 250));
        mItemTreeView->setSelectionMode(QAbstractItemView::ContiguousSelection);
        mItemTreeView->setHeaderHidden(true);
        mItemTreeView->header()->setVisible(false);

        verticalLayout_2->addWidget(mItemTreeView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mMoveDownToolButton = new QToolButton(mLegendItemColGroupBox);
        mMoveDownToolButton->setObjectName(QString::fromUtf8("mMoveDownToolButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mMoveDownToolButton->sizePolicy().hasHeightForWidth());
        mMoveDownToolButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionArrowDown.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mMoveDownToolButton->setIcon(icon);
        mMoveDownToolButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mMoveDownToolButton);

        mMoveUpToolButton = new QToolButton(mLegendItemColGroupBox);
        mMoveUpToolButton->setObjectName(QString::fromUtf8("mMoveUpToolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionArrowUp.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mMoveUpToolButton->setIcon(icon1);
        mMoveUpToolButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mMoveUpToolButton);

        mAddGroupToolButton = new QToolButton(mLegendItemColGroupBox);
        mAddGroupToolButton->setObjectName(QString::fromUtf8("mAddGroupToolButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionAddGroup.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mAddGroupToolButton->setIcon(icon2);
        mAddGroupToolButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mAddGroupToolButton);

        mAddToolButton = new QToolButton(mLegendItemColGroupBox);
        mAddToolButton->setObjectName(QString::fromUtf8("mAddToolButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/symbologyAdd.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mAddToolButton->setIcon(icon3);
        mAddToolButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mAddToolButton);

        mRemoveToolButton = new QToolButton(mLegendItemColGroupBox);
        mRemoveToolButton->setObjectName(QString::fromUtf8("mRemoveToolButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/symbologyRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mRemoveToolButton->setIcon(icon4);
        mRemoveToolButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mRemoveToolButton);

        mEditPushButton = new QToolButton(mLegendItemColGroupBox);
        mEditPushButton->setObjectName(QString::fromUtf8("mEditPushButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/symbologyEdit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mEditPushButton->setIcon(icon5);
        mEditPushButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mEditPushButton);

        mLayerExpressionButton = new QToolButton(mLegendItemColGroupBox);
        mLayerExpressionButton->setObjectName(QString::fromUtf8("mLayerExpressionButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/mIconExpression.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mLayerExpressionButton->setIcon(icon6);
        mLayerExpressionButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mLayerExpressionButton);

        mCountToolButton = new QToolButton(mLegendItemColGroupBox);
        mCountToolButton->setObjectName(QString::fromUtf8("mCountToolButton"));
        mCountToolButton->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/mActionSum.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mCountToolButton->setIcon(icon7);
        mCountToolButton->setIconSize(QSize(20, 20));
        mCountToolButton->setCheckable(true);

        horizontalLayout_2->addWidget(mCountToolButton);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        mExpressionFilterButton = new QgsLegendFilterButton(mLegendItemColGroupBox);
        mExpressionFilterButton->setObjectName(QString::fromUtf8("mExpressionFilterButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/mIconExpressionFilter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mExpressionFilterButton->setIcon(icon8);
        mExpressionFilterButton->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(mExpressionFilterButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        mFilterByMapCheckBox = new QCheckBox(mLegendItemColGroupBox);
        mFilterByMapCheckBox->setObjectName(QString::fromUtf8("mFilterByMapCheckBox"));

        verticalLayout_2->addWidget(mFilterByMapCheckBox);

        mFilterLegendByAtlasCheckBox = new QCheckBox(mLegendItemColGroupBox);
        mFilterLegendByAtlasCheckBox->setObjectName(QString::fromUtf8("mFilterLegendByAtlasCheckBox"));

        verticalLayout_2->addWidget(mFilterLegendByAtlasCheckBox);


        mainLayout->addWidget(mLegendItemColGroupBox);

        mFontsColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mFontsColGroupBox->setObjectName(QString::fromUtf8("mFontsColGroupBox"));
        mFontsColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mFontsColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mFontsColGroupBox->setProperty("collapsed", QVariant(true));
        gridLayout_4 = new QGridLayout(mFontsColGroupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mLayerFontButton = new QgsFontButton(mFontsColGroupBox);
        mLayerFontButton->setObjectName(QString::fromUtf8("mLayerFontButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(mLayerFontButton->sizePolicy().hasHeightForWidth());
        mLayerFontButton->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(mLayerFontButton, 7, 1, 1, 2);

        mTitleFontButton = new QgsFontButton(mFontsColGroupBox);
        mTitleFontButton->setObjectName(QString::fromUtf8("mTitleFontButton"));
        sizePolicy2.setHeightForWidth(mTitleFontButton->sizePolicy().hasHeightForWidth());
        mTitleFontButton->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(mTitleFontButton, 1, 1, 1, 2);

        label_25 = new QLabel(mFontsColGroupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 9, 0, 1, 3);

        label_18_alignment = new QLabel(mFontsColGroupBox);
        label_18_alignment->setObjectName(QString::fromUtf8("label_18_alignment"));

        gridLayout_4->addWidget(label_18_alignment, 5, 0, 1, 1);

        mFontColorButton = new QgsColorButton(mFontsColGroupBox);
        mFontColorButton->setObjectName(QString::fromUtf8("mFontColorButton"));
        sizePolicy2.setHeightForWidth(mFontColorButton->sizePolicy().hasHeightForWidth());
        mFontColorButton->setSizePolicy(sizePolicy2);
        mFontColorButton->setMinimumSize(QSize(120, 0));
        mFontColorButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(mFontColorButton, 12, 1, 1, 2);

        label_26 = new QLabel(mFontsColGroupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 10, 0, 1, 1);

        mItemAlignCombo = new QgsAlignmentComboBox(mFontsColGroupBox);
        mItemAlignCombo->setObjectName(QString::fromUtf8("mItemAlignCombo"));

        gridLayout_4->addWidget(mItemAlignCombo, 11, 1, 1, 2);

        label_28 = new QLabel(mFontsColGroupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_4->addWidget(label_28, 1, 0, 1, 1);

        label_27 = new QLabel(mFontsColGroupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 0, 0, 1, 3);

        label_19_alignment = new QLabel(mFontsColGroupBox);
        label_19_alignment->setObjectName(QString::fromUtf8("label_19_alignment"));

        gridLayout_4->addWidget(label_19_alignment, 8, 0, 1, 1);

        mItemFontButton = new QgsFontButton(mFontsColGroupBox);
        mItemFontButton->setObjectName(QString::fromUtf8("mItemFontButton"));
        sizePolicy3.setHeightForWidth(mItemFontButton->sizePolicy().hasHeightForWidth());
        mItemFontButton->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(mItemFontButton, 10, 1, 1, 2);

        mTitleAlignCombo = new QgsAlignmentComboBox(mFontsColGroupBox);
        mTitleAlignCombo->setObjectName(QString::fromUtf8("mTitleAlignCombo"));

        gridLayout_4->addWidget(mTitleAlignCombo, 2, 1, 1, 2);

        label_21 = new QLabel(mFontsColGroupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 3, 0, 1, 3);

        label_20 = new QLabel(mFontsColGroupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_4->addWidget(label_20, 11, 0, 1, 1);

        mSubgroupAlignCombo = new QgsAlignmentComboBox(mFontsColGroupBox);
        mSubgroupAlignCombo->setObjectName(QString::fromUtf8("mSubgroupAlignCombo"));

        gridLayout_4->addWidget(mSubgroupAlignCombo, 8, 1, 1, 2);

        label_24 = new QLabel(mFontsColGroupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 7, 0, 1, 1);

        label_23 = new QLabel(mFontsColGroupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 6, 0, 1, 3);

        label_16 = new QLabel(mFontsColGroupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 12, 0, 1, 1);

        mGroupAlignCombo = new QgsAlignmentComboBox(mFontsColGroupBox);
        mGroupAlignCombo->setObjectName(QString::fromUtf8("mGroupAlignCombo"));

        gridLayout_4->addWidget(mGroupAlignCombo, 5, 1, 1, 2);

        label_22 = new QLabel(mFontsColGroupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_4->addWidget(label_22, 4, 0, 1, 1);

        mGroupFontButton = new QgsFontButton(mFontsColGroupBox);
        mGroupFontButton->setObjectName(QString::fromUtf8("mGroupFontButton"));
        sizePolicy3.setHeightForWidth(mGroupFontButton->sizePolicy().hasHeightForWidth());
        mGroupFontButton->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(mGroupFontButton, 4, 1, 1, 2);

        label_29 = new QLabel(mFontsColGroupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_4->addWidget(label_29, 2, 0, 1, 1);


        mainLayout->addWidget(mFontsColGroupBox);

        mColumnsColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mColumnsColGroupBox->setObjectName(QString::fromUtf8("mColumnsColGroupBox"));
        mColumnsColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mColumnsColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mColumnsColGroupBox->setProperty("collapsed", QVariant(true));
        gridLayout_3 = new QGridLayout(mColumnsColGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mColumnCountSpinBox = new QgsSpinBox(mColumnsColGroupBox);
        mColumnCountSpinBox->setObjectName(QString::fromUtf8("mColumnCountSpinBox"));
        mColumnCountSpinBox->setMinimum(1);
        mColumnCountSpinBox->setMaximum(1000);

        gridLayout_3->addWidget(mColumnCountSpinBox, 0, 1, 1, 1);

        label_2 = new QLabel(mColumnsColGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        mColumnsDDBtn = new QgsPropertyOverrideButton(mColumnsColGroupBox);
        mColumnsDDBtn->setObjectName(QString::fromUtf8("mColumnsDDBtn"));

        gridLayout_3->addWidget(mColumnsDDBtn, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        mEqualColumnWidthCheckBox = new QCheckBox(mColumnsColGroupBox);
        mEqualColumnWidthCheckBox->setObjectName(QString::fromUtf8("mEqualColumnWidthCheckBox"));

        gridLayout_3->addWidget(mEqualColumnWidthCheckBox, 2, 0, 1, 4);

        mSplitLayerCheckBox = new QCheckBox(mColumnsColGroupBox);
        mSplitLayerCheckBox->setObjectName(QString::fromUtf8("mSplitLayerCheckBox"));

        gridLayout_3->addWidget(mSplitLayerCheckBox, 3, 0, 1, 4);


        mainLayout->addWidget(mColumnsColGroupBox);

        mSymbolsColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mSymbolsColGroupBox->setObjectName(QString::fromUtf8("mSymbolsColGroupBox"));
        mSymbolsColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mSymbolsColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mSymbolsColGroupBox->setProperty("collapsed", QVariant(true));
        formLayout_3 = new QFormLayout(mSymbolsColGroupBox);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(mSymbolsColGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_3);

        mSymbolWidthSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox);
        mSymbolWidthSpinBox->setObjectName(QString::fromUtf8("mSymbolWidthSpinBox"));
        mSymbolWidthSpinBox->setProperty("showClearButton", QVariant(false));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, mSymbolWidthSpinBox);

        label_4 = new QLabel(mSymbolsColGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_4);

        mSymbolHeightSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox);
        mSymbolHeightSpinBox->setObjectName(QString::fromUtf8("mSymbolHeightSpinBox"));
        mSymbolHeightSpinBox->setProperty("showClearButton", QVariant(false));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, mSymbolHeightSpinBox);

        mRasterStrokeGroupBox = new QgsCollapsibleGroupBoxBasic(mSymbolsColGroupBox);
        mRasterStrokeGroupBox->setObjectName(QString::fromUtf8("mRasterStrokeGroupBox"));
        mRasterStrokeGroupBox->setCheckable(true);
        mRasterStrokeGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mRasterStrokeGroupBox->setProperty("collapsed", QVariant(true));
        gridLayout = new QGridLayout(mRasterStrokeGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_17 = new QLabel(mRasterStrokeGroupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        mRasterStrokeColorButton = new QgsColorButton(mRasterStrokeGroupBox);
        mRasterStrokeColorButton->setObjectName(QString::fromUtf8("mRasterStrokeColorButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mRasterStrokeColorButton->sizePolicy().hasHeightForWidth());
        mRasterStrokeColorButton->setSizePolicy(sizePolicy4);
        mRasterStrokeColorButton->setMinimumSize(QSize(120, 0));
        mRasterStrokeColorButton->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(mRasterStrokeColorButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        mStrokeWidthLabel = new QLabel(mRasterStrokeGroupBox);
        mStrokeWidthLabel->setObjectName(QString::fromUtf8("mStrokeWidthLabel"));

        gridLayout->addWidget(mStrokeWidthLabel, 1, 0, 1, 1);

        mRasterStrokeWidthSpinBox = new QgsDoubleSpinBox(mRasterStrokeGroupBox);
        mRasterStrokeWidthSpinBox->setObjectName(QString::fromUtf8("mRasterStrokeWidthSpinBox"));
        sizePolicy3.setHeightForWidth(mRasterStrokeWidthSpinBox->sizePolicy().hasHeightForWidth());
        mRasterStrokeWidthSpinBox->setSizePolicy(sizePolicy3);
        mRasterStrokeWidthSpinBox->setSingleStep(0.100000000000000);
        mRasterStrokeWidthSpinBox->setProperty("showClearButton", QVariant(false));

        gridLayout->addWidget(mRasterStrokeWidthSpinBox, 1, 1, 1, 1);


        formLayout_3->setWidget(5, QFormLayout::SpanningRole, mRasterStrokeGroupBox);

        mMaxSymbolSizeSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox);
        mMaxSymbolSizeSpinBox->setObjectName(QString::fromUtf8("mMaxSymbolSizeSpinBox"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, mMaxSymbolSizeSpinBox);

        mMaxSymbolSizeLabel = new QLabel(mSymbolsColGroupBox);
        mMaxSymbolSizeLabel->setObjectName(QString::fromUtf8("mMaxSymbolSizeLabel"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, mMaxSymbolSizeLabel);

        mMinSymbolSizeLabel = new QLabel(mSymbolsColGroupBox);
        mMinSymbolSizeLabel->setObjectName(QString::fromUtf8("mMinSymbolSizeLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, mMinSymbolSizeLabel);

        mMinSymbolSizeSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox);
        mMinSymbolSizeSpinBox->setObjectName(QString::fromUtf8("mMinSymbolSizeSpinBox"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, mMinSymbolSizeSpinBox);


        mainLayout->addWidget(mSymbolsColGroupBox);

        mSymbolsColGroupBox_2 = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mSymbolsColGroupBox_2->setObjectName(QString::fromUtf8("mSymbolsColGroupBox_2"));
        mSymbolsColGroupBox_2->setFocusPolicy(Qt::StrongFocus);
        mSymbolsColGroupBox_2->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mSymbolsColGroupBox_2->setProperty("collapsed", QVariant(true));
        formLayout_5 = new QFormLayout(mSymbolsColGroupBox_2);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_5->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_13 = new QLabel(mSymbolsColGroupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_13);

        mWmsLegendWidthSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox_2);
        mWmsLegendWidthSpinBox->setObjectName(QString::fromUtf8("mWmsLegendWidthSpinBox"));
        mWmsLegendWidthSpinBox->setMaximum(9999.000000000000000);
        mWmsLegendWidthSpinBox->setProperty("showClearButton", QVariant(false));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, mWmsLegendWidthSpinBox);

        label_14 = new QLabel(mSymbolsColGroupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_14);

        mWmsLegendHeightSpinBox = new QgsDoubleSpinBox(mSymbolsColGroupBox_2);
        mWmsLegendHeightSpinBox->setObjectName(QString::fromUtf8("mWmsLegendHeightSpinBox"));
        mWmsLegendHeightSpinBox->setMaximum(9999.000000000000000);
        mWmsLegendHeightSpinBox->setProperty("showClearButton", QVariant(false));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, mWmsLegendHeightSpinBox);


        mainLayout->addWidget(mSymbolsColGroupBox_2);

        mSpacingColGroupBox = new QgsCollapsibleGroupBoxBasic(scrollAreaWidgetContents);
        mSpacingColGroupBox->setObjectName(QString::fromUtf8("mSpacingColGroupBox"));
        mSpacingColGroupBox->setFocusPolicy(Qt::StrongFocus);
        mSpacingColGroupBox->setProperty("syncGroup", QVariant(QString::fromUtf8("composeritem")));
        mSpacingColGroupBox->setProperty("collapsed", QVariant(true));
        gridLayout_5 = new QGridLayout(mSpacingColGroupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        mSubgroupSideSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mSubgroupSideSpinBox->setObjectName(QString::fromUtf8("mSubgroupSideSpinBox"));

        gridLayout_5->addWidget(mSubgroupSideSpinBox, 11, 1, 1, 1);

        mBoxSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mBoxSpaceSpinBox->setObjectName(QString::fromUtf8("mBoxSpaceSpinBox"));

        gridLayout_5->addWidget(mBoxSpaceSpinBox, 17, 1, 1, 1);

        label_34 = new QLabel(mSpacingColGroupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_5->addWidget(label_34, 12, 0, 1, 2);

        mSpaceBelowSubgroupHeadingSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mSpaceBelowSubgroupHeadingSpinBox->setObjectName(QString::fromUtf8("mSpaceBelowSubgroupHeadingSpinBox"));

        gridLayout_5->addWidget(mSpaceBelowSubgroupHeadingSpinBox, 10, 1, 1, 1);

        mTitleSpaceBottomSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mTitleSpaceBottomSpinBox->setObjectName(QString::fromUtf8("mTitleSpaceBottomSpinBox"));

        gridLayout_5->addWidget(mTitleSpaceBottomSpinBox, 1, 1, 1, 1);

        mColumnSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mColumnSpaceSpinBox->setObjectName(QString::fromUtf8("mColumnSpaceSpinBox"));

        gridLayout_5->addWidget(mColumnSpaceSpinBox, 18, 1, 1, 1);

        label_6 = new QLabel(mSpacingColGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 8, 0, 1, 1);

        mIconLabelSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mIconLabelSpaceSpinBox->setObjectName(QString::fromUtf8("mIconLabelSpaceSpinBox"));

        gridLayout_5->addWidget(mIconLabelSpaceSpinBox, 15, 1, 1, 1);

        label_18 = new QLabel(mSpacingColGroupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_5->addWidget(label_18, 5, 0, 1, 1);

        label_30 = new QLabel(mSpacingColGroupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_5->addWidget(label_30, 6, 0, 1, 1);

        label_5 = new QLabel(mSpacingColGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 3, 0, 1, 1);

        label_36 = new QLabel(mSpacingColGroupBox);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_5->addWidget(label_36, 9, 0, 1, 2);

        mLineSpacingSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mLineSpacingSpinBox->setObjectName(QString::fromUtf8("mLineSpacingSpinBox"));

        gridLayout_5->addWidget(mLineSpacingSpinBox, 19, 1, 1, 1);

        label_8 = new QLabel(mSpacingColGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 15, 0, 1, 1);

        label_33 = new QLabel(mSpacingColGroupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_5->addWidget(label_33, 16, 0, 1, 2);

        label_35 = new QLabel(mSpacingColGroupBox);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_5->addWidget(label_35, 4, 0, 1, 2);

        label_32 = new QLabel(mSpacingColGroupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_5->addWidget(label_32, 7, 0, 1, 2);

        mGroupSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mGroupSpaceSpinBox->setObjectName(QString::fromUtf8("mGroupSpaceSpinBox"));

        gridLayout_5->addWidget(mGroupSpaceSpinBox, 3, 1, 1, 1);

        mSymbolSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mSymbolSpaceSpinBox->setObjectName(QString::fromUtf8("mSymbolSpaceSpinBox"));

        gridLayout_5->addWidget(mSymbolSpaceSpinBox, 14, 1, 1, 1);

        label_37 = new QLabel(mSpacingColGroupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_5->addWidget(label_37, 11, 0, 1, 1);

        label_31 = new QLabel(mSpacingColGroupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_5->addWidget(label_31, 2, 0, 1, 2);

        mSpaceBelowGroupHeadingSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mSpaceBelowGroupHeadingSpinBox->setObjectName(QString::fromUtf8("mSpaceBelowGroupHeadingSpinBox"));

        gridLayout_5->addWidget(mSpaceBelowGroupHeadingSpinBox, 5, 1, 1, 1);

        mLayerSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mLayerSpaceSpinBox->setObjectName(QString::fromUtf8("mLayerSpaceSpinBox"));

        gridLayout_5->addWidget(mLayerSpaceSpinBox, 8, 1, 1, 1);

        label_7 = new QLabel(mSpacingColGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 14, 0, 1, 1);

        mGroupSideSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mGroupSideSpinBox->setObjectName(QString::fromUtf8("mGroupSideSpinBox"));

        gridLayout_5->addWidget(mGroupSideSpinBox, 6, 1, 1, 1);

        label_121 = new QLabel(mSpacingColGroupBox);
        label_121->setObjectName(QString::fromUtf8("label_121"));

        gridLayout_5->addWidget(label_121, 19, 0, 1, 1);

        label_31s = new QLabel(mSpacingColGroupBox);
        label_31s->setObjectName(QString::fromUtf8("label_31s"));

        gridLayout_5->addWidget(label_31s, 0, 0, 1, 2);

        label_19 = new QLabel(mSpacingColGroupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_5->addWidget(label_19, 10, 0, 1, 1);

        label_9 = new QLabel(mSpacingColGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 17, 0, 1, 1);

        label_12 = new QLabel(mSpacingColGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 18, 0, 1, 1);

        label_10 = new QLabel(mSpacingColGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 1, 0, 1, 1);

        label_38 = new QLabel(mSpacingColGroupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_5->addWidget(label_38, 13, 0, 1, 1);

        mSymbolSideSpaceSpinBox = new QgsDoubleSpinBox(mSpacingColGroupBox);
        mSymbolSideSpaceSpinBox->setObjectName(QString::fromUtf8("mSymbolSideSpaceSpinBox"));

        gridLayout_5->addWidget(mSymbolSideSpaceSpinBox, 13, 1, 1, 1);


        mainLayout->addWidget(mSpacingColGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

#ifndef QT_NO_SHORTCUT
        mTitleLabel->setBuddy(mTitleLineEdit);
        mStrokeWidthLabel->setBuddy(mRasterStrokeWidthSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(scrollArea, mMainPropertiesColGroupBox);
        QWidget::setTabOrder(mMainPropertiesColGroupBox, mTitleLineEdit);
        QWidget::setTabOrder(mTitleLineEdit, mLegendTitleDDBtn);
        QWidget::setTabOrder(mLegendTitleDDBtn, mMapComboBox);
        QWidget::setTabOrder(mMapComboBox, mWrapCharLineEdit);
        QWidget::setTabOrder(mWrapCharLineEdit, mArrangementCombo);
        QWidget::setTabOrder(mArrangementCombo, mCheckboxResizeContents);
        QWidget::setTabOrder(mCheckboxResizeContents, mLegendItemColGroupBox);
        QWidget::setTabOrder(mLegendItemColGroupBox, mCheckBoxAutoUpdate);
        QWidget::setTabOrder(mCheckBoxAutoUpdate, mUpdateAllPushButton);
        QWidget::setTabOrder(mUpdateAllPushButton, mItemTreeView);
        QWidget::setTabOrder(mItemTreeView, mMoveDownToolButton);
        QWidget::setTabOrder(mMoveDownToolButton, mMoveUpToolButton);
        QWidget::setTabOrder(mMoveUpToolButton, mAddGroupToolButton);
        QWidget::setTabOrder(mAddGroupToolButton, mAddToolButton);
        QWidget::setTabOrder(mAddToolButton, mRemoveToolButton);
        QWidget::setTabOrder(mRemoveToolButton, mEditPushButton);
        QWidget::setTabOrder(mEditPushButton, mCountToolButton);
        QWidget::setTabOrder(mCountToolButton, mExpressionFilterButton);
        QWidget::setTabOrder(mExpressionFilterButton, mFilterByMapCheckBox);
        QWidget::setTabOrder(mFilterByMapCheckBox, mFilterLegendByAtlasCheckBox);
        QWidget::setTabOrder(mFilterLegendByAtlasCheckBox, mFontsColGroupBox);
        QWidget::setTabOrder(mFontsColGroupBox, mTitleFontButton);
        QWidget::setTabOrder(mTitleFontButton, mTitleAlignCombo);
        QWidget::setTabOrder(mTitleAlignCombo, mGroupFontButton);
        QWidget::setTabOrder(mGroupFontButton, mGroupAlignCombo);
        QWidget::setTabOrder(mGroupAlignCombo, mLayerFontButton);
        QWidget::setTabOrder(mLayerFontButton, mSubgroupAlignCombo);
        QWidget::setTabOrder(mSubgroupAlignCombo, mItemFontButton);
        QWidget::setTabOrder(mItemFontButton, mItemAlignCombo);
        QWidget::setTabOrder(mItemAlignCombo, mFontColorButton);
        QWidget::setTabOrder(mFontColorButton, mColumnsColGroupBox);
        QWidget::setTabOrder(mColumnsColGroupBox, mColumnCountSpinBox);
        QWidget::setTabOrder(mColumnCountSpinBox, mColumnsDDBtn);
        QWidget::setTabOrder(mColumnsDDBtn, mEqualColumnWidthCheckBox);
        QWidget::setTabOrder(mEqualColumnWidthCheckBox, mSplitLayerCheckBox);
        QWidget::setTabOrder(mSplitLayerCheckBox, mSymbolsColGroupBox);
        QWidget::setTabOrder(mSymbolsColGroupBox, mSymbolWidthSpinBox);
        QWidget::setTabOrder(mSymbolWidthSpinBox, mSymbolHeightSpinBox);
        QWidget::setTabOrder(mSymbolHeightSpinBox, mRasterStrokeGroupBox);
        QWidget::setTabOrder(mRasterStrokeGroupBox, mRasterStrokeColorButton);
        QWidget::setTabOrder(mRasterStrokeColorButton, mRasterStrokeWidthSpinBox);
        QWidget::setTabOrder(mRasterStrokeWidthSpinBox, mSymbolsColGroupBox_2);
        QWidget::setTabOrder(mSymbolsColGroupBox_2, mWmsLegendWidthSpinBox);
        QWidget::setTabOrder(mWmsLegendWidthSpinBox, mWmsLegendHeightSpinBox);
        QWidget::setTabOrder(mWmsLegendHeightSpinBox, mSpacingColGroupBox);
        QWidget::setTabOrder(mSpacingColGroupBox, mTitleSpaceBottomSpinBox);
        QWidget::setTabOrder(mTitleSpaceBottomSpinBox, mGroupSpaceSpinBox);
        QWidget::setTabOrder(mGroupSpaceSpinBox, mSpaceBelowGroupHeadingSpinBox);
        QWidget::setTabOrder(mSpaceBelowGroupHeadingSpinBox, mGroupSideSpinBox);
        QWidget::setTabOrder(mGroupSideSpinBox, mLayerSpaceSpinBox);
        QWidget::setTabOrder(mLayerSpaceSpinBox, mSpaceBelowSubgroupHeadingSpinBox);
        QWidget::setTabOrder(mSpaceBelowSubgroupHeadingSpinBox, mSubgroupSideSpinBox);
        QWidget::setTabOrder(mSubgroupSideSpinBox, mSymbolSideSpaceSpinBox);
        QWidget::setTabOrder(mSymbolSideSpaceSpinBox, mSymbolSpaceSpinBox);
        QWidget::setTabOrder(mSymbolSpaceSpinBox, mIconLabelSpaceSpinBox);
        QWidget::setTabOrder(mIconLabelSpaceSpinBox, mBoxSpaceSpinBox);
        QWidget::setTabOrder(mBoxSpaceSpinBox, mColumnSpaceSpinBox);
        QWidget::setTabOrder(mColumnSpaceSpinBox, mLineSpacingSpinBox);
        QWidget::setTabOrder(mLineSpacingSpinBox, mLayerExpressionButton);

        retranslateUi(QgsLayoutLegendWidgetBase);

        QMetaObject::connectSlotsByName(QgsLayoutLegendWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsLayoutLegendWidgetBase)
    {
        QgsLayoutLegendWidgetBase->setWindowTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Legend Options", nullptr));
        label_11->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Legend", nullptr));
        mMainPropertiesColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Main Properties", nullptr));
        label->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Wrap text on", nullptr));
        mLegendTitleDDBtn->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "\342\200\246", nullptr));
        mCheckboxResizeContents->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Resize to fit contents", nullptr));
        mMapLabel->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Map", nullptr));
        mTitleLabel->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "&Title", nullptr));
        label_15->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Arrangement", nullptr));
        mLegendItemColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Legend Items", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckBoxAutoUpdate->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Keeps the legend contents synchronized with the main application legend. Customization is not possible and must be done in the main application.", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckBoxAutoUpdate->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Auto update", nullptr));
#ifndef QT_NO_TOOLTIP
        mUpdateAllPushButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Update whole legend. Layers are added/removed according to main application legend. User defined labels will be deleted.", nullptr));
#endif // QT_NO_TOOLTIP
        mUpdateAllPushButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Update All", nullptr));
#ifndef QT_NO_TOOLTIP
        mMoveDownToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Move item down", nullptr));
#endif // QT_NO_TOOLTIP
        mMoveDownToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mMoveUpToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Move item up", nullptr));
#endif // QT_NO_TOOLTIP
        mMoveUpToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mAddGroupToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Add group", nullptr));
#endif // QT_NO_TOOLTIP
        mAddGroupToolButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mAddToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Add layer(s) to legend", nullptr));
#endif // QT_NO_TOOLTIP
        mAddToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mRemoveToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Remove selected item(s) from legend", nullptr));
#endif // QT_NO_TOOLTIP
        mRemoveToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mEditPushButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Edit selected item properties", nullptr));
#endif // QT_NO_TOOLTIP
        mEditPushButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mLayerExpressionButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", " Add an expression to the vector layer and each child symbol's label", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        mCountToolButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Show feature count for each class of vector layer.", nullptr));
#endif // QT_NO_TOOLTIP
        mCountToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mExpressionFilterButton->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Filter expression", nullptr));
#endif // QT_NO_TOOLTIP
        mExpressionFilterButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        mFilterByMapCheckBox->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Filter out legend elements that lie outside the linked map item.", nullptr));
#endif // QT_NO_TOOLTIP
        mFilterByMapCheckBox->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Only show items inside linked map", nullptr));
#ifndef QT_NO_TOOLTIP
        mFilterLegendByAtlasCheckBox->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Filter out legend elements that lie outside the current atlas feature.", nullptr));
#endif // QT_NO_TOOLTIP
        mFilterLegendByAtlasCheckBox->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Only show items inside current atlas feature", nullptr));
        mFontsColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Fonts and Text Formatting", nullptr));
        mLayerFontButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Subgroup font", nullptr));
        mTitleFontButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Title font", nullptr));
        label_25->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Item Labels</b>", nullptr));
        label_18_alignment->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Alignment", nullptr));
        mFontColorButton->setText(QString());
        label_26->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Font", nullptr));
        label_28->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Font", nullptr));
        label_27->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Legend Title</b>", nullptr));
        label_19_alignment->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Alignment", nullptr));
        mItemFontButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Item font", nullptr));
        label_21->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Group Headings</b>", nullptr));
        label_20->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Alignment", nullptr));
        label_24->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Font", nullptr));
        label_23->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Subgroup Headings</b>", nullptr));
        label_16->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Font color", nullptr));
        label_22->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Font", nullptr));
        mGroupFontButton->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Group font", nullptr));
        label_29->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Alignment", nullptr));
        mColumnsColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Columns", nullptr));
        mColumnCountSpinBox->setPrefix(QString());
        label_2->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Count", nullptr));
        mColumnsDDBtn->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "\342\200\246", nullptr));
        mEqualColumnWidthCheckBox->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Equal column widths", nullptr));
#ifndef QT_NO_TOOLTIP
        mSplitLayerCheckBox->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Allow splitting layer items into multiple columns.", nullptr));
#endif // QT_NO_TOOLTIP
        mSplitLayerCheckBox->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Split layers", nullptr));
        mSymbolsColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Symbol", nullptr));
        label_3->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Symbol width", nullptr));
        mSymbolWidthSpinBox->setPrefix(QString());
        mSymbolWidthSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        label_4->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Symbol height", nullptr));
        mSymbolHeightSpinBox->setPrefix(QString());
        mSymbolHeightSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mRasterStrokeGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Draw stroke for raster symbols", nullptr));
        label_17->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Stroke color", nullptr));
        mRasterStrokeColorButton->setText(QString());
        mStrokeWidthLabel->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Thickness", nullptr));
        mRasterStrokeWidthSpinBox->setSpecialValueText(QApplication::translate("QgsLayoutLegendWidgetBase", "Hairline", nullptr));
        mRasterStrokeWidthSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mMaxSymbolSizeSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", "mm", nullptr));
        mMaxSymbolSizeLabel->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Max symbol size", nullptr));
        mMinSymbolSizeLabel->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Min symbol size", nullptr));
        mMinSymbolSizeSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", "mm", nullptr));
        mSymbolsColGroupBox_2->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "WMS LegendGraphic", nullptr));
        label_13->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Legend width", nullptr));
        mWmsLegendWidthSpinBox->setPrefix(QString());
        mWmsLegendWidthSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        label_14->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Legend height", nullptr));
        mWmsLegendHeightSpinBox->setPrefix(QString());
        mWmsLegendHeightSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mSpacingColGroupBox->setTitle(QApplication::translate("QgsLayoutLegendWidgetBase", "Spacing", nullptr));
        mSubgroupSideSpinBox->setPrefix(QString());
        mSubgroupSideSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mBoxSpaceSpinBox->setPrefix(QString());
        mBoxSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        label_34->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Legend Items</b>", nullptr));
        mSpaceBelowSubgroupHeadingSpinBox->setPrefix(QString());
        mSpaceBelowSubgroupHeadingSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        mTitleSpaceBottomSpinBox->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space below title.", nullptr));
#endif // QT_NO_TOOLTIP
        mTitleSpaceBottomSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mColumnSpaceSpinBox->setPrefix(QString());
        mColumnSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using subgroup style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Above subgroup", nullptr));
        mIconLabelSpaceSpinBox->setPrefix(QString());
        mIconLabelSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        label_18->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using group style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_18->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Below heading", nullptr));
#ifndef QT_NO_TOOLTIP
        label_30->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using group style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_30->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Side of heading", nullptr));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using group style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Above group", nullptr));
        label_36->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Subgroup Headings</b>", nullptr));
        mLineSpacingSpinBox->setPrefix(QString());
        mLineSpacingSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space between symbol icon and symbol label (symbol label left margin).", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Symbol label space", nullptr));
        label_33->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>General</b>", nullptr));
        label_35->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Group Headings</b>", nullptr));
        label_32->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Subgroups</b>", nullptr));
        mGroupSpaceSpinBox->setPrefix(QString());
        mGroupSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mSymbolSpaceSpinBox->setPrefix(QString());
        mSymbolSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        label_37->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using group style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_37->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Side of heading", nullptr));
        label_31->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Groups</b>", nullptr));
        mSpaceBelowGroupHeadingSpinBox->setPrefix(QString());
        mSpaceBelowGroupHeadingSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        mLayerSpaceSpinBox->setPrefix(QString());
        mLayerSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above symbol and symbol label.", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Space between symbols", nullptr));
        mGroupSideSpinBox->setPrefix(QString());
        mGroupSideSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
        label_121->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Line space", nullptr));
        label_31s->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "<b>Legend Title</b>", nullptr));
#ifndef QT_NO_TOOLTIP
        label_19->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above text using group style.", nullptr));
#endif // QT_NO_TOOLTIP
        label_19->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Below heading", nullptr));
        label_9->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Box space", nullptr));
        label_12->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Column space", nullptr));
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space below title.", nullptr));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Space below", nullptr));
#ifndef QT_NO_TOOLTIP
        label_38->setToolTip(QApplication::translate("QgsLayoutLegendWidgetBase", "Space above symbol and symbol label.", nullptr));
#endif // QT_NO_TOOLTIP
        label_38->setText(QApplication::translate("QgsLayoutLegendWidgetBase", "Space before side of symbol", nullptr));
        mSymbolSideSpaceSpinBox->setPrefix(QString());
        mSymbolSideSpaceSpinBox->setSuffix(QApplication::translate("QgsLayoutLegendWidgetBase", " mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsLayoutLegendWidgetBase: public Ui_QgsLayoutLegendWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSLAYOUTLEGENDWIDGETBASE_H
