// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ChangeRadiusSoln::runExercise()
{
    int minradius(5), maxradius(190), step(5), linewidth(10), fontsize(15);
    int circle1x(200), circle1y(200), circle1radius(minradius);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the circle sizes.  Press q to quit.\n";

    int circle1 = fwcDrawCircle(circle1x,circle1y,circle1radius,DARKBLUE,linewidth,true);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "+" )               // == is pronounced "EQUALS" :-)
        {
            if ( circle1radius < maxradius )
            {
                circle1radius += step;
                fwcChangeRadius(circle1, circle1radius);
            }
        }

        if ( key == "-" )               // == is pronounced "EQUALS" :-)
        {
            if ( circle1radius > minradius )
            {
                circle1radius -= step;
                fwcChangeRadius(circle1, circle1radius);
            }
        }
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
