#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "createmeetingdialog.h"
#include "ui_CreateMeetingDialog.h"
#include "addialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QCompleter>
#include <QTableWidget>
#include <QInputDialog>
#include <sstream>
#include <vector>
using std::stringstream;
using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myService.startAgenda();
}

MainWindow::~MainWindow()
{
    myService.quitAgenda();
    delete ui;
}

//in MainWindow.cpp
void MainWindow::receiveCommand(const int& command)
{
    switch(command)
    {
    case(1):
        qDebug() << "main window : Login execeed\n";
        emit showLogin();
        break;
    case(2):
        qDebug() << "main window : register execeed\n";
        emit showRegister();
        break;
    default:
        qDebug() << "mainwindow : emit Quit system";
        myService.quitAgenda();
        emit quitSystem();
        break;
    }
}

void MainWindow::verifyLogin(const QString _userName, const QString _password)
{
    qDebug() << "mainwindow : login succeed\n";
    if (myService.userLogIn(_userName.toStdString(), _password.toStdString()))
    {
        QString ct = "   Hello " + _userName + " !   ";
        QMessageBox message(QMessageBox::NoIcon, "Succeed", ct);
        message.exec();
        userName = _userName.toStdString();
        password = _password.toStdString();
        this->buildComboBox();
        this->show();
        emit loginSucceed();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "Password error or user doesn't exist!");
        message.exec();
        emit loginFail();
    }
}

void MainWindow::verifyRegister(const QString userName, const QString password,
                                const QString email, const QString phone)
{
    if(myService.userRegister(userName.toStdString(), password.toStdString(),
                              email.toStdString(), phone.toStdString()))
    {
        QString ct = "Hello, new guest!";
        QMessageBox message(QMessageBox::NoIcon, "Succeed", ct);
        message.exec();
        emit showWelcome();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "Invalid input or this username has been registered!");
        message.exec();
    }
}

void MainWindow::buildComboBox()
{
    QStringList strings;
    strings << "log out Agenda"
            << "delete Agenda account"
            << "list all Agenda user"
            << "create a meeting"
            << "add meeting participator"
            << "remove meeting participator"
            << "request to quit meeting"
            << "list all meetings"
            << "list all sponsor meetings"
            << "list all participator meetings"
            << "query meeting by title"
            << "query meeting by time interval"
            << "delete meeting by title"
            << "delete all meetings";

    QCompleter *completer = new QCompleter(strings, this);

    ui->actionComboBox->clear();
    ui->actionComboBox->addItems(strings);
    ui->actionComboBox->setEditable(true);
    ui->actionComboBox->setCompleter(completer);
    qDebug()<<__FUNCTION__<<"is running !";
}
void MainWindow::on_comfirmButton_clicked()
{

     int action = ui->actionComboBox->currentIndex();
     qDebug() << action << "\n" << ui->actionComboBox->currentText();
     executeOperation(action);
}

void MainWindow::executeOperation(const int action)
{
    switch(action)
    {
    case 0:
        userLogOut();
        break;
    case 1:
        deleteUser();
        break;
    case 2:
        listAllUsers();
        break;
    case 3:
        createMeeting();
        break;
    case 4:
        addMeetingParticipator();
        break;
    case 5:
        removeMeetingParticipator();
        break;
    case 6:
        quitMeeting();
        break;
    case 7:
        listAllMeetings();
        break;
    case 8:
        listAllSponsorMeetings();
        break;
    case 9:
        listAllParticipateMeetings();
        break;
    case 10:
        queryMeetingByTitle();
        break;
    case 11:
        queryMeetingByTimeInterval();
        break;
    case 12:
        deleteMeetingByTitle();
        break;
    case 13:
        deleteAllMeetings();
        break;
    }
}

void MainWindow::userLogOut(void)
{
    userName.clear();
    password.clear();
    this->hide();
    emit showWelcome();
}


void MainWindow::quitAgenda(void)
{
   myService.quitAgenda();
}

