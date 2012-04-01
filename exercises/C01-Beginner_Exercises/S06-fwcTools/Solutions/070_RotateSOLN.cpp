// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void RotateSoln::runExercise()
{
    int shipx(200), shipy(200), shipangle(0), degreeturnrate(10);
    std::string key;

    seeout << "Hover mouse over the drawing area above and press a or d";
    seeout << " to rotate the ship.  Press q to quit.\n\n";
    seeout.setColor(DARKRED);
    seeout << "Notice that in the solution, shipangle does not go outside";
    seeout << " the range 0..360.\n\n";
    seeout.setFontSize(12);
    seeout.setColor(DARKGREEN);
    seeout << "shipangle:\n";
    seeout.setColor(BLACK);
    seeout.setFontSize(10);

    int ship = fwcDrawImage("spaceship50x59.jpg", shipx, shipy);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();            // = is pronounced "GETS"

        if ( key == "a" || key == "A" )     // == is pronounced "EQUALS" :-)
        {
            shipangle -= degreeturnrate; // THIS SEEMS BACKWARDS.  - SHOULD ROTATE LEFT, CORRECT?
            if ( shipangle < 0 )
            {
                shipangle = 350;
            }
        }

        if ( key == "d" || key == "D" )
        {
            shipangle += degreeturnrate;
            if ( shipangle > 359 )
            {
                shipangle = 0;
            }
        }
        fwcRotateItem(ship, shipangle);
        seeout << shipangle << "  ";
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
