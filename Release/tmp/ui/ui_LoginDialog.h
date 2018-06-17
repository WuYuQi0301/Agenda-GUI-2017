/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *ComfirmButton;
    QPushButton *ReturnBottom;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        groupBox = new QGroupBox(LoginDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 30, 311, 221));
        groupBox->setStyleSheet(QStringLiteral("font: 75 18pt \"Century Gothic\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 91, 21));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 101, 31));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        ComfirmButton = new QPushButton(groupBox);
        ComfirmButton->setObjectName(QStringLiteral("ComfirmButton"));
        ComfirmButton->setGeometry(QRect(40, 170, 81, 31));
        ComfirmButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        ReturnBottom = new QPushButton(groupBox);
        ReturnBottom->setObjectName(QStringLiteral("ReturnBottom"));
        ReturnBottom->setGeometry(QRect(180, 170, 81, 31));
        ReturnBottom->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        usernameLineEdit = new QLineEdit(groupBox);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(130, 60, 141, 21));
        usernameLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(130, 110, 141, 21));
        passwordLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", 0));
        groupBox->setTitle(QApplication::translate("LoginDialog", "Input Info", 0));
        label->setText(QApplication::translate("LoginDialog", "UserName", 0));
        label_2->setText(QApplication::translate("LoginDialog", "Password", 0));
        ComfirmButton->setText(QApplication::translate("LoginDialog", "Comfirm", 0));
        ReturnBottom->setText(QApplication::translate("LoginDialog", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
