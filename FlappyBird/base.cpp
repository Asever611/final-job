#include "base.h"
#include "config.h"

Base::Base()
{
    //地基资源加载
    base.load(BASE_PATH);

    //地基位置
    base_X1=0;
    base_X2=288;
    base_X3=576;
    base_X4=864;

    //地基矩形
    base_rect.setWidth(3*base.width());
    base_rect.setHeight(base.height());
    base_rect.moveTo(0,BASE_Y);
    speed=BASE_SPEED;
}

//地基位置更新
void Base::baseposition()
{
    base_X1-=speed;
    if(base_X1<=-288)
    {
        base_X1=0;
    }
    base_X2-=speed;
    if(base_X2<=0)
    {
        base_X2=288;
    }
    base_X3-=speed;
    if(base_X3<=288)
    {
        base_X3=576;
    }
    base_X4-=speed;
    if(base_X4<=576)
    {
        base_X4=864;
    }
}
