// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void InfiniteLooping1::runExercise()
{
    int x=20, y=20;                 // = is pronounced GETS, == is pronounced EQUALS

    // NOTE: THIS CODE WILL CAUSE FeetWetCoding.EXE TO HANG WHEN YOU TRY TO RUN IT AND YOU
    // WILL HAVE TO KILL IT MANUALLY.  RUN IT ONCE AS IS TO SEE WHAT IT LOOKS LIKE
    // WHEN YOU HAVE AN INFINITE LOOP UNDER THE Qt LIBRARY, SO THAT YOU WILL RECOGNIZE
    // THIS IN FUTURE PROGRAMS AND WILL KNOW WHAT TO FIX.  AFTER YOU KILL FeetWetCoding.exe
    // UNCOMMENT THE VERTICALSTEP LINE AND RUN IT AGAIN.

    // This type of logic error very well may come up again as you learn programming, so
    // it's good for you to know how to recognize it as a possible cause of a hung executable!

    while ( y < 400 )
    {
        DrawText("This loop will never end until the next line is uncommented.", x, y, BLUE, 10);
        //y += 30;

    }
}
