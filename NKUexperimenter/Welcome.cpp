#include "Welcome.h"
#include <QTimer>

Welcome::Welcome(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    QLabel* welcome = this->findChild<QLabel*>("welcome");
    QPixmap pixmapWelcome("icon/welcome.png"); // 原始图片路径
    welcome->setPixmap(pixmapWelcome);
    
}

Welcome::~Welcome()
{}
