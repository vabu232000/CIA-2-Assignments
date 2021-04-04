#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_5->setCheckable(true);

    QAction *a1=new QAction;
    QAction *a2=new QAction;
    QAction *a3=new QAction;
    a1->setText("First");
    a2->setText("Second");
    a3->setText("Third");
    QMenu *menu=new QMenu;
    menu->addAction(a1);
    menu->addAction(a2);
    menu->addAction(a3);
    ui->pushButton_6->setMenu(menu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Vabhoosha_212218104173","This is my information box");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this, "Vabhoosha_212218104173","Is this right?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        QMessageBox::information(this, "Right","You are right");
    }
    if(reply==QMessageBox::No)
    {
        QMessageBox::information(this, "Wrong","You are not right");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
     QMessageBox::StandardButton reply=QMessageBox::question(this, "Custom message","This is a custom critical message",QMessageBox::Yes|QMessageBox::No|QMessageBox::YesAll|QMessageBox::NoAll);
     if(reply==QMessageBox::Yes)
{
         QTextStream stream(stdout);
         {
             stream<<"Nothing is displayed"<<endl;
         }
     }
     if(reply==QMessageBox::YesAll)
     {
         QMessageBox::warning(this, "Message Display","Display the message with warning yes to all");
     }
     if(reply==QMessageBox::NoAll)
     {
         QMessageBox::warning(this, "Message Display","Display the message with warning no to all");
     }
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::warning(this, "Vabhoosha_212218104173","This is a warning message");
 }


void MainWindow::on_pushButton_5_toggled(bool checked)
{
    if(checked)
    {
         ui->pushButton_5->setIcon(QIcon("D:/vabu college/6th sem/C++/onbutton.jpg"));
         QTextStream stream(stdout);
         {
             stream<<"Button clicked--ON--"<<endl;
         }
    }
    else
    {
         ui->pushButton_5->setIcon(QIcon("D:/vabu college/6th sem/C++/offbutton.jpg"));
         QTextStream stream(stdout);
         {
             stream<<"Button unclicked--OFF--"<<endl;
         }
    }
}
