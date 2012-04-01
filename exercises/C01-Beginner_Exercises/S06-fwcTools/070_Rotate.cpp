// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void RotateItem1::runExercise()
{
    int shipx(200), shipy(200), shipangle(0), degreeturnrate(10);
    bool turnclockwise(true);
    std::string key;

    seeout.setColor(DARKGREEN);
    seeout.setFontSize(12);
    seeout << "shipangle:\n";
    seeout.setColor(BLACK);
    seeout.setFontSize(10);

    int ship = fwcDrawImage("spaceship50x59.jpg", shipx, shipy);

    while ( true )
    {
        seeout << shipangle << "  ";
        shipangle += degreeturnrate;
        fwcRotateItem(ship, shipangle);
        msleep(50);
    }

    fwcClearItems();
    fwcDrawText("DONE!", 60, 150, DARKBLUE, 60);
}
