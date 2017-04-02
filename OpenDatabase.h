#ifndef OPENDATABASE_H
#define OPENDATABASE_H

#include <QDialog>

namespace Ui {
class OpenDatabase;
}

class OpenDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDatabase(QWidget *parent = 0);
    ~OpenDatabase();

private:
    Ui::OpenDatabase *ui;
};

#endif // OPENDATABASE_H
