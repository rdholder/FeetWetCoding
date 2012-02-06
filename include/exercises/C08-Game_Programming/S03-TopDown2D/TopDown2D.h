#ifndef TOPDOWN2D_H
#define TOPDOWN2D_H

#include <exercises/FeetWetCodingExercise.h>

class TopDown2DSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TopDown2DSoln(QObject *parent = 0)
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

class TopDown2D : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TopDown2D(QObject *parent = 0)
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
        mSolutionPtr = new TopDown2DSoln(); // Executes soln's runExercise();
    }
};

#endif // TOPDOWN2D_H
