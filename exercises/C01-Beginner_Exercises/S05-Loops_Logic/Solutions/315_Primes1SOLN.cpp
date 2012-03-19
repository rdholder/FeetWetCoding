// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>
#include <math.h>

void Primes1Soln::runExercise()
{
    int n = 0, c = 0, x = 0, y = 0;
    int horizontalstep = 30, verticalstep = 40;
    bool prime = true;
    Color color = DARKBLUE;

    for ( n = 1; n < 101; n++ )
    {
        fwcDrawInt(n, x, y, color);

        for ( c = 2; c < n-1; c++ )
        {
            if ( n%c == 0 )
            {
                prime = false;
                break;
            }
        }

        if ( n == 1 )
        {
            prime = false;
        }
        if ( prime )
        {
            fwcDrawRectangle(x, y, horizontalstep-5, verticalstep-10, RED, 1);
        }
        prime = true;

        x += horizontalstep;
        if ( x > 400 - horizontalstep )
        {
            x = 0;
            y += verticalstep;
        }
    }
    fwcDrawText("Every number in a red box is a prime number.", 20, 370, RED, 12);
    seeout << "A prime number is divisible by 1, and itself, but\n";
    seeout << ">>>none of the numbers in between!<<<  (hint, hint! :-)\n";
}
