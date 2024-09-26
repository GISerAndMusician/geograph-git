/********************************************************************************
** Form generated from reading UI file 'GgsSimilarityDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSSIMILARITYDIALOG_H
#define UI_GGSSIMILARITYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SimilarityDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxReferencLayer;
    QLabel *label_2;
    QComboBox *comboBoxLayer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *SimilarityDialog)
    {
        if (SimilarityDialog->objectName().isEmpty())
            SimilarityDialog->setObjectName(QString::fromUtf8("SimilarityDialog"));
        SimilarityDialog->resize(274, 112);
        formLayout = new QFormLayout(SimilarityDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SimilarityDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxReferencLayer = new QComboBox(SimilarityDialog);
        comboBoxReferencLayer->setObjectName(QString::fromUtf8("comboBoxReferencLayer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxReferencLayer->sizePolicy().hasHeightForWidth());
        comboBoxReferencLayer->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxReferencLayer, 0, 1, 1, 1);

        label_2 = new QLabel(SimilarityDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxLayer = new QComboBox(SimilarityDialog);
        comboBoxLayer->setObjectName(QString::fromUtf8("comboBoxLayer"));
        sizePolicy.setHeightForWidth(comboBoxLayer->sizePolicy().hasHeightForWidth());
        comboBoxLayer->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxLayer, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOk = new QPushButton(SimilarityDialog);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));

        horizontalLayout->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(SimilarityDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        retranslateUi(SimilarityDialog);

        QMetaObject::connectSlotsByName(SimilarityDialog);
    } // setupUi

    void retranslateUi(QDialog *SimilarityDialog)
    {
        SimilarityDialog->setWindowTitle(QApplication::translate("SimilarityDialog", "\345\233\276\345\261\202\347\233\270\344\274\274\345\272\246\350\256\241\347\256\227", nullptr));
        label->setText(QApplication::translate("SimilarityDialog", "\345\217\202\350\200\203\345\233\276\345\261\202\357\274\232", nullptr));
        label_2->setText(QApplication::translate("SimilarityDialog", "\345\233\276\345\261\202\357\274\232", nullptr));
        pushButtonOk->setText(QApplication::translate("SimilarityDialog", "\350\256\241\347\256\227", nullptr));
        pushButtonCancel->setText(QApplication::translate("SimilarityDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimilarityDialog: public Ui_SimilarityDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSSIMILARITYDIALOG_H
