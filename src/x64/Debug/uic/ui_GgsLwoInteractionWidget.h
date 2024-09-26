/********************************************************************************
** Form generated from reading UI file 'GgsLwoInteractionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSLWOINTERACTIONWIDGET_H
#define UI_GGSLWOINTERACTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LWOWidget
{
public:
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *field_comboBox;
    QPushButton *updateComboBox_pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *nodeSize_doubleSpinBox;
    QLabel *label_3;
    QToolButton *nodeFillColor_toolButton;
    QLabel *label_4;
    QToolButton *nodeStrokeColor_toolButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QDoubleSpinBox *nodeRatio_doubleSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *labelSpan_doubleSpinBox;
    QLabel *label_8;
    QToolButton *cNodeFillColor_toolButton;
    QLabel *label_7;
    QToolButton *cNodeStrokeColor_toolButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *ok_pushButton;

    void setupUi(QWidget *LWOWidget)
    {
        if (LWOWidget->objectName().isEmpty())
            LWOWidget->setObjectName(QString::fromUtf8("LWOWidget"));
        LWOWidget->resize(351, 645);
        gridLayout_6 = new QGridLayout(LWOWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(LWOWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        field_comboBox = new QComboBox(groupBox);
        field_comboBox->setObjectName(QString::fromUtf8("field_comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(field_comboBox->sizePolicy().hasHeightForWidth());
        field_comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(field_comboBox);

        updateComboBox_pushButton = new QPushButton(groupBox);
        updateComboBox_pushButton->setObjectName(QString::fromUtf8("updateComboBox_pushButton"));

        horizontalLayout_3->addWidget(updateComboBox_pushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(LWOWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        nodeSize_doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        nodeSize_doubleSpinBox->setObjectName(QString::fromUtf8("nodeSize_doubleSpinBox"));
        sizePolicy.setHeightForWidth(nodeSize_doubleSpinBox->sizePolicy().hasHeightForWidth());
        nodeSize_doubleSpinBox->setSizePolicy(sizePolicy);
        nodeSize_doubleSpinBox->setMaximum(1000000000000000000.000000000000000);
        nodeSize_doubleSpinBox->setSingleStep(0.100000000000000);
        nodeSize_doubleSpinBox->setValue(0.400000000000000);

        gridLayout_2->addWidget(nodeSize_doubleSpinBox, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        nodeFillColor_toolButton = new QToolButton(groupBox_3);
        nodeFillColor_toolButton->setObjectName(QString::fromUtf8("nodeFillColor_toolButton"));
        sizePolicy.setHeightForWidth(nodeFillColor_toolButton->sizePolicy().hasHeightForWidth());
        nodeFillColor_toolButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(nodeFillColor_toolButton, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        nodeStrokeColor_toolButton = new QToolButton(groupBox_3);
        nodeStrokeColor_toolButton->setObjectName(QString::fromUtf8("nodeStrokeColor_toolButton"));
        sizePolicy.setHeightForWidth(nodeStrokeColor_toolButton->sizePolicy().hasHeightForWidth());
        nodeStrokeColor_toolButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(nodeStrokeColor_toolButton, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(LWOWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        nodeRatio_doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        nodeRatio_doubleSpinBox->setObjectName(QString::fromUtf8("nodeRatio_doubleSpinBox"));
        sizePolicy.setHeightForWidth(nodeRatio_doubleSpinBox->sizePolicy().hasHeightForWidth());
        nodeRatio_doubleSpinBox->setSizePolicy(sizePolicy);
        nodeRatio_doubleSpinBox->setSingleStep(0.100000000000000);
        nodeRatio_doubleSpinBox->setValue(2.000000000000000);

        gridLayout_4->addWidget(nodeRatio_doubleSpinBox, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 1, 0, 1, 1);

        labelSpan_doubleSpinBox = new QDoubleSpinBox(groupBox_2);
        labelSpan_doubleSpinBox->setObjectName(QString::fromUtf8("labelSpan_doubleSpinBox"));
        sizePolicy.setHeightForWidth(labelSpan_doubleSpinBox->sizePolicy().hasHeightForWidth());
        labelSpan_doubleSpinBox->setSizePolicy(sizePolicy);
        labelSpan_doubleSpinBox->setSingleStep(0.100000000000000);
        labelSpan_doubleSpinBox->setValue(2.000000000000000);

        gridLayout_4->addWidget(labelSpan_doubleSpinBox, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        cNodeFillColor_toolButton = new QToolButton(groupBox_2);
        cNodeFillColor_toolButton->setObjectName(QString::fromUtf8("cNodeFillColor_toolButton"));
        sizePolicy.setHeightForWidth(cNodeFillColor_toolButton->sizePolicy().hasHeightForWidth());
        cNodeFillColor_toolButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(cNodeFillColor_toolButton, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        cNodeStrokeColor_toolButton = new QToolButton(groupBox_2);
        cNodeStrokeColor_toolButton->setObjectName(QString::fromUtf8("cNodeStrokeColor_toolButton"));
        sizePolicy.setHeightForWidth(cNodeStrokeColor_toolButton->sizePolicy().hasHeightForWidth());
        cNodeStrokeColor_toolButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(cNodeStrokeColor_toolButton, 3, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        ok_pushButton = new QPushButton(LWOWidget);
        ok_pushButton->setObjectName(QString::fromUtf8("ok_pushButton"));

        horizontalLayout_2->addWidget(ok_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(LWOWidget);

        QMetaObject::connectSlotsByName(LWOWidget);
    } // setupUi

    void retranslateUi(QWidget *LWOWidget)
    {
        LWOWidget->setWindowTitle(QApplication::translate("LWOWidget", "LWO", nullptr));
        groupBox->setTitle(QApplication::translate("LWOWidget", "\346\230\276\347\244\272\345\255\227\346\256\265", nullptr));
        label->setText(QApplication::translate("LWOWidget", "\351\200\211\345\214\272\345\206\205\350\212\202\347\202\271\351\234\200\350\246\201\346\230\276\347\244\272\347\232\204\345\261\236\346\200\247\345\255\227\346\256\265\357\274\232", nullptr));
        updateComboBox_pushButton->setText(QApplication::translate("LWOWidget", "\345\210\267\346\226\260\345\255\227\346\256\265", nullptr));
        groupBox_3->setTitle(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\346\270\262\346\237\223\345\217\202\346\225\260", nullptr));
        label_2->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\345\260\272\345\257\270\357\274\232", nullptr));
        label_3->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\345\241\253\345\205\205\350\211\262\357\274\232", nullptr));
        nodeFillColor_toolButton->setText(QString());
        label_4->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\350\276\271\347\272\277\350\211\262\357\274\232", nullptr));
        nodeStrokeColor_toolButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("LWOWidget", "\351\200\211\345\214\272\345\206\205\350\212\202\347\202\271\346\270\262\346\237\223\345\217\202\346\225\260", nullptr));
        label_5->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\346\224\276\345\244\247\346\257\224\344\276\213\357\274\232", nullptr));
        label_6->setText(QApplication::translate("LWOWidget", "\346\240\207\347\255\276\345\201\217\347\247\273\350\267\235\347\246\273\357\274\232", nullptr));
        label_8->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\345\241\253\345\205\205\350\211\262\357\274\232", nullptr));
        cNodeFillColor_toolButton->setText(QString());
        label_7->setText(QApplication::translate("LWOWidget", "\350\212\202\347\202\271\350\276\271\347\272\277\350\211\262\357\274\232", nullptr));
        cNodeStrokeColor_toolButton->setText(QString());
        ok_pushButton->setText(QApplication::translate("LWOWidget", "\345\272\224\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LWOWidget: public Ui_LWOWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSLWOINTERACTIONWIDGET_H
