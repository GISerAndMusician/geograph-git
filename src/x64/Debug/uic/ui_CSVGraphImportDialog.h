/********************************************************************************
** Form generated from reading UI file 'CSVGraphImportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVGRAPHIMPORTDIALOG_H
#define UI_CSVGRAPHIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSVGraphImportDialog
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxNode;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelNodeFileName;
    QLineEdit *lineEditNodeFileName;
    QToolButton *toolButtonNodeFileBrowser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelNodeLayerName;
    QLineEdit *lineEditNodeLayerName;
    QLabel *labelNodeFileSpilter;
    QComboBox *comboBoxNodeFileSpliter;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelNodeX;
    QComboBox *comboBoxXHeaders;
    QLabel *labelNodeY;
    QComboBox *comboBoxYHeaders;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelNodeId;
    QComboBox *comboBoxIdHeaders;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSelectNodeHeaders;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxAllNodeHeaders;
    QListWidget *listWidgetNodeHeaders;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelCRS;
    QLineEdit *lineEditCRS;
    QToolButton *toolButtonCRS;
    QGroupBox *groupBoxRelation;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelEdgeFileName;
    QLineEdit *lineEditEdgeFileName;
    QToolButton *toolButtonEdgeFileBrowser;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelEdgeLayerName;
    QLineEdit *lineEditEdgeLayerName;
    QLabel *labelEdgeFileSpilter;
    QComboBox *comboBoxEdgeFileSpliter;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelEdgeSource;
    QComboBox *comboBoxEdgeSourceHeaders;
    QLabel *labelEdgeTarget;
    QComboBox *comboBoxEdgeTargetHeaders;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelSelectEdgeHeaders;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxAllEdgeHeaders;
    QListWidget *listWidgetEdgeHeaders;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CSVGraphImportDialog)
    {
        if (CSVGraphImportDialog->objectName().isEmpty())
            CSVGraphImportDialog->setObjectName(QString::fromUtf8("CSVGraphImportDialog"));
        CSVGraphImportDialog->resize(716, 709);
        gridLayout_3 = new QGridLayout(CSVGraphImportDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBoxNode = new QGroupBox(CSVGraphImportDialog);
        groupBoxNode->setObjectName(QString::fromUtf8("groupBoxNode"));
        gridLayout = new QGridLayout(groupBoxNode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelNodeFileName = new QLabel(groupBoxNode);
        labelNodeFileName->setObjectName(QString::fromUtf8("labelNodeFileName"));

        horizontalLayout_3->addWidget(labelNodeFileName);

        lineEditNodeFileName = new QLineEdit(groupBoxNode);
        lineEditNodeFileName->setObjectName(QString::fromUtf8("lineEditNodeFileName"));

        horizontalLayout_3->addWidget(lineEditNodeFileName);

        toolButtonNodeFileBrowser = new QToolButton(groupBoxNode);
        toolButtonNodeFileBrowser->setObjectName(QString::fromUtf8("toolButtonNodeFileBrowser"));

        horizontalLayout_3->addWidget(toolButtonNodeFileBrowser);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelNodeLayerName = new QLabel(groupBoxNode);
        labelNodeLayerName->setObjectName(QString::fromUtf8("labelNodeLayerName"));

        horizontalLayout_4->addWidget(labelNodeLayerName);

        lineEditNodeLayerName = new QLineEdit(groupBoxNode);
        lineEditNodeLayerName->setObjectName(QString::fromUtf8("lineEditNodeLayerName"));

        horizontalLayout_4->addWidget(lineEditNodeLayerName);

        labelNodeFileSpilter = new QLabel(groupBoxNode);
        labelNodeFileSpilter->setObjectName(QString::fromUtf8("labelNodeFileSpilter"));

        horizontalLayout_4->addWidget(labelNodeFileSpilter);

        comboBoxNodeFileSpliter = new QComboBox(groupBoxNode);
        comboBoxNodeFileSpliter->setObjectName(QString::fromUtf8("comboBoxNodeFileSpliter"));
        comboBoxNodeFileSpliter->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(comboBoxNodeFileSpliter);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelNodeX = new QLabel(groupBoxNode);
        labelNodeX->setObjectName(QString::fromUtf8("labelNodeX"));

        horizontalLayout_2->addWidget(labelNodeX);

        comboBoxXHeaders = new QComboBox(groupBoxNode);
        comboBoxXHeaders->setObjectName(QString::fromUtf8("comboBoxXHeaders"));
        comboBoxXHeaders->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboBoxXHeaders);

        labelNodeY = new QLabel(groupBoxNode);
        labelNodeY->setObjectName(QString::fromUtf8("labelNodeY"));

        horizontalLayout_2->addWidget(labelNodeY);

        comboBoxYHeaders = new QComboBox(groupBoxNode);
        comboBoxYHeaders->setObjectName(QString::fromUtf8("comboBoxYHeaders"));
        comboBoxYHeaders->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboBoxYHeaders);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelNodeId = new QLabel(groupBoxNode);
        labelNodeId->setObjectName(QString::fromUtf8("labelNodeId"));

        horizontalLayout_2->addWidget(labelNodeId);

        comboBoxIdHeaders = new QComboBox(groupBoxNode);
        comboBoxIdHeaders->setObjectName(QString::fromUtf8("comboBoxIdHeaders"));
        comboBoxIdHeaders->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboBoxIdHeaders);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelSelectNodeHeaders = new QLabel(groupBoxNode);
        labelSelectNodeHeaders->setObjectName(QString::fromUtf8("labelSelectNodeHeaders"));

        horizontalLayout->addWidget(labelSelectNodeHeaders);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBoxAllNodeHeaders = new QCheckBox(groupBoxNode);
        checkBoxAllNodeHeaders->setObjectName(QString::fromUtf8("checkBoxAllNodeHeaders"));
        checkBoxAllNodeHeaders->setChecked(false);

        horizontalLayout->addWidget(checkBoxAllNodeHeaders);


        verticalLayout->addLayout(horizontalLayout);

        listWidgetNodeHeaders = new QListWidget(groupBoxNode);
        listWidgetNodeHeaders->setObjectName(QString::fromUtf8("listWidgetNodeHeaders"));

        verticalLayout->addWidget(listWidgetNodeHeaders);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labelCRS = new QLabel(groupBoxNode);
        labelCRS->setObjectName(QString::fromUtf8("labelCRS"));

        horizontalLayout_9->addWidget(labelCRS);

        lineEditCRS = new QLineEdit(groupBoxNode);
        lineEditCRS->setObjectName(QString::fromUtf8("lineEditCRS"));

        horizontalLayout_9->addWidget(lineEditCRS);

        toolButtonCRS = new QToolButton(groupBoxNode);
        toolButtonCRS->setObjectName(QString::fromUtf8("toolButtonCRS"));

        horizontalLayout_9->addWidget(toolButtonCRS);


        verticalLayout->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBoxNode);

        groupBoxRelation = new QGroupBox(CSVGraphImportDialog);
        groupBoxRelation->setObjectName(QString::fromUtf8("groupBoxRelation"));
        gridLayout_2 = new QGridLayout(groupBoxRelation);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelEdgeFileName = new QLabel(groupBoxRelation);
        labelEdgeFileName->setObjectName(QString::fromUtf8("labelEdgeFileName"));

        horizontalLayout_5->addWidget(labelEdgeFileName);

        lineEditEdgeFileName = new QLineEdit(groupBoxRelation);
        lineEditEdgeFileName->setObjectName(QString::fromUtf8("lineEditEdgeFileName"));

        horizontalLayout_5->addWidget(lineEditEdgeFileName);

        toolButtonEdgeFileBrowser = new QToolButton(groupBoxRelation);
        toolButtonEdgeFileBrowser->setObjectName(QString::fromUtf8("toolButtonEdgeFileBrowser"));

        horizontalLayout_5->addWidget(toolButtonEdgeFileBrowser);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelEdgeLayerName = new QLabel(groupBoxRelation);
        labelEdgeLayerName->setObjectName(QString::fromUtf8("labelEdgeLayerName"));

        horizontalLayout_6->addWidget(labelEdgeLayerName);

        lineEditEdgeLayerName = new QLineEdit(groupBoxRelation);
        lineEditEdgeLayerName->setObjectName(QString::fromUtf8("lineEditEdgeLayerName"));

        horizontalLayout_6->addWidget(lineEditEdgeLayerName);

        labelEdgeFileSpilter = new QLabel(groupBoxRelation);
        labelEdgeFileSpilter->setObjectName(QString::fromUtf8("labelEdgeFileSpilter"));

        horizontalLayout_6->addWidget(labelEdgeFileSpilter);

        comboBoxEdgeFileSpliter = new QComboBox(groupBoxRelation);
        comboBoxEdgeFileSpliter->setObjectName(QString::fromUtf8("comboBoxEdgeFileSpliter"));
        comboBoxEdgeFileSpliter->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(comboBoxEdgeFileSpliter);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelEdgeSource = new QLabel(groupBoxRelation);
        labelEdgeSource->setObjectName(QString::fromUtf8("labelEdgeSource"));

        horizontalLayout_8->addWidget(labelEdgeSource);

        comboBoxEdgeSourceHeaders = new QComboBox(groupBoxRelation);
        comboBoxEdgeSourceHeaders->setObjectName(QString::fromUtf8("comboBoxEdgeSourceHeaders"));
        comboBoxEdgeSourceHeaders->setMinimumSize(QSize(120, 0));

        horizontalLayout_8->addWidget(comboBoxEdgeSourceHeaders);

        labelEdgeTarget = new QLabel(groupBoxRelation);
        labelEdgeTarget->setObjectName(QString::fromUtf8("labelEdgeTarget"));

        horizontalLayout_8->addWidget(labelEdgeTarget);

        comboBoxEdgeTargetHeaders = new QComboBox(groupBoxRelation);
        comboBoxEdgeTargetHeaders->setObjectName(QString::fromUtf8("comboBoxEdgeTargetHeaders"));
        comboBoxEdgeTargetHeaders->setMinimumSize(QSize(120, 0));

        horizontalLayout_8->addWidget(comboBoxEdgeTargetHeaders);

        horizontalSpacer_3 = new QSpacerItem(47, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelSelectEdgeHeaders = new QLabel(groupBoxRelation);
        labelSelectEdgeHeaders->setObjectName(QString::fromUtf8("labelSelectEdgeHeaders"));

        horizontalLayout_7->addWidget(labelSelectEdgeHeaders);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        checkBoxAllEdgeHeaders = new QCheckBox(groupBoxRelation);
        checkBoxAllEdgeHeaders->setObjectName(QString::fromUtf8("checkBoxAllEdgeHeaders"));
        checkBoxAllEdgeHeaders->setChecked(false);

        horizontalLayout_7->addWidget(checkBoxAllEdgeHeaders);


        verticalLayout_2->addLayout(horizontalLayout_7);

        listWidgetEdgeHeaders = new QListWidget(groupBoxRelation);
        listWidgetEdgeHeaders->setObjectName(QString::fromUtf8("listWidgetEdgeHeaders"));

        verticalLayout_2->addWidget(listWidgetEdgeHeaders);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBoxRelation);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(CSVGraphImportDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(CSVGraphImportDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout_3->addLayout(hboxLayout);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(CSVGraphImportDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), CSVGraphImportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CSVGraphImportDialog);
    } // setupUi

    void retranslateUi(QDialog *CSVGraphImportDialog)
    {
        CSVGraphImportDialog->setWindowTitle(QApplication::translate("CSVGraphImportDialog", "CSV\345\233\276\346\225\260\346\215\256\345\212\240\350\275\275", nullptr));
        groupBoxNode->setTitle(QApplication::translate("CSVGraphImportDialog", "\350\212\202\347\202\271", nullptr));
        labelNodeFileName->setText(QApplication::translate("CSVGraphImportDialog", "\350\212\202\347\202\271\346\226\207\344\273\266\357\274\232", nullptr));
        toolButtonNodeFileBrowser->setText(QApplication::translate("CSVGraphImportDialog", "\342\200\246", nullptr));
        labelNodeLayerName->setText(QApplication::translate("CSVGraphImportDialog", "\345\233\276\345\261\202\345\220\215\347\247\260\357\274\232", nullptr));
        labelNodeFileSpilter->setText(QApplication::translate("CSVGraphImportDialog", "\345\210\206\351\232\224\347\254\246\357\274\232", nullptr));
        labelNodeX->setText(QApplication::translate("CSVGraphImportDialog", "X\345\235\220\346\240\207\357\274\232", nullptr));
        labelNodeY->setText(QApplication::translate("CSVGraphImportDialog", "Y\345\235\220\346\240\207\357\274\232", nullptr));
        labelNodeId->setText(QApplication::translate("CSVGraphImportDialog", "\346\240\207\350\257\206\345\255\227\346\256\265\357\274\232", nullptr));
        labelSelectNodeHeaders->setText(QApplication::translate("CSVGraphImportDialog", "\350\257\267\345\213\276\351\200\211\351\234\200\350\246\201\344\277\235\347\225\231\347\232\204\350\212\202\347\202\271\345\261\236\346\200\247\357\274\232", nullptr));
        checkBoxAllNodeHeaders->setText(QApplication::translate("CSVGraphImportDialog", "\345\205\250\351\200\211", nullptr));
        labelCRS->setText(QApplication::translate("CSVGraphImportDialog", "\350\257\267\350\256\276\347\275\256\345\233\276\345\261\202CRS\357\274\232", nullptr));
        toolButtonCRS->setText(QApplication::translate("CSVGraphImportDialog", "\342\200\246", nullptr));
        groupBoxRelation->setTitle(QApplication::translate("CSVGraphImportDialog", "\350\277\236\350\276\271", nullptr));
        labelEdgeFileName->setText(QApplication::translate("CSVGraphImportDialog", "\350\277\236\350\276\271\346\226\207\344\273\266\357\274\232", nullptr));
        toolButtonEdgeFileBrowser->setText(QApplication::translate("CSVGraphImportDialog", "\342\200\246", nullptr));
        labelEdgeLayerName->setText(QApplication::translate("CSVGraphImportDialog", "\345\233\276\345\261\202\345\261\202\345\220\215\357\274\232", nullptr));
        labelEdgeFileSpilter->setText(QApplication::translate("CSVGraphImportDialog", "\345\210\206\351\232\224\347\254\246\357\274\232", nullptr));
        labelEdgeSource->setText(QApplication::translate("CSVGraphImportDialog", "\346\272\220\357\274\232", nullptr));
        labelEdgeTarget->setText(QApplication::translate("CSVGraphImportDialog", "\345\256\277\357\274\232", nullptr));
        labelSelectEdgeHeaders->setText(QApplication::translate("CSVGraphImportDialog", "\350\257\267\345\213\276\351\200\211\351\234\200\350\246\201\344\277\235\347\225\231\347\232\204\350\277\236\350\276\271\345\261\236\346\200\247\357\274\232", nullptr));
        checkBoxAllEdgeHeaders->setText(QApplication::translate("CSVGraphImportDialog", "\345\205\250\351\200\211", nullptr));
        okButton->setText(QApplication::translate("CSVGraphImportDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("CSVGraphImportDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSVGraphImportDialog: public Ui_CSVGraphImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVGRAPHIMPORTDIALOG_H
