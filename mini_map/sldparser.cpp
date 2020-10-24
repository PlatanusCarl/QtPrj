#include "sldparser.h"

sldParser::sldParser()
{

}

bool sldParser::loadfile(QString address)
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
                auto newone = new style;//创建新xmldata
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
