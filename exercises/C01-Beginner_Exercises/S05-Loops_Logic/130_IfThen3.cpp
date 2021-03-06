// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

using std::string;

void writeFalse()
{
    SeeOut seeout;
    seeout.setColor(DARKRED);
    seeout << "FALSE: ";
    seeout.setColor(BLACK);
}

void writeTrue()
{
    SeeOut seeout;
    seeout.setColor(BLUE);
    seeout << "TRUE: ";
    seeout.setColor(BLACK);
}

void IfThen3::runExercise()
{
    int x = 10, y = 20, z = 10;  // = is pronounced GETS, == is pronounced EQUALS
    float a = 0.0, b = 1.5, c = 98.6;
    string name1 = "John";
    string name2 = "Joan";
    string name3 = "john";
    string name4 = "John";

    // This exercise is for you to refer back to when you want to see a working example
    // of a specific conditional logic test.  There is nothing for you to solve here.
    // Understanding comparison logic is important in order to be able to code and debug.
    // Take a break if your brain gets tired from this stuff! (As mine does! :-)

    fwcText("Reference Exercise:", 50, 150, BLUE, 20);
    fwcText("no solution needed.", 50, 180, BLUE, 20);

    seeout.setFontSize(8);

    seeout << "Try to understand in every case below why each is true or false.\n\n";

    // basic comparison logic
    if ( x == y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 1: " << x << " == " << y << "\n";

    if ( x == z ) writeTrue();
    else writeFalse();
    seeout << "Conditional 2: " << x << " == " << z << "\n";

    if ( x != y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 3: " << x << " != " << y << "\n";

    if ( x != z ) writeTrue();
    else writeFalse();
    seeout << "Conditional 4: " << x << " != " << z << "\n";

    if ( x < y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 5: " << x << " < " << y << "\n";

    if ( x > y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 6: " << x << " > " << y << "\n";

    // you can compare ints and floats.  just be careful to remember that you can't store
    // fractional numbers in an int.
    if ( a < b ) writeTrue();
    else writeFalse();
    seeout << "Conditional 7: " << a << " < " << b << "\n";

    if ( a < x ) writeTrue();
    else writeFalse();
    seeout << "Conditional 8: " << a << " < " << x << "\n";

    // AND, OR, NOT and XOR
    if (true) writeTrue();
    else writeFalse();
    seeout << "Conditional 9: true\n";

    if (false) writeTrue();
    else writeFalse();
    seeout << "Conditional 10: false\n";

    if (!true) writeTrue();
    else writeFalse();
    seeout << "Conditional 11: NOT-true == false\n";

    if (!false) writeTrue();
    else writeFalse();
    seeout << "Conditional 12: NOT-false == true\n";

    if ( !x ) writeTrue();
    else writeFalse();
    seeout << "Conditional 13: !" << x << "\n";

    if ( !a ) writeTrue();
    else writeFalse();
    seeout << "Conditional 14: !" << a << "\n";

    if ( a < x && b < y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 15: " << a << " < " << x << " AND ";
    seeout << b << " < " << y << "\n";

    if ( a > x && b < y ) writeTrue();
    else writeFalse();
    seeout << "Conditional 16: " << a << " > " << x << " AND ";
    seeout << b << " < " << y << "\n";

    if ( a < x && b < y && c < z ) writeTrue();
    else writeFalse();
    seeout << "Conditional 17: " << a << " < " << x << " AND " << b << " < " << y;
    seeout << " AND " << c << " < " << z << "\n";

    if ( a < x || b < y || c < z ) writeTrue();
    else writeFalse();
    seeout << "Conditional 18: " << a << " < " << x << " OR " << b << " < " << y;
    seeout << " OR " << c << " < " << z << "\n";

    if ( (a < x && b < y) && ( x < y && y < c ) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 19: ( " << a << " < " << x << " AND ";
    seeout << b << " < " << y << " )";
    seeout << " AND ( " << x << " < " << y << " AND ";
    seeout << y << " < " << c << " )\n";

    if ( ( a < x && b < y) && ( x < y && y > c ) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 20: ( " << a << " < " << x << " AND ";
    seeout << b << " < " << y << " )";
    seeout << " AND";
    seeout << " ( " << x << " < " << y << " AND ";
    seeout << y << " > " << c << " )\n";

    if ( (a < x && b < y) || ( x < y && y > c ) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 21: ( " << a << " < " << x << " AND ";
    seeout << b << " < " << y << " )";
    seeout << " OR";
    seeout << "   ( " << x << " < " << y << " AND ";
    seeout << y << " > " << c << " )\n";

    if ( !(a > x) && !(b < y) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 22: NOT (" << a << " > " << x << ") AND NOT ( ";
    seeout << b << " < " << y << " ) )\n";

    if ( !(a > x && b < y) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 23: NOT ( (" << a << " > " << x << " AND ";
    seeout << b << " < " << y << " ) )\n";

    if ( ( a < x || b < y ) && !( a < x && b < y ) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 24: XOR (Exclusive OR):\n";
    seeout << "( " << a << " < " << x << " OR " << b << " < " << y << ")";
    seeout << "   AND ( NOT ( " << a << " < " << x << " AND " << b << " < " << y << ") )\n";

    if ( ( a > x || b < y ) && !( a > x && b < y ) ) writeTrue();
    else writeFalse();
    seeout << "Conditional 25: XOR (Exclusive OR):\n";
    seeout << "( " << a << " > " << x << " OR " << b << " < " << y << ")";
    seeout << "   AND ( NOT ( " << a << " > " << x << " AND " << b << " < " << y << ") )\n";

    // string comparison
    if ( name1 == name4 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 26: " << name1 << " is the same string as " << name4 << "\n";

    if ( name1 == name2 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 27: " << name1 << " is the same string as " << name2 << "\n";

    if ( name1 == name3 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 28: " << name1 << " is the same string as " << name3 << "\n";

    if ( name1 < name2 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 29: " << name1 << " is alphanumerically less than " << name2 << "\n";

    if ( name2 < name3 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 30: " << name2 << " is alphanumerically less than " << name3 << "\n";

    if ( name3 < name4 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 31: " << name3 << " is alphanumerically less than " << name4 << "\n";

    if (name1 < name3 ) writeTrue();
    else writeFalse();
    seeout << "Conditional 32: " << name1 << " is alphanumerically less than " << name3 << "\n";
}
