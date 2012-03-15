// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S06_H
#define C01_S06_H

#include <exercises/FeetWetCodingExercise.h>

class Sleep1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Sleep1Soln(QObject *parent = 0)
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

class Sleep1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Sleep1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Sleep1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
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
        mSolutionPtr = new Sleep1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class SingleKeyInput1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SingleKeyInput1Soln(QObject *parent = 0)
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

class SingleKeyInput1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SingleKeyInput1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~SingleKeyInput1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
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
        mSolutionPtr = new SingleKeyInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class StringInput1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StringInput1Soln(QObject *parent = 0)
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

class StringInput1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StringInput1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~StringInput1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
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
        mSolutionPtr = new StringInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ShiftDrawnItem1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ShiftDrawnItem1Soln(QObject *parent = 0)
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

class ShiftDrawnItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ShiftDrawnItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~ShiftDrawnItem1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
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
        mSolutionPtr = new ShiftDrawnItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S06_H
