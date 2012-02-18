// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/320_Primes1SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>
#include <math.h>

void Primes2Soln::runExercise()
{
    int n = 2, c = 2, x = 0, y = 0;
    bool prime = true;

    DrawRectangle(0, 0, 400, 400, BLACK, 1, true);

    for ( y = 0; y < 400; y++ )
    {
        for ( x = 0; x < 400; x++ )
        {
            prime = true;
            for ( c = 2; c < n-1; c++ )
            {
                if ( n%c == 0 )
                {
                    prime = false;
                    break;
                }
            }

            if ( prime )
            {
                DrawLine(x, y, x, y+1, GREEN, 1);
            }
            n++;
        }
    }

    //DrawText("Every dot represents a prime number.", 20, 370, GREEN, 12);
    seeout << "This depicts the primes between 1 and " << n-1 << ".";
    seeout << " Instead of drawing the numbers and putting a red box around";
    seeout << " each prime, we're just drawing a dot when that number is prime.";
    seeout << " If you figured out the last exercise, you can figure this one out!\n\n";
    seeout << "Who knew there were so many prime numbers floating around out there?!";
    seeout << " When I created this exercises, I thought there would be a lot more black";
    seeout << " on the screen than that!\n\nTry to think of where there are those vertical";
    seeout << " black lines?  Why are there diagonal black lines?\n\n";
    seeout << "The reason it takes so long to run is because this is an";
    seeout << " Order N-Squared algorithm.  However big n gets, it requires";
    seeout << " n * n number of calculations, approximately.  Our break";
    seeout << " statement here reduces that, but we are still in the ballpark";
    seeout << " of order n^2.  You will learn more about how to figure out";
    seeout << " what \"Order\" of work your algorithms are in the Discrete Math";
    seeout << " exercises.\n\n";

}
