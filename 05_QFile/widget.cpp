#include "widget.h"
#include "ui_widget.h"
#include "QFileDialog"
#include "QTextCodec"
#include "QFileInfo"
#include "QDebug"
#include "QDateTime"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击选取文件按钮，弹出文件对话框
    connect(ui -> pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\zwyyy\\Desktop");
        ui -> lineEdit->setText(path);

        //编码格式类
        QTextCodec * codec = QTextCodec::codecForName("gbk");
        //读取内容放到textEdit中,QFile默认支持utf-8
        QFile file(path);
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        QByteArray array = file.readAll();
        //按行读
        while(!file.atEnd())
        {
            array += file.readLine();
        }

        //ui -> textEdit -> setText(array);
        ui -> textEdit -> setText(codec -> toUnicode(array));

        file.close();

        //进行写文件
        file.open(QIODevice::Append);
        file.write("\nzwyyy");
        file.close();

        //文件信息类
        QFileInfo info(path);

        qDebug() << "size: " << info.size() << "suffix: " << info.suffix() << "name: " << info.fileName() << "paht: " <<info.path();
        qDebug() << "创建日期" << info.birthTime().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "最后的修改日期" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

