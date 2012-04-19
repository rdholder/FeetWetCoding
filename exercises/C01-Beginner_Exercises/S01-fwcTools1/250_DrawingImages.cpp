// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S01.h>

void DrawingImages::runExercise()
{
    // USAGE: fwcImage("filename.png", x, y);
    //        filename.png must be an image file in your FeetWetCoding
    //        project folder's "img" sub-directory.

    fwcImage("ken-thompson-l-and-dennis-ritchie-r100x65.png", 10, 10);
    fwcImage("BrianKernighan50x58.png", 130, 10);
    fwcImage("BjarneStroustrup50x55.png", 200, 10);
    fwcImage("DuckFeet100x45.bmp", 10, 200);
    fwcImage("spaceship50x59.jpg", 200, 200);
    fwcImage("clock100x100.gif", 280, 200);

    // NOTE: This demonstrates what happens when you pass a bad
    //       filename to fwcImage. Notice the message that
    //       appears in your "Exercise output" panel when you run this.

    fwcImage("badfilename.gif", 280, 200);
}
