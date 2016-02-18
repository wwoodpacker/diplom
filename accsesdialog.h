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

private:
    Ui::AccsesDialog *ui;
};

#endif // ACCSESDIALOG_H
