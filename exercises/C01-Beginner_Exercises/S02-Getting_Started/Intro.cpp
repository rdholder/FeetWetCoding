// copyright (c) 2011 Robert Holder, Janice Dugger.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/DrawingAreaIntro.cpp

// Chapter 01 Exercise 00: Drawing on the screen.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int Intro::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;        // is this exercise code or solution code?

    DrawLine(0, 30, 60, 30, YELLOW, 5);
    DrawLine(30, 0, 30, 60, BLUE, 5);

    // Uncomment the following lines one at a time, and run the program after uncommenting each line.

//    DrawLine(0, 30, 60, 30, YELLOW, 5);
//    DrawLine(30, 0, 30, 60, BLUE, 5);

//    DrawCircle(300, 100, 80, BLACK, 7, false);
//    DrawCircle(100, 100, 80, BLUE, 7, false);
//    DrawCircle(150, 100, 80,RED, 7, true);
//    DrawCircle(250, 100, 80, GREEN, 7, true);
//    DrawCircle(200, 100, 80, 7, YELLOW, 7, false);

//    DrawRectangle(20, 300, 340, 250, BLACK, 3, true);
//    DrawEllipse(100, 430, 30, 70, BLUE, 1);
//    DrawEllipse(200, 430, 30, 70, YELLOW, 1, false);
//    DrawEllipse(300, 430, 30, 70, RED, 1, true);
//    DrawRectangle(40, 320, 300, 210, RED, 3);

//    DrawLine(0, 0, 400, 600, PINK, 3);
//    DrawLine(0, 600, 400, 0, GREEN, 3);

    // Now you can look at the IntroSOLN to make sure you got it right!

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    IntroSoln *solution = new IntroSoln();
    solution->runExercise();

    return 0;
}

