#include "createTable.h"
#include "ui_createTable.h"

createTable::createTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTable)
{
    ui->setupUi(this);
}

createTable::~createTable()
{
    delete ui;
}
