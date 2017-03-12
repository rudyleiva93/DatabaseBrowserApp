#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>
#include "databaseInterface.h"
#include "mainwindow.h"
#include "databaseInterface.h"
//#include "dbconnection.h"

namespace Ui {
class signUpWindow;
}

class signUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit signUpWindow(QWidget *parent = 0);
    ~signUpWindow();

    databaseInterface db; //= new databaseInterface();


private slots:
    void on_pushButton_signUp_clicked();

private:
    Ui::signUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
