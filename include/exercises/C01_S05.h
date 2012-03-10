// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S05_H
#define C01_S05_H

#include <exercises/FeetWetCodingExercise.h>

class WhileLoopIntroSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoopIntroSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
    ~WhileLoopIntro()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoopIntroSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoopIntroSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoopIntroSoln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
    ~ForLoopIntro()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new ForLoopIntroSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
    ~WhileLoop1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoop1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class InfiniteLooping1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
    ~InfiniteLooping1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new InfiniteLooping1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~C01S05_OYO1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new C01S05_OYO1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO2Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~C01S05_OYO2()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new C01S05_OYO2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~WhileLoop2()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoop2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~WhileLoop3()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoop3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO3Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~C01S05_OYO3()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new C01S05_OYO3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO4Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~C01S05_OYO4()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new C01S05_OYO4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~WhileLoop4()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoop4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class WhileLoop5Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~WhileLoop5()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new WhileLoop5Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class ForLoops1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~ForLoops1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new ForLoops1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops2Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~ForLoops2()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new ForLoops2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ForLoops3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops3Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~ForLoops3()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new ForLoops3Soln(parent);
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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~DivideByZero()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
    }
};

class IfThen1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~IfThen1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new IfThen1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen2Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~IfThen2()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new IfThen2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen3Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~IfThen3()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new IfThen3Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class IfThen4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen4Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class IfThen4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen4(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~IfThen4()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new IfThen4Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Switch1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Switch1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Switch1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new Switch1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Primes1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Primes1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Primes1()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new Primes1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class OYO_Primes2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OYO_Primes2Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class OYO_Primes2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OYO_Primes2(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~OYO_Primes2()
    {
        qDebug() << "++++++++++++++++++++++ ~OYO_Primes2() +++++++++++++++++++++";
        if ( mSolutionPtr )
        {
            qDebug() << "~OYO_Primes2() - calling mSolutionPtr->terminate()/wait()";
            mSolutionPtr->terminate();
//            mSolutionPtr->wait();
            qDebug() << "~OYO_Primes2() - back from mSolutionPtr->wait()";
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new OYO_Primes2Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class Sleep1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Sleep1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class Sleep1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Sleep1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~Sleep1()
    {
        qDebug() << "++++++++++++++++++++++ ~Sleep1() +++++++++++++++++++++";
        if ( mSolutionPtr )
        {
            qDebug() << "~Sleep1() - calling mSolutionPtr->terminate()/wait()";
            mSolutionPtr->terminate();
//            mSolutionPtr->wait();
            qDebug() << "~Sleep1() - back from mSolutionPtr->wait()";
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new Sleep1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class SingleKeyInput1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SingleKeyInput1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class SingleKeyInput1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SingleKeyInput1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~SingleKeyInput1()
    {
        qDebug() << "++++++++++++++++++++++ ~SingleKeyInput1() +++++++++++++++++++++";
        if ( mSolutionPtr )
        {
            qDebug() << "~SingleKeyInput1() - calling mSolutionPtr->terminate()/wait()";
            mSolutionPtr->terminate();
//            mSolutionPtr->wait();
            qDebug() << "~SingleKeyInput1() - back from mSolutionPtr->wait()";
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new SingleKeyInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class StringInput1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StringInput1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class StringInput1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StringInput1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~StringInput1()
    {
        qDebug() << "++++++++++++++++++++++ ~StringInput1() +++++++++++++++++++++";
        if ( mSolutionPtr )
        {
            qDebug() << "~StringInput1() - calling mSolutionPtr->terminate()/wait()";
            mSolutionPtr->terminate();
//            mSolutionPtr->wait();
            qDebug() << "~StringInput1() - back from mSolutionPtr->wait()";
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new StringInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ShiftDrawnItem1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ShiftDrawnItem1Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

protected:
    void runExercise();
};

class ShiftDrawnItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ShiftDrawnItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~ShiftDrawnItem1()
    {
        qDebug() << "++++++++++++++++++++++ ~ShiftDrawnItem1() +++++++++++++++++++++";
        if ( mSolutionPtr )
        {
            qDebug() << "~ShiftDrawnItem1() - calling mSolutionPtr->terminate()/wait()";
            mSolutionPtr->terminate();
//            mSolutionPtr->wait();
            qDebug() << "~ShiftDrawnItem1() - back from mSolutionPtr->wait()";
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new ShiftDrawnItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class C01S05_OYO5Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO5Soln(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //Update seeout with soln config
        mSoln = true;
        mPane = 1; //Solution is always in pane 1 for now
        seeout.setIsSolution(mSoln);
        seeout.setColor(BLACK);
        seeout.setFontSize(10);
    }

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
        //Exercises can use parent's seeout config

        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }
    ~C01S05_OYO5()
    {
        if ( mSolutionPtr )
        {
            mSolutionPtr->terminate();
            mSolutionPtr->wait();
            delete mSolutionPtr;
            mSolutionPtr = NULL;
        }
    }

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution(QObject *parent=0)
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new C01S05_OYO5Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S05_H
