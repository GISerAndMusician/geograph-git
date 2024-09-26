/****************************************************************************
** Meta object code from reading C++ file 'GgsGraphLegendWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gui/GgsGraphLegendWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GgsGraphLegendWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GgsGraphLegendWidget_t {
    QByteArrayData data[12];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsGraphLegendWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsGraphLegendWidget_t qt_meta_stringdata_GgsGraphLegendWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "GgsGraphLegendWidget"
QT_MOC_LITERAL(1, 21, 17), // "onGraphLayerAdded"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "GgsGraphProxy*"
QT_MOC_LITERAL(4, 55, 5), // "graph"
QT_MOC_LITERAL(5, 61, 13), // "onItemChanged"
QT_MOC_LITERAL(6, 75, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 92, 4), // "item"
QT_MOC_LITERAL(8, 97, 22), // "onItemSelectionChanged"
QT_MOC_LITERAL(9, 120, 16), // "onLinkageClicked"
QT_MOC_LITERAL(10, 137, 8), // "bChecked"
QT_MOC_LITERAL(11, 146, 15) // "onRemoveClicked"

    },
    "GgsGraphLegendWidget\0onGraphLayerAdded\0"
    "\0GgsGraphProxy*\0graph\0onItemChanged\0"
    "QListWidgetItem*\0item\0onItemSelectionChanged\0"
    "onLinkageClicked\0bChecked\0onRemoveClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsGraphLegendWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,
       9,    1,   46,    2, 0x08 /* Private */,
      11,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void GgsGraphLegendWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsGraphLegendWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onGraphLayerAdded((*reinterpret_cast< GgsGraphProxy*(*)>(_a[1]))); break;
        case 1: _t->onItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->onItemSelectionChanged(); break;
        case 3: _t->onLinkageClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onRemoveClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GgsGraphLegendWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GgsGraphLegendWidget.data,
    qt_meta_data_GgsGraphLegendWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsGraphLegendWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsGraphLegendWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsGraphLegendWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::GgsGraphLegendWidget"))
        return static_cast< Ui::GgsGraphLegendWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int GgsGraphLegendWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
