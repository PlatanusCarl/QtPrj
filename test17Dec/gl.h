#ifndef GL_H
#define GL_H
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QMatrix>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <vector>
using namespace std;

class gl :public QOpenGLWidget, protected QOpenGLFunctions_4_1_Core
{
public:
    gl(QWidget *parent = nullptr);
    ~gl() override;
    void updatemap(QList <GLfloat> list);
    void saveAs(const char * format);
    void rotate(float angle);
    void zoom(float scale);
    int moveTag;
    int wheelTag;
    QPoint current;
protected:
    void initializeGL() override;
    void resizeGL(int width,int height) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
signals:
    void wheelChanged(int value);
private:
    void draw();
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer VBO, EBO;
    QOpenGLVertexArrayObject VAO;
    QMatrix MVP;
    QList <GLfloat >metalist={ 0.5f,0.0f,0,
                               0.0f,0.5f,0,
                              -0.5f,0.0f,0};

    float m_angle;
    float m_scale;
    QPoint m_move;
};

#endif // GL_H
