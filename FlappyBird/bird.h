#ifndef BIRD_H
#define BIRD_H
#include<QPixmap>
#include<QRect>
#include<QSoundEffect>

class Bird
{
public:
    Bird();

    //拍打翅膀
    void setposition(int x,int y);

    //按帧率修改小鸟位置和状态
    void birdposition();

    //小鸟死亡
    void dead();

    //小鸟资源
    QPixmap birdmap;

    //小鸟坐标
    int m_x;
    int m_y;

    //小鸟矩形边框(碰撞判定)
    QRect rec;

    //小鸟动作
    int state;
    int i;
    int sound;
};

#endif // BIRD_H
