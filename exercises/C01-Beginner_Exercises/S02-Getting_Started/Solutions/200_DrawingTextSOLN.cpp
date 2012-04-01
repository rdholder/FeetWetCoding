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
    // USAGE: fwcDrawText("Text.", x, y, color, fontsize);

    fwcDrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    fwcDrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    fwcDrawText("Help!",         5, 70, GREEN, 15);
    fwcDrawText("I'm",         100, 70, GREEN, 15);
    fwcDrawText("all",         150, 70, GREEN, 15);
    fwcDrawText("messed",      200, 70, GREEN, 15);
    fwcDrawText("up!",         300, 70, GREEN, 15);

    fwcDrawText("This",          5, 130, RED, 15);
    fwcDrawText("sentence",     50, 130, RED, 15);
    fwcDrawText("is",          150, 130, RED, 15);
    fwcDrawText("out",         200, 130, RED, 15);
    fwcDrawText("of",          250, 130, RED, 15);
    fwcDrawText("order!",      300, 130, RED, 15);

    fwcDrawText("Make",          5, 180, PINK, 10);
    fwcDrawText("these",        40, 180, PINK, 10);
    fwcDrawText("words",        80, 180, PINK, 10);
    fwcDrawText("have",        130, 180, PINK, 10);
    fwcDrawText("fontsize",    180, 180, PINK, 10);
    fwcDrawText("10.",         260, 180, PINK, 10);

    fwcDrawText("Make",        200, 230, GRAY, 15);
    fwcDrawText("these",       200, 255, GRAY, 15);
    fwcDrawText("words",       200, 280, GRAY, 15);
    fwcDrawText("line",        200, 305, GRAY, 15);
    fwcDrawText("up",          200, 330, GRAY, 15);
    fwcDrawText("vertically!", 200, 355, GRAY, 15);
}
