// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeZ1::runExercise()
{
    int radius(100), linewidth(1), fontsize(15);
    int circle1x(150), circle1y(200), circle1z(2);
    int circle2x(250), circle2y(200), circle2z(1);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press 1 or 2";
    seeout << " to increase that circle's Z.  Press q to quit.\n";

    int circle1 = fwcDrawCircle(circle1x,circle1y,radius,DARKBLUE,linewidth,true);
    int circle2 = fwcDrawCircle(circle2x,circle2y,radius,DARKRED,linewidth,true);

    fwcDrawText("1",circle1x-radius-20,circle1y,BLACK,20);
    fwcDrawText("2",circle2x+radius,circle2y,BLACK,20);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "1" )               // == is pronounced "EQUALS" :-)
        {
            fwcChangeZ(circle1, ++circle1z);
        }
        if ( key == "2" )
        {
            fwcChangeZ(circle2, ++circle2z);
        }

        seeout << "Z values: circle1z(" << circle1z << ") circle2z(" << circle2z << ")\n";
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
