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

    if(db.validate(username, password))
    {
        uid = db.getUID(username);
        db.closeConnection();
        user.setUsername(username);
        user.setPassword(password);
        user.setUID(uid);
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
    signUpWindow w(this);
    w.setModal(true);
    w.exec();
}
