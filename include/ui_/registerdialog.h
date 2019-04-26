#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include "ui_RegisterDialog.h"
#include <QDialog>
#include <QString>

namespace Ui{
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();


private slots:

    //ui component action
    void on_comfirmButton_clicked();


    void on_returnButtom_clicked();

signals:
    void registerInfo(const QString, const QString, const QString, const QString);
    void showWelcome();
private:
    Ui::RegisterDialog *ui;
};


#endif // REGISTERDIALOG_H
