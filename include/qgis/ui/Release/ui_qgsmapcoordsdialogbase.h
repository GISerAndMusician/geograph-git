/********************************************************************************
** Form generated from reading UI file 'qgsmapcoordsdialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSMAPCOORDSDIALOGBASE_H
#define UI_QGSMAPCOORDSDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_QgsMapCoordsDialogBase
{
public:
    QGridLayout *gridLayout;
    QLabel *textLabel1;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *textLabel2;
    QSpacerItem *verticalSpacer;
    QLineEdit *leYCoord;
    QLineEdit *leXCoord;
    QCheckBox *mMinimizeWindowCheckBox;

    void setupUi(QDialog *QgsMapCoordsDialogBase)
    {
        if (QgsMapCoordsDialogBase->objectName().isEmpty())
            QgsMapCoordsDialogBase->setObjectName(QString::fromUtf8("QgsMapCoordsDialogBase"));
        QgsMapCoordsDialogBase->resize(531, 212);
        QgsMapCoordsDialogBase->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(QgsMapCoordsDialogBase);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textLabel1 = new QLabel(QgsMapCoordsDialogBase);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));

        gridLayout->addWidget(textLabel1, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QgsMapCoordsDialogBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 4);

        label = new QLabel(QgsMapCoordsDialogBase);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        textLabel2 = new QLabel(QgsMapCoordsDialogBase);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));

        gridLayout->addWidget(textLabel2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        leYCoord = new QLineEdit(QgsMapCoordsDialogBase);
        leYCoord->setObjectName(QString::fromUtf8("leYCoord"));

        gridLayout->addWidget(leYCoord, 1, 3, 1, 1);

        leXCoord = new QLineEdit(QgsMapCoordsDialogBase);
        leXCoord->setObjectName(QString::fromUtf8("leXCoord"));

        gridLayout->addWidget(leXCoord, 1, 1, 1, 1);

        mMinimizeWindowCheckBox = new QCheckBox(QgsMapCoordsDialogBase);
        mMinimizeWindowCheckBox->setObjectName(QString::fromUtf8("mMinimizeWindowCheckBox"));

        gridLayout->addWidget(mMinimizeWindowCheckBox, 4, 0, 1, 4);

        QWidget::setTabOrder(leXCoord, leYCoord);

        retranslateUi(QgsMapCoordsDialogBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsMapCoordsDialogBase, SLOT(close()));
        QObject::connect(leXCoord, SIGNAL(returnPressed()), leYCoord, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(QgsMapCoordsDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsMapCoordsDialogBase)
    {
        QgsMapCoordsDialogBase->setWindowTitle(QApplication::translate("QgsMapCoordsDialogBase", "Enter Map Coordinates", nullptr));
        textLabel1->setText(QApplication::translate("QgsMapCoordsDialogBase", "X / East", nullptr));
        label->setText(QApplication::translate("QgsMapCoordsDialogBase", "<html><head/><body><p>Enter X and Y coordinates (DMS (<span style=\" font-style:italic;\">dd mm ss.ss</span>), DD (<span style=\" font-style:italic;\">dd.dd</span>) or projected coordinates (<span style=\" font-style:italic;\">mmmm.mm</span>)) which correspond with the selected point on the image. Alternatively, click the button with icon of a pencil and then click a corresponding point on map canvas of QGIS to fill in coordinates of that point.</p></body></html>", nullptr));
        textLabel2->setText(QApplication::translate("QgsMapCoordsDialogBase", "Y / North", nullptr));
        mMinimizeWindowCheckBox->setText(QApplication::translate("QgsMapCoordsDialogBase", "Automatically hide georeferencer window ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsMapCoordsDialogBase: public Ui_QgsMapCoordsDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSMAPCOORDSDIALOGBASE_H
