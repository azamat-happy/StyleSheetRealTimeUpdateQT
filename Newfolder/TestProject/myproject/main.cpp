#include <QApplication>
#include <QQuickWindow>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Установка значений organizationName и applicationName
    QCoreApplication::setOrganizationName("YourOrganization");
    QCoreApplication::setApplicationName("YourApplication");
    QApplication a(argc, argv);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
#endif
    CMainWindow w;
    w.show();
    return a.exec();
}
