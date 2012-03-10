// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

void NumericTypes::runExercise()
{
    // Exercises in Sections 3 and 4 are mostly for reference, so that in later
    // sections you can quickly refer back here to see the trivial examples
    // of how things are declared and what the basic syntax looks like.

    // Here is a good online tutorial on the subject of types and variables:
    // ----------------------------------------------------------------------
    // http://www.cplusplus.com/doc/tutorial/variables/
    //(See the "Fundamental data types" section part-way down.)

    // Here are some questions about this subject from real people learing to program:
    // --------------------------------------------------------------------------------
    // http://stackoverflow.com/questions/2386772/difference-between-float-and-double
    // http://stackoverflow.com/questions/3687904/whats-the-least-negative-integer-value-that-can-be-exactly-represented-by-dou

    // If you like math:
    // http://docs.oracle.com/cd/E19422-01/819-3693/ncg_goldberg.html

    DrawText("Make the seeout output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);
    DrawText("Be sure to scroll down to see all the output!", 30, 160, BLUE, 12);
    DrawText("Hint: You can also make the window taller.", 30, 180, BLUE, 12);

    int x = 100;                // = is pronounced GETS, == is pronounced EQUALS
    long y;                     // remember to initialize every variable!
    unsigned short z = 65537;   // the type of int determines the max and min values it can store

    seeout << "int x == " << x << "\n";
    seeout << "long y == " << y << "\n";
    seeout << "unsigned short z == " << z << " ?    <--- Whoa! What's going on here?\n";
    seeout << "\n";

    seeout << "sizeof() returns number of bytes used to store the value.\n";
    seeout << "There are 8 bits in a byte.\n\n";

    seeout << "sizeof x is " << sizeof(x) << " bytes, which is " << sizeof(x)*8 << " bits.\n";
    seeout << "sizeof y is " << sizeof(y) << " bytes, which is " << sizeof(y)*8 << " bits.\n";
    seeout << "sizeof z is " << sizeof(z) << " bytes, which is " << sizeof(z)*8 << " bits.\n\n";

    // You can change x and y as often as you like:
    x = 0;
    seeout << "x is now 200: " << x << "\n";
    x = 0;
    seeout << "x is now 250: " << x << "\n";
    y = 0;
    seeout << "y is now 50: " << y << "\n";
    y = 0;
    seeout << "y is now 1000: " << y << "\n";
}


