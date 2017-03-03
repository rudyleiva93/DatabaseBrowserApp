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
    myDB.open();

    QSqlQuery qry;
    qry.exec("SELECT USERNAME, PASSWD FROM USERS");

    while(qry.next())
    {
        QString name = qry.value(0). toString();
        QString passwd = qry.value(1).toString();

        int x = QString::compare(name, username);
        int y = QString::compare(passwd, password);
        if(x == 0 && y ==0)
        {
            //qDebug() << "They match";
            myDB.close();
            return true;
        }
        else
        {
            return false;
        }
    }
}
