#include "welcomedialog.h"
#include "ui_WelcomeDialog.h"

WelcomeDialog::WelcomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeDialog)
{
    ui->setupUi(this);
}

WelcomeDialog::~WelcomeDialog()
{
    delete ui;
}

void WelcomeDialog::on_Login_clicked()
{
    this->hide();
    emit command(1);
}

void WelcomeDialog::on_RegisterBottom_clicked()
{
    this->hide();
    emit command(2);
}

void WelcomeDialog::on_QuitButton_clicked()
{
    emit command(0);
}