void MainWindow::deleteUser(void)
{
    myService.deleteUser(userName, password);
    QMessageBox message(QMessageBox::NoIcon, "Succeed", "agenda account deleted");
    message.exec();
    userLogOut();
}

void MainWindow::listAllUsers(void)
{
    std::list<User> users = myService.listAllUsers();
    int row = users.size();
    QTableWidget *table = new QTableWidget(row,3);

    //设置表格行标题
    QStringList headerLabels;
    headerLabels << "userName" << "E-mail" << "phone";
    table->setHorizontalHeaderLabels(headerLabels);

    //设置表格行标题的对齐方式
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //设置行表题
    QStringList rowLabels;
    for (int i = 0; i < row; i++)
    {
        QString label = "User";
        stringstream ss;
        ss << (i + 1);
        label += QString::fromStdString( ss.str());
        rowLabels << label;
    }
    table->setVerticalHeaderLabels(rowLabels);

    //设置每一行的高度
    for(int i = 0; i < 4; i++)
        table->setRowHeight(i, 30);

    //自动调整最后一列的宽度使它和表格的右边界对齐
    table->horizontalHeader()->setStretchLastSection(true);

    //设置表格的选择方式
    table->setSelectionBehavior(QAbstractItemView::SelectItems);

    //设置编辑方式
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表格的内容
    int i = 0;
    for (auto it_ = users.begin(); it_ != users.end(); it_++, i++)
    {
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(it_->getName())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(it_->getEmail())));
        table->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(it_->getPhone())));
    }
    table->setWindowTitle("Users");
    table->resizeColumnsToContents();
    table->setFixedSize(400, 300);
    table->show();
}

void MainWindow::createMeeting(void)
{
    this->hide();
    const std::list<User> au = myService.listAllUsers();
    myCM = new CreateMeetingDialog(au);

    //in MainWindow.cpp
    //function : createMeeting()
    QObject::connect( &(*myCM), SIGNAL(meetingInfo(string,string,string,vector<string>)),
                      &(*this), SLOT(verifyCreateMeeting(string,string,string,vector<string>)));

    QObject::connect( &(*myCM), SIGNAL(showMenu()),&(*this), SLOT(show()));
    QObject::connect( &(*myCM), SIGNAL(showMenu()),&(*myCM), SLOT(close()));
    QObject::connect( &(*this), SIGNAL(CMsucceed()), &(*this), SLOT(show()));
    QObject::connect( &(*this), SIGNAL(CMsucceed()), &(*myCM), SLOT(close()));

    myCM->show();
}

void MainWindow::verifyCreateMeeting(const string _title, const string _startDate,
                                     const string _endDate, const vector<string> pa)
{
    qDebug()<<"connected\n";
    qDebug() <<QString::fromStdString(_startDate);
    if (myService.createMeeting(this->userName, _title, _startDate, _endDate, pa))
    {
        QMessageBox message(QMessageBox::NoIcon, "Succeed", "Meeting created!");
        message.exec();
        emit CMsucceed();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "Meeting create Fail!");
        message.exec();
        emit CMfail();
    }
}


void MainWindow::addMeetingParticipator(void)
{
    this->hide();
    const std::list<Meeting> am = myService.listAllSponsorMeetings(this->userName);
    const std::list<User> au = myService.listAllUsers();
    myADD = new ADDialog(am, au);
    myADD->setWindowTitle("Add Meeting Paticipator");
    myADD->setWTitle("input info");

    QObject::connect( &(*myADD), SIGNAL(meetingInfo(string,string)),
                      &(*this), SLOT(verifyAddMeetingPa(string,string)));
    QObject::connect( &(*myADD), SIGNAL(showMenu()), &(*this), SLOT(show()));
    QObject::connect( &(*myADD), SIGNAL(showMenu()), &(*myADD), SLOT(close()));

    QObject::connect( &(*this), SIGNAL(AMPsucceed()), &(*this), SLOT(show()));
    QObject::connect( &(*this), SIGNAL(AMPsucceed()), &(*myADD), SLOT(close()));

    myADD->show();
}

