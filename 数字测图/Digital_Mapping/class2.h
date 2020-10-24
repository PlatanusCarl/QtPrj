#ifndef CLASS2_H
#define CLASS2_H
#include <QPoint>

class class2
{
public:
    class2();
    class2(double x0,double y0,double x,double y,double alpha,bool status);
    ~class2();
    void fromXY1toAB1();
    void fromAB1toXY1();
    double XY0[2],XY1[2],AB1[2];
    double alpha;
};

#endif // CLASS2_H
