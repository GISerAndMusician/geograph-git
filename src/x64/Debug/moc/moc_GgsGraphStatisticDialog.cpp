/****************************************************************************
** Meta object code from reading C++ file 'GgsGraphStatisticDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../statistic/GgsGraphStatisticDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GgsGraphStatisticDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GgsGraphStatisticDialog_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsGraphStatisticDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsGraphStatisticDialog_t qt_meta_stringdata_GgsGraphStatisticDialog = {
    {
QT_MOC_LITERAL(0, 0, 23), // "GgsGraphStatisticDialog"
QT_MOC_LITERAL(1, 24, 7), // "onColor"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4) // "onOK"

    },
    "GgsGraphStatisticDialog\0onColor\0\0onOK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsGraphStatisticDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GgsGraphStatisticDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsGraphStatisticDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onColor(); break;
        case 1: _t->onOK(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GgsGraphStatisticDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_GgsGraphStatisticDialog.data,
    qt_meta_data_GgsGraphStatisticDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsGraphStatisticDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsGraphStatisticDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsGraphStatisticDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::GraphStatisticDialog"))
        return static_cast< Ui::GraphStatisticDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int GgsGraphStatisticDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
