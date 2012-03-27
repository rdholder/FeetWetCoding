// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawCircles::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcDrawCircle(x, y, radius, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    fwcDrawCircle(200, 300, 40, BLUE, 1);
    fwcDrawCircle(200, 100, 50, BLACK, 1, true);
    fwcDrawCircle(200, 200, 100, RED, 10);
}
