#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

//#include "ui_WelcomeDialog.h"
#include <QDialog>
#include <QString>

namespace Ui {
class WelcomeDialog;
}

class WelcomeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WelcomeDialog(QWidget *parent = 0);
     ~WelcomeDialog();

private slots:

    //ui component action
    void on_Login_clicked();

    void on_RegisterBottom_clicked();

    void on_QuitButton_clicked();

signals:
    //in WelcomeDialog
    //emit command to main window
    void command(const int& command);


private:
    Ui::WelcomeDialog *ui;
};

#endif // WELCOMEDIALOG_H
