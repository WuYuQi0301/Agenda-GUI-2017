/********************************************************************************
** Form generated from reading UI file 'ADDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDIALOG_H
#define UI_ADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ADDialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *TitleComboBox;
    QComboBox *paticipatorComboBox;
    QPushButton *comfirmButton;
    QPushButton *returnButtom;

    void setupUi(QDialog *ADDialog)
    {
        if (ADDialog->objectName().isEmpty())
            ADDialog->setObjectName(QStringLiteral("ADDialog"));
        ADDialog->resize(400, 300);
        groupBox = new QGroupBox(ADDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 341, 261));
        groupBox->setStyleSheet(QStringLiteral("font: 75 18pt \"Century Gothic\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 81, 21));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 150, 121, 20));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Britannic Bold\";"));
        TitleComboBox = new QComboBox(groupBox);
        TitleComboBox->setObjectName(QStringLiteral("TitleComboBox"));
        TitleComboBox->setGeometry(QRect(120, 70, 201, 31));
        TitleComboBox->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        paticipatorComboBox = new QComboBox(groupBox);
        paticipatorComboBox->setObjectName(QStringLiteral("paticipatorComboBox"));
        paticipatorComboBox->setGeometry(QRect(120, 150, 201, 31));
        paticipatorComboBox->setStyleSheet(QStringLiteral("font: 11pt \"Batang\";"));
        comfirmButton = new QPushButton(groupBox);
        comfirmButton->setObjectName(QStringLiteral("comfirmButton"));
        comfirmButton->setGeometry(QRect(40, 212, 81, 31));
        comfirmButton->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));
        returnButtom = new QPushButton(groupBox);
        returnButtom->setObjectName(QStringLiteral("returnButtom"));
        returnButtom->setGeometry(QRect(230, 210, 81, 31));
        returnButtom->setStyleSheet(QStringLiteral("font: 12pt \"Bell MT\";"));

        retranslateUi(ADDialog);

        QMetaObject::connectSlotsByName(ADDialog);
    } // setupUi

    void retranslateUi(QDialog *ADDialog)
    {
        ADDialog->setWindowTitle(QApplication::translate("ADDialog", "ADDialog", 0));
        groupBox->setTitle(QApplication::translate("ADDialog", "Select ", 0));
        label->setText(QApplication::translate("ADDialog", "Title", 0));
        label_2->setText(QApplication::translate("ADDialog", "Paticipator", 0));
        comfirmButton->setText(QApplication::translate("ADDialog", "Comfirm", 0));
        returnButtom->setText(QApplication::translate("ADDialog", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class ADDialog: public Ui_ADDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDIALOG_H
