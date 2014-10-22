#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T05:27:26
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pidgeon
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    chatbox.cpp \
    protocol.cpp \
    protocolsv.cpp \
    network.cpp \
    user.cpp \
    channel.cpp \
    protocolirc.cpp \
    networkmode.cpp \
    configuration.cpp \
    items.cpp \
    commands.cpp

HEADERS  += window.h \
    chatbox.h \
    protocol.h \
    protocolsv.h \
    network.h \
    user.h \
    channel.h \
    protocolirc.h \
    networkmode.h \
    configuration.h \
    items.h \
    commands.h

FORMS    += window.ui \
    chatbox.ui \
    items.ui

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml

