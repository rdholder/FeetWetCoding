// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S03.h>
extern bool Gsoln;

int Integers::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;

    // THE EXERCISES IN THIS SECTION ARE MOSTLY FOR YOUR REFERENCE.  DO NOT WORRY
    // IF IT SEEMS CONFUSING OR YOU DON'T GET THE POINT OF WHY WE'RE DOING THIS!
    // You can look at these exercises and run them, and move on.  Types and
    // Variables will make more sense when you get to Section 05.

    int x = 100;            // = is pronounced GETS, == is pronounced EQUALS
    int y = 100;
    int a = 100, b = 100;   // you can declare multiple variables on one line
    int c, d, e = 100;      // remember to initialize every variable!

    DrawText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "x,y: " << x  << "," <<  y << "\n";
    seeout << "apples: " << a << "\n";
    seeout << "bananas: " << b << "\n";
    seeout << "coconuts: " << c << "\n";
    seeout << "dates: " << d << "\n";
    seeout << "emblic: " << e << "\n";

    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    IntegersSoln *solution = new IntegersSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}


