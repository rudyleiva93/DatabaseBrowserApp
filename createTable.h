#ifndef CREATETABLE_H
#define CREATETABLE_H

#include <QDialog>

namespace Ui {
class createTable;
}

class createTable : public QDialog
{
    Q_OBJECT

public:
    explicit createTable(QWidget *parent = 0);
    ~createTable();

private:
    Ui::createTable *ui;
};

#endif // CREATETABLE_H
