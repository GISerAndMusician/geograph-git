/********************************************************************************
** Form generated from reading UI file 'qgsmeshrendererscalarsettingswidgetbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSMESHRENDERERSCALARSETTINGSWIDGETBASE_H
#define UI_QGSMESHRENDERERSCALARSETTINGSWIDGETBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"
#include "qgsmeshvariablestrokewidthwidget.h"
#include "qgsopacitywidget.h"
#include "qgsunitselectionwidget.h"
#include "raster/qgscolorrampshaderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsMeshRendererScalarSettingsWidgetBase
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *mOpacityContainerWidget;
    QFormLayout *formLayout;
    QLabel *mOpacityLabel;
    QgsOpacityWidget *mOpacityWidget;
    QGroupBox *mEdgeWidthGroupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *mScalarEdgeStrokeWidthVariableRadioButton;
    QRadioButton *mScalarEdgeStrokeWidthFixedRadioButton;
    QgsMeshVariableStrokeWidthButton *mScalarEdgeStrokeWidthVariablePushButton;
    QgsDoubleSpinBox *mScalarEdgeStrokeWidthSpinBox;
    QgsUnitSelectionWidget *mScalarEdgeStrokeWidthUnitSelectionWidget;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *mScalarMinLabel;
    QLineEdit *mScalarMinLineEdit;
    QLabel *mScalarMaxLabel;
    QLineEdit *mScalarMaxLineEdit;
    QPushButton *mScalarRecalculateMinMaxButton;
    QWidget *mScalarResamplingWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *mLabelDataInterpolation;
    QComboBox *mScalarInterpolationTypeComboBox;
    QgsColorRampShaderWidget *mScalarColorRampShaderWidget;

    void setupUi(QWidget *QgsMeshRendererScalarSettingsWidgetBase)
    {
        if (QgsMeshRendererScalarSettingsWidgetBase->objectName().isEmpty())
            QgsMeshRendererScalarSettingsWidgetBase->setObjectName(QString::fromUtf8("QgsMeshRendererScalarSettingsWidgetBase"));
        QgsMeshRendererScalarSettingsWidgetBase->resize(378, 206);
        QgsMeshRendererScalarSettingsWidgetBase->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout = new QVBoxLayout(QgsMeshRendererScalarSettingsWidgetBase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mOpacityContainerWidget = new QWidget(QgsMeshRendererScalarSettingsWidgetBase);
        mOpacityContainerWidget->setObjectName(QString::fromUtf8("mOpacityContainerWidget"));
        formLayout = new QFormLayout(mOpacityContainerWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        mOpacityLabel = new QLabel(mOpacityContainerWidget);
        mOpacityLabel->setObjectName(QString::fromUtf8("mOpacityLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mOpacityLabel);

        mOpacityWidget = new QgsOpacityWidget(mOpacityContainerWidget);
        mOpacityWidget->setObjectName(QString::fromUtf8("mOpacityWidget"));
        mOpacityWidget->setMinimumSize(QSize(0, 14));
        mOpacityWidget->setFocusPolicy(Qt::StrongFocus);

        formLayout->setWidget(0, QFormLayout::FieldRole, mOpacityWidget);


        verticalLayout->addWidget(mOpacityContainerWidget);

        mEdgeWidthGroupBox = new QGroupBox(QgsMeshRendererScalarSettingsWidgetBase);
        mEdgeWidthGroupBox->setObjectName(QString::fromUtf8("mEdgeWidthGroupBox"));
        gridLayout_2 = new QGridLayout(mEdgeWidthGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mScalarEdgeStrokeWidthVariableRadioButton = new QRadioButton(mEdgeWidthGroupBox);
        mScalarEdgeStrokeWidthVariableRadioButton->setObjectName(QString::fromUtf8("mScalarEdgeStrokeWidthVariableRadioButton"));

        gridLayout_2->addWidget(mScalarEdgeStrokeWidthVariableRadioButton, 2, 0, 1, 1);

        mScalarEdgeStrokeWidthFixedRadioButton = new QRadioButton(mEdgeWidthGroupBox);
        mScalarEdgeStrokeWidthFixedRadioButton->setObjectName(QString::fromUtf8("mScalarEdgeStrokeWidthFixedRadioButton"));
        mScalarEdgeStrokeWidthFixedRadioButton->setChecked(true);

        gridLayout_2->addWidget(mScalarEdgeStrokeWidthFixedRadioButton, 0, 0, 1, 1);

        mScalarEdgeStrokeWidthVariablePushButton = new QgsMeshVariableStrokeWidthButton(mEdgeWidthGroupBox);
        mScalarEdgeStrokeWidthVariablePushButton->setObjectName(QString::fromUtf8("mScalarEdgeStrokeWidthVariablePushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mScalarEdgeStrokeWidthVariablePushButton->sizePolicy().hasHeightForWidth());
        mScalarEdgeStrokeWidthVariablePushButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(mScalarEdgeStrokeWidthVariablePushButton, 0, 3, 3, 1);

        mScalarEdgeStrokeWidthSpinBox = new QgsDoubleSpinBox(mEdgeWidthGroupBox);
        mScalarEdgeStrokeWidthSpinBox->setObjectName(QString::fromUtf8("mScalarEdgeStrokeWidthSpinBox"));
        sizePolicy.setHeightForWidth(mScalarEdgeStrokeWidthSpinBox->sizePolicy().hasHeightForWidth());
        mScalarEdgeStrokeWidthSpinBox->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(mScalarEdgeStrokeWidthSpinBox, 0, 2, 3, 1);

        mScalarEdgeStrokeWidthUnitSelectionWidget = new QgsUnitSelectionWidget(mEdgeWidthGroupBox);
        mScalarEdgeStrokeWidthUnitSelectionWidget->setObjectName(QString::fromUtf8("mScalarEdgeStrokeWidthUnitSelectionWidget"));

        gridLayout_2->addWidget(mScalarEdgeStrokeWidthUnitSelectionWidget, 0, 4, 3, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 3, 1);


        verticalLayout->addWidget(mEdgeWidthGroupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mScalarMinLabel = new QLabel(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarMinLabel->setObjectName(QString::fromUtf8("mScalarMinLabel"));

        horizontalLayout_2->addWidget(mScalarMinLabel);

        mScalarMinLineEdit = new QLineEdit(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarMinLineEdit->setObjectName(QString::fromUtf8("mScalarMinLineEdit"));

        horizontalLayout_2->addWidget(mScalarMinLineEdit);

        mScalarMaxLabel = new QLabel(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarMaxLabel->setObjectName(QString::fromUtf8("mScalarMaxLabel"));

        horizontalLayout_2->addWidget(mScalarMaxLabel);

        mScalarMaxLineEdit = new QLineEdit(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarMaxLineEdit->setObjectName(QString::fromUtf8("mScalarMaxLineEdit"));

        horizontalLayout_2->addWidget(mScalarMaxLineEdit);

        mScalarRecalculateMinMaxButton = new QPushButton(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarRecalculateMinMaxButton->setObjectName(QString::fromUtf8("mScalarRecalculateMinMaxButton"));

        horizontalLayout_2->addWidget(mScalarRecalculateMinMaxButton);


        verticalLayout->addLayout(horizontalLayout_2);

        mScalarResamplingWidget = new QWidget(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarResamplingWidget->setObjectName(QString::fromUtf8("mScalarResamplingWidget"));
        horizontalLayout_4 = new QHBoxLayout(mScalarResamplingWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        mLabelDataInterpolation = new QLabel(mScalarResamplingWidget);
        mLabelDataInterpolation->setObjectName(QString::fromUtf8("mLabelDataInterpolation"));

        horizontalLayout_4->addWidget(mLabelDataInterpolation);

        mScalarInterpolationTypeComboBox = new QComboBox(mScalarResamplingWidget);
        mScalarInterpolationTypeComboBox->setObjectName(QString::fromUtf8("mScalarInterpolationTypeComboBox"));

        horizontalLayout_4->addWidget(mScalarInterpolationTypeComboBox);


        verticalLayout->addWidget(mScalarResamplingWidget);

        mScalarColorRampShaderWidget = new QgsColorRampShaderWidget(QgsMeshRendererScalarSettingsWidgetBase);
        mScalarColorRampShaderWidget->setObjectName(QString::fromUtf8("mScalarColorRampShaderWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mScalarColorRampShaderWidget->sizePolicy().hasHeightForWidth());
        mScalarColorRampShaderWidget->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(mScalarColorRampShaderWidget);


        retranslateUi(QgsMeshRendererScalarSettingsWidgetBase);

        QMetaObject::connectSlotsByName(QgsMeshRendererScalarSettingsWidgetBase);
    } // setupUi

    void retranslateUi(QWidget *QgsMeshRendererScalarSettingsWidgetBase)
    {
        mOpacityLabel->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Opacity", nullptr));
        mEdgeWidthGroupBox->setTitle(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Stroke width", nullptr));
        mScalarEdgeStrokeWidthVariableRadioButton->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Variable", nullptr));
        mScalarEdgeStrokeWidthFixedRadioButton->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Fixed", nullptr));
        mScalarMinLabel->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Min", nullptr));
        mScalarMinLineEdit->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "0", nullptr));
        mScalarMaxLabel->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Max", nullptr));
        mScalarMaxLineEdit->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "1", nullptr));
        mScalarRecalculateMinMaxButton->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Load", nullptr));
        mLabelDataInterpolation->setText(QApplication::translate("QgsMeshRendererScalarSettingsWidgetBase", "Resampling method", nullptr));
        Q_UNUSED(QgsMeshRendererScalarSettingsWidgetBase);
    } // retranslateUi

};

namespace Ui {
    class QgsMeshRendererScalarSettingsWidgetBase: public Ui_QgsMeshRendererScalarSettingsWidgetBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSMESHRENDERERSCALARSETTINGSWIDGETBASE_H
