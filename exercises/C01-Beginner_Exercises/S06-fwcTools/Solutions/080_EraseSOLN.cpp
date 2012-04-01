// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void EraseItem1Soln::runExercise()
{
    int radius(50), linewidth(1), fontsize(15), circlecount(4);
    int circle1x(150), circle1y(150), circle1z(4);
    int circle2x(250), circle2y(150), circle2z(3);
    int circle3x(150), circle3y(250), circle3z(2);
    int circle4x(250), circle4y(250), circle4z(1);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press 1, 2, 3, or 4";
    seeout << " to delete that circle object.\n";

    int circle1 = fwcDrawCircle(circle1x,circle1y,radius,DARKBLUE,linewidth,true);
    int circle2 = fwcDrawCircle(circle2x,circle2y,radius,DARKRED,linewidth,true);
    int circle3 = fwcDrawCircle(circle3x,circle3y,radius,DARKGREEN,linewidth,true);
    int circle4 = fwcDrawCircle(circle4x,circle4y,radius,YELLOW,linewidth,true);

    fwcDrawText("1",circle1x-radius-20,circle1y,BLUE,20);
    fwcDrawText("2",circle2x+radius,circle2y,BLUE,20);
    fwcDrawText("3",circle3x-radius-20,circle3y,BLUE,20);
    fwcDrawText("4",circle4x+radius,circle4y,BLUE,20);

    while ( circlecount > 0 )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "1" )               // == is pronounced "EQUALS" :-)
        {
            fwcEraseItem(circle1);
            circlecount--;
        }
        if ( key == "2" )
        {
            fwcEraseItem(circle2);
            circlecount--;
        }
        if ( key == "3" )
        {
            fwcEraseItem(circle3);
            circlecount--;
        }
        if ( key == "4" )
        {
            fwcEraseItem(circle4);
            circlecount--;
        }
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
