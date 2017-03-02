#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>

namespace Ui {
class signUpWindow;
}

class signUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit signUpWindow(QWidget *parent = 0);
    ~signUpWindow();

private:
    Ui::signUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
