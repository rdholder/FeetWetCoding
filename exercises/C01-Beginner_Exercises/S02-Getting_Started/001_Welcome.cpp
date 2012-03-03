// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

// Open (double-click) the README.html file to access the documentation.

#include <exercises/C01_S02.h>

void Welcome::runExercise()
{
    // USAGE: DrawText("Text.", x, y, color, fontsize);
    //DrawText("Welcome to FeetWetCoding!", 20, 150, BLUE, 20);

    //Example 1: Pause while looping
    int x=10, y=50;
    int count(5);
    while (count)
    {
//        qDebug() << "Hi! Count is now: " << count;
        DrawText("Hi! Count is now: ", x, y, BLUE, 18);
        DrawInt(count, x+270, y, BLUE, 18);
        count--;
        y+=50;
        msleep(100);
    }
    qDebug() << "Done with loop!";

//    //Example 2: Wait on keyboard input
//    qDebug() << "\n Hit any key to continue...";
//    waitForKeyboardInput();
//    qDebug() << "Thanks! We're done now!";
}
