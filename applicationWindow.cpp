#include "applicationWindow.h"
#include "ui_applicationWindow.h"

applicationWindow::applicationWindow(User user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applicationWindow)
{
    ui->setupUi(this);
    this->user = user;
}

applicationWindow::~applicationWindow()
{
    delete ui;
}

void applicationWindow::on_pushButton_openDatabase_clicked()
{

    // Gets the database name entered by the user
    this->databaseName = ui->lineEdit_openDatabase->text();
    // sets the user database name
    user.setDatabaseName(databaseName);

    if(!db.isDBName(databaseName)) // If the database has not been created yet...
    {
        ui->label_result->setText("Database doesnt exist!");
    }
    else
    {
        if(dh.OpenDatabase(databaseName)) // If the database has been created, then it will open the databsed
        {
            ui->label_result->setText("Database opened!! :D");
        }
    }
}

void applicationWindow::on_pushButton_createDatabase_clicked()
{
    // Creates a new window to create a database
    db.closeConnection();
    createDatabase cd(user);
    cd.setModal(true);
    cd.exec();
    db.reOpenConnection();
}

void applicationWindow::on_pushButton_backupDatabse_clicked()
{
    // Creates a new window to backup a database
    backupDatabase b;
    b.setModal(true);
    b.exec();
}

void applicationWindow::on_pushButton_createTable_clicked()
{
    // Creates a window for the user to cretae a table for an open database
    createTable ct(databaseName, user);
    ct.setModal(true);
    ct.exec();
}

void applicationWindow::on_pushButton_modifyTable_clicked()
{
    // Creates a new window for the user to query into the datbase
    ModifyTable mt(user);
    mt.setModal(true);
    mt.exec();
}

void applicationWindow::on_pushButton_loadTable_clicked()
{
    db.closeConnection();
    QString tableName = ui->lineEdit_tableName->text();
    QString connection = "C:/Users/Rudy/Documents/build-DatabaseBrowserApp-Desktop_Qt_5_8_0_MinGW_32bit-Debug/";
    connection.append(databaseName);
    databaseInterface *database = new databaseInterface (connection);
    database->viewTable(ui->tableView, tableName);
    database->closeConnection();
    db.reOpenConnection();
}

