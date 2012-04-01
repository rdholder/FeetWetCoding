// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>
#include <math.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DistanceEquationSoln::runExercise()     // copy the exercise name & paste it into main.cpp
{
    int x1 = random(200), y1 = random(400), x2 = random(300)+100, y2 = random(400);
    int distance = 0;

    fwcDrawLine(x1, y1, x2, y2, BLUE, 1);
    distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); // don't forget to #include <math.h>!
    fwcDrawText("Line length = ", x1, y1, BLACK, 10);
    fwcDrawInt(distance, x1 + 80, y1, BLACK, 10);

    seeout << "This program generates a new random line every time you hit the";
    seeout << " 'Re-start Exercise' button.  Just add the code to make your";
    seeout << " program display the line length information.\n\n";
    seeout << "Later, when you need to be able to know the distance between";
    seeout << " two points, you'll be able to cut and paste the distance code";
    seeout << " from this exercise.  Don't forget to #include <math.h>!\n";
}


