// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S07_H
#define C01_S07_H

#include <exercises/FeetWetCodingExerciseBase.h>

class WhyUseArraysSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhyUseArraysSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class WhyUseArrays : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhyUseArrays(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhyUseArraysSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Arrays1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Arrays1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class Arrays1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Arrays1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Arrays1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class FillAnArraySoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit FillAnArraySoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class FillAnArray : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit FillAnArray(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new FillAnArraySoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class BubbleSort1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit BubbleSort1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class BubbleSort1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit BubbleSort1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new BubbleSort1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class MadLibSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit MadLibSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class MadLib : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MadLib(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new MadLibSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class BubbleSort2Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit BubbleSort2Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}


protected:
    void runExercise();
};

class BubbleSort2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit BubbleSort2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new BubbleSort2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S07_H
