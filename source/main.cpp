// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

// FeetWetCoding: a framework that tries to make learning C++ a little more fun! :-)

// ACKNOWLEDGEMENT: The seed of the idea for the FeetWetCoding system of learning C++
// was suggested by a passage in an outstanding science fiction book,
// "The Mote in God's Eye" by Larry Niven & Jerry Pournelle, page 210
// (from "ELIZA Crossing the Ice"):
// "There are things wrong wi' some o' the tools and 'tis my task to put them right."

#include <lib/setup.h>

FeetWetCodingExercise *exercise(NULL);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Setup the exercises
    appSetup();

    //Start the application loop
    return a.exec();
}
