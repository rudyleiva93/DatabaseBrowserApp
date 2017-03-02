#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QDialog>

namespace Ui {
class applicationWindow;
}

class applicationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit applicationWindow(QWidget *parent = 0);
    ~applicationWindow();

private:
    Ui::applicationWindow *ui;
};

#endif // APPLICATIONWINDOW_H
