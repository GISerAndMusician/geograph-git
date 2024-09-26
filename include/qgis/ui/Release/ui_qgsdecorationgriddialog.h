/********************************************************************************
** Form generated from reading UI file 'qgsdecorationgriddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSDECORATIONGRIDDIALOG_H
#define UI_QGSDECORATIONGRIDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qgsdoublespinbox.h"
#include "qgsfontbutton.h"
#include "qgsspinbox.h"
#include "qgssymbolbutton.h"

QT_BEGIN_NAMESPACE

class Ui_QgsDecorationGridDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *grpEnable;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QgsSymbolButton *mLineSymbolButton;
    QGridLayout *gridLayout_4;
    QPushButton *mPbtnUpdateFromLayer;
    QPushButton *mPbtnUpdateFromExtents;
    QLabel *mOffsetYLabel;
    QLineEdit *mIntervalYEdit;
    QLineEdit *mIntervalXEdit;
    QLabel *mIntervalYLabel;
    QLabel *mGridTypeLabel;
    QLabel *label;
    QComboBox *mGridTypeComboBox;
    QLabel *mLineSymbolLabel;
    QLineEdit *mOffsetYEdit;
    QLineEdit *mOffsetXEdit;
    QgsSymbolButton *mMarkerSymbolButton;
    QLabel *mIntervalXLabel;
    QLabel *mMarkerSymbolLabel;
    QLabel *mOffsetXLabel;
    QGroupBox *mDrawAnnotationCheckBox;
    QGridLayout *gridLayout;
    QgsSpinBox *mCoordinatePrecisionSpinBox;
    QgsDoubleSpinBox *mDistanceToMapFrameSpinBox;
    QComboBox *mAnnotationDirectionComboBox;
    QLabel *mCoordinatePrecisionLabel;
    QLabel *mDistanceToFrameLabel;
    QLabel *mAnnotationDirectionLabel;
    QgsFontButton *mAnnotationFontButton;
    QLabel *mAnnotationFontLabel;
    QSpacerItem *verticalSpacer;
    QLabel *mUpdateIntervalOffsetLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsDecorationGridDialog)
    {
        if (QgsDecorationGridDialog->objectName().isEmpty())
            QgsDecorationGridDialog->setObjectName(QString::fromUtf8("QgsDecorationGridDialog"));
        QgsDecorationGridDialog->resize(390, 548);
        verticalLayout = new QVBoxLayout(QgsDecorationGridDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        grpEnable = new QGroupBox(QgsDecorationGridDialog);
        grpEnable->setObjectName(QString::fromUtf8("grpEnable"));
        grpEnable->setCheckable(true);
        grpEnable->setChecked(false);
        gridLayout_3 = new QGridLayout(grpEnable);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(grpEnable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 3, 1, 1, 1);

        mLineSymbolButton = new QgsSymbolButton(grpEnable);
        mLineSymbolButton->setObjectName(QString::fromUtf8("mLineSymbolButton"));
        mLineSymbolButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mLineSymbolButton->sizePolicy().hasHeightForWidth());
        mLineSymbolButton->setSizePolicy(sizePolicy);
        mLineSymbolButton->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mLineSymbolButton, 1, 2, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(9, 0, 0, 9);
        mPbtnUpdateFromLayer = new QPushButton(grpEnable);
        mPbtnUpdateFromLayer->setObjectName(QString::fromUtf8("mPbtnUpdateFromLayer"));

        gridLayout_4->addWidget(mPbtnUpdateFromLayer, 0, 1, 1, 1);

        mPbtnUpdateFromExtents = new QPushButton(grpEnable);
        mPbtnUpdateFromExtents->setObjectName(QString::fromUtf8("mPbtnUpdateFromExtents"));

        gridLayout_4->addWidget(mPbtnUpdateFromExtents, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 9, 0, 1, 3);

        mOffsetYLabel = new QLabel(grpEnable);
        mOffsetYLabel->setObjectName(QString::fromUtf8("mOffsetYLabel"));
        mOffsetYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mOffsetYLabel->setWordWrap(true);

        gridLayout_3->addWidget(mOffsetYLabel, 7, 1, 1, 1);

        mIntervalYEdit = new QLineEdit(grpEnable);
        mIntervalYEdit->setObjectName(QString::fromUtf8("mIntervalYEdit"));

        gridLayout_3->addWidget(mIntervalYEdit, 4, 2, 1, 1);

        mIntervalXEdit = new QLineEdit(grpEnable);
        mIntervalXEdit->setObjectName(QString::fromUtf8("mIntervalXEdit"));

        gridLayout_3->addWidget(mIntervalXEdit, 3, 2, 1, 1);

        mIntervalYLabel = new QLabel(grpEnable);
        mIntervalYLabel->setObjectName(QString::fromUtf8("mIntervalYLabel"));
        mIntervalYLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        mIntervalYLabel->setWordWrap(true);

        gridLayout_3->addWidget(mIntervalYLabel, 4, 1, 1, 1);

        mGridTypeLabel = new QLabel(grpEnable);
        mGridTypeLabel->setObjectName(QString::fromUtf8("mGridTypeLabel"));
        mGridTypeLabel->setWordWrap(true);

        gridLayout_3->addWidget(mGridTypeLabel, 0, 0, 1, 2);

        label = new QLabel(grpEnable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 6, 1, 1, 1);

        mGridTypeComboBox = new QComboBox(grpEnable);
        mGridTypeComboBox->setObjectName(QString::fromUtf8("mGridTypeComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mGridTypeComboBox->sizePolicy().hasHeightForWidth());
        mGridTypeComboBox->setSizePolicy(sizePolicy1);
        mGridTypeComboBox->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mGridTypeComboBox, 0, 2, 1, 1);

        mLineSymbolLabel = new QLabel(grpEnable);
        mLineSymbolLabel->setObjectName(QString::fromUtf8("mLineSymbolLabel"));
        mLineSymbolLabel->setWordWrap(true);

        gridLayout_3->addWidget(mLineSymbolLabel, 1, 0, 1, 2);

        mOffsetYEdit = new QLineEdit(grpEnable);
        mOffsetYEdit->setObjectName(QString::fromUtf8("mOffsetYEdit"));

        gridLayout_3->addWidget(mOffsetYEdit, 7, 2, 1, 1);

        mOffsetXEdit = new QLineEdit(grpEnable);
        mOffsetXEdit->setObjectName(QString::fromUtf8("mOffsetXEdit"));

        gridLayout_3->addWidget(mOffsetXEdit, 6, 2, 1, 1);

        mMarkerSymbolButton = new QgsSymbolButton(grpEnable);
        mMarkerSymbolButton->setObjectName(QString::fromUtf8("mMarkerSymbolButton"));
        mMarkerSymbolButton->setEnabled(false);
        sizePolicy.setHeightForWidth(mMarkerSymbolButton->sizePolicy().hasHeightForWidth());
        mMarkerSymbolButton->setSizePolicy(sizePolicy);
        mMarkerSymbolButton->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(mMarkerSymbolButton, 2, 2, 1, 1);

        mIntervalXLabel = new QLabel(grpEnable);
        mIntervalXLabel->setObjectName(QString::fromUtf8("mIntervalXLabel"));
        mIntervalXLabel->setWordWrap(true);

        gridLayout_3->addWidget(mIntervalXLabel, 3, 0, 2, 1);

        mMarkerSymbolLabel = new QLabel(grpEnable);
        mMarkerSymbolLabel->setObjectName(QString::fromUtf8("mMarkerSymbolLabel"));
        mMarkerSymbolLabel->setWordWrap(true);

        gridLayout_3->addWidget(mMarkerSymbolLabel, 2, 0, 1, 2);

        mOffsetXLabel = new QLabel(grpEnable);
        mOffsetXLabel->setObjectName(QString::fromUtf8("mOffsetXLabel"));
        mOffsetXLabel->setWordWrap(true);

        gridLayout_3->addWidget(mOffsetXLabel, 6, 0, 2, 1);

        mDrawAnnotationCheckBox = new QGroupBox(grpEnable);
        mDrawAnnotationCheckBox->setObjectName(QString::fromUtf8("mDrawAnnotationCheckBox"));
        mDrawAnnotationCheckBox->setFlat(false);
        mDrawAnnotationCheckBox->setCheckable(true);
        mDrawAnnotationCheckBox->setChecked(false);
        gridLayout = new QGridLayout(mDrawAnnotationCheckBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        mCoordinatePrecisionSpinBox = new QgsSpinBox(mDrawAnnotationCheckBox);
        mCoordinatePrecisionSpinBox->setObjectName(QString::fromUtf8("mCoordinatePrecisionSpinBox"));

        gridLayout->addWidget(mCoordinatePrecisionSpinBox, 3, 1, 1, 1);

        mDistanceToMapFrameSpinBox = new QgsDoubleSpinBox(mDrawAnnotationCheckBox);
        mDistanceToMapFrameSpinBox->setObjectName(QString::fromUtf8("mDistanceToMapFrameSpinBox"));

        gridLayout->addWidget(mDistanceToMapFrameSpinBox, 2, 1, 1, 1);

        mAnnotationDirectionComboBox = new QComboBox(mDrawAnnotationCheckBox);
        mAnnotationDirectionComboBox->setObjectName(QString::fromUtf8("mAnnotationDirectionComboBox"));

        gridLayout->addWidget(mAnnotationDirectionComboBox, 0, 1, 1, 1);

        mCoordinatePrecisionLabel = new QLabel(mDrawAnnotationCheckBox);
        mCoordinatePrecisionLabel->setObjectName(QString::fromUtf8("mCoordinatePrecisionLabel"));
        mCoordinatePrecisionLabel->setWordWrap(true);

        gridLayout->addWidget(mCoordinatePrecisionLabel, 3, 0, 1, 1);

        mDistanceToFrameLabel = new QLabel(mDrawAnnotationCheckBox);
        mDistanceToFrameLabel->setObjectName(QString::fromUtf8("mDistanceToFrameLabel"));
        mDistanceToFrameLabel->setWordWrap(true);

        gridLayout->addWidget(mDistanceToFrameLabel, 2, 0, 1, 1);

        mAnnotationDirectionLabel = new QLabel(mDrawAnnotationCheckBox);
        mAnnotationDirectionLabel->setObjectName(QString::fromUtf8("mAnnotationDirectionLabel"));
        mAnnotationDirectionLabel->setFrameShape(QFrame::NoFrame);
        mAnnotationDirectionLabel->setWordWrap(true);

        gridLayout->addWidget(mAnnotationDirectionLabel, 0, 0, 1, 1);

        mAnnotationFontButton = new QgsFontButton(mDrawAnnotationCheckBox);
        mAnnotationFontButton->setObjectName(QString::fromUtf8("mAnnotationFontButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mAnnotationFontButton->sizePolicy().hasHeightForWidth());
        mAnnotationFontButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(mAnnotationFontButton, 1, 1, 1, 1);

        mAnnotationFontLabel = new QLabel(mDrawAnnotationCheckBox);
        mAnnotationFontLabel->setObjectName(QString::fromUtf8("mAnnotationFontLabel"));

        gridLayout->addWidget(mAnnotationFontLabel, 1, 0, 1, 1);


        gridLayout_3->addWidget(mDrawAnnotationCheckBox, 18, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 19, 0, 1, 3);

        mUpdateIntervalOffsetLabel = new QLabel(grpEnable);
        mUpdateIntervalOffsetLabel->setObjectName(QString::fromUtf8("mUpdateIntervalOffsetLabel"));

        gridLayout_3->addWidget(mUpdateIntervalOffsetLabel, 8, 0, 1, 3);


        verticalLayout->addWidget(grpEnable);

        buttonBox = new QDialogButtonBox(QgsDecorationGridDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(grpEnable, mGridTypeComboBox);
        QWidget::setTabOrder(mGridTypeComboBox, mLineSymbolButton);
        QWidget::setTabOrder(mLineSymbolButton, mMarkerSymbolButton);
        QWidget::setTabOrder(mMarkerSymbolButton, mIntervalXEdit);
        QWidget::setTabOrder(mIntervalXEdit, mIntervalYEdit);
        QWidget::setTabOrder(mIntervalYEdit, mOffsetXEdit);
        QWidget::setTabOrder(mOffsetXEdit, mOffsetYEdit);
        QWidget::setTabOrder(mOffsetYEdit, mPbtnUpdateFromExtents);
        QWidget::setTabOrder(mPbtnUpdateFromExtents, mPbtnUpdateFromLayer);
        QWidget::setTabOrder(mPbtnUpdateFromLayer, mDrawAnnotationCheckBox);
        QWidget::setTabOrder(mDrawAnnotationCheckBox, mAnnotationDirectionComboBox);
        QWidget::setTabOrder(mAnnotationDirectionComboBox, mAnnotationFontButton);
        QWidget::setTabOrder(mAnnotationFontButton, mDistanceToMapFrameSpinBox);
        QWidget::setTabOrder(mDistanceToMapFrameSpinBox, mCoordinatePrecisionSpinBox);

        retranslateUi(QgsDecorationGridDialog);

        QMetaObject::connectSlotsByName(QgsDecorationGridDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsDecorationGridDialog)
    {
        QgsDecorationGridDialog->setWindowTitle(QApplication::translate("QgsDecorationGridDialog", "Grid Properties", nullptr));
        grpEnable->setTitle(QApplication::translate("QgsDecorationGridDialog", "Enable Grid", nullptr));
        label_2->setText(QApplication::translate("QgsDecorationGridDialog", "X", nullptr));
        mLineSymbolButton->setText(QString());
        mPbtnUpdateFromLayer->setText(QApplication::translate("QgsDecorationGridDialog", "Active Raster Layer", nullptr));
        mPbtnUpdateFromExtents->setText(QApplication::translate("QgsDecorationGridDialog", "Canvas Extents", nullptr));
        mOffsetYLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Y", nullptr));
        mIntervalYLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Y", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        mGridTypeLabel->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        mGridTypeLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Grid type", nullptr));
        label->setText(QApplication::translate("QgsDecorationGridDialog", "X", nullptr));
        mLineSymbolLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Line symbol", nullptr));
        mMarkerSymbolButton->setText(QString());
        mIntervalXLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Interval", nullptr));
        mMarkerSymbolLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Marker symbol", nullptr));
        mOffsetXLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Offset", nullptr));
        mDrawAnnotationCheckBox->setTitle(QApplication::translate("QgsDecorationGridDialog", "Draw Annotation", nullptr));
        mCoordinatePrecisionLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Coordinate precision", nullptr));
        mDistanceToFrameLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Distance to map frame", nullptr));
        mAnnotationDirectionLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Annotation direction", nullptr));
        mAnnotationFontButton->setText(QApplication::translate("QgsDecorationGridDialog", "Font", nullptr));
        mAnnotationFontLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Annotation font", nullptr));
        mUpdateIntervalOffsetLabel->setText(QApplication::translate("QgsDecorationGridDialog", "Update Interval / Offset from", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsDecorationGridDialog: public Ui_QgsDecorationGridDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSDECORATIONGRIDDIALOG_H
