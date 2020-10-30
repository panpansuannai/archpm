/****************************************************************************
** Meta object code from reading C++ file 'pkg_info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "pkg_info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pkg_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pkg_info_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pkg_info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pkg_info_t qt_meta_stringdata_pkg_info = {
    {
QT_MOC_LITERAL(0, 0, 8), // "pkg_info"
QT_MOC_LITERAL(1, 9, 12), // "slot_install"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "slot_remove"
QT_MOC_LITERAL(4, 35, 10), // "slot_files"
QT_MOC_LITERAL(5, 46, 11), // "slot_detail"
QT_MOC_LITERAL(6, 58, 11), // "slot_depend"
QT_MOC_LITERAL(7, 70, 11), // "slot_c_deps"
QT_MOC_LITERAL(8, 82, 12), // "slot_c_files"
QT_MOC_LITERAL(9, 95, 13), // "slot_add_note"
QT_MOC_LITERAL(10, 109, 12) // "slot_newinfo"

    },
    "pkg_info\0slot_install\0\0slot_remove\0"
    "slot_files\0slot_detail\0slot_depend\0"
    "slot_c_deps\0slot_c_files\0slot_add_note\0"
    "slot_newinfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pkg_info[] = {

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
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void pkg_info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pkg_info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_install(); break;
        case 1: _t->slot_remove(); break;
        case 2: _t->slot_files(); break;
        case 3: _t->slot_detail(); break;
        case 4: _t->slot_depend(); break;
        case 5: _t->slot_c_deps(); break;
        case 6: _t->slot_c_files(); break;
        case 7: _t->slot_add_note(); break;
        case 8: _t->slot_newinfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pkg_info::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_pkg_info.data,
    qt_meta_data_pkg_info,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pkg_info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pkg_info::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pkg_info.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int pkg_info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
