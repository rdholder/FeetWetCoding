// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void WhileLoop4Soln::runExercise()
{
    int x=0, y=400;
    int velocity= -45;
    int rateofchange=3;
    int horizontalstep = 12;

    while ( x < 400 )
    {
        x += horizontalstep;
        y += velocity;
        velocity += rateofchange;
        fwcDrawCircle(x, y, 10, RED, 1);
        fwcDrawInt(velocity, x+10, y, BLUE, 10);
    }
}
