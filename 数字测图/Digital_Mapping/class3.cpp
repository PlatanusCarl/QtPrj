#include "class3.h"

class3::class3(){}

class3 ::class3(double a,double b,double c)
{
    n = a;
    n1 = b;
    L = c;
}

class3::~class3(){}


void class3::calculate()
{
    if(int(n))
    {
        n1 = 2*n-1;
        L = n*6-3;
        return;
    }
    n = (n1+1)/2;
    L = n1*3;
}
