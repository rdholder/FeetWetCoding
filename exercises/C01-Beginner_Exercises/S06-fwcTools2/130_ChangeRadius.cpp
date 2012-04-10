// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeRadius::runExercise()
{
    int minradius(5), maxradius(50), step(5), linewidth(10), fontsize(15);
    int circle1x(100), circle1y(200), circle1radius(minradius);
    int circle2x(200), circle2y(200), circle2radius(minradius);
    int circle3x(300), circle3y(200), circle3radius(minradius);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the circle sizes.  Press q to quit.\n";

    int circle1 = fwcCircle(circle1x,circle1y,circle1radius,DARKBLUE,linewidth,true);
    int circle2 = fwcCircle(circle2x,circle2y,circle2radius,DARKBLUE,linewidth,true);
    int circle3 = fwcCircle(circle3x,circle3y,circle3radius,DARKBLUE,linewidth,true);

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
            else if ( circle2radius < maxradius )
            {
                circle2radius += step;
                fwcChangeRadius(circle2, circle2radius);
            }
            else if ( circle3radius < maxradius )
            {
                circle3radius += step;
                fwcChangeRadius(circle3, circle3radius);
            }
        }

        if ( key == "-" )               // == is pronounced "EQUALS" :-)
        {
            if ( circle3radius > minradius )
            {
                circle3radius -= step;
                fwcChangeRadius(circle3, circle3radius);
            }
            else if ( circle2radius > minradius )
            {
                circle2radius -= step;
                fwcChangeRadius(circle2, circle2radius);
            }
            else if ( circle1radius > minradius )
            {
                circle1radius -= step;
                fwcChangeRadius(circle1, circle1radius);
            }
        }
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
