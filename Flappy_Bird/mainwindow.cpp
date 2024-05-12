#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initial();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initial()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置图标资源
    setWindowIcon(QIcon(GAME_ICON));

    //设置定时器帧率
    Timer.setInterval(GAME_RATE);

    //播放音乐
    /*if(gameover.state==0)
    {
        QSound::play(bgm);
    }*/

    //抽象时钟
    count=0;

    //其它变量
    point=0;
    start=0;
    gameover.state=0;

    //重新开始
    recover();

    //开始游戏
    if(judge==0)
    {
        PlayGame();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    if(point%20<10)
    {
        painter.drawPixmap(0,map.map_posY,map.map1);
        painter.drawPixmap(288,map.map_posY,map.map1);
        painter.drawPixmap(576,map.map_posY,map.map1);
    }
    else
    {
        painter.drawPixmap(0,map.map_posY,map.map2);
        painter.drawPixmap(288,map.map_posY,map.map2);
        painter.drawPixmap(576,map.map_posY,map.map2);
    }
    if(start==0)
    {
        painter.drawPixmap(330,90,map.startmap);
    }

    //绘制地基
    painter.drawPixmap(base.base_X1,BASE_Y,base.base);
    painter.drawPixmap(base.base_X2,BASE_Y,base.base);
    painter.drawPixmap(base.base_X3,BASE_Y,base.base);
    painter.drawPixmap(base.base_X4,BASE_Y,base.base);

    //绘制小鸟
    painter.drawPixmap(bird.m_x,bird.m_y,bird.birdmap);

    //绘制管道
    for(int j=0;j<TUBE_NUM;j++)
    {
        if(tube[j].exist==true)
        {
            painter.drawPixmap(tube[j].m_x,tube[j].m_y,tube[j].tube);
            painter.drawPixmap(tube[j].m_rx,tube[j].m_ry,tube[j].rtube);
        }
    }

    //绘制得分
    switch(point%10)
    {
    case 0:
        painter.drawPixmap(820,20,scored.S0);
        break;
    case 1:
        painter.drawPixmap(820,20,scored.S1);
        break;
    case 2:
        painter.drawPixmap(820,20,scored.S2);
        break;
    case 3:
        painter.drawPixmap(820,20,scored.S3);
        break;
    case 4:
        painter.drawPixmap(820,20,scored.S4);
        break;
    case 5:
        painter.drawPixmap(820,20,scored.S5);
        break;
    case 6:
        painter.drawPixmap(820,20,scored.S6);
        break;
    case 7:
        painter.drawPixmap(820,20,scored.S7);
        break;
    case 8:
        painter.drawPixmap(820,20,scored.S8);
        break;
    case 9:
        painter.drawPixmap(820,20,scored.S9);
        break;
    }

    switch(point/10)
    {
    case 0:
        painter.drawPixmap(788,20,scored.S0);
        break;
    case 1:
        painter.drawPixmap(788,20,scored.S1);
        break;
    case 2:
        painter.drawPixmap(788,20,scored.S2);
        break;
    case 3:
        painter.drawPixmap(788,20,scored.S3);
        break;
    case 4:
        painter.drawPixmap(788,20,scored.S4);
        break;
    case 5:
        painter.drawPixmap(788,20,scored.S5);
        break;
    case 6:
        painter.drawPixmap(788,20,scored.S6);
        break;
    case 7:
        painter.drawPixmap(788,20,scored.S7);
        break;
    case 8:
        painter.drawPixmap(788,20,scored.S8);
        break;
    case 9:
        painter.drawPixmap(786,20,scored.S9);
        break;
    }

    //绘制gameover
    if(gameover.state==1)
    {
        painter.drawPixmap(320,200,gameover.gameovermap);
    }
}

void MainWindow::PlayGame()
{
    //启动定时器
    Timer.start();
    //监听定时器
    connect(&Timer,&QTimer::timeout,[=]()
            {
        //更新游戏中元素的坐标
        updatePosition();
        //碰撞检测
        crash();
        //抽象计时器
        if(start==1&&gameover.state==0)
        {
            count++;
        }
        //管道刷新器
        moretube();
        //刷新计分器
        score();
        //重新绘制图片
        update();
        //变速器
        speedup();
    });
}

void MainWindow::updatePosition()
{
    base.baseposition();
    if(start==1)
    {
        if(gameover.state==1)
        {
            bird.dead();
        }
        else
        {
            bird.birdposition();
        }
        for(int j=0;j<TUBE_NUM;j++)
        {
            tube[j].updateposition();
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int y=bird.m_y;
    if(e->key() == Qt::Key_Space)
    {
        y-=BIRD_UP_SPEED;
        if(gameover.state==0)
        {
            QSoundEffect effect;
            effect.setSource(QUrl::fromLocalFile(BIRD_FLAP2_SOUND));
            effect.setLoopCount(QSoundEffect::Infinite);
            effect.setVolume(1);
            effect.play();
        }
        if(start==0)
        {
            start=1;
            QSoundEffect effect;
            effect.setSource(QUrl::fromLocalFile(BIRD_FLAP1_SOUND));
            effect.setLoopCount(QSoundEffect::Infinite);
            effect.setVolume(1);
            effect.play();
        }
    }
    bird.setposition(bird.m_x,y);
    if(gameover.state==1)
    {
        if(e->key() == Qt::Key_Space)
        {
            judge=1;
            initial();
        }
    }
}

void MainWindow::crash()
{
    if(bird.rec.intersects(base.base_rect))
    {
        gameover.state=1;
    }
    for(int j=0;j<TUBE_NUM;j++)
    {
        if(bird.rec.intersects(tube[j].rec))
        {
            gameover.state=1;
        }
        if(bird.rec.intersects(tube[j].rrec))
        {
            gameover.state=1;
        }
    }
}
void MainWindow:: moretube()
{
    int w=count/(TUBE_INTERVAL-point*4);
    tube[w].exist=true;
}
void MainWindow::score()
{
    if(bird.m_x>=tube[point].m_x&&bird.m_x<=tube[point].m_x+tube[point].rec.width()&&gameover.state==0)
    {
        point++;
        QSoundEffect effect;
        effect.setSource(QUrl::fromLocalFile(BIRD_SCORE_SOUND));
        effect.setLoopCount(QSoundEffect::Infinite);
        effect.setVolume(1);
        effect.play();
    }
}
void MainWindow::speedup()
{
    for(int i=0;i<TUBE_NUM;i++)
    {
        tube[i].speed=point*0.2+TUBE_SPEED ;
    }
    base.speed=point*0.2+TUBE_SPEED;
}

void MainWindow:: recover()
{
    bird.birdmap.load(BIRD_UP_PATH);
    for(int i=0;i<TUBE_NUM;i++)
    {
        tube[i].m_x=GAME_WIDTH;
        tube[i].m_rx=GAME_WIDTH;
        tube[i].rec.moveTo(tube[i].m_x,tube[i].m_y);
        tube[i].rrec.moveTo(tube[i].m_rx,tube[i].m_ry);
        tube[i].exist=false;
    }
    bird.m_x=GAME_WIDTH *0.1;
    bird.m_y=GAME_HEIGHT*0.5;
    bird.rec.moveTo(bird.m_x,bird.m_y);
    bird.sound=0;
}
