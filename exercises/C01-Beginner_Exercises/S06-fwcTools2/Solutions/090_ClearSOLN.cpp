// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ClearSoln::runExercise()
{
    int x(100), y(0), count(0), numberofcircles(50), objectsize(20);
    int fontSize(200);
    std::string key;
    Color color = DARKGREEN;

    seeout.setColor(DARKRED);
    seeout.setFontSize(15);
    seeout << "Hover mouse over the exercise drawing area and press keys, or q to quit.\n";

    while ( key != "q" && key != "Q" )
    {
        fwcClearItems();
        for(count=0; count<numberofcircles; ++count)
        {
            x=random(400-(objectsize*2))+objectsize;
            y=random(400-(objectsize*2))+objectsize;
            fwcCircle(x,y,objectsize,DARKRED,1,true);
        }

        key = waitForKeyPress();
    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, color, 60);
}
