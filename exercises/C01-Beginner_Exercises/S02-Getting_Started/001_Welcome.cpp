// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/001_Welcome.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int Welcome::runExercise()
{
    Gsoln = false;

    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("Welcome to FeetWetCoding!", 20, 150, BLUE, 20);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    WelcomeSoln *solution = new WelcomeSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
