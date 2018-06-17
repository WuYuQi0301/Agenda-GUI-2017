#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

//#include "ui_LoginDialog.h"
#include <QDialog>

namespace Ui{
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void clearInput();

    //ui component action
    void on_ComfirmButton_clicked();

    void on_ReturnBottom_clicked();

signals:
    //emit user login info to mainwindow
    void loginInfo(const QString userName, const QString password);
    //emit to show welcome
    void showWelcome();

private:
    Ui::LoginDialog *ui;
};



#endif // LOGINDIALOG_H
