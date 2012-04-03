// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void Scale::runExercise()
{
    int lightbulbx(0), lightbulby(0), maxradius(100), linewidth(10), fontsize(15);
    int circle1x(200), circle1y(200), circle1radius(3);
    double scalefactor(1.0), maxscale(10.0);
    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the circle size.  Press q to quit.\n";

    int circle1 = fwcCircle(circle1x,circle1y,circle1radius,DARKBLUE,linewidth,true);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "+" )               // == is pronounced "EQUALS" :-)
        {

            //if ( circle1radius < maxradius )
            if ( scalefactor < maxscale )
            {
                fwcScaleItem(circle1, 1.1);
                scalefactor *= 1.1;
            }
        }

        if ( key == "-" )
        {

            //if ( circle1radius > 5 )
            if ( scalefactor > 1.0 )
            {
                fwcScaleItem(circle1, 0.9);
                scalefactor *= 0.9;
            }
        }
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
