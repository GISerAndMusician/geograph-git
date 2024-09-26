/********************************************************************************
** Form generated from reading UI file 'GgsBackboneDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSBACKBONEDIALOG_H
#define UI_GGSBACKBONEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BackboneDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QComboBox *comboBox;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *hboxLayout;
    QProgressBar *progressBar;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *BackboneDialog)
    {
        if (BackboneDialog->objectName().isEmpty())
            BackboneDialog->setObjectName(QString::fromUtf8("BackboneDialog"));
        BackboneDialog->resize(449, 115);
        gridLayout_2 = new QGridLayout(BackboneDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(BackboneDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(BackboneDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(BackboneDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(BackboneDialog);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(60.000000000000000);

        gridLayout->addWidget(doubleSpinBox, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(BackboneDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(200, 0));
        progressBar->setValue(24);

        hboxLayout->addWidget(progressBar);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(BackboneDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(BackboneDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(BackboneDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), BackboneDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BackboneDialog);
    } // setupUi

    void retranslateUi(QDialog *BackboneDialog)
    {
        BackboneDialog->setWindowTitle(QApplication::translate("BackboneDialog", "\346\217\220\345\217\226\351\252\250\346\236\266\347\275\221\347\273\234", nullptr));
        label_2->setText(QApplication::translate("BackboneDialog", "\344\277\235\347\225\231\346\257\224\347\216\207\357\274\210%\357\274\211\357\274\232", nullptr));
        label->setText(QApplication::translate("BackboneDialog", "\346\217\220\345\217\226\346\226\271\346\263\225\357\274\232", nullptr));
        okButton->setText(QApplication::translate("BackboneDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("BackboneDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackboneDialog: public Ui_BackboneDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSBACKBONEDIALOG_H
