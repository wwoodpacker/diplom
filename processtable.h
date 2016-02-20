#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <QtGui>
#include <iostream>
#include <fstream>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QPushButton>
using namespace std;

class ProcessTable : public QWidget
{
    Q_OBJECT
public:
    explicit ProcessTable(QWidget *parent = 0);
private:
    QTableWidget * table;
    QHBoxLayout* hlayout;
    QPushButton* button_kill;
    QPushButton* button_cont;
    QPushButton* button_hup;
    QPushButton* button_term;
    QPushButton* button_stop;
    QVBoxLayout* layout;
public slots:
    void update();
    void kill();
    void stop();
    void term();
    void cont();
    void hup();
};

#endif // PROCESSTABLE_H
