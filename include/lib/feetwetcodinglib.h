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

extern QTextEdit *exerciseOut;
extern QTextEdit *solnOut;
extern QMutex globalmutex;
extern bool Gsoln;

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

QGraphicsItem* DrawLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness );
QGraphicsItem* DrawCircleRender( int x, int y, int r, Color color, int thickness, bool solid=false);
QGraphicsItem* DrawCircleRGBRender( int x, int y, int r, int thickness, int red, int green, int blue, bool solid=false );
QGraphicsItem* DrawEllipseRender( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
QGraphicsItem* DrawRectangleRender( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
QGraphicsItem* DrawTextRender( std::string text, int x, int y, Color color, int size=12);
QGraphicsItem* DrawIntRender( int number, int x, int y, Color color, int size=12 );
QGraphicsItem* DrawFloatRender( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
QGraphicsItem* DrawImageRender( std::string filename, int x, int y );

int random(int biggest);
int randomRange(int smallest, int biggest);

QColor getQColor( Color color );
std::string getNameForColor( Color color );

class FWCView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit FWCView(QWidget *parent=0) : QGraphicsView(parent){}
    explicit FWCView(QGraphicsScene *scene, QWidget *parent=0):QGraphicsView(scene, parent){}
    ~FWCView(){}

    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void keyPressSignal(QKeyEvent *);

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

////SeeOut is a simulated "cout" that prints to a
//// text widget in addition to std::out
//class SeeOut
//{

//public:

//    void setColor(Color color)
//    {
//        QMutexLocker globallocker(&globalmutex);
//        if ( !Gsoln && exerciseOut )
//        {
//            exerciseOut->setTextColor(getQColor(color));
//        }
//        if ( Gsoln && solnOut )
//        {
//            solnOut->setTextColor(getQColor(color));
//        }
//    }

//    void setFontSize(int size)
//    {
//        QMutexLocker globallocker(&globalmutex);
//        if ( !Gsoln && exerciseOut )
//        {
//            exerciseOut->setFontPointSize(size);
//        }
//        if ( Gsoln && solnOut )
//        {
//            solnOut->setFontPointSize(size);
//        }
//    }

//    template <typename T>
//    SeeOut& operator<<(const T& x)
//    {
//        QMutexLocker locker(&mutex);
//        mOss.str("");
//        mOss << x;
//        std::cerr << mOss.str();

//        QMutexLocker globallocker(&globalmutex);
//        if ( !Gsoln && exerciseOut )
//        {
//            exerciseOut->insertPlainText(mOss.str().c_str());
//        }
//        if ( Gsoln && solnOut )
//        {
//            solnOut->insertPlainText(mOss.str().c_str());
//        }

//        return *this;
//    }

//private:
//    std::ostringstream mOss;
//    QMutex mutex;
//};

#endif // FEETWETCODINGLIB_H
