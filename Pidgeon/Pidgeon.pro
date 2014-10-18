#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T05:27:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pidgeon
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    chatbox.cpp \
    protocol.cpp \
    protocolsv.cpp \
    network.cpp

HEADERS  += window.h \
    chatbox.h \
    protocol.h \
    protocolsv.h \
    network.h

FORMS    += window.ui \
    chatbox.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

