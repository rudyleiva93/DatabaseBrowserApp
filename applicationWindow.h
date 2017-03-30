#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QDialog>
#include "createDatabase.h"
#include "createTable.h"

namespace Ui {
class applicationWindow;
}

class applicationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit applicationWindow(QWidget *parent = 0);
    ~applicationWindow();

private slots:

    void on_pushButton_openDatabase_clicked();

    void on_pushButton_createDatabase_clicked();

    void on_pushButton_modifyTable_clicked();

    void on_pushButton_deleteTable_clicked();

    void on_pushButton_backupDatabse_clicked();

    void on_pushButton_createTable_clicked();

private:
    Ui::applicationWindow *ui;
};

#endif // APPLICATIONWINDOW_H
