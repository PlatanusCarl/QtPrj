#include "mydata.h"
#include "myparsers.h"
#include <QXmlStreamReader>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

bool sldparser::loadfile(const char* address)
{
    QFile file(address);//打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//验证文件已经打开
    {
        qDebug()<<"Error: Cannot read file"<<qPrintable(address)<<":"<<qPrintable(file.errorString());
        return false;
    }
    qDebug()<<"SLD file opened";
    QXmlStreamReader reader;//创建reader
    reader.setDevice(&file);

    reader.readNext();
    while(!reader.atEnd())
    {
        if(reader.isStartElement())
        {
            if(reader.name()=="Rule")
            {
                xmldata* newone = new xmldata;//创建新xmldata
                stylelist.push_back(*newone);//存入vector中
                reader.readNext();
                while(!(reader.name()=="Rule"&&reader.isEndElement()))//在到达标签</Rule>前读入样式信息
                {
                    if(reader.name()=="Name")
                    {
                        newone->name = reader.readElementText();
                        qDebug()<<"reading"<<newone->name;
                    }
                    if(reader.name()=="SvgParameter")
                    {
                        if(reader.attributes().value("name")=="fill")
                        {    newone->fillcolor = reader.readElementText();
                            qDebug()<<newone->fillcolor;
                        }
                        if(reader.attributes().value("name")=="stroke")
                        {    newone->strokecolor = reader.readElementText();
                            qDebug()<<newone->strokecolor;
                        }
                            if(reader.attributes().value("name")=="stroke-width")
                        {    newone->strokewidth = reader.readElementText();
                            qDebug()<<newone->strokewidth;
                        }
                            if(reader.attributes().value("name")=="stroke-linejoin")
                        {
                            newone->strokelinejoin =reader.readElementText();
                            qDebug() <<newone->strokelinejoin;
                        }
                    }
                    reader.readNext();
                }//while
            }//if
        }//if
        reader.readNext();
        if(reader.hasError())//如果读取过程中出现错误，输出错误原因
            qDebug()<<reader.errorString();
    }//while
    file.close();//关闭文件
    qDebug()<<"SLD file closed.";
    return true;
}

bool geojsonparser::loadfile(const char *address)
{
    QFile file(address);//打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//验证文件已经打开
    {
        qDebug()<<"Error: Cannot read file"<<qPrintable(address)<<":"<<qPrintable(file.errorString());
        return false;
    }
    qDebug()<<"GEOJSON file opened";
    QJsonDocument jsondoc =QJsonDocument::fromJson(file.readAll());//创建Qjsondocument
    file.close();//关闭文件
    qDebug()<<"GEOJSON file closed";

    QJsonObject jsonobj = jsondoc.object();//创建Qjsonobject

    if(jsonobj.contains("features"))
    {
     QJsonArray array = jsonobj.value("features").toArray();
     foreach(const QJsonValue &value,array)
     {

         jsondata *newone = new jsondata;//创建新的jsondata
         polylist.push_back(*newone);
         QJsonObject obj = value.toObject();
         if(obj.contains("properties"))//读取多多边形名称
         {
            QJsonObject pro = obj.value("properties").toObject();
            newone->name = pro.value("JDNAME").toString();
            qDebug()<<"reading"<<newone->name;
         }
         if(obj.contains("geometry"))//读取多多边形
         {
            QJsonObject geobj = obj.value("geometry").toObject();
            QJsonArray mutipolyarr = geobj.value("coordinates").toArray();

            for(int i=0;i<mutipolyarr.size();i++)
            {

                QJsonArray poly = mutipolyarr.at(i).toArray().at(0).toArray();
                qDebug()<<"reading points"<<poly.size();
                vector <pt>* polyvec = new vector <pt>;//创建多边形vector
                newone->multipoly.push_back(*polyvec);//存入多多边形Vector
                for(int j=0;j<poly.size();j++)
                {
                    pointdata* newpt =new pointdata;
                    polyvec->push_back(*newpt);//将点读入多边形vector
                    newpt->x=poly.at(j).toArray().toVariantList().at(0).toDouble();
                    newpt->y=poly.at(j).toArray().toVariantList().at(1).toDouble();
                }//for
            }//for
         }//if
     }//foreach
    }//if
    return true;
}
