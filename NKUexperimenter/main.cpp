#include "NKUexperimenter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NKUexperimenter w;
    w.show();
    return a.exec();
}
