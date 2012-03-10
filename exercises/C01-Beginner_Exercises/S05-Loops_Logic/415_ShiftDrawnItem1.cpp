// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ShiftDrawnItem1::runExercise()
{
    int x(20), y(200);
    int dx(2);
    int circle = DrawCircle(x,y,20,DARKRED,1, true);

    while (x < 380)
    {
        x+=dx;
        ShiftDrawnItem(circle, dx, 0);
        msleep(20);
    }
}
