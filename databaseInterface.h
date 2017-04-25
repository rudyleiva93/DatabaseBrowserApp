#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QTableView>

class databaseInterface
{
public:
    QSqlDatabase myDB;

    databaseInterface();
    databaseInterface(QString connection);
    void closeConnection();
    bool validate(QString username, QString password);
    bool signUp(QString usernameEntered, QString passwordEntered);
    bool isDBName(QString dbNameEntered);
    bool addDatabase(QString username, QString dbNameEntered);
    int getUID(QString username);
    void viewTable(QTableView *tableView, QString tableName);

private:
    QString connection;
    //int uid;
};

#endif // DATABASEINTERFACE_H
