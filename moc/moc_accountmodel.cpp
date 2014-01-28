/****************************************************************************
** Meta object code from reading C++ file 'accountmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/accountmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountModel_t {
    QByteArrayData data[14];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountModel_t qt_meta_stringdata_AccountModel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 12),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 7),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 7),
QT_MOC_LITERAL(6, 55, 5),
QT_MOC_LITERAL(7, 61, 16),
QT_MOC_LITERAL(8, 78, 14),
QT_MOC_LITERAL(9, 93, 12),
QT_MOC_LITERAL(10, 106, 8),
QT_MOC_LITERAL(11, 115, 3),
QT_MOC_LITERAL(12, 119, 13),
QT_MOC_LITERAL(13, 133, 13)
    },
    "AccountModel\0generateNext\0\0account\0"
    "generateAll\0refresh\0index\0isTimeControlled\0"
    "accountChanged\0storeAccount\0Account*\0"
    "get\0createAccount\0deleteAccount\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a,
       4,    0,   72,    2, 0x0a,
       5,    0,   73,    2, 0x0a,
       5,    1,   74,    2, 0x0a,
       7,    1,   77,    2, 0x0a,
       8,    0,   80,    2, 0x08,
       9,    1,   81,    2, 0x08,

 // methods: name, argc, parameters, tag, flags
      11,    1,   84,    2, 0x02,
      12,    0,   87,    2, 0x02,
      13,    1,   88,    2, 0x02,
      13,    1,   91,    2, 0x02,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,    3,

 // methods: parameters
    0x80000000 | 10, QMetaType::Int,    6,
    0x80000000 | 10,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 10,    3,

       0        // eod
};

void AccountModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountModel *_t = static_cast<AccountModel *>(_o);
        switch (_id) {
        case 0: _t->generateNext((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->generateAll(); break;
        case 2: _t->refresh(); break;
        case 3: _t->refresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isTimeControlled((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->accountChanged(); break;
        case 6: _t->storeAccount((*reinterpret_cast< Account*(*)>(_a[1]))); break;
        case 7: { Account* _r = _t->get((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Account**>(_a[0]) = _r; }  break;
        case 8: { Account* _r = _t->createAccount();
            if (_a[0]) *reinterpret_cast< Account**>(_a[0]) = _r; }  break;
        case 9: _t->deleteAccount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->deleteAccount((*reinterpret_cast< Account*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AccountModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_AccountModel.data,
      qt_meta_data_AccountModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountModel.stringdata))
        return static_cast<void*>(const_cast< AccountModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int AccountModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
