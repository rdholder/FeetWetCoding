// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S05.h>
extern bool Gsoln;

int WhileLoop4Soln::runExercise()
{
    Gsoln = true;

    int x=0, y=400;
    int velocity= -45;
    int rateofchange=3;
    int horizontalstep = 12;
    char buffer [33];

    while ( x < 400 )
    {
        x += horizontalstep;
        y += velocity;
        velocity += rateofchange;
        DrawCircle(x, y, 20, RED, 1);
        DrawText(itoa(velocity, buffer, 10), x+10, y, BLUE, 10);
    }

    return 0;

}
