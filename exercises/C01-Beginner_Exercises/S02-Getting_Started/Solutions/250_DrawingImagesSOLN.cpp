// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawingImagesSoln::runExercise()
{
    // USAGE: fwcDrawImage("images:/filename.png", x, y);

    fwcDrawImage(":images/ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    fwcDrawImage(":images/BrianKernighan50x58.png", 130, 10);
    fwcDrawImage(":images/BjarneStroustrup50x55.png", 200, 10);
    fwcDrawImage(":images/Qtlogo59x71.png", 300, 10);
    fwcDrawImage(":images/DuckFeet100x45.bmp", 150, 340);
    fwcDrawImage(":images/clock100x100.gif", 150, 150);
    fwcDrawImage(":images/spaceship50x59.jpg", 175, 80);
    fwcDrawImage(":images/spaceship50x59.jpg", 70, 160);
    fwcDrawImage(":images/spaceship50x59.jpg", 280, 160);
    fwcDrawImage(":images/spaceship50x59.jpg", 175, 260);
}
