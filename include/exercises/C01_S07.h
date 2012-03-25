// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S07_H
#define C01_S07_H

#include <exercises/FeetWetCodingExerciseBase.h>

//class WhileLoopIntroSoln : public FeetWetCodingSolution
//{
//    Q_OBJECT
//public:
//    explicit WhileLoopIntroSoln(QObject *parent = 0)
//        :FeetWetCodingSolution(parent){}


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
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};



#endif // C01_S07_H
