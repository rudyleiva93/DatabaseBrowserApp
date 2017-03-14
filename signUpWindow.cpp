#include "signUpWindow.h"
#include "ui_signUpWindow.h"

signUpWindow::signUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUpWindow)
{
    ui->setupUi(this);
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
    qDebug()<< usernameEntered;
    qDebug()<< passwordEntered;

    if (db.signUp(usernameEntered, passwordEntered))
    {
        QMessageBox::information(this,"Sign Up","You have successfuly signed up :D");
    }
    else
    {
        QMessageBox::critical(this,"Sign Up","You were not able to sign up!! :(");
    }
}
