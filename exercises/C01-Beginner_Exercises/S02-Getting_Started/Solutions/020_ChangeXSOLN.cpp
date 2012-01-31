// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/020_ChangeXSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int ChangeXSoln::runExercise()
{
    Gsoln = true;

    // USAGE: DrawText("Text.", x, y, color, fontsize);

    DrawText("change x", 300, 150, BLUE, 15);

    return 0;
}
