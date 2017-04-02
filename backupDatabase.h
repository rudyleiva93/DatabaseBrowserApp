#ifndef BACKUPDATABASE_H
#define BACKUPDATABASE_H

#include <QDialog>

namespace Ui {
class backupDatabase;
}

class backupDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit backupDatabase(QWidget *parent = 0);
    ~backupDatabase();

private:
    Ui::backupDatabase *ui;
};

#endif // BACKUPDATABASE_H
