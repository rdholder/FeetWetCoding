// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int seeoutFormattingSoln::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = true;              // is this exercise code or solution code?

    DrawText("Make the seeout output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1\n";
    seeout << "2\n";
    seeout << "3\n\n\n";
    seeout << "I";
    seeout << " need";
    seeout << " my";
    seeout << " spaces!\n";

    return 0;
}


