#include "createDatabase.h"
#include "ui_createDatabase.h"
#include "applicationwindow.h"
#include "mainwindow.h"


//static User MainWindow::user;

createDatabase::createDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDatabase)
{
    ui->setupUi(this);
}

createDatabase::~createDatabase()
{
    delete ui;
}

void createDatabase::on_pushButton_createDB_clicked()
{
    qInfo()<<"Clicked";
    QString dbNameEntered;

    dbNameEntered = ui->lineEdit_dbNameEntered->text();

    if(db.isDBName(dbNameEntered))
    {
        qInfo()<<"DataBase exists"<<endl;
    }
    else
    {
        //qInfo()<<"DataBase doesnt exists"<<endl;
        db.addDatabase(dbNameEntered);
        //db.insertUID_intoDATABASES(MainWindow::user.getUsername());
        //db.insertUID_intoDATABASES(MainWindow::user.getUsername());
        qInfo()<<"DataBase added"<<endl;
    }

    /* Create a function on dtabasaeInterface that will check if the dbNameEntered already exists in the database.
     *  If (dbNameEntered exists)
     *      Display Error message and promt user to enter another db name
     *  else
     *      create a new object for createDB_Function(dbNameEntred)
     *      which will create a new database and save it on a folder in the computer. */
}
