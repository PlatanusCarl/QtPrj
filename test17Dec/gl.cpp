#include "gl.h"
#include <QList>
int FirstTag =0;
gl::gl(QWidget *parent) : QOpenGLWidget (parent), VBO(QOpenGLBuffer::VertexBuffer), EBO(QOpenGLBuffer::IndexBuffer)
{

    {//抗锯齿
        QSurfaceFormat surfaceFormat;
        surfaceFormat.setSamples(16);//多重采样
        this->setFormat(surfaceFormat);
    }

    {//初始化
        moveTag = 0;
        wheelTag =0;
        m_move.setX(0);m_move.setY(0);
        m_angle = 0;
        m_scale = 1;
    }

}

gl::~gl()
{
    makeCurrent();
    VBO.destroy();
    EBO.destroy();
    VAO.destroy();
    doneCurrent();
}

void gl::initializeGL()
{
    initializeOpenGLFunctions();//初始化opengl
    glClearColor(1,1,1,1);//设置清除颜色为白色

    {//着色器部分
        shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexshadersource.vert");
        shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragmentshadersource.frag");
        //shaderProgram.addShaderFromSourceFile(QOpenGLShader::TessellationControl, ":/tesselationControlShader.tcs");
        //shaderProgram.addShaderFromSourceFile(QOpenGLShader::TessellationEvaluation, ":/tesselationEvaluationShader.tes");
        shaderProgram.link();
    }

}

void gl::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void gl::paintGL()
{
    {
        QOpenGLVertexArrayObject::Binder VAOBind(&VAO);//绑定VAO

        QList <GLfloat >list=metalist;//为了绘制内容可更新，使用Qlist
        VBO.create();//生成vbo对象
        VBO.bind();//将vbo对象与当前的上下文绑定
        VBO.allocate(&list[0], (int)list.size()*(int)sizeof (float));//向VBO分配顶点
        qDebug() <<"sizeoflist"<<list.size()/3;

        /*unsigned int indices[] = {
               0,1,2,3
        };//索引数据集
        EBO.create();
        EBO.bind();
        EBO.allocate(indices, sizeof(indices));
    */
        int attr = -1;
        attr = shaderProgram.attributeLocation("aPos");//链接顶点位置
        shaderProgram.setAttributeBuffer(attr, GL_FLOAT, 0, 3, sizeof(GLfloat) * 3);//链接顶点属性：位置值（要配置的顶点属性），数据类型，偏移量 ，维数，步长
        shaderProgram.enableAttributeArray(attr);//启用顶点属性（顶点属性默认是禁用的）

        VBO.release();
    }
    draw();
}

void gl::updatemap(QList<GLfloat> list)
{
    if(FirstTag ==0)
    {
        metalist.clear();
        FirstTag =1;
    }
    this->metalist.append(list);
    repaint();
    qDebug() <<"!!!";

}
void gl::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shaderProgram.bind();

    {//MVP部分
    QMatrix rotate,scale,translate;

    rotate.rotate(qreal(m_angle));
    scale.scale(qreal(m_scale),qreal(m_scale));
    translate.translate(-m_move.x()/300.0,m_move.y()/300.0);

    MVP = rotate  * scale * translate ;
    shaderProgram.setUniformValue("MVP",MVP);
    }

    QOpenGLVertexArrayObject::Binder VAOBind(&VAO);//绑定VAO
//    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glPointSize(0.2f);
    glDrawArrays(GL_LINE_STRIP, 0, metalist.size()/3);

//    glDrawElements(GL_PATCHES, 100, GL_UNSIGNED_INT, 0);//绘制：图元模式，起始索引，顶点数

    shaderProgram.release();

}

void gl::saveAs(const char * format)
{
    QPixmap pixmap = this->grab();
    QString filename =QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("保存为")+QString(format),"","*."+QString(format));
    if(!pixmap.save(filename,format,-1))
        QMessageBox::information(this,QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("保存失败！"));
}

void gl::rotate(float angle)
{
    this->m_angle = angle;
    update();
}

void gl::zoom(float scale)
{
    this->m_scale = scale;
    update();
}

static QPoint pre(0,0),sub(0,0);

void gl::mousePressEvent(QMouseEvent *event)
{
    if(moveTag ==0)
        return;
    pre.setX(event->x());
    pre.setY(event->y());
    this->setCursor(Qt::ClosedHandCursor);
}

void gl::mouseMoveEvent(QMouseEvent *event)
{

    if(moveTag ==0)
        return;
    sub.setX(event->x());
    sub.setY(event->y());

    m_move += pre-sub;//位移向量

    pre.setX(event->x());
    pre.setY(event->y());
    current = pre;
    update();
}

void gl::mouseReleaseEvent(QMouseEvent *event)
{
    if(moveTag ==0)
        return;
    this->setCursor(Qt::OpenHandCursor);
}

void gl::wheelEvent(QWheelEvent *event)
{
    if(wheelTag ==0)
        return;
    QPoint point = event->angleDelta();
    if(m_scale+point.y()/200.0 >0)
        m_scale += point.y()/200.0;
    update();
}
