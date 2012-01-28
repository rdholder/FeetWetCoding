// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/GetsAndPlusGets.cpp

// Chapter 01 Exercise 02: Introduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/GetsAndPlusGets.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int GetsAndPlusGetsSoln::runExercise()
{
    Gsoln = true;

    int verticalstep=0;
    int a=0, x=2, y=50;

    verticalstep=y;
    a=x;
    DrawText("First sentence.", x, y, BLACK, 15);
    y = y + verticalstep;
    DrawText("Second sentence.", x, y, BLACK, 15);
    y += verticalstep;
    DrawText("Third sentence.", x, y, BLACK, 15);
    y += verticalstep;
    a += x;
    DrawText("Fourth sentence.", x, y, RED, 15);
    y += verticalstep;
    DrawText("Fifth sentence.", x, y, BLACK, 15);

    return 0;
}
