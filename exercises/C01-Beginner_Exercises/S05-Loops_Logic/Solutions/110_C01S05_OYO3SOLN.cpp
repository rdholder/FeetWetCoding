// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void C01S05_OYO3Soln::runExercise()
{
    int x=0, y=0;
    int step=10;

    while ( x < 200 )
    {
        x += step;
        y = x;
        DrawRectangle(x, y, 400-(x*2), 400-(y*2), BLUE, 2);
        DrawRectangle(x+5, y+5, 390-(x*2), 390-(y*2), RED, 2);
    }
    seeout << "Makes for kind of a psychedelic optical illusion, huh?\n";
    seeout << "That's not your screen flickering, that's some property of how\n";
    seeout << "the hardware in your eyes and brain process lines and colors!\n\n";
    seeout << "Hint:  you can use two while loops if you want, but it is\n";
    seeout << "possible to do it with one.  This one takes a little fiddling\n";
    seeout << "with to get right.  You can do it! :-)\n";
}
