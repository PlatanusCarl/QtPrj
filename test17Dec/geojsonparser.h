#ifndef GEOJSONPARSER_H
#define GEOJSONPARSER_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include "geoclass.h"
#include "points.h"
#include "lines.h"
#include "polygons.h"
#include "multipolygons.h"
#include "layer.h"


class geojsonParser
{
public:
    geojsonParser(QString address);
    bool loadfile();
    layer alayer;
private:
    void projection(float* lon,float* lat);
    QString address;
};

#endif // GEOJSONPARSER_H
