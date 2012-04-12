// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void Shift::runExercise()
{
    int x(20), y(200), dx(2), dy(0);
    int circle = fwcCircle(x,y,10,DARKRED,1, true);
    int velocity = fwcInt(dy, x+20, y-12, DARKBLUE);

    while (x < 380)
    {
        x+=dx;
        fwcShiftItem(circle, dx, 0);
        fwcShiftItem(velocity, dx, dy);
        fwcChangeInt(velocity, dy);
        msleep(20);
    }
}
