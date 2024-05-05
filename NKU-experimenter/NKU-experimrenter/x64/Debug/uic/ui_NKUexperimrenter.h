/********************************************************************************
** Form generated from reading UI file 'NKUexperimrenter.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NKUEXPERIMRENTER_H
#define UI_NKUEXPERIMRENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NKUexperimrenterClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NKUexperimrenterClass)
    {
        if (NKUexperimrenterClass->objectName().isEmpty())
            NKUexperimrenterClass->setObjectName("NKUexperimrenterClass");
        NKUexperimrenterClass->resize(600, 400);
        menuBar = new QMenuBar(NKUexperimrenterClass);
        menuBar->setObjectName("menuBar");
        NKUexperimrenterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NKUexperimrenterClass);
        mainToolBar->setObjectName("mainToolBar");
        NKUexperimrenterClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NKUexperimrenterClass);
        centralWidget->setObjectName("centralWidget");
        NKUexperimrenterClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NKUexperimrenterClass);
        statusBar->setObjectName("statusBar");
        NKUexperimrenterClass->setStatusBar(statusBar);

        retranslateUi(NKUexperimrenterClass);

        QMetaObject::connectSlotsByName(NKUexperimrenterClass);
    } // setupUi

    void retranslateUi(QMainWindow *NKUexperimrenterClass)
    {
        NKUexperimrenterClass->setWindowTitle(QCoreApplication::translate("NKUexperimrenterClass", "NKUexperimrenter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NKUexperimrenterClass: public Ui_NKUexperimrenterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NKUEXPERIMRENTER_H
