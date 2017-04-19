#ifndef OPENDATABASE_H
#define OPENDATABASE_H

#include <QDialog>
#include "DatabaseHandler.h"
#include "databaseInterface.h"
#include "applicationwindow.h"
#include "User.h"

namespace Ui {
class OpenDatabase;
}

class OpenDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDatabase(User, QWidget *parent = 0);
    ~OpenDatabase();
    databaseInterface db;
    DatabaseHandler dh;

private slots:
    void on_pushButton_openDB_clicked();

    void on_pushButton_clicked();

private:
    Ui::OpenDatabase *ui;
    User user;
};

#endif // OPENDATABASE_H
