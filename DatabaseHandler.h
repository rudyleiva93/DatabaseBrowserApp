#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <stdio.h>
#include <sqlite3.h>

class DatabaseHandler
{
public:
    DatabaseHandler();
    bool CreateDatabase(QString dbNameEntered);

private:
    QString dbNameEntered;
};

#endif // DATABASEHANDLER_H
