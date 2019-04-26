
#include "registerdialog.h"


RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}
RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_comfirmButton_clicked()
{
    QString username = ui->usernameLineEdit->text(), password = ui->passwordLineEdit->text(),
            email = ui->emailLineEdit->text(), phone = ui->phoneLineEdit->text();
    emit registerInfo(username, password, email, phone);
}


void RegisterDialog::on_returnButtom_clicked()
{
    this->hide();
    emit showWelcome();
}
