// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S09_H
#define C01_S09_H

#include <exercises/FeetWetCodingExerciseBase.h>

class Classes1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Classes1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Classes1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Classes1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Classes1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S09_H
