#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T19:07:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DatabaseBrowserApp
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    databaseInterface.cpp \
    applicationWindow.cpp \
    signUpWindow.cpp \
    createTable.cpp \
    createDatabase.cpp \
    OpenDatabase.cpp \
    backupDatabase.cpp \
    deleteTable.cpp \
    Insert.cpp \
    Delete.cpp

HEADERS  += mainwindow.h \
    databaseinterface.h \
    databaseInterface.h \
    applicationWindow.h \
    signUpWindow.h \
    createTable.h \
    createDatabase.h \
    OpenDatabase.h \
    backupDatabase.h \
    deleteTable.h \
    Insert.h \
    Delete.h

FORMS    += mainwindow.ui \
    applicationWindow.ui \
    signUpWindow.ui \
    createTable.ui \
    createDatabase.ui \
    opendatabase.ui \
    backupDatabase.ui \
    deleteTable.ui \
    Insert.ui \
    Delete.ui
