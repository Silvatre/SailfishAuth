/****************************************************************************
** Meta object code from reading C++ file 'account.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/account.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'account.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Account_t {
    QByteArrayData data[13];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Account_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Account_t qt_meta_stringdata_Account = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 11),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 13),
QT_MOC_LITERAL(4, 35, 14),
QT_MOC_LITERAL(5, 50, 16),
QT_MOC_LITERAL(6, 67, 10),
QT_MOC_LITERAL(7, 78, 4),
QT_MOC_LITERAL(8, 83, 4),
QT_MOC_LITERAL(9, 88, 6),
QT_MOC_LITERAL(10, 95, 7),
QT_MOC_LITERAL(11, 103, 9),
QT_MOC_LITERAL(12, 113, 3)
    },
    "Account\0nameChanged\0\0secretChanged\0"
    "counterChanged\0pinLengthChanged\0"
    "otpChanged\0next\0name\0secret\0counter\0"
    "pinLength\0otp\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Account[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,
       3,    0,   45,    2, 0x05,
       4,    0,   46,    2, 0x05,
       5,    0,   47,    2, 0x05,
       6,    0,   48,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    0,   49,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::ULongLong, 0x00495103,
      11, QMetaType::Int, 0x00495103,
      12, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Account::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Account *_t = static_cast<Account *>(_o);
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->secretChanged(); break;
        case 2: _t->counterChanged(); break;
        case 3: _t->pinLengthChanged(); break;
        case 4: _t->otpChanged(); break;
        case 5: _t->next(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::nameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::secretChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::counterChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::pinLengthChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::otpChanged)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Account::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Account.data,
      qt_meta_data_Account,  qt_static_metacall, 0, 0}
};


const QMetaObject *Account::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Account::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Account.stringdata))
        return static_cast<void*>(const_cast< Account*>(this));
    return QObject::qt_metacast(_clname);
}

int Account::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = secret(); break;
        case 2: *reinterpret_cast< quint64*>(_v) = counter(); break;
        case 3: *reinterpret_cast< int*>(_v) = pinLength(); break;
        case 4: *reinterpret_cast< QString*>(_v) = otp(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setSecret(*reinterpret_cast< QString*>(_v)); break;
        case 2: setCounter(*reinterpret_cast< quint64*>(_v)); break;
        case 3: setPinLength(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Account::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Account::secretChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Account::counterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Account::pinLengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Account::otpChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
