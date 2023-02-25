#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->actionOpen, &QAction::triggered,[=]{

//        QDialog* dialog = new QDialog(this);
//        dialog->setAttribute(Qt::WA_DeleteOnClose);
//        dialog->resize(250,50);
////        dialog->exec();  //模态

//        dialog->show();  //非模态

//        qDebug() << "对话框弹出了";
//    });
     QMessageBox::about(this, "111", "新年快乐");
     QMessageBox::warning(this, "111", "2222", QMessageBox::Ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}
