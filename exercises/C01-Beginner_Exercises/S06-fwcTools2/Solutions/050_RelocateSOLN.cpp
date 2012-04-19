// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void RelocateSoln::runExercise()
{
    int lightbulbx(0), lightbulby(0), radius(50), linewidth(10), fontsize(15);
    int circleWx(100), circleWy(100);
    int circleEx(300), circleEy(100);
    int circleSx(100), circleSy(300);
    int circleDx(300), circleDy(300);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press e, w, d or s";
    seeout << " to move the lightbulb.  Press q to quit.\n";

    lightbulbx = circleEx;  // fwcMoveItem needs to be fixed (it's using it's own
    lightbulby = circleEy;  // coordinate space instead of drawing area coords

    fwcText("Route Power to:", 50, 0, DARKRED, 25);

    fwcCircle(circleEx,circleEy,radius,DARKBLUE,linewidth);
    fwcCircle(circleWx,circleWy,radius,DARKBLUE,linewidth);
    fwcCircle(circleDx,circleDy,radius,DARKBLUE,linewidth);
    fwcCircle(circleSx,circleSy,radius,DARKBLUE,linewidth);

    fwcText("Weapons", circleWx, circleWy+(radius)+5, BLACK, 15);
    fwcText("Engines", circleEx, circleEy+(radius)+5, BLACK, 15);
    fwcText("Sensors", circleSx, circleSy+(radius)+5, BLACK, 15);
    fwcText("Deflectors", circleDx, circleDy+(radius)+5, BLACK, 15);

    int lightbulb = fwcCircle(circleEx, circleEy, radius-linewidth/2, GREEN, 1, true);

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
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
