// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/DrawingAreaIntroSOLutioN.cpp

// Chapter 01 Exercise 00: Drawing on the screen.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int IntroSoln::runExercise()
{
    Gsoln = true;

    // This is what your Intro.cpp file should look like when you finished
    // uncommenting all the non-english lines to see what they do.  (It's OK that the
    // english comment lines here are different, the compiler doesn't care about comments.)

    // The numbers here determine the location, size and line thickness of the objects
    // on the screen.  "true" and "false" here refer to whether the circle or rectangle
    // is filled in with color or not.

    // The order of these statements determines what gets drawn on top of what.
    // Objects that are drawn later are drawn on top of objects that were drawn earlier.

    DrawLine(0, 30, 60, 30, YELLOW, 5);
    DrawLine(30, 0, 30, 60, BLUE, 5);

    DrawCircle(300, 100, 80, BLACK, 7, false);
    DrawCircle(100, 100, 80, BLUE, 7, false);
    DrawCircle(150, 100, 80, RED, 7, true);
    DrawCircle(250, 100, 80, GREEN, 7, true);
    DrawCircle(200, 100, 80, YELLOW, 7, false);

    DrawRectangle(20, 300, 340, 250, BLACK, 3, true);
    DrawEllipse(100, 430, 30, 70, BLUE, 1);
    DrawEllipse(200, 430, 30, 70, YELLOW, 1, false);
    DrawEllipse(300, 430, 30, 70, RED, 1, true);
    DrawRectangle(40, 320, 300, 210, RED, 3);

    DrawLine(0, 0, 400, 600, PINK, 3);
    DrawLine(0, 600, 400, 0, GREEN, 3);

    return 0;
}


