// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeLineEnd::runExercise()
{
    int x(0), y(0), step(5), sleepTimeInMiliseconds(30);

    fwcRectangle(0,0,400,400,BLACK,1,true);

    int line = fwcLine(200,200,0,0,GREEN,1);

    for(x=0; x < 400; x+=step)
    {
        fwcChangeLineEnd(line, x, y);
        msleep(sleepTimeInMiliseconds);
    }
}
