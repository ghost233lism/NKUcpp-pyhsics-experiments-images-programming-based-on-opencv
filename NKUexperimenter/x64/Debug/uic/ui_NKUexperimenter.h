/********************************************************************************
** Form generated from reading UI file 'NKUexperimenter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NKUEXPERIMENTER_H
#define UI_NKUEXPERIMENTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NKUexperimenterClass
{
public:
    QAction *newFile;
    QAction *saveCanny;
    QAction *saveRotate;
    QAction *saveErase;
    QAction *helpDocument;
    QAction *actionForMoreHelp;
    QAction *actionCuda;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *buttonNew;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonUpload;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonGenerate;
    QSpacerItem *verticalSpacer_3;
    QPushButton *buttonRetry;
    QSpacerItem *verticalSpacer_4;
    QPushButton *buttonErase;
    QSpacerItem *verticalSpacer_5;
    QPushButton *buttonDownload;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    QLabel *imgOriginal;
    QLabel *showOriginal;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QLabel *showRotate;
    QSpacerItem *horizontalSpacer_3;
    QLabel *showCanny;
    QSpacerItem *horizontalSpacer_4;
    QLabel *imgErase;
    QLabel *imgEdge;
    QLabel *imgRotate;
    QSpacerItem *horizontalSpacer_2;
    QLabel *showErase;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *setMenu;
    QMenu *helpMenu;

    void setupUi(QMainWindow *NKUexperimenterClass)
    {
        if (NKUexperimenterClass->objectName().isEmpty())
            NKUexperimenterClass->setObjectName("NKUexperimenterClass");
        NKUexperimenterClass->resize(574, 310);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NKUexperimenterClass->sizePolicy().hasHeightForWidth());
        NKUexperimenterClass->setSizePolicy(sizePolicy);
        NKUexperimenterClass->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: white; \n"
"}"));
        newFile = new QAction(NKUexperimenterClass);
        newFile->setObjectName("newFile");
        saveCanny = new QAction(NKUexperimenterClass);
        saveCanny->setObjectName("saveCanny");
        saveRotate = new QAction(NKUexperimenterClass);
        saveRotate->setObjectName("saveRotate");
        saveErase = new QAction(NKUexperimenterClass);
        saveErase->setObjectName("saveErase");
        helpDocument = new QAction(NKUexperimenterClass);
        helpDocument->setObjectName("helpDocument");
        actionForMoreHelp = new QAction(NKUexperimenterClass);
        actionForMoreHelp->setObjectName("actionForMoreHelp");
        actionCuda = new QAction(NKUexperimenterClass);
        actionCuda->setObjectName("actionCuda");
        centralWidget = new QWidget(NKUexperimenterClass);
        centralWidget->setObjectName("centralWidget");
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #F0FAFA;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        buttonNew = new QPushButton(widget);
        buttonNew->setObjectName("buttonNew");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(buttonNew->sizePolicy().hasHeightForWidth());
        buttonNew->setSizePolicy(sizePolicy1);
        buttonNew->setCursor(QCursor(Qt::OpenHandCursor));
        buttonNew->setAutoFillBackground(false);
        buttonNew->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonNew);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonUpload = new QPushButton(widget);
        buttonUpload->setObjectName("buttonUpload");
        sizePolicy1.setHeightForWidth(buttonUpload->sizePolicy().hasHeightForWidth());
        buttonUpload->setSizePolicy(sizePolicy1);
        buttonUpload->setCursor(QCursor(Qt::OpenHandCursor));
        buttonUpload->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonUpload);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonGenerate = new QPushButton(widget);
        buttonGenerate->setObjectName("buttonGenerate");
        sizePolicy1.setHeightForWidth(buttonGenerate->sizePolicy().hasHeightForWidth());
        buttonGenerate->setSizePolicy(sizePolicy1);
        buttonGenerate->setCursor(QCursor(Qt::OpenHandCursor));
        buttonGenerate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonGenerate);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        buttonRetry = new QPushButton(widget);
        buttonRetry->setObjectName("buttonRetry");
        sizePolicy1.setHeightForWidth(buttonRetry->sizePolicy().hasHeightForWidth());
        buttonRetry->setSizePolicy(sizePolicy1);
        buttonRetry->setCursor(QCursor(Qt::OpenHandCursor));
        buttonRetry->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonRetry);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        buttonErase = new QPushButton(widget);
        buttonErase->setObjectName("buttonErase");
        sizePolicy1.setHeightForWidth(buttonErase->sizePolicy().hasHeightForWidth());
        buttonErase->setSizePolicy(sizePolicy1);
        buttonErase->setCursor(QCursor(Qt::OpenHandCursor));
        buttonErase->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonErase);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        buttonDownload = new QPushButton(widget);
        buttonDownload->setObjectName("buttonDownload");
        sizePolicy1.setHeightForWidth(buttonDownload->sizePolicy().hasHeightForWidth());
        buttonDownload->setSizePolicy(sizePolicy1);
        buttonDownload->setCursor(QCursor(Qt::OpenHandCursor));
        buttonDownload->setMouseTracking(false);
        buttonDownload->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F0FAFA; /* \344\271\237\345\217\257\344\273\245\344\275\277\347\224\250\345\205\266\344\273\226\351\242\234\350\211\262\346\210\226\345\215\201\345\205\255\350\277\233\345\210\266\345\200\274 */\n"
