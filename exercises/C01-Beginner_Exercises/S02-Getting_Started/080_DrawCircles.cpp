// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawCircles::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcCircle(x, y, radius, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    fwcCircle(200, 300, 40, BLUE, 1);
    fwcCircle(200, 100, 50, BLACK, 1, true);
    fwcCircle(200, 200, 100, RED, 10);
}
