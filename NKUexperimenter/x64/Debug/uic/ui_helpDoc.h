/********************************************************************************
** Form generated from reading UI file 'helpDoc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDOC_H
#define UI_HELPDOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpDocClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *helpDocClass)
    {
        if (helpDocClass->objectName().isEmpty())
            helpDocClass->setObjectName("helpDocClass");
        helpDocClass->resize(1000, 800);
        centralWidget = new QWidget(helpDocClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1000, 800));
        helpDocClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(helpDocClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1000, 17));
        helpDocClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(helpDocClass);
        mainToolBar->setObjectName("mainToolBar");
        helpDocClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(helpDocClass);
        statusBar->setObjectName("statusBar");
        helpDocClass->setStatusBar(statusBar);

        retranslateUi(helpDocClass);

        QMetaObject::connectSlotsByName(helpDocClass);
    } // setupUi

    void retranslateUi(QMainWindow *helpDocClass)
    {
        helpDocClass->setWindowTitle(QCoreApplication::translate("helpDocClass", "helpDoc", nullptr));
        label->setText(QCoreApplication::translate("helpDocClass", "<html><head/><body><p><span style=\" font-size:36pt;\">NKU-Experimenter vbeta \344\275\277\347\224\250\346\226\207\346\241\243\357\274\232</span></p><p align=\"justify\"><br/><span style=\" font-size:24pt;\">\347\273\204\344\273\266\350\247\243\351\207\212\357\274\232</span></p><p align=\"justify\"><span style=\" font-size:22pt;\">\346\214\211\351\222\256\357\274\210\345\267\246\344\276\247\344\273\216\344\270\212\345\210\260\344\270\213\357\274\211</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\346\226\260\345\273\272\357\274\232\346\226\260\345\273\272\344\270\200\344\270\252\347\252\227\345\217\243\357\274\214\346\234\200\345\244\232\345\205\201\350\256\270\345\220\214\346\227\266\345\255\230\345\234\2505\344\270\252\347\252\227\345\217\243</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\344\270\212\344\274\240\357\274\232\344\270\212\344\274\240\344\275\240\346\203\263\350\246\201\345\244\204\347\220\206\347\232\204\345\233\276\347\211\207</span></p><p align=\"justify\"><"
                        "span style=\" font-size:14pt;\">\347\224\237\346\210\220\357\274\232\347\224\237\346\210\220\350\276\271\347\274\230\346\243\200\346\265\213\345\233\276\345\222\214\346\227\213\350\275\254\345\220\216\347\232\204\345\233\276\347\211\207</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\351\207\215\350\257\225\357\274\232\351\207\215\346\226\260\346\227\213\350\275\254\357\274\214\345\246\202\346\236\234\347\202\271\345\207\273\345\220\216\346\227\213\350\275\254\345\233\276\346\227\240\346\263\225\346\224\271\345\217\230\357\274\214\345\210\231\347\250\213\345\272\217\350\256\244\344\270\272\345\275\223\345\211\215\345\267\262\347\273\217\346\230\257\346\234\200\345\245\275\346\225\210\346\236\234\357\274\214\345\273\272\350\256\256\344\270\215\350\246\201\344\270\212\344\274\240\345\200\276\346\226\234\350\247\222\345\272\246\350\277\207\345\244\247\347\232\204\345\233\276\347\211\207</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\346\223\246\351\231\244\357\274\232\346\223\246"
                        "\351\231\244\345\233\276\347\211\207\344\270\255\347\232\204\346\226\207\345\255\227</span></p><p align=\"justify\"><span style=\" font-size:14pt;\">\344\277\235\345\255\230\357\274\232\344\277\235\345\255\230\346\223\246\351\231\244\346\226\207\345\255\227\345\220\216\347\232\204\345\233\276\347\211\207\357\274\214\345\246\202\344\270\215\346\203\263\346\223\246\351\231\244\346\226\207\345\255\227\357\274\214\345\217\257\344\273\245\347\202\271\345\207\273\345\267\246\344\270\212\350\247\222\346\226\207\344\273\266\357\274\214\351\200\211\346\213\251\344\275\240\346\203\263\344\277\235\345\255\230\347\232\204\345\233\276\347\211\207\343\200\202</span></p><p align=\"justify\"><span style=\" font-size:14pt; font-weight:700;\">\350\257\267\344\276\235\346\254\241\347\202\271\345\207\273\344\270\212\344\274\240\343\200\201\347\224\237\346\210\220\343\200\201\351\207\215\350\257\225\357\274\210\345\217\257\350\267\263\350\277\207\357\274\211\343\200\201\346\223\246\351\231\244\343\200\201\344\277\235\345\255\230</"
                        "span></p><p align=\"justify\"><span style=\" font-size:22pt;\">\344\270\255\351\227\264\345\233\276\347\211\207\346\230\276\347\244\272\345\214\272\345\237\237</span></p><p align=\"justify\"><span style=\" font-size:16pt;\">\345\210\206\345\210\253\344\270\272\345\216\237\345\233\276\343\200\201\350\276\271\347\274\230\346\243\200\346\265\213\345\233\276\343\200\201\346\227\213\350\275\254\345\220\216\345\233\276\347\211\207\343\200\201\346\223\246\351\231\244\346\226\207\345\255\227\345\220\216\345\233\276\347\211\207</span></p><p align=\"justify\"><span style=\" font-size:22pt;\">\345\217\263\344\276\247\346\226\207\344\273\266\345\214\272</span></p><p align=\"justify\"><span style=\" font-size:16pt;\">\345\217\214\345\207\273\345\233\276\347\211\207\345\215\263\345\217\257\344\270\212\344\274\240</span><br/></p><p align=\"justify\"><span style=\" font-size:28pt;\">beta\347\211\210\346\234\254\351\201\227\347\225\231\351\227\256\351\242\230\357\274\232</span></p><p align=\"justify\"><span style=\" font-size:"
                        "16pt;\">\345\234\250\346\213\226\346\213\275\346\224\271\345\217\230\347\252\227\345\217\243\345\244\247\345\260\217\347\232\204\346\227\266\345\200\231\357\274\214\345\217\257\350\203\275\344\274\232\344\272\247\347\224\237\347\273\204\344\273\266\350\207\252\345\212\250\346\211\251\345\244\247\347\232\204bug\357\274\214\350\257\267\344\275\277\347\224\250\345\217\263\344\270\212\350\247\222\346\234\200\345\244\247\345\214\226\347\232\204\346\226\271\345\274\217\346\224\276\345\244\247\347\252\227\345\217\243\357\274\214</span></p><p align=\"justify\"><span style=\" font-size:16pt;\">\345\220\216\347\273\255\347\232\204\347\211\210\346\234\254\344\274\232\350\277\233\350\241\214\344\277\256\346\224\271\343\200\202</span></p><p align=\"justify\"><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpDocClass: public Ui_helpDocClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDOC_H
