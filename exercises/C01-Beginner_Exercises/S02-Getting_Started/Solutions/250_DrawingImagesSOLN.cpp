// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawingImagesSoln::runExercise()
{
    // USAGE: fwcImage("filename.png", x, y);
    //        filename.png must be an image file in your FeetWetCoding
    //        project folder's "img" sub-directory.

    fwcImage("ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    fwcImage("BrianKernighan50x58.png", 130, 10);
    fwcImage("BjarneStroustrup50x55.png", 200, 10);
    fwcImage("Qtlogo59x71.png", 300, 10);
    fwcImage("DuckFeet100x45.bmp", 150, 340);
    fwcImage("clock100x100.gif", 150, 150);
    fwcImage("spaceship50x59.jpg", 175, 80);
    fwcImage("spaceship50x59.jpg", 70, 160);
    fwcImage("spaceship50x59.jpg", 280, 160);
    fwcImage("spaceship50x59.jpg", 175, 260);
}
