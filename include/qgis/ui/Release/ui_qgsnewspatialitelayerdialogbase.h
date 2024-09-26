/********************************************************************************
** Form generated from reading UI file 'qgsnewspatialitelayerdialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSNEWSPATIALITELAYERDIALOGBASE_H
#define UI_QGSNEWSPATIALITELAYERDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "qgscollapsiblegroupbox.h"
#include "qgsproviderconnectioncombobox.h"
#include "qgsscrollarea.h"

QT_BEGIN_NAMESPACE

class Ui_QgsNewSpatialiteLayerDialogBase
{
public:
    QGridLayout *gridLayout_4;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QLabel *mFileFormatLabel;
    QgsProviderConnectionComboBox *mDatabaseComboBox;
    QToolButton *toolButtonNewDatabase;
    QLabel *label1;
    QLineEdit *leLayerName;
    QLabel *label;
    QComboBox *mGeometryTypeBox;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *mGeometryWithZCheckBox;
    QCheckBox *mGeometryWithMCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leSRID;
    QPushButton *pbnFindSRID;
    QGroupBox *groupBox1;
    QGridLayout *gridLayout_7;
    QLabel *textLabel1;
    QLineEdit *mNameEdit;
    QLabel *textLabel2;
    QComboBox *mTypeBox;
    QToolButton *mAddAttributeButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTreeWidget *mAttributeView;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *mRemoveAttributeButton;
    QgsCollapsibleGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLineEdit *leGeometryColumn;
    QCheckBox *checkBoxPrimaryKey;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsNewSpatialiteLayerDialogBase)
    {
        if (QgsNewSpatialiteLayerDialogBase->objectName().isEmpty())
            QgsNewSpatialiteLayerDialogBase->setObjectName(QString::fromUtf8("QgsNewSpatialiteLayerDialogBase"));
        QgsNewSpatialiteLayerDialogBase->resize(470, 627);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QgsNewSpatialiteLayerDialogBase->sizePolicy().hasHeightForWidth());
        QgsNewSpatialiteLayerDialogBase->setSizePolicy(sizePolicy);
        QgsNewSpatialiteLayerDialogBase->setMinimumSize(QSize(351, 0));
        QgsNewSpatialiteLayerDialogBase->setMaximumSize(QSize(16777215, 16777215));
        QgsNewSpatialiteLayerDialogBase->setModal(true);
        gridLayout_4 = new QGridLayout(QgsNewSpatialiteLayerDialogBase);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea = new QgsScrollArea(QgsNewSpatialiteLayerDialogBase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 483, 549));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        mFileFormatLabel = new QLabel(scrollAreaWidgetContents);
        mFileFormatLabel->setObjectName(QString::fromUtf8("mFileFormatLabel"));
        mFileFormatLabel->setEnabled(true);

        gridLayout_5->addWidget(mFileFormatLabel, 0, 0, 1, 1);

        mDatabaseComboBox = new QgsProviderConnectionComboBox(scrollAreaWidgetContents);
        mDatabaseComboBox->setObjectName(QString::fromUtf8("mDatabaseComboBox"));
        mDatabaseComboBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mDatabaseComboBox->sizePolicy().hasHeightForWidth());
        mDatabaseComboBox->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(mDatabaseComboBox, 0, 1, 1, 1);

        toolButtonNewDatabase = new QToolButton(scrollAreaWidgetContents);
        toolButtonNewDatabase->setObjectName(QString::fromUtf8("toolButtonNewDatabase"));

        gridLayout_5->addWidget(toolButtonNewDatabase, 0, 2, 1, 1);

        label1 = new QLabel(scrollAreaWidgetContents);
        label1->setObjectName(QString::fromUtf8("label1"));

        gridLayout_5->addWidget(label1, 1, 0, 1, 1);

        leLayerName = new QLineEdit(scrollAreaWidgetContents);
        leLayerName->setObjectName(QString::fromUtf8("leLayerName"));
        sizePolicy1.setHeightForWidth(leLayerName->sizePolicy().hasHeightForWidth());
        leLayerName->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(leLayerName, 1, 1, 1, 2);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 2, 0, 1, 1);

        mGeometryTypeBox = new QComboBox(scrollAreaWidgetContents);
        mGeometryTypeBox->setObjectName(QString::fromUtf8("mGeometryTypeBox"));
        mGeometryTypeBox->setEnabled(true);
        sizePolicy1.setHeightForWidth(mGeometryTypeBox->sizePolicy().hasHeightForWidth());
        mGeometryTypeBox->setSizePolicy(sizePolicy1);

        gridLayout_5->addWidget(mGeometryTypeBox, 2, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mGeometryWithZCheckBox = new QCheckBox(scrollAreaWidgetContents);
        mGeometryWithZCheckBox->setObjectName(QString::fromUtf8("mGeometryWithZCheckBox"));

        horizontalLayout_2->addWidget(mGeometryWithZCheckBox);

        mGeometryWithMCheckBox = new QCheckBox(scrollAreaWidgetContents);
        mGeometryWithMCheckBox->setObjectName(QString::fromUtf8("mGeometryWithMCheckBox"));

        horizontalLayout_2->addWidget(mGeometryWithMCheckBox);

        horizontalSpacer_3 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_5->addLayout(horizontalLayout_2, 3, 1, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        leSRID = new QLineEdit(scrollAreaWidgetContents);
        leSRID->setObjectName(QString::fromUtf8("leSRID"));
        leSRID->setReadOnly(true);

        horizontalLayout_3->addWidget(leSRID);

        pbnFindSRID = new QPushButton(scrollAreaWidgetContents);
        pbnFindSRID->setObjectName(QString::fromUtf8("pbnFindSRID"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbnFindSRID->sizePolicy().hasHeightForWidth());
        pbnFindSRID->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mActionSetProjection.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbnFindSRID->setIcon(icon);

        horizontalLayout_3->addWidget(pbnFindSRID);


        gridLayout_5->addLayout(horizontalLayout_3, 4, 1, 1, 2);

        groupBox1 = new QGroupBox(scrollAreaWidgetContents);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        gridLayout_7 = new QGridLayout(groupBox1);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        textLabel1 = new QLabel(groupBox1);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
        textLabel1->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(textLabel1, 0, 0, 1, 1);

        mNameEdit = new QLineEdit(groupBox1);
        mNameEdit->setObjectName(QString::fromUtf8("mNameEdit"));
        sizePolicy1.setHeightForWidth(mNameEdit->sizePolicy().hasHeightForWidth());
        mNameEdit->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(mNameEdit, 0, 1, 1, 2);

        textLabel2 = new QLabel(groupBox1);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        sizePolicy3.setHeightForWidth(textLabel2->sizePolicy().hasHeightForWidth());
        textLabel2->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(textLabel2, 1, 0, 1, 1);

        mTypeBox = new QComboBox(groupBox1);
        mTypeBox->setObjectName(QString::fromUtf8("mTypeBox"));
        sizePolicy1.setHeightForWidth(mTypeBox->sizePolicy().hasHeightForWidth());
        mTypeBox->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(mTypeBox, 1, 1, 1, 2);

        mAddAttributeButton = new QToolButton(groupBox1);
        mAddAttributeButton->setObjectName(QString::fromUtf8("mAddAttributeButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mAddAttributeButton->sizePolicy().hasHeightForWidth());
        mAddAttributeButton->setSizePolicy(sizePolicy4);
        mAddAttributeButton->setLayoutDirection(Qt::LeftToRight);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionNewAttribute.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mAddAttributeButton->setIcon(icon1);
        mAddAttributeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_7->addWidget(mAddAttributeButton, 2, 2, 1, 1);


        gridLayout_5->addWidget(groupBox1, 5, 0, 1, 3);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mAttributeView = new QTreeWidget(groupBox_2);
        mAttributeView->setObjectName(QString::fromUtf8("mAttributeView"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(mAttributeView->sizePolicy().hasHeightForWidth());
        mAttributeView->setSizePolicy(sizePolicy5);
        mAttributeView->setAlternatingRowColors(true);
        mAttributeView->setRootIsDecorated(false);
        mAttributeView->setColumnCount(2);

        gridLayout_3->addWidget(mAttributeView, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        mRemoveAttributeButton = new QToolButton(groupBox_2);
        mRemoveAttributeButton->setObjectName(QString::fromUtf8("mRemoveAttributeButton"));
        sizePolicy4.setHeightForWidth(mRemoveAttributeButton->sizePolicy().hasHeightForWidth());
        mRemoveAttributeButton->setSizePolicy(sizePolicy4);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mActionDeleteAttribute.svg"), QSize(), QIcon::Normal, QIcon::Off);
        mRemoveAttributeButton->setIcon(icon2);
        mRemoveAttributeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(mRemoveAttributeButton, 2, 1, 1, 2);


        gridLayout_5->addWidget(groupBox_2, 6, 0, 1, 3);

        groupBox = new QgsCollapsibleGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setProperty("collapsed", QVariant(true));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        leGeometryColumn = new QLineEdit(groupBox);
        leGeometryColumn->setObjectName(QString::fromUtf8("leGeometryColumn"));
        sizePolicy1.setHeightForWidth(leGeometryColumn->sizePolicy().hasHeightForWidth());
        leGeometryColumn->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(leGeometryColumn, 0, 1, 1, 1);

        checkBoxPrimaryKey = new QCheckBox(groupBox);
        checkBoxPrimaryKey->setObjectName(QString::fromUtf8("checkBoxPrimaryKey"));
        checkBoxPrimaryKey->setChecked(true);

        gridLayout_6->addWidget(checkBoxPrimaryKey, 1, 0, 1, 2);


        gridLayout_5->addWidget(groupBox, 7, 0, 1, 3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QgsNewSpatialiteLayerDialogBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 9, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        mFileFormatLabel->setBuddy(mDatabaseComboBox);
        label1->setBuddy(leLayerName);
        label->setBuddy(mGeometryTypeBox);
        textLabel1->setBuddy(mNameEdit);
        textLabel2->setBuddy(mTypeBox);
        label_2->setBuddy(leGeometryColumn);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(scrollArea, mDatabaseComboBox);
        QWidget::setTabOrder(mDatabaseComboBox, toolButtonNewDatabase);
        QWidget::setTabOrder(toolButtonNewDatabase, leLayerName);
        QWidget::setTabOrder(leLayerName, mGeometryTypeBox);
        QWidget::setTabOrder(mGeometryTypeBox, mGeometryWithZCheckBox);
        QWidget::setTabOrder(mGeometryWithZCheckBox, mGeometryWithMCheckBox);
        QWidget::setTabOrder(mGeometryWithMCheckBox, leSRID);
        QWidget::setTabOrder(leSRID, pbnFindSRID);
        QWidget::setTabOrder(pbnFindSRID, mNameEdit);
        QWidget::setTabOrder(mNameEdit, mTypeBox);
        QWidget::setTabOrder(mTypeBox, mAddAttributeButton);
        QWidget::setTabOrder(mAddAttributeButton, mAttributeView);
        QWidget::setTabOrder(mAttributeView, mRemoveAttributeButton);
        QWidget::setTabOrder(mRemoveAttributeButton, leGeometryColumn);
        QWidget::setTabOrder(leGeometryColumn, checkBoxPrimaryKey);

        retranslateUi(QgsNewSpatialiteLayerDialogBase);
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsNewSpatialiteLayerDialogBase, SLOT(reject()));

        QMetaObject::connectSlotsByName(QgsNewSpatialiteLayerDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsNewSpatialiteLayerDialogBase)
    {
        QgsNewSpatialiteLayerDialogBase->setWindowTitle(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "New SpatiaLite Layer", nullptr));
        mFileFormatLabel->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Database", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButtonNewDatabase->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Create a new SpatiaLite database", nullptr));
#endif // QT_NO_TOOLTIP
        toolButtonNewDatabase->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "\342\200\246", nullptr));
        label1->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Layer name", nullptr));
#ifndef QT_NO_TOOLTIP
        leLayerName->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Name for the new layer", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Geometry type", nullptr));
#ifndef QT_NO_TOOLTIP
        mGeometryTypeBox->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "<html><head/><body><p>Geometry type</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mGeometryWithZCheckBox->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Include Z dimension", nullptr));
        mGeometryWithMCheckBox->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Include M values", nullptr));
#ifndef QT_NO_TOOLTIP
        leSRID->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Spatial Reference Id", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbnFindSRID->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Specify the coordinate reference system of the layer's geometry.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pbnFindSRID->setWhatsThis(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Specify the coordinate reference system of the layer's geometry.", nullptr));
#endif // QT_NO_WHATSTHIS
        groupBox1->setTitle(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "New Field", nullptr));
        textLabel1->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Name", nullptr));
#ifndef QT_NO_TOOLTIP
        mNameEdit->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "A field name", nullptr));
#endif // QT_NO_TOOLTIP
        textLabel2->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Type", nullptr));
#ifndef QT_NO_TOOLTIP
        mAddAttributeButton->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Add field to list", nullptr));
#endif // QT_NO_TOOLTIP
        mAddAttributeButton->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Add to Fields List", nullptr));
        groupBox_2->setTitle(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Fields List", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = mAttributeView->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Type", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Name", nullptr));
#ifndef QT_NO_TOOLTIP
        mRemoveAttributeButton->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Delete selected field", nullptr));
#endif // QT_NO_TOOLTIP
        mRemoveAttributeButton->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Remove Field", nullptr));
        groupBox->setProperty("title", QVariant(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Advanced Options", nullptr)));
        label_2->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Geometry column", nullptr));
#ifndef QT_NO_TOOLTIP
        leGeometryColumn->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Name of the geometry column", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBoxPrimaryKey->setToolTip(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Add an integer id field as the primary key for the new layer", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxPrimaryKey->setText(QApplication::translate("QgsNewSpatialiteLayerDialogBase", "Create an autoincrementing primary key", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsNewSpatialiteLayerDialogBase: public Ui_QgsNewSpatialiteLayerDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSNEWSPATIALITELAYERDIALOGBASE_H
