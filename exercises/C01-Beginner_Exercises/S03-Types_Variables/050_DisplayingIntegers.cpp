// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int DisplayingIntegers::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;

    int x = 42;     // = is pronounced GETS, == is pronounced EQUALS
    int y = 32767;
    int a = 100;
    int b = 200;

    DrawText("It's a harder to draw variables graphically...", 30, 50, BLUE, 12);
    DrawText("x ==", 30, 100, BLUE, 20);
    DrawInt(x, 30, 100, BLUE, 20);
    DrawText("y ==", 200, 100, BLUE, 20);
    DrawInt(y, 200, 100, BLUE, 20);
    DrawText("a ==", 30, 300, BLUE, 20);
    DrawInt(a, 30, 300, BLUE, 20);
    DrawText("b ==", 200, 300, BLUE, 20);
    DrawInt(b, 200, 300, BLUE, 20);

    seeout << "...than it is to show them with seeout!\n";
    seeout << "x == " << x  << "  y == " << y << "\n";
    seeout << "a == " << a  << "  b == " << b << "\n";


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    DisplayingIntegersSoln *solution = new DisplayingIntegersSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}


