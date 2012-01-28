#include <setup.h>

using namespace std;

FeetWetCodingExercise::FeetWetCodingExercise(QObject *parent) :
    QObject(parent)
{
}

void FeetWetCodingExercise::update()
{
    this->runExercise();
}
