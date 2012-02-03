// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding: a framework that tries to make learning C/C++ a little more fun! :-)

// ACKNOWLEDGEMENT: The seed of the idea for the FeetWetCoding system of learning C/C++
// was suggested by a passage in an outstanding science fiction book,
// "The Mote in God's Eye" by Larry Niven & Jerry Pournelle, page 210
// (from "ELIZA Crossing the Ice"):
// "There are things wrong wi' some o' the tools and 'tis my task to put them right."

#include <setup.h>

FeetWetCodingExercise *exercise(NULL);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupDrawingUtils();

    /////////////////////////////////////////
    //////  CHOOSE YOUR EXERCISE HERE  //////
    exercise = new Welcome();
    /////////////////////////////////////////
    exercise->runExercise();

    //Start the application loop
    return a.exec();
}


