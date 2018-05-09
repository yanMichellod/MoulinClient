QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = MoulinClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    serverconnection.cpp

HEADERS += \
    serverconnection.h
