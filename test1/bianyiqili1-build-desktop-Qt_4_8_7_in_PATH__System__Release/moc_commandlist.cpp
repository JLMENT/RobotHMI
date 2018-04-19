/****************************************************************************
** Meta object code from reading C++ file 'commandlist.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/commandlist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommandList[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      24,   12,   12,   12, 0x05,
      48,   12,   12,   12, 0x05,
      79,   12,   12,   12, 0x05,
     110,   12,   12,   12, 0x05,
     141,   12,   12,   12, 0x05,
     173,   12,   12,   12, 0x05,
     204,   12,   12,   12, 0x05,
     234,   12,   12,   12, 0x05,
     266,   12,   12,   12, 0x05,
     297,   12,   12,   12, 0x05,
     328,   12,   12,   12, 0x05,
     359,   12,   12,   12, 0x05,
     390,   12,   12,   12, 0x05,
     420,   12,   12,   12, 0x05,
     438,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     469,   12,   12,   12, 0x08,
     483,   12,   12,   12, 0x08,
     497,   12,   12,   12, 0x08,
     511,   12,   12,   12, 0x08,
     525,   12,   12,   12, 0x08,
     540,   12,   12,   12, 0x08,
     555,   12,   12,   12, 0x08,
     569,   12,   12,   12, 0x08,
     583,   12,   12,   12, 0x08,
     596,   12,   12,   12, 0x08,
     610,   12,   12,   12, 0x08,
     623,   12,   12,   12, 0x08,
     640,   12,   12,   12, 0x08,
     657,   12,   12,   12, 0x08,
     671,   12,   12,   12, 0x08,
     686,   12,   12,   12, 0x08,
     700,   12,   12,   12, 0x08,
     713,   12,   12,   12, 0x08,
     728,   12,   12,   12, 0x08,
     743,   12,   12,   12, 0x08,
     758,   12,   12,   12, 0x08,
     771,   12,   12,   12, 0x08,
     784,   12,   12,   12, 0x08,
     797,   12,   12,   12, 0x08,
     810,   12,   12,   12, 0x08,
     823,   12,   12,   12, 0x08,
     836,   12,   12,   12, 0x08,
     849,   12,   12,   12, 0x08,
     861,   12,   12,   12, 0x08,
     874,   12,   12,   12, 0x08,
     887,   12,   12,   12, 0x08,
     906,   12,   12,   12, 0x08,
     930,   12,   12,   12, 0x08,
     950,   12,   12,   12, 0x08,
     970,   12,   12,   12, 0x08,
     990,   12,   12,   12, 0x08,
    1011,   12,   12,   12, 0x08,
    1031,   12,   12,   12, 0x08,
    1050,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CommandList[] = {
    "CommandList\0\0test_sig()\0movj_list_sig(QString*)\0"
    "movj_list_simula_sig(QString*)\0"
    "movl_list_simula_sig(QString*)\0"
    "movc_list_simula_sig(QString*)\0"
    "speed_list_simula_sig(QString*)\0"
    "dout_list_simula_sig(QString*)\0"
    "din_list_simula_sig(QString*)\0"
    "pause_list_simula_sig(QString*)\0"
    "timer_list_simula_sig(QString)\0"
    "jump_list_simula_sig(QString*)\0"
    "label_list_simula_sig(QString)\0"
    "call_list_simula_sig(QString*)\0"
    "ret_list_simula_sig(QString*)\0"
    "list_insert_sig()\0list_simu_insert_sig(QString*)\0"
    "commandmovj()\0commandmovl()\0commandmovc()\0"
    "commandimov()\0commandspeed()\0"
    "commandcoord()\0commandhome()\0commanddout()\0"
    "commanddin()\0commandaout()\0commandain()\0"
    "commandaration()\0commandaratiof()\0"
    "commandjump()\0commandlabel()\0commandcall()\0"
    "commandret()\0commandtimer()\0commandpause()\0"
    "commandcwait()\0commandadd()\0commandsub()\0"
    "commandmul()\0commanddiv()\0commandinc()\0"
    "commanddec()\0commandand()\0commandor()\0"
    "commandnot()\0commandxor()\0close_input_slot()\0"
    "on_pushButton_clicked()\0movj_slot(QString*)\0"
    "movl_slot(QString*)\0movc_slot(QString*)\0"
    "speed_slot(QString*)\0dout_slot(QString*)\0"
    "list_insert_slot()\0list_simu_insert_slot(QString*)\0"
};

void CommandList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommandList *_t = static_cast<CommandList *>(_o);
        switch (_id) {
        case 0: _t->test_sig(); break;
        case 1: _t->movj_list_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 2: _t->movj_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 3: _t->movl_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 4: _t->movc_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 5: _t->speed_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 6: _t->dout_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 7: _t->din_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 8: _t->pause_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 9: _t->timer_list_simula_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->jump_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 11: _t->label_list_simula_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->call_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 13: _t->ret_list_simula_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 14: _t->list_insert_sig(); break;
        case 15: _t->list_simu_insert_sig((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 16: _t->commandmovj(); break;
        case 17: _t->commandmovl(); break;
        case 18: _t->commandmovc(); break;
        case 19: _t->commandimov(); break;
        case 20: _t->commandspeed(); break;
        case 21: _t->commandcoord(); break;
        case 22: _t->commandhome(); break;
        case 23: _t->commanddout(); break;
        case 24: _t->commanddin(); break;
        case 25: _t->commandaout(); break;
        case 26: _t->commandain(); break;
        case 27: _t->commandaration(); break;
        case 28: _t->commandaratiof(); break;
        case 29: _t->commandjump(); break;
        case 30: _t->commandlabel(); break;
        case 31: _t->commandcall(); break;
        case 32: _t->commandret(); break;
        case 33: _t->commandtimer(); break;
        case 34: _t->commandpause(); break;
        case 35: _t->commandcwait(); break;
        case 36: _t->commandadd(); break;
        case 37: _t->commandsub(); break;
        case 38: _t->commandmul(); break;
        case 39: _t->commanddiv(); break;
        case 40: _t->commandinc(); break;
        case 41: _t->commanddec(); break;
        case 42: _t->commandand(); break;
        case 43: _t->commandor(); break;
        case 44: _t->commandnot(); break;
        case 45: _t->commandxor(); break;
        case 46: _t->close_input_slot(); break;
        case 47: _t->on_pushButton_clicked(); break;
        case 48: _t->movj_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 49: _t->movl_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 50: _t->movc_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 51: _t->speed_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 52: _t->dout_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 53: _t->list_insert_slot(); break;
        case 54: _t->list_simu_insert_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommandList::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommandList::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CommandList,
      qt_meta_data_CommandList, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommandList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommandList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommandList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommandList))
        return static_cast<void*>(const_cast< CommandList*>(this));
    return QDialog::qt_metacast(_clname);
}

int CommandList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void CommandList::test_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CommandList::movj_list_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandList::movj_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandList::movl_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommandList::movc_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommandList::speed_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommandList::dout_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CommandList::din_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CommandList::pause_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CommandList::timer_list_simula_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CommandList::jump_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CommandList::label_list_simula_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CommandList::call_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CommandList::ret_list_simula_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CommandList::list_insert_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void CommandList::list_simu_insert_sig(QString * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_END_MOC_NAMESPACE
