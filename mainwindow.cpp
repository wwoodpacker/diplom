#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "processtable.h"
#include "accsesdialog.h"
#include "ui_accsesdialog.h"
#include "global.h"

#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QTableWidget>
#include <QLabel>
#include <QDirModel>
#include <QTreeView>
#include <QTreeWidget>
#include <QSplitter>
#include <QMenu>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    const QStringList LIST_ITEMS =
        QStringList() << "Користувачі" << "Журнал аудиту" << "Доступ до ресурсів" << "Процеси" << "Sudo" ;
    const QStringList LIST_ICONS =
        QStringList() << "user.png" << "journal.jpg" << "resources.png" << "process.png" << "Sudo-logo.png" ;
    ui->setupUi(this);
    ui->list_operation->setIconSize(QSize(40,40));

    int i=0;
    foreach( const QString& item, LIST_ICONS  ) {

        QListWidgetItem *listItem = new QListWidgetItem( LIST_ITEMS[i]);
        listItem->setIcon( QPixmap( "/root/diplom_beta/"+item) );

        ui->list_operation->addItem( listItem );
        i++;

    }
    QLabel *temp_lable =new QLabel;
    temp_lable->setText("<----- Choose item");
    ui->gridLayout->addWidget(temp_lable);
    connect(ui->list_operation,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(MainItemsAction(QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;

}
//accses dialog constr and destr
AccsesDialog::AccsesDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccsesDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(changeAccses()));
}

AccsesDialog::~AccsesDialog()
{
    delete ui;
}

//chmod chown function
void AccsesDialog::changeAccses()
{
  QString ChmodCommand="chmod ";
  QString ChownCommand="chown ";

{
  if (ui->radioButton->isChecked()) ChmodCommand.append("7");
    else
  if (ui->radioButton_2->isChecked()) ChmodCommand.append("6");
     else
  if (ui->radioButton_3->isChecked()) ChmodCommand.append("5");
    else
  if (ui->radioButton_4->isChecked()) ChmodCommand.append("4");
    else
  if (ui->radioButton_5->isChecked()) ChmodCommand.append("3");
    else
  if (ui->radioButton_6->isChecked()) ChmodCommand.append("2");
    else
  if (ui->radioButton_7->isChecked()) ChmodCommand.append("1");

  if (ui->radioButton_8->isChecked()) ChmodCommand.append("7");
    else
  if (ui->radioButton_9->isChecked()) ChmodCommand.append("6");
     else
  if (ui->radioButton_10->isChecked()) ChmodCommand.append("5");
    else
  if (ui->radioButton_11->isChecked()) ChmodCommand.append("4");
    else
  if (ui->radioButton_12->isChecked()) ChmodCommand.append("3");
    else
  if (ui->radioButton_13->isChecked()) ChmodCommand.append("2");
    else
  if (ui->radioButton_14->isChecked()) ChmodCommand.append("1");


  if (ui->radioButton_15->isChecked()) ChmodCommand.append("7");
    else
  if (ui->radioButton_16->isChecked()) ChmodCommand.append("6");
     else
  if (ui->radioButton_17->isChecked()) ChmodCommand.append("5");
    else
  if (ui->radioButton_18->isChecked()) ChmodCommand.append("4");
    else
  if (ui->radioButton_19->isChecked()) ChmodCommand.append("3");
    else
  if (ui->radioButton_20->isChecked()) ChmodCommand.append("2");
    else
  if (ui->radioButton_21->isChecked()) ChmodCommand.append("1");
}
  QProcess::execute(ChmodCommand+" "+fpp);
  QProcess::execute(ChownCommand+" "+ui->chown_user->toPlainText()+":"+ui->chown_group->toPlainText()+" "+fpp);
  fpp="";
  AccsesDialog::close();

 // QMessageBox::information(this,"jur",ChmodCommand+fpp,QMessageBox::Ok, 0 );
}
//popup menu
void MainWindow::onCustomContextMenu(const QPoint &point)
{
    //QDir dir("");
    AccsesDialog *Accsesdial = new AccsesDialog;
    Accsesdial->show();

    QModelIndex index = Treelist->indexAt(point);
    if (index.isValid()) {

        QDirModel *model2 = new QDirModel;
        QFileInfo fileInfo = model2->fileInfo(index);
        filePath =fileInfo.filePath();
        fpp=filePath;
       // QMessageBox::information(this,"jur",filePath,QMessageBox::Ok, 0 );
        //QMenu *menu=new QMenu;
        //  menu->exec(Treelist->mapToGlobal(point));
    // contextMenu->exec(Treelist->mapToGlobal(point));
    }
}

