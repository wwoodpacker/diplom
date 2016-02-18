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
    /*QSplitter *splitter = new QSplitter;
    QDirModel *model = new QDirModel;
    QListView *list = new QListView(splitter);
         list->setModel(model);
         list->setRootIndex(model->index(QDir::currentPath()));
         splitter->setWindowTitle("Two views onto the same directory model");
             splitter->show();
*/
    w.show();

    return a.exec();
}
