// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/GraphicTools1.cpp

// Chapter 01 Exercise 00: Drawing on the screen.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int GraphicTools1::runExercise()    // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;                  // is this exercise code or solution code?

    DrawLine(  0,  0, 175,  50,  RED, 1);
    DrawLine( 10, 10, 350,  10,  YELLOW, 5);
    DrawLine(175,  0, 175,  50,  GREEN, 2);
    DrawLine( 10, 30, 350,  30, YELLOW, 10);
    DrawLine(350,  0, 175,  50,  BLUE, 3);

    DrawCircle( 10, 100, 20, BLACK, 1);
    DrawCircle(100, 100, 40, GREEN, 2);
    DrawCircle(200, 100, 60, YELLOW, 3, true);
    DrawCircle(300, 100,  1, RED, 1);
    DrawLine(10, 100, 200, 100, BLUE, 1);

    DrawEllipse( 10, 200, 20, 20, BLACK, 2);
    DrawEllipse(100, 200, 20, 40, GREEN, 1);
    DrawEllipse(200, 200, 70, 30, YELLOW, 5, true);
    DrawEllipse(300, 200,  1,  1, RED, 1);
    DrawEllipse(350, 200,  1, 30, PINK, 1);
    DrawLine(10, 200, 200, 200, BLUE, 1);

    DrawRectangle( 10, 300, 20, 20, BLACK, 1);
    DrawRectangle(100, 300, 10, 40, GREEN, 3);
    DrawRectangle(200, 300, 30, 50, YELLOW, 1, true);
    DrawRectangle(300, 300,  1,  1, RED, 1);
    DrawRectangle(350, 300,  1, 30, PINK, 1);
    DrawLine(10, 300, 200, 300, BLUE, 1);

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    GraphicTools1Soln *solution = new GraphicTools1Soln();
    solution->runExercise();

    return 0;
}
