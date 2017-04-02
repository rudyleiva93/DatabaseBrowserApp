#include "Insert.h"
#include "ui_Insert.h"

Insert::Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insert)
{
    ui->setupUi(this);
}

Insert::~Insert()
{
    delete ui;
}
