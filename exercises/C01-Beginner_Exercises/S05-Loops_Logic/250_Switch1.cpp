// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void Switch1::runExercise()
{
    int x = 0, y = 0, size = 30;
    int horizontalstep = 50, verticalstep = 50;
    bool iscircle = true;
    Color color = BLUE;

    //DrawRectangle(0, 0, 400, 400, BLACK, 1, true);

    for ( x = 0; x < 400; x += horizontalstep )
    {
        for (y = 0; y < 400; y += verticalstep )
        {
            if ( random(1) == 1 )
            {
                iscircle = true;
            }
            else
            {
                iscircle = false;
            }
            switch ( random(3) ){
            case 1:
                color = BLUE;
                break;
            case 2:
                color = RED;
            }

            if ( random(2) )
            {
                DrawCircle(x, y, size, color, 5 );
            }
            else
            {
                DrawRectangle(x, y, size, size, color, 5 );
            }
        }
    }
}
