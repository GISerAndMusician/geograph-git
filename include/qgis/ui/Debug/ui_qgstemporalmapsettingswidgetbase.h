/********************************************************************************
** Form generated from reading UI file 'qgstemporalmapsettingswidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSTEMPORALMAPSETTINGSWIDGETBASE_H
#define UI_QGSTEMPORALMAPSETTINGSWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qgsdoublespinbox.h"
#include "qgspanelwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsTemporalMapSettingsWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QgsDoubleSpinBox *mFrameSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *mCumulativeTemporalRange;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QgsPanelWidget *QgsTemporalMapSettingsWidgetBase)
    {
        if (QgsTemporalMapSettingsWidgetBase->objectName().isEmpty())
            QgsTemporalMapSettingsWidgetBase->setObjectName(QString::fromUtf8("QgsTemporalMapSettingsWidgetBase"));
        QgsTemporalMapSettingsWidgetBase->resize(409, 82);
        QgsTemporalMapSettingsWidgetBase->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout = new QVBoxLayout(QgsTemporalMapSettingsWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(QgsTemporalMapSettingsWidgetBase);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        mFrameSpinBox = new QgsDoubleSpinBox(QgsTemporalMapSettingsWidgetBase);
        mFrameSpinBox->setObjectName(QString::fromUtf8("mFrameSpinBox"));

        horizontalLayout->addWidget(mFrameSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mCumulativeTemporalRange = new QCheckBox(QgsTemporalMapSettingsWidgetBase);
        mCumulativeTemporalRange->setObjectName(QString::fromUtf8("mCumulativeTemporalRange"));

        horizontalLayout_2->addWidget(mCumulativeTemporalRange);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(QgsTemporalMapSettingsWidgetBase);

        QMetaObject::connectSlotsByName(QgsTemporalMapSettingsWidgetBase);
    } // setupUi

    void retranslateUi(QgsPanelWidget *QgsTemporalMapSettingsWidgetBase)
    {
        label->setText(QApplication::translate("QgsTemporalMapSettingsWidgetBase", "Frame rate (frames per second)", nullptr));
        mCumulativeTemporalRange->setText(QApplication::translate("QgsTemporalMapSettingsWidgetBase", "Cumulative range", nullptr));
        Q_UNUSED(QgsTemporalMapSettingsWidgetBase);
    } // retranslateUi

};

namespace Ui {
    class QgsTemporalMapSettingsWidgetBase: public Ui_QgsTemporalMapSettingsWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSTEMPORALMAPSETTINGSWIDGETBASE_H
