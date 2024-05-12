#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"config.h"
#include <QIcon>
#include"map.h"
#include<QPaintEvent>
#include<QPainter>
#include<QTimer>
#include"base.h"
#include"bird.h"
#include"tube.h"
#include"gameover.h"
#include"score.h"
#include <QAbstractButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initial();
    void paintEvent(QPaintEvent *);//绘图事件
    void updatePosition();//以帧率为周期更新坐标
    void keyPressEvent(QKeyEvent *);//键盘事件
    void crash();//碰撞检测
    void GameOver();//游戏结束
    void moretube();//管道刷新器
    void score();//得分
    void PlayGame();//启动游戏，开启定时器对象
    void recover();//回复初始位置
    void speedup();//变速器

public:
    Map map;//地图对象
    QTimer Timer;//定时器对象
    Base base;//地基对象
    Bird bird;//小鸟对象
    Gameover gameover;//结束对象
    Tube tube[60];//管道对象
    Score scored;//计分对象
    int count;//计时器
    int point;
    int start;
    int judge=0;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
