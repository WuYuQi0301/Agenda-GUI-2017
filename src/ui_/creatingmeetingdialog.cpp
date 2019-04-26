#include "createmeetingdialog.h"
#include "ui_CreateMeetingDialog.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QDate>

CreateMeetingDialog::CreateMeetingDialog(const std::list<User> &au, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMeetingDialog)
{
    ui->setupUi(this);
    ui->startDateEdit->setCalendarPopup(true);
    ui->endDateEdit->setCalendarPopup(true);

    QStandardItemModel  *model = new QStandardItemModel();
    model->setColumnCount(1);

    model->setHeaderData(0,Qt::Horizontal,"Users");

    ui->userTableView->setModel(model);
    ui->userTableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->userTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->userTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    注：在进行表格设置时必须是“ui->tableView->setModel(model);”在前，属性具体设置在后，
//    反之则设置不会生效。如上述代码所示。
    int i = 0;
     for(auto _it = au.begin(); _it != au.end(); _it++, i++)
     {
         model->setItem(i,0,new QStandardItem(QString::fromStdString(_it->getName())));
         model->item(i,0)->setForeground(QBrush(QColor(100, 100, 200)));
         model->item(i,0)->setTextAlignment(Qt::AlignCenter);
     }
}

CreateMeetingDialog::~CreateMeetingDialog()
{
    delete ui;
}

void CreateMeetingDialog::on_comfirmButton_clicked()
{
    qDebug() << "comfirm\n";
//获取选中
    QItemSelectionModel *selections = ui->userTableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    std::vector<string> pa;
    foreach (QModelIndex index, selected)
    {
        qDebug() << index.data();
        pa.push_back((index.data().toString().toStdString()));
    }
    std::string _title = ui->titleLineEdit->text().toStdString();
    QString startDate = ui->startDateEdit->date().toString("yyyy-MM-dd") + "/"
                      + ui->startTimeEdit->time().toString("HH:mm");
//    qDebug() <<
    QString endDate = ui->endDateEdit->date().toString("yyyy-MM-dd") + "/"
                      + ui->endTimeEdit->time().toString("HH:mm");

//in CreateMeeting.cpp
//function : on_comfirmButton_clicked()
    emit meetingInfo(_title, startDate.toStdString(), endDate.toStdString(), pa);
}

void CreateMeetingDialog::on_returnButton_clicked()
{
    qDebug() << "return\n";
    this->hide();
    emit showMenu();
}
