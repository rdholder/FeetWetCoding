// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S04.h>

void Misdirection::runExercise()
{
    int verticalstep=0;             // = is pronounced GETS and don't you forget!
    int a=0, x=2, y=50;             // == is pronounced EQUALS, it's twice, like a sequel

    verticalstep=y;
    a=x;
    fwcText("First sentence.", x, y, BLACK, 15);
    y = y + verticalstep;
    fwcText("Second sentence.", x, y, BLACK, 15);
    y += verticalstep;
    fwcText("Third sentence.", x, y, BLACK, 15);
    y += verticalstep;
    a += x;
    fwcText("Fourth sentence.", y, x, RED, 15);
    y += verticalstep;
    fwcText("Fifth sentence.", x, y, BLACK, 15);
}
