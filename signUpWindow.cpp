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
