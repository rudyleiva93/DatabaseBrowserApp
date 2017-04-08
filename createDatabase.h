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

class createDatabase : public QDialog //, public MainWindow /* Trying to inherit user from main window to use user.getUsername and query into db*/
{
    Q_OBJECT

public:
    explicit createDatabase(QWidget *parent = 0);
    ~createDatabase();
    databaseInterface db;
    //static User MainWindow::user;

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_createDB_clicked();

private:
    Ui::createDatabase *ui;
};
//static User MainWindow::user;


#endif // CREATEDATABASE_H
