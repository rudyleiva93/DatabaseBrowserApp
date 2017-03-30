#include "deleteTable.h"
#include "ui_deleteTable.h"

deleteTable::deleteTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteTable)
{
    ui->setupUi(this);
}

deleteTable::~deleteTable()
{
    delete ui;
}
