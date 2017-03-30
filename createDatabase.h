#ifndef CREATEDATABASE_H
#define CREATEDATABASE_H

#include <QDialog>

namespace Ui {
class createDatabase;
}

class createDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabase(QWidget *parent = 0);
    ~createDatabase();

private:
    Ui::createDatabase *ui;
};

#endif // CREATEDATABASE_H
