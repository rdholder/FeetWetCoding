// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ShiftSoln::runExercise()
{
    int x(20), y(380);
    int dx(2);
    double dy(-9), rateofchange(0.1);
    int circle = fwcCircle(x,y,10,DARKRED,1, true);
    int velocity = fwcInt(dy, x+20, y-12, DARKBLUE);

    while (x < 380)
    {
        fwcShiftItem(circle, dx, dy);
        fwcShiftItem(velocity, dx, dy);
        fwcChangeInt(velocity, dy);
        x+=dx;
        dy += rateofchange;
        msleep(20);
    }
}
