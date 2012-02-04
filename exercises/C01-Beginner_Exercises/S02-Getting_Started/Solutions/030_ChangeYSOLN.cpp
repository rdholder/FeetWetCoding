// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/030_ChangeYSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int ChangeYSoln::runExercise()
{
    Gsoln = true;

    // USAGE: DrawText("Text.", x, y, color, fontsize);

    DrawText("change y", 50, 300, BLUE, 15);

    return 0;
}
