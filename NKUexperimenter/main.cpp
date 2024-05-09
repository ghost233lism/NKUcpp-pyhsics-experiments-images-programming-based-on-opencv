#include "NKUexperimenter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon("icon/avatar.png"));
    NKUexperimenter w;
    w.show();
    return a.exec();
}
