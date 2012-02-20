// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawCircles::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: DrawCircle(x, y, radius, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    DrawCircle(130, 180, 80, BLUE, 1);
    DrawCircle(150, 220, 100, BLACK, 1, true);
    DrawCircle(250, 200, 200, RED, 10);
}
