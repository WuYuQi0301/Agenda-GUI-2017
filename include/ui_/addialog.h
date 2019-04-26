#ifndef ADDIALOG_H
#define ADDIALOG_H

#include "ui_ADDialog.h"
#include <QDialog>
#include "Meeting.hpp"
#include "User.hpp"
#include <list>
#include <QString>
#include <string>
using std::list;
using std::string;


namespace Ui{
class ADDialog;
}

class ADDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ADDialog(const list<Meeting> meeting,const list<User> users, QWidget *parent = 0);
    ~ADDialog();
    void setWTitle(const QString& str);

private slots:
    void on_returnButtom_clicked();

    void on_comfirmButton_clicked();

signals:
    void showMenu();
    void meetingInfo(const string, const string);

private:
    Ui::ADDialog *ui;
};


#endif // ADDIALOG_H
