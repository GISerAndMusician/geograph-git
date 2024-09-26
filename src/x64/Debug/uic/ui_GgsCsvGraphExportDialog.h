/********************************************************************************
** Form generated from reading UI file 'GgsCsvGraphExportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSCSVGRAPHEXPORTDIALOG_H
#define UI_GGSCSVGRAPHEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
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

class Ui_GgsCsvGraphExportDialog
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_filename;
    QLineEdit *lineEdit_filename;
    QLabel *label_filepath;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_filepath;
    QToolButton *toolButton_filepath;
    QHBoxLayout *hboxLayout;
    QProgressBar *progressBar;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *GgsCsvGraphExportDialog)
    {
        if (GgsCsvGraphExportDialog->objectName().isEmpty())
            GgsCsvGraphExportDialog->setObjectName(QString::fromUtf8("GgsCsvGraphExportDialog"));
        GgsCsvGraphExportDialog->resize(426, 117);
        formLayout = new QFormLayout(GgsCsvGraphExportDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_filename = new QLabel(GgsCsvGraphExportDialog);
        label_filename->setObjectName(QString::fromUtf8("label_filename"));

        gridLayout->addWidget(label_filename, 0, 0, 1, 1);

        lineEdit_filename = new QLineEdit(GgsCsvGraphExportDialog);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));

        gridLayout->addWidget(lineEdit_filename, 0, 1, 1, 1);

        label_filepath = new QLabel(GgsCsvGraphExportDialog);
        label_filepath->setObjectName(QString::fromUtf8("label_filepath"));

        gridLayout->addWidget(label_filepath, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_filepath = new QLineEdit(GgsCsvGraphExportDialog);
        lineEdit_filepath->setObjectName(QString::fromUtf8("lineEdit_filepath"));

        horizontalLayout->addWidget(lineEdit_filepath);

        toolButton_filepath = new QToolButton(GgsCsvGraphExportDialog);
        toolButton_filepath->setObjectName(QString::fromUtf8("toolButton_filepath"));

        horizontalLayout->addWidget(toolButton_filepath);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(GgsCsvGraphExportDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(200, 0));
        progressBar->setValue(24);

        hboxLayout->addWidget(progressBar);

        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(GgsCsvGraphExportDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(GgsCsvGraphExportDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout);


        retranslateUi(GgsCsvGraphExportDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), GgsCsvGraphExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GgsCsvGraphExportDialog);
    } // setupUi

    void retranslateUi(QDialog *GgsCsvGraphExportDialog)
    {
        GgsCsvGraphExportDialog->setWindowTitle(QApplication::translate("GgsCsvGraphExportDialog", "\345\257\274\345\207\272CSV\346\240\274\345\274\217\345\233\276\346\225\260\346\215\256", nullptr));
        label_filename->setText(QApplication::translate("GgsCsvGraphExportDialog", "\345\233\276\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_filepath->setText(QApplication::translate("GgsCsvGraphExportDialog", "\345\257\274\345\207\272\350\267\257\345\276\204\357\274\232", nullptr));
        toolButton_filepath->setText(QApplication::translate("GgsCsvGraphExportDialog", "...", nullptr));
        okButton->setText(QApplication::translate("GgsCsvGraphExportDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("GgsCsvGraphExportDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GgsCsvGraphExportDialog: public Ui_GgsCsvGraphExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSCSVGRAPHEXPORTDIALOG_H
