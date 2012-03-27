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

    fwcDrawRectangle(0, 0, 400, 400, BLACK, 1, true);

    fwcDrawRectangle(100, 200, 1, 1, RED, 1);
    fwcDrawLine(200, 200, 200, 201, GREEN, 1);
    fwcDrawCircle(300, 200, 1, BLUE, 1, true);

}
