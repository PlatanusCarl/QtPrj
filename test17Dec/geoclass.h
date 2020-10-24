#ifndef GEOCLASS_H
#define GEOCLASS_H
#include <QString>
#include <QList>
using namespace std;
class geoclass
{
public:
    QString ID;
    QString TYPE;
    geoclass();
};

class point
{
public:
    float X;
    float Y;
};

#endif // GEOCLASS_H
