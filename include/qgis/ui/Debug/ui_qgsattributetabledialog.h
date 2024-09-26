/********************************************************************************
** Form generated from reading UI file 'qgsattributetabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSATTRIBUTETABLEDIALOG_H
#define UI_QGSATTRIBUTETABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include "qgsdualview.h"
#include "qgsfeaturefilterwidget_p.h"
#include "qgsfieldcombobox.h"
#include "qgsfieldexpressionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAttributeTableDialog
{
public:
    QAction *mActionSearchForm;
    QAction *mActionToggleEditing;
    QAction *mActionToggleMultiEdit;
    QAction *mActionSaveEdits;
    QAction *mActionReload;
    QAction *mActionAddFeature;
    QAction *mActionDeleteSelected;
    QAction *mActionExpressionSelect;
    QAction *mActionSelectAll;
    QAction *mActionInvertSelection;
    QAction *mActionRemoveSelection;
    QAction *mActionSelectedToTop;
    QAction *mActionPanMapToSelectedRows;
    QAction *mActionZoomMapToSelectedRows;
    QAction *mActionCutSelectedRows;
    QAction *mActionCopySelectedRows;
    QAction *mActionPasteFeatures;
    QAction *mActionRemoveAttribute;
    QAction *mActionAddAttribute;
    QAction *mActionOpenFieldCalculator;
    QAction *mActionSetStyles;
    QAction *mActionDockUndock;
    QAction *mActionOrganizeColumns;
    QAction *mActionAddFeatureViaAttributeTable;
    QAction *mActionAddFeatureViaAttributeForm;
    QGridLayout *gridLayout;
    QgsDualView *mMainView;
    QFrame *mUpdateExpressionBox;
    QHBoxLayout *horizontalLayout_3;
    QgsFieldComboBox *mFieldCombo;
    QLabel *label;
    QgsFieldExpressionWidget *mUpdateExpressionText;
    QToolButton *mRunFieldCalc;
    QToolButton *mRunFieldCalcSelected;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *horizontalLayout_2;
    QgsFeatureFilterWidget *mFeatureFilterWidget;
    QToolButton *mAttributeViewButton;
    QToolButton *mTableViewButton;
    QToolBar *mToolbar;
    QButtonGroup *mMainViewButtonGroup;

    void setupUi(QDialog *QgsAttributeTableDialog)
    {
        if (QgsAttributeTableDialog->objectName().isEmpty())
            QgsAttributeTableDialog->setObjectName(QString::fromUtf8("QgsAttributeTableDialog"));
        QgsAttributeTableDialog->resize(1054, 570);
        mActionSearchForm = new QAction(QgsAttributeTableDialog);
        mActionSearchForm->setObjectName(QString::fromUtf8("mActionSearchForm"));
        mActionSearchForm->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionFilter2.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSearchForm->setIcon(icon);
        mActionToggleEditing = new QAction(QgsAttributeTableDialog);
        mActionToggleEditing->setObjectName(QString::fromUtf8("mActionToggleEditing"));
        mActionToggleEditing->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionToggleEditing.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionToggleEditing->setIcon(icon1);
        mActionToggleMultiEdit = new QAction(QgsAttributeTableDialog);
        mActionToggleMultiEdit->setObjectName(QString::fromUtf8("mActionToggleMultiEdit"));
        mActionToggleMultiEdit->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionMultiEdit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionToggleMultiEdit->setIcon(icon2);
        mActionSaveEdits = new QAction(QgsAttributeTableDialog);
        mActionSaveEdits->setObjectName(QString::fromUtf8("mActionSaveEdits"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionSaveAllEdits.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSaveEdits->setIcon(icon3);
        mActionReload = new QAction(QgsAttributeTableDialog);
        mActionReload->setObjectName(QString::fromUtf8("mActionReload"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionReload->setIcon(icon4);
        mActionAddFeature = new QAction(QgsAttributeTableDialog);
        mActionAddFeature->setObjectName(QString::fromUtf8("mActionAddFeature"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionNewTableRow.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAddFeature->setIcon(icon5);
        mActionDeleteSelected = new QAction(QgsAttributeTableDialog);
        mActionDeleteSelected->setObjectName(QString::fromUtf8("mActionDeleteSelected"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteSelectedFeatures.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDeleteSelected->setIcon(icon6);
        mActionExpressionSelect = new QAction(QgsAttributeTableDialog);
        mActionExpressionSelect->setObjectName(QString::fromUtf8("mActionExpressionSelect"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/themes/default/mIconExpressionSelect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionExpressionSelect->setIcon(icon7);
        mActionSelectAll = new QAction(QgsAttributeTableDialog);
        mActionSelectAll->setObjectName(QString::fromUtf8("mActionSelectAll"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/themes/default/mActionSelectAll.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectAll->setIcon(icon8);
        mActionInvertSelection = new QAction(QgsAttributeTableDialog);
        mActionInvertSelection->setObjectName(QString::fromUtf8("mActionInvertSelection"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/themes/default/mActionInvertSelection.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionInvertSelection->setIcon(icon9);
        mActionRemoveSelection = new QAction(QgsAttributeTableDialog);
        mActionRemoveSelection->setObjectName(QString::fromUtf8("mActionRemoveSelection"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/themes/default/mActionDeselectActiveLayer.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRemoveSelection->setIcon(icon10);
        mActionSelectedToTop = new QAction(QgsAttributeTableDialog);
        mActionSelectedToTop->setObjectName(QString::fromUtf8("mActionSelectedToTop"));
        mActionSelectedToTop->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/themes/default/mActionSelectedToTop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSelectedToTop->setIcon(icon11);
        mActionPanMapToSelectedRows = new QAction(QgsAttributeTableDialog);
        mActionPanMapToSelectedRows->setObjectName(QString::fromUtf8("mActionPanMapToSelectedRows"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/themes/default/mActionPanToSelected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPanMapToSelectedRows->setIcon(icon12);
        mActionZoomMapToSelectedRows = new QAction(QgsAttributeTableDialog);
        mActionZoomMapToSelectedRows->setObjectName(QString::fromUtf8("mActionZoomMapToSelectedRows"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/themes/default/mActionZoomToSelected.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionZoomMapToSelectedRows->setIcon(icon13);
        mActionCutSelectedRows = new QAction(QgsAttributeTableDialog);
        mActionCutSelectedRows->setObjectName(QString::fromUtf8("mActionCutSelectedRows"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCut.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionCutSelectedRows->setIcon(icon14);
        mActionCopySelectedRows = new QAction(QgsAttributeTableDialog);
        mActionCopySelectedRows->setObjectName(QString::fromUtf8("mActionCopySelectedRows"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionCopySelectedRows->setIcon(icon15);
        mActionPasteFeatures = new QAction(QgsAttributeTableDialog);
        mActionPasteFeatures->setObjectName(QString::fromUtf8("mActionPasteFeatures"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/themes/default/mActionEditPaste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionPasteFeatures->setIcon(icon16);
        mActionRemoveAttribute = new QAction(QgsAttributeTableDialog);
        mActionRemoveAttribute->setObjectName(QString::fromUtf8("mActionRemoveAttribute"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteAttribute.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionRemoveAttribute->setIcon(icon17);
        mActionAddAttribute = new QAction(QgsAttributeTableDialog);
        mActionAddAttribute->setObjectName(QString::fromUtf8("mActionAddAttribute"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/themes/default/mActionNewAttribute.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAddAttribute->setIcon(icon18);
        mActionOpenFieldCalculator = new QAction(QgsAttributeTableDialog);
        mActionOpenFieldCalculator->setObjectName(QString::fromUtf8("mActionOpenFieldCalculator"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/themes/default/mActionCalculateField.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionOpenFieldCalculator->setIcon(icon19);
        mActionSetStyles = new QAction(QgsAttributeTableDialog);
        mActionSetStyles->setObjectName(QString::fromUtf8("mActionSetStyles"));
        mActionSetStyles->setCheckable(true);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/themes/default/mActionConditionalFormatting.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionSetStyles->setIcon(icon20);
        mActionDockUndock = new QAction(QgsAttributeTableDialog);
        mActionDockUndock->setObjectName(QString::fromUtf8("mActionDockUndock"));
        mActionDockUndock->setCheckable(true);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/images/themes/default/mDockify.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionDockUndock->setIcon(icon21);
        mActionOrganizeColumns = new QAction(QgsAttributeTableDialog);
        mActionOrganizeColumns->setObjectName(QString::fromUtf8("mActionOrganizeColumns"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/images/themes/default/mActionEditTable.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionOrganizeColumns->setIcon(icon22);
        mActionAddFeatureViaAttributeTable = new QAction(QgsAttributeTableDialog);
        mActionAddFeatureViaAttributeTable->setObjectName(QString::fromUtf8("mActionAddFeatureViaAttributeTable"));
        mActionAddFeatureViaAttributeTable->setIcon(icon5);
        mActionAddFeatureViaAttributeForm = new QAction(QgsAttributeTableDialog);
        mActionAddFeatureViaAttributeForm->setObjectName(QString::fromUtf8("mActionAddFeatureViaAttributeForm"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/images/themes/default/mIconFormSelect.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mActionAddFeatureViaAttributeForm->setIcon(icon23);
        gridLayout = new QGridLayout(QgsAttributeTableDialog);
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mMainView = new QgsDualView(QgsAttributeTableDialog);
        mMainView->setObjectName(QString::fromUtf8("mMainView"));

        gridLayout->addWidget(mMainView, 6, 0, 1, 1);

        mUpdateExpressionBox = new QFrame(QgsAttributeTableDialog);
        mUpdateExpressionBox->setObjectName(QString::fromUtf8("mUpdateExpressionBox"));
        horizontalLayout_3 = new QHBoxLayout(mUpdateExpressionBox);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, 1, 0, 3);
        mFieldCombo = new QgsFieldComboBox(mUpdateExpressionBox);
        mFieldCombo->setObjectName(QString::fromUtf8("mFieldCombo"));

        horizontalLayout_3->addWidget(mFieldCombo);

        label = new QLabel(mUpdateExpressionBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label);

        mUpdateExpressionText = new QgsFieldExpressionWidget(mUpdateExpressionBox);
        mUpdateExpressionText->setObjectName(QString::fromUtf8("mUpdateExpressionText"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mUpdateExpressionText->sizePolicy().hasHeightForWidth());
        mUpdateExpressionText->setSizePolicy(sizePolicy1);
        mUpdateExpressionText->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout_3->addWidget(mUpdateExpressionText);

        mRunFieldCalc = new QToolButton(mUpdateExpressionBox);
        mRunFieldCalc->setObjectName(QString::fromUtf8("mRunFieldCalc"));

        horizontalLayout_3->addWidget(mRunFieldCalc);

        mRunFieldCalcSelected = new QToolButton(mUpdateExpressionBox);
        mRunFieldCalcSelected->setObjectName(QString::fromUtf8("mRunFieldCalcSelected"));

        horizontalLayout_3->addWidget(mRunFieldCalcSelected);


        gridLayout->addWidget(mUpdateExpressionBox, 5, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mFeatureFilterWidget = new QgsFeatureFilterWidget(QgsAttributeTableDialog);
        mFeatureFilterWidget->setObjectName(QString::fromUtf8("mFeatureFilterWidget"));

        horizontalLayout_2->addWidget(mFeatureFilterWidget);

        mAttributeViewButton = new QToolButton(QgsAttributeTableDialog);
        mMainViewButtonGroup = new QButtonGroup(QgsAttributeTableDialog);
        mMainViewButtonGroup->setObjectName(QString::fromUtf8("mMainViewButtonGroup"));
        mMainViewButtonGroup->addButton(mAttributeViewButton);
        mAttributeViewButton->setObjectName(QString::fromUtf8("mAttributeViewButton"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/images/themes/default/mActionFormView.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mAttributeViewButton->setIcon(icon24);
        mAttributeViewButton->setCheckable(true);
        mAttributeViewButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(mAttributeViewButton);

        mTableViewButton = new QToolButton(QgsAttributeTableDialog);
        mMainViewButtonGroup->addButton(mTableViewButton);
        mTableViewButton->setObjectName(QString::fromUtf8("mTableViewButton"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/themes/default/mActionOpenTable.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mTableViewButton->setIcon(icon25);
        mTableViewButton->setCheckable(true);
        mTableViewButton->setChecked(true);
        mTableViewButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(mTableViewButton);


        hboxLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(hboxLayout, 8, 0, 1, 1);

        mToolbar = new QToolBar(QgsAttributeTableDialog);
        mToolbar->setObjectName(QString::fromUtf8("mToolbar"));
        mToolbar->setIconSize(QSize(18, 18));
        mToolbar->setFloatable(false);

        gridLayout->addWidget(mToolbar, 4, 0, 1, 1);

        QWidget::setTabOrder(mFieldCombo, mUpdateExpressionText);
        QWidget::setTabOrder(mUpdateExpressionText, mRunFieldCalc);
        QWidget::setTabOrder(mRunFieldCalc, mRunFieldCalcSelected);
        QWidget::setTabOrder(mRunFieldCalcSelected, mAttributeViewButton);
        QWidget::setTabOrder(mAttributeViewButton, mTableViewButton);

        mToolbar->addAction(mActionToggleEditing);
        mToolbar->addAction(mActionToggleMultiEdit);
        mToolbar->addAction(mActionSaveEdits);
        mToolbar->addAction(mActionReload);
        mToolbar->addSeparator();
        mToolbar->addAction(mActionAddFeature);
        mToolbar->addAction(mActionDeleteSelected);
        mToolbar->addAction(mActionCutSelectedRows);
        mToolbar->addAction(mActionCopySelectedRows);
        mToolbar->addAction(mActionPasteFeatures);
        mToolbar->addSeparator();
        mToolbar->addAction(mActionExpressionSelect);
        mToolbar->addAction(mActionSelectAll);
        mToolbar->addAction(mActionInvertSelection);
        mToolbar->addAction(mActionRemoveSelection);
        mToolbar->addAction(mActionSearchForm);
        mToolbar->addAction(mActionSelectedToTop);
        mToolbar->addAction(mActionPanMapToSelectedRows);
        mToolbar->addAction(mActionZoomMapToSelectedRows);
        mToolbar->addSeparator();
        mToolbar->addAction(mActionAddAttribute);
        mToolbar->addAction(mActionRemoveAttribute);
        mToolbar->addAction(mActionOrganizeColumns);
        mToolbar->addAction(mActionOpenFieldCalculator);
        mToolbar->addSeparator();
        mToolbar->addAction(mActionSetStyles);
        mToolbar->addSeparator();
        mToolbar->addAction(mActionDockUndock);

        retranslateUi(QgsAttributeTableDialog);
        QObject::connect(mMainViewButtonGroup, SIGNAL(buttonClicked(int)), mMainView, SLOT(setCurrentIndex(int)));
        QObject::connect(mActionToggleEditing, SIGNAL(toggled(bool)), mActionSaveEdits, SLOT(setEnabled(bool)));
        QObject::connect(mActionToggleEditing, SIGNAL(toggled(bool)), mActionReload, SLOT(setDisabled(bool)));

        mMainView->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(QgsAttributeTableDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsAttributeTableDialog)
    {
        QgsAttributeTableDialog->setWindowTitle(QApplication::translate("QgsAttributeTableDialog", "Attribute Table", nullptr));
        mActionSearchForm->setText(QApplication::translate("QgsAttributeTableDialog", "Select/filter features using form", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSearchForm->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Select/filter features using form (Ctrl+F)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionSearchForm->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        mActionToggleEditing->setText(QApplication::translate("QgsAttributeTableDialog", "Toggle editing mode", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionToggleEditing->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Toggle editing mode (Ctrl+E)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionToggleEditing->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        mActionToggleMultiEdit->setText(QApplication::translate("QgsAttributeTableDialog", "Toggle multi edit mode", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionToggleMultiEdit->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Toggle multi edit mode", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSaveEdits->setText(QApplication::translate("QgsAttributeTableDialog", "Save edits", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSaveEdits->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Save edits (Ctrl+S)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionReload->setText(QApplication::translate("QgsAttributeTableDialog", "Reload the table", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionReload->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Reload the table", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAddFeature->setText(QApplication::translate("QgsAttributeTableDialog", "Add feature", nullptr));
        mActionDeleteSelected->setText(QApplication::translate("QgsAttributeTableDialog", "Delete selected features", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDeleteSelected->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Delete selected features", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionDeleteSelected->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        mActionExpressionSelect->setText(QApplication::translate("QgsAttributeTableDialog", "Select features using an expression", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionExpressionSelect->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Select features using an expression", nullptr));
#endif // QT_NO_TOOLTIP
        mActionSelectAll->setText(QApplication::translate("QgsAttributeTableDialog", "Select all", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectAll->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Select all (Ctrl+A)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionInvertSelection->setText(QApplication::translate("QgsAttributeTableDialog", "Invert selection", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionInvertSelection->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Invert selection (Ctrl+R)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionInvertSelection->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        mActionRemoveSelection->setText(QApplication::translate("QgsAttributeTableDialog", "Deselect all features from the layer", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRemoveSelection->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Deselect all features from the layer (Ctrl+Shift+A)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionRemoveSelection->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+Shift+A", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSelectedToTop->setText(QApplication::translate("QgsAttributeTableDialog", "Move selection to top", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSelectedToTop->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Move selection to top", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPanMapToSelectedRows->setText(QApplication::translate("QgsAttributeTableDialog", "Pan map to the selected rows", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPanMapToSelectedRows->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Pan map to the selected rows (Ctrl+P)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionPanMapToSelectedRows->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        mActionZoomMapToSelectedRows->setText(QApplication::translate("QgsAttributeTableDialog", "Zoom map to the selected rows", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionZoomMapToSelectedRows->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Zoom map to the selected rows (Ctrl+J)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionZoomMapToSelectedRows->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+J", nullptr));
#endif // QT_NO_SHORTCUT
        mActionCutSelectedRows->setText(QApplication::translate("QgsAttributeTableDialog", "Cut selected rows to clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionCutSelectedRows->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Cut selected rows to clipboard (Ctrl+X)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionCopySelectedRows->setText(QApplication::translate("QgsAttributeTableDialog", "Copy selected rows to clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionCopySelectedRows->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Copy selected rows to clipboard (Ctrl+C)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionPasteFeatures->setText(QApplication::translate("QgsAttributeTableDialog", "Paste features from clipboard", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionPasteFeatures->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Paste features from clipboard (Ctrl+V)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionRemoveAttribute->setText(QApplication::translate("QgsAttributeTableDialog", "Delete field", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionRemoveAttribute->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Delete field (Ctrl+L)", nullptr));
#endif // QT_NO_TOOLTIP
        mActionAddAttribute->setText(QApplication::translate("QgsAttributeTableDialog", "New field", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAddAttribute->setToolTip(QApplication::translate("QgsAttributeTableDialog", "New field (Ctrl+W)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionAddAttribute->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+W", nullptr));
#endif // QT_NO_SHORTCUT
        mActionOpenFieldCalculator->setText(QApplication::translate("QgsAttributeTableDialog", "Open field calculator", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionOpenFieldCalculator->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Open field calculator (Ctrl+I)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        mActionOpenFieldCalculator->setShortcut(QApplication::translate("QgsAttributeTableDialog", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        mActionSetStyles->setText(QApplication::translate("QgsAttributeTableDialog", "Conditional formatting", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionSetStyles->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Conditional formatting", nullptr));
#endif // QT_NO_TOOLTIP
        mActionDockUndock->setText(QApplication::translate("QgsAttributeTableDialog", "Dock Attribute Table", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionDockUndock->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Dock Attribute Table", nullptr));
#endif // QT_NO_TOOLTIP
        mActionOrganizeColumns->setText(QApplication::translate("QgsAttributeTableDialog", "Organize Columns", nullptr));
        mActionAddFeatureViaAttributeTable->setText(QApplication::translate("QgsAttributeTableDialog", "Add feature via attribute table", nullptr));
        mActionAddFeatureViaAttributeForm->setText(QApplication::translate("QgsAttributeTableDialog", "Add feature via attribute form", nullptr));
#ifndef QT_NO_TOOLTIP
        mActionAddFeatureViaAttributeForm->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Add feature via attribute form", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("QgsAttributeTableDialog", "=", nullptr));
        mRunFieldCalc->setText(QApplication::translate("QgsAttributeTableDialog", "Update All", nullptr));
        mRunFieldCalcSelected->setText(QApplication::translate("QgsAttributeTableDialog", "Update Selected", nullptr));
#ifndef QT_NO_TOOLTIP
        mAttributeViewButton->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Switch to form view", nullptr));
#endif // QT_NO_TOOLTIP
        mAttributeViewButton->setText(QApplication::translate("QgsAttributeTableDialog", "Form View", nullptr));
#ifndef QT_NO_TOOLTIP
        mTableViewButton->setToolTip(QApplication::translate("QgsAttributeTableDialog", "Switch to table view", nullptr));
#endif // QT_NO_TOOLTIP
        mTableViewButton->setText(QApplication::translate("QgsAttributeTableDialog", "Table View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAttributeTableDialog: public Ui_QgsAttributeTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSATTRIBUTETABLEDIALOG_H
