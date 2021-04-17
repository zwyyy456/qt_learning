#include "widget.h"
#include "ui_widget.h"
#include "QPainter"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton * pushButton = new QPushButton(this);

    connect(pushButton, &QPushButton::clicked,  [=](){
        //如果手动调用绘图事件,用 update 更新
        update();
    });
}

void Widget::paintEvent(QPaintEvent *)
{
//    //设置画笔
//    QPen pen(QColor(255, 0, 0));
//    pen.setWidth(3);
//    pen.setStyle(Qt::DashLine);
//    //实例化画家对象，this指定的是绘图设备
//    QPainter painter(this);
//    painter.setPen(pen);

//    //设置画刷
//    QBrush brush(Qt::cyan);
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);

//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));

//    painter.drawEllipse(QPoint(100, 100), 50, 50);

//    painter.drawRect(20, 20, 50, 50);

//    //画文字
//    painter.drawText(QRect(10, 200,200, 50), "好好学习，天天向上");


///*高级设置*/
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100, 50), 50, 50);
//    //设置 抗锯齿 效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200, 50), 50, 50);

//    //画矩形
//    painter.drawRect(QRect(20, 20, 50, 50));

//    painter.translate(100, 0);

//    painter.drawRect(QRect(20, 20, 50, 50));

//    painter.translate(100, 0);

//    painter.drawRect(QRect(20, 20, 50, 50));

    //利用画家添加资源图片
    QPainter painter(this);

    posx += 20;

    painter.drawPixmap(posx, 0, QPixmap(":/memory.png"));
}

Widget::~Widget()
{
    delete ui;
}

