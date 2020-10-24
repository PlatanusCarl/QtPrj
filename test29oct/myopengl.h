#ifndef MYOPENGL_H
#define MYOPENGL_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class myopengl : public QOpenGLWidget,protected QOpenGLFunctions//继承QOpenGLWidget和QOpenGLFunctions
{
public:
    myopengl(QWidget *parent):QOpenGLWidget(parent){}
protected:
    void initializeGL() override;//设置OpenGL资源和状态
    void resizeGL(int width,int height) override;//设置OpenGL视口，投影等
    void paintGL() override;//渲染OpenGL场景
signals:

};

#endif // MYOPENGL_H
