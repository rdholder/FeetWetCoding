// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/010_ChangeText.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int ChangeText::runExercise()
{
    Gsoln = false;  // Don't worry about what Gsoln is yet.  :-)

    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("Change this text to...", 50, 150, BLUE, 15);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    ChangeTextSoln *solution = new ChangeTextSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
