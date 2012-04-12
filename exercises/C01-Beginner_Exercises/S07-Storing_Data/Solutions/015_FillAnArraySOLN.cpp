// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S07.h>
#include <math.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void FillAnArraySoln::runExercise()
{

    Color color = DARKBLUE;
    int bar(0);
    int number_of_bars(400);
    int bar_height[number_of_bars];

    std::string key;

    for (bar = 0; bar < number_of_bars; bar++ )  // always initialize your array!
    {
        bar_height[bar] = random(400);
    }

    seeout << "We just filled the bar_height array with a bunch of random numbers.";
    seeout << " Here is what bar_height contains now:\n";

    for (bar = 0; bar < number_of_bars; bar++ )  // always initialize your array!
    {
        seeout << "bar_height[" << bar << "] == " << bar_height[bar] << "\n";
        fwcLine(bar,400,bar,400-bar_height[bar],DARKBLUE,1);
    }
}
