// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C08_S03.h>

extern FWCView *view;

SpaceshipFlyerSoln::SpaceshipFlyerSoln(QObject *parent)
    :FeetWetCodingSolution(parent)
{
}

SpaceshipFlyerSoln::~SpaceshipFlyerSoln()
{
}

void SpaceshipFlyerSoln::runExercise()
{
    fwcDrawText("Demo Exercise:", 50, 150, BLUE, 20);
    fwcDrawText("no solution needed.", 50, 180, BLUE, 20);
}

