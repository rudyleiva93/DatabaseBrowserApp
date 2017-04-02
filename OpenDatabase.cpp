#include "OpenDatabase.h"
#include "ui_opendatabase.h"

OpenDatabase::OpenDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDatabase)
{
    ui->setupUi(this);
}

OpenDatabase::~OpenDatabase()
{
    delete ui;
}
