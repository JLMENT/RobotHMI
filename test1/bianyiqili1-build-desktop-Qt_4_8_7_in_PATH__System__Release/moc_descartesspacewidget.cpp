/****************************************************************************
** Meta object code from reading C++ file 'descartesspacewidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/robot_setup/descartesspace/descartesspacewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'descartesspacewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DescartesSpaceWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      45,   21,   21,   21, 0x08,
      68,   21,   21,   21, 0x08,
      91,   21,   21,   21, 0x08,
     114,   21,   21,   21, 0x08,
     137,   21,   21,   21, 0x08,
     160,   21,   21,   21, 0x08,
     172,   21,   21,   21, 0x08,
     186,   21,   21,   21, 0x08,
     202,   21,   21,   21, 0x08,
     214,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DescartesSpaceWidget[] = {
    "DescartesSpaceWidget\0\0axis1_parameter_slot()\0"
    "axis2_parameter_slot()\0axis3_parameter_slot()\0"
    "axis4_parameter_slot()\0axis5_parameter_slot()\0"
    "axis6_parameter_slot()\0save_slot()\0"
    "pageup_slot()\0pagedown_slot()\0load_slot()\0"
    "remove_slot()\0"
};

void DescartesSpaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DescartesSpaceWidget *_t = static_cast<DescartesSpaceWidget *>(_o);
        switch (_id) {
        case 0: _t->axis1_parameter_slot(); break;
        case 1: _t->axis2_parameter_slot(); break;
        case 2: _t->axis3_parameter_slot(); break;
        case 3: _t->axis4_parameter_slot(); break;
        case 4: _t->axis5_parameter_slot(); break;
        case 5: _t->axis6_parameter_slot(); break;
        case 6: _t->save_slot(); break;
        case 7: _t->pageup_slot(); break;
        case 8: _t->pagedown_slot(); break;
        case 9: _t->load_slot(); break;
        case 10: _t->remove_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DescartesSpaceWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DescartesSpaceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DescartesSpaceWidget,
      qt_meta_data_DescartesSpaceWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DescartesSpaceWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DescartesSpaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DescartesSpaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DescartesSpaceWidget))
        return static_cast<void*>(const_cast< DescartesSpaceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DescartesSpaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
