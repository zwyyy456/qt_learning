#include "mainscene.h"
#include "ui_mainscene.h"
#include "QPainter"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置固定大小
    setFixedSize(400, 640);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币主场景");
    //退出按钮实现
    connect(ui -> actionquit, &QAction::triggered, [=](){
        this -> close();
    });
}

void MainScene::paintEvent(QPaintEvent * )
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this -> width(), this -> height(), pix);

    //画背景上的图标
    pix.load(":/res/Title.png");

    //缩放
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix);

}
MainScene::~MainScene()
{
    delete ui;
}

