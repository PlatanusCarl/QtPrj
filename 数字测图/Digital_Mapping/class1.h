#ifndef CLASS1_H
#define CLASS1_H
const double e2=0.0066943799013 ;
const double a = 6378137;
class class1
{
public:
    class1();
    class1(double a,double b,double c,bool p);
    void fromLBHtoXYZ();
    void fromXYZtoLBH();
    ~class1();
    double LBH[3],XYZ[3];
};

#endif // CLASS1_H
