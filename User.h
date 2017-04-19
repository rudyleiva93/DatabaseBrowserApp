#ifndef USER_H
#define USER_H

#include <QFileInfo>
class User
{
public:
    User();
    void setUsername(QString username);
    void setUID(int uid);
    void setPassword(QString password);
    QString getUsername();
    QString getPassword();
    int getUID();
    void setDatabaseName(QString dbName);
    QString  getDatabaseName();


private:
    QString username;
    int uid;
    QString password;
    QString dbName;
};

#endif // USER_H
