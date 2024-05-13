#include "tube.h"

Tube::Tube()
{
    tube.load(TUBE_PATH);//加载管道资源
    rec.setWidth(tube.width());//设置实体矩形宽高
    rec.setHeight(tube.height());

    rtube.load(TUBE_PATH2);//加载上管道资源
    rrec.setWidth(rtube.width());//设置上管道实体矩阵
    rrec.setHeight(rtube.height());

    m_y=( rand() % (GAME_HEIGHT-100 - 180 + 1) ) -300;//利用随机数生成初始y坐标
    m_x=GAME_WIDTH;//设置初始X坐标
    rec.moveTo(m_x,m_y);//设置初始矩形位置

    m_rx=GAME_WIDTH;
    m_ry=m_y-rtube.height()-180;
    rrec.moveTo(m_rx,m_ry);//设置上矩形初始位置

    speed=TUBE_SPEED;
    exist=false;
}
void Tube::updateposition(){
    if(exist==true){
        m_x-=speed;
        m_rx-=speed;
        rec.moveTo(m_x,m_y);
        rrec.moveTo(m_rx,m_ry);
    }
}
