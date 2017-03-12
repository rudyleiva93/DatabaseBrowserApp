#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "applicationWindow.h"
#include "signUpWindow.h"
#include "databaseInterface.h"
//#include "dbconnection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    databaseInterface db;// = new databaseInterface();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signUp_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
