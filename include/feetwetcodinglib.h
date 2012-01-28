// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/include/FeetWetCodinglib.h

// Function prototypes for the simplified graphical and other functions
// provided to the student.

#ifndef FEETWETCODINGLIB_H
#define FEETWETCODINGLIB_H

#include <constants.h>
#include <QColor>
#include <QKeyEvent>
#include <QPaintEvent>

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

//Function declarations
void setupDrawingUtils();

void ClearScreen();
void DrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness );
void DrawCircle( int x, int y, int r, Color color, int thickness, bool solid=false);
void DrawCircleRGB( int x, int y, int r, int thickness, int red, int green, int blue, bool solid=false );
void DrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
void DrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
void DrawText( std::string text, int x, int y, Color color, int size=12);
void DrawInt( int number, int x, int y, Color color, int size=12 );
void DrawFloat( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
void DrawImage( QString filename, int x, int y );
void DrawReferenceBox( RefBoxLayout layout );
int random(int biggest);
int randomRange(int smallest, int biggest);
//void PuzzleSetup(RefBoxLayout orientation, bool soln);

Qt::GlobalColor getQColor( Color color );

class eoView : public QGraphicsView
{
public:

    explicit eoView(QWidget *parent=0):QGraphicsView(parent){}
    explicit eoView(QGraphicsScene *scene, QWidget *parent=0):QGraphicsView(scene, parent){}
    ~eoView(){}

    virtual void keyPressEvent(QKeyEvent *event);
//    virtual void paintEvent(QPaintEvent *event);

protected:


private:

};

class solutionOrientation
{
public:
    solutionOrientation(RefBoxLayout initialOrientation);
    ~solutionOrientation();
    RefBoxLayout getOrientation();
    void setOrientation(RefBoxLayout);

private:
    RefBoxLayout itsOrientation;

};

#endif // FEETWETCODINGLIB_H
