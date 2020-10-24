#ifndef MYDATA_H
#define MYDATA_H
#include <QString>
#include <vector>

using namespace std;

typedef class pointdata{
    public:
        double x;
        double y;
}pt;

typedef class jsondata{
        public:
        vector <vector<pt>> multipoly;
        QString name;
}jsd;

typedef class xmldata{
    public:
        QString name;
        QString fillcolor;
        QString strokewidth;
        QString strokecolor;
        QString strokelinejoin;
}xmd;

#endif // MYDATA_H