void MainWindow::verifyAddMeetingPa(const string _title, const string _paticipator)
{
    qDebug()<< __FUNCTION__ << "connected\n"
            <<QString::fromStdString( _title) <<QString::fromStdString( _paticipator);
    if (myService.addMeetingParticipator(this->userName, _title, _paticipator))
    {
        QMessageBox message(QMessageBox::NoIcon, "Succeed", "Paticipator Add!");
        message.exec();
        emit ADsucceed();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "Add Paticipator Fail!");
        message.exec();
        emit ADfail();
    }
}

void MainWindow::removeMeetingParticipator(void)
{
    this->hide();
    const std::list<Meeting> am = myService.listAllSponsorMeetings(this->userName);
    const std::list<User> au = myService.listAllUsers();
    myADD = new ADDialog(am, au);
    myADD->setWindowTitle("Remove Meeting Paticipator");
    myADD->setWTitle("input info");

    QObject::connect( &(*myADD), SIGNAL(meetingInfo(string,string)),
                      &(*this), SLOT(verifyAddMeetingPa(string,string)));
    QObject::connect( &(*myADD), SIGNAL(showMenu()), &(*this), SLOT(show()));
    QObject::connect( &(*myADD), SIGNAL(showMenu()), &(*myADD), SLOT(close()));

    QObject::connect( &(*this), SIGNAL(AMPsucceed()), &(*this), SLOT(show()));
    QObject::connect( &(*this), SIGNAL(AMPsucceed()), &(*myADD), SLOT(close()));

    myADD->show();
}

void MainWindow::verifyRemoveMeetingPa(const string _title, const string _paticipator)
{
    qDebug()<< __FUNCTION__ << "connected\n";
    if (myService.removeMeetingParticipator(this->userName, _title, _paticipator))
    {
        QMessageBox message(QMessageBox::NoIcon, "Succeed", "Paticipator Removed!");
        message.exec();
        emit ADsucceed();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "Remove Paticipator Fail!");
        message.exec();
        emit ADfail();
    }
}


void MainWindow::quitMeeting(void)
{
    auto am = myService.listAllMeetings(this->userName);
    QStringList list;
    for (auto it_ = am.begin(); it_ != am.end(); it_++)
            list << QString::fromStdString(it_->getTitle());
    bool ok;
    QString meetingTitle = QInputDialog::getItem(this, "Meeting Title",
                                                "Please input a Meeting title to quit.",
                                                list, 0, false, &ok);
qDebug() << meetingTitle;
    if(ok)
    {
        if (myService.quitMeeting(this->userName, meetingTitle.toStdString()))
        {
            QMessageBox message(QMessageBox::NoIcon, "Succeed", "quited Meeting!");
            message.exec();
        }
        else
        {
            QMessageBox message(QMessageBox::NoIcon, "Error", "quit Meeting Fail!");
            message.exec();
        }
    }
}

//in MainWindow.cpp
void MainWindow::listAllMeetings(void)
{
    QString title = "Your ( " + QString::fromStdString(userName) + " ) all meetings : ";
    printMeetings(myService.listAllMeetings(userName), title);
}


void MainWindow::listAllSponsorMeetings(void)
{
    QString title = "Your ( " + QString::fromStdString(userName) + " ) sponser meetings : ";
    printMeetings(myService.listAllSponsorMeetings(userName), title);
}


void MainWindow::listAllParticipateMeetings(void)
{
    QString title = "Your ( " + QString::fromStdString(userName) + " ) paticipator meetings : ";
    printMeetings(myService.listAllParticipateMeetings(userName), title);
}


void MainWindow::queryMeetingByTitle(void)
{
    auto am = myService.listAllMeetings(this->userName);
    QStringList list;
    for (auto it_ = am.begin(); it_ != am.end(); it_++)
            list << QString::fromStdString(it_->getTitle());
    bool ok;
    QString meetingTitle = QInputDialog::getItem(this, "Meeting Title",
                                                "Please input a Meeting title to query.",
                                                list, 0, false, &ok);
    if(ok)
        printMeetings(myService.meetingQuery(userName, meetingTitle.toStdString()), "query meetings by title");
}

