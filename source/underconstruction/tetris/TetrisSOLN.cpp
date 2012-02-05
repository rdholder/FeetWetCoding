// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/.../TetrisSOLN.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <underconstruction/tetris/Tetris.h>
#include <underconstruction/tetris/TetrisWidget.h>

extern bool Gsoln;

int TetrisSoln::runExercise()
{
    Gsoln = true;

    TetrisWidget *tw = new TetrisWidget();

    return 0;
}

