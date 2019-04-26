#include "logindialog.h"
#include "ui_LoginDialog.h"
#include <QString>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}
LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_ComfirmButton_clicked()
{
    QString userName = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    emit loginInfo(userName, password);
}


void LoginDialog::on_ReturnBottom_clicked()
{
    this->hide();
    emit showWelcome();
}
void LoginDialog::clearInput()
{
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
}
