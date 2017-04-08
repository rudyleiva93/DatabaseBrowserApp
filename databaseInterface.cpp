#include "databaseInterface.h"
databaseInterface::databaseInterface()
{
    this->connection = "C:/Users/Rudy/Documents/GitHub/DatabaseBrowserApp/DBbrowser.db";
    myDB = QSqlDatabase (QSqlDatabase::addDatabase("QSQLITE"));
    myDB.setDatabaseName(connection);
    myDB.open();
}

void databaseInterface::closeConnection()
{
    myDB.close();
    myDB = QSqlDatabase();
    myDB.removeDatabase(connection);
    myDB.removeDatabase(QSqlDatabase::defaultConnection);
}

databaseInterface::databaseInterface(QString connection)
{
    this->connection = connection;
    myDB = QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    myDB.setDatabaseName(connection);
}

bool databaseInterface::validate(QString username, QString password)
{
    //myDB->open();

    QSqlQuery qry;
    qry.exec("SELECT USERNAME, PASSWD FROM USERS");

    while(qry.next())
    {
        QString name = qry.value(0). toString();
        QString passwd = qry.value(1).toString();

        int x = QString::compare(name, username);
        int y = QString::compare(passwd, password);

        return (x == 0 && y == 0);
        /*if(x == 0 && y == 0)
        {
            //qDebug() << "They match";
            //myDB->close();
            return true;
        }*/

    }
    return false;
}

bool databaseInterface::signUp(QString usernameEntered, QString passwordEntered)
{
    //myDB->open();

    QSqlQuery qry;
    qry.prepare("INSERT INTO USERS (USERNAME,PASSWD)" \
                "VALUES(:USERNAME, :PASSWD)");
    qry.bindValue(":USERNAME", usernameEntered);
    qry.bindValue(":PASSWD",passwordEntered);

    //qDebug()<<qry.exec()<<endl;
    return qry.exec();

}

bool databaseInterface::isDBName(QString dbNameEntered)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM DATABASES WHERE DB_NAME = :DBNAME_ENTERED");
    qry.bindValue(":DBNAME_ENTERED", dbNameEntered);

   /*if(!qry.exec())
   {
        qDebug()<<qry.lastError()<<endl;
   }*/
   while(qry.next())
   {
       QString dbName = qry.value(0).toString();
       int result = QString::compare(dbName, dbNameEntered);
       return(result == 0);
   }
   return false;
}

bool databaseInterface::addDatabase(QString dbNameEntered)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO DATABASES (DB_NAME)" \
                "VALUES (:DB_NAME)");
    qry.bindValue(":DB_NAME", dbNameEntered);

    if(!qry.exec())
    {
        qDebug()<<qry.lastError().text()<<endl;
    }
    //return qry.exec();

}

void databaseInterface::insertUID_intoDATABASES(QString username)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO DATABASES (UID)" \
                "SELECT USERS.UID" \
                "FROM USERS" \
                "WHERE USERS.USERNAME = :USERNAME");
    qry.bindValue(":USERNAME", username);
}

int databaseInterface::getUID(QString username)
{
    QSqlQuery qry;
    qry.prepare("SELECT UID FROM USERS WHERE USERNAME = :USERNAME");
    qry.bindValue(":USERNAME", username);
    qry.exec();

    if(qry.first())
    {
        while(qry.next())
        {
            this->uid = qry.value(0).toInt();
        }
    }
    return uid;
}
