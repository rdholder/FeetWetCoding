// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void C01S05_OYO5Soln::runExercise()
{
    int x = 0, y = 200;
    float velocity = 2;
    float rateofchange = 0.1;
    int changedirectioncounter = 50;
    bool godown = true;

    seeout << "Click the \"Re-start Exercise\" button a few times to get an idea";
    seeout << " of the behavior we are looking for here.\n\n";
    seeout << "Brand new coders will have to work for this one.  :-)  One thing";
    seeout << " I've found that helps when I'm stuck on a coding problem is to";
    seeout << " think about it awhile, and then sleep on it.  Sometimes, I wake";
    seeout << " up with the answer (or at least a new idea) in my head!  :-)\n\n";

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

            //seeout << "********* Direction changed! ***********\n";
        }

        fwcCircle(x, y, 1, RED, 1, true);
        //seeout << "x,y: " << x << "," << y << " velocity: " << velocity << "\n";
    }
}
