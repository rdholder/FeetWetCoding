// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void RotateItem1::runExercise()
{
    int shipx(200), shipy(200), shipcompassheading(0), degreeturnrate(10);
    bool turnclockwise(true);

    std::string key;

    int ship = fwcDrawImage("spaceship50x59.jpg", shipx, shipy);

    while ( true )
    {
        if ( turnclockwise )     // == is pronounced "EQUALS" :-)
        {
            shipcompassheading -= degreeturnrate; // THIS SEEMS BACKWARDS.  - SHOULD ROTATE LEFT, CORRECT?
            if ( shipcompassheading < 0 )
            {
                shipcompassheading = 355;
                turnclockwise = true;
            }
        }

        if ( !turnclockwise )
        {
            shipcompassheading += degreeturnrate;
            if ( shipcompassheading > 355 )
            {
                shipcompassheading = 0;
                turnclockwise = false;
            }
        }
        fwcRotateItem(ship, shipcompassheading);
        msleep(50);
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
