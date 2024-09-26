/********************************************************************************
** Form generated from reading UI file 'goochmaterialwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOOCHMATERIALWIDGET_H
#define UI_GOOCHMATERIALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "qgscolorbutton.h"
#include "qgsdoublespinbox.h"

QT_BEGIN_NAMESPACE

class Ui_GoochMaterialWidget
{
public:
    QGridLayout *gridLayout;
    QgsDoubleSpinBox *spinShininess;
    QLabel *lblSpecular;
    QLabel *lblDiffuse;
    QgsColorButton *btnWarm;
    QgsColorButton *btnCool;
    QLabel *lblShininess_2;
    QLabel *lblShininess;
    QgsColorButton *btnDiffuse;
    QLabel *lblAmbient;
    QgsColorButton *btnSpecular;
    QLabel *lblAmbient_2;
    QLabel *lblShininess_3;
    QgsDoubleSpinBox *spinAlpha;
    QgsDoubleSpinBox *spinBeta;

    void setupUi(QWidget *GoochMaterialWidget)
    {
        if (GoochMaterialWidget->objectName().isEmpty())
            GoochMaterialWidget->setObjectName(QString::fromUtf8("GoochMaterialWidget"));
        GoochMaterialWidget->resize(394, 230);
        GoochMaterialWidget->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(GoochMaterialWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinShininess = new QgsDoubleSpinBox(GoochMaterialWidget);
        spinShininess->setObjectName(QString::fromUtf8("spinShininess"));
        spinShininess->setMinimum(1.000000000000000);
        spinShininess->setMaximum(1000.000000000000000);
        spinShininess->setValue(100.000000000000000);

        gridLayout->addWidget(spinShininess, 4, 1, 1, 1);

        lblSpecular = new QLabel(GoochMaterialWidget);
        lblSpecular->setObjectName(QString::fromUtf8("lblSpecular"));

        gridLayout->addWidget(lblSpecular, 3, 0, 1, 1);

        lblDiffuse = new QLabel(GoochMaterialWidget);
        lblDiffuse->setObjectName(QString::fromUtf8("lblDiffuse"));

        gridLayout->addWidget(lblDiffuse, 0, 0, 1, 1);

        btnWarm = new QgsColorButton(GoochMaterialWidget);
        btnWarm->setObjectName(QString::fromUtf8("btnWarm"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnWarm->sizePolicy().hasHeightForWidth());
        btnWarm->setSizePolicy(sizePolicy);
        btnWarm->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnWarm, 1, 1, 1, 1);

        btnCool = new QgsColorButton(GoochMaterialWidget);
        btnCool->setObjectName(QString::fromUtf8("btnCool"));
        sizePolicy.setHeightForWidth(btnCool->sizePolicy().hasHeightForWidth());
        btnCool->setSizePolicy(sizePolicy);
        btnCool->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnCool, 2, 1, 1, 1);

        lblShininess_2 = new QLabel(GoochMaterialWidget);
        lblShininess_2->setObjectName(QString::fromUtf8("lblShininess_2"));

        gridLayout->addWidget(lblShininess_2, 5, 0, 1, 1);

        lblShininess = new QLabel(GoochMaterialWidget);
        lblShininess->setObjectName(QString::fromUtf8("lblShininess"));

        gridLayout->addWidget(lblShininess, 4, 0, 1, 1);

        btnDiffuse = new QgsColorButton(GoochMaterialWidget);
        btnDiffuse->setObjectName(QString::fromUtf8("btnDiffuse"));
        sizePolicy.setHeightForWidth(btnDiffuse->sizePolicy().hasHeightForWidth());
        btnDiffuse->setSizePolicy(sizePolicy);
        btnDiffuse->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnDiffuse, 0, 1, 1, 1);

        lblAmbient = new QLabel(GoochMaterialWidget);
        lblAmbient->setObjectName(QString::fromUtf8("lblAmbient"));

        gridLayout->addWidget(lblAmbient, 1, 0, 1, 1);

        btnSpecular = new QgsColorButton(GoochMaterialWidget);
        btnSpecular->setObjectName(QString::fromUtf8("btnSpecular"));
        sizePolicy.setHeightForWidth(btnSpecular->sizePolicy().hasHeightForWidth());
        btnSpecular->setSizePolicy(sizePolicy);
        btnSpecular->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(btnSpecular, 3, 1, 1, 1);

        lblAmbient_2 = new QLabel(GoochMaterialWidget);
        lblAmbient_2->setObjectName(QString::fromUtf8("lblAmbient_2"));

        gridLayout->addWidget(lblAmbient_2, 2, 0, 1, 1);

        lblShininess_3 = new QLabel(GoochMaterialWidget);
        lblShininess_3->setObjectName(QString::fromUtf8("lblShininess_3"));

        gridLayout->addWidget(lblShininess_3, 6, 0, 1, 1);

        spinAlpha = new QgsDoubleSpinBox(GoochMaterialWidget);
        spinAlpha->setObjectName(QString::fromUtf8("spinAlpha"));
        spinAlpha->setMaximum(1000.000000000000000);
        spinAlpha->setSingleStep(0.100000000000000);

        gridLayout->addWidget(spinAlpha, 5, 1, 1, 1);

        spinBeta = new QgsDoubleSpinBox(GoochMaterialWidget);
        spinBeta->setObjectName(QString::fromUtf8("spinBeta"));
        spinBeta->setMaximum(1000.000000000000000);
        spinBeta->setSingleStep(0.100000000000000);

        gridLayout->addWidget(spinBeta, 6, 1, 1, 1);

        QWidget::setTabOrder(btnDiffuse, btnWarm);
        QWidget::setTabOrder(btnWarm, btnCool);
        QWidget::setTabOrder(btnCool, btnSpecular);
        QWidget::setTabOrder(btnSpecular, spinShininess);
        QWidget::setTabOrder(spinShininess, spinAlpha);
        QWidget::setTabOrder(spinAlpha, spinBeta);

        retranslateUi(GoochMaterialWidget);

        QMetaObject::connectSlotsByName(GoochMaterialWidget);
    } // setupUi

    void retranslateUi(QWidget *GoochMaterialWidget)
    {
        lblSpecular->setText(QApplication::translate("GoochMaterialWidget", "Specular", nullptr));
        lblDiffuse->setText(QApplication::translate("GoochMaterialWidget", "Diffuse", nullptr));
        lblShininess_2->setText(QApplication::translate("GoochMaterialWidget", "Alpha", nullptr));
        lblShininess->setText(QApplication::translate("GoochMaterialWidget", "Shininess", nullptr));
        lblAmbient->setText(QApplication::translate("GoochMaterialWidget", "Warm", nullptr));
        lblAmbient_2->setText(QApplication::translate("GoochMaterialWidget", "Cool", nullptr));
        lblShininess_3->setText(QApplication::translate("GoochMaterialWidget", "Beta", nullptr));
        Q_UNUSED(GoochMaterialWidget);
    } // retranslateUi

};

namespace Ui {
    class GoochMaterialWidget: public Ui_GoochMaterialWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOOCHMATERIALWIDGET_H
