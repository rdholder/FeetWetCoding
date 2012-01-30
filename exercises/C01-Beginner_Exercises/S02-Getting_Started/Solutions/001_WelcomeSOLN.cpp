// copyright (c) 2011 Robert Holder, Janice Dugger.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/001_WelcomeSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int WelcomeSoln::runExercise()
{
    Gsoln = true;

    DrawText("Welcome to FeetWetCoding!", 20, 150, RED, 20);

    return 0;
}
