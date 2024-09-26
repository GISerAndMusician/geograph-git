/****************************************************************************
** Meta object code from reading C++ file 'KDEEBWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../algo/KDEEB/KDEEBWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDEEBWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KDEEBWidget_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDEEBWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDEEBWidget_t qt_meta_stringdata_KDEEBWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "KDEEBWidget"
QT_MOC_LITERAL(1, 12, 18), // "refreshGraphProxys"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "GraphProxy*"
QT_MOC_LITERAL(4, 44, 10), // "graphProxy"
QT_MOC_LITERAL(5, 55, 3), // "run"
QT_MOC_LITERAL(6, 59, 14), // "updateProgress"
QT_MOC_LITERAL(7, 74, 7), // "current"
QT_MOC_LITERAL(8, 82, 5) // "total"

    },
    "KDEEBWidget\0refreshGraphProxys\0\0"
    "GraphProxy*\0graphProxy\0run\0updateProgress\0"
    "current\0total"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDEEBWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x08 /* Private */,
       6,    2,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void KDEEBWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KDEEBWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshGraphProxys((*reinterpret_cast< GraphProxy*(*)>(_a[1]))); break;
        case 1: _t->run(); break;
        case 2: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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

QT_INIT_METAOBJECT const QMetaObject KDEEBWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_KDEEBWidget.data,
    qt_meta_data_KDEEBWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KDEEBWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDEEBWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KDEEBWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::KDEEBWidget"))
        return static_cast< Ui::KDEEBWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int KDEEBWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
