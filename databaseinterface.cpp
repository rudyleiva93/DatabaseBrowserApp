#include "databaseinterface.h"
#define Path_To_DB "C:/Users/Rudy/Documents/GitHub/DatabaseBrowserApp/DBBrowser.db"


databaseInterface::databaseInterface()
{
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_To_DB);
    QFileInfo checkFile(Path_To_DB);

    if(checkFile.isFile())
    {
        if(myDB.open())
        {

        }
    }
    else
    {

    }

    //myDB.close();
}
