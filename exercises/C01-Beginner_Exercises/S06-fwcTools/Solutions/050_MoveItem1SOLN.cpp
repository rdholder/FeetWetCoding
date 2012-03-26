// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void MoveItem1Soln::runExercise()
{
    int lightbulbx(0), lightbulby(0), radius(100), linewidth(10), fontsize(15);
    int circleEx(100), circleEy(100);
    int circleWx(300), circleWy(100);
    int circleDx(100), circleDy(300);
    int circleSx(300), circleSy(300);
    std::string key;

    seeout << "Hover mouse over the drawing area above and press e, w, d or s";
    seeout << " to move the lightbulb.  Press q to quit.\n";

    lightbulbx = circleEx;  // fwcMoveItem needs to be fixed (it's using it's own
    lightbulby = circleEy;  // coordinate space instead of drawing area coords

    fwcDrawText("Route Power to:", 50, 0, DARKRED, 25);

    fwcDrawCircle(circleEx,circleEy,radius,DARKBLUE,linewidth);
    fwcDrawCircle(circleWx,circleWy,radius,DARKBLUE,linewidth);
    fwcDrawCircle(circleDx,circleDy,radius,DARKBLUE,linewidth);
    fwcDrawCircle(circleSx,circleSy,radius,DARKBLUE,linewidth);

    fwcDrawText("Engines", circleEx, circleEy+(radius/2)+5, BLACK, 15);
    fwcDrawText("Weapons", circleWx, circleWy+(radius/2)+5, BLACK, 15);
    fwcDrawText("Deflectors", circleDx, circleDy+(radius/2)+5, BLACK, 15);
    fwcDrawText("Sensors", circleSx, circleSy+(radius/2)+5, BLACK, 15);

    int lightbulb = fwcDrawCircle(circleEx, circleEy, radius-linewidth, GREEN, 1, true);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "e" || key == "E" ) // == is pronounced "EQUALS" :-)
        {
            lightbulbx = circleEx;
            lightbulby = circleEy;
        }
        if ( key == "w" || key == "W" )
        {
            lightbulbx = circleWx;
            lightbulby = circleWy;
        }
        if ( key == "d" || key == "D" )
        {
            lightbulbx = circleDx;
            lightbulby = circleDy;
        }
        if ( key == "s" || key == "S" )
        {
            lightbulbx = circleSx;
            lightbulby = circleSy;
        }

        fwcMoveItem(lightbulb, lightbulbx, lightbulby);
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
