// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void Sleep1::runExercise()
{
    int x=50, y=50;
    int horizontalstep=50, verticalstep=50;
    int delayInMilliseconds = 1000;
    Color color = DARKBLUE;

    seeout << "delayInMilliseconds == " << delayInMilliseconds << "\n";

    for (y = 0; y < 400; y += verticalstep )
    {
        for ( x = 0; x < 400; x += horizontalstep )
        {
            fwcDrawCircle(x, y, 20, color, 1, true);
            msleep(delayInMilliseconds);
        }
        delayInMilliseconds /= 2;
        seeout << "delayInMilliseconds == " << delayInMilliseconds << "\n";
    }
}
