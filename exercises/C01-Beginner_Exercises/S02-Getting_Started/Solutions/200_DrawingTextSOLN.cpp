// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawingTextSoln::runExercise()
{
    // USAGE: DrawText("Text.", x, y, color, fontsize);

    DrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    DrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    DrawText("Help!",         5, 70, GREEN, 15);
    DrawText("I'm",         100, 70, GREEN, 15);
    DrawText("all",         150, 70, GREEN, 15);
    DrawText("messed",      200, 70, GREEN, 15);
    DrawText("up!",         300, 70, GREEN, 15);

    DrawText("This",          5, 130, RED, 15);
    DrawText("sentence",     50, 130, RED, 15);
    DrawText("is",          150, 130, RED, 15);
    DrawText("out",         200, 130, RED, 15);
    DrawText("of",          250, 130, RED, 15);
    DrawText("order!",      300, 130, RED, 15);

    DrawText("Make",          5, 180, PINK, 10);
    DrawText("these",        40, 180, PINK, 10);
    DrawText("words",        80, 180, PINK, 10);
    DrawText("have",        130, 180, PINK, 10);
    DrawText("fontsize",    180, 180, PINK, 10);
    DrawText("10.",         260, 180, PINK, 10);

    DrawText("Make",        200, 230, GRAY, 15);
    DrawText("these",       200, 255, GRAY, 15);
    DrawText("words",       200, 280, GRAY, 15);
    DrawText("line",        200, 305, GRAY, 15);
    DrawText("up",          200, 330, GRAY, 15);
    DrawText("vertically!", 200, 355, GRAY, 15);
}
