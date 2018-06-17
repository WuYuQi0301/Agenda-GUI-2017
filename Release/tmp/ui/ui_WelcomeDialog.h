/********************************************************************************
** Form generated from reading UI file 'WelcomeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEDIALOG_H
#define UI_WELCOMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WelcomeDialog
{
public:
    QLabel *welcome;
    QPushButton *Login;
    QPushButton *RegisterBottom;
    QPushButton *QuitButton;

    void setupUi(QDialog *WelcomeDialog)
    {
        if (WelcomeDialog->objectName().isEmpty())
            WelcomeDialog->setObjectName(QStringLiteral("WelcomeDialog"));
        WelcomeDialog->resize(400, 300);
        WelcomeDialog->setMaximumSize(QSize(400, 300));
        WelcomeDialog->setStyleSheet(QStringLiteral("background-image: url(:/bg.png);"));
        welcome = new QLabel(WelcomeDialog);
        welcome->setObjectName(QStringLiteral("welcome"));
        welcome->setGeometry(QRect(60, 60, 311, 51));
        welcome->setStyleSheet(QStringLiteral("font: 26pt \"Tempus Sans ITC\";"));
        Login = new QPushButton(WelcomeDialog);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(150, 130, 91, 31));
        Login->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        RegisterBottom = new QPushButton(WelcomeDialog);
        RegisterBottom->setObjectName(QStringLiteral("RegisterBottom"));
        RegisterBottom->setGeometry(QRect(149, 180, 91, 31));
        RegisterBottom->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        QuitButton = new QPushButton(WelcomeDialog);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(149, 230, 91, 31));
        QuitButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));

        retranslateUi(WelcomeDialog);

        QMetaObject::connectSlotsByName(WelcomeDialog);
    } // setupUi

    void retranslateUi(QDialog *WelcomeDialog)
    {
        WelcomeDialog->setWindowTitle(QApplication::translate("WelcomeDialog", "WelcomeDialog", 0));
        welcome->setText(QApplication::translate("WelcomeDialog", "Welcome to Agenda", 0));
        Login->setText(QApplication::translate("WelcomeDialog", "Login", 0));
        RegisterBottom->setText(QApplication::translate("WelcomeDialog", "Register", 0));
        QuitButton->setText(QApplication::translate("WelcomeDialog", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class WelcomeDialog: public Ui_WelcomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDIALOG_H
