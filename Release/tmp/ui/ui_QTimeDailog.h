/********************************************************************************
** Form generated from reading UI file 'QTimeDailog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTIMEDAILOG_H
#define UI_QTIMEDAILOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QTimeDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QDateTimeEdit *startDateTimeEdit;
    QDateTimeEdit *endDateTimeEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *QTimeDialog)
    {
        if (QTimeDialog->objectName().isEmpty())
            QTimeDialog->setObjectName(QStringLiteral("QTimeDialog"));
        QTimeDialog->resize(400, 300);
        groupBox = new QGroupBox(QTimeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 30, 311, 191));
        groupBox->setStyleSheet(QStringLiteral("font: 75 16pt \"Century Gothic\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 81, 21));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 81, 21));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        startDateTimeEdit = new QDateTimeEdit(groupBox);
        startDateTimeEdit->setObjectName(QStringLiteral("startDateTimeEdit"));
        startDateTimeEdit->setGeometry(QRect(110, 70, 194, 22));
        startDateTimeEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        endDateTimeEdit = new QDateTimeEdit(groupBox);
        endDateTimeEdit->setObjectName(QStringLiteral("endDateTimeEdit"));
        endDateTimeEdit->setGeometry(QRect(110, 140, 194, 22));
        endDateTimeEdit->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        pushButton = new QPushButton(QTimeDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 239, 91, 31));
        pushButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        pushButton_2 = new QPushButton(QTimeDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 239, 81, 31));
        pushButton_2->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));

        retranslateUi(QTimeDialog);

        QMetaObject::connectSlotsByName(QTimeDialog);
    } // setupUi

    void retranslateUi(QDialog *QTimeDialog)
    {
        QTimeDialog->setWindowTitle(QApplication::translate("QTimeDialog", "QTimeDialog", 0));
        groupBox->setTitle(QApplication::translate("QTimeDialog", "Time Info", 0));
        label->setText(QApplication::translate("QTimeDialog", "StartDate", 0));
        label_2->setText(QApplication::translate("QTimeDialog", "EndDate", 0));
        pushButton->setText(QApplication::translate("QTimeDialog", "Comfirm", 0));
        pushButton_2->setText(QApplication::translate("QTimeDialog", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class QTimeDialog: public Ui_QTimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTIMEDAILOG_H
