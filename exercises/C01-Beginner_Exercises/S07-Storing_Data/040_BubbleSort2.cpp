// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S07.h>

void BubbleSort2::runExercise()
{

    Color color = DARKBLUE;
    int bar(0), swapper(0);
    int number_of_bars(400);
    int bar_height[number_of_bars];
    bool swap_occurred(true);  // init to true so while loop runs at least once

    std::string key;

//    seeout << "We fill the bar_height array with a bunch of random numbers.";
//    seeout << " Here is what bar_height contains now:\n";

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
        msleep(30);
    }
}
