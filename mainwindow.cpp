#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName("C:/Users/Rudy/Documents/GitHub/DatabaseBrowserApp/DBbrowser.db");

    if(!myDB.open())
    {
        ui->label_status->setText("Failed to connect!");
    }
    else
    {
        ui ->label_status->setText("Connected...");
    }
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

    if(!myDB.isOpen())
    {
        qDebug() <<"Failed to connect!";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM USERS WHERE USERNAME ='" + username + "' AND PASSWD = '" + password + "'"))
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            ui -> label_status -> setText("username and password is correct");
        }
        if(count > 1)
        {
            ui -> label_status -> setText("Duplicate username and password");
        }
        if(count < 1)
        {
            ui -> label_status -> setText("username and password is incorrect");
        }
    }
}
