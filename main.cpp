#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDirModel>
#include <QListWidget>
#include <QModelIndex>
#include <QSplitter>
#include <QTreeView>
static const QStringList LIST_ITEMS =
    QStringList() << "Користувачі" << "Журнал аудиту" << "Доступ до ресурсів" << "Процеси" << "Sudo" ;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget* desktopWidget = a.desktop();
    QRect screenGeometry = desktopWidget->screenGeometry();
    int x = (screenGeometry.width()-w.width()) / 2;
    int y = (screenGeometry.height()-w.height()) / 2;
    w.move(x,y);
    w.show();

    return a.exec();
}