//Ma
void MainWindow::MainItemsAction(QListWidgetItem *item)
{

    ProcessTable* pt= new ProcessTable;
    QTableWidget *tableUser = new QTableWidget(100, 6, this);
     QTableWidget *tableJournal = new QTableWidget(10000,4, this);

    if(item->text()=="Користувачі") {
        QLayoutItem *item = ui->gridLayout->takeAt(0);
         delete item->widget();
        //tableUsers->move(QPoint(300,30));
        QStringList name_table_user;
            name_table_user <<"login"<<"password"<<"UID"<<"GID"<<"GECOS"<<"home"<<"shell";
        tableUser->setHorizontalHeaderLabels(name_table_user);
        tableUser->resize(QSize(400,300));
        tableUser->setColumnWidth(2,70);
        tableUser->setColumnWidth(3,70);


        int row=0;
        QFile file("/etc/passwd");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        { QMessageBox::information(this,"Error","Can't open passwd file",QMessageBox::Ok, 0 );}
        else
        while (!file.atEnd())
        {
             QByteArray line = file.readLine();
             QString str = line.data();
             QStringList user;
             user=str.split(":");
             for (int j=0;j<6;j++){
                 QTableWidgetItem *newItem = new QTableWidgetItem(user[j]);
                 tableUser->setItem(row,j, newItem);
             }
             row++;

        }
        ui->gridLayout->addWidget(tableUser);//tableUsers->show();

    }
    else
    if(item->text()=="Журнал аудиту"){
        QLayoutItem *item = ui->gridLayout->takeAt(0);
         delete item->widget();
        QStringList name_table_jurnal;
            name_table_jurnal<<"Дата"<<"Хост"<<"Процес"<<"Повідомлення";
            tableJournal->setHorizontalHeaderLabels(name_table_jurnal);
            tableJournal->resize(QSize(400,300));
            tableJournal->setColumnWidth(2,70);
            tableJournal->setColumnWidth(3,100);

            int row=0;
            QFile file("/var/log/syslog");

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            { QMessageBox::information(this,"Error","Can't open syslog file",QMessageBox::Ok, 0 );}
            else
            while (!file.atEnd())
            {
                 QByteArray line = file.readLine();
                 QString str = line.data();
                 QStringList journal_line;
                 QString tmp_line="";
                 journal_line=str.split(" ");
                // for (int j=0;j<3;j++){
                 tmp_line.append(journal_line[0]+" ");
                 tmp_line.append(journal_line[1]+" ");
                 tmp_line.append(journal_line[2]);
                 QTableWidgetItem *newItem1 = new QTableWidgetItem(tmp_line);
                 tableJournal->setItem(row,0,newItem1);

                 tmp_line.clear();
                 tmp_line.append(journal_line[3]);
                 QTableWidgetItem *newItem2 = new QTableWidgetItem(tmp_line);
                 tableJournal->setItem(row,1,newItem2);

                 tmp_line.clear();
                 tmp_line.append(journal_line[4]);
                 QTableWidgetItem *newItem3 = new QTableWidgetItem(tmp_line);
                 tableJournal->setItem(row,2,newItem3);

                 tmp_line.clear();
                 for (int j=5;j<journal_line.size();j++)
                 {
                    tmp_line.append(journal_line[j]);
                  }
                 QTableWidgetItem *newItem4 = new QTableWidgetItem(tmp_line);
                 tableJournal->setItem(row,3,newItem4);
                 //}
                 row++;

            }

            ui->gridLayout->addWidget(tableJournal);
            // QMessageBox::information(this,"jur","dd",QMessageBox::Ok, 0 );
    }
    else
    if(item->text()=="Доступ до ресурсів"){
        QLayoutItem *item = ui->gridLayout->takeAt(0);
         delete item->widget();
         splitter = new QSplitter;
         model = new QDirModel;
         Treelist = new QTreeView(splitter);
         Treelist->setModel(model);

            // list->setRootIndex(model->index(QDir::currentPath()));
             //splitter->setWindowTitle("Two views onto the same directory model");
                // splitter->show();
         ui->gridLayout->addWidget(Treelist);
         Treelist->setContextMenuPolicy(Qt::CustomContextMenu);
         connect(Treelist, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));

    }
    else
    if(item->text()=="Процеси"){
       QLayoutItem *item = ui->gridLayout->takeAt(0);
        delete item->widget();
       ui->gridLayout->addWidget(pt);

    }
    else
    if(item->text()=="Sudo"){
        QMessageBox::information(this,"jur","dd",QMessageBox::Ok, 0 );

    }


}

