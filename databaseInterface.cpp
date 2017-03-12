#include "databaseInterface.h"
#include <QMessageBox>

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
    //QSqlDatabase::removeDatabase(connection);
    //delete myDB;
    //QSqlDatabase::~QSqlDatabase();
}

databaseInterface::databaseInterface(QString connection)
{
    this->connection = connection;
    myDB = QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    myDB.setDatabaseName(connection);
    //myDB->open();
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
        if(x == 0 && y ==0)
        {
            //qDebug() << "They match";
            //myDB->close();
            return true;
        }

    }
    //myDB->close();
    return false;
}

void databaseInterface::signUp(QString usernameEntered, QString passwordEntered)
{
    //myDB->open();

    QSqlQuery qry;
    qry.prepare("INSERT INTO USERS (USERNAME,PASSWD)" \
                "VALUES(:USERNAME, :PASSWD)");
    qry.bindValue(":USERNAME", usernameEntered);
    qry.bindValue(":PASSWD",passwordEntered);
    //qry.exec("INSERT INTO USERS (USERNAME,PASSWD" \
             "VALUES('"+usernameEntered+"', '"+passwordEntered+")");
    /*qry.prepare("INSERT INTO USERS (USERNAME,PASSWD" \
             "VALUES (?, ?)");
    qry.addBindValue(usernameEntered);
    qry.addBindValue(passwordEntered);*/

    qDebug()<<qry.exec()<<endl;
    /*if(qry.exec())
    {
        QMessageBox::information(this,"Save","Saved");
    }
    else
    {
        QMessageBox::critical(this,"Error::",qry.lastError().text());
    }*/

}
