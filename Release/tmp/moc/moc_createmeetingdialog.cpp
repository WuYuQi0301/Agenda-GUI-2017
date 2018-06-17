/****************************************************************************
** Meta object code from reading C++ file 'createmeetingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/ui_/createmeetingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createmeetingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateMeetingDialog_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateMeetingDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateMeetingDialog_t qt_meta_stringdata_CreateMeetingDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CreateMeetingDialog"
QT_MOC_LITERAL(1, 20, 11), // "meetingInfo"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 6), // "string"
QT_MOC_LITERAL(4, 40, 14), // "vector<string>"
QT_MOC_LITERAL(5, 55, 3), // "row"
QT_MOC_LITERAL(6, 59, 8), // "showMenu"
QT_MOC_LITERAL(7, 68, 24), // "on_comfirmButton_clicked"
QT_MOC_LITERAL(8, 93, 23) // "on_returnButton_clicked"

    },
    "CreateMeetingDialog\0meetingInfo\0\0"
    "string\0vector<string>\0row\0showMenu\0"
    "on_comfirmButton_clicked\0"
    "on_returnButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateMeetingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 4,    2,    2,    2,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateMeetingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateMeetingDialog *_t = static_cast<CreateMeetingDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->meetingInfo((*reinterpret_cast< const string(*)>(_a[1])),(*reinterpret_cast< const string(*)>(_a[2])),(*reinterpret_cast< const string(*)>(_a[3])),(*reinterpret_cast< const vector<string>(*)>(_a[4]))); break;
        case 1: _t->showMenu(); break;
        case 2: _t->on_comfirmButton_clicked(); break;
        case 3: _t->on_returnButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CreateMeetingDialog::*_t)(const string , const string , const string , const vector<string> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateMeetingDialog::meetingInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CreateMeetingDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CreateMeetingDialog::showMenu)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CreateMeetingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreateMeetingDialog.data,
      qt_meta_data_CreateMeetingDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateMeetingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateMeetingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateMeetingDialog.stringdata0))
        return static_cast<void*>(const_cast< CreateMeetingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreateMeetingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void CreateMeetingDialog::meetingInfo(const string _t1, const string _t2, const string _t3, const vector<string> _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateMeetingDialog::showMenu()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
