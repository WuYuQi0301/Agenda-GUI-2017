#include "mainwindow.h"
#include "welcomedialog.h"
#include "logindialog.h"
#include "registerdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WelcomeDialog myWelcome;
    LoginDialog myLogin;
    RegisterDialog myRegister;

    QObject::connect(&w, SIGNAL(quitSystem()), &a, SLOT(quit()));

    QObject::connect(&w, SIGNAL(showLogin()), &myLogin, SLOT(show()));
    QObject::connect(&w, SIGNAL(loginSucceed()), &myLogin, SLOT(hide()));
    QObject::connect(&w, SIGNAL(showLogin()), &myLogin, SLOT(clearInput()));
    QObject::connect(&w, SIGNAL(loginSucceed()), &myLogin, SLOT(clearInput()));

    QObject::connect(&w, SIGNAL(loginSucceed()), &myWelcome, SLOT(hide()));
    QObject::connect(&w, SIGNAL(registerSucceed()), &myWelcome, SLOT(hide()));
    QObject::connect(&w, SIGNAL(showWelcome()), &myWelcome, SLOT(show()));

    QObject::connect(&w, SIGNAL(showRegister()), &myRegister, SLOT(show()));
    QObject::connect(&w, SIGNAL(registerSucceed()), &myRegister, SLOT(hide()));


    QObject::connect(&myLogin, SIGNAL(showWelcome()), &myWelcome, SLOT(show()));
    QObject::connect(&myLogin, SIGNAL(loginInfo(QString,QString)), &w, SLOT(verifyLogin(QString,QString)));


    QObject::connect(&myRegister, SIGNAL(showWelcome()), &myWelcome, SLOT(show()));
    QObject::connect(&myRegister, SIGNAL(registerInfo(QString,QString,QString,QString)),
                     &w, SLOT(verifyRegister(QString,QString,QString,QString)));
    //in main.cpp
    QObject::connect(&myWelcome, SIGNAL(command(int)), &w, SLOT(receiveCommand(int)));

    myWelcome.show();
    return a.exec();
}
