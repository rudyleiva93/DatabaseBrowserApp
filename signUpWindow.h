#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include "databaseInterface.h"
#include "mainwindow.h"
class MainWindow;

namespace Ui {
class signUpWindow;
}

class signUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit signUpWindow(MainWindow *, QWidget *parent = 0);
    ~signUpWindow();

    databaseInterface db;

private slots:
    void on_pushButton_signUp_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::signUpWindow *ui;
    MainWindow *mw;
};

#endif // SIGNUPWINDOW_H
