// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S11_H
#define C01_S11_H

#include <exercises/FeetWetCodingExercise.h>

class TheEventLoopSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TheEventLoopSoln(QObject *parent = 0)
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

class TheEventLoop : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TheEventLoop(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~TheEventLoop()
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
        mSolutionPtr = new TheEventLoopSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S11_H
