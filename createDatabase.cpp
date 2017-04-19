#include "createDatabase.h"
#include "ui_createDatabase.h"
#include "applicationwindow.h"
#include "mainwindow.h"

createDatabase::createDatabase(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDatabase)
{
    ui->setupUi(this);
    this->user = user;
}

createDatabase::~createDatabase()
{
    delete ui;
}

void createDatabase::on_pushButton_createDB_clicked()
{
    QString dbNameEntered;

    dbNameEntered = ui->lineEdit_dbNameEntered->text();

    if(db.isDBName(dbNameEntered))
    {
        ui->label_result->setText("Database already exists! Choose another name!");
    }
    else
    {
       dh.CreateDatabase(dbNameEntered);
       db.addDatabase(user.getUsername() ,dbNameEntered);
       ui->label_result->setText("Database craeted!!");
    }
}

void createDatabase::on_pushButton_2_clicked()
{
    db.closeConnection();
    this->hide();
}
