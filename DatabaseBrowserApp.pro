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
    backupDatabase.cpp \
    sqlite3.c \
    DatabaseHandler.cpp \
    User.cpp \
    ModifyTable.cpp

HEADERS  += mainwindow.h \
    databaseinterface.h \
    databaseInterface.h \
    signUpWindow.h \
    createTable.h \
    createDatabase.h \
    backupDatabase.h \
    applicationwindow.h \
    sqlite3.h \
    sqlite3ext.h \
    DatabaseHandler.h \
    User.h \
    ModifyTable.h

FORMS    += mainwindow.ui \
    applicationWindow.ui \
    signUpWindow.ui \
    createTable.ui \
    createDatabase.ui \
    backupDatabase.ui \
    ModifyTable.ui
