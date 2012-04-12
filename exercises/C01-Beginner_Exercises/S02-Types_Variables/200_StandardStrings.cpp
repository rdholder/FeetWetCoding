// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

using std::string;

void StandardStrings::runExercise()
{
    // NOTICE: to use standard strings we have to say "using std::string;" above!

    string towel = "Always know where your towel is!";
    string fordsays = "Don't Panic!";
    string swap = "sometext";

    fwcText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    swap = fordsays;
    fordsays = towel;
    towel.clear();
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    towel = "Don't forget to bring a towel!";
    fordsays = swap;
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
}


