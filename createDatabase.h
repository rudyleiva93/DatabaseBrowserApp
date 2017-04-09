#ifndef CREATEDATABASE_H
#define CREATEDATABASE_H

#include <QDialog>
#include "DatabaseHandler.h"
#include "databaseInterface.h"
#include "applicationwindow.h"
#include "User.h"
#include "mainwindow.h"
//class MainWindow;

namespace Ui {
class createDatabase;
}

class createDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabase(User, QWidget *parent = 0);
    ~createDatabase();
    databaseInterface db;
    //static User MainWindow::user;

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_createDB_clicked();

private:
    Ui::createDatabase *ui;
    User user;
};
//static User MainWindow::user;


#endif // CREATEDATABASE_H
