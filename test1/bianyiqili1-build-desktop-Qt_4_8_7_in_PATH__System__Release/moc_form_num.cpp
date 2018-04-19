/****************************************************************************
** Meta object code from reading C++ file 'form_num.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/numeric_type_module/numwidget/form_num.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_num.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Form[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      21,    5,    5,    5, 0x08,
      38,    5,    5,    5, 0x08,
      57,    5,    5,    5, 0x08,
      77,    5,    5,    5, 0x08,
      95,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Form[] = {
    "Form\0\0up_page_slot()\0down_page_slot()\0"
    "left_change_slot()\0right_change_slot()\0"
    "save_value_slot()\0cancle_value_slot()\0"
};

void Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Form *_t = static_cast<Form *>(_o);
        switch (_id) {
        case 0: _t->up_page_slot(); break;
        case 1: _t->down_page_slot(); break;
        case 2: _t->left_change_slot(); break;
        case 3: _t->right_change_slot(); break;
        case 4: _t->save_value_slot(); break;
        case 5: _t->cancle_value_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Form::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Form,
      qt_meta_data_Form, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Form::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Form::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Form))
        return static_cast<void*>(const_cast< Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
