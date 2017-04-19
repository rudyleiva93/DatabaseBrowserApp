#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QFileInfo>
#include <stdio.h>
#include <sqlite3.h>

class DatabaseHandler
{
public:
    DatabaseHandler();
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    bool CreateDatabase(QString dbNameEntered);
    bool OpenDatabase(QString dbNameEntered);
    bool CreateTable(QString databaseName, QString statement);
    bool DeleteTable(QString databaseName);
    void Insert(QString query, QString databaseName);
    void Delete(QString query, QString databaseName);
    int BackupDatabase(QString databaseFileName, QString backupFileName, int isSave);
    void viewDatabase(QString databaseName);

private:
    QString dbNameEntered;
};

#endif // DATABASEHANDLER_H
