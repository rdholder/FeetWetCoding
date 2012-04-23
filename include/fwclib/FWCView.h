#ifndef FWCVIEW_H
#define FWCVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

//FWCView class provides access to the scene and handles keyboard and mouse events
class FWCView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit FWCView(QWidget *parent=0) : QGraphicsView(parent){}
    explicit FWCView(QGraphicsScene *scene, QWidget *parent=0):QGraphicsView(scene, parent){}
    ~FWCView(){}

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

signals:
    void keyPressSignal(QKeyEvent *);
    void newMousePos(QPoint);
    void sceneCleared();

protected:


private:

};

#endif // FWCVIEW_H
