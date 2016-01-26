/****************************************************************************
** Meta object code from reading C++ file 'ex03opengl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ex03opengl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ex03opengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Ex03opengl_t {
    QByteArrayData data[19];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Ex03opengl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Ex03opengl_t qt_meta_stringdata_Ex03opengl = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 4),
QT_MOC_LITERAL(4, 24, 4),
QT_MOC_LITERAL(5, 29, 9),
QT_MOC_LITERAL(6, 39, 3),
QT_MOC_LITERAL(7, 43, 14),
QT_MOC_LITERAL(8, 58, 2),
QT_MOC_LITERAL(9, 61, 9),
QT_MOC_LITERAL(10, 71, 4),
QT_MOC_LITERAL(11, 76, 4),
QT_MOC_LITERAL(12, 81, 1),
QT_MOC_LITERAL(13, 83, 4),
QT_MOC_LITERAL(14, 88, 1),
QT_MOC_LITERAL(15, 90, 7),
QT_MOC_LITERAL(16, 98, 1),
QT_MOC_LITERAL(17, 100, 12),
QT_MOC_LITERAL(18, 113, 5)
    },
    "Ex03opengl\0angles\0\0text\0zoom\0setShader\0"
    "sel\0setPerspective\0on\0setObject\0type\0"
    "setX\0X\0setY\0Y\0setZoom\0Z\0setLightMove\0"
    "reset\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ex03opengl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,
       4,    1,   67,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a,
       7,    1,   73,    2, 0x0a,
       9,    1,   76,    2, 0x0a,
      11,    1,   79,    2, 0x0a,
      13,    1,   82,    2, 0x0a,
      15,    1,   85,    2, 0x0a,
      17,    1,   88,    2, 0x0a,
      18,    0,   91,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void Ex03opengl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ex03opengl *_t = static_cast<Ex03opengl *>(_o);
        switch (_id) {
        case 0: _t->angles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->zoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setShader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setPerspective((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setZoom((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setLightMove((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ex03opengl::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ex03opengl::angles)) {
                *result = 0;
            }
        }
        {
            typedef void (Ex03opengl::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ex03opengl::zoom)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Ex03opengl::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Ex03opengl.data,
      qt_meta_data_Ex03opengl,  qt_static_metacall, 0, 0}
};


const QMetaObject *Ex03opengl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ex03opengl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ex03opengl.stringdata))
        return static_cast<void*>(const_cast< Ex03opengl*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Ex03opengl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Ex03opengl::angles(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Ex03opengl::zoom(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
