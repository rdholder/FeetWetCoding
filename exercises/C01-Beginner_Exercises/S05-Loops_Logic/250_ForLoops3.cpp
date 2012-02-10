// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void ForLoops3::runExercise()
{
    int a = 0, x = 0, y = 0;                // = is pronounced GETS, == is pronounced EQUALS

    // Now you learn the for loop.  You learned while first because it forces you
    // to think a little more about the condition that terminates your loops.  Using
    // while makes you think a little more about your logic, which is good practice.
    // But many loops you will use will have a straight-forward structure of
    // iterating a finite number of times.  When you know you need to run a loop for
    // values from 0 to 200, for example, a for loop works well.

    // NOTICE:  You should go back and review Chapter 01, Section 02, 550_FontProportions.cpp
    // before attempting to solve this exercise!

    for ( a = 0; a < 200; a++)
    {
        x = random(400);
        y = random(400);
        DrawInt( a, x, y, RED, 15);
    }
}
