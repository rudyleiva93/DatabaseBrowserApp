#include <QDebug>
#include <QtSql>
#include <QFileInfo>

#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H


class databaseInterface
{
public:
    databaseInterface();

private:
    QSqlDatabase myDB;
};

#endif // DATABASEINTERFACE_H
