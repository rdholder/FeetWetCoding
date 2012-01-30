// copyright (c) 2011 Robert Holder, Janice Dugger.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/DrawingText.cpp

// Chapter 01 Exercise 02: How to draw text on the screen.

// OPEN FeetWetCoding/helpinfo/html/DrawingText.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int DrawingText::runExercise()      // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;                  // is this exercise code or solution code?

    DrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    DrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    DrawText("Help!",         5, 100, GREEN, 15);
    DrawText("I'm",          50, 100, GREEN, 15);
    DrawText("all",          70, 100, GREEN, 15);
    DrawText("messed",       85, 100, GREEN, 15);
    DrawText("up!",         145, 100, GREEN, 15);

    DrawText("This",        160, 200, RED, 15);
    DrawText("sentence",    210, 200, RED, 15);
    DrawText("is",          300, 200, RED, 15);
    DrawText("out",           5, 200, RED, 15);
    DrawText("of",           50, 200, RED, 15);
    DrawText("order!",      100, 200, RED, 15);

    DrawText("Make",          5, 300, PINK, 8);
    DrawText("these",        40, 300, PINK, 10);
    DrawText("words",        80, 300, PINK, 12);
    DrawText("have",        130, 300, PINK, 14);
    DrawText("fontsize",    180, 300, PINK, 16);
    DrawText("10.",         260, 300, PINK, 18);

    DrawText("Make",        200, 400, GRAY, 15);
    DrawText("these",       210, 425, GRAY, 15);
    DrawText("words",       190, 450, GRAY, 15);
    DrawText("line",        205, 475, GRAY, 15);
    DrawText("up",          195, 500, GRAY, 15);
    DrawText("vertically!", 180, 525, GRAY, 15);

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    DrawingTextSoln *solution = new DrawingTextSoln();
    solution->runExercise();

    return 0;
}
