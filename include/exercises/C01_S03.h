// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S03_H
#define C01_S03_H

#include <exercises/FeetWetCodingExercise.h>

// CHAPTER01/SECTION03-Types_Variables


class NumericTypesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit NumericTypesSoln(QObject *parent = 0)
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

class NumericTypes : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit NumericTypes(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~NumericTypes()
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
        mSolutionPtr = new NumericTypesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawingVersusSeeoutSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingVersusSeeoutSoln(QObject *parent = 0)
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

class DrawingVersusSeeout : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingVersusSeeout(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~DrawingVersusSeeout()
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
        mSolutionPtr = new DrawingVersusSeeoutSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class CONSTANTS : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit CONSTANTS(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~CONSTANTS()
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
    }
};

class Chars : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Chars(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Chars()
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
    }
};

class Booleans : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Booleans(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Booleans()
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
    }
};

class StandardStringsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StandardStringsSoln(QObject *parent = 0)
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

class StandardStrings : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StandardStrings(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~StandardStrings()
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
        mSolutionPtr = new StandardStringsSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S03_H
