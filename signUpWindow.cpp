#include "signUpWindow.h"
#include "ui_signUpWindow.h"
#include "mainwindow.h"

signUpWindow::signUpWindow(MainWindow *mw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUpWindow)
{
    ui->setupUi(this);
    this->mw = mw;
}

signUpWindow::~signUpWindow()
{
    delete ui;
}

void signUpWindow::on_pushButton_signUp_clicked()
{
    QString usernameEntered, passwordEntered;

    usernameEntered = ui->lineEdit_entrUsnm->text();
    passwordEntered = ui->lineEdit_entrPsswd->text();

    if (db.signUp(usernameEntered, passwordEntered))
    {
        QMessageBox::information(this,"Sign Up","You have successfuly signed up :D");
    }
    else
    {
        QMessageBox::critical(this,"Sign Up","Username and/or password already exists! \nYou were not able to sign up!! :(");
    }
}

void signUpWindow::on_pushButton_close_clicked()
{
    this->hide();
    mw->show();

}
