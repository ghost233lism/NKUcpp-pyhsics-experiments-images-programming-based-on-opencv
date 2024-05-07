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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
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
    QSpacerItem *horizontalSpacer_2;
    QLabel *imgOriginal;
    QLabel *showErase;
    QLabel *imgEdge;
    QLabel *imgRotate;
    QLabel *imgErase;
    QLabel *showCanny;
    QLabel *showOriginal;
    QSpacerItem *horizontalSpacer;
    QLabel *showRotate;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *setMenu;
    QMenu *helpMenu;

    void setupUi(QMainWindow *NKUexperimenterClass)
    {
        if (NKUexperimenterClass->objectName().isEmpty())
            NKUexperimenterClass->setObjectName("NKUexperimenterClass");
        NKUexperimenterClass->resize(602, 424);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NKUexperimenterClass->sizePolicy().hasHeightForWidth());
        NKUexperimenterClass->setSizePolicy(sizePolicy);
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
        buttonNew->setAutoFillBackground(false);

        verticalLayout->addWidget(buttonNew);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonUpload = new QPushButton(widget);
        buttonUpload->setObjectName("buttonUpload");
        sizePolicy1.setHeightForWidth(buttonUpload->sizePolicy().hasHeightForWidth());
        buttonUpload->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(buttonUpload);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonGenerate = new QPushButton(widget);
        buttonGenerate->setObjectName("buttonGenerate");
        sizePolicy1.setHeightForWidth(buttonGenerate->sizePolicy().hasHeightForWidth());
        buttonGenerate->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(buttonGenerate);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        buttonRetry = new QPushButton(widget);
        buttonRetry->setObjectName("buttonRetry");
        sizePolicy1.setHeightForWidth(buttonRetry->sizePolicy().hasHeightForWidth());
        buttonRetry->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(buttonRetry);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        buttonErase = new QPushButton(widget);
        buttonErase->setObjectName("buttonErase");
        sizePolicy1.setHeightForWidth(buttonErase->sizePolicy().hasHeightForWidth());
        buttonErase->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(buttonErase);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        buttonDownload = new QPushButton(widget);
        buttonDownload->setObjectName("buttonDownload");
        sizePolicy1.setHeightForWidth(buttonDownload->sizePolicy().hasHeightForWidth());
        buttonDownload->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(buttonDownload);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        imgOriginal = new QLabel(widget_2);
        imgOriginal->setObjectName("imgOriginal");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(imgOriginal->sizePolicy().hasHeightForWidth());
        imgOriginal->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(imgOriginal, 1, 1, 1, 1);

        showErase = new QLabel(widget_2);
        showErase->setObjectName("showErase");

        gridLayout->addWidget(showErase, 3, 3, 1, 1);

        imgEdge = new QLabel(widget_2);
        imgEdge->setObjectName("imgEdge");
        sizePolicy2.setHeightForWidth(imgEdge->sizePolicy().hasHeightForWidth());
        imgEdge->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(imgEdge, 1, 3, 1, 1);

        imgRotate = new QLabel(widget_2);
        imgRotate->setObjectName("imgRotate");
        sizePolicy2.setHeightForWidth(imgRotate->sizePolicy().hasHeightForWidth());
        imgRotate->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(imgRotate, 2, 1, 1, 1);

        imgErase = new QLabel(widget_2);
        imgErase->setObjectName("imgErase");
        sizePolicy2.setHeightForWidth(imgErase->sizePolicy().hasHeightForWidth());
        imgErase->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(imgErase, 2, 3, 1, 1);

        showCanny = new QLabel(widget_2);
        showCanny->setObjectName("showCanny");

        gridLayout->addWidget(showCanny, 0, 3, 1, 1);

        showOriginal = new QLabel(widget_2);
        showOriginal->setObjectName("showOriginal");

        gridLayout->addWidget(showOriginal, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        showRotate = new QLabel(widget_2);
        showRotate->setObjectName("showRotate");

        gridLayout->addWidget(showRotate, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 4, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 4, 1, 1);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName("widget_3");
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        listWidget = new QListWidget(widget_3);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout->addWidget(widget_3);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 15);
        horizontalLayout->setStretch(2, 4);
        NKUexperimenterClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(NKUexperimenterClass);
        mainToolBar->setObjectName("mainToolBar");
        NKUexperimenterClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(NKUexperimenterClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 602, 17));
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
        buttonNew->setText(QCoreApplication::translate("NKUexperimenterClass", "New", nullptr));
        buttonUpload->setText(QCoreApplication::translate("NKUexperimenterClass", "Upload", nullptr));
        buttonGenerate->setText(QCoreApplication::translate("NKUexperimenterClass", "Generate", nullptr));
        buttonRetry->setText(QCoreApplication::translate("NKUexperimenterClass", "Retry", nullptr));
        buttonErase->setText(QCoreApplication::translate("NKUexperimenterClass", "Erase", nullptr));
        buttonDownload->setText(QCoreApplication::translate("NKUexperimenterClass", "Download", nullptr));
        imgOriginal->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        showErase->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        imgEdge->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        imgRotate->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        imgErase->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        showCanny->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        showOriginal->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
        showRotate->setText(QCoreApplication::translate("NKUexperimenterClass", "TextLabel", nullptr));
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
