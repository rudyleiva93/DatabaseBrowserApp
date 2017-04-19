/* This class file will handle the the use cases for the user created databases. */

#include "DatabaseHandler.h"
//void(*xProgress)(int, int);

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
          fprintf(stderr, "Opened database successfully\n");
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
                 fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
                 return false;
              }else{
                 fprintf(stderr, "Opened database successfully\n");
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
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return(0);
       }else{
          fprintf(stdout, "Opened database successfully\n");
       }

       // Create SQL statement
       QByteArray ba = statement.toLatin1();
       sql = ba.data();

       // Execute SQL statement
       rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
       if( rc != SQLITE_OK ){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
          return false;
       }else{
          fprintf(stdout, "Table created successfully\n");
          return true;
       }
       sqlite3_close(db);
       return false;
}

int DatabaseHandler::BackupDatabase(QString databaseFileName, QString backupFileName, int isSave)
{
    const char *zFileName;
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", backupFileName);
     db.open();

     QVariant v = db.driver()->handle();
     if (v.isValid() && strcmp(v.typeName(), "sqlite3*") == 0)
     {
        // v.data() returns a pointer to the handle
        sqlite3 *handle = *static_cast<sqlite3 **>(v.data());

        if (handle != 0) { // check that it is not NULL
        sqlite3 *p; //without this there is a crash.
        QByteArray ba1 = databaseFileName.toLatin1();
        int result = sqlite3_open( ba1.data(), &p );

        if (result == SQLITE_OK)
        {
            //sqlite3_close(p);
            int rc;                   /* Function return code */
            sqlite3 *pFile;           /* Database connection opened on zFilename */
            sqlite3_backup *pBackup;  /* Backup object used to copy data */
            sqlite3 *pTo;             /* Database to copy to (pFile or pInMemory) */
            sqlite3 *pFrom;           /* Database to copy from (pFile or pInMemory) */

            QByteArray ba = backupFileName.toLatin1();
            zFileName = ba.data();
            rc = sqlite3_open(zFileName, &pFile);

            if( rc==SQLITE_OK )
            {
                pFrom = (isSave ? p : pFile);
                pTo = (isSave ? pFile : p);
                pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main");
                //fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(pFile));

                if( pBackup )
                {
                    (void)sqlite3_backup_step(pBackup, -1);
                    (void)sqlite3_backup_finish(pBackup);
                }
                rc = sqlite3_errcode(pTo);
            }
            (void)sqlite3_close(pFile);
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
       sql = "SELECT * from COMPANY";
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
         fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
         //return(0);
      }else{
         fprintf(stderr, "Opened database successfully\n");
      }

      /* Create SQL statement */
      //sql =

      /* Execute SQL statement */
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
      if( rc != SQLITE_OK ){
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      }else{
         fprintf(stdout, "Records created successfully\n");
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
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          //return(0);
       }else{
          fprintf(stderr, "Opened database successfully\n");
       }

       /* Create SQL statement */
       QByteArray ba = query.toLatin1();
       sql = ba.data();

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
