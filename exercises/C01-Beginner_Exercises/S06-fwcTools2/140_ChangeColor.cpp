// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeColor::runExercise()
{
    int light_bars_up_to(0), count(0);
    int barwidth(70), barheight(20), linewidth(1);
    int bar1x(25), bar1y(200);
    int bar2x(bar1x+barwidth), bar2y(200);
    int bar3x(bar2x+barwidth), bar3y(200);
    int bar4x(bar3x+barwidth), bar4y(200);
    int bar5x(bar4x+barwidth), bar5y(200);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the total bar length.  Press q to quit.";
    seeout << " (What happens when you press other keys?)\n\n";
    seeout.setFontSize(12);
    seeout.setColor(DARKGREEN);
    seeout << "light_bars_up_to:\n";
    seeout.setColor(BLACK);
    seeout.setFontSize(10);

    fwcRectangle(0,0,400,400,BLACK,1,true);

    int bar1 = fwcRectangle(bar1x,bar1y,barwidth,barheight,WHITE,linewidth,true);
    int bar2 = fwcRectangle(bar2x,bar2y,barwidth,barheight,WHITE,linewidth,true);

    while (key != "q" && key != "Q")
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if (key == "+")                 // == is pronounced "EQUALS" :-)
        {
            light_bars_up_to++;
            if (light_bars_up_to > 2)
            {
                light_bars_up_to = 2;
            }
        }

        if ( key == "-" )
        {
            light_bars_up_to--;
            if (light_bars_up_to < 0)
            {
                light_bars_up_to = 0;
            }
        }

        seeout << light_bars_up_to << " ";

        fwcChangeColor(bar1, WHITE, true);  // reset all the bars to white
        fwcChangeColor(bar2, WHITE, true);  // every keystroke loop...

        if (light_bars_up_to > 0)
        {
            fwcChangeColor(bar1, DARKRED, true);    // ...then color them DARKRED up to
            if (light_bars_up_to > 1)                  // light_bars_up_to number of bars
            {
                fwcChangeColor(bar2, DARKRED, true);
            }
        }
    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
