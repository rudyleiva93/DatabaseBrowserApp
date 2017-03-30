#include "backupDatabase.h"
#include "ui_backupDatabase.h"

backupDatabase::backupDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backupDatabase)
{
    ui->setupUi(this);
}

backupDatabase::~backupDatabase()
{
    delete ui;
}
