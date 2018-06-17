#ifndef CREATEMEETINGDAILOG_H
#define CREATEMEETINGDAILOG_H

#include "ui_CreateMeetingDialog.h"
#include "User.hpp"
#include <list>
#include <string>
#include <vector>
#include <QDialog>
using std::string;
using std::vector;

namespace Ui{
class CreateMeetingDialog;
}

class CreateMeetingDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CreateMeetingDialog(const std::list<User> &au, QWidget *parent = 0);
    ~CreateMeetingDialog();

private slots:
//    void on_comfirmButton_clicked();

    void on_comfirmButton_clicked();

    void on_returnButton_clicked();

signals:
    //in CreateMeeting.cpp
    void meetingInfo(const string, const string, const string, const vector<string> row);
    void showMenu();
private:
    Ui::CreateMeetingDialog *ui;
};


#endif // CREATEMEETINGDAILOG_H
