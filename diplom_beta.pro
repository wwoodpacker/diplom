#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T19:27:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diplom_beta
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Processtable.cpp \
    global.cpp

HEADERS  += mainwindow.h \
    processtable.h \
    accsesdialog.h \
    global.h

FORMS    += mainwindow.ui \
    accsesdialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    Sudo-logo.png \
    process.png \
    journal.jpg \
    main_ico.png \
    user.png \
    resources.png
