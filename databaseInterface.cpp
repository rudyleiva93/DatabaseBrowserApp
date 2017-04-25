#include "databaseInterface.h"
databaseInterface::databaseInterface()
{
    /* Connects to the database in order to insert or retrive user information */
    this->connection = "C:/Users/Rudy/Documents/GitHub/DatabaseBrowserApp/DBbrowser.db";
    myDB = QSqlDatabase (QSqlDatabase::addDatabase("QSQLITE"));
    myDB.setDatabaseName(connection);
    myDB.open();
}

void databaseInterface::closeConnection()
{
    /* Closes and removes the database connection.
     * Always called after an operation is preformed on the database*/
    myDB.close();
    myDB = QSqlDatabase();
    myDB.removeDatabase(connection);
    myDB.removeDatabase(QSqlDatabase::defaultConnection);
}

databaseInterface::databaseInterface(QString connection)
{
    /* Connects to a user specified database */
    this->connection = connection;
    myDB = QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    myDB.setDatabaseName(connection);
    myDB.open();
}

bool databaseInterface::validate(QString username, QString password)
{
    /* Function to validate a if a username and password exist in the database.
     * If it does nont exist the user will have to sign up. */

    QSqlQuery qry; // Initilizes an object of QSqlQuery in order to execute and manipulate SQL statments.
    qry.prepare("SELECT USERNAME, PASSWD FROM USERS"); // Executes the query within the quotes.

    // Retrieves the next record in the result,if available, and positions the query on the retrieved record.
    if(qry.exec())
    {
        if(qry.first())
        {
            do
            {
                // Returns the value of field in the current record.
                QString name = qry.value(0). toString();
                QString passwd = qry.value(1).toString();

                // Compares the values retrived from database with the inputed values from user.
                int x = QString::compare(name, username);
                int y = QString::compare(passwd, password);
                if(x == 0 && y == 0)
                {
                    return true;
                }
            }while(qry.next());
        }
    }
    return false;
}

bool databaseInterface::signUp(QString usernameEntered, QString passwordEntered)
{

    QSqlQuery qry;
    // Prepares the SQL query for execution. Returns true if the query is prepared successfully, otherwise returns false.
    qry.prepare("INSERT INTO USERS (USERNAME,PASSWD)" \
                "VALUES(:USERNAME, :PASSWD)");
    /* Set the placeholders (":USERNAME" & ":PASSWD")to be bound to the value (usernameEntered & passwordEntered) respectively.
     * This method is used in order to prevent SQL injection. */
    qry.bindValue(":USERNAME", usernameEntered);
    qry.bindValue(":PASSWD",passwordEntered);

    // Executes the query and returns true if it executed successfuly, ohterwise returns false.
    return qry.exec();

}

bool databaseInterface::isDBName(QString dbNameEntered)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM DATABASES WHERE DB_NAME = :DBNAME_ENTERED");
    qry.bindValue(":DBNAME_ENTERED", dbNameEntered);

   /* If query does not execute, returns erros.
    * Else, qry retirves the values from database, compares them and returns true or false depending on result. */
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
    // Prepares database for a transaction. Returns true is successful otherwise returns false.
    myDB.transaction();
    QSqlQuery qry;
    // Selects the user ID for the username entered by user
    qry.prepare("SELECT UID FROM USERS WHERE USERNAME = :USERNAME");
    qry.bindValue(":USERNAME", username);

    if (!qry.exec()) {
        qDebug()<<qry.lastError().text()<<endl;
      // Retrieves the first record in the result, if available, and positions the query on the retrieved record.
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
        // Clears the result set and releases any resources held by the query. Sets the query state to inactive.
        qry.clear();
        /* Commits a transaction to the database if a transaction() has been started.
         * Returns true if successful, otherwise returns false. */
        myDB.commit();
        return true;
    }
    return false;
}

int databaseInterface::getUID(QString username)
{
    /* This method was made for the User class
     * so it can have easy access to the user's ID needed for other classes */
    QSqlQuery qry;
    int uid;
    qry.prepare("SELECT UID FROM USERS WHERE USERNAME = :USERNAME");
    qry.bindValue(":USERNAME", username);

    if(qry.exec())
    {
        if(qry.first())
        {
            do
            {
                uid = qry.value(0).toInt();
            }while(qry.next());
        }
    }
    return uid;
}

void databaseInterface::viewTable(QTableView *tableView, QString tableName)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery query;

    if(!query.prepare("SELECT * FROM " + tableName))
        qDebug()<<query.lastError().text()<<endl;

    query.exec();

    modal->setQuery(query);
    qDebug()<<modal->lastError()<<endl;
    tableView->setModel(modal);
    tableView->show();
}
