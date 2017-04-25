/* This is the  window used to backup user created databases.
 * The database does not have to be opened in order to backup. */

#include "backupDatabase.h"
#include "ui_backupDatabase.h"

backupDatabase::backupDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backupDatabase)
{
    ui->setupUi(this); // Sets up the window
}

backupDatabase::~backupDatabase()
{
    delete ui;
}

void backupDatabase::on_pushButton_backupDB_clicked()
{
    QString databaseFileName = ui->lineEdit_dbToBackup->text(); // Gets the name of the databse to be backed up, entered by user
    QString backupFileName = ui->lineEdit_backupFileName->text();// Gets the path of where the backed up databse is to be saved.

    dh.BackupDatabase(databaseFileName, backupFileName, 1); // Method to backup the database
}

// This is the method that gets called when the browse button is pushed
void backupDatabase::on_pushButton_browse_clicked()
{
    // This QString variable calls a window that allows the user where to d=save his backed up database.
    // The file name that the user inputs, along with the path of where it is saved will be stored in this variable as a QString.
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Backup"), "",
            tr("Backup (*.db);;All Files (*)"));

    ui->lineEdit_backupFileName->setText(fileName); // Set the line edit to the path where the database backup is to be saved.
}
