// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S06_H
#define C01_S06_H

#include <exercises/FeetWetCodingExercise.h>

//class WhileLoopIntroSoln : public FeetWetCodingExercise
//{
//    Q_OBJECT
//public:
//    explicit WhileLoopIntroSoln(QObject *parent = 0)
//        :FeetWetCodingExercise(parent)
//    {
//        Gsoln = true;
//        this->runExercise();
//    }


//signals:

//public slots:

//protected:
//    void runExercise();
//};

class Arrays1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Arrays1(QObject *parent = 0)
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
        //mSolutionPtr = new Arrays1Soln(); // Executes soln's runExercise();
    }
};



#endif // C01_S06_H
