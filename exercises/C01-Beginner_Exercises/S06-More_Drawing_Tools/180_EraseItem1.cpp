// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void EraseItem1::runExercise()
{
    int x(20), y(200);
    int dx(2);
    int dy(0);
    int circle = DrawCircle(x,y,20,DARKRED,1, true);
    int velocity = DrawInt(dy, x+20, y-12, DARKBLUE);

    while (x < 380)
    {
        x+=dx;
        ShiftItem(circle, dx, 0);
        ShiftItem(velocity, dx, dy);
        ChangeInt(velocity, dy);
        msleep(20);
    }
}
