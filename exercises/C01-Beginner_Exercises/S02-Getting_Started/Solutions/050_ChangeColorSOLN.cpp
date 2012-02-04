// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/050_ChangeColorSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int ChangeColorSoln::runExercise()
{
    Gsoln = true;

    // USAGE: DrawText("Text.", x, y, color, fontsize);

    DrawText("color is RED", 50, 150, RED, 15);

    return 0;
}
