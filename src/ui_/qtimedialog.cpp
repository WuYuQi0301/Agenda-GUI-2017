#include "qtimedialog.h"
#include "ui_QTimeDailog.h"

QTimeDialog::QTimeDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::QTimeDialog)
{
    ui->setupUi(this);
    ui->startDateTimeEdit->setDate(QDate::currentDate());
    ui->endDateTimeEdit->setDate(QDate::currentDate());
    ui->startDateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    ui->endDateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm");

    ui->startDateTimeEdit->setCalendarPopup(true);
    ui->endDateTimeEdit->setCalendarPopup(true);
}

QTimeDialog::~QTimeDialog()
{
    delete ui;
}

void QTimeDialog::setWTitle(const QString& str)
{
    ui->groupBox->setTitle(str);
}


void QTimeDialog::on_pushButton_clicked()
{
    QString startDate = ui->startDateTimeEdit->date().toString("yyyy-MM-dd")
            + "/" + ui->startDateTimeEdit->time().toString("HH:mm");
    QString endDate = ui->endDateTimeEdit->date().toString("yyyy-MM-dd")
            + "/" + ui->endDateTimeEdit->time().toString("HH:mm");
    emit timeInfo(startDate.toStdString(), endDate.toStdString());
}

void QTimeDialog::on_pushButton_2_clicked()
{
    emit showMenu();
}
