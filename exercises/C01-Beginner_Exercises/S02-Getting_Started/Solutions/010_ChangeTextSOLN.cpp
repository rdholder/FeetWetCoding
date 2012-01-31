// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/010_ChangeTextSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int ChangeTextSoln::runExercise()
{
    Gsoln = true;

    // USAGE: DrawText("Text.", x, y, color, fontsize);

    DrawText("...your name! :-)", 100, 150, BLUE, 15);

    return 0;
}
