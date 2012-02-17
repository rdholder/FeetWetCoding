// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/060_C01S05_OYO1SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void C01S05_OYO1Soln::runExercise()
{
    int x=50;

    while ( x < 400 )
    {
        DrawCircle(x, 200, 20, BLUE, 1, true);
        x += 50;
    }
    seeout << "The first circle is located at 50, 200 with radius 20.\n";
    seeout << "The center of the circles are spaced 50px apart.\n";
}
