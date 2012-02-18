// FeetWetCoding/source/feetwetcodingexercise.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <exercises/FeetWetCodingExercise.h>

using namespace std;

FeetWetCodingExercise::FeetWetCodingExercise(QObject *parent)
    :QObject(parent)
    ,mSolutionPtr(NULL)
{
}

FeetWetCodingExercise::~FeetWetCodingExercise()
{
    std::cerr << "FeetWetCodingExercise::~FeetWetCodingExercise()\n";
    ClearScreen();
    initOutputArea();
}

void FeetWetCodingExercise::runExercise()
{
}

void FeetWetCodingExercise::update()
{
    this->runExercise();
}
