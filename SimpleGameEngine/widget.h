#ifndef WIDGET_H
#define WIDGET_H
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QBasicTimer>


class SimpleObject3D;
class Group;
class TransformableObject;
class Camera;
class SkyBox;


class Widget : public QOpenGLWidget
{
    Q_OBJECT

private:

    SkyBox* _skybox;

    QVector<SimpleObject3D* > _singleObjects;
    QVector<Group* > _groups;
    QVector<TransformableObject* > _transformableObjects;

    QOpenGLShaderProgram _renderProgram;
    QOpenGLShaderProgram _shaderSkybox;

    Camera* _camera;
    QMatrix4x4 _projectionMatrix;
    QVector2D _mousePosition;

    QBasicTimer _timer;
    float _angObj;
    float _angGroup1;
    float _angGroup2;
    float _angMain;

protected:

    void initializeGL();
    void resizeGL(int width , int height);
    void paintGL();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void timerEvent(QTimerEvent* event);
    void keyPressEvent(QKeyEvent* event);

    void initShaders();
    bool tryInitShader(QOpenGLShaderProgram* program , QString vShaderPath , QString fShaderPath);

    void loadObj(const QString& path);

public:

    Widget(QWidget *parent = 0);
    ~Widget();

};

#endif // WIDGET_H
