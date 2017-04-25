#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QDialog>
#include "databaseInterface.h"
#include "DatabaseHandler.h"
#include "createDatabase.h"
#include "createTable.h"
#include "backupDatabase.h"
#include "ModifyTable.h"
#include "User.h"

namespace Ui {
class applicationWindow;
}

class applicationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit applicationWindow(User, QWidget *parent = 0);
    ~applicationWindow();

private slots:

    void on_pushButton_openDatabase_clicked();

    void on_pushButton_createDatabase_clicked();

    void on_pushButton_backupDatabse_clicked();

    void on_pushButton_createTable_clicked();

    void on_pushButton_modifyTable_clicked();

    void on_pushButton_loadTable_clicked();

private:
    Ui::applicationWindow *ui;
    User user;
    QString databaseName;
    databaseInterface db;
    DatabaseHandler dh;
};

#endif // APPLICATIONWINDOW_H
