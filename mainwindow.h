#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDirModel>
#include <QListWidget>
#include <QMainWindow>
#include <QSplitter>
#include <QTreeView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSplitter *splitter;
    QDirModel *model ;
    QTreeView *Treelist;
public slots:
    void myItemAction(QListWidgetItem *item);
    void onCustomContextMenu(const QPoint &point);
};

#endif // MAINWINDOW_H
