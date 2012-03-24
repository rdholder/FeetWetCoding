// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawingImages::runExercise()
{
    // USAGE: fwcDrawImage("filename.png", x, y);
    //        filename.png must be an image file in your FeetWetCoding
    //        project folder's "img" sub-directory.

    fwcDrawImage("ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    fwcDrawImage("BrianKernighan50x58.png", 130, 10);
    fwcDrawImage("BjarneStroustrup50x55.png", 200, 10);
    fwcDrawImage("DuckFeet100x45.bmp", 10, 200);
    fwcDrawImage("spaceship50x59.jpg", 200, 200);
    fwcDrawImage("clock100x100.gif", 280, 200);

    // NOTE: This demonstrates what happens when you pass a bad
    //       filename to fwcDrawImage. Notice the message that
    //       appears in your "Exercise output" panel when you run this.

    fwcDrawImage("badfilename.gif", 280, 200);
}
