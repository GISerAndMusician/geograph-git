/********************************************************************************
** Form generated from reading UI file 'GgsFdebWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSFDEBWIDGET_H
#define UI_GGSFDEBWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GgsFDEBWidget
{
public:
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBoxLayers;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelGraphLayer;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxGraphLayer;
    QGroupBox *groupBoxAlgorithmParams;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *doubleSpinBoxK;
    QLabel *labelK;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBoxI;
    QLabel *labelI;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBoxCycles;
    QLabel *labelCycles;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *doubleSpinBoxCompatibility;
    QLabel *labelCompatibility;
    QHBoxLayout *horizontalLayout_8;
    QDoubleSpinBox *doubleSpinBoxsmooth;
    QLabel *labelsmooth;
    QGroupBox *groupBoxPhysical;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QDoubleSpinBox *doubleSpinBoxS;
    QLabel *labelS;
    QHBoxLayout *horizontalLayout_10;
    QDoubleSpinBox *doubleSpinBoxEdgeDistance;
    QLabel *labelEdgeDistance;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBoxGravity;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QDoubleSpinBox *doubleSpinBoxGravityExponent;
    QLabel *labelGravityExponent;
    QGroupBox *groupBoxNetWork;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_13;
    QDoubleSpinBox *doubleSpinBoxWeightThreshold;
    QLabel *labelWeightThreshold;
    QHBoxLayout *horizontalLayout_14;
    QDoubleSpinBox *doubleSpinBoxPercentage;
    QLabel *labelPercentage;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_15;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonRun;

    void setupUi(QWidget *GgsFDEBWidget)
    {
        if (GgsFDEBWidget->objectName().isEmpty())
            GgsFDEBWidget->setObjectName(QString::fromUtf8("GgsFDEBWidget"));
        GgsFDEBWidget->resize(388, 811);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GgsFDEBWidget->sizePolicy().hasHeightForWidth());
        GgsFDEBWidget->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(GgsFDEBWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_6->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(GgsFDEBWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 803));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBoxLayers = new QGroupBox(scrollAreaWidgetContents);
        groupBoxLayers->setObjectName(QString::fromUtf8("groupBoxLayers"));
        gridLayout = new QGridLayout(groupBoxLayers);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelGraphLayer = new QLabel(groupBoxLayers);
        labelGraphLayer->setObjectName(QString::fromUtf8("labelGraphLayer"));

        horizontalLayout->addWidget(labelGraphLayer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        comboBoxGraphLayer = new QComboBox(groupBoxLayers);
        comboBoxGraphLayer->setObjectName(QString::fromUtf8("comboBoxGraphLayer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxGraphLayer->sizePolicy().hasHeightForWidth());
        comboBoxGraphLayer->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(comboBoxGraphLayer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBoxLayers);

        groupBoxAlgorithmParams = new QGroupBox(scrollAreaWidgetContents);
        groupBoxAlgorithmParams->setObjectName(QString::fromUtf8("groupBoxAlgorithmParams"));
        gridLayout_2 = new QGridLayout(groupBoxAlgorithmParams);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        doubleSpinBoxK = new QDoubleSpinBox(groupBoxAlgorithmParams);
        doubleSpinBoxK->setObjectName(QString::fromUtf8("doubleSpinBoxK"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxK->sizePolicy().hasHeightForWidth());
        doubleSpinBoxK->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(doubleSpinBoxK);

        labelK = new QLabel(groupBoxAlgorithmParams);
        labelK->setObjectName(QString::fromUtf8("labelK"));
        sizePolicy.setHeightForWidth(labelK->sizePolicy().hasHeightForWidth());
        labelK->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(labelK);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBoxI = new QSpinBox(groupBoxAlgorithmParams);
        spinBoxI->setObjectName(QString::fromUtf8("spinBoxI"));
        sizePolicy1.setHeightForWidth(spinBoxI->sizePolicy().hasHeightForWidth());
        spinBoxI->setSizePolicy(sizePolicy1);
        spinBoxI->setMaximum(9999);

        horizontalLayout_4->addWidget(spinBoxI);

        labelI = new QLabel(groupBoxAlgorithmParams);
        labelI->setObjectName(QString::fromUtf8("labelI"));
        sizePolicy.setHeightForWidth(labelI->sizePolicy().hasHeightForWidth());
        labelI->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(labelI);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        spinBoxCycles = new QSpinBox(groupBoxAlgorithmParams);
        spinBoxCycles->setObjectName(QString::fromUtf8("spinBoxCycles"));
        sizePolicy1.setHeightForWidth(spinBoxCycles->sizePolicy().hasHeightForWidth());
        spinBoxCycles->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(spinBoxCycles);

        labelCycles = new QLabel(groupBoxAlgorithmParams);
        labelCycles->setObjectName(QString::fromUtf8("labelCycles"));
        sizePolicy.setHeightForWidth(labelCycles->sizePolicy().hasHeightForWidth());
        labelCycles->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(labelCycles);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        doubleSpinBoxCompatibility = new QDoubleSpinBox(groupBoxAlgorithmParams);
        doubleSpinBoxCompatibility->setObjectName(QString::fromUtf8("doubleSpinBoxCompatibility"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxCompatibility->sizePolicy().hasHeightForWidth());
        doubleSpinBoxCompatibility->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(doubleSpinBoxCompatibility);

        labelCompatibility = new QLabel(groupBoxAlgorithmParams);
        labelCompatibility->setObjectName(QString::fromUtf8("labelCompatibility"));
        sizePolicy.setHeightForWidth(labelCompatibility->sizePolicy().hasHeightForWidth());
        labelCompatibility->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(labelCompatibility);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        doubleSpinBoxsmooth = new QDoubleSpinBox(groupBoxAlgorithmParams);
        doubleSpinBoxsmooth->setObjectName(QString::fromUtf8("doubleSpinBoxsmooth"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxsmooth->sizePolicy().hasHeightForWidth());
        doubleSpinBoxsmooth->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(doubleSpinBoxsmooth);

        labelsmooth = new QLabel(groupBoxAlgorithmParams);
        labelsmooth->setObjectName(QString::fromUtf8("labelsmooth"));
        sizePolicy.setHeightForWidth(labelsmooth->sizePolicy().hasHeightForWidth());
        labelsmooth->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(labelsmooth);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBoxAlgorithmParams);

        groupBoxPhysical = new QGroupBox(scrollAreaWidgetContents);
        groupBoxPhysical->setObjectName(QString::fromUtf8("groupBoxPhysical"));
        gridLayout_3 = new QGridLayout(groupBoxPhysical);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        doubleSpinBoxS = new QDoubleSpinBox(groupBoxPhysical);
        doubleSpinBoxS->setObjectName(QString::fromUtf8("doubleSpinBoxS"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxS->sizePolicy().hasHeightForWidth());
        doubleSpinBoxS->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(doubleSpinBoxS);

        labelS = new QLabel(groupBoxPhysical);
        labelS->setObjectName(QString::fromUtf8("labelS"));
        sizePolicy.setHeightForWidth(labelS->sizePolicy().hasHeightForWidth());
        labelS->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(labelS);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        doubleSpinBoxEdgeDistance = new QDoubleSpinBox(groupBoxPhysical);
        doubleSpinBoxEdgeDistance->setObjectName(QString::fromUtf8("doubleSpinBoxEdgeDistance"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxEdgeDistance->sizePolicy().hasHeightForWidth());
        doubleSpinBoxEdgeDistance->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(doubleSpinBoxEdgeDistance);

        labelEdgeDistance = new QLabel(groupBoxPhysical);
        labelEdgeDistance->setObjectName(QString::fromUtf8("labelEdgeDistance"));
        sizePolicy.setHeightForWidth(labelEdgeDistance->sizePolicy().hasHeightForWidth());
        labelEdgeDistance->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(labelEdgeDistance);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        checkBoxGravity = new QCheckBox(groupBoxPhysical);
        checkBoxGravity->setObjectName(QString::fromUtf8("checkBoxGravity"));
        checkBoxGravity->setEnabled(false);

        horizontalLayout_11->addWidget(checkBoxGravity);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        doubleSpinBoxGravityExponent = new QDoubleSpinBox(groupBoxPhysical);
        doubleSpinBoxGravityExponent->setObjectName(QString::fromUtf8("doubleSpinBoxGravityExponent"));
        doubleSpinBoxGravityExponent->setEnabled(false);
        sizePolicy1.setHeightForWidth(doubleSpinBoxGravityExponent->sizePolicy().hasHeightForWidth());
        doubleSpinBoxGravityExponent->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(doubleSpinBoxGravityExponent);

        labelGravityExponent = new QLabel(groupBoxPhysical);
        labelGravityExponent->setObjectName(QString::fromUtf8("labelGravityExponent"));
        sizePolicy.setHeightForWidth(labelGravityExponent->sizePolicy().hasHeightForWidth());
        labelGravityExponent->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(labelGravityExponent);


        verticalLayout_3->addLayout(horizontalLayout_12);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBoxPhysical);

        groupBoxNetWork = new QGroupBox(scrollAreaWidgetContents);
        groupBoxNetWork->setObjectName(QString::fromUtf8("groupBoxNetWork"));
        gridLayout_4 = new QGridLayout(groupBoxNetWork);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        doubleSpinBoxWeightThreshold = new QDoubleSpinBox(groupBoxNetWork);
        doubleSpinBoxWeightThreshold->setObjectName(QString::fromUtf8("doubleSpinBoxWeightThreshold"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxWeightThreshold->sizePolicy().hasHeightForWidth());
        doubleSpinBoxWeightThreshold->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(doubleSpinBoxWeightThreshold);

        labelWeightThreshold = new QLabel(groupBoxNetWork);
        labelWeightThreshold->setObjectName(QString::fromUtf8("labelWeightThreshold"));
        sizePolicy.setHeightForWidth(labelWeightThreshold->sizePolicy().hasHeightForWidth());
        labelWeightThreshold->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(labelWeightThreshold);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        doubleSpinBoxPercentage = new QDoubleSpinBox(groupBoxNetWork);
        doubleSpinBoxPercentage->setObjectName(QString::fromUtf8("doubleSpinBoxPercentage"));
        sizePolicy1.setHeightForWidth(doubleSpinBoxPercentage->sizePolicy().hasHeightForWidth());
        doubleSpinBoxPercentage->setSizePolicy(sizePolicy1);

        horizontalLayout_14->addWidget(doubleSpinBoxPercentage);

        labelPercentage = new QLabel(groupBoxNetWork);
        labelPercentage->setObjectName(QString::fromUtf8("labelPercentage"));
        sizePolicy.setHeightForWidth(labelPercentage->sizePolicy().hasHeightForWidth());
        labelPercentage->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(labelPercentage);


        verticalLayout_4->addLayout(horizontalLayout_14);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBoxNetWork);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_15->addWidget(progressBar);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_4);

        pushButtonRun = new QPushButton(scrollAreaWidgetContents);
        pushButtonRun->setObjectName(QString::fromUtf8("pushButtonRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qgis/themes/default/mTaskRunning.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRun->setIcon(icon);

        horizontalLayout_15->addWidget(pushButtonRun);


        verticalLayout_5->addLayout(horizontalLayout_15);


        gridLayout_5->addLayout(verticalLayout_5, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_6->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(GgsFDEBWidget);

        QMetaObject::connectSlotsByName(GgsFDEBWidget);
    } // setupUi

    void retranslateUi(QWidget *GgsFDEBWidget)
    {
        GgsFDEBWidget->setWindowTitle(QApplication::translate("GgsFDEBWidget", "FDEB", nullptr));
        groupBoxLayers->setTitle(QApplication::translate("GgsFDEBWidget", "\345\233\276\345\261\202", nullptr));
        labelGraphLayer->setText(QApplication::translate("GgsFDEBWidget", "\351\200\211\346\213\251\345\233\276\345\233\276\345\261\202", nullptr));
        groupBoxAlgorithmParams->setTitle(QApplication::translate("GgsFDEBWidget", "\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxK->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\205\250\345\261\200\345\274\271\347\260\247\345\270\270\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelK->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\205\250\345\261\200\345\274\271\347\260\247\345\270\270\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
        labelK->setText(QApplication::translate("GgsFDEBWidget", "K", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBoxI->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\221\250\346\234\237\344\270\255\347\232\204\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelI->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\221\250\346\234\237\344\270\255\347\232\204\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
        labelI->setText(QApplication::translate("GgsFDEBWidget", "I", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBoxCycles->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\211\251\344\275\231\345\276\252\347\216\257\346\225\260\351\207\217", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelCycles->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\211\251\344\275\231\345\276\252\347\216\257\346\225\260\351\207\217", nullptr));
#endif // QT_NO_TOOLTIP
        labelCycles->setText(QApplication::translate("GgsFDEBWidget", "Cycles", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxCompatibility->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\205\274\345\256\271\346\200\247\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelCompatibility->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\205\274\345\256\271\346\200\247\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        labelCompatibility->setText(QApplication::translate("GgsFDEBWidget", "Compatibility", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxsmooth->setToolTip(QApplication::translate("GgsFDEBWidget", "\351\253\230\346\226\257\345\271\263\346\273\221\347\232\204\345\256\275\345\272\246", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelsmooth->setToolTip(QApplication::translate("GgsFDEBWidget", "\351\253\230\346\226\257\345\271\263\346\273\221\347\232\204\345\256\275\345\272\246", nullptr));
#endif // QT_NO_TOOLTIP
        labelsmooth->setText(QApplication::translate("GgsFDEBWidget", "smooth", nullptr));
        groupBoxPhysical->setTitle(QApplication::translate("GgsFDEBWidget", "\347\211\251\347\220\206\345\217\202\346\225\260", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxS->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\234\250\344\270\200\346\254\241\350\277\255\344\273\243\344\270\255\345\210\222\345\210\206\347\202\271\347\232\204\344\275\215\347\247\273", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelS->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\234\250\344\270\200\346\254\241\350\277\255\344\273\243\344\270\255\345\210\222\345\210\206\347\202\271\347\232\204\344\275\215\347\247\273", nullptr));
#endif // QT_NO_TOOLTIP
        labelS->setText(QApplication::translate("GgsFDEBWidget", "S", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxEdgeDistance->setToolTip(QApplication::translate("GgsFDEBWidget", "\350\277\236\350\276\271\344\271\213\351\227\264\347\232\204\346\234\200\345\260\217\350\267\235\347\246\273", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelEdgeDistance->setToolTip(QApplication::translate("GgsFDEBWidget", "\350\277\236\350\276\271\344\271\213\351\227\264\347\232\204\346\234\200\345\260\217\350\267\235\347\246\273", nullptr));
#endif // QT_NO_TOOLTIP
        labelEdgeDistance->setText(QApplication::translate("GgsFDEBWidget", "Edge Distance", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxGravity->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\274\225\345\212\233\346\230\257\345\220\246\345\274\200\345\220\257", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBoxGravity->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        checkBoxGravity->setText(QApplication::translate("GgsFDEBWidget", "gravity", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxGravityExponent->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\274\225\345\212\233\346\214\207\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelGravityExponent->setToolTip(QApplication::translate("GgsFDEBWidget", "\345\274\225\345\212\233\346\214\207\346\225\260", nullptr));
#endif // QT_NO_TOOLTIP
        labelGravityExponent->setText(QApplication::translate("GgsFDEBWidget", "Gravity Exponent", nullptr));
        groupBoxNetWork->setTitle(QApplication::translate("GgsFDEBWidget", "\347\275\221\347\273\234\345\217\202\346\225\260", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxWeightThreshold->setToolTip(QApplication::translate("GgsFDEBWidget", "\350\277\236\350\276\271\346\235\203\351\207\215\347\232\204\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelWeightThreshold->setToolTip(QApplication::translate("GgsFDEBWidget", "\350\277\236\350\276\271\346\235\203\351\207\215\347\232\204\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        labelWeightThreshold->setText(QApplication::translate("GgsFDEBWidget", "Weight Threshold", nullptr));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxPercentage->setToolTip(QApplication::translate("GgsFDEBWidget", "\344\277\235\347\225\231\350\276\271\347\232\204\347\231\276\345\210\206\346\257\224", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelPercentage->setToolTip(QApplication::translate("GgsFDEBWidget", "\344\277\235\347\225\231\350\276\271\347\232\204\347\231\276\345\210\206\346\257\224", nullptr));
#endif // QT_NO_TOOLTIP
        labelPercentage->setText(QApplication::translate("GgsFDEBWidget", "Percentage", nullptr));
        pushButtonRun->setText(QApplication::translate("GgsFDEBWidget", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GgsFDEBWidget: public Ui_GgsFDEBWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSFDEBWIDGET_H
