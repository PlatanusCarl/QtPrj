#ifndef LINE_H
#define LINE_H
#include "geoclass.h"

class line:public geoclass
{
public:
    line();
    vector<point> pointlist;
};

#endif // LINE_H
