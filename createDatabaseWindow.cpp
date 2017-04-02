#include "createDatabaseWindow.h"
#include "ui_createDatabaseWindow.h"

createDatabaseWindow::createDatabaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDatabaseWindow)
{
    ui->setupUi(this);
}

createDatabaseWindow::~createDatabaseWindow()
{
    delete ui;
}

void createDatabaseWindow::on_pushButton_clicked()
{
    QString dbName;

    dbName = ui->lineEdit_dbNameEntered->text();

    //Create c++ class file and pass the name of the db entered to the file and do the logic there
}
