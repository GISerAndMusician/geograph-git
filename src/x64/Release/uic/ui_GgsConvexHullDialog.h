/********************************************************************************
** Form generated from reading UI file 'GgsConvexHullDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSCONVEXHULLDIALOG_H
#define UI_GGSCONVEXHULLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConvexHullDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBoxAlgo;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_alpha;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *ConvexHullDialog)
    {
        if (ConvexHullDialog->objectName().isEmpty())
            ConvexHullDialog->setObjectName(QString::fromUtf8("ConvexHullDialog"));
        ConvexHullDialog->resize(362, 140);
        formLayout = new QFormLayout(ConvexHullDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ConvexHullDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(ConvexHullDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(ConvexHullDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxAlgo = new QComboBox(ConvexHullDialog);
        comboBoxAlgo->setObjectName(QString::fromUtf8("comboBoxAlgo"));
        sizePolicy.setHeightForWidth(comboBoxAlgo->sizePolicy().hasHeightForWidth());
        comboBoxAlgo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxAlgo, 1, 1, 1, 1);

        label_3 = new QLabel(ConvexHullDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox_alpha = new QDoubleSpinBox(ConvexHullDialog);
        doubleSpinBox_alpha->setObjectName(QString::fromUtf8("doubleSpinBox_alpha"));
        doubleSpinBox_alpha->setMinimum(0.010000000000000);
        doubleSpinBox_alpha->setValue(13.000000000000000);

        gridLayout->addWidget(doubleSpinBox_alpha, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(ConvexHullDialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(ConvexHullDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        retranslateUi(ConvexHullDialog);

        QMetaObject::connectSlotsByName(ConvexHullDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvexHullDialog)
    {
        ConvexHullDialog->setWindowTitle(QApplication::translate("ConvexHullDialog", "\347\202\271\347\276\244\345\207\270\345\214\205\350\256\241\347\256\227", nullptr));
        label->setText(QApplication::translate("ConvexHullDialog", "\345\233\276\345\261\202\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ConvexHullDialog", "\347\256\227\346\263\225\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ConvexHullDialog", "alpha\357\274\232", nullptr));
        pushButtonOK->setText(QApplication::translate("ConvexHullDialog", "\347\241\256\345\256\232", nullptr));
        pushButtonCancel->setText(QApplication::translate("ConvexHullDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConvexHullDialog: public Ui_ConvexHullDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSCONVEXHULLDIALOG_H
