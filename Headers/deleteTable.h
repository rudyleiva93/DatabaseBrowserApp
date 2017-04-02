#ifndef DELETETABLE_H
#define DELETETABLE_H

#include <QDialog>

namespace Ui {
class deleteTable;
}

class deleteTable : public QDialog
{
    Q_OBJECT

public:
    explicit deleteTable(QWidget *parent = 0);
    ~deleteTable();

private:
    Ui::deleteTable *ui;
};

#endif // DELETETABLE_H
