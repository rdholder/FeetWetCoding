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
        this->runExercise();
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

class PreAndPostIncAndDec : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit PreAndPostIncAndDec(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = false;
        this->runExercise();
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

class MisdirectionSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MisdirectionSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        Gsoln = true;
        this->runExercise();
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
        this->runExercise();
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
