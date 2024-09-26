/********************************************************************************
** Form generated from reading UI file 'GgsSomDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSSOMDIALOG_H
#define UI_GGSSOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *layers_comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *iterator_spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *batch_size_spinBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(415, 144);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        layers_comboBox = new QComboBox(Dialog);
        layers_comboBox->setObjectName(QString::fromUtf8("layers_comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layers_comboBox->sizePolicy().hasHeightForWidth());
        layers_comboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(layers_comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        iterator_spinBox = new QSpinBox(Dialog);
        iterator_spinBox->setObjectName(QString::fromUtf8("iterator_spinBox"));
        sizePolicy.setHeightForWidth(iterator_spinBox->sizePolicy().hasHeightForWidth());
        iterator_spinBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(iterator_spinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        batch_size_spinBox = new QSpinBox(Dialog);
        batch_size_spinBox->setObjectName(QString::fromUtf8("batch_size_spinBox"));
        sizePolicy.setHeightForWidth(batch_size_spinBox->sizePolicy().hasHeightForWidth());
        batch_size_spinBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(batch_size_spinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        ok_pushButton = new QPushButton(Dialog);
        ok_pushButton->setObjectName(QString::fromUtf8("ok_pushButton"));

        horizontalLayout_4->addWidget(ok_pushButton);

        cancel_pushButton = new QPushButton(Dialog);
        cancel_pushButton->setObjectName(QString::fromUtf8("cancel_pushButton"));

        horizontalLayout_4->addWidget(cancel_pushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "SOM\350\201\232\347\261\273\345\244\204\347\220\206", nullptr));
        label->setText(QApplication::translate("Dialog", "\350\201\232\347\261\273\345\233\276\345\261\202\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\346\257\217\346\254\241\350\277\255\344\273\243\347\232\204\346\240\267\346\234\254\346\225\260\351\207\217\357\274\232", nullptr));
        ok_pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSSOMDIALOG_H
