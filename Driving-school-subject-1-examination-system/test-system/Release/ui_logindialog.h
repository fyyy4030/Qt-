/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *passwordlabel_2;
    QLineEdit *accountlineEdit;
    QLineEdit *passwordlineEdit;
    QPushButton *landingpushButton;
    QPushButton *pushButton_2;
    QLabel *accountlabel_3;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(468, 295);
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 471, 301));
        label->setPixmap(QPixmap(QString::fromUtf8(":/H1A@R}L}~`]691A(Z0F_SUC.jpg")));
        passwordlabel_2 = new QLabel(LoginDialog);
        passwordlabel_2->setObjectName(QString::fromUtf8("passwordlabel_2"));
        passwordlabel_2->setGeometry(QRect(150, 110, 31, 16));
        accountlineEdit = new QLineEdit(LoginDialog);
        accountlineEdit->setObjectName(QString::fromUtf8("accountlineEdit"));
        accountlineEdit->setGeometry(QRect(190, 80, 121, 21));
        passwordlineEdit = new QLineEdit(LoginDialog);
        passwordlineEdit->setObjectName(QString::fromUtf8("passwordlineEdit"));
        passwordlineEdit->setGeometry(QRect(190, 110, 121, 21));
        passwordlineEdit->setEchoMode(QLineEdit::Password);
        landingpushButton = new QPushButton(LoginDialog);
        landingpushButton->setObjectName(QString::fromUtf8("landingpushButton"));
        landingpushButton->setGeometry(QRect(130, 200, 71, 31));
        pushButton_2 = new QPushButton(LoginDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 200, 71, 31));
        accountlabel_3 = new QLabel(LoginDialog);
        accountlabel_3->setObjectName(QString::fromUtf8("accountlabel_3"));
        accountlabel_3->setGeometry(QRect(150, 80, 31, 16));
        QWidget::setTabOrder(accountlineEdit, passwordlineEdit);
        QWidget::setTabOrder(passwordlineEdit, pushButton_2);
        QWidget::setTabOrder(pushButton_2, landingpushButton);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "LoginDialog", nullptr));
        label->setText(QString());
        passwordlabel_2->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        landingpushButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\351\231\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        accountlabel_3->setText(QCoreApplication::translate("LoginDialog", "\350\264\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
