#ifndef CREATEDATABASE_H
#define CREATEDATABASE_H

#include <QDialog>
#include "createDB_Function.h"
#include "databaseInterface.h"
#include "applicationwindow.h"

namespace Ui {
class createDatabase;
}

class createDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabase(QWidget *parent = 0);
    ~createDatabase();
    databaseInterface db;

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_createDB_clicked();

private:
    Ui::createDatabase *ui;
};

#endif // CREATEDATABASE_H
