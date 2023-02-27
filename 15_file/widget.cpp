#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QTextCodec>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=]{
        QFileDialog* fileDialog = new QFileDialog;
        QString filePath = fileDialog->getOpenFileName();
        qDebug() << filePath;
        ui->lineEdit->setText(filePath);

          //gbk
//        QTextCodec* codec = QTextCodec::codecForName("gbk");

        QFile* file = new QFile(filePath);
        file->open(QIODevice::ReadOnly);

//        QString context = codec->toUnicode( file->readAll());
        QString context = file->readAll();
        ui->textEdit->setText(context);

        QFileInfo* fileinfo = new QFileInfo(*file);
        QString fileData = fileinfo->created().toString("yyyy-MM-dd h:m:s ap");
        ui->label->setText(fileData);
    });
}

Widget::~Widget()
{
    delete ui;
}
