#include "User.h"

User::User()
{
    this->username = "";
    this->uid = 0;
    this->password = "";
}

QString User::getUsername()
{
    return username;
}

QString User::getPassword()
{
    return password;
}

int User::getUID()
{
    return uid;
}

void User::setUsername(QString username)
{
    this->username = username;
}

void User::setPassword(QString password)
{
    this->password = password;
}

void User::setUID(int uid)
{
    this->uid = uid;
}

void User::setDatabaseName(QString dbName)
{
    this->dbName = dbName;
}

QString User::getDatabaseName()
{
    return dbName;
}
