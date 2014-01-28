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
    QByteArrayData data[18];
    char stringdata[187];
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
QT_MOC_LITERAL(7, 78, 9),
QT_MOC_LITERAL(8, 88, 15),
QT_MOC_LITERAL(9, 104, 4),
QT_MOC_LITERAL(10, 109, 18),
QT_MOC_LITERAL(11, 128, 4),
QT_MOC_LITERAL(12, 133, 6),
QT_MOC_LITERAL(13, 140, 7),
QT_MOC_LITERAL(14, 148, 9),
QT_MOC_LITERAL(15, 158, 8),
QT_MOC_LITERAL(16, 167, 3),
QT_MOC_LITERAL(17, 171, 14)
    },
    "Account\0nameChanged\0\0secretChanged\0"
    "counterChanged\0pinLengthChanged\0"
    "otpChanged\0tcChanged\0timeStepChanged\0"
    "next\0getTimeToNextBlock\0name\0secret\0"
    "counter\0pinLength\0timeStep\0otp\0"
    "timeControlled\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Account[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       7,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    0,   60,    2, 0x05,
       4,    0,   61,    2, 0x05,
       5,    0,   62,    2, 0x05,
       6,    0,   63,    2, 0x05,
       7,    0,   64,    2, 0x05,
       8,    0,   65,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    0,   66,    2, 0x0a,
      10,    0,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Double,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::ULongLong, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       6,
       4,
       5,

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
        case 5: _t->tcChanged(); break;
        case 6: _t->timeStepChanged(); break;
        case 7: _t->next(); break;
        case 8: { double _r = _t->getTimeToNextBlock();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
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
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::tcChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (Account::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Account::timeStepChanged)) {
                *result = 6;
            }
        }
    }
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = secret(); break;
        case 2: *reinterpret_cast< quint64*>(_v) = counter(); break;
        case 3: *reinterpret_cast< int*>(_v) = pinLength(); break;
        case 4: *reinterpret_cast< int*>(_v) = timeStep(); break;
        case 5: *reinterpret_cast< QString*>(_v) = otp(); break;
        case 6: *reinterpret_cast< bool*>(_v) = timeControlled(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setSecret(*reinterpret_cast< QString*>(_v)); break;
        case 2: setCounter(*reinterpret_cast< quint64*>(_v)); break;
        case 3: setPinLength(*reinterpret_cast< int*>(_v)); break;
        case 4: setTimeStep(*reinterpret_cast< int*>(_v)); break;
        case 6: setTimeControlled(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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

// SIGNAL 5
void Account::tcChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Account::timeStepChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
