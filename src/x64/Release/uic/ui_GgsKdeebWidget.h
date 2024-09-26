/********************************************************************************
** Form generated from reading UI file 'GgsKdeebWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSKDEEBWIDGET_H
#define UI_GGSKDEEBWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_GgsKdeebWidget
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxLayer;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelGraphLayer;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxGraphLayer;
    QGroupBox *groupBoxAlgoParams;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBoxAttraction;
    QLabel *labelAttraction;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *spinBoxSmooth;
    QLabel *labelSmooth;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBoxKernel;
    QLabel *labelSmooth_2;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *doubleSpinBoxSplitDist;
    QLabel *labelSplitDist;
    QHBoxLayout *horizontalLayout_7;
    QDoubleSpinBox *doubleSpinBoxRemoveDist;
    QLabel *labelRemoveDist;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spinBoxIterator;
    QLabel *labelIterator;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonRun;

    void setupUi(QWidget *GgsKdeebWidget)
    {
        if (GgsKdeebWidget->objectName().isEmpty())
            GgsKdeebWidget->setObjectName(QString::fromUtf8("GgsKdeebWidget"));
        GgsKdeebWidget->resize(406, 776);
        gridLayout_2 = new QGridLayout(GgsKdeebWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        scrollArea = new QScrollArea(GgsKdeebWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 768));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBoxLayer = new QGroupBox(scrollAreaWidgetContents);
        groupBoxLayer->setObjectName(QString::fromUtf8("groupBoxLayer"));
        gridLayout = new QGridLayout(groupBoxLayer);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelGraphLayer = new QLabel(groupBoxLayer);
        labelGraphLayer->setObjectName(QString::fromUtf8("labelGraphLayer"));

        horizontalLayout->addWidget(labelGraphLayer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        comboBoxGraphLayer = new QComboBox(groupBoxLayer);
        comboBoxGraphLayer->setObjectName(QString::fromUtf8("comboBoxGraphLayer"));

        verticalLayout->addWidget(comboBoxGraphLayer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBoxLayer);

        groupBoxAlgoParams = new QGroupBox(scrollAreaWidgetContents);
        groupBoxAlgoParams->setObjectName(QString::fromUtf8("groupBoxAlgoParams"));
        gridLayout_3 = new QGridLayout(groupBoxAlgoParams);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        doubleSpinBoxAttraction = new QDoubleSpinBox(groupBoxAlgoParams);
        doubleSpinBoxAttraction->setObjectName(QString::fromUtf8("doubleSpinBoxAttraction"));
        doubleSpinBoxAttraction->setMaximum(5.000000000000000);
        doubleSpinBoxAttraction->setValue(2.100000000000000);

        horizontalLayout_2->addWidget(doubleSpinBoxAttraction);

        labelAttraction = new QLabel(groupBoxAlgoParams);
        labelAttraction->setObjectName(QString::fromUtf8("labelAttraction"));

        horizontalLayout_2->addWidget(labelAttraction);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        spinBoxSmooth = new QSpinBox(groupBoxAlgoParams);
        spinBoxSmooth->setObjectName(QString::fromUtf8("spinBoxSmooth"));
        spinBoxSmooth->setMinimum(1);
        spinBoxSmooth->setMaximum(99);
        spinBoxSmooth->setValue(1);

        horizontalLayout_4->addWidget(spinBoxSmooth);

        labelSmooth = new QLabel(groupBoxAlgoParams);
        labelSmooth->setObjectName(QString::fromUtf8("labelSmooth"));

        horizontalLayout_4->addWidget(labelSmooth);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spinBoxKernel = new QSpinBox(groupBoxAlgoParams);
        spinBoxKernel->setObjectName(QString::fromUtf8("spinBoxKernel"));
        spinBoxKernel->setMinimum(1);
        spinBoxKernel->setMaximum(99);
        spinBoxKernel->setValue(25);

        horizontalLayout_3->addWidget(spinBoxKernel);

        labelSmooth_2 = new QLabel(groupBoxAlgoParams);
        labelSmooth_2->setObjectName(QString::fromUtf8("labelSmooth_2"));

        horizontalLayout_3->addWidget(labelSmooth_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        doubleSpinBoxSplitDist = new QDoubleSpinBox(groupBoxAlgoParams);
        doubleSpinBoxSplitDist->setObjectName(QString::fromUtf8("doubleSpinBoxSplitDist"));
        doubleSpinBoxSplitDist->setValue(15.000000000000000);

        horizontalLayout_6->addWidget(doubleSpinBoxSplitDist);

        labelSplitDist = new QLabel(groupBoxAlgoParams);
        labelSplitDist->setObjectName(QString::fromUtf8("labelSplitDist"));

        horizontalLayout_6->addWidget(labelSplitDist);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        doubleSpinBoxRemoveDist = new QDoubleSpinBox(groupBoxAlgoParams);
        doubleSpinBoxRemoveDist->setObjectName(QString::fromUtf8("doubleSpinBoxRemoveDist"));
        doubleSpinBoxRemoveDist->setValue(5.000000000000000);

        horizontalLayout_7->addWidget(doubleSpinBoxRemoveDist);

        labelRemoveDist = new QLabel(groupBoxAlgoParams);
        labelRemoveDist->setObjectName(QString::fromUtf8("labelRemoveDist"));

        horizontalLayout_7->addWidget(labelRemoveDist);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        spinBoxIterator = new QSpinBox(groupBoxAlgoParams);
        spinBoxIterator->setObjectName(QString::fromUtf8("spinBoxIterator"));
        spinBoxIterator->setMinimum(1);
        spinBoxIterator->setMaximum(99);
        spinBoxIterator->setValue(50);

        horizontalLayout_9->addWidget(spinBoxIterator);

        labelIterator = new QLabel(groupBoxAlgoParams);
        labelIterator->setObjectName(QString::fromUtf8("labelIterator"));

        horizontalLayout_9->addWidget(labelIterator);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBoxAlgoParams);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_5->addWidget(progressBar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        pushButtonRun = new QPushButton(scrollAreaWidgetContents);
        pushButtonRun->setObjectName(QString::fromUtf8("pushButtonRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qgis/themes/default/mTaskRunning.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRun->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonRun);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(GgsKdeebWidget);

        QMetaObject::connectSlotsByName(GgsKdeebWidget);
    } // setupUi

    void retranslateUi(QWidget *GgsKdeebWidget)
    {
        GgsKdeebWidget->setWindowTitle(QApplication::translate("GgsKdeebWidget", "KDEEB", nullptr));
        groupBoxLayer->setTitle(QApplication::translate("GgsKdeebWidget", "\345\233\276\345\261\202", nullptr));
        labelGraphLayer->setText(QApplication::translate("GgsKdeebWidget", "\351\200\211\346\213\251\345\233\276\345\233\276\345\261\202", nullptr));
        groupBoxAlgoParams->setTitle(QApplication::translate("GgsKdeebWidget", "\347\256\227\346\263\225\345\217\202\346\225\260", nullptr));
        labelAttraction->setText(QApplication::translate("GgsKdeebWidget", "Attraction", nullptr));
        labelSmooth->setText(QApplication::translate("GgsKdeebWidget", "Smooth", nullptr));
        labelSmooth_2->setText(QApplication::translate("GgsKdeebWidget", "Kernel Size", nullptr));
        labelSplitDist->setText(QApplication::translate("GgsKdeebWidget", "Split Distance (px)", nullptr));
        labelRemoveDist->setText(QApplication::translate("GgsKdeebWidget", "Remove Distance (px)", nullptr));
        labelIterator->setText(QApplication::translate("GgsKdeebWidget", "Iterator", nullptr));
        label->setText(QApplication::translate("GgsKdeebWidget", "\346\263\250\346\204\217\357\274\232\347\224\261\344\272\216\346\266\211\345\217\212\345\210\260\346\261\202\346\240\270\345\257\206\345\272\246\345\233\276\357\274\214\346\211\200\344\273\245\347\256\227\346\263\225\346\211\247\350\241\214\345\211\215\344\274\232\350\207\252\345\212\250\347\274\251\346\224\276\350\207\263\345\233\276\345\261\202\350\214\203\345\233\264\343\200\202", nullptr));
        pushButtonRun->setText(QApplication::translate("GgsKdeebWidget", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GgsKdeebWidget: public Ui_GgsKdeebWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSKDEEBWIDGET_H
