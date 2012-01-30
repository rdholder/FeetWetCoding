// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int SeeOutIntroSoln::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = true;

    DrawText("Make the \"seeout\" output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << " 1" << "\n";
    seeout << " 2" << "\n";
    seeout << " 3" << "\n";
    seeout << " 4" << "\n";
    seeout << " 5" << "\n";
    seeout << " 6" << "\n";
    seeout << " 7" << "\n";
    seeout << " 8" << "\n";
    seeout << " 9" << "\n";
    seeout << "10" << "\n";

    return 0;
}



