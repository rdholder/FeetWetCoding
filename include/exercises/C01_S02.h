// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S02_H
#define C01_S02_H

#include <exercises/FeetWetCodingExerciseBase.h>

// CHAPTER01/SECTION02-Types_Variables


class NumericTypesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit NumericTypesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new NumericTypesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawingVersusSeeoutSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawingVersusSeeoutSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
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
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *){}
};

class Chars : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Chars(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class Booleans : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Booleans(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class StandardStringsSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit StandardStringsSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new StandardStringsSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S02_H
