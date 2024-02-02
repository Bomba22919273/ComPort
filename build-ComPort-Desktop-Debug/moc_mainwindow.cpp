/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ComPort/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "wheelEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QWheelEvent*"
QT_MOC_LITERAL(4, 36, 5), // "event"
QT_MOC_LITERAL(5, 42, 13), // "keyPressEvent"
QT_MOC_LITERAL(6, 56, 10), // "QKeyEvent*"
QT_MOC_LITERAL(7, 67, 14), // "updateDateTime"
QT_MOC_LITERAL(8, 82, 11), // "draw_axis_X"
QT_MOC_LITERAL(9, 94, 11), // "draw_axis_Y"
QT_MOC_LITERAL(10, 106, 9), // "clearAxis"
QT_MOC_LITERAL(11, 116, 10), // "initDraw_X"
QT_MOC_LITERAL(12, 127, 10), // "initDraw_Y"
QT_MOC_LITERAL(13, 138, 11), // "initDraw_XY"
QT_MOC_LITERAL(14, 150, 14), // "receiveMessage"
QT_MOC_LITERAL(15, 165, 24), // "on_RefreshButton_clicked"
QT_MOC_LITERAL(16, 190, 24), // "on_ConnectButton_clicked"
QT_MOC_LITERAL(17, 215, 27), // "on_DisconnectButton_clicked"
QT_MOC_LITERAL(18, 243, 22), // "on_ClearButton_clicked"
QT_MOC_LITERAL(19, 266, 21), // "on_StopButton_clicked"
QT_MOC_LITERAL(20, 288, 8) // "clear_XY"

    },
    "MainWindow\0wheelEvent\0\0QWheelEvent*\0"
    "event\0keyPressEvent\0QKeyEvent*\0"
    "updateDateTime\0draw_axis_X\0draw_axis_Y\0"
    "clearAxis\0initDraw_X\0initDraw_Y\0"
    "initDraw_XY\0receiveMessage\0"
    "on_RefreshButton_clicked\0"
    "on_ConnectButton_clicked\0"
    "on_DisconnectButton_clicked\0"
    "on_ClearButton_clicked\0on_StopButton_clicked\0"
    "clear_XY"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       5,    1,   97,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    0,  109,    2, 0x08 /* Private */,
      17,    0,  110,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x08 /* Private */,
      19,    0,  112,    2, 0x08 /* Private */,
      20,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->updateDateTime(); break;
        case 3: _t->draw_axis_X(); break;
        case 4: _t->draw_axis_Y(); break;
        case 5: _t->clearAxis(); break;
        case 6: _t->initDraw_X(); break;
        case 7: _t->initDraw_Y(); break;
        case 8: _t->initDraw_XY(); break;
        case 9: _t->receiveMessage(); break;
        case 10: _t->on_RefreshButton_clicked(); break;
        case 11: _t->on_ConnectButton_clicked(); break;
        case 12: _t->on_DisconnectButton_clicked(); break;
        case 13: _t->on_ClearButton_clicked(); break;
        case 14: _t->on_StopButton_clicked(); break;
        case 15: _t->clear_XY(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
