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

   if(!qry.exec())
   {
        qDebug()<<qry.lastError()<<endl;
   }
   else
   {
        while(qry.next())
        {
            QString dbName = qry.value(0).toString();
            int result = QString::compare(dbName, dbNameEntered);
            return(result == 0);
        }
    }
   return false;
}

bool databaseInterface::addDatabase(QString username, QString dbNameEntered)
{
    myDB.transaction();
    QSqlQuery qry;
    qry.prepare("SELECT UID FROM USERS WHERE USERNAME = :USERNAME");
    qry.bindValue(":USERNAME", username);

    if (!qry.exec()) {
        qDebug()<<qry.lastError().text()<<endl;;
    } else if (!qry.first()) {
        qDebug()<<"No Unchecked invoice in the database"<<endl;
    } else {
        do {
            int uid = (qry.value(0).toInt());
            qry.prepare("INSERT INTO DATABASES (DB_NAME, UID)" \
                                "VALUES (:DB_NAME, :UID)");
            qry.bindValue(":DB_NAME", dbNameEntered);
            qry.bindValue(":UID", uid);
            if(!qry.exec())
                qDebug()<<qry.lastError().text();
        } while(qry.next());
        qry.clear();
        myDB.commit();
        return true;
    }
    return false;
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
