// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ChangeLineEnd1Soln::runExercise()
{

    int x(0), y(0), step(10);

    fwcDrawRectangle(0,0,400,400,BLACK,1,true);

    int line = fwcDrawLine(200,200,0,0,GREEN,1);

    while(true)
    {
        for(x=0; x < 400; ++x)
        {
            fwcChangeLineEnd(line, x, y);
            msleep(50);
            seeout << x << " ";
        }
        for(y=0; y < 400; ++y)
        {
            fwcChangeLineEnd(line, x, y);
            msleep(50);
        }
        for(x=400; x > 0; --x)
        {
            fwcChangeLineEnd(line, x, y);
            msleep(50);
        }
        for(y=400; y > 0; --y)
        {
            fwcChangeLineEnd(line, x, y);
            msleep(50);
        }
    }
}
