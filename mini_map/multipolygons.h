#ifndef MULTIPOLYGON_H
#define MULTIPOLYGON_H
#include "geoclass.h"
#include "polygons.h"

class multipolygon:public geoclass
{
public:
    multipolygon();
    QList<polygon> polygonlist;
};

#endif // MULTIPOLYGON_H
