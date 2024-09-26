/********************************************************************************
** Form generated from reading UI file 'qgsattributetypeedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSATTRIBUTETYPEEDIT_H
#define UI_QGSATTRIBUTETYPEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgsexpressionlineedit.h"
#include "qgsfieldexpressionwidget.h"
#include "qgspropertyoverridebutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAttributeTypeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QgsCollapsibleGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *laComment;
    QLabel *label_9;
    QCheckBox *isFieldEditableCheckBox;
    QCheckBox *labelOnTopCheckBox;
    QLineEdit *mAlias;
    QgsPropertyOverrideButton *mAliasExpressionButton;
    QLabel *label_6;
    QgsCollapsibleGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QStackedWidget *stackedWidget;
    QComboBox *mWidgetTypeComboBox;
    QgsCollapsibleGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QCheckBox *mUniqueCheckBox;
    QCheckBox *notNullCheckBox;
    QCheckBox *mCheckBoxEnforceUnique;
    QgsFieldExpressionWidget *constraintExpressionWidget;
    QLabel *label_2;
    QLineEdit *leConstraintExpressionDescription;
    QCheckBox *mCheckBoxEnforceNotNull;
    QLabel *label;
    QCheckBox *mCheckBoxEnforceExpression;
    QgsCollapsibleGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QgsExpressionLineEdit *mExpressionWidget;
    QLabel *mDefaultPreviewLabel;
    QWidget *mWarnDefaultValueHasFieldsWidget;
    QHBoxLayout *mWarnDefaultValueHasFields;
    QLabel *label_8;
    QLabel *label_7;
    QCheckBox *mApplyDefaultValueOnUpdateCheckBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QgsAttributeTypeDialog)
    {
        if (QgsAttributeTypeDialog->objectName().isEmpty())
            QgsAttributeTypeDialog->setObjectName(QString::fromUtf8("QgsAttributeTypeDialog"));
        QgsAttributeTypeDialog->resize(751, 620);
        verticalLayout = new QVBoxLayout(QgsAttributeTypeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_4 = new QgsCollapsibleGroupBox(QgsAttributeTypeDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        laComment = new QLabel(groupBox_4);
        laComment->setObjectName(QString::fromUtf8("laComment"));
        laComment->setWordWrap(true);

        gridLayout->addWidget(laComment, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        isFieldEditableCheckBox = new QCheckBox(groupBox_4);
        isFieldEditableCheckBox->setObjectName(QString::fromUtf8("isFieldEditableCheckBox"));
        isFieldEditableCheckBox->setChecked(true);

        gridLayout->addWidget(isFieldEditableCheckBox, 2, 0, 1, 1);

        labelOnTopCheckBox = new QCheckBox(groupBox_4);
        labelOnTopCheckBox->setObjectName(QString::fromUtf8("labelOnTopCheckBox"));
        labelOnTopCheckBox->setChecked(false);

        gridLayout->addWidget(labelOnTopCheckBox, 2, 2, 1, 1);

        mAlias = new QLineEdit(groupBox_4);
        mAlias->setObjectName(QString::fromUtf8("mAlias"));

        gridLayout->addWidget(mAlias, 0, 2, 1, 1);

        mAliasExpressionButton = new QgsPropertyOverrideButton(groupBox_4);
        mAliasExpressionButton->setObjectName(QString::fromUtf8("mAliasExpressionButton"));

        gridLayout->addWidget(mAliasExpressionButton, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        groupBox_3 = new QgsCollapsibleGroupBox(QgsAttributeTypeDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        stackedWidget = new QStackedWidget(groupBox_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        gridLayout_5->addWidget(stackedWidget, 1, 1, 1, 1);

        mWidgetTypeComboBox = new QComboBox(groupBox_3);
        mWidgetTypeComboBox->setObjectName(QString::fromUtf8("mWidgetTypeComboBox"));

        gridLayout_5->addWidget(mWidgetTypeComboBox, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QgsCollapsibleGroupBox(QgsAttributeTypeDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFocusPolicy(Qt::NoFocus);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mUniqueCheckBox = new QCheckBox(groupBox);
        mUniqueCheckBox->setObjectName(QString::fromUtf8("mUniqueCheckBox"));

        gridLayout_3->addWidget(mUniqueCheckBox, 1, 0, 1, 1);

        notNullCheckBox = new QCheckBox(groupBox);
        notNullCheckBox->setObjectName(QString::fromUtf8("notNullCheckBox"));

        gridLayout_3->addWidget(notNullCheckBox, 0, 0, 1, 1);

        mCheckBoxEnforceUnique = new QCheckBox(groupBox);
        mCheckBoxEnforceUnique->setObjectName(QString::fromUtf8("mCheckBoxEnforceUnique"));
        mCheckBoxEnforceUnique->setEnabled(false);

        gridLayout_3->addWidget(mCheckBoxEnforceUnique, 1, 1, 1, 1);

        constraintExpressionWidget = new QgsFieldExpressionWidget(groupBox);
        constraintExpressionWidget->setObjectName(QString::fromUtf8("constraintExpressionWidget"));
        constraintExpressionWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout_3->addWidget(constraintExpressionWidget, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 3, 0, 1, 1);

        leConstraintExpressionDescription = new QLineEdit(groupBox);
        leConstraintExpressionDescription->setObjectName(QString::fromUtf8("leConstraintExpressionDescription"));

        gridLayout_3->addWidget(leConstraintExpressionDescription, 3, 1, 1, 1);

        mCheckBoxEnforceNotNull = new QCheckBox(groupBox);
        mCheckBoxEnforceNotNull->setObjectName(QString::fromUtf8("mCheckBoxEnforceNotNull"));
        mCheckBoxEnforceNotNull->setEnabled(false);

        gridLayout_3->addWidget(mCheckBoxEnforceNotNull, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        mCheckBoxEnforceExpression = new QCheckBox(groupBox);
        mCheckBoxEnforceExpression->setObjectName(QString::fromUtf8("mCheckBoxEnforceExpression"));

        gridLayout_3->addWidget(mCheckBoxEnforceExpression, 4, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QgsCollapsibleGroupBox(QgsAttributeTypeDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        mExpressionWidget = new QgsExpressionLineEdit(groupBox_2);
        mExpressionWidget->setObjectName(QString::fromUtf8("mExpressionWidget"));
        mExpressionWidget->setFocusPolicy(Qt::StrongFocus);

        gridLayout_2->addWidget(mExpressionWidget, 4, 1, 1, 1);

        mDefaultPreviewLabel = new QLabel(groupBox_2);
        mDefaultPreviewLabel->setObjectName(QString::fromUtf8("mDefaultPreviewLabel"));

        gridLayout_2->addWidget(mDefaultPreviewLabel, 6, 1, 1, 1);

        mWarnDefaultValueHasFieldsWidget = new QWidget(groupBox_2);
        mWarnDefaultValueHasFieldsWidget->setObjectName(QString::fromUtf8("mWarnDefaultValueHasFieldsWidget"));
        mWarnDefaultValueHasFields = new QHBoxLayout(mWarnDefaultValueHasFieldsWidget);
        mWarnDefaultValueHasFields->setObjectName(QString::fromUtf8("mWarnDefaultValueHasFields"));
        label_8 = new QLabel(mWarnDefaultValueHasFieldsWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/images/themes/default/mIconWarning.svg")));

        mWarnDefaultValueHasFields->addWidget(label_8);

        label_7 = new QLabel(mWarnDefaultValueHasFieldsWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        mWarnDefaultValueHasFields->addWidget(label_7);


        gridLayout_2->addWidget(mWarnDefaultValueHasFieldsWidget, 7, 0, 1, 2);

        mApplyDefaultValueOnUpdateCheckBox = new QCheckBox(groupBox_2);
        mApplyDefaultValueOnUpdateCheckBox->setObjectName(QString::fromUtf8("mApplyDefaultValueOnUpdateCheckBox"));

        gridLayout_2->addWidget(mApplyDefaultValueOnUpdateCheckBox, 8, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(isFieldEditableCheckBox, labelOnTopCheckBox);
        QWidget::setTabOrder(labelOnTopCheckBox, mWidgetTypeComboBox);
        QWidget::setTabOrder(mWidgetTypeComboBox, notNullCheckBox);
        QWidget::setTabOrder(notNullCheckBox, mCheckBoxEnforceNotNull);
        QWidget::setTabOrder(mCheckBoxEnforceNotNull, mUniqueCheckBox);
        QWidget::setTabOrder(mUniqueCheckBox, mCheckBoxEnforceUnique);
        QWidget::setTabOrder(mCheckBoxEnforceUnique, constraintExpressionWidget);
        QWidget::setTabOrder(constraintExpressionWidget, leConstraintExpressionDescription);
        QWidget::setTabOrder(leConstraintExpressionDescription, mCheckBoxEnforceExpression);
        QWidget::setTabOrder(mCheckBoxEnforceExpression, mExpressionWidget);

        retranslateUi(QgsAttributeTypeDialog);

        QMetaObject::connectSlotsByName(QgsAttributeTypeDialog);
    } // setupUi

    void retranslateUi(QWidget *QgsAttributeTypeDialog)
    {
        QgsAttributeTypeDialog->setWindowTitle(QApplication::translate("QgsAttributeTypeDialog", "Edit Widget Properties", nullptr));
        groupBox_4->setTitle(QApplication::translate("QgsAttributeTypeDialog", "General", nullptr));
        laComment->setText(QString());
        label_9->setText(QApplication::translate("QgsAttributeTypeDialog", "Alias", nullptr));
        isFieldEditableCheckBox->setText(QApplication::translate("QgsAttributeTypeDialog", "Editable", nullptr));
        labelOnTopCheckBox->setText(QApplication::translate("QgsAttributeTypeDialog", "Label on top", nullptr));
        mAliasExpressionButton->setText(QApplication::translate("QgsAttributeTypeDialog", "...", nullptr));
        label_6->setText(QApplication::translate("QgsAttributeTypeDialog", "Comment", nullptr));
        groupBox_3->setTitle(QApplication::translate("QgsAttributeTypeDialog", "Widget Type", nullptr));
        groupBox->setTitle(QApplication::translate("QgsAttributeTypeDialog", "Constraints", nullptr));
        mUniqueCheckBox->setText(QApplication::translate("QgsAttributeTypeDialog", "Unique", nullptr));
        notNullCheckBox->setText(QApplication::translate("QgsAttributeTypeDialog", "Not null", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckBoxEnforceUnique->setToolTip(QApplication::translate("QgsAttributeTypeDialog", "<p>Enforcing the unique constraint prevents committing features which do not meet the constraint.</p><p>Unenforced constraints display a warning to users, but do not prevent committing the feature.</p>", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckBoxEnforceUnique->setText(QApplication::translate("QgsAttributeTypeDialog", "Enforce unique constraint", nullptr));
        label_2->setText(QApplication::translate("QgsAttributeTypeDialog", "Expression description", nullptr));
#ifndef QT_NO_TOOLTIP
        leConstraintExpressionDescription->setToolTip(QApplication::translate("QgsAttributeTypeDialog", "Optional descriptive name for expression constraint", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        mCheckBoxEnforceNotNull->setToolTip(QApplication::translate("QgsAttributeTypeDialog", "<p>Enforcing the not null constraint prevents committing features which do not meet the constraint.</p><p>Unenforced constraints display a warning to users, but do not prevent committing the feature.</p>", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckBoxEnforceNotNull->setText(QApplication::translate("QgsAttributeTypeDialog", "Enforce not null constraint", nullptr));
        label->setText(QApplication::translate("QgsAttributeTypeDialog", "Expression", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckBoxEnforceExpression->setToolTip(QApplication::translate("QgsAttributeTypeDialog", "<p>Enforcing the expression constraint prevents committing features which do not meet the constraint.</p><p>Unenforced constraints display a warning to users, but do not prevent committing the feature.</p>", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckBoxEnforceExpression->setText(QApplication::translate("QgsAttributeTypeDialog", "Enforce expression constraint", nullptr));
        groupBox_2->setTitle(QApplication::translate("QgsAttributeTypeDialog", "Defaults", nullptr));
        label_3->setText(QApplication::translate("QgsAttributeTypeDialog", "Default value", nullptr));
        label_4->setText(QApplication::translate("QgsAttributeTypeDialog", "Preview", nullptr));
        mDefaultPreviewLabel->setText(QString());
        label_8->setText(QString());
        label_7->setText(QApplication::translate("QgsAttributeTypeDialog", "Using fields in a default value expression only works if \"Apply default value on update\" is checked.", nullptr));
#ifndef QT_NO_TOOLTIP
        mApplyDefaultValueOnUpdateCheckBox->setToolTip(QApplication::translate("QgsAttributeTypeDialog", "<p>With this option checked, the default value will not only be used when the feature is first created, but also whenever a feature's attribute or geometry is changed.</p><p>This is often useful for a last_modified timestamp or to record the username that last modified the feature.</p>", nullptr));
#endif // QT_NO_TOOLTIP
        mApplyDefaultValueOnUpdateCheckBox->setText(QApplication::translate("QgsAttributeTypeDialog", "Apply default value on update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAttributeTypeDialog: public Ui_QgsAttributeTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSATTRIBUTETYPEEDIT_H
