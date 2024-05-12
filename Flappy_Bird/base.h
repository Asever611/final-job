#ifndef BASE_H
#define BASE_H
#include<QPixmap>
#include<QRect>

class Base
{
public:
    Base();

    //地基图像
    QPixmap base;

    //地基图像位置
    int base_X1;
    int base_X2;
    int base_X3;
    int base_X4;
    int speed;

    //地基矩形边框
    QRect base_rect;

    //地基位置更新
    void baseposition();
};

#endif // BASE_H
