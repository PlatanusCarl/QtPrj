#include "geojsonparser.h"
#include "QtMath"
geojsonParser::geojsonParser(QString addr)
{
    this->address =addr;
}

void geojsonParser::projection(float *lon, float *lat)
{

}

bool geojsonParser::loadfile()
{
    QFile file(address);//打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){//验证文件已经打开
        qDebug()<<"读取失败"<<qPrintable(address)<<":"<<qPrintable(file.errorString());
        return false;
    }

    QJsonDocument jsondoc =QJsonDocument::fromJson(file.readAll());//创建Qjsondocument
    file.close();//关闭文件

    QJsonObject jsonobj = jsondoc.object();//创建Qjsonobject

    if(jsonobj.contains("features")){
         QJsonArray array = jsonobj.value("features").toArray();
         foreach(const QJsonValue &value,array)
         {
             auto *feature = new geoclass;//创建新的要素
             QJsonObject obj = value.toObject();
             if(obj.contains("properties"))//读取要素名称
             {
                QJsonObject pro = obj.value("properties").toObject();
                feature->ID = pro.value("JDNAME").toString();
             }

             if(obj.contains("geometry"))//读取要素几何属性
             {
                QJsonObject geobj = obj.value("geometry").toObject();

                if(geobj.value("type").toString() == "MultiPolygon")
                {
                    auto multi = new multipolygon;
                    multi->ID = feature->ID;
                    multi->TYPE ="MultiPolygon";
                    delete feature;

                    QJsonArray mutipolyarr = geobj.value("coordinates").toArray();

                    for(int i=0;i<mutipolyarr.size();i++)
                    {
                        QJsonArray poly = mutipolyarr.at(i).toArray().at(0).toArray();
                        polygon* apolygon = new polygon;//创建多边形
                        float max=1;
                        for(int j=0;j<poly.size();j++)
                        {
                            float x,y;
                            y = poly.at(j).toArray().toVariantList().at(1).toFloat();
                            apolygon->polygonvec.push_back(-y);//将点读入多边形vector

                            x =poly.at(j).toArray().toVariantList().at(0).toFloat();
                            apolygon->polygonvec.push_back(x);

                            apolygon->polygonvec.push_back(0.0f);
                            if(x>max) max =x;
                            if(y>max) max =y;
                            // qDebug() << x,y;

                        }//for
                        for (int i = 0;i<apolygon->polygonvec.size();i++)
                        {
                            apolygon->polygonvec.replace(i,((apolygon->polygonvec.at(i)/max-0.4)));
                        }
                        multi->polygonlist.push_back(*apolygon);//存入多多边形Vector

                     }//for

                     alayer.multipolygonlist.push_back(*multi);//存入图层

                   }//if

                 if(geobj.value("type").toString() == "Polygon")
                 {

                 }

                 if(geobj.value("type").toString() == "Line")
                 {

                 }

                 if(geobj.value("type").toString() == "Point")
                 {

                 }

            }//if
         }//foreach
        }//if

    return true;
}




