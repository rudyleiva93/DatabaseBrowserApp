#ifndef CREATEDATABASE_H
#define CREATEDATABASE_H

#include <QDialog>
#include "createDB_Function.h"

namespace Ui {
class createDatabase;
}

class createDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabase(QWidget *parent = 0);
    ~createDatabase();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createDatabase *ui;
};

#endif // CREATEDATABASE_H
