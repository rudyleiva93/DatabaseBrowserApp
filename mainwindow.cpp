#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseInterface.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   /* if(!myDB.open())
    {
        ui->label_status->setText("Failed to connect!");
    }
    else
    {
        ui ->label_status->setText("Connected...");
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username, password;
    username = ui -> lineEdit_username -> text();
    password = ui -> lineEdit_password -> text();

    databaseInterface db;
    if(db.validate(username, password))
    {
        // To be continued here....
    }
    else
    {

    }
}
