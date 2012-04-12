// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void Relocate::runExercise()
{
    int lightbulbx(0), lightbulby(0), radius(25), linewidth(10), fontsize(15);
    int circleAx(100), circleAy(200);
    int circleBx(300), circleBy(200);
    std::string key;

    lightbulbx = circleAx;  // fwcMoveItem needs to be fixed (it's using it's own
    lightbulby = circleAy;  // coordinate space instead of drawing area coords

    seeout << "Hover mouse over the drawing area above and press a or b";
    seeout << " to move the lightbulb.  Press q to quit.\n\n";

    fwcCircle(circleAx,circleAy,radius,DARKBLUE,linewidth);
    fwcCircle(circleBx,circleBy,radius,DARKBLUE,linewidth);

    fwcText("A", circleAx, circleAy+(radius)+5, BLACK, 25);
    fwcText("B", circleBx, circleBy+(radius)+5, BLACK, 25);

    int lightbulb = fwcCircle(circleAx, circleAy, radius-linewidth/2, GREEN, 1, true);

    seeout << "lightbulb == " << lightbulb << "\n";
    seeout << "circleAx == " << circleAx << "\n";
    seeout << "circleAy == " << circleAy << "\n";
    seeout << "circleBx == " << circleBx << "\n";
    seeout << "circleBy == " << circleBy << "\n";
    seeout << "radius == " << radius << "\n";
    seeout << "circleAy+radius == " << circleAy+radius << "\n";

    fwcLine(circleAx-2, circleAy, circleAx+2, circleAy, BLACK, 1);
    fwcCircle(circleAx,circleAy+radius,2,RED,1,true);
    fwcLine(circleAx-2, circleAy+radius, circleAx+2, circleAy+radius, WHITE, 1);


    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "a" || key == "A" ) // == is pronounced "EQUALS" :-)
        {
            lightbulbx = circleAx;
            lightbulby = circleAy;
        }
        if ( key == "b" || key == "B" )
        {
            lightbulbx = circleBx;
            lightbulby = circleBy;
        }

        fwcMoveItem(lightbulb, lightbulbx, lightbulby);

        seeout << "lightbulb == " << lightbulb << "\n";
        seeout << "lightbulbx, lightbulby == " << lightbulbx << "," << lightbulby << "\n\n";
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
