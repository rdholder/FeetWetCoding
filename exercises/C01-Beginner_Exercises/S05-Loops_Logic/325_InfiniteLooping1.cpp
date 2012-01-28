// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int InfiniteLooping1::runExercise()
{
    Gsoln = false;                  // is this exercise code or solution code?

    int x=20, y=20;                 // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=30;

    // NOTE: THIS CODE WILL CAUSE FeetWetCoding.EXE TO HANG WHEN YOU TRY TO RUN IT AND YOU
    // WILL HAVE TO KILL IT MANUALLY.  RUN IT ONCE AS IS TO SEE WHAT IT LOOKS LIKE
    // WHEN YOU HAVE AN INFINITE LOOP UNDER THE Qt LIBRARY, SO THAT YOU WILL RECOGNIZE
    // THIS IN FUTURE PROGRAMS AND WILL KNOW WHAT TO FIX.

    while ( y < 600 )
    {
        DrawText("This loop will never end until the next line is uncommented.", x, y, BLUE, 10);
        //y += verticalstep;

    }

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    InfiniteLooping1Soln *solution = new InfiniteLooping1Soln();
    solution->runExercise();

    return 0;
}
