#include "createDatabase.h"
#include "ui_createDatabase.h"

createDatabase::createDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDatabase)
{
    ui->setupUi(this);
}

createDatabase::~createDatabase()
{
    delete ui;
}

void createDatabase::on_pushButton_clicked()
{
    QString dbNameEntered;

    dbNameEntered = ui->lineEdit_dbNameEntered->text();

    /* Create a function on dtabasaeInterface that will check if the dbNameEntered already exists in the database.
     *  If (dbNameEntered exists)
     *      Display Error message and promt user to enter another db name
     *  else
     *      create a new object for createDB_Function(dbNameEntred)
     *      which will create a new database and save it on a folder in the computer.
     * /
}
