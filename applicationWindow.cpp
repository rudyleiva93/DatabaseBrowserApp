#include "applicationWindow.h"
#include "ui_applicationWindow.h"

applicationWindow::applicationWindow(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applicationWindow)
{
    ui->setupUi(this);
    this->user = user;
    //qDebug()<< user.getUsername()<<endl;
}

applicationWindow::~applicationWindow()
{
    delete ui;
}

void applicationWindow::on_pushButton_openDatabase_clicked()
{

}

void applicationWindow::on_pushButton_createDatabase_clicked()
{
    createDatabase w(user);
    w.setModal(true);
    w.exec();
}

void applicationWindow::on_pushButton_backupDatabse_clicked()
{

}

void applicationWindow::on_pushButton_deleteTable_clicked()
{

}

void applicationWindow::on_pushButton_createTable_clicked()
{

}
