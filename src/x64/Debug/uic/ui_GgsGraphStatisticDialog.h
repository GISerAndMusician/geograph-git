/********************************************************************************
** Form generated from reading UI file 'GgsGraphStatisticDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSGRAPHSTATISTICDIALOG_H
#define UI_GGSGRAPHSTATISTICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GraphStatisticDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_type;
    QFormLayout *formLayout_type;
    QVBoxLayout *verticalLayout_type;
    QCheckBox *checkBox_centrality;
    QCheckBox *checkBox_betweeness;
    QCheckBox *checkBox_closeness;
    QGroupBox *groupBox_style;
    QFormLayout *formLayout_style;
    QHBoxLayout *layout_buttons;
    QCheckBox *checkBox_coverData;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *GraphStatisticDialog)
    {
        if (GraphStatisticDialog->objectName().isEmpty())
            GraphStatisticDialog->setObjectName(QString::fromUtf8("GraphStatisticDialog"));
        GraphStatisticDialog->resize(606, 222);
        formLayout = new QFormLayout(GraphStatisticDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_type = new QGroupBox(GraphStatisticDialog);
        groupBox_type->setObjectName(QString::fromUtf8("groupBox_type"));
        formLayout_type = new QFormLayout(groupBox_type);
        formLayout_type->setObjectName(QString::fromUtf8("formLayout_type"));
        verticalLayout_type = new QVBoxLayout();
        verticalLayout_type->setObjectName(QString::fromUtf8("verticalLayout_type"));
        checkBox_centrality = new QCheckBox(groupBox_type);
        checkBox_centrality->setObjectName(QString::fromUtf8("checkBox_centrality"));
        checkBox_centrality->setChecked(true);

        verticalLayout_type->addWidget(checkBox_centrality);

        checkBox_betweeness = new QCheckBox(groupBox_type);
        checkBox_betweeness->setObjectName(QString::fromUtf8("checkBox_betweeness"));

        verticalLayout_type->addWidget(checkBox_betweeness);

        checkBox_closeness = new QCheckBox(groupBox_type);
        checkBox_closeness->setObjectName(QString::fromUtf8("checkBox_closeness"));

        verticalLayout_type->addWidget(checkBox_closeness);


        formLayout_type->setLayout(0, QFormLayout::FieldRole, verticalLayout_type);


        verticalLayout->addWidget(groupBox_type);

        groupBox_style = new QGroupBox(GraphStatisticDialog);
        groupBox_style->setObjectName(QString::fromUtf8("groupBox_style"));
        formLayout_style = new QFormLayout(groupBox_style);
        formLayout_style->setObjectName(QString::fromUtf8("formLayout_style"));

        verticalLayout->addWidget(groupBox_style);

        layout_buttons = new QHBoxLayout();
        layout_buttons->setSpacing(6);
        layout_buttons->setObjectName(QString::fromUtf8("layout_buttons"));
        layout_buttons->setContentsMargins(0, 0, 0, 0);
        checkBox_coverData = new QCheckBox(GraphStatisticDialog);
        checkBox_coverData->setObjectName(QString::fromUtf8("checkBox_coverData"));
        checkBox_coverData->setChecked(true);

        layout_buttons->addWidget(checkBox_coverData);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_buttons->addItem(spacerItem);

        okButton = new QPushButton(GraphStatisticDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        layout_buttons->addWidget(okButton);

        cancelButton = new QPushButton(GraphStatisticDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        layout_buttons->addWidget(cancelButton);


        verticalLayout->addLayout(layout_buttons);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        retranslateUi(GraphStatisticDialog);
        QObject::connect(okButton, SIGNAL(clicked()), GraphStatisticDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), GraphStatisticDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GraphStatisticDialog);
    } // setupUi

    void retranslateUi(QDialog *GraphStatisticDialog)
    {
        GraphStatisticDialog->setWindowTitle(QApplication::translate("GraphStatisticDialog", "\345\244\215\346\235\202\347\275\221\347\273\234\347\273\237\350\256\241\346\214\207\346\240\207", nullptr));
        groupBox_type->setTitle(QApplication::translate("GraphStatisticDialog", "\346\214\207\346\240\207\347\261\273\345\236\213", nullptr));
        checkBox_centrality->setText(QApplication::translate("GraphStatisticDialog", "\345\272\246\343\200\201\344\273\213\346\225\260\343\200\201\346\216\245\350\277\221\343\200\201\347\211\271\345\276\201\345\220\221\351\207\217\344\270\255\345\277\203\346\200\247\357\274\210Centrality\357\274\211", nullptr));
        checkBox_betweeness->setText(QApplication::translate("GraphStatisticDialog", "\345\237\272\344\272\216Pearson\347\233\270\345\205\263\347\263\273\346\225\260\347\232\204\345\272\246-\345\272\246\347\233\270\345\205\263\346\200\247\357\274\210Pearson Correlation Coefficient\357\274\211", nullptr));
        checkBox_closeness->setText(QApplication::translate("GraphStatisticDialog", "\345\257\214\344\272\272\344\277\261\344\271\220\351\203\250\347\263\273\346\225\260\357\274\210Rich Club Coefficient\357\274\211", nullptr));
        groupBox_style->setTitle(QApplication::translate("GraphStatisticDialog", "\346\270\262\346\237\223\346\240\267\345\274\217", nullptr));
        checkBox_coverData->setText(QApplication::translate("GraphStatisticDialog", "\345\260\206\347\273\237\350\256\241\347\273\223\346\236\234\345\206\231\345\205\245\345\233\276\345\261\202", nullptr));
        okButton->setText(QApplication::translate("GraphStatisticDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("GraphStatisticDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphStatisticDialog: public Ui_GraphStatisticDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSGRAPHSTATISTICDIALOG_H
