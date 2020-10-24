#include "class2.h"
#include <QtMath>
const double pi = 3.1415926;

class2::class2(){}
class2::class2(double x0,double y0,double x,double y,double alp,bool status)
{
    XY0[0] =x0;
    XY0[1] =y0;
    alpha = alp;
    if(status)
    {
        AB1[0] =x;
        AB1[1] =y;
    }
    XY1[0] =x;
    XY1[1] =y;
}
class2::~class2(){}

void class2::fromAB1toXY1()
{
    XY1[0] = XY0[0] + AB1[0]*cos(alpha*pi/180)-AB1[1]*sin(alpha*pi/180);
    XY1[1] = XY0[1] + AB1[0]*sin(alpha*pi/180)+AB1[1]*cos(alpha*pi/180);
}

void class2::fromXY1toAB1()
{
    AB1[0] = (XY1[0]-XY0[0])*cos(alpha*pi/180) + (XY1[1]-XY0[1])*sin(alpha*pi/180);
    AB1[1] = -(XY1[0]-XY0[0])*sin(alpha*pi/180) +(XY1[1]-XY0[1])*cos(alpha*pi/180);
}
