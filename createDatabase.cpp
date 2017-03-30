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
