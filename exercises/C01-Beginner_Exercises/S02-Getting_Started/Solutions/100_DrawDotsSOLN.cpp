// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawDotsSoln::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcDrawLine(xStart, yStart, xEnd, yEnd, color, linewidth);
    // USAGE: fwcDrawCircle(x, y, radius, color, linewidth, solid);
    // USAGE: fwcDrawRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)

    fwcDrawLine(200, 100, 200, 101, BLACK, 1);
    fwcDrawCircle(150, 250, 1, BLUE, 1);
    fwcDrawRectangle(250, 250, 1, 1, RED, 1);
}
