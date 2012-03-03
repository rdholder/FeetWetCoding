// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void IfThen4Soln::runExercise()
{
    int x=0, y=0;
    int horizontalstep=50, verticalstep=50;
    Color color = DARKBLUE;
    int boxsize = 20;

    for ( y = 0; y < 400; y += verticalstep )
    {
        for (x = 0; x < 400; x += horizontalstep )
        {
            boxsize = 200 - ((100-x/15) + (100-y/15));
            DrawRectangle(x, y, boxsize, boxsize, color, 1, true);
        }
    }
}