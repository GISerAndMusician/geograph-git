/********************************************************************************
** Form generated from reading UI file 'qgsattributewidgetrelationeditwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSATTRIBUTEWIDGETRELATIONEDITWIDGET_H
#define UI_QGSATTRIBUTEWIDGETRELATIONEDITWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QgsAttributeWidgetRelationEditWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLabel;
    QLineEdit *mRelationLabelEdit;
    QCheckBox *mRelationShowLinkCheckBox;
    QCheckBox *mRelationShowUnlinkCheckBox;
    QCheckBox *mRelationShowSaveChildEditsCheckBox;
    QCheckBox *mRelationShowAddChildCheckBox;
    QCheckBox *mRelationShowDuplicateChildFeatureCheckBox;
    QCheckBox *mRelationDeleteChildFeatureCheckBox;
    QCheckBox *mRelationShowZoomToFeatureCheckBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *cardinalityLabel;
    QComboBox *mRelationCardinalityCombo;
    QCheckBox *mRelationForceSuppressFormPopupCheckBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *QgsAttributeWidgetRelationEditWidget)
    {
        if (QgsAttributeWidgetRelationEditWidget->objectName().isEmpty())
            QgsAttributeWidgetRelationEditWidget->setObjectName(QString::fromUtf8("QgsAttributeWidgetRelationEditWidget"));
        QgsAttributeWidgetRelationEditWidget->resize(340, 361);
        verticalLayout = new QVBoxLayout(QgsAttributeWidgetRelationEditWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelLabel = new QLabel(QgsAttributeWidgetRelationEditWidget);
        labelLabel->setObjectName(QString::fromUtf8("labelLabel"));

        horizontalLayout->addWidget(labelLabel);

        mRelationLabelEdit = new QLineEdit(QgsAttributeWidgetRelationEditWidget);
        mRelationLabelEdit->setObjectName(QString::fromUtf8("mRelationLabelEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mRelationLabelEdit->sizePolicy().hasHeightForWidth());
        mRelationLabelEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mRelationLabelEdit);


        verticalLayout->addLayout(horizontalLayout);

        mRelationShowLinkCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowLinkCheckBox->setObjectName(QString::fromUtf8("mRelationShowLinkCheckBox"));

        verticalLayout->addWidget(mRelationShowLinkCheckBox);

        mRelationShowUnlinkCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowUnlinkCheckBox->setObjectName(QString::fromUtf8("mRelationShowUnlinkCheckBox"));

        verticalLayout->addWidget(mRelationShowUnlinkCheckBox);

        mRelationShowSaveChildEditsCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowSaveChildEditsCheckBox->setObjectName(QString::fromUtf8("mRelationShowSaveChildEditsCheckBox"));

        verticalLayout->addWidget(mRelationShowSaveChildEditsCheckBox);

        mRelationShowAddChildCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowAddChildCheckBox->setObjectName(QString::fromUtf8("mRelationShowAddChildCheckBox"));

        verticalLayout->addWidget(mRelationShowAddChildCheckBox);

        mRelationShowDuplicateChildFeatureCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowDuplicateChildFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationShowDuplicateChildFeatureCheckBox"));

        verticalLayout->addWidget(mRelationShowDuplicateChildFeatureCheckBox);

        mRelationDeleteChildFeatureCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationDeleteChildFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationDeleteChildFeatureCheckBox"));

        verticalLayout->addWidget(mRelationDeleteChildFeatureCheckBox);

        mRelationShowZoomToFeatureCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationShowZoomToFeatureCheckBox->setObjectName(QString::fromUtf8("mRelationShowZoomToFeatureCheckBox"));

        verticalLayout->addWidget(mRelationShowZoomToFeatureCheckBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cardinalityLabel = new QLabel(QgsAttributeWidgetRelationEditWidget);
        cardinalityLabel->setObjectName(QString::fromUtf8("cardinalityLabel"));

        horizontalLayout_2->addWidget(cardinalityLabel);

        mRelationCardinalityCombo = new QComboBox(QgsAttributeWidgetRelationEditWidget);
        mRelationCardinalityCombo->setObjectName(QString::fromUtf8("mRelationCardinalityCombo"));

        horizontalLayout_2->addWidget(mRelationCardinalityCombo);


        verticalLayout->addLayout(horizontalLayout_2);

        mRelationForceSuppressFormPopupCheckBox = new QCheckBox(QgsAttributeWidgetRelationEditWidget);
        mRelationForceSuppressFormPopupCheckBox->setObjectName(QString::fromUtf8("mRelationForceSuppressFormPopupCheckBox"));

        verticalLayout->addWidget(mRelationForceSuppressFormPopupCheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(QgsAttributeWidgetRelationEditWidget);

        QMetaObject::connectSlotsByName(QgsAttributeWidgetRelationEditWidget);
    } // setupUi

    void retranslateUi(QWidget *QgsAttributeWidgetRelationEditWidget)
    {
        QgsAttributeWidgetRelationEditWidget->setWindowTitle(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Attribute Widget Relation Edit Widget", nullptr));
        labelLabel->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Label", nullptr));
        mRelationShowLinkCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Show link button", nullptr));
        mRelationShowUnlinkCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Show unlink button", nullptr));
        mRelationShowSaveChildEditsCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Show save child layer edits button", nullptr));
        mRelationShowAddChildCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Add child feature", nullptr));
        mRelationShowDuplicateChildFeatureCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Duplicate child feature", nullptr));
        mRelationDeleteChildFeatureCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Delete child feature", nullptr));
        mRelationShowZoomToFeatureCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Zoom to child feature", nullptr));
        cardinalityLabel->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Cardinality", nullptr));
#ifndef QT_NO_STATUSTIP
        mRelationForceSuppressFormPopupCheckBox->setStatusTip(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Do not open a new attribute form after digitizing a new feature, overrides all other options", nullptr));
#endif // QT_NO_STATUSTIP
        mRelationForceSuppressFormPopupCheckBox->setText(QApplication::translate("QgsAttributeWidgetRelationEditWidget", "Force hide form on add feature", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAttributeWidgetRelationEditWidget: public Ui_QgsAttributeWidgetRelationEditWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSATTRIBUTEWIDGETRELATIONEDITWIDGET_H
