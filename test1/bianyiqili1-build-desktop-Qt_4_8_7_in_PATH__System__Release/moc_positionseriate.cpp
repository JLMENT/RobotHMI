/****************************************************************************
** Meta object code from reading C++ file 'positionseriate.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/positionseriate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'positionseriate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PositionSeriate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   16,   16,   16, 0x08,
      78,   16,   16,   16, 0x08,
     118,   16,   16,   16, 0x08,
     151,   16,   16,   16, 0x08,
     178,   16,   16,   16, 0x08,
     224,   16,   16,   16, 0x08,
     272,  266,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PositionSeriate[] = {
    "PositionSeriate\0\0refresh_posi_vari_sig()\0"
    "on_pushButton_new_position_clicked()\0"
    "on_pushButton_select_position_clicked()\0"
    "on_pushButton_pos_save_clicked()\0"
    "refresh_current_position()\0"
    "on_pushButton_setpu_currentposition_clicked()\0"
    "on_pushButton_posi_variate_data_clicked()\0"
    "index\0on_comboBox_cu_co_select_currentIndexChanged(int)\0"
};

void PositionSeriate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PositionSeriate *_t = static_cast<PositionSeriate *>(_o);
        switch (_id) {
        case 0: _t->refresh_posi_vari_sig(); break;
        case 1: _t->on_pushButton_new_position_clicked(); break;
        case 2: _t->on_pushButton_select_position_clicked(); break;
        case 3: _t->on_pushButton_pos_save_clicked(); break;
        case 4: _t->refresh_current_position(); break;
        case 5: _t->on_pushButton_setpu_currentposition_clicked(); break;
        case 6: _t->on_pushButton_posi_variate_data_clicked(); break;
        case 7: _t->on_comboBox_cu_co_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PositionSeriate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PositionSeriate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PositionSeriate,
      qt_meta_data_PositionSeriate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PositionSeriate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PositionSeriate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PositionSeriate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PositionSeriate))
        return static_cast<void*>(const_cast< PositionSeriate*>(this));
    return QWidget::qt_metacast(_clname);
}

int PositionSeriate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PositionSeriate::refresh_posi_vari_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
