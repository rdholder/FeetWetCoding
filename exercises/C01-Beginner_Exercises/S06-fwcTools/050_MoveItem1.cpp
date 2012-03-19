// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void MoveItem1::runExercise()
{
    int x(100), count(0);

    fwcDrawCircle(100,200,75,DARKBLUE,10);
    fwcDrawCircle(300,200,75,DARKBLUE,10);
    int lightbulb = fwcDrawCircle(x, 200, 65, GREEN, 1, true);

    x=0;    // fwcMoveItem needs to be fixed (it's using it's own
            // coordinate space instead of drawing area coords

    for(count = 0; count < 20; count++)
    {
        if(x==0)
        {
            x = 200;
        }
        else
        {
            x = 0;
        }

        fwcMoveItem(lightbulb, x, 0);
        msleep(500);
    }
}
