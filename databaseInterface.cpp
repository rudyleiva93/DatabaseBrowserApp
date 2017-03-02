#include "databaseInterface.h"

databaseInterface::databaseInterface()
{
    this->connection = "C:/Users/Rudy/Documents/GitHub/DatabaseBrowserApp/DBbrowser.db";
}

databaseInterface::databaseInterface(QString connection)
{
    this->connection = connection;
}

bool databaseInterface::validate(QString username, QString password)
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(connection);

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM USERS WHERE USERNAME ='" + username + "' AND PASSWD = '" + password + "'"))
    {
        myDB.close();
        return true;
    }
    else
    {
        return false;
    }
}
