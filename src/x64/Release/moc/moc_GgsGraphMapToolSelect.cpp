/****************************************************************************
** Meta object code from reading C++ file 'GgsGraphMapToolSelect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GgsGraphMapToolSelect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GgsGraphMapToolSelect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GgsGraphMapToolSelect_t {
    QByteArrayData data[12];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsGraphMapToolSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsGraphMapToolSelect_t qt_meta_stringdata_GgsGraphMapToolSelect = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GgsGraphMapToolSelect"
QT_MOC_LITERAL(1, 22, 11), // "modeChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 4), // "Mode"
QT_MOC_LITERAL(4, 40, 4), // "mode"
QT_MOC_LITERAL(5, 45, 28), // "graphFeatureSelectionChanged"
QT_MOC_LITERAL(6, 74, 14), // "GgsGraphProxy*"
QT_MOC_LITERAL(7, 89, 1), // "g"
QT_MOC_LITERAL(8, 91, 19), // "selectGraphFeatures"
QT_MOC_LITERAL(9, 111, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(10, 133, 9), // "modifiers"
QT_MOC_LITERAL(11, 143, 14) // "selectFeatures"

    },
    "GgsGraphMapToolSelect\0modeChanged\0\0"
    "Mode\0mode\0graphFeatureSelectionChanged\0"
    "GgsGraphProxy*\0g\0selectGraphFeatures\0"
    "Qt::KeyboardModifiers\0modifiers\0"
    "selectFeatures"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsGraphMapToolSelect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x08 /* Private */,
      11,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void GgsGraphMapToolSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsGraphMapToolSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modeChanged((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 1: _t->graphFeatureSelectionChanged((*reinterpret_cast< GgsGraphProxy*(*)>(_a[1]))); break;
        case 2: _t->selectGraphFeatures((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 3: _t->selectFeatures((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GgsGraphMapToolSelect::*)(Mode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphMapToolSelect::modeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GgsGraphMapToolSelect::*)(GgsGraphProxy * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphMapToolSelect::graphFeatureSelectionChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GgsGraphMapToolSelect::staticMetaObject = { {
    &QgsMapTool::staticMetaObject,
    qt_meta_stringdata_GgsGraphMapToolSelect.data,
    qt_meta_data_GgsGraphMapToolSelect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsGraphMapToolSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsGraphMapToolSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsGraphMapToolSelect.stringdata0))
        return static_cast<void*>(this);
    return QgsMapTool::qt_metacast(_clname);
}

int GgsGraphMapToolSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsMapTool::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GgsGraphMapToolSelect::modeChanged(Mode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GgsGraphMapToolSelect::graphFeatureSelectionChanged(GgsGraphProxy * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
