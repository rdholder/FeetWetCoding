// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ChangeLineEndSoln::runExercise()
{
    int x(0), y(0), step(5), sleepTimeInMiliseconds(30);

    fwcRectangle(0,0,400,400,BLACK,1,true);

    int line = fwcLine(200,200,0,0,GREEN,1);

    for(x=0; x < 400; x+=step)
    {
        fwcChangeLineEnd(line, x, y);
        msleep(sleepTimeInMiliseconds);
    }
    for(y=0; y < 400; y+=step)
    {
        fwcChangeLineEnd(line, x, y);
        msleep(sleepTimeInMiliseconds);
    }
    for(x=400; x > 0; x-=step)
    {
        fwcChangeLineEnd(line, x, y);
        msleep(sleepTimeInMiliseconds);
    }
    for(y=400; y > 0; y-=step)
    {
        fwcChangeLineEnd(line, x, y);
        msleep(sleepTimeInMiliseconds);
    }
}
