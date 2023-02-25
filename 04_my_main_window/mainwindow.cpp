#include "mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800,600);

    //菜单栏创建并放入窗口
    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    //添加菜单选项
    QMenu* file = bar->addMenu("文件");
    QMenu* edit = bar->addMenu("编辑");

    //添加下拉菜单
    QAction * open_action = file->addAction("打开");
    file->addSeparator();
    QAction * open_save = file->addAction("保存");

    // 创建一个工具栏
    QToolBar* tool_bar = new QToolBar("tool_bar", this);
    addToolBar(Qt::LeftToolBarArea, tool_bar);

    //创建一个组件
    QPushButton* button = new QPushButton("widget", this);

    //设置移动
    tool_bar->setFloatable(false);
    tool_bar->setAllowedAreas(Qt::RightToolBarArea| Qt::LeftToolBarArea);

    //给工具栏添加动作
    tool_bar->addAction(open_action);
    tool_bar->addSeparator();
    tool_bar->addAction(open_save);
    tool_bar->addWidget(button);
}

MainWindow::~MainWindow()
{

}
