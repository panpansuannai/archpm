/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[14];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainwindow"
QT_MOC_LITERAL(1, 11, 16), // "slot_main_search"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "slot_main_installed"
QT_MOC_LITERAL(4, 49, 19), // "slot_main_db_update"
QT_MOC_LITERAL(5, 69, 19), // "slot_main_configure"
QT_MOC_LITERAL(6, 89, 17), // "slot_main_orphans"
QT_MOC_LITERAL(7, 107, 19), // "slot_main_sysupdate"
QT_MOC_LITERAL(8, 127, 15), // "slot_main_about"
QT_MOC_LITERAL(9, 143, 16), // "slot_main_fixlck"
QT_MOC_LITERAL(10, 160, 16), // "slot_main_depend"
QT_MOC_LITERAL(11, 177, 18), // "slot_main_cleandis"
QT_MOC_LITERAL(12, 196, 16), // "slot_main_insall"
QT_MOC_LITERAL(13, 213, 15) // "slot_main_rmall"

    },
    "mainwindow\0slot_main_search\0\0"
    "slot_main_installed\0slot_main_db_update\0"
    "slot_main_configure\0slot_main_orphans\0"
    "slot_main_sysupdate\0slot_main_about\0"
    "slot_main_fixlck\0slot_main_depend\0"
    "slot_main_cleandis\0slot_main_insall\0"
    "slot_main_rmall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // slots: parameters
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
    QMetaType::Void,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_main_search(); break;
        case 1: _t->slot_main_installed(); break;
        case 2: _t->slot_main_db_update(); break;
        case 3: _t->slot_main_configure(); break;
        case 4: _t->slot_main_orphans(); break;
        case 5: _t->slot_main_sysupdate(); break;
        case 6: _t->slot_main_about(); break;
        case 7: _t->slot_main_fixlck(); break;
        case 8: _t->slot_main_depend(); break;
        case 9: _t->slot_main_cleandis(); break;
        case 10: _t->slot_main_insall(); break;
        case 11: _t->slot_main_rmall(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject mainwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_mainwindow.data,
    qt_meta_data_mainwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
