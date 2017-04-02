#ifndef CREATEDATABASEWINDOW_H
#define CREATEDATABASEWINDOW_H

#include <QDialog>

namespace Ui {
class createDatabaseWindow;
}

class createDatabaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabaseWindow(QWidget *parent = 0);
    ~createDatabaseWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createDatabaseWindow *ui;
};

#endif // CREATEDATABASEWINDOW_H
