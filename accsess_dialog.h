#ifndef ACCSESS_DIALOG_H
#define ACCSESS_DIALOG_H

#include <QDialog>


namespace Ui {
    class Dialog;
    }

class Dialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();
   private:
    Ui::Dialog *dialog_ui;
};
#endif // ACCSESS_DIALOG_H
