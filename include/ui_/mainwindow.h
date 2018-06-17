#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AgendaService.hpp"
#include "createmeetingdialog.h"
#include "addialog.h"
#include "qtimedialog.h"
#include <QMainWindow>
#include <string>
#include <vector>
#include <QInputDialog>
using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //in MainWindow
    //receive command from welcome dialog
    void receiveCommand(const int& command);
    //receive user login info from login dialog
    void verifyLogin(const QString userName, const QString password);
    //receive register info from register dialog
    void verifyRegister(const QString, const QString, const QString, const QString);
    //build comboBox
    void buildComboBox();

private slots:
    //in MainWindow.hpp
    //verify CM
    void verifyCreateMeeting(const string _title, const string _startDate,
                             const string _endDate, const vector<string> pa);
    //verify AMP
    void verifyAddMeetingPa(const string _title, const string _paticpator);
    //verify RMP
    void verifyRemoveMeetingPa(const string _title, const string _paticipator);
    //verify QT
    void verifyQueryMeetingTime(const string startDate, const string endDate);

    void on_comfirmButton_clicked();

signals:
    void quitSystem();

    void loginSucceed();
    void loginFail();
    void registerFail();
    void registerSucceed();
    void CMsucceed();
    void CMfail();
    void ADsucceed();
    void ADfail();
    void AMPsucceed();

    void showLogin();
    void showRegister();
    void showWelcome();

private:
    Ui::MainWindow *ui;
    AgendaService myService;
    std::string userName;
    std::string password;
    CreateMeetingDialog *myCM;
    ADDialog *myADD;
    QTimeDialog *myQT;

    void executeOperation(const int action);
    void userLogOut(void);

    void quitAgenda(void);

    void deleteUser(void);

    void listAllUsers(void);

    void createMeeting(void);

    void addMeetingParticipator(void);

    void removeMeetingParticipator(void);

    void quitMeeting(void);

    void listAllMeetings(void);

    void listAllSponsorMeetings(void);

    void listAllParticipateMeetings(void);

    void queryMeetingByTitle(void);

    void queryMeetingByTimeInterval(void);

    void deleteMeetingByTitle(void);

    void deleteAllMeetings(void);

    void printMeetings(const list<Meeting>&, const QString);
};

#endif // MAINWINDOW_H
