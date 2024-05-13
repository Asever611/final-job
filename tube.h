#ifndef TUBE_H
#define TUBE_H
#include "config.h"
#include <QPixmap>
#include <QRect>
#include <QtGlobal>
#include <cstdlib>

class Tube
{
public:
    Tube();

    void updateposition();//更新管道坐标

    QPixmap tube;//管道资源
    QPixmap rtube;//上管道资源

    QRect rec;//下管道实体矩形
    int m_x;//下管道坐标x
    int m_y;//下管道坐标y

    QRect rrec;//上管道实体矩形
    int m_rx;//上管道坐标
    int m_ry;//上管道坐标

    bool exist;
    int speed;
};

#endif // TUBE_H
