// FeetWetCoding/include/exercises/C01_S05.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S05_H
#define C01_S05_H

#include <exercises/FeetWetCodingExercise.h>

class WhileLoop1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1Soln(QObject *parent = 0)
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

class WhileLoop1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1(QObject *parent = 0)
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
        mSolutionPtr = new WhileLoop1Soln(); // Executes soln's runExercise();
    }
};

class InfiniteLooping1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1Soln(QObject *parent = 0)
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

class InfiniteLooping1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1(QObject *parent = 0)
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
        mSolutionPtr = new InfiniteLooping1Soln(); // Executes soln's runExercise();
    }
};

class C01S05_OYO1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO1Soln(QObject *parent = 0)
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

class C01S05_OYO1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO1(QObject *parent = 0)
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
        mSolutionPtr = new C01S05_OYO1Soln(); // Executes soln's runExercise();
    }
};

class C01S05_OYO2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO2Soln(QObject *parent = 0)
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

class C01S05_OYO2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO2(QObject *parent = 0)
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
        mSolutionPtr = new C01S05_OYO2Soln(); // Executes soln's runExercise();
    }
};

class WhileLoop2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2Soln(QObject *parent = 0)
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

class WhileLoop2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2(QObject *parent = 0)
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
        mSolutionPtr = new WhileLoop2Soln(); // Executes soln's runExercise();
    }
};

class WhileLoop3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3Soln(QObject *parent = 0)
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

class WhileLoop3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3(QObject *parent = 0)
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
        mSolutionPtr = new WhileLoop3Soln(); // Executes soln's runExercise();
    }
};

class C01S05_OYO3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO3Soln(QObject *parent = 0)
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

class C01S05_OYO3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO3(QObject *parent = 0)
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
        mSolutionPtr = new C01S05_OYO3Soln(); // Executes soln's runExercise();
    }
};

class C01S05_OYO4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO4Soln(QObject *parent = 0)
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

class C01S05_OYO4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO4(QObject *parent = 0)
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
        mSolutionPtr = new C01S05_OYO4Soln(); // Executes soln's runExercise();
    }
};

class WhileLoop4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4Soln(QObject *parent = 0)
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

class WhileLoop4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4(QObject *parent = 0)
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
        mSolutionPtr = new WhileLoop4Soln(); // Executes soln's runExercise();
    }
};

class WhileLoop5Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5Soln(QObject *parent = 0)
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

class WhileLoop5 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5(QObject *parent = 0)
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
        mSolutionPtr = new WhileLoop5Soln(); // Executes soln's runExercise();
    }
};

class ForLoops1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops1Soln(QObject *parent = 0)
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

class ForLoops1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops1(QObject *parent = 0)
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
        mSolutionPtr = new ForLoops1Soln(); // Executes soln's runExercise();
    }
};

class ForLoops2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops2Soln(QObject *parent = 0)
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

class ForLoops2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops2(QObject *parent = 0)
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
        mSolutionPtr = new ForLoops2Soln(); // Executes soln's runExercise();
    }
};

class ForLoops3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops3Soln(QObject *parent = 0)
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

class ForLoops3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ForLoops3(QObject *parent = 0)
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
        mSolutionPtr = new ForLoops3Soln(); // Executes soln's runExercise();
    }
};

class DivideByZero : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DivideByZero(QObject *parent = 0)
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

class IfThen1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1Soln(QObject *parent = 0)
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

class IfThen1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1(QObject *parent = 0)
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
        mSolutionPtr = new IfThen1Soln(); // Executes soln's runExercise();
    }
};

class IfThen2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen2Soln(QObject *parent = 0)
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

class IfThen2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen2(QObject *parent = 0)
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
        mSolutionPtr = new IfThen2Soln(); // Executes soln's runExercise();
    }
};

class IfThen3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen3Soln(QObject *parent = 0)
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

class IfThen3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen3(QObject *parent = 0)
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
        mSolutionPtr = new IfThen3Soln(); // Executes soln's runExercise();
    }
};

class Primes1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Primes1Soln(QObject *parent = 0)
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

class Primes1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Primes1(QObject *parent = 0)
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
        mSolutionPtr = new Primes1Soln(); // Executes soln's runExercise();
    }
};

class C01S05_OYO5Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO5Soln(QObject *parent = 0)
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

class C01S05_OYO5 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit C01S05_OYO5(QObject *parent = 0)
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
        mSolutionPtr = new C01S05_OYO5Soln(); // Executes soln's runExercise();
    }
};

#endif // C01_S05_H
