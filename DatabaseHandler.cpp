/* This class file will handle the the use cases for the user created databases. */

#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler()
{
    this->dbNameEntered = "";
}

bool DatabaseHandler::CreateDatabase(QString dbNameEntered)
{
    sqlite3 *db;
       //char *zErrMsg = 0;
       int rc;

       rc = sqlite3_open_v2(dbNameEntered.toStdString().c_str(), &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);

       if( rc ){
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return(0);
       }else{
          fprintf(stderr, "Opened database successfully\n");
       }
       return false;
       sqlite3_close(db);
}
