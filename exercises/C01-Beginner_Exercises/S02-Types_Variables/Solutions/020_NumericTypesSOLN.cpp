// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void NumericTypesSoln::runExercise()
{
    fwcText("Make the seeout output", 30, 80, BLUE, 20);
    fwcText("in the boxes below match...", 30, 120, BLUE, 20);

    int x = 100;                // = is pronounced GETS, == is pronounced EQUALS
    double y = 200;             // remember to initialize every variable!
    unsigned short z = 65535;   // the type of int determines the max and min values it can store

    seeout << "int x == " << x << "\n";
    seeout << "double y == " << y << "\n";
    seeout << "unsigned short z == " << z << "\n";
    seeout << "\n";

    seeout << "sizeof() returns number of bytes used to store the value.\n";
    seeout << "There are 8 bits in a byte.\n\n";

    seeout << "sizeof x is " << sizeof(x) << " bytes, which is " << sizeof(x)*8 << " bits.\n";
    seeout << "sizeof y is " << sizeof(y) << " bytes, which is " << sizeof(y)*8 << " bits.\n";
    seeout << "sizeof z is " << sizeof(z) << " bytes, which is " << sizeof(z)*8 << " bits.\n\n";

    // You can change x and y as often as you like:
    x = 200;
    seeout << "x is now 200: " << x << "\n";
    x = 250;
    seeout << "x is now 250: " << x << "\n";
    y = 50;
    seeout << "y is now 50: " << y << "\n";
    y = 1000;
    seeout << "y is now 1000: " << y << "\n";
}