void MainWindow::queryMeetingByTimeInterval(void)
{
    this->hide();
    myQT = new QTimeDialog();
    myQT->setWindowTitle("Query Meeting by Time");

    QObject::connect( &(*myQT), SIGNAL(timeInfo(string,string)),
                      &(*this), SLOT(verifyQueryMeetingTime(string,string)));
    QObject::connect( &(*myQT), SIGNAL(showMenu()), &(*this), SLOT(show()));
    QObject::connect( &(*myQT), SIGNAL(showMenu()), &(*myQT), SLOT(close()));

    myQT->show();
}

void MainWindow::verifyQueryMeetingTime(const string startDate, const string endDate)
{
    qDebug()<< __FUNCTION__ << "connected\n";
    printMeetings(myService.meetingQuery(userName, startDate, endDate), "Meetings");
}

void MainWindow::deleteMeetingByTitle(void)
{
    auto am = myService.listAllMeetings(this->userName);
    QStringList list;
    for (auto it_ = am.begin(); it_ != am.end(); it_++)
            list << QString::fromStdString(it_->getTitle());
    bool ok;
    QString meetingTitle = QInputDialog::getItem(this, "Meeting Title",
                                                "Please input a Meeting title to delete.",
                                                list, 0, false, &ok);
    if(ok)
    {
        if (myService.deleteMeeting(this->userName, meetingTitle.toStdString()))
        {
            QMessageBox message(QMessageBox::NoIcon, "Succeed", "deleted Meeting!");
            message.exec();
        }
        else
        {
            QMessageBox message(QMessageBox::NoIcon, "Error", "delete Meeting Fail!\n");
            message.exec();
        }
    }
}

void MainWindow::deleteAllMeetings(void)
{
    if(myService.deleteAllMeetings(userName))
    {
        QMessageBox message(QMessageBox::NoIcon, "Succeed",
                            "deleted all meetings!\n you are totally free now");
        message.exec();
    }
    else
    {
        QMessageBox message(QMessageBox::NoIcon, "Error", "you are aready totally free ");
        message.exec();
    }
}

void MainWindow::printMeetings(const list<Meeting>& meeting, const QString title)
{
    int row = meeting.size();
    QTableWidget *table = new QTableWidget(row,5);
    table->setWindowTitle(title);
    //设置表格行标题
    QStringList headerLabels;
    headerLabels << "Title" << "Sponsor" << "Start date" << "End date" << "Participator";
    table->setHorizontalHeaderLabels(headerLabels);

    //设置表格行标题的对齐方式
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    //设置行表题
    QStringList rowLabels;
    for (int i = 0; i < row; i++)
    {
        QString label = "Meeting";
        stringstream ss;
        ss << (i + 1);
        label += QString::fromStdString(ss.str());
        rowLabels << label;
    }
    table->setVerticalHeaderLabels(rowLabels);

    //设置每一行的高度
    for(int i = 0; i < 4; i++)
        table->setRowHeight(i, 27);


    //自动调整最后一列的宽度使它和表格的右边界对齐
    table->horizontalHeader()->setStretchLastSection(true);

    //设置表格的选择方式
    table->setSelectionBehavior(QAbstractItemView::SelectItems);

    //设置编辑方式
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表格的内容
    int i = 0;
    for (auto it_ = meeting.begin(); it_ != meeting.end(); it_++, i++)
    {
        table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(it_->getTitle())));
        table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(it_->getSponsor())));
        table->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(Date::dateToString(it_->getStartDate()))));
        table->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(Date::dateToString(it_->getEndDate()))));

        auto _pa = it_->getParticipator();
        QString pa = "";
        for (unsigned int j = 0; j < _pa.size();)
        {
            qDebug() << QString::fromStdString(_pa[j]);
            pa += QString::fromStdString(_pa[j]);
            if (j++ != _pa.size()) pa += ", ";
        }
        table->setItem(i, 2, new QTableWidgetItem(pa));
    }
    table->setWindowTitle("Meetings");
    table->resizeColumnsToContents();
    table->setFixedSize(600, 300);
    table->show();
}
