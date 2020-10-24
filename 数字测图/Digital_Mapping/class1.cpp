#include "class1.h"
#include <QtMath>
const double pi = 3.1415926;
class1::class1(){}
class1::~class1(){};
class1::class1(double a,double b,double c,bool p)
{
    if(p == true)
    {
        XYZ[0] =a;
        XYZ[1] =b;
        XYZ[2] =c;
        return;
    }
    LBH[0] = a*pi/180.00;
    LBH[1] = b*pi/180.00;
    LBH[2] = c;
}

void class1::fromLBHtoXYZ()
{
    double N = double(a/(sqrt(1-e2*sin(LBH[1])*sin(LBH[1]))));
    XYZ[0] = (N + LBH[2])*cos(LBH[1])*cos(LBH[0]);
    XYZ[1] = (N + LBH[2])*cos(LBH[1])*sin(LBH[0]);
    XYZ[2] = (N*(1-e2) + LBH[2]);
}

void class1::fromXYZtoLBH()
{
    LBH[0]=atan(XYZ[1]/XYZ[2]);
    qreal B1=1,B2=2,N1=0,N2=0;
    while(qFabs(B1-B2)/B1 < 1/10000)
    {
        B1 = atan(XYZ[2]/sqrt(XYZ[0]*XYZ[0]+XYZ[1]*XYZ[1]));
        N1 = (sqrt(XYZ[0]*XYZ[0]+XYZ[1]*XYZ[1])*tan(B1)-XYZ[2])/e2*sin(B1);
        B2 = atan((XYZ[2]+ N1*e2*sin(B1))/sqrt(XYZ[0]*XYZ[0]+XYZ[1]*XYZ[1]));
        N2 = (sqrt(XYZ[0]*XYZ[0]+XYZ[1]*XYZ[1])*tan(B2)-XYZ[2])/e2*sin(B2);
    }
    LBH[1] = B2;
    LBH[2] = sqrt(XYZ[0]*XYZ[0]+XYZ[1]*XYZ[1])/cos(B2) - N2;
}
