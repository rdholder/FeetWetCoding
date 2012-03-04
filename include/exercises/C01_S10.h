// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S10_H
#define C01_S10_H

#include <exercises/FeetWetCodingExercise.h>

class Classes1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Classes1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        mSoln = true;
        //this->runExercise();
    }


signals:

public slots:

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
        mSoln = false;
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
        mSolutionPtr = new Classes1Soln(); // Executes soln's runExercise();
    }
};

#endif // C01_S10_H
