/********************************************************************************
** Form generated from reading UI file 'map3dconfigwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP3DCONFIGWIDGET_H
#define UI_MAP3DCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsdoublespinbox.h"
#include "qgslightswidget.h"
#include "qgsmaplayercombobox.h"
#include "qgsmessagebar.h"
#include "qgsphongmaterialwidget.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_Map3DConfigWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QgsMessageBar *mMessageBar;
    QSplitter *m3DOptionsSplitter;
    QFrame *m3DOptionsListFrame;
    QVBoxLayout *verticalLayout_23;
    QListWidget *m3DOptionsListWidget;
    QFrame *m3DOptionGroupsFrame;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *m3DOptionsStackedWidget;
    QWidget *mPageTerrain;
    QVBoxLayout *verticalLayout_61;
    QgsScrollArea *scrollAreaTerrain;
    QWidget *scrollAreaTerrainWidgetContents;
    QVBoxLayout *verticalLayoutTerrain;
    QGroupBox *groupTerrain;
    QGridLayout *gridLayout1;
    QgsMapLayerComboBox *cboTerrainLayer;
    QLabel *labelTerrainLayer;
    QComboBox *cboTerrainType;
    QLabel *labelTerrainResolution;
    QgsDoubleSpinBox *spinTerrainScale;
    QLabel *labelTerrainType;
    QgsSpinBox *spinTerrainResolution;
    QLabel *labelTerrainScale;
    QLabel *labelTerrainSkirtHeight;
    QgsDoubleSpinBox *spinTerrainSkirtHeight;
    QFrame *groupMeshTerrainShading;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupTerrainShading;
    QVBoxLayout *verticalLayout_2;
    QgsPhongMaterialWidget *widgetTerrainMaterial;
    QSpacerItem *verticalSpacerTerrain;
    QWidget *mPageLight;
    QVBoxLayout *verticalLayout_64;
    QgsScrollArea *scrollAreaLight;
    QWidget *scrollAreaLightWidgetContents;
    QVBoxLayout *verticalLayoutLight;
    QGroupBox *groupLights;
    QVBoxLayout *verticalLayout_31;
    QgsLightsWidget *widgetLights;
    QSpacerItem *verticalSpacerLights;
    QWidget *mPageShadow;
    QVBoxLayout *verticalLayout_6;
    QgsScrollArea *scrollAreaShadow;
    QWidget *scrollAreaShadowWidgetContents;
    QVBoxLayout *verticalLayoutShadow;
    QGroupBox *groupShadowRendering;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacerShadow;
    QWidget *mPageCameraSkybox;
    QVBoxLayout *verticalLayout_62;
    QgsScrollArea *scrollAreaCameraSkybox;
    QWidget *scrollAreaCameraSkyboxWidgetContents;
    QVBoxLayout *verticalLayoutCameraSkybox;
    QGroupBox *cameraTerrain;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QgsSpinBox *spinCameraFieldOfView;
    QGroupBox *groupSkyboxSettings;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacerCameraSkybox;
    QWidget *mPageAdvanced;
    QVBoxLayout *verticalLayout_63;
    QgsScrollArea *scrollAreaAdvanced;
    QWidget *scrollAreaAdvancedWidgetContents;
    QVBoxLayout *verticalLayoutAdvanced;
    QGroupBox *groupAdvanced;
    QVBoxLayout *verticalLayout_32;
    QGridLayout *gridLayoutAdvanced;
    QCheckBox *chkShowLabels;
    QCheckBox *chkShowBoundingBoxes;
    QCheckBox *chkShowCameraViewCenter;
    QgsDoubleSpinBox *spinScreenError;
    QgsSpinBox *spinMapResolution;
    QgsDoubleSpinBox *spinGroundError;
    QLabel *labelZoomLevels;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_6;
    QCheckBox *chkShowTileInfo;
    QCheckBox *chkShowLightSourceOrigins;
    QSpacerItem *verticalSpacerAdvanced;

    void setupUi(QWidget *Map3DConfigWidget)
    {
        if (Map3DConfigWidget->objectName().isEmpty())
            Map3DConfigWidget->setObjectName(QString::fromUtf8("Map3DConfigWidget"));
        Map3DConfigWidget->resize(775, 620);
        verticalLayout_4 = new QVBoxLayout(Map3DConfigWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        mMessageBar = new QgsMessageBar(Map3DConfigWidget);
        mMessageBar->setObjectName(QString::fromUtf8("mMessageBar"));

        verticalLayout_4->addWidget(mMessageBar);

        m3DOptionsSplitter = new QSplitter(Map3DConfigWidget);
        m3DOptionsSplitter->setObjectName(QString::fromUtf8("m3DOptionsSplitter"));
        m3DOptionsSplitter->setOrientation(Qt::Horizontal);
        m3DOptionsSplitter->setChildrenCollapsible(false);
        m3DOptionsListFrame = new QFrame(m3DOptionsSplitter);
        m3DOptionsListFrame->setObjectName(QString::fromUtf8("m3DOptionsListFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m3DOptionsListFrame->sizePolicy().hasHeightForWidth());
        m3DOptionsListFrame->setSizePolicy(sizePolicy);
        m3DOptionsListFrame->setMinimumSize(QSize(32, 0));
        m3DOptionsListFrame->setFrameShape(QFrame::NoFrame);
        m3DOptionsListFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_23 = new QVBoxLayout(m3DOptionsListFrame);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        verticalLayout_23->setContentsMargins(3, 0, 0, 0);
        m3DOptionsListWidget = new QListWidget(m3DOptionsListFrame);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/themes/default/mLayoutItem3DMap.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(m3DOptionsListWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/themes/default/mActionHighlightFeature.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(m3DOptionsListWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/themes/default/mIconShadow.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(m3DOptionsListWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/themes/default/mIconCamera.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(m3DOptionsListWidget);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/themes/default/propertyicons/system.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(m3DOptionsListWidget);
        __qlistwidgetitem4->setIcon(icon4);
        m3DOptionsListWidget->setObjectName(QString::fromUtf8("m3DOptionsListWidget"));
        m3DOptionsListWidget->setMinimumSize(QSize(32, 0));
        m3DOptionsListWidget->setProperty("showDropIndicator", QVariant(false));
        m3DOptionsListWidget->setIconSize(QSize(20, 20));

        verticalLayout_23->addWidget(m3DOptionsListWidget);

        m3DOptionsSplitter->addWidget(m3DOptionsListFrame);
        m3DOptionGroupsFrame = new QFrame(m3DOptionsSplitter);
        m3DOptionGroupsFrame->setObjectName(QString::fromUtf8("m3DOptionGroupsFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m3DOptionGroupsFrame->sizePolicy().hasHeightForWidth());
        m3DOptionGroupsFrame->setSizePolicy(sizePolicy1);
        m3DOptionGroupsFrame->setFrameShape(QFrame::NoFrame);
        m3DOptionGroupsFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(m3DOptionGroupsFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        m3DOptionsStackedWidget = new QStackedWidget(m3DOptionGroupsFrame);
        m3DOptionsStackedWidget->setObjectName(QString::fromUtf8("m3DOptionsStackedWidget"));
        mPageTerrain = new QWidget();
        mPageTerrain->setObjectName(QString::fromUtf8("mPageTerrain"));
        verticalLayout_61 = new QVBoxLayout(mPageTerrain);
        verticalLayout_61->setObjectName(QString::fromUtf8("verticalLayout_61"));
        verticalLayout_61->setContentsMargins(-1, 0, 0, 0);
        scrollAreaTerrain = new QgsScrollArea(mPageTerrain);
        scrollAreaTerrain->setObjectName(QString::fromUtf8("scrollAreaTerrain"));
        scrollAreaTerrain->setFrameShape(QFrame::NoFrame);
        scrollAreaTerrain->setWidgetResizable(true);
        scrollAreaTerrainWidgetContents = new QWidget();
        scrollAreaTerrainWidgetContents->setObjectName(QString::fromUtf8("scrollAreaTerrainWidgetContents"));
        scrollAreaTerrainWidgetContents->setGeometry(QRect(0, 0, 317, 220));
        verticalLayoutTerrain = new QVBoxLayout(scrollAreaTerrainWidgetContents);
        verticalLayoutTerrain->setObjectName(QString::fromUtf8("verticalLayoutTerrain"));
        verticalLayoutTerrain->setContentsMargins(0, 0, 0, 0);
        groupTerrain = new QGroupBox(scrollAreaTerrainWidgetContents);
        groupTerrain->setObjectName(QString::fromUtf8("groupTerrain"));
        gridLayout1 = new QGridLayout(groupTerrain);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        cboTerrainLayer = new QgsMapLayerComboBox(groupTerrain);
        cboTerrainLayer->setObjectName(QString::fromUtf8("cboTerrainLayer"));

        gridLayout1->addWidget(cboTerrainLayer, 1, 1, 1, 2);

        labelTerrainLayer = new QLabel(groupTerrain);
        labelTerrainLayer->setObjectName(QString::fromUtf8("labelTerrainLayer"));

        gridLayout1->addWidget(labelTerrainLayer, 1, 0, 1, 1);

        cboTerrainType = new QComboBox(groupTerrain);
        cboTerrainType->setObjectName(QString::fromUtf8("cboTerrainType"));

        gridLayout1->addWidget(cboTerrainType, 0, 1, 1, 2);

        labelTerrainResolution = new QLabel(groupTerrain);
        labelTerrainResolution->setObjectName(QString::fromUtf8("labelTerrainResolution"));

        gridLayout1->addWidget(labelTerrainResolution, 3, 0, 1, 1);

        spinTerrainScale = new QgsDoubleSpinBox(groupTerrain);
        spinTerrainScale->setObjectName(QString::fromUtf8("spinTerrainScale"));
        spinTerrainScale->setValue(1.000000000000000);

        gridLayout1->addWidget(spinTerrainScale, 2, 1, 1, 2);

        labelTerrainType = new QLabel(groupTerrain);
        labelTerrainType->setObjectName(QString::fromUtf8("labelTerrainType"));

        gridLayout1->addWidget(labelTerrainType, 0, 0, 1, 1);

        spinTerrainResolution = new QgsSpinBox(groupTerrain);
        spinTerrainResolution->setObjectName(QString::fromUtf8("spinTerrainResolution"));
        spinTerrainResolution->setMaximum(4096);

        gridLayout1->addWidget(spinTerrainResolution, 3, 1, 1, 2);

        labelTerrainScale = new QLabel(groupTerrain);
        labelTerrainScale->setObjectName(QString::fromUtf8("labelTerrainScale"));

        gridLayout1->addWidget(labelTerrainScale, 2, 0, 1, 1);

        labelTerrainSkirtHeight = new QLabel(groupTerrain);
        labelTerrainSkirtHeight->setObjectName(QString::fromUtf8("labelTerrainSkirtHeight"));

        gridLayout1->addWidget(labelTerrainSkirtHeight, 4, 0, 1, 1);

        spinTerrainSkirtHeight = new QgsDoubleSpinBox(groupTerrain);
        spinTerrainSkirtHeight->setObjectName(QString::fromUtf8("spinTerrainSkirtHeight"));
        spinTerrainSkirtHeight->setDecimals(1);
        spinTerrainSkirtHeight->setMaximum(10000.000000000000000);
        spinTerrainSkirtHeight->setSingleStep(10.000000000000000);

        gridLayout1->addWidget(spinTerrainSkirtHeight, 4, 1, 1, 2);


        verticalLayoutTerrain->addWidget(groupTerrain);

        groupMeshTerrainShading = new QFrame(scrollAreaTerrainWidgetContents);
        groupMeshTerrainShading->setObjectName(QString::fromUtf8("groupMeshTerrainShading"));
        verticalLayout = new QVBoxLayout(groupMeshTerrainShading);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayoutTerrain->addWidget(groupMeshTerrainShading);

        groupTerrainShading = new QGroupBox(scrollAreaTerrainWidgetContents);
        groupTerrainShading->setObjectName(QString::fromUtf8("groupTerrainShading"));
        groupTerrainShading->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(groupTerrainShading);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTerrainMaterial = new QgsPhongMaterialWidget(groupTerrainShading);
        widgetTerrainMaterial->setObjectName(QString::fromUtf8("widgetTerrainMaterial"));

        verticalLayout_2->addWidget(widgetTerrainMaterial);


        verticalLayoutTerrain->addWidget(groupTerrainShading);

        verticalSpacerTerrain = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutTerrain->addItem(verticalSpacerTerrain);

        scrollAreaTerrain->setWidget(scrollAreaTerrainWidgetContents);

        verticalLayout_61->addWidget(scrollAreaTerrain);

        m3DOptionsStackedWidget->addWidget(mPageTerrain);
        mPageLight = new QWidget();
        mPageLight->setObjectName(QString::fromUtf8("mPageLight"));
        verticalLayout_64 = new QVBoxLayout(mPageLight);
        verticalLayout_64->setObjectName(QString::fromUtf8("verticalLayout_64"));
        verticalLayout_64->setContentsMargins(-1, 0, 0, 0);
        scrollAreaLight = new QgsScrollArea(mPageLight);
        scrollAreaLight->setObjectName(QString::fromUtf8("scrollAreaLight"));
        scrollAreaLight->setFrameShape(QFrame::NoFrame);
        scrollAreaLight->setWidgetResizable(true);
        scrollAreaLightWidgetContents = new QWidget();
        scrollAreaLightWidgetContents->setObjectName(QString::fromUtf8("scrollAreaLightWidgetContents"));
        scrollAreaLightWidgetContents->setGeometry(QRect(0, 0, 706, 603));
        verticalLayoutLight = new QVBoxLayout(scrollAreaLightWidgetContents);
        verticalLayoutLight->setObjectName(QString::fromUtf8("verticalLayoutLight"));
        verticalLayoutLight->setContentsMargins(0, 0, 0, 0);
        groupLights = new QGroupBox(scrollAreaLightWidgetContents);
        groupLights->setObjectName(QString::fromUtf8("groupLights"));
        verticalLayout_31 = new QVBoxLayout(groupLights);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        verticalLayout_31->setContentsMargins(0, 0, 0, 0);
        widgetLights = new QgsLightsWidget(groupLights);
        widgetLights->setObjectName(QString::fromUtf8("widgetLights"));

        verticalLayout_31->addWidget(widgetLights);


        verticalLayoutLight->addWidget(groupLights);

        verticalSpacerLights = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutLight->addItem(verticalSpacerLights);

        scrollAreaLight->setWidget(scrollAreaLightWidgetContents);

        verticalLayout_64->addWidget(scrollAreaLight);

        m3DOptionsStackedWidget->addWidget(mPageLight);
        mPageShadow = new QWidget();
        mPageShadow->setObjectName(QString::fromUtf8("mPageShadow"));
        verticalLayout_6 = new QVBoxLayout(mPageShadow);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 0, 0, 0);
        scrollAreaShadow = new QgsScrollArea(mPageShadow);
        scrollAreaShadow->setObjectName(QString::fromUtf8("scrollAreaShadow"));
        scrollAreaShadow->setFrameShape(QFrame::NoFrame);
        scrollAreaShadow->setWidgetResizable(true);
        scrollAreaShadowWidgetContents = new QWidget();
        scrollAreaShadowWidgetContents->setObjectName(QString::fromUtf8("scrollAreaShadowWidgetContents"));
        scrollAreaShadowWidgetContents->setGeometry(QRect(0, 0, 143, 28));
        verticalLayoutShadow = new QVBoxLayout(scrollAreaShadowWidgetContents);
        verticalLayoutShadow->setObjectName(QString::fromUtf8("verticalLayoutShadow"));
        verticalLayoutShadow->setContentsMargins(0, 0, 0, 0);
        groupShadowRendering = new QGroupBox(scrollAreaShadowWidgetContents);
        groupShadowRendering->setObjectName(QString::fromUtf8("groupShadowRendering"));
        groupShadowRendering->setCheckable(true);
        groupShadowRendering->setChecked(false);
        gridLayout_6 = new QGridLayout(groupShadowRendering);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        verticalLayoutShadow->addWidget(groupShadowRendering);

        verticalSpacerShadow = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutShadow->addItem(verticalSpacerShadow);

        scrollAreaShadow->setWidget(scrollAreaShadowWidgetContents);

        verticalLayout_6->addWidget(scrollAreaShadow);

        m3DOptionsStackedWidget->addWidget(mPageShadow);
        mPageCameraSkybox = new QWidget();
        mPageCameraSkybox->setObjectName(QString::fromUtf8("mPageCameraSkybox"));
        verticalLayout_62 = new QVBoxLayout(mPageCameraSkybox);
        verticalLayout_62->setObjectName(QString::fromUtf8("verticalLayout_62"));
        verticalLayout_62->setContentsMargins(-1, 0, 0, 0);
        scrollAreaCameraSkybox = new QgsScrollArea(mPageCameraSkybox);
        scrollAreaCameraSkybox->setObjectName(QString::fromUtf8("scrollAreaCameraSkybox"));
        scrollAreaCameraSkybox->setFrameShape(QFrame::NoFrame);
        scrollAreaCameraSkybox->setWidgetResizable(true);
        scrollAreaCameraSkyboxWidgetContents = new QWidget();
        scrollAreaCameraSkyboxWidgetContents->setObjectName(QString::fromUtf8("scrollAreaCameraSkyboxWidgetContents"));
        scrollAreaCameraSkyboxWidgetContents->setGeometry(QRect(0, 0, 204, 113));
        verticalLayoutCameraSkybox = new QVBoxLayout(scrollAreaCameraSkyboxWidgetContents);
        verticalLayoutCameraSkybox->setObjectName(QString::fromUtf8("verticalLayoutCameraSkybox"));
        verticalLayoutCameraSkybox->setContentsMargins(0, 0, 0, 0);
        cameraTerrain = new QGroupBox(scrollAreaCameraSkyboxWidgetContents);
        cameraTerrain->setObjectName(QString::fromUtf8("cameraTerrain"));
        gridLayout = new QGridLayout(cameraTerrain);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(cameraTerrain);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        spinCameraFieldOfView = new QgsSpinBox(cameraTerrain);
        spinCameraFieldOfView->setObjectName(QString::fromUtf8("spinCameraFieldOfView"));
        spinCameraFieldOfView->setMaximum(180);

        gridLayout->addWidget(spinCameraFieldOfView, 1, 1, 1, 2);


        verticalLayoutCameraSkybox->addWidget(cameraTerrain);

        groupSkyboxSettings = new QGroupBox(scrollAreaCameraSkyboxWidgetContents);
        groupSkyboxSettings->setObjectName(QString::fromUtf8("groupSkyboxSettings"));
        groupSkyboxSettings->setCheckable(true);
        groupSkyboxSettings->setChecked(false);
        gridLayout_3 = new QGridLayout(groupSkyboxSettings);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        verticalLayoutCameraSkybox->addWidget(groupSkyboxSettings);

        verticalSpacerCameraSkybox = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutCameraSkybox->addItem(verticalSpacerCameraSkybox);

        scrollAreaCameraSkybox->setWidget(scrollAreaCameraSkyboxWidgetContents);

        verticalLayout_62->addWidget(scrollAreaCameraSkybox);

        m3DOptionsStackedWidget->addWidget(mPageCameraSkybox);
        mPageAdvanced = new QWidget();
        mPageAdvanced->setObjectName(QString::fromUtf8("mPageAdvanced"));
        verticalLayout_63 = new QVBoxLayout(mPageAdvanced);
        verticalLayout_63->setObjectName(QString::fromUtf8("verticalLayout_63"));
        verticalLayout_63->setContentsMargins(-1, 0, 0, 0);
        scrollAreaAdvanced = new QgsScrollArea(mPageAdvanced);
        scrollAreaAdvanced->setObjectName(QString::fromUtf8("scrollAreaAdvanced"));
        scrollAreaAdvanced->setFrameShape(QFrame::NoFrame);
        scrollAreaAdvanced->setWidgetResizable(true);
        scrollAreaAdvancedWidgetContents = new QWidget();
        scrollAreaAdvancedWidgetContents->setObjectName(QString::fromUtf8("scrollAreaAdvancedWidgetContents"));
        scrollAreaAdvancedWidgetContents->setGeometry(QRect(0, 0, 343, 277));
        verticalLayoutAdvanced = new QVBoxLayout(scrollAreaAdvancedWidgetContents);
        verticalLayoutAdvanced->setObjectName(QString::fromUtf8("verticalLayoutAdvanced"));
        verticalLayoutAdvanced->setContentsMargins(0, 0, 0, 0);
        groupAdvanced = new QGroupBox(scrollAreaAdvancedWidgetContents);
        groupAdvanced->setObjectName(QString::fromUtf8("groupAdvanced"));
        verticalLayout_32 = new QVBoxLayout(groupAdvanced);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        gridLayoutAdvanced = new QGridLayout();
        gridLayoutAdvanced->setObjectName(QString::fromUtf8("gridLayoutAdvanced"));
        chkShowLabels = new QCheckBox(groupAdvanced);
        chkShowLabels->setObjectName(QString::fromUtf8("chkShowLabels"));

        gridLayoutAdvanced->addWidget(chkShowLabels, 4, 0, 1, 2);

        chkShowBoundingBoxes = new QCheckBox(groupAdvanced);
        chkShowBoundingBoxes->setObjectName(QString::fromUtf8("chkShowBoundingBoxes"));

        gridLayoutAdvanced->addWidget(chkShowBoundingBoxes, 6, 0, 1, 2);

        chkShowCameraViewCenter = new QCheckBox(groupAdvanced);
        chkShowCameraViewCenter->setObjectName(QString::fromUtf8("chkShowCameraViewCenter"));

        gridLayoutAdvanced->addWidget(chkShowCameraViewCenter, 7, 0, 1, 2);

        spinScreenError = new QgsDoubleSpinBox(groupAdvanced);
        spinScreenError->setObjectName(QString::fromUtf8("spinScreenError"));
        spinScreenError->setDecimals(1);

        gridLayoutAdvanced->addWidget(spinScreenError, 1, 1, 1, 1);

        spinMapResolution = new QgsSpinBox(groupAdvanced);
        spinMapResolution->setObjectName(QString::fromUtf8("spinMapResolution"));
        spinMapResolution->setMaximum(4096);

        gridLayoutAdvanced->addWidget(spinMapResolution, 0, 1, 1, 1);

        spinGroundError = new QgsDoubleSpinBox(groupAdvanced);
        spinGroundError->setObjectName(QString::fromUtf8("spinGroundError"));
        spinGroundError->setDecimals(1);
        spinGroundError->setMinimum(0.100000000000000);
        spinGroundError->setMaximum(1000.000000000000000);
        spinGroundError->setValue(1.000000000000000);

        gridLayoutAdvanced->addWidget(spinGroundError, 2, 1, 1, 1);

        labelZoomLevels = new QLabel(groupAdvanced);
        labelZoomLevels->setObjectName(QString::fromUtf8("labelZoomLevels"));

        gridLayoutAdvanced->addWidget(labelZoomLevels, 3, 1, 1, 1);

        label_5 = new QLabel(groupAdvanced);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayoutAdvanced->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(groupAdvanced);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayoutAdvanced->addWidget(label_4, 0, 0, 1, 1);

        label_7 = new QLabel(groupAdvanced);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayoutAdvanced->addWidget(label_7, 3, 0, 1, 1);

        label_6 = new QLabel(groupAdvanced);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayoutAdvanced->addWidget(label_6, 2, 0, 1, 1);

        chkShowTileInfo = new QCheckBox(groupAdvanced);
        chkShowTileInfo->setObjectName(QString::fromUtf8("chkShowTileInfo"));

        gridLayoutAdvanced->addWidget(chkShowTileInfo, 5, 0, 1, 2);

        chkShowLightSourceOrigins = new QCheckBox(groupAdvanced);
        chkShowLightSourceOrigins->setObjectName(QString::fromUtf8("chkShowLightSourceOrigins"));

        gridLayoutAdvanced->addWidget(chkShowLightSourceOrigins, 8, 0, 1, 2);


        verticalLayout_32->addLayout(gridLayoutAdvanced);

        verticalSpacerAdvanced = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_32->addItem(verticalSpacerAdvanced);


        verticalLayoutAdvanced->addWidget(groupAdvanced);

        scrollAreaAdvanced->setWidget(scrollAreaAdvancedWidgetContents);

        verticalLayout_63->addWidget(scrollAreaAdvanced);

        m3DOptionsStackedWidget->addWidget(mPageAdvanced);

        verticalLayout_3->addWidget(m3DOptionsStackedWidget);

        m3DOptionsSplitter->addWidget(m3DOptionGroupsFrame);

        verticalLayout_4->addWidget(m3DOptionsSplitter);

        verticalLayout_4->setStretch(1, 1);
        QWidget::setTabOrder(spinCameraFieldOfView, cboTerrainType);
        QWidget::setTabOrder(cboTerrainType, cboTerrainLayer);
        QWidget::setTabOrder(cboTerrainLayer, spinTerrainScale);
        QWidget::setTabOrder(spinTerrainScale, spinTerrainResolution);
        QWidget::setTabOrder(spinTerrainResolution, spinTerrainSkirtHeight);
        QWidget::setTabOrder(spinTerrainSkirtHeight, groupTerrainShading);
        QWidget::setTabOrder(groupTerrainShading, groupSkyboxSettings);
        QWidget::setTabOrder(groupSkyboxSettings, spinMapResolution);
        QWidget::setTabOrder(spinMapResolution, spinScreenError);
        QWidget::setTabOrder(spinScreenError, spinGroundError);
        QWidget::setTabOrder(spinGroundError, chkShowLabels);
        QWidget::setTabOrder(chkShowLabels, chkShowTileInfo);
        QWidget::setTabOrder(chkShowTileInfo, chkShowBoundingBoxes);
        QWidget::setTabOrder(chkShowBoundingBoxes, chkShowCameraViewCenter);
        QWidget::setTabOrder(chkShowCameraViewCenter, chkShowLightSourceOrigins);

        retranslateUi(Map3DConfigWidget);

        m3DOptionsStackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Map3DConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *Map3DConfigWidget)
    {
        Map3DConfigWidget->setWindowTitle(QApplication::translate("Map3DConfigWidget", "Configure 3D Map Rendering", nullptr));

        const bool __sortingEnabled = m3DOptionsListWidget->isSortingEnabled();
        m3DOptionsListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = m3DOptionsListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Map3DConfigWidget", "Terrain", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem->setToolTip(QApplication::translate("Map3DConfigWidget", "Terrain settings", nullptr));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem1 = m3DOptionsListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Map3DConfigWidget", "Lights", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem1->setToolTip(QApplication::translate("Map3DConfigWidget", "Lights settings", nullptr));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem2 = m3DOptionsListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Map3DConfigWidget", "Shadow", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem2->setToolTip(QApplication::translate("Map3DConfigWidget", "Shadow settings", nullptr));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem3 = m3DOptionsListWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Map3DConfigWidget", "Camera & Skybox", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem3->setToolTip(QApplication::translate("Map3DConfigWidget", "Camera and skybox settings", nullptr));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem4 = m3DOptionsListWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Map3DConfigWidget", "Advanced", nullptr));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem4->setToolTip(QApplication::translate("Map3DConfigWidget", "Advanced settings", nullptr));
#endif // QT_NO_TOOLTIP
        m3DOptionsListWidget->setSortingEnabled(__sortingEnabled);

        groupTerrain->setTitle(QApplication::translate("Map3DConfigWidget", "Terrain", nullptr));
        labelTerrainLayer->setText(QApplication::translate("Map3DConfigWidget", "Elevation", nullptr));
        labelTerrainResolution->setText(QApplication::translate("Map3DConfigWidget", "Tile resolution", nullptr));
        labelTerrainType->setText(QApplication::translate("Map3DConfigWidget", "Type", nullptr));
        spinTerrainResolution->setSuffix(QApplication::translate("Map3DConfigWidget", " px", nullptr));
        labelTerrainScale->setText(QApplication::translate("Map3DConfigWidget", "Vertical scale", nullptr));
        labelTerrainSkirtHeight->setText(QApplication::translate("Map3DConfigWidget", "Skirt height", nullptr));
        spinTerrainSkirtHeight->setSuffix(QApplication::translate("Map3DConfigWidget", " map units", nullptr));
        groupTerrainShading->setTitle(QApplication::translate("Map3DConfigWidget", "Terrain Shading", nullptr));
        groupLights->setTitle(QApplication::translate("Map3DConfigWidget", "Lights", nullptr));
        groupShadowRendering->setTitle(QApplication::translate("Map3DConfigWidget", "Show Shadows", nullptr));
        cameraTerrain->setTitle(QApplication::translate("Map3DConfigWidget", "Camera", nullptr));
        label_3->setText(QApplication::translate("Map3DConfigWidget", "Field of View", nullptr));
        spinCameraFieldOfView->setSuffix(QApplication::translate("Map3DConfigWidget", "\302\260", nullptr));
        groupSkyboxSettings->setTitle(QApplication::translate("Map3DConfigWidget", "Show Skybox", nullptr));
        groupAdvanced->setTitle(QApplication::translate("Map3DConfigWidget", "Advanced Settings", nullptr));
        chkShowLabels->setText(QApplication::translate("Map3DConfigWidget", "Show labels", nullptr));
        chkShowBoundingBoxes->setText(QApplication::translate("Map3DConfigWidget", "Show bounding boxes", nullptr));
        chkShowCameraViewCenter->setText(QApplication::translate("Map3DConfigWidget", "Show camera's view center", nullptr));
        spinScreenError->setSuffix(QApplication::translate("Map3DConfigWidget", " px", nullptr));
        spinMapResolution->setSuffix(QApplication::translate("Map3DConfigWidget", " px", nullptr));
        spinGroundError->setSuffix(QApplication::translate("Map3DConfigWidget", " map units", nullptr));
        labelZoomLevels->setText(QApplication::translate("Map3DConfigWidget", "0", nullptr));
        label_5->setText(QApplication::translate("Map3DConfigWidget", "Max. screen error", nullptr));
        label_4->setText(QApplication::translate("Map3DConfigWidget", "Map tile resolution", nullptr));
        label_7->setText(QApplication::translate("Map3DConfigWidget", "Zoom levels", nullptr));
        label_6->setText(QApplication::translate("Map3DConfigWidget", "Max. ground error", nullptr));
        chkShowTileInfo->setText(QApplication::translate("Map3DConfigWidget", "Show map tile info", nullptr));
        chkShowLightSourceOrigins->setText(QApplication::translate("Map3DConfigWidget", "Show light sources", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Map3DConfigWidget: public Ui_Map3DConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP3DCONFIGWIDGET_H
