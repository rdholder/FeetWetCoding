// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <exercises/C01_S02.h>

void DrawDots::runExercise()
{
    // There is nothing for you to change in this exercise.  It just demonstrates
    // how to draw a pixel with DrawLine and small dots with DrawCircle and DrawRectangle.
    // Most of the time in graphical programing, you won't actually draw individual
    // pixels and dots on the screen like this, but you should be aware of how to do it.

    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    // USAGE: DrawCircle(x, y, radius, color, thickness, solid);
    // USAGE: DrawRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)
    DrawLine(200, 100, 200, 100, BLACK, 1);
    DrawCircle(150, 250, 1, BLUE, 1);
    DrawRectangle(250, 250, 1, 1, RED, 1);
}
