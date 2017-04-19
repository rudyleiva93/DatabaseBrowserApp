#include "createTable.h"
#include "ui_createTable.h"

createTable::createTable(QString databaseName, User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTable)
{
    ui->setupUi(this);
    this->user = user;
    this->databaseName = databaseName;
}

createTable::~createTable()
{
    delete ui;
}

void createTable::on_pushButton_createTable_clicked()
{
    QString statement = ui->lineEdit_statement->text();
    if(dh.CreateTable(databaseName, statement))
    {
        ui->label_result->setText("Table created!");
    }
    else
    {
        ui->label_result->setText("Inavlid query!");
    }

}
