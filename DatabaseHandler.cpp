/* This class file will handle the the use cases for the user created databases. */
#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler()
{
    this->dbNameEntered = "";
}

int DatabaseHandler::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool DatabaseHandler::CreateDatabase(QString dbNameEntered)
{
    sqlite3 *db;
       int rc;

       rc = sqlite3_open_v2(dbNameEntered.toStdString().c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

       if( rc ){
          //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
           qDebug("Can't create database: %s\n", sqlite3_errmsg(db));
          return false;
       }else{
          //fprintf(stderr, "Opened database successfully\n");
           qDebug("Created database successfuly.\n");
          return true;
       }
       return false;
       //return rc;
       sqlite3_close(db);
}

bool DatabaseHandler::OpenDatabase(QString dbNameEntered)
{
    sqlite3 *db;
    int rc;

       rc = sqlite3_open_v2(dbNameEntered.toStdString().c_str(), &db, SQLITE_OPEN_READWRITE, NULL);
       if( rc ){
                 //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                 qDebug("Can't open database: %s\n", sqlite3_errmsg(db));
                 return false;
              }else{
                 //fprintf(stderr, "Opened database successfully\n");
                 qDebug("Opened database successfully\n");
                 return true;
              }
              return false;
       //return rc;
       sqlite3_close(db);

}

bool DatabaseHandler::CreateTable(QString databaseName, QString statement)
{

       sqlite3 *db;
       char *zErrMsg = 0;
       int  rc;
       char *sql;

       // Open database
       rc = sqlite3_open_v2(databaseName.toStdString().c_str(), &db, SQLITE_OPEN_READWRITE, NULL);
       if( rc ){
          //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          //qDebug("Can't open database: %s\n", sqlite3_errmsg(db));
          return(0);
       }else{
          //fprintf(stdout, "Opened database successfully\n");
          //qDebug("");
       }

       // Create SQL statement
       QByteArray ba = statement.toLatin1();
       sql = ba.data();

       // Execute SQL statement
       rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
       if( rc != SQLITE_OK ){
       //fprintf(stderr, "SQL error: %s\n", zErrMsg);
       qDebug("SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
          return false;
       }else{
          //fprintf(stdout, "Table created successfully\n");
          qDebug("Table created successfully\n");
          return true;
       }
       sqlite3_close(db);
       return false;
}

int DatabaseHandler::BackupDatabase(QString databaseFileName, QString backupFileName, int isSave)
{
     const char *zFileName;
     // Add a database connection of type QSqlDatabase
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", backupFileName);
     db.open(); // Opens the QSqlDatabse type

     /* The QVariant acts like a union for the most common types of QT data types.
      * The driver() function is from the QSqlDatabse class which returns the database driver used to acces the databse connection.
      * The handle() function is from the QSqlDriver class and returns the low-level database handle wrapped in a QVariant. */
     QVariant v = db.driver()->handle();

     // Checks to see if v is not an UNKNOWN TYPE and if v has the same name type as "sqlite3 *" object
     if (v.isValid() && strcmp(v.typeName(), "sqlite3*") == 0)
     {
        // Cast v.data() to and sqlite3** and returns a pointer to the handle
        sqlite3 *handle = *static_cast<sqlite3 **>(v.data());

        if (handle != 0) { // check that it is not NULL
        sqlite3 *p; //without this there is a crash.

        // The next two lines is used to turn the QString databaseFilename into a cost char *
        QByteArray ba1 = databaseFileName.toLatin1();
        int result = sqlite3_open( ba1.data(), &p ); // Opens a connection of type sqlite3 * to the original database

        if (result == SQLITE_OK)
        {
            //sqlite3_close(p);
            int rc;                   // Function return code
            sqlite3 *pFile;           // Database connection opened on zFilename
            sqlite3_backup *pBackup;  // Backup object used to copy data
            sqlite3 *pTo;             // Database to copy to (pFile or pInMemory)
            sqlite3 *pFrom;           // Database to copy from (pFile or pInMemory)

            QByteArray ba = backupFileName.toLatin1();
            zFileName = ba.data();
            rc = sqlite3_open(zFileName, &pFile); // opens a databse connection to of type sqlite3 * to the backup databse file

            if( rc==SQLITE_OK )
            {
                // The int isSave is automatically set to 1 so the data from the original database can be copied into the back up database file
                pFrom = (isSave ? p : pFile);
                pTo = (isSave ? pFile : p);
                pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main"); // This initializes the backup

                if( pBackup )
                {
                    (void)sqlite3_backup_step(pBackup, -1); // Transfers the data from the original to the bckup file
                    (void)sqlite3_backup_finish(pBackup);   // releases all resources associated with the backup operation
                }
                rc = sqlite3_errcode(pTo);
            }
            (void)sqlite3_close(pFile); // Close the connection of the sqlite3 * backup file
            db.close(); // close the connection of the QSqlDatabase backup file
            return rc;
     } else
     qDebug() << "Could not sqlite3_open p" << result;
     } else {
     qDebug() << "Could not get sqlite handle";
     }
     } else {
     qDebug() << "handle variant returned typename " << v.typeName();
     }
}

void DatabaseHandler::viewDatabase(QString databaseName)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char *sql;
       const char* data = "Callback function called";

       /* Open database */
       rc = sqlite3_open(databaseName.toStdString().c_str(), &db);
       if( rc ){
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          //return(0);
       }else{
          fprintf(stderr, "Opened database successfully\n");
       }

       /* Create SQL statement */
       sql = "SELECT * from PERSON";
       //QByteArray ba = query.toLatin1();
       //sql = ba.data();

       /* Execute SQL statement */
       rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       }else{
          fprintf(stdout, "Operation done successfully\n");
       }
       sqlite3_close(db);
}

void DatabaseHandler::Insert(QString query, QString databaseName)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

      QByteArray ba = query.toLatin1();
      sql = ba.data();

      /* Open database */
      rc = sqlite3_open(databaseName.toStdString().c_str(), &db);
      if( rc ){
         //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
         //return(0);
      }else{
         //fprintf(stderr, "Opened database successfully\n");
      }

      /* Create SQL statement */
      //sql =

      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
      if( rc != SQLITE_OK ){
         //fprintf(stderr, "SQL error: %s\n", zErrMsg);
         qDebug("SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      }else{
         //fprintf(stdout, "Records created successfully\n");
         qDebug("Records created sucessfully");
      }
      sqlite3_close(db);
}

void DatabaseHandler::Delete(QString query, QString databaseName)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char *sql;
       const char* data = "Callback function called";

       /* Open database */
       rc = sqlite3_open(databaseName.toStdString().c_str(), &db);
       if( rc ){
          //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          //return(0);
       }else{
          //fprintf(stderr, "Opened database successfully\n");
       }

       /* Create SQL statement */
       QByteArray ba = query.toLatin1();
       sql = ba.data();

       /* Execute SQL statement */
       rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
       if( rc != SQLITE_OK ){
          //fprintf(stderr, "SQL error: %s\n", zErrMsg);
          qDebug("SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       }else{
          //fprintf(stdout, "Operation done successfully\n");
          qDebug("Records deleted sucessfully");
       }
       sqlite3_close(db);
}
