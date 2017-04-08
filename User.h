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

private:
    QString username;
    int uid;
    QString password;

};

#endif // USER_H
