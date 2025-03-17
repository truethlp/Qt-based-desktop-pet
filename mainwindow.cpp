#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QLabel>
#include<QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QString>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //标签加载图片
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowFlags (windowFlags () | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);
    setMinimumSize(1400, 1400);

    auto l = new QLabel();
    layout()->addWidget(l);

    this->idx = 1;
    l->setStyleSheet(QString("background: url(:/test/test/%1.png) no-repeat;").arg(this->idx));
    auto time = new QTimer(this);
    time->setInterval(100);
    connect(time, &QTimer::timeout, this, [this, l]() {
        // 131是根据我的切割完以后图片来进行输入的
        this->idx = (this->idx + 1 ) % 150 + 1;
        l->setStyleSheet(QString("background: url(:/test/test/%1.png) no-repeat;").arg(this->idx));
    });
    time->start();





}
void MainWindow::mousePressEvent(QMouseEvent *event)
{

    diff_ = event->globalPos() - this->pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

    diff_ = QPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    this->move(event->globalPos() - this->diff_);
}


MainWindow::~MainWindow()
{
    delete ui;
}
