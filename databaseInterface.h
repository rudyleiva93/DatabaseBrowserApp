#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>

class databaseInterface
{
public:
    QSqlDatabase myDB;

    databaseInterface();
    databaseInterface(QString connection);
    void closeConnection();
    bool validate(QString username, QString password);
    bool signUp(QString usernameEntered, QString passwordEntered);

private:
    //QSqlDatabase *myDB;
    QString connection;  
};

#endif // DATABASEINTERFACE_H
