/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_ThreadData[] = {
    "ThreadData\0"
};

void ThreadData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ThreadData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadData::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ThreadData,
      qt_meta_data_ThreadData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadData))
        return static_cast<void*>(const_cast< ThreadData*>(this));
    return QThread::qt_metacast(_clname);
}

int ThreadData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
     103,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     126,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     226,   11,   11,   11, 0x08,
     244,   11,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     274,   11,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     384,   11,   11,   11, 0x08,
     401,   11,   11,   11, 0x08,
     422,   11,   11,   11, 0x08,
     436,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,
     466,   11,   11,   11, 0x08,
     480,   11,   11,   11, 0x08,
     497,   11,   11,   11, 0x08,
     516,   11,   11,   11, 0x08,
     530,   11,   11,   11, 0x08,
     541,   11,   11,   11, 0x08,
     553,   11,   11,   11, 0x08,
     566,   11,   11,   11, 0x08,
     582,   11,   11,   11, 0x08,
     605,   11,   11,   11, 0x08,
     634,   11,   11,   11, 0x08,
     670,   11,   11,   11, 0x08,
     705,   11,   11,   11, 0x08,
     735,   11,   11,   11, 0x08,
     765,   11,   11,   11, 0x08,
     799,   11,   11,   11, 0x08,
     830,   11,   11,   11, 0x08,
     860,   11,   11,   11, 0x08,
     892,   11,   11,   11, 0x08,
     920,   11,   11,   11, 0x08,
     953,   11,   11,   11, 0x08,
     986,   11,   11,   11, 0x08,
    1019,   11,   11,   11, 0x08,
    1052,   11,   11,   11, 0x08,
    1085,   11,   11,   11, 0x08,
    1118,   11,   11,   11, 0x08,
    1151,   11,   11,   11, 0x08,
    1184,   11,   11,   11, 0x08,
    1212,   11,   11,   11, 0x08,
    1238,   11,   11,   11, 0x08,
    1266,   11,   11,   11, 0x08,
    1293,   11,   11,   11, 0x08,
    1327,   11,   11,   11, 0x08,
    1365,   11,   11,   11, 0x08,
    1391,   11,   11,   11, 0x08,
    1411,   11,   11,   11, 0x08,
    1433,   11,   11,   11, 0x08,
    1455,   11,   11,   11, 0x08,
    1477,   11,   11,   11, 0x08,
    1515,   11,   11,   11, 0x08,
    1537,   11,   11,   11, 0x08,
    1562,   11,   11,   11, 0x08,
    1590,   11,   11,   11, 0x08,
    1614,   11,   11,   11, 0x08,
    1638,   11,   11,   11, 0x08,
    1670,   11,   11,   11, 0x08,
    1702,   11,   11,   11, 0x08,
    1718,   11,   11,   11, 0x08,
    1737,   11,   11,   11, 0x08,
    1759,   11,   11,   11, 0x08,
    1796,   11,   11,   11, 0x08,
    1826,   11,   11,   11, 0x08,
    1841,   11,   11,   11, 0x08,
    1878,   11,   11,   11, 0x08,
    1896,   11,   11,   11, 0x08,
    1912,   11,   11,   11, 0x08,
    1924,   11,   11,   11, 0x08,
    1935,   11,   11,   11, 0x08,
    1957, 1948,   11,   11, 0x08,
    1985, 1948,   11,   11, 0x08,
    2013,   11,   11,   11, 0x08,
    2034,   11,   11,   11, 0x08,
    2053,   11,   11,   11, 0x08,
    2074,   11,   11,   11, 0x0a,
    2105,   11,   11,   11, 0x0a,
    2136,   11,   11,   11, 0x0a,
    2167,   11,   11,   11, 0x0a,
    2199,   11,   11,   11, 0x0a,
    2230,   11,   11,   11, 0x0a,
    2260,   11,   11,   11, 0x0a,
    2292,   11,   11,   11, 0x0a,
    2323,   11,   11,   11, 0x0a,
    2354,   11,   11,   11, 0x0a,
    2385,   11,   11,   11, 0x0a,
    2416,   11,   11,   11, 0x0a,
    2446,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0ActionClick(int)\0"
    "main_insert_sig()\0programcontentpage()\0"
    "programselectpage()\0programmanagepage()\0"
    "programmainpage()\0on_pushButton_6_clicked()\0"
    "SpdAdj1()\0SpeAdj2()\0stackpage1()\0"
    "stackpage2()\0cppage()\0dhpage()\0dhlpage()\0"
    "axiscontrolpage()\0otherpage()\0"
    "ioparameterpage()\0currentpositionpage()\0"
    "zeropositionsetuppage()\0coordinateSMpage()\0"
    "toolmanagementpage()\0exceptionhandlingpage()\0"
    "userrightspage()\0warninghistorypage()\0"
    "editionpage()\0iostatuspage()\0"
    "CAstatuspage()\0Astatuspage()\0"
    "valuestylepage()\0valuemonitorpage()\0"
    "installpage()\0savepage()\0checkpage()\0"
    "deletepage()\0equipmentpage()\0"
    "robotoriginpointpage()\0"
    "on_ParameterButton_clicked()\0"
    "on_positioneditpushButton_clicked()\0"
    "on_simulatekeypushButton_clicked()\0"
    "on_AxispushButton_1_clicked()\0"
    "on_AxispushButton_2_clicked()\0"
    "on_Axis11nextpushButton_clicked()\0"
    "on_iomnextpushButton_clicked()\0"
    "on_dgituppushButton_clicked()\0"
    "on_dgetnextpushButton_clicked()\0"
    "on_kmuppushButton_clicked()\0"
    "on_lwbdcpushButton_581_clicked()\0"
    "on_lwbdcpushButton_582_clicked()\0"
    "on_lwbdcpushButton_583_clicked()\0"
    "on_lwbdcpushButton_584_clicked()\0"
    "on_lwbdcpushButton_587_clicked()\0"
    "on_lwbdcpushButton_588_clicked()\0"
    "on_lwbdcpushButton_586_clicked()\0"
    "on_lwbdcpushButton_585_clicked()\0"
    "on_showpushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_Goodtoolbutton_clicked()\0"
    "on_ProgramButton_clicked()\0"
    "on_OutsideStorageButton_clicked()\0"
    "on_new_main_prog_pushButton_pressed()\0"
    "on_pushButton_5_clicked()\0program_cursor_up()\0"
    "program_cursor_down()\0program_delete_line()\0"
    "insert_slot(QString*)\0"
    "on_pushButton_seprog_ensure_clicked()\0"
    "require_modify_data()\0send_current_line_slot()\0"
    "single_step_backward_slot()\0"
    "multip_send_line_slot()\0multin_send_line_slot()\0"
    "multip_release_send_line_slot()\0"
    "multin_release_send_line_slot()\0"
    "test_run_slot()\0restart_run_slot()\0"
    "when_run_pause_slot()\0"
    "on_new_sub_prog_pushButton_clicked()\0"
    "display_changed_file(QString)\0"
    "file_run_end()\0refresh_reload_program_slot(QString)\0"
    "start_line_slot()\0end_line_slot()\0"
    "copy_slot()\0cut_slot()\0paste_slot()\0"
    "filename\0reload_select_file(QString)\0"
    "ensure_select_file(QString)\0"
    "file_manage_delete()\0file_manage_copy()\0"
    "file_manage_rename()\0"
    "movj_command_display(QString*)\0"
    "movl_command_display(QString*)\0"
    "movc_command_display(QString*)\0"
    "speed_command_display(QString*)\0"
    "dout_command_display(QString*)\0"
    "din_command_display(QString*)\0"
    "pause_command_display(QString*)\0"
    "timer_command_display(QString)\0"
    "jump_command_display(QString*)\0"
    "label_command_display(QString)\0"
    "call_command_display(QString*)\0"
    "ret_command_display(QString*)\0"
    "mainwindow_refresh_cursor()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->ActionClick((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->main_insert_sig(); break;
        case 2: _t->programcontentpage(); break;
        case 3: _t->programselectpage(); break;
        case 4: _t->programmanagepage(); break;
        case 5: _t->programmainpage(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->SpdAdj1(); break;
        case 8: _t->SpeAdj2(); break;
        case 9: _t->stackpage1(); break;
        case 10: _t->stackpage2(); break;
        case 11: _t->cppage(); break;
        case 12: _t->dhpage(); break;
        case 13: _t->dhlpage(); break;
        case 14: _t->axiscontrolpage(); break;
        case 15: _t->otherpage(); break;
        case 16: _t->ioparameterpage(); break;
        case 17: _t->currentpositionpage(); break;
        case 18: _t->zeropositionsetuppage(); break;
        case 19: _t->coordinateSMpage(); break;
        case 20: _t->toolmanagementpage(); break;
        case 21: _t->exceptionhandlingpage(); break;
        case 22: _t->userrightspage(); break;
        case 23: _t->warninghistorypage(); break;
        case 24: _t->editionpage(); break;
        case 25: _t->iostatuspage(); break;
        case 26: _t->CAstatuspage(); break;
        case 27: _t->Astatuspage(); break;
        case 28: _t->valuestylepage(); break;
        case 29: _t->valuemonitorpage(); break;
        case 30: _t->installpage(); break;
        case 31: _t->savepage(); break;
        case 32: _t->checkpage(); break;
        case 33: _t->deletepage(); break;
        case 34: _t->equipmentpage(); break;
        case 35: _t->robotoriginpointpage(); break;
        case 36: _t->on_ParameterButton_clicked(); break;
        case 37: _t->on_positioneditpushButton_clicked(); break;
        case 38: _t->on_simulatekeypushButton_clicked(); break;
        case 39: _t->on_AxispushButton_1_clicked(); break;
        case 40: _t->on_AxispushButton_2_clicked(); break;
        case 41: _t->on_Axis11nextpushButton_clicked(); break;
        case 42: _t->on_iomnextpushButton_clicked(); break;
        case 43: _t->on_dgituppushButton_clicked(); break;
        case 44: _t->on_dgetnextpushButton_clicked(); break;
        case 45: _t->on_kmuppushButton_clicked(); break;
        case 46: _t->on_lwbdcpushButton_581_clicked(); break;
        case 47: _t->on_lwbdcpushButton_582_clicked(); break;
        case 48: _t->on_lwbdcpushButton_583_clicked(); break;
        case 49: _t->on_lwbdcpushButton_584_clicked(); break;
        case 50: _t->on_lwbdcpushButton_587_clicked(); break;
        case 51: _t->on_lwbdcpushButton_588_clicked(); break;
        case 52: _t->on_lwbdcpushButton_586_clicked(); break;
        case 53: _t->on_lwbdcpushButton_585_clicked(); break;
        case 54: _t->on_showpushButton_clicked(); break;
        case 55: _t->on_pushButton_2_clicked(); break;
        case 56: _t->on_Goodtoolbutton_clicked(); break;
        case 57: _t->on_ProgramButton_clicked(); break;
        case 58: _t->on_OutsideStorageButton_clicked(); break;
        case 59: _t->on_new_main_prog_pushButton_pressed(); break;
        case 60: _t->on_pushButton_5_clicked(); break;
        case 61: _t->program_cursor_up(); break;
        case 62: _t->program_cursor_down(); break;
        case 63: _t->program_delete_line(); break;
        case 64: _t->insert_slot((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 65: _t->on_pushButton_seprog_ensure_clicked(); break;
        case 66: _t->require_modify_data(); break;
        case 67: _t->send_current_line_slot(); break;
        case 68: _t->single_step_backward_slot(); break;
        case 69: _t->multip_send_line_slot(); break;
        case 70: _t->multin_send_line_slot(); break;
        case 71: _t->multip_release_send_line_slot(); break;
        case 72: _t->multin_release_send_line_slot(); break;
        case 73: _t->test_run_slot(); break;
        case 74: _t->restart_run_slot(); break;
        case 75: _t->when_run_pause_slot(); break;
        case 76: _t->on_new_sub_prog_pushButton_clicked(); break;
        case 77: _t->display_changed_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 78: _t->file_run_end(); break;
        case 79: _t->refresh_reload_program_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 80: _t->start_line_slot(); break;
        case 81: _t->end_line_slot(); break;
        case 82: _t->copy_slot(); break;
        case 83: _t->cut_slot(); break;
        case 84: _t->paste_slot(); break;
        case 85: _t->reload_select_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 86: _t->ensure_select_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 87: _t->file_manage_delete(); break;
        case 88: _t->file_manage_copy(); break;
        case 89: _t->file_manage_rename(); break;
        case 90: _t->movj_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 91: _t->movl_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 92: _t->movc_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 93: _t->speed_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 94: _t->dout_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 95: _t->din_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 96: _t->pause_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 97: _t->timer_command_display((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 98: _t->jump_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 99: _t->label_command_display((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 100: _t->call_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 101: _t->ret_command_display((*reinterpret_cast< QString*(*)>(_a[1]))); break;
        case 102: _t->mainwindow_refresh_cursor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 103)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 103;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::ActionClick(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::main_insert_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_FileSelectPushButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      50,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileSelectPushButton[] = {
    "FileSelectPushButton\0\0reload_program_sig(QString)\0"
    "select_program_sig(QString)\0"
    "send_select_program_slot()\0"
};

void FileSelectPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileSelectPushButton *_t = static_cast<FileSelectPushButton *>(_o);
        switch (_id) {
        case 0: _t->reload_program_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->select_program_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->send_select_program_slot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileSelectPushButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileSelectPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_FileSelectPushButton,
      qt_meta_data_FileSelectPushButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileSelectPushButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileSelectPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileSelectPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileSelectPushButton))
        return static_cast<void*>(const_cast< FileSelectPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int FileSelectPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FileSelectPushButton::reload_program_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileSelectPushButton::select_program_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
