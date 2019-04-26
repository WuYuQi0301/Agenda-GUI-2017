/********************************************************************************
** Form generated from reading UI file 'RegisterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

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

class Ui_RegisterDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneLineEdit;
    QPushButton *comfirmButton;
    QPushButton *returnButtom;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(417, 313);
        groupBox = new QGroupBox(RegisterDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 20, 311, 231));
        groupBox->setStyleSheet(QStringLiteral("font: 75 18pt \"Century Gothic\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 91, 21));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 91, 21));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 140, 81, 21));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 190, 81, 21));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        usernameLineEdit = new QLineEdit(groupBox);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setGeometry(QRect(120, 40, 141, 21));
        usernameLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(120, 90, 141, 21));
        passwordLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        emailLineEdit = new QLineEdit(groupBox);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));
        emailLineEdit->setGeometry(QRect(120, 140, 141, 21));
        emailLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        phoneLineEdit = new QLineEdit(groupBox);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));
        phoneLineEdit->setGeometry(QRect(120, 190, 141, 21));
        phoneLineEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        comfirmButton = new QPushButton(RegisterDialog);
        comfirmButton->setObjectName(QStringLiteral("comfirmButton"));
        comfirmButton->setGeometry(QRect(60, 260, 81, 31));
        comfirmButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        returnButtom = new QPushButton(RegisterDialog);
        returnButtom->setObjectName(QStringLiteral("returnButtom"));
        returnButtom->setGeometry(QRect(260, 260, 81, 31));
        returnButtom->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "RegisterDialog", 0));
        groupBox->setTitle(QApplication::translate("RegisterDialog", "Input Information", 0));
        label->setText(QApplication::translate("RegisterDialog", "userName", 0));
        label_2->setText(QApplication::translate("RegisterDialog", "password", 0));
        label_3->setText(QApplication::translate("RegisterDialog", "E-mail", 0));
        label_4->setText(QApplication::translate("RegisterDialog", "phone", 0));
        comfirmButton->setText(QApplication::translate("RegisterDialog", "Comfirm", 0));
        returnButtom->setText(QApplication::translate("RegisterDialog", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
