#ifndef CREATEDB_FUNCTION_H
#define CREATEDB_FUNCTION_H

#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include "databaseInterface.h"

class createDB_Function
{
public:
    createDB_Function(QString dbNameEntered);

    databaseInterface db;

private:
    QString dbNameEntered;
};

#endif // CREATEDB_FUNCTION_H
