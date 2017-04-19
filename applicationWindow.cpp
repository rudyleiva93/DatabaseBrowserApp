#include "applicationWindow.h"
#include "ui_applicationWindow.h"

applicationWindow::applicationWindow(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applicationWindow)
{
    ui->setupUi(this);
    this->user = user;
}

applicationWindow::~applicationWindow()
{
    delete ui;
}

void applicationWindow::on_pushButton_openDatabase_clicked()
{
    //OpenDatabase od(user);
    //od.setModal(true);
    //od.exec();

    this->databaseName = ui->lineEdit_openDatabase->text();
    user.setDatabaseName(databaseName);
    if(!db.isDBName(databaseName))
    {
        ui->label_result->setText("Database doesnt exist!");
    }
    else
    {
        if(dh.OpenDatabase(databaseName))
        {
            //user.setDatabaseName(dbNameEntered);
            //qDebug()<<"1 " + user.getDatabaseName()<<endl;
            ui->label_result->setText("Database opened!! :D");
        }
    }
}

void applicationWindow::on_pushButton_createDatabase_clicked()
{
    createDatabase cd(user);
    cd.setModal(true);
    cd.exec();
}

void applicationWindow::on_pushButton_backupDatabse_clicked()
{
    backupDatabase b;
    b.setModal(true);
    b.exec();
}

void applicationWindow::on_pushButton_createTable_clicked()
{
    createTable ct(databaseName, user);
    ct.setModal(true);
    ct.exec();
}

void applicationWindow::on_pushButton_modifyTable_clicked()
{
    ModifyTable mt(user);
    mt.setModal(true);
    mt.exec();
}

void applicationWindow::on_pushButton_refresh_clicked()
{
   //dh.viewDatabase(databaseName);

}
