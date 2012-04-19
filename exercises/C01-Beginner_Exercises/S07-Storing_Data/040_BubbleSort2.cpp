// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S07.h>

void BubbleSort2::runExercise()
{

    Color color = DARKBLUE;
    int bar(0), swapper(0);
    int number_of_bars(400);
    int bar_height[number_of_bars];
    bool swap_occurred(true);  // init to true so while loop runs at least once

    std::string key;

    seeout << "If your screen flickers during this exercise, that's not a fault of Qt.";
    seeout << " Rather it is because of how fwc does multi-threading and graphical rendering.";
    seeout << " Just didn't want you to think Qt can't do graphics smoothly, because it can!";
    seeout << " While fwc is a convenient and fun environment to learn with, this exercise is";
    seeout << " actually a pretty good demonstration of why fwc is not really";
    seeout << " a good platform for developing \"real\" software projects (although it should";
    seeout << " be fine for small hobbyist projects and small games).\n\n";
    seeout << "Also, the graph above is a good way to see how random the random number generator";
    seeout << " is.  The less random the random number generator is, the more the graph";
    seeout << " deviates from the red line.  Generating truly random numbers is hard!\n\n";

    for (bar = 0; bar < number_of_bars; bar++ )  // always initialize your array!
    {
        bar_height[bar] = random(400);
        fwcLine(bar,400,bar,400-bar_height[bar-1],color,1);
        seeout << "bar_height[" << bar << "] == " << bar_height[bar] << "\n";
    }

    while (swap_occurred && key != "q" && key != "Q")
    {
        //key = waitForKeyPress();
        swap_occurred = false;
        fwcClearItems();

        for ( bar = 1; bar < number_of_bars; bar++ )
        {
            color = DARKBLUE;

            if ( bar_height[bar] < bar_height[bar-1] )
            {
                swapper = bar_height[bar];
                bar_height[bar] = bar_height[bar-1];
                bar_height[bar-1] = swapper;

                //color = RED;
                swap_occurred = true;
            }

            fwcLine(bar,400,bar,400-bar_height[bar-1],color,1);
        }
        fwcLine(0,400,400,0,RED,1);
        msleep(30);
    }
}
