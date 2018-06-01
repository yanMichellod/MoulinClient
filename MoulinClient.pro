QT += core
QT += network
QT += widgets
QT -= gui

CONFIG += c++11

TARGET = MoulinClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serverconnection.cpp \
    View/view.cpp \
    View/setupview.cpp \
    data.cpp \
    factory.cpp \
    XF/xf.cpp \
    XF/xfevent.cpp \
    XF/xftimer.cpp \
    Control/controller.cpp \
    View/waitingview.cpp \
    View/inputview.cpp \
    View/gameview.cpp \
    GamePiece/piece.cpp

HEADERS += \
    serverconnection.h \
    View/view.h \
    View/setupview.h \
    data.h \
    factory.h \
    XF/ism.h \
    XF/xf.h \
    XF/xfevent.h \
    XF/xftimer.h \
    Control/controller.h \
    View/waitingview.h \
    View/inputview.h \
    View/gameview.h \
    GamePiece/piece.h
