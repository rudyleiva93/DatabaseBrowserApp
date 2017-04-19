#ifndef MODIFYTABLE_H
#define MODIFYTABLE_H

#include <QDialog>
#include "User.h"
#include "DatabaseHandler.h"

namespace Ui {
class ModifyTable;
}

class ModifyTable : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyTable(User, QWidget *parent = 0);
    ~ModifyTable();

private slots:
    void on_pushButton_insertTable_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::ModifyTable *ui;
    User user;
    DatabaseHandler dh;
};

#endif // MODIFYTABLE_H
