/****************************************************************************
** Meta object code from reading C++ file 'LayerTreeViewMenuProvider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../LayerTreeViewMenuProvider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerTreeViewMenuProvider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LayerTreeViewMenuProvider_t {
    QByteArrayData data[9];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerTreeViewMenuProvider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerTreeViewMenuProvider_t qt_meta_stringdata_LayerTreeViewMenuProvider = {
    {
QT_MOC_LITERAL(0, 0, 25), // "LayerTreeViewMenuProvider"
QT_MOC_LITERAL(1, 26, 24), // "setSymbolLegendNodeColor"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "color"
QT_MOC_LITERAL(4, 58, 26), // "editSymbolLegendNodeSymbol"
QT_MOC_LITERAL(5, 85, 7), // "layerId"
QT_MOC_LITERAL(6, 93, 7), // "ruleKey"
QT_MOC_LITERAL(7, 101, 26), // "copySymbolLegendNodeSymbol"
QT_MOC_LITERAL(8, 128, 27) // "pasteSymbolLegendNodeSymbol"

    },
    "LayerTreeViewMenuProvider\0"
    "setSymbolLegendNodeColor\0\0color\0"
    "editSymbolLegendNodeSymbol\0layerId\0"
    "ruleKey\0copySymbolLegendNodeSymbol\0"
    "pasteSymbolLegendNodeSymbol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerTreeViewMenuProvider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    2,   37,    2, 0x08 /* Private */,
       7,    2,   42,    2, 0x08 /* Private */,
       8,    2,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,

       0        // eod
};

void LayerTreeViewMenuProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LayerTreeViewMenuProvider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSymbolLegendNodeColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->editSymbolLegendNodeSymbol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->copySymbolLegendNodeSymbol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->pasteSymbolLegendNodeSymbol((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LayerTreeViewMenuProvider::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_LayerTreeViewMenuProvider.data,
    qt_meta_data_LayerTreeViewMenuProvider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LayerTreeViewMenuProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerTreeViewMenuProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LayerTreeViewMenuProvider.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QgsLayerTreeViewMenuProvider"))
        return static_cast< QgsLayerTreeViewMenuProvider*>(this);
    return QObject::qt_metacast(_clname);
}

int LayerTreeViewMenuProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
