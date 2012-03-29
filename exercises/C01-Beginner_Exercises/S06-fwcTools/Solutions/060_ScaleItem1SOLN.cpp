// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ScaleItem1Soln::runExercise()
{
    int lightbulbx(0), lightbulby(0), maxradius(50), linewidth(10), fontsize(15);
    int circle1x(100), circle1y(200), circle1radius(3);
    int circle2x(200), circle2y(200), circle2radius(3);
    int circle3x(300), circle3y(200), circle3radius(3);
    double scalefactor1(1.0), scalefactor2(1.0), scalefactor3(1.0), maxscale(5.0);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the circle sizes.  Press q to quit.\n";

    int circle1 = fwcDrawCircle(circle1x,circle1y,circle1radius,DARKBLUE,linewidth,true);
    int circle2 = fwcDrawCircle(circle2x,circle2y,circle2radius,DARKBLUE,linewidth,true);
    int circle3 = fwcDrawCircle(circle3x,circle3y,circle3radius,DARKBLUE,linewidth,true);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "+" )               // == is pronounced "EQUALS" :-)
        {

            //if ( circle1radius < maxradius )
            if ( scalefactor1 < maxscale )
            {
                fwcScaleItem(circle1, 1.1);
                scalefactor1 *= 1.1;
            }
            //else if ( circle2radius < maxradius )
            else if ( scalefactor2 < maxscale )
            {
                fwcScaleItem(circle2, 1.05);
                scalefactor2 *= 1.05;
            }
            //else if ( circle3radius < maxradius )
            else if ( scalefactor3 < maxscale )
            {
                fwcScaleItem(circle3, 1.05);
                scalefactor3 *= 1.05;
            }
        }

        if ( key == "-" )               // == is pronounced "EQUALS" :-)
        {

            //if ( circle3radius > 5 )
            if ( scalefactor3 > 1.0 )
            {
                fwcScaleItem(circle3, 0.95);
                scalefactor3 *= 0.95;
            }
            //else if ( circle2radius > 5 )
            else if ( scalefactor2 > 1.0 )
            {
                fwcScaleItem(circle2, 0.95);
                scalefactor2 *= 0.95;
            }
            //else if ( circle1radius > 5 )
            else if ( scalefactor1 > 1.0 )
            {
                fwcScaleItem(circle1, 0.95);
                scalefactor1 *= 0.95;
            }
        }
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
