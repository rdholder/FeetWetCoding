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
