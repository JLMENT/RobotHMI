/****************************************************************************
** Meta object code from reading C++ file 'dhspaceparem.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/robot_setup/DHSpace/dhspaceparem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dhspaceparem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DHSpaceParem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      23,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DHSpaceParem[] = {
    "DHSpaceParem\0\0dhsave()\0dhadd()\0"
};

void DHSpaceParem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DHSpaceParem *_t = static_cast<DHSpaceParem *>(_o);
        switch (_id) {
        case 0: _t->dhsave(); break;
        case 1: _t->dhadd(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DHSpaceParem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DHSpaceParem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DHSpaceParem,
      qt_meta_data_DHSpaceParem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DHSpaceParem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DHSpaceParem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DHSpaceParem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DHSpaceParem))
        return static_cast<void*>(const_cast< DHSpaceParem*>(this));
    return QWidget::qt_metacast(_clname);
}

int DHSpaceParem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
