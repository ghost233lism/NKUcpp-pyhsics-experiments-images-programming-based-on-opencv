/********************************************************************************
** Form generated from reading UI file 'help_doc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_DOC_H
#define UI_HELP_DOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help_docClass
{
public:

    void setupUi(QWidget *help_docClass)
    {
        if (help_docClass->objectName().isEmpty())
            help_docClass->setObjectName("help_docClass");
        help_docClass->resize(600, 400);

        retranslateUi(help_docClass);

        QMetaObject::connectSlotsByName(help_docClass);
    } // setupUi

    void retranslateUi(QWidget *help_docClass)
    {
        help_docClass->setWindowTitle(QCoreApplication::translate("help_docClass", "help_doc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help_docClass: public Ui_help_docClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_DOC_H
