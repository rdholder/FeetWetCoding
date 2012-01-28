// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/DrawingText.cpp

// Chapter 01 Exercise 02: How to draw text on the screen.

// OPEN FeetWetCoding/helpinfo/html/DrawingText.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int DrawingTextSoln::runExercise()
{
    Gsoln = true;

    DrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    DrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    DrawText("Help!",         5, 100, GREEN, 15);
    DrawText("I'm",         100, 100, GREEN, 15);
    DrawText("all",         150, 100, GREEN, 15);
    DrawText("messed",      200, 100, GREEN, 15);
    DrawText("up!",         300, 100, GREEN, 15);

    DrawText("This",          5, 200, RED, 15);
    DrawText("sentence",     50, 200, RED, 15);
    DrawText("is",          150, 200, RED, 15);
    DrawText("out",         200, 200, RED, 15);
    DrawText("of",          250, 200, RED, 15);
    DrawText("order!",      300, 200, RED, 15);

    DrawText("Make",          5, 300, PINK, 10);
    DrawText("these",        40, 300, PINK, 10);
    DrawText("words",        80, 300, PINK, 10);
    DrawText("have",        130, 300, PINK, 10);
    DrawText("fontsize",    180, 300, PINK, 10);
    DrawText("10.",         260, 300, PINK, 10);

    DrawText("Make",        200, 400, GRAY, 15);
    DrawText("these",       200, 425, GRAY, 15);
    DrawText("words",       200, 450, GRAY, 15);
    DrawText("line",        200, 475, GRAY, 15);
    DrawText("up",          200, 500, GRAY, 15);
    DrawText("vertically!", 200, 525, GRAY, 15);

    return 0;
}
