/********************************************************************************
** Form generated from reading UI file 'qgsmssqlnewconnectionbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSMSSQLNEWCONNECTIONBASE_H
#define UI_QGSMSSQLNEWCONNECTIONBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include "qgsmessagebar.h"
#include "qgspasswordlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsMssqlNewConnectionBase
{
public:
    QGridLayout *gridLayout;
    QgsMessageBar *bar;
    QGroupBox *GroupBox1;
    QFormLayout *formLayout;
    QLabel *TextLabel1_2;
    QLineEdit *txtName;
    QLabel *label;
    QLineEdit *txtService;
    QLabel *TextLabel1;
    QLineEdit *txtHost;
    QLabel *label_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QCheckBox *cb_trustedConnection;
    QLabel *TextLabel3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtUsername;
    QCheckBox *chkStoreUsername;
    QLabel *TextLabel3_2;
    QHBoxLayout *horizontalLayout_2;
    QgsPasswordLineEdit *txtPassword;
    QCheckBox *chkStorePassword;
    QLabel *lblWarning;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_3;
    QListWidget *listDatabase;
    QCheckBox *cb_allowGeometrylessTables;
    QCheckBox *cb_useEstimatedMetadata;
    QCheckBox *cb_geometryColumns;
    QPushButton *btnConnect;
    QPushButton *btnListDatabase;
    QLabel *TextLabel2;
    QCheckBox *mCheckNoInvalidGeometryHandling;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsMssqlNewConnectionBase)
    {
        if (QgsMssqlNewConnectionBase->objectName().isEmpty())
            QgsMssqlNewConnectionBase->setObjectName(QString::fromUtf8("QgsMssqlNewConnectionBase"));
        QgsMssqlNewConnectionBase->resize(772, 575);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QgsMssqlNewConnectionBase->sizePolicy().hasHeightForWidth());
        QgsMssqlNewConnectionBase->setSizePolicy(sizePolicy);
        QgsMssqlNewConnectionBase->setSizeGripEnabled(true);
        QgsMssqlNewConnectionBase->setModal(true);
        gridLayout = new QGridLayout(QgsMssqlNewConnectionBase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 0, 9, 9);
        bar = new QgsMessageBar(QgsMssqlNewConnectionBase);
        bar->setObjectName(QString::fromUtf8("bar"));

        gridLayout->addWidget(bar, 0, 0, 1, 2);

        GroupBox1 = new QGroupBox(QgsMssqlNewConnectionBase);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        formLayout = new QFormLayout(GroupBox1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        TextLabel1_2 = new QLabel(GroupBox1);
        TextLabel1_2->setObjectName(QString::fromUtf8("TextLabel1_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, TextLabel1_2);

        txtName = new QLineEdit(GroupBox1);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtName);

        label = new QLabel(GroupBox1);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        txtService = new QLineEdit(GroupBox1);
        txtService->setObjectName(QString::fromUtf8("txtService"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtService);

        TextLabel1 = new QLabel(GroupBox1);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));

        formLayout->setWidget(2, QFormLayout::LabelRole, TextLabel1);

        txtHost = new QLineEdit(GroupBox1);
        txtHost->setObjectName(QString::fromUtf8("txtHost"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtHost);

        label_2 = new QLabel(GroupBox1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        groupBox = new QGroupBox(GroupBox1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        cb_trustedConnection = new QCheckBox(groupBox);
        cb_trustedConnection->setObjectName(QString::fromUtf8("cb_trustedConnection"));
        cb_trustedConnection->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, cb_trustedConnection);

        TextLabel3 = new QLabel(groupBox);
        TextLabel3->setObjectName(QString::fromUtf8("TextLabel3"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, TextLabel3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        txtUsername = new QLineEdit(groupBox);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        txtUsername->setEnabled(false);

        horizontalLayout->addWidget(txtUsername);

        chkStoreUsername = new QCheckBox(groupBox);
        chkStoreUsername->setObjectName(QString::fromUtf8("chkStoreUsername"));
        chkStoreUsername->setEnabled(false);

        horizontalLayout->addWidget(chkStoreUsername);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        TextLabel3_2 = new QLabel(groupBox);
        TextLabel3_2->setObjectName(QString::fromUtf8("TextLabel3_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, TextLabel3_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        txtPassword = new QgsPasswordLineEdit(groupBox);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setEnabled(false);
        txtPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtPassword);

        chkStorePassword = new QCheckBox(groupBox);
        chkStorePassword->setObjectName(QString::fromUtf8("chkStorePassword"));
        chkStorePassword->setEnabled(false);

        horizontalLayout_2->addWidget(chkStorePassword);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        lblWarning = new QLabel(groupBox);
        lblWarning->setObjectName(QString::fromUtf8("lblWarning"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblWarning->sizePolicy().hasHeightForWidth());
        lblWarning->setSizePolicy(sizePolicy1);
        lblWarning->setWordWrap(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lblWarning);


        formLayout->setWidget(3, QFormLayout::SpanningRole, groupBox);


        gridLayout->addWidget(GroupBox1, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(QgsMssqlNewConnectionBase);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_3 = new QFormLayout(groupBox_2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        listDatabase = new QListWidget(groupBox_2);
        listDatabase->setObjectName(QString::fromUtf8("listDatabase"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, listDatabase);

        cb_allowGeometrylessTables = new QCheckBox(groupBox_2);
        cb_allowGeometrylessTables->setObjectName(QString::fromUtf8("cb_allowGeometrylessTables"));

        formLayout_3->setWidget(3, QFormLayout::SpanningRole, cb_allowGeometrylessTables);

        cb_useEstimatedMetadata = new QCheckBox(groupBox_2);
        cb_useEstimatedMetadata->setObjectName(QString::fromUtf8("cb_useEstimatedMetadata"));
        cb_useEstimatedMetadata->setChecked(true);

        formLayout_3->setWidget(4, QFormLayout::SpanningRole, cb_useEstimatedMetadata);

        cb_geometryColumns = new QCheckBox(groupBox_2);
        cb_geometryColumns->setObjectName(QString::fromUtf8("cb_geometryColumns"));
        cb_geometryColumns->setChecked(false);

        formLayout_3->setWidget(2, QFormLayout::SpanningRole, cb_geometryColumns);

        btnConnect = new QPushButton(groupBox_2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        formLayout_3->setWidget(6, QFormLayout::SpanningRole, btnConnect);

        btnListDatabase = new QPushButton(groupBox_2);
        btnListDatabase->setObjectName(QString::fromUtf8("btnListDatabase"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, btnListDatabase);

        TextLabel2 = new QLabel(groupBox_2);
        TextLabel2->setObjectName(QString::fromUtf8("TextLabel2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, TextLabel2);

        mCheckNoInvalidGeometryHandling = new QCheckBox(groupBox_2);
        mCheckNoInvalidGeometryHandling->setObjectName(QString::fromUtf8("mCheckNoInvalidGeometryHandling"));
        mCheckNoInvalidGeometryHandling->setChecked(false);

        formLayout_3->setWidget(5, QFormLayout::SpanningRole, mCheckNoInvalidGeometryHandling);


        gridLayout->addWidget(groupBox_2, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(QgsMssqlNewConnectionBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);

        QWidget::setTabOrder(txtName, txtService);
        QWidget::setTabOrder(txtService, txtHost);
        QWidget::setTabOrder(txtHost, cb_trustedConnection);
        QWidget::setTabOrder(cb_trustedConnection, txtUsername);
        QWidget::setTabOrder(txtUsername, chkStoreUsername);
        QWidget::setTabOrder(chkStoreUsername, txtPassword);
        QWidget::setTabOrder(txtPassword, chkStorePassword);
        QWidget::setTabOrder(chkStorePassword, btnListDatabase);
        QWidget::setTabOrder(btnListDatabase, listDatabase);
        QWidget::setTabOrder(listDatabase, cb_geometryColumns);
        QWidget::setTabOrder(cb_geometryColumns, cb_allowGeometrylessTables);
        QWidget::setTabOrder(cb_allowGeometrylessTables, cb_useEstimatedMetadata);
        QWidget::setTabOrder(cb_useEstimatedMetadata, mCheckNoInvalidGeometryHandling);
        QWidget::setTabOrder(mCheckNoInvalidGeometryHandling, btnConnect);

        retranslateUi(QgsMssqlNewConnectionBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsMssqlNewConnectionBase, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsMssqlNewConnectionBase, SLOT(accept()));
        QObject::connect(cb_trustedConnection, SIGNAL(toggled(bool)), chkStoreUsername, SLOT(setDisabled(bool)));
        QObject::connect(cb_trustedConnection, SIGNAL(toggled(bool)), chkStorePassword, SLOT(setDisabled(bool)));
        QObject::connect(cb_trustedConnection, SIGNAL(toggled(bool)), txtUsername, SLOT(setDisabled(bool)));
        QObject::connect(cb_trustedConnection, SIGNAL(toggled(bool)), txtPassword, SLOT(setDisabled(bool)));
        QObject::connect(chkStorePassword, SIGNAL(toggled(bool)), lblWarning, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(QgsMssqlNewConnectionBase);
    } // setupUi

    void retranslateUi(QDialog *QgsMssqlNewConnectionBase)
    {
        QgsMssqlNewConnectionBase->setWindowTitle(QApplication::translate("QgsMssqlNewConnectionBase", "Create a New MSSQL Connection", nullptr));
        GroupBox1->setTitle(QApplication::translate("QgsMssqlNewConnectionBase", "Connection Details", nullptr));
        TextLabel1_2->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Connection name", nullptr));
#ifndef QT_NO_TOOLTIP
        txtName->setToolTip(QApplication::translate("QgsMssqlNewConnectionBase", "Name of the new connection", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Provider/DSN", nullptr));
        TextLabel1->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Host", nullptr));
        label_2->setText(QString());
        groupBox->setTitle(QApplication::translate("QgsMssqlNewConnectionBase", "Login", nullptr));
        cb_trustedConnection->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Trusted connection", nullptr));
        TextLabel3->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Username", nullptr));
        chkStoreUsername->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Save", nullptr));
        TextLabel3_2->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Password", nullptr));
        chkStorePassword->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Save", nullptr));
        lblWarning->setText(QApplication::translate("QgsMssqlNewConnectionBase", "HEADS UP: You have opted to save your password. It will be stored in plain text in your project files and in your home directory on Unix-like systems, or in your user profile on Windows\n"
"\n"
"Untick save if you don't wish to be the case.", nullptr));
        groupBox_2->setTitle(QApplication::translate("QgsMssqlNewConnectionBase", "Database Details", nullptr));
#ifndef QT_NO_TOOLTIP
        cb_allowGeometrylessTables->setToolTip(QApplication::translate("QgsMssqlNewConnectionBase", "If checked, tables without a geometry column attached will also be shown in the available table lists.", nullptr));
#endif // QT_NO_TOOLTIP
        cb_allowGeometrylessTables->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Also list tables with no geometry", nullptr));
#ifndef QT_NO_TOOLTIP
        cb_useEstimatedMetadata->setToolTip(QApplication::translate("QgsMssqlNewConnectionBase", "If checked, only estimated table metadata will be used. This avoids a slow table scan, but may result in incorrect layer properties such as layer extent.", nullptr));
#endif // QT_NO_TOOLTIP
        cb_useEstimatedMetadata->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Use estimated table parameters", nullptr));
#ifndef QT_NO_TOOLTIP
        cb_geometryColumns->setToolTip(QApplication::translate("QgsMssqlNewConnectionBase", "If checked, only tables which are present in the \"geometry_columns\" metadata table will be available. This speeds up table scanning, but requires users to manually manage the geometry_columns table and ensure that layers are correctly represented in the table.", nullptr));
#endif // QT_NO_TOOLTIP
        cb_geometryColumns->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Only look in the geometry_columns metadata table", nullptr));
        btnConnect->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Test Connection", nullptr));
        btnListDatabase->setText(QApplication::translate("QgsMssqlNewConnectionBase", "List Databases", nullptr));
        TextLabel2->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Database", nullptr));
#ifndef QT_NO_TOOLTIP
        mCheckNoInvalidGeometryHandling->setToolTip(QApplication::translate("QgsMssqlNewConnectionBase", "If checked, all handling of records with invalid geometry will be disabled. This speeds up the provider, however, if any invalid geometries are present in a table then the result is unpredictable and may include missing records. Only check this option if you are certain that all geometries present in the database are valid, and any newly added geometries or tables will also be valid.", nullptr));
#endif // QT_NO_TOOLTIP
        mCheckNoInvalidGeometryHandling->setText(QApplication::translate("QgsMssqlNewConnectionBase", "Skip invalid geometry handling", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsMssqlNewConnectionBase: public Ui_QgsMssqlNewConnectionBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSMSSQLNEWCONNECTIONBASE_H
