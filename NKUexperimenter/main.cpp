#include "NKUexperimenter.h"
#include <QtWidgets/QApplication>
#include "Welcome.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    
    QApplication app(argc, argv);
    QIcon appIcon("icon/avatar.png");
    app.setWindowIcon(appIcon);
    // 创建第一个窗口实例
    Welcome firstWindow;
    NKUexperimenter secondWindow;
    firstWindow.show();

    // 创建一个计时器
    QTimer::singleShot(5000, &firstWindow, [&firstWindow, &secondWindow]()
        {
            // 3秒后关闭第一个窗口
            firstWindow.close();
            // 创建并显示第二个窗口

            secondWindow.show();
        });

    return app.exec();
}
