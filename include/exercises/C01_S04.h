// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S04_H
#define C01_S04_H

#include <exercises/FeetWetCodingExercise.h>

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
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class OrderOfOperations : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OrderOfOperations(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class PreAndPostIncAndDecSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit PreAndPostIncAndDecSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = true;
        //this->runExercise();
    }

signals:

public slots:

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
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new PreAndPostIncAndDecSoln(); // Executes soln's runExercise();
    }
};

class ModulusOperator : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ModulusOperator(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class BlocksAndScope : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit BlocksAndScope(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class MathFunctions : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MathFunctions(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class randomAndrandomRange : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit randomAndrandomRange(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class DistanceEquationSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DistanceEquationSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = true;
        //this->runExercise();
    }

signals:

public slots:

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
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new DistanceEquationSoln(); // Executes soln's runExercise();
    }
};

class MisdirectionSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MisdirectionSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = true;
        //this->runExercise();
    }

signals:

public slots:

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
        Gsoln = false;
        //this->runExercise();
        this->setupSolution();
    }

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new MisdirectionSoln(); // Executes soln's runExercise();
    }
};

#endif // C01_S04_H
