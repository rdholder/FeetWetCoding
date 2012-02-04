#ifndef C01_S03_H
#define C01_S03_H

#include <exercises/FeetWetCodingExercise.h>

// CHAPTER01/SECTION03-Types_Variables


class IntegersSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntegersSoln(QObject *parent = 0)
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

class Integers : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Integers(QObject *parent = 0)
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
        mSolutionPtr = new IntegersSoln(); // Executes soln's runExercise();
    }
};

class DrawingVersusSeeoutSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingVersusSeeoutSoln(QObject *parent = 0)
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

class DrawingVersusSeeout : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingVersusSeeout(QObject *parent = 0)
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
        mSolutionPtr = new DrawingVersusSeeoutSoln(); // Executes soln's runExercise();
    }
};

class FloatsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit FloatsSoln(QObject *parent = 0)
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

class Floats : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Floats(QObject *parent = 0)
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
        mSolutionPtr = new FloatsSoln(); // Executes soln's runExercise();
    }
};

class CONSTANTS : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit CONSTANTS(QObject *parent = 0)
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

class Chars : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Chars(QObject *parent = 0)
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

class StandardStringsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StandardStringsSoln(QObject *parent = 0)
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

class StandardStrings : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StandardStrings(QObject *parent = 0)
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
        mSolutionPtr = new StandardStringsSoln(); // Executes soln's runExercise();
    }
};

#endif // C01_S03_H
