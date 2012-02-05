// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/DrawingText.cpp

// Chapter 01 Exercise 02: How to draw text on the screen.

// OPEN FeetWetCoding/helpinfo/html/DrawingText.html
// for more information about this exercise.

#include <exercises/C01_S02.h>

void DrawingText::runExercise()
{
    DrawText("This is at location 5, 10 with font size 10 in black.", 5, 10, BLACK, 10);
    DrawText("This is at location 5, 30 with font size 13 in blue.",  5, 30, BLUE, 13);

    DrawText("Help!",         5, 70, GREEN, 15);
    DrawText("I'm",          50, 70, GREEN, 15);
    DrawText("all",          70, 70, GREEN, 15);
    DrawText("messed",       85, 70, GREEN, 15);
    DrawText("up!",         145, 70, GREEN, 15);

    DrawText("This",        160, 130, RED, 15);
    DrawText("sentence",    210, 130, RED, 15);
    DrawText("is",          300, 130, RED, 15);
    DrawText("out",           5, 130, RED, 15);
    DrawText("of",           50, 130, RED, 15);
    DrawText("order!",      100, 130, RED, 15);

    DrawText("Make",          5, 180, PINK, 8);
    DrawText("these",        40, 180, PINK, 10);
    DrawText("words",        80, 180, PINK, 12);
    DrawText("have",        130, 180, PINK, 14);
    DrawText("fontsize",    180, 180, PINK, 16);
    DrawText("10.",         260, 180, PINK, 18);

    DrawText("Make",        200, 230, GRAY, 15);
    DrawText("these",       210, 255, GRAY, 15);
    DrawText("words",       190, 280, GRAY, 15);
    DrawText("line",        205, 305, GRAY, 15);
    DrawText("up",          195, 330, GRAY, 15);
    DrawText("vertically!", 180, 355, GRAY, 15);
}
