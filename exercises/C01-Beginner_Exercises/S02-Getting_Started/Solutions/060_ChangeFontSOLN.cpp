// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int ChangeFontSoln::runExercise()
{
    Gsoln = true;

    DrawText("...to fontsize 30.", 50, 150, BLUE, 30);

    return 0;
}
