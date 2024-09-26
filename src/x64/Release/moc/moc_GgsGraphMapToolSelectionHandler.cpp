/****************************************************************************
** Meta object code from reading C++ file 'GgsGraphMapToolSelectionHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GgsGraphMapToolSelectionHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GgsGraphMapToolSelectionHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GgsGraphDistanceWidget_t {
    QByteArrayData data[8];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsGraphDistanceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsGraphDistanceWidget_t qt_meta_stringdata_GgsGraphDistanceWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GgsGraphDistanceWidget"
QT_MOC_LITERAL(1, 23, 15), // "distanceChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 8), // "distance"
QT_MOC_LITERAL(4, 49, 23), // "distanceEditingFinished"
QT_MOC_LITERAL(5, 73, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(6, 95, 9), // "modifiers"
QT_MOC_LITERAL(7, 105, 23) // "distanceEditingCanceled"

    },
    "GgsGraphDistanceWidget\0distanceChanged\0"
    "\0distance\0distanceEditingFinished\0"
    "Qt::KeyboardModifiers\0modifiers\0"
    "distanceEditingCanceled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsGraphDistanceWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    2,   32,    2, 0x06 /* Public */,
       7,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 5,    3,    6,
    QMetaType::Void,

       0        // eod
};

void GgsGraphDistanceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsGraphDistanceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->distanceChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->distanceEditingFinished((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< const Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 2: _t->distanceEditingCanceled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GgsGraphDistanceWidget::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphDistanceWidget::distanceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GgsGraphDistanceWidget::*)(double , const Qt::KeyboardModifiers & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphDistanceWidget::distanceEditingFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GgsGraphDistanceWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphDistanceWidget::distanceEditingCanceled)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GgsGraphDistanceWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GgsGraphDistanceWidget.data,
    qt_meta_data_GgsGraphDistanceWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsGraphDistanceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsGraphDistanceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsGraphDistanceWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GgsGraphDistanceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GgsGraphDistanceWidget::distanceChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GgsGraphDistanceWidget::distanceEditingFinished(double _t1, const Qt::KeyboardModifiers & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GgsGraphDistanceWidget::distanceEditingCanceled()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_GgsGraphMapToolSelectionHandler_t {
    QByteArrayData data[9];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsGraphMapToolSelectionHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsGraphMapToolSelectionHandler_t qt_meta_stringdata_GgsGraphMapToolSelectionHandler = {
    {
QT_MOC_LITERAL(0, 0, 31), // "GgsGraphMapToolSelectionHandler"
QT_MOC_LITERAL(1, 32, 15), // "geometryChanged"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 21), // "Qt::KeyboardModifiers"
QT_MOC_LITERAL(4, 71, 9), // "modifiers"
QT_MOC_LITERAL(5, 81, 6), // "cancel"
QT_MOC_LITERAL(6, 88, 22), // "updateRadiusRubberband"
QT_MOC_LITERAL(7, 111, 6), // "radius"
QT_MOC_LITERAL(8, 118, 18) // "radiusValueEntered"

    },
    "GgsGraphMapToolSelectionHandler\0"
    "geometryChanged\0\0Qt::KeyboardModifiers\0"
    "modifiers\0cancel\0updateRadiusRubberband\0"
    "radius\0radiusValueEntered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsGraphMapToolSelectionHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    0,   42,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    2,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 3,    7,    4,

       0        // eod
};

void GgsGraphMapToolSelectionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsGraphMapToolSelectionHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->geometryChanged((*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[1]))); break;
        case 1: _t->geometryChanged(); break;
        case 2: _t->cancel(); break;
        case 3: _t->updateRadiusRubberband((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->radiusValueEntered((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GgsGraphMapToolSelectionHandler::*)(Qt::KeyboardModifiers );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GgsGraphMapToolSelectionHandler::geometryChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GgsGraphMapToolSelectionHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GgsGraphMapToolSelectionHandler.data,
    qt_meta_data_GgsGraphMapToolSelectionHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsGraphMapToolSelectionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsGraphMapToolSelectionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsGraphMapToolSelectionHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GgsGraphMapToolSelectionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GgsGraphMapToolSelectionHandler::geometryChanged(Qt::KeyboardModifiers _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
