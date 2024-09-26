/********************************************************************************
** Form generated from reading UI file 'GgsODDataDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSODDATADIALOG_H
#define UI_GGSODDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ODDataDialog
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDataSource;
    QToolButton *toolButtonExplore;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelSpilter;
    QComboBox *comboBoxSpliter;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_OX;
    QComboBox *comboBox_OY;
    QLabel *label_3;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QComboBox *comboBox_DX;
    QLabel *label_5;
    QComboBox *comboBox_DY;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelCRS;
    QLineEdit *lineEditCRS;
    QToolButton *toolButtonCRS;
    QHBoxLayout *horizontalLayout_3;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *ODDataDialog)
    {
        if (ODDataDialog->objectName().isEmpty())
            ODDataDialog->setObjectName(QString::fromUtf8("ODDataDialog"));
        ODDataDialog->resize(462, 204);
        gridLayout_3 = new QGridLayout(ODDataDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ODDataDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditDataSource = new QLineEdit(ODDataDialog);
        lineEditDataSource->setObjectName(QString::fromUtf8("lineEditDataSource"));

        horizontalLayout->addWidget(lineEditDataSource);

        toolButtonExplore = new QToolButton(ODDataDialog);
        toolButtonExplore->setObjectName(QString::fromUtf8("toolButtonExplore"));

        horizontalLayout->addWidget(toolButtonExplore);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelSpilter = new QLabel(ODDataDialog);
        labelSpilter->setObjectName(QString::fromUtf8("labelSpilter"));

        horizontalLayout_4->addWidget(labelSpilter);

        comboBoxSpliter = new QComboBox(ODDataDialog);
        comboBoxSpliter->setObjectName(QString::fromUtf8("comboBoxSpliter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxSpliter->sizePolicy().hasHeightForWidth());
        comboBoxSpliter->setSizePolicy(sizePolicy);
        comboBoxSpliter->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(comboBoxSpliter);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_OX = new QComboBox(ODDataDialog);
        comboBox_OX->setObjectName(QString::fromUtf8("comboBox_OX"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_OX->sizePolicy().hasHeightForWidth());
        comboBox_OX->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_OX, 0, 1, 1, 1);

        comboBox_OY = new QComboBox(ODDataDialog);
        comboBox_OY->setObjectName(QString::fromUtf8("comboBox_OY"));
        sizePolicy1.setHeightForWidth(comboBox_OY->sizePolicy().hasHeightForWidth());
        comboBox_OY->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_OY, 1, 1, 1, 1);

        label_3 = new QLabel(ODDataDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(ODDataDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(ODDataDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        comboBox_DX = new QComboBox(ODDataDialog);
        comboBox_DX->setObjectName(QString::fromUtf8("comboBox_DX"));
        sizePolicy1.setHeightForWidth(comboBox_DX->sizePolicy().hasHeightForWidth());
        comboBox_DX->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(comboBox_DX, 0, 1, 1, 1);

        label_5 = new QLabel(ODDataDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        comboBox_DY = new QComboBox(ODDataDialog);
        comboBox_DY->setObjectName(QString::fromUtf8("comboBox_DY"));
        sizePolicy1.setHeightForWidth(comboBox_DY->sizePolicy().hasHeightForWidth());
        comboBox_DY->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(comboBox_DY, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelCRS = new QLabel(ODDataDialog);
        labelCRS->setObjectName(QString::fromUtf8("labelCRS"));

        horizontalLayout_9->addWidget(labelCRS);

        lineEditCRS = new QLineEdit(ODDataDialog);
        lineEditCRS->setObjectName(QString::fromUtf8("lineEditCRS"));

        horizontalLayout_9->addWidget(lineEditCRS);

        toolButtonCRS = new QToolButton(ODDataDialog);
        toolButtonCRS->setObjectName(QString::fromUtf8("toolButtonCRS"));

        horizontalLayout_9->addWidget(toolButtonCRS);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        progressBar = new QProgressBar(ODDataDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_3->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(ODDataDialog);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        horizontalLayout_3->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(ODDataDialog);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ODDataDialog);

        QMetaObject::connectSlotsByName(ODDataDialog);
    } // setupUi

    void retranslateUi(QDialog *ODDataDialog)
    {
        ODDataDialog->setWindowTitle(QApplication::translate("ODDataDialog", "\345\212\240\350\275\275OD\346\225\260\346\215\256\345\233\276\345\261\202", nullptr));
        label->setText(QApplication::translate("ODDataDialog", "\346\225\260\346\215\256\346\272\220\357\274\232", nullptr));
        toolButtonExplore->setText(QApplication::translate("ODDataDialog", "...", nullptr));
        labelSpilter->setText(QApplication::translate("ODDataDialog", "\345\210\206\351\232\224\347\254\246\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ODDataDialog", "\350\265\267\345\247\213Y\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ODDataDialog", "\350\265\267\345\247\213X\357\274\232", nullptr));
        label_4->setText(QApplication::translate("ODDataDialog", "\347\273\210\346\255\242X\357\274\232", nullptr));
        label_5->setText(QApplication::translate("ODDataDialog", "\347\273\210\346\255\242Y\357\274\232", nullptr));
        labelCRS->setText(QApplication::translate("ODDataDialog", "\350\257\267\350\256\276\347\275\256\345\233\276\345\261\202CRS\357\274\232", nullptr));
        toolButtonCRS->setText(QApplication::translate("ODDataDialog", "\342\200\246", nullptr));
        pushButton_ok->setText(QApplication::translate("ODDataDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_cancel->setText(QApplication::translate("ODDataDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ODDataDialog: public Ui_ODDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSODDATADIALOG_H
