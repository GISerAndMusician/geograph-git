/********************************************************************************
** Form generated from reading UI file 'GgsClusterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSCLUSTERDIALOG_H
#define UI_GGSCLUSTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *layers_comboBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *spinBox_cluster_count;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_pushButton;
    QPushButton *cancel_pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(308, 153);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        spinBox_cluster_count = new QSpinBox(groupBox);
        spinBox_cluster_count->setObjectName(QString::fromUtf8("spinBox_cluster_count"));
        sizePolicy.setHeightForWidth(spinBox_cluster_count->sizePolicy().hasHeightForWidth());
        spinBox_cluster_count->setSizePolicy(sizePolicy);
        spinBox_cluster_count->setMaximum(99999);
        spinBox_cluster_count->setValue(1);

        horizontalLayout_2->addWidget(spinBox_cluster_count);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

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


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\350\201\232\347\261\273\345\244\204\347\220\206", nullptr));
        label->setText(QApplication::translate("Dialog", "\350\201\232\347\261\273\345\233\276\345\261\202\357\274\232", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "\345\217\202\346\225\260", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\350\201\232\347\261\273\344\270\252\346\225\260\357\274\232", nullptr));
        ok_pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        cancel_pushButton->setText(QApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSCLUSTERDIALOG_H
