// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawEllipsesSoln::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcDrawEllipse(x, y, width, height, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcDrawEllipse(200, 100, 300, 50, BLUE, 1, true);
    fwcDrawEllipse(200, 200, 300, 30, RED, 5);
    fwcDrawEllipse(200, 300, 300, 10, BLACK, 1);
}
