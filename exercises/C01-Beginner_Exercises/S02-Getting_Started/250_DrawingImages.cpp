// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int DrawingImages::runExercise()
{
    Gsoln = false;

    // WARNING!  Please do not try to add your own images yet!  I know it's fun,
    // but until you are more familiar with Qt Creator and C++, you will most
    // likely just hose your FeetWetCoding project, and then you may not be able to
    // get any exercises to run at all!  We will show you how to use your own
    // images down the road, but there is a lot to learn first.  :-)

    // USAGE: DrawImage("images:/filename.png", x, y);
    DrawImage(":images/ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    DrawImage(":images/BrianKernighan50x58.png", 130, 10);
    DrawImage(":images/BjarneStroustrup50x55.png", 200, 10);
    DrawImage(":images/Qtlogo59x71.png", 300, 10);
    DrawImage(":images/DuckFeet100x45.bmp", 10, 200);
    DrawImage(":images/spaceship50x59.jpg", 200, 200);
    DrawImage(":images/clock100x100.gif", 280, 200);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    DrawingImagesSoln *solution = new DrawingImagesSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
