// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/.../Tetris.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <underconstruction/tetris/Tetris.h>
#include <underconstruction/tetris/TetrisWidget.h>

extern bool Gsoln;

int Tetris::runExercise()
{
    Gsoln = false;

    TetrisWidget *tw = new TetrisWidget();

    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    TetrisSoln *solution = new TetrisSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}

