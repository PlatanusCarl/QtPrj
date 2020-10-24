#ifndef SLDPARSER_H
#define SLDPARSER_H
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include "style.h"
#include <QList>

class sldParser
{
public:
    sldParser();
    bool loadfile(QString address);
    QList <style>stylelist;
};

#endif // SLDPARSER_H
