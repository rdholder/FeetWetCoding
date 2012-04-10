// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S01.h>

void DrawRectangles::runExercise()
{
    // USAGE: fwcRectangle(x, y, width, height, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    fwcRectangle(50, 50, 300, 300, BLACK, 1);
    fwcRectangle(150, 150, 100, 100, RED, 5);
    fwcRectangle(175, 175, 50, 50, BLUE, 10, true);
}
