#ifndef QTIMEDISLOG_H
#define QTIMEDISLOG_H

#include "ui_QTimeDailog.h"
#include "Meeting.hpp"
#include "User.hpp"
#include <QDialog>
#include <QString>
#include <string>
#include <list>
using std::list;
using std::string;


namespace Ui{
class QTimeDialog;
}

class QTimeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QTimeDialog(QWidget *parent = 0);
    ~QTimeDialog();
    void setWTitle(const QString& str);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void showMenu();
    void timeInfo(const string, const string);

private:
    Ui::QTimeDialog *ui;
};


#endif // QTIMEDISLOG_H
