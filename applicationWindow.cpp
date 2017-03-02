#include "applicationWindow.h"
#include "ui_applicationWindow.h"

applicationWindow::applicationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applicationWindow)
{
    ui->setupUi(this);
}

applicationWindow::~applicationWindow()
{
    delete ui;
}
