// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeLineWidth1::runExercise()
{
    int x(100), y(200), count(0), laserwidth(1);
    int line = fwcDrawLine(x, y, x+200, y, RED, laserwidth);
    int circle1 = fwcDrawCircle(x,y,10,DARKRED,1, true);
    int circle2 = fwcDrawCircle(x+200,y,10,DARKBLUE,1, true);

    while (count++ < 100)
    {
        if (laserwidth == 1)
        {
            laserwidth = 3;
        }
        else
        {
            laserwidth = 1;
        }
        fwcChangeLineWidth(line, laserwidth);
        msleep(50);
    }
}
