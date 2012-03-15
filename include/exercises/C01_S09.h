// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S09_H
#define C01_S09_H

#include <exercises/FeetWetCodingExercise.h>

class Classes1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Classes1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Classes1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new Classes1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S09_H
