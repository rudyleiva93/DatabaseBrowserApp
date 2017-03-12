#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include "databaseInterface.h"

class dbConnection
{
public:
    databaseInterface *db = new databaseInterface();
};

#endif // DBCONNECTION_H
