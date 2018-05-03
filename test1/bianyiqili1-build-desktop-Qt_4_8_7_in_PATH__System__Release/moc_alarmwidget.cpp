/****************************************************************************
** Meta object code from reading C++ file 'alarmwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/system_information/Alarm_Module1/alarmwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AlarmWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   13,   12,   12, 0x05,
      77,   70,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     107,   12,   12,   12, 0x08,
     138,   12,   12,   12, 0x08,
     166,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AlarmWidget[] = {
    "AlarmWidget\0\0alarm_information\0"
    "current_alarm_information_sig(QString)\0"
    "number\0current_alarm_number_sig(int)\0"
    "clear_alarm_information_slot()\0"
    "previous_page_information()\0"
    "next_page_information()\0"
};

void AlarmWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AlarmWidget *_t = static_cast<AlarmWidget *>(_o);
        switch (_id) {
        case 0: _t->current_alarm_information_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->current_alarm_number_sig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->clear_alarm_information_slot(); break;
        case 3: _t->previous_page_information(); break;
        case 4: _t->next_page_information(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AlarmWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AlarmWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AlarmWidget,
      qt_meta_data_AlarmWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AlarmWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AlarmWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AlarmWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmWidget))
        return static_cast<void*>(const_cast< AlarmWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AlarmWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AlarmWidget::current_alarm_information_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlarmWidget::current_alarm_number_sig(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
