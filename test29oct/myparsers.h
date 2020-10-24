#ifndef MYPARSERS_H
#define MYPARSERS_H

#include"mydata.h"
#include<vector>

using namespace std;

class sldparser{
public:
    vector <xmldata> stylelist;
    bool loadfile(const char* address);
};

class geojsonparser{
public:
    vector <jsondata> polylist;
    bool loadfile(const char* address);
};

#endif // MYPARSERS_H
