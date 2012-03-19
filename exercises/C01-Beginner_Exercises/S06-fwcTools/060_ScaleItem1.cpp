// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ScaleItem1::runExercise()
{
    int count1(100), count2(100), leftgrow(1);
    float scalefactor(1.1);
    bool c1grow(true), c2grow(false);

    int circle1 = fwcDrawCircle(100, 200, 10, DARKBLUE, 1, true);
    int circle2 = fwcDrawCircle(300, 200, 180, DARKCYAN, 1, true);

    for (count1 = 0; count1 < 100; count1++)
    {
        while( 0 < 180 )
        {
            //scalefactor += 0.1;
            fwcScaleItem(circle1, scalefactor * leftgrow);
            fwcScaleItem(circle2, scalefactor);
            msleep(200);
        }
        if (leftgrow ==1 )
        {
            leftgrow = -1;
        }
        else
        {
            leftgrow = 1;
        }
    }

}
