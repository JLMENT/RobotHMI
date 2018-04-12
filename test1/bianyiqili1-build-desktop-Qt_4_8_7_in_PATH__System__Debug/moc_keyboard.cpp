/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/keyboardedit/keyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeyBoard[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      27,    9,    9,    9, 0x05,
      55,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,    9,    9,    9, 0x08,
      98,    9,    9,    9, 0x08,
     126,    9,    9,    9, 0x08,
     152,    9,    9,    9, 0x08,
     186,    9,    9,    9, 0x08,
     217,    9,    9,    9, 0x08,
     248,    9,    9,    9, 0x08,
     281,    9,    9,    9, 0x08,
     315,    9,    9,    9, 0x08,
     348,    9,    9,    9, 0x08,
     374,    9,    9,    9, 0x08,
     400,    9,    9,    9, 0x08,
     426,    9,    9,    9, 0x08,
     452,    9,    9,    9, 0x08,
     478,    9,    9,    9, 0x08,
     504,    9,    9,    9, 0x08,
     530,    9,    9,    9, 0x08,
     556,    9,    9,    9, 0x08,
     583,    9,    9,    9, 0x08,
     609,    9,    9,    9, 0x08,
     635,    9,    9,    9, 0x08,
     661,    9,    9,    9, 0x08,
     687,    9,    9,    9, 0x08,
     713,    9,    9,    9, 0x08,
     739,    9,    9,    9, 0x08,
     765,    9,    9,    9, 0x08,
     791,    9,    9,    9, 0x08,
     817,    9,    9,    9, 0x08,
     843,    9,    9,    9, 0x08,
     869,    9,    9,    9, 0x08,
     895,    9,    9,    9, 0x08,
     921,    9,    9,    9, 0x08,
     947,    9,    9,    9, 0x08,
     973,    9,    9,    9, 0x08,
     999,    9,    9,    9, 0x08,
    1025,    9,    9,    9, 0x08,
    1051,    9,    9,    9, 0x08,
    1077,    9,    9,    9, 0x08,
    1103,    9,    9,    9, 0x08,
    1129,    9,    9,    9, 0x08,
    1155,    9,    9,    9, 0x08,
    1181,    9,    9,    9, 0x08,
    1207,    9,    9,    9, 0x08,
    1233,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeyBoard[] = {
    "KeyBoard\0\0sendstr(QString)\0"
    "remove_last_character_sig()\0"
    "remove_all_sig()\0on_pushButton_1_clicked()\0"
    "on_pushButton_dot_clicked()\0"
    "on_pushButton_b_clicked()\0"
    "on_pushButton_underline_clicked()\0"
    "on_pushButton_cancle_clicked()\0"
    "on_pushButton_ensure_clicked()\0"
    "on_pushButton_capsmall_clicked()\0"
    "on_pushButton_backspace_clicked()\0"
    "on_pushButton_clearall_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_7_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_9_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_q_clicked()\0"
    "on_pushButton_w_clicked()\0"
    "on_pushButton_e_clicked()\0"
    "on_pushButton_r_clicked()\0"
    "on_pushButton_t_clicked()\0"
    "on_pushButton_y_clicked()\0"
    "on_pushButton_u_clicked()\0"
    "on_pushButton_i_clicked()\0"
    "on_pushButton_o_clicked()\0"
    "on_pushButton_p_clicked()\0"
    "on_pushButton_a_clicked()\0"
    "on_pushButton_s_clicked()\0"
    "on_pushButton_d_clicked()\0"
    "on_pushButton_f_clicked()\0"
    "on_pushButton_g_clicked()\0"
    "on_pushButton_h_clicked()\0"
    "on_pushButton_j_clicked()\0"
    "on_pushButton_k_clicked()\0"
    "on_pushButton_l_clicked()\0"
    "on_pushButton_z_clicked()\0"
    "on_pushButton_x_clicked()\0"
    "on_pushButton_c_clicked()\0"
    "on_pushButton_v_clicked()\0"
    "on_pushButton_n_clicked()\0"
    "on_pushButton_m_clicked()\0"
    "display_edit_str_slot(QString)\0"
};

void KeyBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeyBoard *_t = static_cast<KeyBoard *>(_o);
        switch (_id) {
        case 0: _t->sendstr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->remove_last_character_sig(); break;
        case 2: _t->remove_all_sig(); break;
        case 3: _t->on_pushButton_1_clicked(); break;
        case 4: _t->on_pushButton_dot_clicked(); break;
        case 5: _t->on_pushButton_b_clicked(); break;
        case 6: _t->on_pushButton_underline_clicked(); break;
        case 7: _t->on_pushButton_cancle_clicked(); break;
        case 8: _t->on_pushButton_ensure_clicked(); break;
        case 9: _t->on_pushButton_capsmall_clicked(); break;
        case 10: _t->on_pushButton_backspace_clicked(); break;
        case 11: _t->on_pushButton_clearall_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->on_pushButton_3_clicked(); break;
        case 14: _t->on_pushButton_4_clicked(); break;
        case 15: _t->on_pushButton_5_clicked(); break;
        case 16: _t->on_pushButton_6_clicked(); break;
        case 17: _t->on_pushButton_7_clicked(); break;
        case 18: _t->on_pushButton_8_clicked(); break;
        case 19: _t->on_pushButton_9_clicked(); break;
        case 20: _t->on_pushButton_10_clicked(); break;
        case 21: _t->on_pushButton_q_clicked(); break;
        case 22: _t->on_pushButton_w_clicked(); break;
        case 23: _t->on_pushButton_e_clicked(); break;
        case 24: _t->on_pushButton_r_clicked(); break;
        case 25: _t->on_pushButton_t_clicked(); break;
        case 26: _t->on_pushButton_y_clicked(); break;
        case 27: _t->on_pushButton_u_clicked(); break;
        case 28: _t->on_pushButton_i_clicked(); break;
        case 29: _t->on_pushButton_o_clicked(); break;
        case 30: _t->on_pushButton_p_clicked(); break;
        case 31: _t->on_pushButton_a_clicked(); break;
        case 32: _t->on_pushButton_s_clicked(); break;
        case 33: _t->on_pushButton_d_clicked(); break;
        case 34: _t->on_pushButton_f_clicked(); break;
        case 35: _t->on_pushButton_g_clicked(); break;
        case 36: _t->on_pushButton_h_clicked(); break;
        case 37: _t->on_pushButton_j_clicked(); break;
        case 38: _t->on_pushButton_k_clicked(); break;
        case 39: _t->on_pushButton_l_clicked(); break;
        case 40: _t->on_pushButton_z_clicked(); break;
        case 41: _t->on_pushButton_x_clicked(); break;
        case 42: _t->on_pushButton_c_clicked(); break;
        case 43: _t->on_pushButton_v_clicked(); break;
        case 44: _t->on_pushButton_n_clicked(); break;
        case 45: _t->on_pushButton_m_clicked(); break;
        case 46: _t->display_edit_str_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KeyBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeyBoard::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KeyBoard,
      qt_meta_data_KeyBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeyBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeyBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeyBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeyBoard))
        return static_cast<void*>(const_cast< KeyBoard*>(this));
    return QDialog::qt_metacast(_clname);
}

int KeyBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}

// SIGNAL 0
void KeyBoard::sendstr(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KeyBoard::remove_last_character_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void KeyBoard::remove_all_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
