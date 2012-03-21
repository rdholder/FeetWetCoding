// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawRectangles::runExercise()
{
    // USAGE: fwcDrawRectangle(x, y, width, height, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    fwcDrawRectangle(50, 50, 300, 300, BLACK, 1);
    fwcDrawRectangle(150, 150, 100, 100, RED, 5);
    fwcDrawRectangle(175, 175, 50, 50, BLUE, 10, true);
}
