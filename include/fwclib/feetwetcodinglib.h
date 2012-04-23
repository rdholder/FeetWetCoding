// FeetWetCoding/include/feetwetcodinglib.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef FEETWETCODINGLIB_H
#define FEETWETCODINGLIB_H

#include <include/fwclib/colors.h>
#include <QGraphicsView>
#include <QKeyEvent>


//////////////////////////////////////////////
//  FWC convenience functions for the user
//////////////////////////////////////////////

int random(int biggest);
int randomRange(int smallest, int biggest);
QColor getQColor( Color color );
std::string getNameForColor( Color color );



//////////////////////////////////////////////
//  FWC Internals
//////////////////////////////////////////////

//FWC drawing utils
void ClearScreen();
void ClearOutputArea();
QGraphicsItem* fwcLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth );
QGraphicsItem* fwcCircleRender( int x, int y, int r, Color color, int linewidth, bool solid=false);
QGraphicsItem* fwcCircleRGBRender( int x, int y, int r, int linewidth, int red, int green, int blue, bool solid=false );
QGraphicsItem* fwcEllipseRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcRectangleRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcTextRender( std::string text, int x, int y, Color color, int size=12);
QGraphicsItem* fwcIntRender( int number, int x, int y, Color color, int size=12 );
QGraphicsItem* fwcFloatRender( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
QGraphicsItem* fwcImageRender( std::string filename, int x, int y );


#endif // FEETWETCODINGLIB_H
