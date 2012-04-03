// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawingTextSoln::runExercise()
{
    // USAGE: fwcText("Text.", x, y, color, fontsize);

    fwcText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    fwcText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    fwcText("Help!",         5, 70, GREEN, 15);
    fwcText("I'm",         100, 70, GREEN, 15);
    fwcText("all",         150, 70, GREEN, 15);
    fwcText("messed",      200, 70, GREEN, 15);
    fwcText("up!",         300, 70, GREEN, 15);

    fwcText("This",          5, 130, RED, 15);
    fwcText("sentence",     50, 130, RED, 15);
    fwcText("is",          150, 130, RED, 15);
    fwcText("out",         200, 130, RED, 15);
    fwcText("of",          250, 130, RED, 15);
    fwcText("order!",      300, 130, RED, 15);

    fwcText("Make",          5, 180, PINK, 10);
    fwcText("these",        40, 180, PINK, 10);
    fwcText("words",        80, 180, PINK, 10);
    fwcText("have",        130, 180, PINK, 10);
    fwcText("fontsize",    180, 180, PINK, 10);
    fwcText("10.",         260, 180, PINK, 10);

    fwcText("Make",        200, 230, GRAY, 15);
    fwcText("these",       200, 255, GRAY, 15);
    fwcText("words",       200, 280, GRAY, 15);
    fwcText("line",        200, 305, GRAY, 15);
    fwcText("up",          200, 330, GRAY, 15);
    fwcText("vertically!", 200, 355, GRAY, 15);
}
