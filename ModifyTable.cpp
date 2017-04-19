#include "ModifyTable.h"
#include "ui_ModifyTable.h"

ModifyTable::ModifyTable(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyTable)
{
    ui->setupUi(this);
    this->user = user;
}

ModifyTable::~ModifyTable()
{
    delete ui;
}

void ModifyTable::on_pushButton_insertTable_clicked()
{
    QString dbName = user.getDatabaseName();
    qDebug()<<dbName<<endl;
    QString query = ui->lineEdit_query->text();
    dh.Insert(query, dbName);
    //QString query2 = "SELECT * FROM " + dbName;
    dh.viewDatabase(dbName);
}

void ModifyTable::on_pushButton_delete_clicked()
{
    QString dbName = user.getDatabaseName();
    qDebug()<<dbName<<endl;
    QString query = ui->lineEdit_deleteQuery->text();
    dh.Delete(query, dbName);
    //QString query2 = "SELECT * FROM " + dbName;
    dh.viewDatabase(dbName);
}
