// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/390_DivideByZero.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void DivideByZero::runExercise()     // copy the exercise name & paste it into main.cpp
{

    // THIS PROGRAM WILL HANG WHEN YOU TRY TO RUN IT WITH THE if LINE COMMENTED OUT.
    // Go ahead and run it as-is to see the correct behavior and then comment the
    // if ( != 0 )
    // line out and run it again to see what happens when you try to divide by zero.

    // ****** You may have to kill FeetWetCoding.exe manually. ******

    int a = 256, b = 8;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    for ( b = 8; b > - 8; b-- )
    {
        if ( b != 0 ) // comment out this if statement to see divide-by-zero error at runtime
            seeout << a << " / " << b << " == " << a / b << "\n";
    }

    // This is why it's always good to test the denominator before any division calculation
    // if there is ANY CHANCE that the denominator could resolve to zero.  Good habit to
    // learn early in your programming efforts!

}
