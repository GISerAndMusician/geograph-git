/****************************************************************************
** Meta object code from reading C++ file 'GgsMapThemes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GgsMapThemes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GgsMapThemes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GgsMapThemes_t {
    QByteArrayData data[9];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GgsMapThemes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GgsMapThemes_t qt_meta_stringdata_GgsMapThemes = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GgsMapThemes"
QT_MOC_LITERAL(1, 13, 9), // "addPreset"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "presetTriggered"
QT_MOC_LITERAL(4, 40, 16), // "replaceTriggered"
QT_MOC_LITERAL(5, 57, 19), // "removeCurrentPreset"
QT_MOC_LITERAL(6, 77, 19), // "renameCurrentPreset"
QT_MOC_LITERAL(7, 97, 15), // "menuAboutToShow"
QT_MOC_LITERAL(8, 113, 8) // "showHelp"

    },
    "GgsMapThemes\0addPreset\0\0presetTriggered\0"
    "replaceTriggered\0removeCurrentPreset\0"
    "renameCurrentPreset\0menuAboutToShow\0"
    "showHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GgsMapThemes[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x09 /* Protected */,
       3,    0,   50,    2, 0x09 /* Protected */,
       4,    0,   51,    2, 0x09 /* Protected */,
       5,    0,   52,    2, 0x09 /* Protected */,
       6,    0,   53,    2, 0x09 /* Protected */,
       7,    0,   54,    2, 0x09 /* Protected */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GgsMapThemes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GgsMapThemes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addPreset(); break;
        case 1: _t->presetTriggered(); break;
        case 2: _t->replaceTriggered(); break;
        case 3: _t->removeCurrentPreset(); break;
        case 4: _t->renameCurrentPreset(); break;
        case 5: _t->menuAboutToShow(); break;
        case 6: _t->showHelp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GgsMapThemes::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_GgsMapThemes.data,
    qt_meta_data_GgsMapThemes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GgsMapThemes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GgsMapThemes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GgsMapThemes.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GgsMapThemes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
