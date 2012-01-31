// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int seeoutFormatting::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;              // is this exercise code or solution code?

    DrawText("Make the \"seeout\" output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1";
    seeout << "2";
    seeout << "3" << "\n";
    seeout << "I";
    seeout << "need";
    seeout << "my";
    seeout << "spaces!\n";



    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    seeoutFormattingSoln *solution = new seeoutFormattingSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}


