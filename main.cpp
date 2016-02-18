#include "mainwindow.h"

#include <QApplication>
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


    w.show();

    return a.exec();
}
