// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <fwclib/FWCSettings.h>
#include <stdexcept>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <exercises/C01_S07.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void Arrays2Soln::runExercise()
{

    Color color = DARKBLUE;
    int bar(0);
    int number_of_bars(400);
    int bar_height[number_of_bars];

    std::string key;

    FWCSettings settings;
    QString dataDir;
    try
    {
        dataDir = settings.getProjectSandboxPath() + "/data";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    for (bar = 0; bar < number_of_bars; bar++ )  // always initialize your array!
    {
        bar_height[bar] = random(400);
    }

    seeout << "We just filled the bar_height array with a bunch of random numbers.";

    for (bar = 0; bar < number_of_bars; bar++ )  // always initialize your array!
    {
        fwcLine(bar,400,bar,400-bar_height[bar],DARKBLUE,1);
    }
}
