/********************************************************************************
** Form generated from reading UI file 'qgspresetcolorrampwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSPRESETCOLORRAMPWIDGETBASE_H
#define UI_QGSPRESETCOLORRAMPWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <qgscolorschemelist.h>
#include "qgspanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsPresetColorRampWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QgsColorSchemeList *mTreeColors;
    QHBoxLayout *horizontalLayout;
    QToolButton *mButtonAddColor;
    QToolButton *mButtonRemoveColor;
    QToolButton *mButtonCopyColors;
    QToolButton *mButtonPasteColors;
    QToolButton *mButtonImportColors;
    QToolButton *mButtonExportColors;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblPreview;

    void setupUi(QgsPanelWidget *QgsPresetColorRampWidgetBase)
    {
        if (QgsPresetColorRampWidgetBase->objectName().isEmpty())
            QgsPresetColorRampWidgetBase->setObjectName(QString::fromUtf8("QgsPresetColorRampWidgetBase"));
        QgsPresetColorRampWidgetBase->resize(232, 282);
        verticalLayout = new QVBoxLayout(QgsPresetColorRampWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mTreeColors = new QgsColorSchemeList(QgsPresetColorRampWidgetBase);
        mTreeColors->setObjectName(QString::fromUtf8("mTreeColors"));

        verticalLayout->addWidget(mTreeColors);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mButtonAddColor = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonAddColor->setObjectName(QString::fromUtf8("mButtonAddColor"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/symbologyAdd.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonAddColor->setIcon(icon);

        horizontalLayout->addWidget(mButtonAddColor);

        mButtonRemoveColor = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonRemoveColor->setObjectName(QString::fromUtf8("mButtonRemoveColor"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/symbologyRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonRemoveColor->setIcon(icon1);

        horizontalLayout->addWidget(mButtonRemoveColor);

        mButtonCopyColors = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonCopyColors->setObjectName(QString::fromUtf8("mButtonCopyColors"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionEditCopy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonCopyColors->setIcon(icon2);

        horizontalLayout->addWidget(mButtonCopyColors);

        mButtonPasteColors = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonPasteColors->setObjectName(QString::fromUtf8("mButtonPasteColors"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mActionEditPaste.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonPasteColors->setIcon(icon3);

        horizontalLayout->addWidget(mButtonPasteColors);

        mButtonImportColors = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonImportColors->setObjectName(QString::fromUtf8("mButtonImportColors"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/mActionFileOpen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonImportColors->setIcon(icon4);

        horizontalLayout->addWidget(mButtonImportColors);

        mButtonExportColors = new QToolButton(QgsPresetColorRampWidgetBase);
        mButtonExportColors->setObjectName(QString::fromUtf8("mButtonExportColors"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/themes/default/mActionFileSave.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mButtonExportColors->setIcon(icon5);

        horizontalLayout->addWidget(mButtonExportColors);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(QgsPresetColorRampWidgetBase);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblPreview = new QLabel(groupBox);
        lblPreview->setObjectName(QString::fromUtf8("lblPreview"));
        lblPreview->setFrameShape(QFrame::NoFrame);
        lblPreview->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblPreview);


        verticalLayout->addWidget(groupBox);

        verticalLayout->setStretch(0, 1);

        retranslateUi(QgsPresetColorRampWidgetBase);

        QMetaObject::connectSlotsByName(QgsPresetColorRampWidgetBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsPresetColorRampWidgetBase)
    {
        QgsPresetColorRampWidgetBase->setWindowTitle(QApplication::translate("QgsPresetColorRampWidgetBase", "Color Presets Ramp", nullptr));
#ifndef QT_NO_TOOLTIP
        mButtonAddColor->setToolTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Add color", nullptr));
#endif // QT_NO_TOOLTIP
        mButtonAddColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        mButtonRemoveColor->setToolTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Remove color", nullptr));
#endif // QT_NO_TOOLTIP
        mButtonRemoveColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        mButtonCopyColors->setToolTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Copy colors", nullptr));
#endif // QT_NO_TOOLTIP
        mButtonCopyColors->setText(QString());
#ifndef QT_NO_TOOLTIP
        mButtonPasteColors->setToolTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Paste colors", nullptr));
#endif // QT_NO_TOOLTIP
        mButtonPasteColors->setText(QString());
#ifndef QT_NO_STATUSTIP
        mButtonImportColors->setStatusTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Import colors", nullptr));
#endif // QT_NO_STATUSTIP
        mButtonImportColors->setText(QString());
#ifndef QT_NO_TOOLTIP
        mButtonExportColors->setToolTip(QApplication::translate("QgsPresetColorRampWidgetBase", "Export colors", nullptr));
#endif // QT_NO_TOOLTIP
        mButtonExportColors->setText(QString());
        groupBox->setTitle(QApplication::translate("QgsPresetColorRampWidgetBase", "Preview", nullptr));
        lblPreview->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QgsPresetColorRampWidgetBase: public Ui_QgsPresetColorRampWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSPRESETCOLORRAMPWIDGETBASE_H
