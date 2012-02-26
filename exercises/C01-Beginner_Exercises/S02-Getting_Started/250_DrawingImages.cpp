// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawingImages::runExercise()
{
    // WARNING!  Please do not try to add your own images yet!  I know it's fun,
    // but until you are more familiar with Qt Creator and C++, you will most
    // likely just hose your FeetWetCoding project, and then you may not be able to
    // get any exercises to run at all!  We will show you how to use your own
    // images down the road, but there is a lot to learn first.  :-)

    // USAGE: DrawImage("images:/filename.png", x, y);
    DrawImage(":images/ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    DrawImage(":images/BrianKernighan50x58.png", 130, 10);
    DrawImage(":images/BjarneStroustrup50x55.png", 200, 10);
    DrawImage(":images/DuckFeet100x45.bmp", 10, 200);
    DrawImage(":images/spaceship50x59.jpg", 200, 200);
    DrawImage(":images/clock100x100.gif", 280, 200);
}
