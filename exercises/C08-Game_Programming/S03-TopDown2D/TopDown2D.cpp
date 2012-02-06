// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/.../Tetris.cpp

// Open (double-click) the README.html file to access the documentation.

#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2D.h>
#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.h>

extern FWCView *view;

void TopDown2D::runExercise()
{
    TopDown2DWidget *tw = new TopDown2DWidget(view);
    tw->setIsSolution(false);

    tw->setAutoFillBackground(true);
    tw->setBackgroundRole(QPalette::Window);
    tw->setGeometry(BORDER+2, BORDER/2+2, WINDOW_WIDTH/2-2, WINDOW_HEIGHT-2);

    tw->show();
}


