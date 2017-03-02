#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

class databaseInterface
{
public:
    databaseInterface();
    databaseInterface(QString connection);
    bool validate(QString username, QString password);

//private slots:
    //bool validate(QString username, QString password);

private:
    QSqlDatabase myDB;
    QString connection;
};

#endif // DATABASEINTERFACE_H
