// FeetWetCoding/include/feetwetcodinglib.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef FEETWETCODINGLIB_H
#define FEETWETCODINGLIB_H

#include <include/lib/constants.h>
#include <include/lib/colors.h>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTextEdit>
#include <QMutex>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <queue>

//Convenience drawable items provided by Qt
//--------------------------------------------
//QGraphicsEllipseItem : provides an ellipse item
//QGraphicsLineItem : provides a line item
//QGraphicsPathItem : provides an arbitrary path item
//QGraphicsPixmapItem : provides a pixmap item
//QGraphicsPolygonItem : provides a polygon item
//QGraphicsRectItem : provides a rectangular item
//QGraphicsSimpleTextItem : provides a simple text label item
//QGraphicsTextItem : provides an advanced text browser item

//Forward class declarations
class FeetWetCodingExercise;

//Function declarations
FeetWetCodingExercise * exerciseFactory( std::string const& name );
void appSetup();
void initSettingsFile();
void setupDrawingUtils();

void ClearScreen();
void initOutputArea();

QGraphicsItem* fwcDrawLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth );
QGraphicsItem* fwcDrawCircleRender( int x, int y, int r, Color color, int linewidth, bool solid=false);
QGraphicsItem* fwcDrawCircleRGBRender( int x, int y, int r, int linewidth, int red, int green, int blue, bool solid=false );
QGraphicsItem* fwcDrawEllipseRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcDrawRectangleRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcDrawTextRender( std::string text, int x, int y, Color color, int size=12);
QGraphicsItem* fwcDrawIntRender( int number, int x, int y, Color color, int size=12 );
QGraphicsItem* fwcDrawFloatRender( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
QGraphicsItem* fwcDrawImageRender( std::string filename, int x, int y );

int random(int biggest);
int randomRange(int smallest, int biggest);

QColor getQColor( Color color );
std::string getNameForColor( Color color );
QString getDefaultConfigFilePath();

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

class solutionOrientation
{
public:

    typedef enum {
        BLANK,
        LEFTRIGHT,
        TOPBOTTOM
    } RefBoxLayout;

    solutionOrientation(RefBoxLayout initialOrientation);
    ~solutionOrientation();
    RefBoxLayout getOrientation();
    void setOrientation(RefBoxLayout);

private:
    RefBoxLayout itsOrientation;

};

#endif // FEETWETCODINGLIB_H
