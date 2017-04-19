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

void backupDatabase::on_pushButton_backupDB_clicked()
{
    QString databaseFileName = ui->lineEdit_dbToBackup->text();
    QString backupFileName = ui->lineEdit_backupFileName->text();

    dh.BackupDatabase(databaseFileName, backupFileName, 1);
}

void backupDatabase::on_pushButton_browse_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Backup"), "",
            tr("Backup (*.db);;All Files (*)"));
    ui->lineEdit_backupFileName->setText(fileName);
    //qDebug()<<fileName<<endl;

    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }
}
}
