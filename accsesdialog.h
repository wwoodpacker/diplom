#ifndef ACCSESDIALOG_H
#define ACCSESDIALOG_H

#include <QWidget>

namespace Ui {
class AccsesDialog;
}

class AccsesDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AccsesDialog(QWidget *parent = 0);
    ~AccsesDialog();

public slots:
    void changeAccses();

private:
    Ui::AccsesDialog *ui;

};

#endif // ACCSESDIALOG_H
