/********************************************************************************
** Form generated from reading UI file 'qgswmsdimensiondialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSWMSDIMENSIONDIALOGBASE_H
#define UI_QGSWMSDIMENSIONDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include "qgsfieldcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsWmsDimensionDialogBase
{
public:
    QGridLayout *gridLayout;
    QLineEdit *mUnitSymbolLineEdit;
    QLineEdit *mUnitsLineEdit;
    QComboBox *mNameComboBox;
    QgsFieldComboBox *mFieldComboBox;
    QSpacerItem *verticalSpacer;
    QLabel *mFieldLabel;
    QLabel *mNameLabel;
    QLabel *mEndFiledLabel;
    QgsFieldComboBox *mEndFieldComboBox;
    QLabel *mUnitSymbolLabel;
    QLabel *mUnitsLabel;
    QLabel *mDefaultDisplayLabel;
    QLabel *mReferenceValueLabel;
    QComboBox *mDefaultDisplayComboBox;
    QComboBox *mReferenceValueComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsWmsDimensionDialogBase)
    {
        if (QgsWmsDimensionDialogBase->objectName().isEmpty())
            QgsWmsDimensionDialogBase->setObjectName(QString::fromUtf8("QgsWmsDimensionDialogBase"));
        QgsWmsDimensionDialogBase->resize(400, 300);
        gridLayout = new QGridLayout(QgsWmsDimensionDialogBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mUnitSymbolLineEdit = new QLineEdit(QgsWmsDimensionDialogBase);
        mUnitSymbolLineEdit->setObjectName(QString::fromUtf8("mUnitSymbolLineEdit"));

        gridLayout->addWidget(mUnitSymbolLineEdit, 4, 1, 1, 1);

        mUnitsLineEdit = new QLineEdit(QgsWmsDimensionDialogBase);
        mUnitsLineEdit->setObjectName(QString::fromUtf8("mUnitsLineEdit"));

        gridLayout->addWidget(mUnitsLineEdit, 3, 1, 1, 1);

        mNameComboBox = new QComboBox(QgsWmsDimensionDialogBase);
        mNameComboBox->setObjectName(QString::fromUtf8("mNameComboBox"));
        mNameComboBox->setEditable(true);

        gridLayout->addWidget(mNameComboBox, 0, 1, 1, 1);

        mFieldComboBox = new QgsFieldComboBox(QgsWmsDimensionDialogBase);
        mFieldComboBox->setObjectName(QString::fromUtf8("mFieldComboBox"));

        gridLayout->addWidget(mFieldComboBox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        mFieldLabel = new QLabel(QgsWmsDimensionDialogBase);
        mFieldLabel->setObjectName(QString::fromUtf8("mFieldLabel"));

        gridLayout->addWidget(mFieldLabel, 1, 0, 1, 1);

        mNameLabel = new QLabel(QgsWmsDimensionDialogBase);
        mNameLabel->setObjectName(QString::fromUtf8("mNameLabel"));

        gridLayout->addWidget(mNameLabel, 0, 0, 1, 1);

        mEndFiledLabel = new QLabel(QgsWmsDimensionDialogBase);
        mEndFiledLabel->setObjectName(QString::fromUtf8("mEndFiledLabel"));

        gridLayout->addWidget(mEndFiledLabel, 2, 0, 1, 1);

        mEndFieldComboBox = new QgsFieldComboBox(QgsWmsDimensionDialogBase);
        mEndFieldComboBox->setObjectName(QString::fromUtf8("mEndFieldComboBox"));

        gridLayout->addWidget(mEndFieldComboBox, 2, 1, 1, 1);

        mUnitSymbolLabel = new QLabel(QgsWmsDimensionDialogBase);
        mUnitSymbolLabel->setObjectName(QString::fromUtf8("mUnitSymbolLabel"));

        gridLayout->addWidget(mUnitSymbolLabel, 4, 0, 1, 1);

        mUnitsLabel = new QLabel(QgsWmsDimensionDialogBase);
        mUnitsLabel->setObjectName(QString::fromUtf8("mUnitsLabel"));
        mUnitsLabel->setEnabled(true);

        gridLayout->addWidget(mUnitsLabel, 3, 0, 1, 1);

        mDefaultDisplayLabel = new QLabel(QgsWmsDimensionDialogBase);
        mDefaultDisplayLabel->setObjectName(QString::fromUtf8("mDefaultDisplayLabel"));

        gridLayout->addWidget(mDefaultDisplayLabel, 5, 0, 1, 1);

        mReferenceValueLabel = new QLabel(QgsWmsDimensionDialogBase);
        mReferenceValueLabel->setObjectName(QString::fromUtf8("mReferenceValueLabel"));

        gridLayout->addWidget(mReferenceValueLabel, 6, 0, 1, 1);

        mDefaultDisplayComboBox = new QComboBox(QgsWmsDimensionDialogBase);
        mDefaultDisplayComboBox->addItem(QString());
        mDefaultDisplayComboBox->addItem(QString());
        mDefaultDisplayComboBox->addItem(QString());
        mDefaultDisplayComboBox->addItem(QString());
        mDefaultDisplayComboBox->setObjectName(QString::fromUtf8("mDefaultDisplayComboBox"));

        gridLayout->addWidget(mDefaultDisplayComboBox, 5, 1, 1, 1);

        mReferenceValueComboBox = new QComboBox(QgsWmsDimensionDialogBase);
        mReferenceValueComboBox->setObjectName(QString::fromUtf8("mReferenceValueComboBox"));
        mReferenceValueComboBox->setEditable(true);

        gridLayout->addWidget(mReferenceValueComboBox, 6, 1, 1, 1);

        buttonBox = new QDialogButtonBox(QgsWmsDimensionDialogBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 0, 1, 2);


        retranslateUi(QgsWmsDimensionDialogBase);

        QMetaObject::connectSlotsByName(QgsWmsDimensionDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsWmsDimensionDialogBase)
    {
        QgsWmsDimensionDialogBase->setWindowTitle(QApplication::translate("QgsWmsDimensionDialogBase", "Add WMS Dimension", nullptr));
        mFieldLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Attribute", nullptr));
#ifndef QT_NO_TOOLTIP
        mNameLabel->setToolTip(QApplication::translate("QgsWmsDimensionDialogBase", "OAPIF supports \"Name\" and \"Date\" only, \"WMS\" does not support \"Date\"", nullptr));
#endif // QT_NO_TOOLTIP
        mNameLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Name", nullptr));
        mEndFiledLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "End attribute (optional)", nullptr));
        mUnitSymbolLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Unit symbol", nullptr));
        mUnitsLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Units", nullptr));
        mDefaultDisplayLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Default display", nullptr));
        mReferenceValueLabel->setText(QApplication::translate("QgsWmsDimensionDialogBase", "Reference value", nullptr));
        mDefaultDisplayComboBox->setItemText(0, QApplication::translate("QgsWmsDimensionDialogBase", "All values", nullptr));
        mDefaultDisplayComboBox->setItemText(1, QApplication::translate("QgsWmsDimensionDialogBase", "Min value", nullptr));
        mDefaultDisplayComboBox->setItemText(2, QApplication::translate("QgsWmsDimensionDialogBase", "Max value", nullptr));
        mDefaultDisplayComboBox->setItemText(3, QApplication::translate("QgsWmsDimensionDialogBase", "Reference value", nullptr));

    } // retranslateUi

};

namespace Ui {
    class QgsWmsDimensionDialogBase: public Ui_QgsWmsDimensionDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSWMSDIMENSIONDIALOGBASE_H
