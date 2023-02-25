#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen->setIcon(QIcon(":/zsh/images/img1.jpg"));
    ui->actionEdit->setIcon(QIcon(":/zsh/images/vipp.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
