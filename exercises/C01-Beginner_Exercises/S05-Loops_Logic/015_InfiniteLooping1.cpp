// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void InfiniteLooping1::runExercise()
{
    int x=20, y=20;                 // = is pronounced GETS, == is pronounced EQUALS

    // NOTE: THIS CODE WILL CAUSE FeetWetCoding.exe TO HANG WHEN YOU TRY TO RUN IT WITH
    // y += 30; LINE COMMENTED OUT.  YOU WILL HAVE TO KILL IT MANUALLY.

    // Run it once with the y += 30; line commented out so that you can see what it looks
    // like when you have an infinite loop under the Qt Library.  That way, if you write
    // code during these exercises that creates an infinite loop, you will have seen this
    // hanging behavior already, and will have an idea of what you will need to fix.

    // This type of logic error is likely to come up again as you learn programming, so
    // it's good for you to know how to recognize it as a possible cause of a hung executable!

    while ( y < 400 )
    {
        fwcText("This loop will never end when the next line is commented out.", x, y, BLUE, 10);
        y += 30;

    }
}
