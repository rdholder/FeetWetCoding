// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void C01S05_OYO2Soln::runExercise()
{
    int n=0;

    while ( n++ < 50 )
    {
        DrawCircle(random(400), random(400), random(50), BLUE, 1, true);
    }
    seeout << "Click the \"Re-start Exercise\" button a few times to get an idea";
    seeout << " of the behavior we are looking for here.\n\n";
    seeout << "There are 50 circles of random size and location.\n";
}
