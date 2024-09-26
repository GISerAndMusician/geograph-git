/********************************************************************************
** Form generated from reading UI file 'widget_svgselector.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SVGSELECTOR_H
#define UI_WIDGET_SVGSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qgscollapsiblegroupbox.h>
#include "qgsfilecontentsourcelineedit.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetSvgSelector
{
public:
    QGridLayout *gridLayout;
    QgsCollapsibleGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *mGroupsLabel;
    QTreeView *mGroupsTreeView;
    QWidget *layoutWidget_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *mImagesLabel;
    QListView *mImagesListView;
    QgsSvgSourceLineEdit *mSvgSourceLineEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetSvgSelector)
    {
        if (WidgetSvgSelector->objectName().isEmpty())
            WidgetSvgSelector->setObjectName(QString::fromUtf8("WidgetSvgSelector"));
        WidgetSvgSelector->resize(315, 490);
        WidgetSvgSelector->setWindowTitle(QString::fromUtf8("Form"));
        gridLayout = new QGridLayout(WidgetSvgSelector);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QgsCollapsibleGroupBox(WidgetSvgSelector);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mGroupsLabel = new QLabel(layoutWidget);
        mGroupsLabel->setObjectName(QString::fromUtf8("mGroupsLabel"));

        verticalLayout->addWidget(mGroupsLabel);

        mGroupsTreeView = new QTreeView(layoutWidget);
        mGroupsTreeView->setObjectName(QString::fromUtf8("mGroupsTreeView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mGroupsTreeView->sizePolicy().hasHeightForWidth());
        mGroupsTreeView->setSizePolicy(sizePolicy1);
        mGroupsTreeView->setMinimumSize(QSize(200, 0));

        verticalLayout->addWidget(mGroupsTreeView);

        splitter->addWidget(layoutWidget);
        layoutWidget_1 = new QWidget(splitter);
        layoutWidget_1->setObjectName(QString::fromUtf8("layoutWidget_1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mImagesLabel = new QLabel(layoutWidget_1);
        mImagesLabel->setObjectName(QString::fromUtf8("mImagesLabel"));

        verticalLayout_2->addWidget(mImagesLabel);

        mImagesListView = new QListView(layoutWidget_1);
        mImagesListView->setObjectName(QString::fromUtf8("mImagesListView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(5);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mImagesListView->sizePolicy().hasHeightForWidth());
        mImagesListView->setSizePolicy(sizePolicy2);
        mImagesListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mImagesListView->setIconSize(QSize(32, 32));
        mImagesListView->setMovement(QListView::Static);
        mImagesListView->setResizeMode(QListView::Adjust);
        mImagesListView->setLayoutMode(QListView::Batched);
        mImagesListView->setSpacing(2);
        mImagesListView->setGridSize(QSize(36, 36));
        mImagesListView->setViewMode(QListView::IconMode);
        mImagesListView->setUniformItemSizes(true);
        mImagesListView->setWordWrap(true);

        verticalLayout_2->addWidget(mImagesListView);

        splitter->addWidget(layoutWidget_1);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 2);

        mSvgSourceLineEdit = new QgsSvgSourceLineEdit(WidgetSvgSelector);
        mSvgSourceLineEdit->setObjectName(QString::fromUtf8("mSvgSourceLineEdit"));
        mSvgSourceLineEdit->setMinimumSize(QSize(0, 0));
        mSvgSourceLineEdit->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(mSvgSourceLineEdit, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 2);


        retranslateUi(WidgetSvgSelector);

        QMetaObject::connectSlotsByName(WidgetSvgSelector);
    } // setupUi

    void retranslateUi(QWidget *WidgetSvgSelector)
    {
        groupBox->setTitle(QApplication::translate("WidgetSvgSelector", "SVG browser", nullptr));
        mGroupsLabel->setText(QApplication::translate("WidgetSvgSelector", "SVG Groups", nullptr));
        mImagesLabel->setText(QApplication::translate("WidgetSvgSelector", "SVG Images", nullptr));
        Q_UNUSED(WidgetSvgSelector);
    } // retranslateUi

};

namespace Ui {
    class WidgetSvgSelector: public Ui_WidgetSvgSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SVGSELECTOR_H
