#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T17:58:49
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agenda_UI
TEMPLATE = app

INCLUDEPATH += include/service_ \
        include/ui_

SOURCES += src/main.cpp\
        src/ui_/mainwindow.cpp \
    src/service_/AgendaService.cpp \
    src/service_/Date.cpp \
    src/service_/Meeting.cpp \
    src/service_/Storage.cpp \
    src/service_/User.cpp \
    src/ui_/welcomedialog.cpp \
    src/ui_/logindialog.cpp \
    src/ui_/registerdialog.cpp \
    src/ui_/creatingmeetingdialog.cpp \
    src/ui_/addialog.cpp \
    src/ui_/qtimedialog.cpp

HEADERS  += include/ui_/mainwindow.h \
    include/service_/AgendaService.hpp \
    include/service_/Date.hpp \
    include/service_/Meeting.hpp \
    include/service_/Path.hpp \
    include/service_/Storage.hpp \
    include/service_/User.hpp \
    Release/tmp/ui/ui_mainwindow.h \
    Release/tmp/ui/ui_WelcomeDialog.h \
    include/ui_/welcomedialog.h \
    include/ui_/logindialog.h \
    include/ui_/registerdialog.h \
    Release/tmp/ui/ui_RegisterDialog.h \
    Release/tmp/ui/ui_LoginDialog.h \
    Release/tmp/ui/ui_CreateMeetingDialog.h \
    include/ui_/createmeetingdialog.h \
    Release/tmp/ui/ui_ADDialog.h \
    include/ui_/addialog.h \
    Release/tmp/ui/ui_QTimeDailog.h \
    include/ui_/qtimedialog.h

FORMS    += ui/mainwindow.ui \
    ui/WelcomeDialog.ui \
    ui/LoginDialog.ui \
    ui/RegisterDialog.ui \
    ui/CreateMeetingDialog.ui \
    ui/ADDialog.ui \
    ui/QTimeDailog.ui

MOC_DIR = tmp/moc

RCC_DIR = tmp/rcc

UI_DIR = tmp/ui

OBJECTS_DIR = ../build

DESTDIR = ../bin

DISTFILES += \
    Release/.qmake.stash \
    data/meetings.csv \
    data/users.csv \
    rc/Agenda.rs

RC_FILE += rc/Agenda.rc

RESOURCES += \
    rc/picture.qrc

