// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawingText::runExercise()
{
    fwcDrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    fwcDrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    fwcDrawText("Help!",         5, 70, GREEN, 15);
    fwcDrawText("I'm",          50, 70, GREEN, 15);
    fwcDrawText("all",          70, 70, GREEN, 15);
    fwcDrawText("messed",       85, 70, GREEN, 15);
    fwcDrawText("up!",         145, 70, GREEN, 15);

    fwcDrawText("This",        160, 130, RED, 15);
    fwcDrawText("sentence",    210, 130, RED, 15);
    fwcDrawText("is",          300, 130, RED, 15);
    fwcDrawText("out",           5, 130, RED, 15);
    fwcDrawText("of",           50, 130, RED, 15);
    fwcDrawText("order!",      100, 130, RED, 15);

    fwcDrawText("Make",          5, 180, PINK, 8);
    fwcDrawText("these",        40, 180, PINK, 10);
    fwcDrawText("words",        80, 180, PINK, 12);
    fwcDrawText("have",        130, 180, PINK, 14);
    fwcDrawText("fontsize",    180, 180, PINK, 16);
    fwcDrawText("10.",         260, 180, PINK, 18);

    fwcDrawText("Make",        200, 230, GRAY, 15);
    fwcDrawText("these",       210, 255, GRAY, 15);
    fwcDrawText("words",       190, 280, GRAY, 15);
    fwcDrawText("line",        205, 305, GRAY, 15);
    fwcDrawText("up",          195, 330, GRAY, 15);
    fwcDrawText("vertically!", 180, 355, GRAY, 15);
}
