// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void C01S05_OYO2Soln::runExercise()
{
    int n=0;

    while ( n++ < 50 )
    {
        fwcCircle(random(400), random(400), random(25), BLUE, 1, true);
    }
    seeout << "Click the \"Re-start Exercise\" button a few times to get an idea";
    seeout << " of the behavior we are looking for here.\n\n";
    seeout << "There are 50 circles of random location and random size (up to 50).\n";
}
