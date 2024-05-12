/********************************************************************************
** Form generated from reading UI file 'Welcome.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeClass
{
public:
    QLabel *welcome;

    void setupUi(QWidget *WelcomeClass)
    {
        if (WelcomeClass->objectName().isEmpty())
            WelcomeClass->setObjectName("WelcomeClass");
        WelcomeClass->resize(1400, 980);
        WelcomeClass->setMaximumSize(QSize(1400, 980));
        welcome = new QLabel(WelcomeClass);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(0, 0, 1400, 980));
        welcome->setMaximumSize(QSize(1400, 980));

        retranslateUi(WelcomeClass);

        QMetaObject::connectSlotsByName(WelcomeClass);
    } // setupUi

    void retranslateUi(QWidget *WelcomeClass)
    {
        WelcomeClass->setWindowTitle(QCoreApplication::translate("WelcomeClass", "Welcome", nullptr));
        welcome->setText(QCoreApplication::translate("WelcomeClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeClass: public Ui_WelcomeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
