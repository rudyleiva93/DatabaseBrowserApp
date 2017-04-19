#include "OpenDatabase.h"
#include "ui_opendatabase.h"

OpenDatabase::OpenDatabase(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDatabase)
{
    ui->setupUi(this);
    this->user = user;
}

OpenDatabase::~OpenDatabase()
{
    delete ui;
}

void OpenDatabase::on_pushButton_openDB_clicked()
{
    QString dbNameEntered = ui->lineEdit_dbToOpen->text();
    if(!db.isDBName(dbNameEntered))
    {
        ui->label_result->setText("Database doesnt exist!");
    }
    else
    {
        if(dh.OpenDatabase(dbNameEntered))
        {
            //user.setDatabaseName(dbNameEntered);
            //qDebug()<<"1 " + user.getDatabaseName()<<endl;
            ui->label_result->setText("Database opened!! :D");
        }
    }
}

void OpenDatabase::on_pushButton_clicked()
{
    db.closeConnection();
    this->hide();
}
