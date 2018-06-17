/********************************************************************************
** Form generated from reading UI file 'CreateMeetingDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEMEETINGDIALOG_H
#define UI_CREATEMEETINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateMeetingDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *titleLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *startDateEdit;
    QTimeEdit *startTimeEdit;
    QTimeEdit *endTimeEdit;
    QDateEdit *endDateEdit;
    QPushButton *comfirmButton;
    QPushButton *returnButton;
    QLabel *label_4;
    QTableView *userTableView;
    QLabel *label_5;

    void setupUi(QDialog *CreateMeetingDialog)
    {
        if (CreateMeetingDialog->objectName().isEmpty())
            CreateMeetingDialog->setObjectName(QStringLiteral("CreateMeetingDialog"));
        CreateMeetingDialog->resize(664, 334);
        CreateMeetingDialog->setMinimumSize(QSize(400, 300));
        groupBox = new QGroupBox(CreateMeetingDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 611, 281));
        groupBox->setMinimumSize(QSize(371, 271));
        groupBox->setStyleSheet(QStringLiteral("font: 75 18pt \"Century Gothic\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 21));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        titleLineEdit = new QLineEdit(groupBox);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));
        titleLineEdit->setGeometry(QRect(100, 40, 141, 21));
        titleLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 111, 20));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 81, 16));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        startDateEdit = new QDateEdit(groupBox);
        startDateEdit->setObjectName(QStringLiteral("startDateEdit"));
        startDateEdit->setGeometry(QRect(100, 90, 110, 22));
        startDateEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        startTimeEdit = new QTimeEdit(groupBox);
        startTimeEdit->setObjectName(QStringLiteral("startTimeEdit"));
        startTimeEdit->setGeometry(QRect(230, 90, 118, 22));
        startTimeEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        endTimeEdit = new QTimeEdit(groupBox);
        endTimeEdit->setObjectName(QStringLiteral("endTimeEdit"));
        endTimeEdit->setGeometry(QRect(230, 140, 118, 22));
        endTimeEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        endDateEdit = new QDateEdit(groupBox);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));
        endDateEdit->setGeometry(QRect(100, 140, 110, 22));
        endDateEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        comfirmButton = new QPushButton(groupBox);
        comfirmButton->setObjectName(QStringLiteral("comfirmButton"));
        comfirmButton->setGeometry(QRect(60, 210, 81, 31));
        comfirmButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        returnButton = new QPushButton(groupBox);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(240, 210, 91, 31));
        returnButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 20, 131, 41));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        userTableView = new QTableView(groupBox);
        userTableView->setObjectName(QStringLiteral("userTableView"));
        userTableView->setGeometry(QRect(380, 60, 191, 192));
        userTableView->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(380, 260, 231, 20));
        label_5->setStyleSheet(QStringLiteral("font: 14pt \"Aparajita\";"));

        retranslateUi(CreateMeetingDialog);

        QMetaObject::connectSlotsByName(CreateMeetingDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateMeetingDialog)
    {
        CreateMeetingDialog->setWindowTitle(QApplication::translate("CreateMeetingDialog", "CreateMeetingDialog", 0));
        groupBox->setTitle(QApplication::translate("CreateMeetingDialog", "Meeting Info", 0));
        label->setText(QApplication::translate("CreateMeetingDialog", "Title", 0));
        label_2->setText(QApplication::translate("CreateMeetingDialog", "Start date", 0));
        label_3->setText(QApplication::translate("CreateMeetingDialog", "End date", 0));
        comfirmButton->setText(QApplication::translate("CreateMeetingDialog", "Comfirm", 0));
        returnButton->setText(QApplication::translate("CreateMeetingDialog", "Return", 0));
        label_4->setText(QApplication::translate("CreateMeetingDialog", "Participator ", 0));
        label_5->setText(QApplication::translate("CreateMeetingDialog", "perss Ctrl to choose more than one", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateMeetingDialog: public Ui_CreateMeetingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEMEETINGDIALOG_H
