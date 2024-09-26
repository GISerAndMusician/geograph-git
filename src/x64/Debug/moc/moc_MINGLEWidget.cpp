/****************************************************************************
** Meta object code from reading C++ file 'MINGLEWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../algo/MINGLE/MINGLEWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MINGLEWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MINGLEWidget_t {
    QByteArrayData data[19];
    char stringdata0[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MINGLEWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MINGLEWidget_t qt_meta_stringdata_MINGLEWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MINGLEWidget"
QT_MOC_LITERAL(1, 13, 18), // "refreshGraphProxys"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "GraphProxy*"
QT_MOC_LITERAL(4, 45, 10), // "graphProxy"
QT_MOC_LITERAL(5, 56, 3), // "run"
QT_MOC_LITERAL(6, 60, 17), // "onProgressChanged"
QT_MOC_LITERAL(7, 78, 4), // "iter"
QT_MOC_LITERAL(8, 83, 7), // "current"
QT_MOC_LITERAL(9, 91, 5), // "total"
QT_MOC_LITERAL(10, 97, 21), // "onCurrentProxyChanged"
QT_MOC_LITERAL(11, 119, 5), // "index"
QT_MOC_LITERAL(12, 125, 12), // "toggleMargin"
QT_MOC_LITERAL(13, 138, 10), // "checkState"
QT_MOC_LITERAL(14, 149, 17), // "updateDeltaUiText"
QT_MOC_LITERAL(15, 167, 5), // "value"
QT_MOC_LITERAL(16, 173, 21), // "updateCurvenessUiText"
QT_MOC_LITERAL(17, 195, 17), // "updateAlphaUiText"
QT_MOC_LITERAL(18, 213, 11) // "toggleLoose"

    },
    "MINGLEWidget\0refreshGraphProxys\0\0"
    "GraphProxy*\0graphProxy\0run\0onProgressChanged\0"
    "iter\0current\0total\0onCurrentProxyChanged\0"
    "index\0toggleMargin\0checkState\0"
    "updateDeltaUiText\0value\0updateCurvenessUiText\0"
    "updateAlphaUiText\0toggleLoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MINGLEWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    3,   63,    2, 0x08 /* Private */,
      10,    1,   70,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,
      14,    1,   76,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x08 /* Private */,
      17,    1,   82,    2, 0x08 /* Private */,
      18,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void MINGLEWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MINGLEWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshGraphProxys((*reinterpret_cast< GraphProxy*(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->onProgressChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->onCurrentProxyChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->toggleMargin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateDeltaUiText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateCurvenessUiText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateAlphaUiText((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleLoose((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GraphProxy* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MINGLEWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MINGLEWidget.data,
    qt_meta_data_MINGLEWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MINGLEWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MINGLEWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MINGLEWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::GgsMingleWidget"))
        return static_cast< Ui::GgsMingleWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int MINGLEWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
