// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>
#include <math.h>

void DistanceEquation::runExercise()
{
    int x1 = random(200), y1 = random(400), x2 = random(300)+100, y2 = random(400);
    int distance = 0;

    fwcLine(x1, y1, x2, y2, BLUE, 1);
    // good ol' pythagoras:
    distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); // don't forget to #include <math.h>!
}


