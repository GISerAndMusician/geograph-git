/********************************************************************************
** Form generated from reading UI file 'qgsgeonodesourceselectbase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSGEONODESOURCESELECTBASE_H
#define UI_QGSGEONODESOURCESELECTBASE_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_QgsGeonodeSourceSelectBase
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GroupBox1;
    QGridLayout *gridLayout_2;
    QComboBox *cmbConnections;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConnect;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *spacerItem;
    QPushButton *btnLoad;
    QPushButton *btnSave;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cbxUseTitleLayerName;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayoutFilter;
    QLabel *labelFilter;
    QLineEdit *lineFilter;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsGeonodeSourceSelectBase)
    {
        if (QgsGeonodeSourceSelectBase->objectName().isEmpty())
            QgsGeonodeSourceSelectBase->setObjectName(QString::fromUtf8("QgsGeonodeSourceSelectBase"));
        QgsGeonodeSourceSelectBase->resize(592, 439);
        gridLayout = new QGridLayout(QgsGeonodeSourceSelectBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GroupBox1 = new QGroupBox(QgsGeonodeSourceSelectBase);
        GroupBox1->setObjectName(QString::fromUtf8("GroupBox1"));
        gridLayout_2 = new QGridLayout(GroupBox1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cmbConnections = new QComboBox(GroupBox1);
        cmbConnections->setObjectName(QString::fromUtf8("cmbConnections"));

        gridLayout_2->addWidget(cmbConnections, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnConnect = new QPushButton(GroupBox1);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setEnabled(false);

        horizontalLayout->addWidget(btnConnect);

        btnNew = new QPushButton(GroupBox1);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(GroupBox1);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setEnabled(false);

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(GroupBox1);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(false);

        horizontalLayout->addWidget(btnDelete);

        spacerItem = new QSpacerItem(171, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerItem);

        btnLoad = new QPushButton(GroupBox1);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        horizontalLayout->addWidget(btnLoad);

        btnSave = new QPushButton(GroupBox1);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout->addWidget(GroupBox1, 0, 0, 1, 1);

        treeView = new QTreeView(QgsGeonodeSourceSelectBase);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeView->setSortingEnabled(true);
        treeView->header()->setVisible(true);

        gridLayout->addWidget(treeView, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cbxUseTitleLayerName = new QCheckBox(QgsGeonodeSourceSelectBase);
        cbxUseTitleLayerName->setObjectName(QString::fromUtf8("cbxUseTitleLayerName"));

        horizontalLayout_4->addWidget(cbxUseTitleLayerName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        horizontalLayoutFilter = new QHBoxLayout();
        horizontalLayoutFilter->setObjectName(QString::fromUtf8("horizontalLayoutFilter"));
        labelFilter = new QLabel(QgsGeonodeSourceSelectBase);
        labelFilter->setObjectName(QString::fromUtf8("labelFilter"));
        labelFilter->setEnabled(true);

        horizontalLayoutFilter->addWidget(labelFilter);

        lineFilter = new QLineEdit(QgsGeonodeSourceSelectBase);
        lineFilter->setObjectName(QString::fromUtf8("lineFilter"));
        lineFilter->setEnabled(true);

        horizontalLayoutFilter->addWidget(lineFilter);


        gridLayout->addLayout(horizontalLayoutFilter, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(QgsGeonodeSourceSelectBase);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Help);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        labelFilter->setBuddy(lineFilter);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cmbConnections, btnConnect);
        QWidget::setTabOrder(btnConnect, btnNew);
        QWidget::setTabOrder(btnNew, btnEdit);
        QWidget::setTabOrder(btnEdit, btnDelete);
        QWidget::setTabOrder(btnDelete, btnLoad);
        QWidget::setTabOrder(btnLoad, btnSave);
        QWidget::setTabOrder(btnSave, lineFilter);
        QWidget::setTabOrder(lineFilter, treeView);
        QWidget::setTabOrder(treeView, cbxUseTitleLayerName);

        retranslateUi(QgsGeonodeSourceSelectBase);

        QMetaObject::connectSlotsByName(QgsGeonodeSourceSelectBase);
    } // setupUi

    void retranslateUi(QDialog *QgsGeonodeSourceSelectBase)
    {
        QgsGeonodeSourceSelectBase->setWindowTitle(QApplication::translate("QgsGeonodeSourceSelectBase", "Add GeoNode Layer", nullptr));
        GroupBox1->setTitle(QApplication::translate("QgsGeonodeSourceSelectBase", "GeoNode Connections", nullptr));
#ifndef QT_NO_TOOLTIP
        btnConnect->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Connect to selected service", nullptr));
#endif // QT_NO_TOOLTIP
        btnConnect->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "C&onnect", nullptr));
#ifndef QT_NO_TOOLTIP
        btnNew->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Create a new service connection", nullptr));
#endif // QT_NO_TOOLTIP
        btnNew->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "&New", nullptr));
#ifndef QT_NO_TOOLTIP
        btnEdit->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Edit selected service connection", nullptr));
#endif // QT_NO_TOOLTIP
        btnEdit->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Edit", nullptr));
#ifndef QT_NO_TOOLTIP
        btnDelete->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Remove connection to selected service", nullptr));
#endif // QT_NO_TOOLTIP
        btnDelete->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        btnLoad->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Load connections from file", nullptr));
#endif // QT_NO_TOOLTIP
        btnLoad->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Load", nullptr));
#ifndef QT_NO_TOOLTIP
        btnSave->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Save connections to file", nullptr));
#endif // QT_NO_TOOLTIP
        btnSave->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Save", nullptr));
        cbxUseTitleLayerName->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Use title for layer name", nullptr));
        labelFilter->setText(QApplication::translate("QgsGeonodeSourceSelectBase", "Filter", nullptr));
#ifndef QT_NO_TOOLTIP
        lineFilter->setToolTip(QApplication::translate("QgsGeonodeSourceSelectBase", "Display WFS FeatureTypes containing this word in the title, name or abstract", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineFilter->setWhatsThis(QApplication::translate("QgsGeonodeSourceSelectBase", "Display WFS FeatureTypes containing this word in the title, name or abstract", nullptr));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class QgsGeonodeSourceSelectBase: public Ui_QgsGeonodeSourceSelectBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSGEONODESOURCESELECTBASE_H
