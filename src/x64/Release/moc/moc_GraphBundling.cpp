/****************************************************************************
** Meta object code from reading C++ file 'GraphBundling.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GraphBundling.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphBundling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphBundling_t {
    QByteArrayData data[118];
    char stringdata0[1932];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphBundling_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphBundling_t qt_meta_stringdata_GraphBundling = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GraphBundling"
QT_MOC_LITERAL(1, 14, 18), // "activeLayerChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "QgsMapLayer*"
QT_MOC_LITERAL(4, 47, 5), // "layer"
QT_MOC_LITERAL(5, 53, 18), // "connectionsChanged"
QT_MOC_LITERAL(6, 72, 10), // "newProject"
QT_MOC_LITERAL(7, 83, 10), // "saveAsFile"
QT_MOC_LITERAL(8, 94, 12), // "onlySelected"
QT_MOC_LITERAL(9, 107, 17), // "defaultToAddToMap"
QT_MOC_LITERAL(10, 125, 16), // "saveAsRasterFile"
QT_MOC_LITERAL(11, 142, 15), // "QgsRasterLayer*"
QT_MOC_LITERAL(12, 158, 18), // "defaultAddToCanvas"
QT_MOC_LITERAL(13, 177, 13), // "saveStyleFile"
QT_MOC_LITERAL(14, 191, 24), // "makeMemoryLayerPermanent"
QT_MOC_LITERAL(15, 216, 15), // "QgsVectorLayer*"
QT_MOC_LITERAL(16, 232, 15), // "layerProperties"
QT_MOC_LITERAL(17, 248, 10), // "messageBar"
QT_MOC_LITERAL(18, 259, 14), // "QgsMessageBar*"
QT_MOC_LITERAL(19, 274, 28), // "updateNewLayerInsertionPoint"
QT_MOC_LITERAL(20, 303, 20), // "autoSelectAddedLayer"
QT_MOC_LITERAL(21, 324, 19), // "QList<QgsMapLayer*>"
QT_MOC_LITERAL(22, 344, 6), // "layers"
QT_MOC_LITERAL(23, 351, 9), // "mapCanvas"
QT_MOC_LITERAL(24, 361, 13), // "QgsMapCanvas*"
QT_MOC_LITERAL(25, 375, 24), // "askUserForDatumTransform"
QT_MOC_LITERAL(26, 400, 28), // "QgsCoordinateReferenceSystem"
QT_MOC_LITERAL(27, 429, 9), // "sourceCrs"
QT_MOC_LITERAL(28, 439, 14), // "destinationCrs"
QT_MOC_LITERAL(29, 454, 18), // "const QgsMapLayer*"
QT_MOC_LITERAL(30, 473, 22), // "askUserForOGRSublayers"
QT_MOC_LITERAL(31, 496, 16), // "QgsVectorLayer*&"
QT_MOC_LITERAL(32, 513, 22), // "layerTransferOwnership"
QT_MOC_LITERAL(33, 536, 9), // "subLayers"
QT_MOC_LITERAL(34, 546, 23), // "askUserForZipItemLayers"
QT_MOC_LITERAL(35, 570, 4), // "path"
QT_MOC_LITERAL(36, 575, 29), // "shouldAskUserForGDALSublayers"
QT_MOC_LITERAL(37, 605, 23), // "askUserForGDALSublayers"
QT_MOC_LITERAL(38, 629, 17), // "loadGDALSublayers"
QT_MOC_LITERAL(39, 647, 3), // "uri"
QT_MOC_LITERAL(40, 651, 4), // "list"
QT_MOC_LITERAL(41, 656, 14), // "freezeCanvases"
QT_MOC_LITERAL(42, 671, 6), // "frozen"
QT_MOC_LITERAL(43, 678, 17), // "showStatusMessage"
QT_MOC_LITERAL(44, 696, 7), // "message"
QT_MOC_LITERAL(45, 704, 19), // "actionShowAllLayers"
QT_MOC_LITERAL(46, 724, 8), // "QAction*"
QT_MOC_LITERAL(47, 733, 19), // "actionHideAllLayers"
QT_MOC_LITERAL(48, 753, 24), // "actionShowSelectedLayers"
QT_MOC_LITERAL(49, 778, 24), // "actionHideSelectedLayers"
QT_MOC_LITERAL(50, 803, 26), // "actionToggleSelectedLayers"
QT_MOC_LITERAL(51, 830, 39), // "actionToggleSelectedLayersInd..."
QT_MOC_LITERAL(52, 870, 26), // "actionHideDeselectedLayers"
QT_MOC_LITERAL(53, 897, 17), // "dataSourceManager"
QT_MOC_LITERAL(54, 915, 8), // "pageName"
QT_MOC_LITERAL(55, 924, 14), // "addRasterLayer"
QT_MOC_LITERAL(56, 939, 11), // "rasterLayer"
QT_MOC_LITERAL(57, 951, 14), // "addVectorLayer"
QT_MOC_LITERAL(58, 966, 15), // "vectorLayerPath"
QT_MOC_LITERAL(59, 982, 8), // "baseName"
QT_MOC_LITERAL(60, 991, 11), // "providerKey"
QT_MOC_LITERAL(61, 1003, 15), // "addVectorLayers"
QT_MOC_LITERAL(62, 1019, 16), // "layerQStringList"
QT_MOC_LITERAL(63, 1036, 3), // "enc"
QT_MOC_LITERAL(64, 1040, 14), // "dataSourceType"
QT_MOC_LITERAL(65, 1055, 16), // "changeDataSource"
QT_MOC_LITERAL(66, 1072, 15), // "addVirtualLayer"
QT_MOC_LITERAL(67, 1088, 11), // "removeLayer"
QT_MOC_LITERAL(68, 1100, 17), // "legendGroupSetCrs"
QT_MOC_LITERAL(69, 1118, 21), // "saveAsLayerDefinition"
QT_MOC_LITERAL(70, 1140, 22), // "setProjectCrsFromLayer"
QT_MOC_LITERAL(71, 1163, 11), // "setLayerCrs"
QT_MOC_LITERAL(72, 1175, 11), // "deselectAll"
QT_MOC_LITERAL(73, 1187, 16), // "setAppStyleSheet"
QT_MOC_LITERAL(74, 1204, 10), // "stylesheet"
QT_MOC_LITERAL(75, 1215, 26), // "layerTreeViewDoubleClicked"
QT_MOC_LITERAL(76, 1242, 11), // "QModelIndex"
QT_MOC_LITERAL(77, 1254, 5), // "index"
QT_MOC_LITERAL(78, 1260, 37), // "activateDeactivateLayerRelate..."
QT_MOC_LITERAL(79, 1298, 20), // "onActiveLayerChanged"
QT_MOC_LITERAL(80, 1319, 18), // "updateFilterLegend"
QT_MOC_LITERAL(81, 1338, 30), // "toggleFilterLegendByExpression"
QT_MOC_LITERAL(82, 1369, 7), // "checked"
QT_MOC_LITERAL(83, 1377, 6), // "zoomIn"
QT_MOC_LITERAL(84, 1384, 7), // "zoomOut"
QT_MOC_LITERAL(85, 1392, 3), // "pan"
QT_MOC_LITERAL(86, 1396, 8), // "identify"
QT_MOC_LITERAL(87, 1405, 14), // "selectFeatures"
QT_MOC_LITERAL(88, 1420, 15), // "selectByPolygon"
QT_MOC_LITERAL(89, 1436, 16), // "selectByFreehand"
QT_MOC_LITERAL(90, 1453, 14), // "selectByRadius"
QT_MOC_LITERAL(91, 1468, 14), // "showPanMessage"
QT_MOC_LITERAL(92, 1483, 8), // "distance"
QT_MOC_LITERAL(93, 1492, 26), // "QgsUnitTypes::DistanceUnit"
QT_MOC_LITERAL(94, 1519, 4), // "unit"
QT_MOC_LITERAL(95, 1524, 7), // "bearing"
QT_MOC_LITERAL(96, 1532, 20), // "selectionModeChanged"
QT_MOC_LITERAL(97, 1553, 22), // "QgsMapToolSelect::Mode"
QT_MOC_LITERAL(98, 1576, 4), // "mode"
QT_MOC_LITERAL(99, 1581, 16), // "refreshMapCanvas"
QT_MOC_LITERAL(100, 1598, 15), // "redrawAllLayers"
QT_MOC_LITERAL(101, 1614, 30), // "updateMouseCoordinatePrecision"
QT_MOC_LITERAL(102, 1645, 7), // "fileNew"
QT_MOC_LITERAL(103, 1653, 16), // "promptToSaveFlag"
QT_MOC_LITERAL(104, 1670, 10), // "forceBlank"
QT_MOC_LITERAL(105, 1681, 16), // "addCSVGraphLayer"
QT_MOC_LITERAL(106, 1698, 13), // "showAllLayers"
QT_MOC_LITERAL(107, 1712, 13), // "hideAllLayers"
QT_MOC_LITERAL(108, 1726, 18), // "showSelectedLayers"
QT_MOC_LITERAL(109, 1745, 18), // "hideSelectedLayers"
QT_MOC_LITERAL(110, 1764, 20), // "toggleSelectedLayers"
QT_MOC_LITERAL(111, 1785, 33), // "toggleSelectedLayersIndepende..."
QT_MOC_LITERAL(112, 1819, 20), // "hideDeselectedLayers"
QT_MOC_LITERAL(113, 1840, 18), // "showFDEBDockWidget"
QT_MOC_LITERAL(114, 1859, 20), // "showMINGLEDockWidget"
QT_MOC_LITERAL(115, 1880, 19), // "showKDEEBDockWidget"
QT_MOC_LITERAL(116, 1900, 22), // "onLocalWindowTriggered"
QT_MOC_LITERAL(117, 1923, 8) // "bChecked"

    },
    "GraphBundling\0activeLayerChanged\0\0"
    "QgsMapLayer*\0layer\0connectionsChanged\0"
    "newProject\0saveAsFile\0onlySelected\0"
    "defaultToAddToMap\0saveAsRasterFile\0"
    "QgsRasterLayer*\0defaultAddToCanvas\0"
    "saveStyleFile\0makeMemoryLayerPermanent\0"
    "QgsVectorLayer*\0layerProperties\0"
    "messageBar\0QgsMessageBar*\0"
    "updateNewLayerInsertionPoint\0"
    "autoSelectAddedLayer\0QList<QgsMapLayer*>\0"
    "layers\0mapCanvas\0QgsMapCanvas*\0"
    "askUserForDatumTransform\0"
    "QgsCoordinateReferenceSystem\0sourceCrs\0"
    "destinationCrs\0const QgsMapLayer*\0"
    "askUserForOGRSublayers\0QgsVectorLayer*&\0"
    "layerTransferOwnership\0subLayers\0"
    "askUserForZipItemLayers\0path\0"
    "shouldAskUserForGDALSublayers\0"
    "askUserForGDALSublayers\0loadGDALSublayers\0"
    "uri\0list\0freezeCanvases\0frozen\0"
    "showStatusMessage\0message\0actionShowAllLayers\0"
    "QAction*\0actionHideAllLayers\0"
    "actionShowSelectedLayers\0"
    "actionHideSelectedLayers\0"
    "actionToggleSelectedLayers\0"
    "actionToggleSelectedLayersIndependently\0"
    "actionHideDeselectedLayers\0dataSourceManager\0"
    "pageName\0addRasterLayer\0rasterLayer\0"
    "addVectorLayer\0vectorLayerPath\0baseName\0"
    "providerKey\0addVectorLayers\0"
    "layerQStringList\0enc\0dataSourceType\0"
    "changeDataSource\0addVirtualLayer\0"
    "removeLayer\0legendGroupSetCrs\0"
    "saveAsLayerDefinition\0setProjectCrsFromLayer\0"
    "setLayerCrs\0deselectAll\0setAppStyleSheet\0"
    "stylesheet\0layerTreeViewDoubleClicked\0"
    "QModelIndex\0index\0"
    "activateDeactivateLayerRelatedActions\0"
    "onActiveLayerChanged\0updateFilterLegend\0"
    "toggleFilterLegendByExpression\0checked\0"
    "zoomIn\0zoomOut\0pan\0identify\0selectFeatures\0"
    "selectByPolygon\0selectByFreehand\0"
    "selectByRadius\0showPanMessage\0distance\0"
    "QgsUnitTypes::DistanceUnit\0unit\0bearing\0"
    "selectionModeChanged\0QgsMapToolSelect::Mode\0"
    "mode\0refreshMapCanvas\0redrawAllLayers\0"
    "updateMouseCoordinatePrecision\0fileNew\0"
    "promptToSaveFlag\0forceBlank\0"
    "addCSVGraphLayer\0showAllLayers\0"
    "hideAllLayers\0showSelectedLayers\0"
    "hideSelectedLayers\0toggleSelectedLayers\0"
    "toggleSelectedLayersIndependently\0"
    "hideDeselectedLayers\0showFDEBDockWidget\0"
    "showMINGLEDockWidget\0showKDEEBDockWidget\0"
    "onLocalWindowTriggered\0bChecked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphBundling[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      81,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  419,    2, 0x06 /* Public */,
       5,    0,  422,    2, 0x06 /* Public */,
       6,    0,  423,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,  424,    2, 0x0a /* Public */,
       7,    2,  431,    2, 0x2a /* Public | MethodCloned */,
       7,    1,  436,    2, 0x2a /* Public | MethodCloned */,
       7,    0,  439,    2, 0x2a /* Public | MethodCloned */,
      10,    2,  440,    2, 0x0a /* Public */,
      10,    1,  445,    2, 0x2a /* Public | MethodCloned */,
      10,    0,  448,    2, 0x2a /* Public | MethodCloned */,
      13,    1,  449,    2, 0x0a /* Public */,
      13,    0,  452,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  453,    2, 0x0a /* Public */,
      16,    0,  456,    2, 0x0a /* Public */,
      17,    0,  457,    2, 0x0a /* Public */,
      19,    0,  458,    2, 0x0a /* Public */,
      20,    1,  459,    2, 0x0a /* Public */,
      23,    0,  462,    2, 0x0a /* Public */,
      25,    3,  463,    2, 0x0a /* Public */,
      25,    2,  470,    2, 0x2a /* Public | MethodCloned */,
      30,    2,  475,    2, 0x0a /* Public */,
      34,    1,  480,    2, 0x0a /* Public */,
      36,    1,  483,    2, 0x0a /* Public */,
      37,    1,  486,    2, 0x0a /* Public */,
      38,    2,  489,    2, 0x0a /* Public */,
      41,    1,  494,    2, 0x0a /* Public */,
      41,    0,  497,    2, 0x2a /* Public | MethodCloned */,
      43,    1,  498,    2, 0x0a /* Public */,
      45,    0,  501,    2, 0x0a /* Public */,
      47,    0,  502,    2, 0x0a /* Public */,
      48,    0,  503,    2, 0x0a /* Public */,
      49,    0,  504,    2, 0x0a /* Public */,
      50,    0,  505,    2, 0x0a /* Public */,
      51,    0,  506,    2, 0x0a /* Public */,
      52,    0,  507,    2, 0x0a /* Public */,
      53,    1,  508,    2, 0x0a /* Public */,
      53,    0,  511,    2, 0x2a /* Public | MethodCloned */,
      55,    1,  512,    2, 0x0a /* Public */,
      57,    3,  515,    2, 0x0a /* Public */,
      61,    3,  522,    2, 0x0a /* Public */,
      65,    1,  529,    2, 0x0a /* Public */,
      66,    0,  532,    2, 0x0a /* Public */,
      67,    0,  533,    2, 0x0a /* Public */,
      68,    0,  534,    2, 0x0a /* Public */,
      69,    0,  535,    2, 0x0a /* Public */,
      70,    0,  536,    2, 0x0a /* Public */,
      71,    0,  537,    2, 0x0a /* Public */,
      72,    0,  538,    2, 0x0a /* Public */,
      73,    1,  539,    2, 0x08 /* Private */,
      75,    1,  542,    2, 0x08 /* Private */,
      78,    1,  545,    2, 0x08 /* Private */,
      79,    1,  548,    2, 0x08 /* Private */,
      80,    0,  551,    2, 0x08 /* Private */,
      81,    1,  552,    2, 0x08 /* Private */,
      83,    0,  555,    2, 0x08 /* Private */,
      84,    0,  556,    2, 0x08 /* Private */,
      85,    0,  557,    2, 0x08 /* Private */,
      86,    0,  558,    2, 0x08 /* Private */,
      87,    0,  559,    2, 0x08 /* Private */,
      88,    0,  560,    2, 0x08 /* Private */,
      89,    0,  561,    2, 0x08 /* Private */,
      90,    0,  562,    2, 0x08 /* Private */,
      91,    3,  563,    2, 0x08 /* Private */,
      96,    1,  570,    2, 0x08 /* Private */,
      99,    1,  573,    2, 0x08 /* Private */,
      99,    0,  576,    2, 0x28 /* Private | MethodCloned */,
     101,    0,  577,    2, 0x08 /* Private */,
     102,    2,  578,    2, 0x08 /* Private */,
     102,    1,  583,    2, 0x28 /* Private | MethodCloned */,
     105,    0,  586,    2, 0x08 /* Private */,
     106,    0,  587,    2, 0x08 /* Private */,
     107,    0,  588,    2, 0x08 /* Private */,
     108,    0,  589,    2, 0x08 /* Private */,
     109,    0,  590,    2, 0x08 /* Private */,
     110,    0,  591,    2, 0x08 /* Private */,
     111,    0,  592,    2, 0x08 /* Private */,
     112,    0,  593,    2, 0x08 /* Private */,
     113,    0,  594,    2, 0x08 /* Private */,
     114,    0,  595,    2, 0x08 /* Private */,
     115,    0,  596,    2, 0x08 /* Private */,
     116,    1,  597,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString, 0x80000000 | 3, QMetaType::Bool, QMetaType::Bool,    4,    8,    9,
    QMetaType::QString, 0x80000000 | 3, QMetaType::Bool,    4,    8,
    QMetaType::QString, 0x80000000 | 3,    4,
    QMetaType::QString,
    QMetaType::QString, 0x80000000 | 11, QMetaType::Bool,    4,   12,
    QMetaType::QString, 0x80000000 | 11,    4,
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    4,
    QMetaType::Void,
    0x80000000 | 18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    0x80000000 | 24,
    QMetaType::Bool, 0x80000000 | 26, 0x80000000 | 26, 0x80000000 | 29,   27,   28,    4,
    QMetaType::Bool, 0x80000000 | 26, 0x80000000 | 26,   27,   28,
    0x80000000 | 21, 0x80000000 | 31, QMetaType::QStringList,   32,   33,
    QMetaType::Bool, QMetaType::QString,   35,
    QMetaType::Bool, 0x80000000 | 11,    4,
    0x80000000 | 21, 0x80000000 | 11,    4,
    0x80000000 | 21, QMetaType::QString, QMetaType::QStringList,   39,   40,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   44,
    0x80000000 | 46,
    0x80000000 | 46,
    0x80000000 | 46,
    0x80000000 | 46,
    0x80000000 | 46,
    0x80000000 | 46,
    0x80000000 | 46,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 11,   56,
    0x80000000 | 15, QMetaType::QString, QMetaType::QString, QMetaType::QString,   58,   59,   60,
    QMetaType::Bool, QMetaType::QStringList, QMetaType::QString, QMetaType::QString,   62,   63,   64,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   74,
    QMetaType::Void, 0x80000000 | 76,   77,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   82,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 93, QMetaType::Double,   92,   94,   95,
    QMetaType::Void, 0x80000000 | 97,   98,
    QMetaType::Void, QMetaType::Bool,  100,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,  103,  104,
    QMetaType::Bool, QMetaType::Bool,  103,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  117,

       0        // eod
};

