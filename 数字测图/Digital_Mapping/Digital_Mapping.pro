#-------------------------------------------------
#
# Project created by QtCreator 2019-12-17T18:27:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Digital_Mapping
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        class1.cpp \
        class2.cpp \
        class3.cpp \
        class4.cpp \
        class5.cpp \
        dialog1.cpp \
        dialog2.cpp \
        dialog3.cpp \
        dialog4.cpp \
        dialog5.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        class1.h \
        class2.h \
        class3.h \
        class4.h \
        class5.h \
        dialog1.h \
        dialog2.h \
        dialog3.h \
        dialog4.h \
        dialog5.h \
        mainwindow.h

FORMS += \
        dialog1.ui \
        dialog2.ui \
        dialog3.ui \
        dialog4.ui \
        dialog5.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
