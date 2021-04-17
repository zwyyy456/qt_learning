#include "mywidget.h"
#include "QPushButton"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;
    //令btn依赖于mywidget窗口中
    btn -> setParent(this);
    //显示文本
    btn -> setText("first button");

    //创建第二个按钮,按照控件大小创建窗口
    QPushButton *btn2 = new QPushButton("second button", this);

    //移动第二个按钮
    btn2 ->move(100, 100);

    //重置窗口大小
    resize(600, 400);
}

MyWidget::~MyWidget()
{


}

