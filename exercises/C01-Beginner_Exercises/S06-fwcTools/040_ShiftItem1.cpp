// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ShiftItem1::runExercise()
{
    int x(20), y(200);
    int dx(2);
    int dy(0);
    int circle = fwcDrawCircle(x,y,20,DARKRED,1, true);
    int velocity = fwcDrawInt(dy, x+20, y-12, DARKBLUE);

    while (x < 380)
    {
        x+=dx;
        fwcShiftItem(circle, dx, 0);
        fwcShiftItem(velocity, dx, dy);
        fwcChangeInt(velocity, dy);
        msleep(20);
    }
}
