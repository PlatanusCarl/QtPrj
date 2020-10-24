#ifndef LAYER_H
#define LAYER_H
#include "geoclass.h"
#include "multipolygons.h"
class layer
{
public:
    layer();
    vector<geoclass> list;
    QList<multipolygon> multipolygonlist;
};

#endif // LAYER_H