void GraphBundling::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphBundling *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->activeLayerChanged((*reinterpret_cast< QgsMapLayer*(*)>(_a[1]))); break;
        case 1: _t->connectionsChanged(); break;
        case 2: _t->newProject(); break;
        case 3: { QString _r = _t->saveAsFile((*reinterpret_cast< QgsMapLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->saveAsFile((*reinterpret_cast< QgsMapLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->saveAsFile((*reinterpret_cast< QgsMapLayer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->saveAsFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->saveAsRasterFile((*reinterpret_cast< QgsRasterLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->saveAsRasterFile((*reinterpret_cast< QgsRasterLayer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->saveAsRasterFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->saveStyleFile((*reinterpret_cast< QgsMapLayer*(*)>(_a[1]))); break;
        case 11: _t->saveStyleFile(); break;
        case 12: _t->makeMemoryLayerPermanent((*reinterpret_cast< QgsVectorLayer*(*)>(_a[1]))); break;
        case 13: _t->layerProperties(); break;
        case 14: { QgsMessageBar* _r = _t->messageBar();
            if (_a[0]) *reinterpret_cast< QgsMessageBar**>(_a[0]) = std::move(_r); }  break;
        case 15: _t->updateNewLayerInsertionPoint(); break;
        case 16: _t->autoSelectAddedLayer((*reinterpret_cast< QList<QgsMapLayer*>(*)>(_a[1]))); break;
        case 17: { QgsMapCanvas* _r = _t->mapCanvas();
            if (_a[0]) *reinterpret_cast< QgsMapCanvas**>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->askUserForDatumTransform((*reinterpret_cast< const QgsCoordinateReferenceSystem(*)>(_a[1])),(*reinterpret_cast< const QgsCoordinateReferenceSystem(*)>(_a[2])),(*reinterpret_cast< const QgsMapLayer*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->askUserForDatumTransform((*reinterpret_cast< const QgsCoordinateReferenceSystem(*)>(_a[1])),(*reinterpret_cast< const QgsCoordinateReferenceSystem(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { QList<QgsMapLayer*> _r = _t->askUserForOGRSublayers((*reinterpret_cast< QgsVectorLayer*(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QgsMapLayer*>*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->askUserForZipItemLayers((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->shouldAskUserForGDALSublayers((*reinterpret_cast< QgsRasterLayer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { QList<QgsMapLayer*> _r = _t->askUserForGDALSublayers((*reinterpret_cast< QgsRasterLayer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QgsMapLayer*>*>(_a[0]) = std::move(_r); }  break;
        case 24: { QList<QgsMapLayer*> _r = _t->loadGDALSublayers((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QgsMapLayer*>*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->freezeCanvases((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->freezeCanvases(); break;
        case 27: _t->showStatusMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: { QAction* _r = _t->actionShowAllLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 29: { QAction* _r = _t->actionHideAllLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 30: { QAction* _r = _t->actionShowSelectedLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 31: { QAction* _r = _t->actionHideSelectedLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 32: { QAction* _r = _t->actionToggleSelectedLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 33: { QAction* _r = _t->actionToggleSelectedLayersIndependently();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 34: { QAction* _r = _t->actionHideDeselectedLayers();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = std::move(_r); }  break;
        case 35: _t->dataSourceManager((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->dataSourceManager(); break;
        case 37: { bool _r = _t->addRasterLayer((*reinterpret_cast< QgsRasterLayer*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { QgsVectorLayer* _r = _t->addVectorLayer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QgsVectorLayer**>(_a[0]) = std::move(_r); }  break;
        case 39: { bool _r = _t->addVectorLayers((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->changeDataSource((*reinterpret_cast< QgsMapLayer*(*)>(_a[1]))); break;
        case 41: _t->addVirtualLayer(); break;
        case 42: _t->removeLayer(); break;
        case 43: _t->legendGroupSetCrs(); break;
        case 44: _t->saveAsLayerDefinition(); break;
        case 45: _t->setProjectCrsFromLayer(); break;
        case 46: _t->setLayerCrs(); break;
        case 47: _t->deselectAll(); break;
        case 48: _t->setAppStyleSheet((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->layerTreeViewDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 50: _t->activateDeactivateLayerRelatedActions((*reinterpret_cast< QgsMapLayer*(*)>(_a[1]))); break;
        case 51: _t->onActiveLayerChanged((*reinterpret_cast< QgsMapLayer*(*)>(_a[1]))); break;
        case 52: _t->updateFilterLegend(); break;
        case 53: _t->toggleFilterLegendByExpression((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->zoomIn(); break;
        case 55: _t->zoomOut(); break;
        case 56: _t->pan(); break;
        case 57: _t->identify(); break;
        case 58: _t->selectFeatures(); break;
        case 59: _t->selectByPolygon(); break;
        case 60: _t->selectByFreehand(); break;
        case 61: _t->selectByRadius(); break;
        case 62: _t->showPanMessage((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QgsUnitTypes::DistanceUnit(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 63: _t->selectionModeChanged((*reinterpret_cast< QgsMapToolSelect::Mode(*)>(_a[1]))); break;
        case 64: _t->refreshMapCanvas((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->refreshMapCanvas(); break;
        case 66: _t->updateMouseCoordinatePrecision(); break;
        case 67: { bool _r = _t->fileNew((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 68: { bool _r = _t->fileNew((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 69: _t->addCSVGraphLayer(); break;
        case 70: _t->showAllLayers(); break;
        case 71: _t->hideAllLayers(); break;
        case 72: _t->showSelectedLayers(); break;
        case 73: _t->hideSelectedLayers(); break;
        case 74: _t->toggleSelectedLayers(); break;
        case 75: _t->toggleSelectedLayersIndependently(); break;
        case 76: _t->hideDeselectedLayers(); break;
        case 77: _t->showFDEBDockWidget(); break;
        case 78: _t->showMINGLEDockWidget(); break;
        case 79: _t->showKDEEBDockWidget(); break;
        case 80: _t->onLocalWindowTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsVectorLayer* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QgsMapLayer*> >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsCoordinateReferenceSystem >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsCoordinateReferenceSystem >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 50:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QgsMapLayer* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphBundling::*)(QgsMapLayer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphBundling::activeLayerChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphBundling::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphBundling::connectionsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphBundling::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphBundling::newProject)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphBundling::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_GraphBundling.data,
    qt_meta_data_GraphBundling,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GraphBundling::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphBundling::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphBundling.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::GraphBundlingClass"))
        return static_cast< Ui::GraphBundlingClass*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int GraphBundling::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 81)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 81;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 81)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 81;
    }
    return _id;
}

// SIGNAL 0
void GraphBundling::activeLayerChanged(QgsMapLayer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphBundling::connectionsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void GraphBundling::newProject()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
