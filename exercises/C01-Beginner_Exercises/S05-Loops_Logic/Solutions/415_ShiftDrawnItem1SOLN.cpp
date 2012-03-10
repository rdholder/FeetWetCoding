// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ShiftDrawnItem1Soln::runExercise()
{
    int x(20), y(380);
    int dx(2);
    double dy(-9), rateofchange(0.1);
    int circle = DrawCircle(x,y,20,DARKRED,1, true);
    int velocity = DrawInt(dy, x+20, y-12, DARKBLUE);

    while (x < 380)
    {
        ShiftDrawnItem(circle, dx, dy);
        ShiftDrawnItem(velocity, dx, dy);
        x+=dx;
        dy += rateofchange;
        msleep(20);
    }
}
