#include "myopengl.h"

void myopengl::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0,0,0,1);//为色彩缓存器指明RGBA值(Alpha为透明度)

}
void myopengl::resizeGL(int width,int height)
{

}
void myopengl::paintGL()
{

}
