// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void RotateItem1Soln::runExercise()
{
    int shipx(200), shipy(200), shipcompassheading(0), degreeturnrate(10);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press a or d";
    seeout << " to rotate the ship.  Press q to quit.\n\n";
    seeout << "Hm, why isn't the ship centered on 200,200?...\n";

    int ship = fwcDrawImage("spaceship50x59.jpg", shipx, shipy);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();            // = is pronounced "GETS"

        if ( key == "a" || key == "A" )     // == is pronounced "EQUALS" :-)
        {
            shipcompassheading -= degreeturnrate; // THIS SEEMS BACKWARDS.  - SHOULD ROTATE LEFT, CORRECT?
            if ( shipcompassheading < 0 )
            {
                shipcompassheading = 355;
            }
        }

        if ( key == "d" || key == "D" )
        {
            shipcompassheading += degreeturnrate;
            if ( shipcompassheading > 355 )
            {
                shipcompassheading = 0;
            }
        }
        fwcRotateItem(ship, shipcompassheading);
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