"	border: 1px solid #F0FAFA; \n"
"}"));

        verticalLayout->addWidget(buttonDownload);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #E6F5EA;\n"
"}"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 4, 1, 1);

        imgOriginal = new QLabel(widget_2);
        imgOriginal->setObjectName("imgOriginal");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(imgOriginal->sizePolicy().hasHeightForWidth());
        imgOriginal->setSizePolicy(sizePolicy2);
        imgOriginal->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: white;\n"
"}"));

        gridLayout->addWidget(imgOriginal, 1, 1, 1, 1);

        showOriginal = new QLabel(widget_2);
        showOriginal->setObjectName("showOriginal");

        gridLayout->addWidget(showOriginal, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        showRotate = new QLabel(widget_2);
        showRotate->setObjectName("showRotate");

        gridLayout->addWidget(showRotate, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        showCanny = new QLabel(widget_2);
        showCanny->setObjectName("showCanny");

        gridLayout->addWidget(showCanny, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        imgErase = new QLabel(widget_2);
        imgErase->setObjectName("imgErase");
        sizePolicy2.setHeightForWidth(imgErase->sizePolicy().hasHeightForWidth());
        imgErase->setSizePolicy(sizePolicy2);
        imgErase->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: white;\n"
"}"));

        gridLayout->addWidget(imgErase, 3, 3, 1, 1);

        imgEdge = new QLabel(widget_2);
        imgEdge->setObjectName("imgEdge");
        sizePolicy2.setHeightForWidth(imgEdge->sizePolicy().hasHeightForWidth());
        imgEdge->setSizePolicy(sizePolicy2);
        imgEdge->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: white;\n"
"}"));

        gridLayout->addWidget(imgEdge, 1, 3, 1, 1);

        imgRotate = new QLabel(widget_2);
        imgRotate->setObjectName("imgRotate");
        sizePolicy2.setHeightForWidth(imgRotate->sizePolicy().hasHeightForWidth());
        imgRotate->setSizePolicy(sizePolicy2);
        imgRotate->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	background-color: white;\n"
