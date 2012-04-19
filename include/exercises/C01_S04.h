// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef C01_S04_H
#define C01_S04_H

#include <exercises/FeetWetCodingExerciseBase.h>

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// CH01/S04/Expressions_Syntax
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class AssignmentArithmetic : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit AssignmentArithmetic(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class OrderOfOperations : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OrderOfOperations(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class PreAndPostIncAndDecSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit PreAndPostIncAndDecSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class PreAndPostIncAndDec : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit PreAndPostIncAndDec(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new PreAndPostIncAndDecSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ModulusOperator : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ModulusOperator(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class BlocksAndScope : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit BlocksAndScope(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class MathFunctions : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MathFunctions(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class randomAndrandomRange : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit randomAndrandomRange(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class DistanceEquationSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DistanceEquationSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DistanceEquation : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DistanceEquation(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DistanceEquationSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class MisdirectionSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit MisdirectionSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Misdirection : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Misdirection(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new MisdirectionSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S04_H
