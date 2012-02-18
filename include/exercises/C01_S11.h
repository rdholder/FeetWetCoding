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
        Gsoln = true;
        this->runExercise();
    }


signals:

public slots:

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
        mSolutionPtr = new TheEventLoopSoln(); // Executes soln's runExercise();
    }
};

#endif // C01_S11_H
