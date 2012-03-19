// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawRectanglesSoln::runExercise()
{
    // USAGE: fwcDrawRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcDrawRectangle(50, 50, 50, 50, BLACK, 1);
    fwcDrawRectangle(150, 150, 50, 100, RED, 5, true);
    fwcDrawRectangle(250, 250, 100, 50, BLUE, 10);
}
