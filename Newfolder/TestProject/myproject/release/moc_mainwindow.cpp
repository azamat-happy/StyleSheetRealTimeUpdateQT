/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCMainWindowENDCLASS = QtMocHelpers::stringData(
    "CMainWindow",
    "onThemeActionTriggered",
    "",
    "onStyleManagerStylesheetChanged",
    "onThemeColorButtonClicked",
    "connectThemeActions",
    "onThemeButtonClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCMainWindowENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[12];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[32];
    char stringdata4[26];
    char stringdata5[20];
    char stringdata6[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCMainWindowENDCLASS_t qt_meta_stringdata_CLASSCMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "CMainWindow"
        QT_MOC_LITERAL(12, 22),  // "onThemeActionTriggered"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 31),  // "onStyleManagerStylesheetChanged"
        QT_MOC_LITERAL(68, 25),  // "onThemeColorButtonClicked"
        QT_MOC_LITERAL(94, 19),  // "connectThemeActions"
        QT_MOC_LITERAL(114, 20)   // "onThemeButtonClicked"
    },
    "CMainWindow",
    "onThemeActionTriggered",
    "",
    "onStyleManagerStylesheetChanged",
    "onThemeColorButtonClicked",
    "connectThemeActions",
    "onThemeButtonClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CMainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSCMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CMainWindow, std::true_type>,
        // method 'onThemeActionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onStyleManagerStylesheetChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onThemeColorButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectThemeActions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onThemeButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onThemeActionTriggered(); break;
        case 1: _t->onStyleManagerStylesheetChanged(); break;
        case 2: _t->onThemeColorButtonClicked(); break;
        case 3: _t->connectThemeActions(); break;
        case 4: _t->onThemeButtonClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
