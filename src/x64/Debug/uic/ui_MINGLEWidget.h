/********************************************************************************
** Form generated from reading UI file 'MINGLEWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINGLEWIDGET_H
#define UI_MINGLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MINGLEWidget
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBoxGraph;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelGraph;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxGraph;
    QGroupBox *groupBoxAlgoParams;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *labelCurvenessAngle;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBoxNeighbors;
    QLabel *labelNeighbors;
    QGroupBox *groupBoxRenderParams;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSliderDelta;
    QLabel *labelDelta;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSliderCurveness;
    QLabel *labelCurveness;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBoxLoose;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *spinBoxMargin;
    QLabel *labelMargin;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBoxLineType;
    QLabel *labelLineType;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *comboBoxColor;
    QLabel *labelLineType_2;
    QHBoxLayout *horizontalLayout_11;
    QSlider *horizontalSliderAlpha;
    QLabel *labelAlpha;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonRun;

    void setupUi(QWidget *MINGLEWidget)
    {
        if (MINGLEWidget->objectName().isEmpty())
            MINGLEWidget->setObjectName(QString::fromUtf8("MINGLEWidget"));
        MINGLEWidget->resize(493, 680);
        gridLayout = new QGridLayout(MINGLEWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(MINGLEWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 485, 672));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBoxGraph = new QGroupBox(scrollAreaWidgetContents);
        groupBoxGraph->setObjectName(QString::fromUtf8("groupBoxGraph"));
        gridLayout_2 = new QGridLayout(groupBoxGraph);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelGraph = new QLabel(groupBoxGraph);
        labelGraph->setObjectName(QString::fromUtf8("labelGraph"));

        horizontalLayout->addWidget(labelGraph);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        comboBoxGraph = new QComboBox(groupBoxGraph);
        comboBoxGraph->setObjectName(QString::fromUtf8("comboBoxGraph"));

        verticalLayout->addWidget(comboBoxGraph);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBoxGraph);

        groupBoxAlgoParams = new QGroupBox(scrollAreaWidgetContents);
        groupBoxAlgoParams->setObjectName(QString::fromUtf8("groupBoxAlgoParams"));
        gridLayout_3 = new QGridLayout(groupBoxAlgoParams);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        doubleSpinBox = new QDoubleSpinBox(groupBoxAlgoParams);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMaximum(5.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);
        doubleSpinBox->setValue(3.000000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox);

        labelCurvenessAngle = new QLabel(groupBoxAlgoParams);
        labelCurvenessAngle->setObjectName(QString::fromUtf8("labelCurvenessAngle"));

        horizontalLayout_5->addWidget(labelCurvenessAngle);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        spinBoxNeighbors = new QSpinBox(groupBoxAlgoParams);
        spinBoxNeighbors->setObjectName(QString::fromUtf8("spinBoxNeighbors"));
        sizePolicy.setHeightForWidth(spinBoxNeighbors->sizePolicy().hasHeightForWidth());
        spinBoxNeighbors->setSizePolicy(sizePolicy);
        spinBoxNeighbors->setValue(10);

        horizontalLayout_6->addWidget(spinBoxNeighbors);

        labelNeighbors = new QLabel(groupBoxAlgoParams);
        labelNeighbors->setObjectName(QString::fromUtf8("labelNeighbors"));

        horizontalLayout_6->addWidget(labelNeighbors);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBoxAlgoParams);

        groupBoxRenderParams = new QGroupBox(scrollAreaWidgetContents);
        groupBoxRenderParams->setObjectName(QString::fromUtf8("groupBoxRenderParams"));
        gridLayout_4 = new QGridLayout(groupBoxRenderParams);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSliderDelta = new QSlider(groupBoxRenderParams);
        horizontalSliderDelta->setObjectName(QString::fromUtf8("horizontalSliderDelta"));
        sizePolicy.setHeightForWidth(horizontalSliderDelta->sizePolicy().hasHeightForWidth());
        horizontalSliderDelta->setSizePolicy(sizePolicy);
        horizontalSliderDelta->setMinimumSize(QSize(280, 0));
        horizontalSliderDelta->setMaximum(100);
        horizontalSliderDelta->setValue(100);
        horizontalSliderDelta->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSliderDelta);

        labelDelta = new QLabel(groupBoxRenderParams);
        labelDelta->setObjectName(QString::fromUtf8("labelDelta"));

        horizontalLayout_3->addWidget(labelDelta);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSliderCurveness = new QSlider(groupBoxRenderParams);
        horizontalSliderCurveness->setObjectName(QString::fromUtf8("horizontalSliderCurveness"));
        sizePolicy.setHeightForWidth(horizontalSliderCurveness->sizePolicy().hasHeightForWidth());
        horizontalSliderCurveness->setSizePolicy(sizePolicy);
        horizontalSliderCurveness->setMinimumSize(QSize(280, 0));
        horizontalSliderCurveness->setMaximum(100);
        horizontalSliderCurveness->setSingleStep(1);
        horizontalSliderCurveness->setValue(100);
        horizontalSliderCurveness->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderCurveness);

        labelCurveness = new QLabel(groupBoxRenderParams);
        labelCurveness->setObjectName(QString::fromUtf8("labelCurveness"));

        horizontalLayout_4->addWidget(labelCurveness);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        checkBoxLoose = new QCheckBox(groupBoxRenderParams);
        checkBoxLoose->setObjectName(QString::fromUtf8("checkBoxLoose"));
        checkBoxLoose->setChecked(true);

        horizontalLayout_10->addWidget(checkBoxLoose);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        spinBoxMargin = new QSpinBox(groupBoxRenderParams);
        spinBoxMargin->setObjectName(QString::fromUtf8("spinBoxMargin"));
        sizePolicy.setHeightForWidth(spinBoxMargin->sizePolicy().hasHeightForWidth());
        spinBoxMargin->setSizePolicy(sizePolicy);
        spinBoxMargin->setMaximum(25);

        horizontalLayout_7->addWidget(spinBoxMargin);

        labelMargin = new QLabel(groupBoxRenderParams);
        labelMargin->setObjectName(QString::fromUtf8("labelMargin"));

        horizontalLayout_7->addWidget(labelMargin);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        comboBoxLineType = new QComboBox(groupBoxRenderParams);
        comboBoxLineType->setObjectName(QString::fromUtf8("comboBoxLineType"));
        sizePolicy.setHeightForWidth(comboBoxLineType->sizePolicy().hasHeightForWidth());
        comboBoxLineType->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(comboBoxLineType);

        labelLineType = new QLabel(groupBoxRenderParams);
        labelLineType->setObjectName(QString::fromUtf8("labelLineType"));

        horizontalLayout_8->addWidget(labelLineType);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        comboBoxColor = new QComboBox(groupBoxRenderParams);
        comboBoxColor->setObjectName(QString::fromUtf8("comboBoxColor"));
        sizePolicy.setHeightForWidth(comboBoxColor->sizePolicy().hasHeightForWidth());
        comboBoxColor->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(comboBoxColor);

        labelLineType_2 = new QLabel(groupBoxRenderParams);
        labelLineType_2->setObjectName(QString::fromUtf8("labelLineType_2"));

        horizontalLayout_9->addWidget(labelLineType_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSliderAlpha = new QSlider(groupBoxRenderParams);
        horizontalSliderAlpha->setObjectName(QString::fromUtf8("horizontalSliderAlpha"));
        sizePolicy.setHeightForWidth(horizontalSliderAlpha->sizePolicy().hasHeightForWidth());
        horizontalSliderAlpha->setSizePolicy(sizePolicy);
        horizontalSliderAlpha->setMinimumSize(QSize(280, 0));
        horizontalSliderAlpha->setMaximum(100);
        horizontalSliderAlpha->setSingleStep(1);
        horizontalSliderAlpha->setValue(100);
        horizontalSliderAlpha->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSliderAlpha);

        labelAlpha = new QLabel(groupBoxRenderParams);
        labelAlpha->setObjectName(QString::fromUtf8("labelAlpha"));

        horizontalLayout_11->addWidget(labelAlpha);


        verticalLayout_3->addLayout(horizontalLayout_11);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBoxRenderParams);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonRun = new QPushButton(scrollAreaWidgetContents);
        pushButtonRun->setObjectName(QString::fromUtf8("pushButtonRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qgis/themes/default/mTaskRunning.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRun->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonRun);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout_5->addLayout(verticalLayout_4, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(MINGLEWidget);

        QMetaObject::connectSlotsByName(MINGLEWidget);
    } // setupUi

    void retranslateUi(QWidget *MINGLEWidget)
    {
        MINGLEWidget->setWindowTitle(QApplication::translate("MINGLEWidget", "MINGLE", nullptr));
        groupBoxGraph->setTitle(QApplication::translate("MINGLEWidget", "\345\233\276\345\261\202", nullptr));
        labelGraph->setText(QApplication::translate("MINGLEWidget", "\351\200\211\346\213\251\345\233\276\345\233\276\345\261\202", nullptr));
        groupBoxAlgoParams->setTitle(QApplication::translate("MINGLEWidget", "\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
        labelCurvenessAngle->setText(QApplication::translate("MINGLEWidget", "Angle", nullptr));
        labelNeighbors->setText(QApplication::translate("MINGLEWidget", "Neighbors", nullptr));
        groupBoxRenderParams->setTitle(QApplication::translate("MINGLEWidget", "\346\270\262\346\237\223\345\217\202\346\225\260", nullptr));
        labelDelta->setText(QApplication::translate("MINGLEWidget", "Delta(100%)", nullptr));
        labelCurveness->setText(QApplication::translate("MINGLEWidget", "Curveness(100%)", nullptr));
        checkBoxLoose->setText(QApplication::translate("MINGLEWidget", "\345\220\257\347\224\250\346\235\276\345\274\233", nullptr));
        labelMargin->setText(QApplication::translate("MINGLEWidget", "Margin", nullptr));
        labelLineType->setText(QApplication::translate("MINGLEWidget", "Line Type", nullptr));
        labelLineType_2->setText(QApplication::translate("MINGLEWidget", "Color", nullptr));
        labelAlpha->setText(QApplication::translate("MINGLEWidget", "Alpha(100%)", nullptr));
        pushButtonRun->setText(QApplication::translate("MINGLEWidget", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MINGLEWidget: public Ui_MINGLEWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINGLEWIDGET_H
