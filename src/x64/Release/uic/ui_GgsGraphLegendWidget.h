/********************************************************************************
** Form generated from reading UI file 'GgsGraphLegendWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGSGRAPHLEGENDWIDGET_H
#define UI_GGSGRAPHLEGENDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GgsGraphLegendWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *linkage_toolButton;
    QToolButton *remove_toolButton;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidget;

    void setupUi(QWidget *GgsGraphLegendWidget)
    {
        if (GgsGraphLegendWidget->objectName().isEmpty())
            GgsGraphLegendWidget->setObjectName(QString::fromUtf8("GgsGraphLegendWidget"));
        GgsGraphLegendWidget->resize(297, 669);
        gridLayout = new QGridLayout(GgsGraphLegendWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        linkage_toolButton = new QToolButton(GgsGraphLegendWidget);
        linkage_toolButton->setObjectName(QString::fromUtf8("linkage_toolButton"));
        linkage_toolButton->setMinimumSize(QSize(24, 24));
        linkage_toolButton->setMaximumSize(QSize(24, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/graph/bundling/linkage.png"), QSize(), QIcon::Normal, QIcon::Off);
        linkage_toolButton->setIcon(icon);
        linkage_toolButton->setCheckable(true);
        linkage_toolButton->setChecked(true);
        linkage_toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(linkage_toolButton);

        remove_toolButton = new QToolButton(GgsGraphLegendWidget);
        remove_toolButton->setObjectName(QString::fromUtf8("remove_toolButton"));
        remove_toolButton->setMinimumSize(QSize(24, 24));
        remove_toolButton->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qgis/themes/default/mIconSelectRemove.svg"), QSize(), QIcon::Normal, QIcon::Off);
        remove_toolButton->setIcon(icon1);
        remove_toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(remove_toolButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(GgsGraphLegendWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(GgsGraphLegendWidget);

        QMetaObject::connectSlotsByName(GgsGraphLegendWidget);
    } // setupUi

    void retranslateUi(QWidget *GgsGraphLegendWidget)
    {
        GgsGraphLegendWidget->setWindowTitle(QApplication::translate("GgsGraphLegendWidget", "\345\233\276\345\233\276\345\261\202\347\252\227\345\217\243", nullptr));
#ifndef QT_NO_TOOLTIP
        linkage_toolButton->setToolTip(QApplication::translate("GgsGraphLegendWidget", "\345\210\207\346\215\242\345\233\276\345\261\202\350\201\224\345\212\250\346\250\241\345\274\217", nullptr));
#endif // QT_NO_TOOLTIP
        linkage_toolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        remove_toolButton->setToolTip(QApplication::translate("GgsGraphLegendWidget", "\345\210\240\351\231\244\345\233\276\345\233\276\345\261\202", nullptr));
#endif // QT_NO_TOOLTIP
        remove_toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GgsGraphLegendWidget: public Ui_GgsGraphLegendWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGSGRAPHLEGENDWIDGET_H
