/********************************************************************************
** Form generated from reading UI file 'qgsmeshvariablestrokewidthwidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSMESHVARIABLESTROKEWIDTHWIDGETBASE_H
#define UI_QGSMESHVARIABLESTROKEWIDTHWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsMeshVariableStrokeWidthWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QgsDoubleSpinBox *mWidthMinimumSpinBox;
    QLineEdit *mValueMinimumLineEdit;
    QSpacerItem *verticalSpacer;
    QLineEdit *mValueMaximumLineEdit;
    QPushButton *mDefaultMinMaxButton;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_4;
    QgsDoubleSpinBox *mWidthMaximumSpinBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *mIgnoreOutOfRangecheckBox;
    QCheckBox *mUseAbsoluteValueCheckBox;

    void setupUi(QWidget *QgsMeshVariableStrokeWidthWidget)
    {
        if (QgsMeshVariableStrokeWidthWidget->objectName().isEmpty())
            QgsMeshVariableStrokeWidthWidget->setObjectName(QString::fromUtf8("QgsMeshVariableStrokeWidthWidget"));
        QgsMeshVariableStrokeWidthWidget->resize(437, 220);
        QgsMeshVariableStrokeWidthWidget->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(QgsMeshVariableStrokeWidthWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(QgsMeshVariableStrokeWidthWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        mWidthMinimumSpinBox = new QgsDoubleSpinBox(QgsMeshVariableStrokeWidthWidget);
        mWidthMinimumSpinBox->setObjectName(QString::fromUtf8("mWidthMinimumSpinBox"));
        mWidthMinimumSpinBox->setValue(1.000000000000000);

        gridLayout->addWidget(mWidthMinimumSpinBox, 7, 1, 1, 1);

        mValueMinimumLineEdit = new QLineEdit(QgsMeshVariableStrokeWidthWidget);
        mValueMinimumLineEdit->setObjectName(QString::fromUtf8("mValueMinimumLineEdit"));

        gridLayout->addWidget(mValueMinimumLineEdit, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        mValueMaximumLineEdit = new QLineEdit(QgsMeshVariableStrokeWidthWidget);
        mValueMaximumLineEdit->setObjectName(QString::fromUtf8("mValueMaximumLineEdit"));

        gridLayout->addWidget(mValueMaximumLineEdit, 2, 1, 1, 1);

        mDefaultMinMaxButton = new QPushButton(QgsMeshVariableStrokeWidthWidget);
        mDefaultMinMaxButton->setObjectName(QString::fromUtf8("mDefaultMinMaxButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mDefaultMinMaxButton->sizePolicy().hasHeightForWidth());
        mDefaultMinMaxButton->setSizePolicy(sizePolicy);
        mDefaultMinMaxButton->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionRefresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mDefaultMinMaxButton->setIcon(icon);

        gridLayout->addWidget(mDefaultMinMaxButton, 1, 2, 2, 1);

        label = new QLabel(QgsMeshVariableStrokeWidthWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 7, 0, 1, 1);

        label_2 = new QLabel(QgsMeshVariableStrokeWidthWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 8, 0, 1, 1);

        line = new QFrame(QgsMeshVariableStrokeWidthWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 6, 0, 1, 3);

        label_5 = new QLabel(QgsMeshVariableStrokeWidthWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_4 = new QLabel(QgsMeshVariableStrokeWidthWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        mWidthMaximumSpinBox = new QgsDoubleSpinBox(QgsMeshVariableStrokeWidthWidget);
        mWidthMaximumSpinBox->setObjectName(QString::fromUtf8("mWidthMaximumSpinBox"));
        mWidthMaximumSpinBox->setValue(5.000000000000000);

        gridLayout->addWidget(mWidthMaximumSpinBox, 8, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        mIgnoreOutOfRangecheckBox = new QCheckBox(QgsMeshVariableStrokeWidthWidget);
        mIgnoreOutOfRangecheckBox->setObjectName(QString::fromUtf8("mIgnoreOutOfRangecheckBox"));

        horizontalLayout->addWidget(mIgnoreOutOfRangecheckBox);

        mUseAbsoluteValueCheckBox = new QCheckBox(QgsMeshVariableStrokeWidthWidget);
        mUseAbsoluteValueCheckBox->setObjectName(QString::fromUtf8("mUseAbsoluteValueCheckBox"));

        horizontalLayout->addWidget(mUseAbsoluteValueCheckBox);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

        QWidget::setTabOrder(mValueMinimumLineEdit, mValueMaximumLineEdit);
        QWidget::setTabOrder(mValueMaximumLineEdit, mDefaultMinMaxButton);
        QWidget::setTabOrder(mDefaultMinMaxButton, mWidthMinimumSpinBox);
        QWidget::setTabOrder(mWidthMinimumSpinBox, mWidthMaximumSpinBox);

        retranslateUi(QgsMeshVariableStrokeWidthWidget);

        QMetaObject::connectSlotsByName(QgsMeshVariableStrokeWidthWidget);
    } // setupUi

    void retranslateUi(QWidget *QgsMeshVariableStrokeWidthWidget)
    {
        label_3->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Input Values", nullptr));
        mDefaultMinMaxButton->setText(QString());
        label->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Min Width", nullptr));
        label_2->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Max Width", nullptr));
        label_5->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Max Value", nullptr));
        label_4->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Min Value", nullptr));
        mIgnoreOutOfRangecheckBox->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Ignore Out of Range Values", nullptr));
        mUseAbsoluteValueCheckBox->setText(QApplication::translate("QgsMeshVariableStrokeWidthWidget", "Use Absolute Value", nullptr));
        Q_UNUSED(QgsMeshVariableStrokeWidthWidget);
    } // retranslateUi

};

namespace Ui {
    class QgsMeshVariableStrokeWidthWidget: public Ui_QgsMeshVariableStrokeWidthWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSMESHVARIABLESTROKEWIDTHWIDGETBASE_H
