#ifndef BACKUPDATABASE_H
#define BACKUPDATABASE_H

#include <QDialog>
#include <QFileDialog>
#include "DatabaseHandler.h"
#include <sqlite3.h>
#include <sqlite3ext.h>
#include "applicationwindow.h"
#include "mainwindow.h"

namespace Ui {
class backupDatabase;
}

class backupDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit backupDatabase(QWidget *parent = 0);
    ~backupDatabase();

private slots:
    void on_pushButton_backupDB_clicked();

    void on_pushButton_browse_clicked();

private:
    Ui::backupDatabase *ui;
    DatabaseHandler dh;
};

#endif // BACKUPDATABASE_H
