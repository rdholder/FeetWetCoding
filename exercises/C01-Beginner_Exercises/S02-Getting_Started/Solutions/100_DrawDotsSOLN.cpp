// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawDotsSoln::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    // USAGE: DrawCircle(x, y, radius, color, thickness, solid);
    // USAGE: DrawRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)

    DrawLine(200, 100, 200, 100, BLACK, 1);
    DrawCircle(150, 250, 1, BLUE, 1);
    DrawRectangle(250, 250, 1, 1, RED, 1);
}
