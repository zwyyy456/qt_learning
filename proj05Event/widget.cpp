#include "widget.h"
#include "ui_widget.h"
#include "QTimer"
#include "QLabel"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    //定时器第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer -> start(500);

    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;

        //label4 每隔0.5s+1
        ui -> label_3 -> setText(QString::number(num++));
    });

    QLabel * mylbl = new QLabel(this);
    mylbl -> setText("study now");
    QPushButton * btn = new QPushButton("stop", this);
    connect(btn, &QPushButton::clicked, this, [=](){
        timer -> stop();
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent * ev)
{
    if (ev -> timerId() == id1)
    {
        static int num = 1;
        ui -> label -> setText(QString::number(num++));
    }

    if (ev -> timerId() == id1)
    {
        static int num = 1;
        ui -> label_2 -> setText(QString::number(num++));
    }
}

