// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop4::runExercise()
{
    int x=0, y=400;                 // = is pronounced GETS, == is pronounced EQUALS
    int velocity= -45;
    int rateofchange=1;
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
