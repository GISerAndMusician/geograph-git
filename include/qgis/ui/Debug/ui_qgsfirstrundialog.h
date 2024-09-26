/********************************************************************************
** Form generated from reading UI file 'qgsfirstrundialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSFIRSTRUNDIALOG_H
#define UI_QGSFIRSTRUNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QgsFirstRunDialog
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *mWelcomeLabel;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *mWelcomeDevLabel;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QWidget *mMigrationWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QRadioButton *mImportSettingsYes;
    QRadioButton *mImportSettingsNo;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;

    void setupUi(QDialog *QgsFirstRunDialog)
    {
        if (QgsFirstRunDialog->objectName().isEmpty())
            QgsFirstRunDialog->setObjectName(QString::fromUtf8("QgsFirstRunDialog"));
        QgsFirstRunDialog->resize(659, 464);
        gridLayout_2 = new QGridLayout(QgsFirstRunDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(QgsFirstRunDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, -1);
        mWelcomeLabel = new QLabel(QgsFirstRunDialog);
        mWelcomeLabel->setObjectName(QString::fromUtf8("mWelcomeLabel"));
        QFont font;
        font.setPointSize(23);
        mWelcomeLabel->setFont(font);

        gridLayout->addWidget(mWelcomeLabel, 2, 1, 2, 1);

        label_3 = new QLabel(QgsFirstRunDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/icons/qgis-icon-60x60.png")));
        label_3->setScaledContents(false);

        gridLayout->addWidget(label_3, 2, 0, 3, 1);

        label_2 = new QLabel(QgsFirstRunDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        label_2->setWordWrap(true);
        label_2->setOpenExternalLinks(true);

        gridLayout->addWidget(label_2, 6, 0, 1, 2);

        mWelcomeDevLabel = new QLabel(QgsFirstRunDialog);
        mWelcomeDevLabel->setObjectName(QString::fromUtf8("mWelcomeDevLabel"));
        mWelcomeDevLabel->setWordWrap(true);

        gridLayout->addWidget(mWelcomeDevLabel, 4, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mMigrationWidget = new QWidget(QgsFirstRunDialog);
        mMigrationWidget->setObjectName(QString::fromUtf8("mMigrationWidget"));
        verticalLayout_2 = new QVBoxLayout(mMigrationWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(mMigrationWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        mImportSettingsYes = new QRadioButton(mMigrationWidget);
        mImportSettingsYes->setObjectName(QString::fromUtf8("mImportSettingsYes"));
        mImportSettingsYes->setChecked(true);

        verticalLayout_2->addWidget(mImportSettingsYes);

        mImportSettingsNo = new QRadioButton(mMigrationWidget);
        mImportSettingsNo->setObjectName(QString::fromUtf8("mImportSettingsNo"));

        verticalLayout_2->addWidget(mImportSettingsNo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_4 = new QLabel(mMigrationWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setWordWrap(true);

        verticalLayout_2->addWidget(label_4);


        verticalLayout->addWidget(mMigrationWidget);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 2);


        retranslateUi(QgsFirstRunDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), QgsFirstRunDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(QgsFirstRunDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsFirstRunDialog)
    {
        QgsFirstRunDialog->setWindowTitle(QApplication::translate("QgsFirstRunDialog", "Welcome to QGIS", nullptr));
        pushButton->setText(QApplication::translate("QgsFirstRunDialog", "Let's get started!", nullptr));
        mWelcomeLabel->setText(QApplication::translate("QgsFirstRunDialog", "Welcome to QGIS 3", nullptr));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("QgsFirstRunDialog", "<html><head/><body><p><a href=\"https://changelog.qgis.org/en/qgis/version/3.16/\"><span style=\" text-decoration: underline; color:#2a76c6;\">Check out </span></a>the change log for all the new stuff.</p></body></html>", nullptr));
        mWelcomeDevLabel->setText(QApplication::translate("QgsFirstRunDialog", "<html><head/><body><p><span style=\" font-style:italic;\">You are running a dev version.  We would love your feedback and testing.</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("QgsFirstRunDialog", "Ready to go?", nullptr));
        mImportSettingsYes->setText(QApplication::translate("QgsFirstRunDialog", "Import settings from QGIS 2.", nullptr));
        mImportSettingsNo->setText(QApplication::translate("QgsFirstRunDialog", "I want a clean start. Don't import my QGIS 2 settings.", nullptr));
        label_4->setText(QApplication::translate("QgsFirstRunDialog", "Settings will be imported into the default profile and you will only see this screen once.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsFirstRunDialog: public Ui_QgsFirstRunDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSFIRSTRUNDIALOG_H
