// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawDots::runExercise()
{
    // There is nothing for you to change in this exercise.  It just demonstrates
    // how to draw a pixel with fwcLine and small dots with fwcCircle and fwcRectangle.
    // Most of the time in graphical programing, you won't actually draw individual
    // pixels and dots on the screen like this, but you should be aware of how to do it.

    // USAGE: fwcLine(xStart, yStart, xEnd, yEnd, color, linewidth);
    // USAGE: fwcCircle(x, y, radius, color, linewidth, solid);
    // USAGE: fwcRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)

    fwcRectangle(150, 250, 1, 1, RED, 1);
    fwcLine(200, 100, 200, 101, GREEN, 1);
    fwcCircle(250, 250, 1, BLUE, 1, true);

}