"}"));

        gridLayout->addWidget(imgRotate, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        showErase = new QLabel(widget_2);
        showErase->setObjectName("showErase");

        gridLayout->addWidget(showErase, 4, 3, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 8, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 8, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_7, 2, 3, 1, 1);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName("widget_3");
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #EBF5DC;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        treeView = new QTreeView(widget_3);
        treeView->setObjectName("treeView");
        treeView->setStyleSheet(QString::fromUtf8("QListWidget\n"
"{\n"
"	background-color: white;\n"
"}"));

        verticalLayout_2->addWidget(treeView);


        horizontalLayout->addWidget(widget_3);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 15);
        horizontalLayout->setStretch(2, 5);
        NKUexperimenterClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(NKUexperimenterClass);
        mainToolBar->setObjectName("mainToolBar");
        NKUexperimenterClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(NKUexperimenterClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 574, 17));
        fileMenu = new QMenu(menuBar);
        fileMenu->setObjectName("fileMenu");
        setMenu = new QMenu(menuBar);
        setMenu->setObjectName("setMenu");
        helpMenu = new QMenu(menuBar);
        helpMenu->setObjectName("helpMenu");
        NKUexperimenterClass->setMenuBar(menuBar);

        menuBar->addAction(fileMenu->menuAction());
        menuBar->addAction(setMenu->menuAction());
        menuBar->addAction(helpMenu->menuAction());
        fileMenu->addAction(newFile);
        fileMenu->addAction(saveCanny);
        fileMenu->addAction(saveRotate);
        fileMenu->addAction(saveErase);
        setMenu->addAction(actionCuda);
        helpMenu->addAction(helpDocument);
        helpMenu->addAction(actionForMoreHelp);

        retranslateUi(NKUexperimenterClass);

        QMetaObject::connectSlotsByName(NKUexperimenterClass);
    } // setupUi

    void retranslateUi(QMainWindow *NKUexperimenterClass)
    {
        NKUexperimenterClass->setWindowTitle(QCoreApplication::translate("NKUexperimenterClass", "NKUexperimenter", nullptr));
        newFile->setText(QCoreApplication::translate("NKUexperimenterClass", "\346\226\260\345\273\272(&N)", nullptr));
        saveCanny->setText(QCoreApplication::translate("NKUexperimenterClass", "\344\277\235\345\255\230\350\276\271\347\274\230\345\233\276", nullptr));
        saveRotate->setText(QCoreApplication::translate("NKUexperimenterClass", "\344\277\235\345\255\230\346\227\213\350\275\254\345\233\276", nullptr));
        saveErase->setText(QCoreApplication::translate("NKUexperimenterClass", "\344\277\235\345\255\230\347\273\223\346\236\234", nullptr));
        helpDocument->setText(QCoreApplication::translate("NKUexperimenterClass", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        actionForMoreHelp->setText(QCoreApplication::translate("NKUexperimenterClass", "For More Help...", nullptr));
        actionCuda->setText(QCoreApplication::translate("NKUexperimenterClass", "\345\205\263\351\227\255cuda\345\212\240\351\200\237", nullptr));
        buttonNew->setText(QString());
        buttonUpload->setText(QString());
        buttonGenerate->setText(QString());
        buttonRetry->setText(QString());
        buttonErase->setText(QString());
        buttonDownload->setText(QString());
        imgOriginal->setText(QString());
        showOriginal->setText(QCoreApplication::translate("NKUexperimenterClass", "<html><head/><body><p align=\"center\">\345\216\237\345\247\213\345\233\276\347\211\207</p></body></html>", nullptr));
        showRotate->setText(QCoreApplication::translate("NKUexperimenterClass", "<html><head/><body><p align=\"center\">\346\227\213\350\275\254\345\220\216\345\233\276\347\211\207\357\274\210\345\217\257\347\202\271\345\207\273\346\214\211\351\222\256\351\207\215\346\226\260\347\224\237\346\210\220\357\274\211</p></body></html>", nullptr));
        showCanny->setText(QCoreApplication::translate("NKUexperimenterClass", "<html><head/><body><p align=\"center\">\350\276\271\347\274\230\346\243\200\346\265\213</p></body></html>", nullptr));
        imgErase->setText(QString());
        imgEdge->setText(QString());
        imgRotate->setText(QString());
        showErase->setText(QCoreApplication::translate("NKUexperimenterClass", "<html><head/><body><p align=\"center\">\347\224\237\346\210\220\347\273\223\346\236\234</p></body></html>", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("NKUexperimenterClass", "\346\226\207\344\273\266(&F)", nullptr));
        setMenu->setTitle(QCoreApplication::translate("NKUexperimenterClass", "\350\256\276\347\275\256(&S)", nullptr));
        helpMenu->setTitle(QCoreApplication::translate("NKUexperimenterClass", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NKUexperimenterClass: public Ui_NKUexperimenterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NKUEXPERIMENTER_H
