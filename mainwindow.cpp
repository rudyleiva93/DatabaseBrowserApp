#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username, password;
    int uid;
    username = ui ->lineEdit_username->text();
    password = ui ->lineEdit_password->text();
    //uid = db.getUID(username);
    //qInfo()<< uid<<endl;

    if(db.validate(username, password))
    {
        uid = db.getUID(username);
        //qInfo()<< uid<<endl;
        db.closeConnection();
        //User user;
        user.setUsername(username);
        user.setPassword(password);
        user.setUID(uid);
        //qDebug()<<user.getUID()<<endl;
        //qDebug()<<user.getUsername()<<endl;
        //qDebug()<<user.getPassword()<<endl;
        this->hide();
        applicationWindow app (user);
        app.setModal(true);
        app.exec();
    }
    else
    {
        ui->label_status->setText("Invalid username and/or password");
    }
}

void MainWindow::on_pushButton_signUp_clicked()
{
    db.closeConnection();
    this->hide();
    signUpWindow w;
    w.setModal(true);
    w.exec();
}
