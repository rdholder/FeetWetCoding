// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S05_H
#define C01_S05_H

#include <exercises/FeetWetCodingExerciseBase.h>

class WhileLoopIntroSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoopIntroSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoopIntro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoopIntro(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoopIntroSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoopIntroSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ForLoopIntroSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ForLoopIntro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoopIntro(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ForLoopIntroSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoop1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoop1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoop1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class InfiniteLooping1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit InfiniteLooping1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class InfiniteLooping1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new InfiniteLooping1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit C01S05_OYO1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class C01S05_OYO1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new C01S05_OYO1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO2Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit C01S05_OYO2Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class C01S05_OYO2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new C01S05_OYO2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop2Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoop2Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoop2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoop2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop3Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoop3Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoop3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoop3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO3Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit C01S05_OYO3Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class C01S05_OYO3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO3(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new C01S05_OYO3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO4Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit C01S05_OYO4Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class C01S05_OYO4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO4(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new C01S05_OYO4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop4Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoop4Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoop4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoop4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop5Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WhileLoop5Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class WhileLoop5 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WhileLoop5Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops2Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ForLoops2Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ForLoops2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ForLoops2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops3Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ForLoops3Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ForLoops3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops3(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ForLoops3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops4Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ForLoops4Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ForLoops4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops4(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ForLoops4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DivideByZero : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DivideByZero(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        //this->setupSolution(parent);
    }

protected:
    void runExercise();
    void setupSolution(QObject *){}
};

class IfThen1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit IfThen1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class IfThen1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new IfThen1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen2Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit IfThen2Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class IfThen2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new IfThen2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen3Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit IfThen3Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class IfThen3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen3(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new IfThen3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen4_OYOSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit IfThen4_OYOSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class IfThen4_OYO : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen4_OYO(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new IfThen4_OYOSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Switch1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Switch1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Switch1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Switch1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Switch1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Primes1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Primes1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Primes1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Primes1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Primes1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Primes2_OYOSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Primes2_OYOSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Primes2_OYO : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Primes2_OYO(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Primes2_OYOSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO5Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit C01S05_OYO5Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class C01S05_OYO5 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO5(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new C01S05_OYO5Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S05_H
