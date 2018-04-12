/****************************************************************************
** Meta object code from reading C++ file 'commandinput.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/commandinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommandInput[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,
      56,   13,   13,   13, 0x05,
      82,   13,   13,   13, 0x05,
     108,   13,   13,   13, 0x05,
     135,   13,   13,   13, 0x05,
     161,   13,   13,   13, 0x05,
     186,   13,   13,   13, 0x05,
     213,   13,   13,   13, 0x05,
     239,   13,   13,   13, 0x05,
     265,   13,   13,   13, 0x05,
     291,   13,   13,   13, 0x05,
     317,   13,   13,   13, 0x05,
     342,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     374,   13,   13,   13, 0x08,
     413,   13,   13,   13, 0x08,
     449,   13,   13,   13, 0x08,
     478,   13,   13,   13, 0x08,
     514,   13,   13,   13, 0x08,
     550,   13,   13,   13, 0x08,
     587,   13,   13,   13, 0x08,
     607,   13,   13,   13, 0x08,
     632,   13,   13,   13, 0x08,
     673,   13,   13,   13, 0x08,
     715,   13,   13,   13, 0x08,
     754,   13,   13,   13, 0x08,
     792,   13,   13,   13, 0x08,
     829,   13,   13,   13, 0x08,
     866,   13,   13,   13, 0x08,
     902,   13,   13,   13, 0x08,
     939,   13,   13,   13, 0x08,
     975,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CommandInput[] = {
    "CommandInput\0\0commandsig(int)\0"
    "movj_ensure_sig(QString*)\0"
    "movl_ensure_sig(QString*)\0"
    "movc_ensure_sig(QString*)\0"
    "speed_ensure_sig(QString*)\0"
    "dout_ensure_sig(QString*)\0"
    "din_ensure_sig(QString*)\0"
    "pause_ensure_sig(QString*)\0"
    "timer_ensure_sig(QString)\0"
    "jump_ensure_sig(QString*)\0"
    "label_ensure_sig(QString)\0"
    "call_ensure_sig(QString*)\0"
    "ret_ensure_sig(QString*)\0"
    "input_list_insert_sig(QString*)\0"
    "on_mojpositioneditpushButton_clicked()\0"
    "on_pushButton_movj_ensure_clicked()\0"
    "on_pushButton_TEST_clicked()\0"
    "on_pushButton_movl_ensure_pressed()\0"
    "on_pushButton_movc_ensure_pressed()\0"
    "on_pushButton_speed_ensure_pressed()\0"
    "input_insert_slot()\0refresh_posi_vari_slot()\0"
    "on_pushButton_movl_editpotiion_clicked()\0"
    "on_pushButton_movc_editposition_clicked()\0"
    "on_io_dout_ensure_pushButton_clicked()\0"
    "on_io_din_ensure_pushButton_clicked()\0"
    "on_pause_ensure_pushButton_clicked()\0"
    "on_timer_ensure_pushButton_clicked()\0"
    "on_jump_ensure_pushButton_clicked()\0"
    "on_label_ensure_pushButton_clicked()\0"
    "on_call_ensure_pushButton_clicked()\0"
    "on_ret_ensure_pushButton_clicked()\0"
};

void CommandInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommandInput *_t = static_cast<CommandInput *>(_o);
        switch (_id) {
        case 0: _t->commandsig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->movj_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 2: _t->movl_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 3: _t->movc_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 4: _t->speed_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 5: _t->dout_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 6: _t->din_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 7: _t->pause_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 8: _t->timer_ensure_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->jump_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 10: _t->label_ensure_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->call_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 12: _t->ret_ensure_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 13: _t->input_list_insert_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 14: _t->on_mojpositioneditpushButton_clicked(); break;
        case 15: _t->on_pushButton_movj_ensure_clicked(); break;
        case 16: _t->on_pushButton_TEST_clicked(); break;
        case 17: _t->on_pushButton_movl_ensure_pressed(); break;
        case 18: _t->on_pushButton_movc_ensure_pressed(); break;
        case 19: _t->on_pushButton_speed_ensure_pressed(); break;
        case 20: _t->input_insert_slot(); break;
        case 21: _t->refresh_posi_vari_slot(); break;
        case 22: _t->on_pushButton_movl_editpotiion_clicked(); break;
        case 23: _t->on_pushButton_movc_editposition_clicked(); break;
        case 24: _t->on_io_dout_ensure_pushButton_clicked(); break;
        case 25: _t->on_io_din_ensure_pushButton_clicked(); break;
        case 26: _t->on_pause_ensure_pushButton_clicked(); break;
        case 27: _t->on_timer_ensure_pushButton_clicked(); break;
        case 28: _t->on_jump_ensure_pushButton_clicked(); break;
        case 29: _t->on_label_ensure_pushButton_clicked(); break;
        case 30: _t->on_call_ensure_pushButton_clicked(); break;
        case 31: _t->on_ret_ensure_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommandInput::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommandInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CommandInput,
      qt_meta_data_CommandInput, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommandInput::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommandInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommandInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommandInput))
        return static_cast<void*>(const_cast< CommandInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int CommandInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void CommandInput::commandsig(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandInput::movj_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandInput::movl_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandInput::movc_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommandInput::speed_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommandInput::dout_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommandInput::din_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CommandInput::pause_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CommandInput::timer_ensure_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CommandInput::jump_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CommandInput::label_ensure_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CommandInput::call_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CommandInput::ret_ensure_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CommandInput::input_list_insert_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
