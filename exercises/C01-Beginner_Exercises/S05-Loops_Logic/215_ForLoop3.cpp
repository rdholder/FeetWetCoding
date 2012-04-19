// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoops3::runExercise()
{
    int a = 1, x = 385, y = 0;      // = is pronounced GETS, == is pronounced EQUALS

    seeout << "Dangit, the solution for this exercise uses if() but the student";
    seeout << " hasn't seen if() yet!  This exercise needs to be relocated somewhere";
    seeout << " after 210_IfThen1.cpp.\n";

    for ( y = 0; y < 375; y += 25 )
    {
        fwcInt( a, x, y, BLUE, 15);
        a++;
    }
}
