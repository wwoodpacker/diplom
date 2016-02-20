#include "processtable.h"
#include "mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QWidget>

ProcessTable::ProcessTable(QWidget *parent) :
    QWidget(parent)
{
    hlayout = new QHBoxLayout;
    button_kill = new QPushButton("SIGKILL");
    button_stop = new QPushButton("SIGSTOP");
    button_cont = new QPushButton("SIGCONT");
    button_hup = new QPushButton("SIGHUP");
    button_term = new QPushButton("SIGTERM");
    //button_kill->setToolTip("Для завершения процесса вы должны выделить его PID и нажать на кнопку \"Завершить\"");
    connect(button_kill,SIGNAL(clicked()),this,SLOT(kill()));
    connect(button_kill,SIGNAL(clicked()),this,SLOT(stop()));
    connect(button_kill,SIGNAL(clicked()),this,SLOT(cont()));
    connect(button_kill,SIGNAL(clicked()),this,SLOT(hup()));
    connect(button_kill,SIGNAL(clicked()),this,SLOT(term()));
    hlayout->addStretch();
    hlayout->addWidget(button_kill);
    hlayout->addWidget(button_stop);
    hlayout->addWidget(button_cont);
    hlayout->addWidget(button_hup);
    hlayout->addWidget(button_term);
    layout = new QVBoxLayout;
    table = new QTableWidget;
    update();
    layout->addWidget(table);
    layout->addLayout(hlayout);
    this->setLayout(layout);
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(4000);
}
void ProcessTable::update()
{
    table->setColumnCount(2);
    table->setRowCount(0);

    QStringList list;
    list << "Процес" << "PID";
    table->setHorizontalHeaderLabels(list);
    QDir * dir = new QDir("/proc");
    list = dir->entryList(QStringList("*"),QDir::AllDirs);
    foreach(QString str, list) {
        if(str.toInt()) {
            ifstream stream;

            stream.open("/proc/" + str.toUtf8()+ "/comm");
            string s; getline(stream,s);
            int lastRow = table->rowCount();
            QString icon = "/usr/share/icons/hicolor/32x32/apps/" + QString::fromStdString(s) + ".png";
            QFile file(icon);
            table->insertRow(lastRow);
            table->setColumnWidth(0,170);
            table->setColumnWidth(1,179);

            if(!file.exists()) {
                icon = ":/binary.png";
            }
            table->setItem(lastRow,0,new QTableWidgetItem(QPixmap(icon),QString::fromStdString(s)));
            table->setItem(lastRow,1,new QTableWidgetItem(str));
        } else {
            continue;
        }
    }
}


void ProcessTable::kill()
{
    QList<QTableWidgetItem*> list = table->selectedItems();
    QTableWidgetItem* item = list.value(0);
    QString str = item->text();
    QProcess::execute("kill -9 "+str);
    update();
}

void ProcessTable::stop()
{
    QList<QTableWidgetItem*> list = table->selectedItems();
    QTableWidgetItem* item = list.value(0);
    QString str = item->text();
    QProcess::execute("kill -19 "+str);
    update();

}

void ProcessTable::cont()
{
    QList<QTableWidgetItem*> list = table->selectedItems();
    QTableWidgetItem* item = list.value(0);
    QString str = item->text();
    QProcess::execute("kill -18 "+str);
    update();

}

void ProcessTable::term()
{
    QList<QTableWidgetItem*> list = table->selectedItems();
    QTableWidgetItem* item = list.value(0);
    QString str = item->text();
    QProcess::execute("kill -15 "+str);
    update();

}

void ProcessTable::hup()
{
    QList<QTableWidgetItem*> list = table->selectedItems();
    QTableWidgetItem* item = list.value(0);
    QString str = item->text();
    QProcess::execute("kill -1 "+str);
    update();

}
