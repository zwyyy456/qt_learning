#include "widget.h"
#include "ui_widget.h"
#include "QPixmap"
#include "QPainter"
#include "QImage"
#include "QPicture"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备
//    QPixmap pix(600, 400);

//    //填充颜色
//    pix.fill(Qt::white);

//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(Qt::green);
//    painter.drawEllipse(QPoint(300, 200), 100, 100);

//    pix.save("D:\\pix.png");

//    //QImage绘图设备,可以对像素进行访问
//    QImage img(300, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter imgPainter(&img);
//    imgPainter.setPen(Qt::blue);
//    imgPainter.drawEllipse(QPoint(150, 150), 100, 100);

//    img.save("D:\\img.png");

    //QPicture绘图设备,可以记录和重现绘图指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);//开始画画
    painter.setPen(Qt::cyan);
    painter.drawEllipse(QPoint(300, 200), 100, 100);
    painter.end();

    //保存到磁盘
    pic.save("D:\\400study\\500cs\\507qt\\qt_learning\\04_QPainterDevice\\Image\\img.zwy");

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

//    //利用QImage对像素进行修改
//    QImage img;
//    img.load(":/Image/memory.png");

//    //修改像素点
//    for(int i = 50; i < 100; i++)
//    {
//        for(int j = 50; j < 100; j++)
//        {
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }
//    painter.drawImage(0, 0, img);

    //重现QPicture的绘图指令
    QPicture pic;
    pic.load("D:\\400study\\500cs\\507qt\\qt_learning\\04_QPainterDevice\\Image\\img.zwy");
    painter.drawPicture(0, 0, pic);
}

Widget::~Widget()
{
    delete ui;
}

