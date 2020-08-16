#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myaction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyAction *action = new MyAction;
    QMenu* menu =ui->menuBar->addMenu("编辑(&E)");
    menu->addAction(action);

    connect(action,&MyAction::getText,this,&MainWindow::setText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setText(const QString &str)
{
    //ui->文本编辑器->设置文本
    ui->textEdit->setText(str);
}
