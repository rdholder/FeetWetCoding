// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

void Erase::runExercise()
{
    int circle = fwcCircle(200,300,50,DARKBLUE,1,true);
    sleep(1);
    fwcShiftItem(circle,0,-100);
    sleep(1);
    fwcEraseItem(circle);           // should we write an error to stderr here?
                                    // do we need an fwcItemExists() function?
    fwcShiftItem(circle,0,-100);
}
