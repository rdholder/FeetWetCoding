// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S01.h>

void DrawingText::runExercise()
{
    fwcText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    fwcText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    fwcText("Help!",         5, 70, GREEN, 15);
    fwcText("I'm",          50, 70, GREEN, 15);
    fwcText("all",          70, 70, GREEN, 15);
    fwcText("messed",       85, 70, GREEN, 15);
    fwcText("up!",         145, 70, GREEN, 15);

    fwcText("This",        160, 130, RED, 15);
    fwcText("sentence",    210, 130, RED, 15);
    fwcText("is",          300, 130, RED, 15);
    fwcText("out",           5, 130, RED, 15);
    fwcText("of",           50, 130, RED, 15);
    fwcText("order!",      100, 130, RED, 15);

    fwcText("Make",          5, 180, PINK, 8);
    fwcText("these",        40, 180, PINK, 10);
    fwcText("words",        80, 180, PINK, 12);
    fwcText("have",        130, 180, PINK, 14);
    fwcText("fontsize",    180, 180, PINK, 16);
    fwcText("10.",         260, 180, PINK, 18);

    fwcText("Make",        200, 230, GRAY, 15);
    fwcText("these",       210, 255, GRAY, 15);
    fwcText("words",       190, 280, GRAY, 15);
    fwcText("line",        205, 305, GRAY, 15);
    fwcText("up",          195, 330, GRAY, 15);
    fwcText("vertically!", 180, 355, GRAY, 15);
}
