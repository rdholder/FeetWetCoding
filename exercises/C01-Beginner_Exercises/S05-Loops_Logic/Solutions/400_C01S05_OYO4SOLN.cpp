// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void C01S05_OYO4Soln::runExercise()
{
    int x = 0, y = 200;
    float velocity = 2;
    float rateofchange = 0.1;
    int changedirectioncounter = 50;
    bool godown = true;

    seeout << "Run this a few times to get an idea of the behavior we are\n";
    seeout << "looking for here.  Brand new coders will have to work for\n";
    seeout << "this one.  :-)  One thing I've found that helps when I'm\n";
    seeout << "stuck on a coding problem is to think about it awhile, and\n";
    seeout << "then sleep on it.  Sometimes, I wake up with the answer (or at\n";
    seeout << "least a new idea) my head!  :-)\n\n";

    while ( x++ < 400 )
    {
        if (godown)
        {
            y += velocity;
        }
        else
        {
            y -= velocity;
        }

        velocity -= rateofchange;

        if ( changedirectioncounter-- < 0 )
        {
            changedirectioncounter = random(50);
            velocity = random (2);

            if ( godown )
            {
                godown = false;
            }
            else
            {
                godown = true;
            }

            seeout << "********* Direction changed! ***********\n";
        }

        DrawCircle(x, y, 1, RED, 1);
        seeout << "x,y: " << x << "," << y << " velocity: " << velocity << "\n";
    }
}
