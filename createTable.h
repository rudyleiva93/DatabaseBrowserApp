#ifndef CREATETABLE_H
#define CREATETABLE_H

#include <QDialog>
#include "User.h"
#include "DatabaseHandler.h"

namespace Ui {
class createTable;
}

class createTable : public QDialog
{
    Q_OBJECT

public:
    explicit createTable(QString, User, QWidget *parent = 0);
    ~createTable();
    DatabaseHandler dh;

private slots:
    void on_pushButton_createTable_clicked();

private:
    Ui::createTable *ui;
    User user;
    QString databaseName;
};

#endif // CREATETABLE_H
