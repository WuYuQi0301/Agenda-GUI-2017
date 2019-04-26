#include "addialog.h"
#include "ui_ADDialog.h"
#include <qDebug>
#include <QCompleter>

ADDialog::ADDialog(const list<Meeting> meeting, const list<User> users, QWidget *parent) :
    QDialog(parent), ui(new Ui::ADDialog)
{
    qDebug()<<__FUNCTION__<<"is running !";
    ui->setupUi(this);
    //init meeting title box
    QStringList strings;
    for (auto c : meeting)
        strings << QString::fromStdString( c.getTitle() );
    QCompleter *completer = new QCompleter(strings, this);
    ui->TitleComboBox->clear();
    ui->TitleComboBox->addItems(strings);
    ui->TitleComboBox->setEditable(true);
    ui->TitleComboBox->setCompleter(completer);

    //initi user name box
    QStringList ustrings;
    for (auto i : users)
        ustrings << QString::fromStdString( i.getName());
    QCompleter *ucompleter = new QCompleter(ustrings, this);
    ui->paticipatorComboBox->clear();
    ui->paticipatorComboBox->addItems(ustrings);
    ui->paticipatorComboBox->setEditable(true);
    ui->paticipatorComboBox->setCompleter(ucompleter);

}
ADDialog::~ADDialog()
{
    delete ui;
}

void ADDialog::setWTitle(const QString& str)
{
    ui->groupBox->setTitle(str);
}

void ADDialog::on_returnButtom_clicked()
{
    emit showMenu();
}

void ADDialog::on_comfirmButton_clicked()
{
    QString _title = ui->TitleComboBox->currentData().toString();
    QString _pa = ui->paticipatorComboBox->currentData().toString();
    emit meetingInfo(_title.toStdString(), _pa.toStdString());
}
