// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S06_H
#define C01_S06_H

#include <exercises/FeetWetCodingExerciseBase.h>

class SleepSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit SleepSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Sleep : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Sleep(QObject *parent = 0)
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
        mSolutionPtr = new SleepSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class SingleKeyInputSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit SingleKeyInputSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class SingleKeyInput : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SingleKeyInput(QObject *parent = 0)
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
        mSolutionPtr = new SingleKeyInputSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class StringInputSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit StringInputSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class StringInput : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit StringInput(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new StringInputSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ShiftSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ShiftSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Shift : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Shift(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ShiftSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class RelocateSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit RelocateSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Relocate : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Relocate(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new RelocateSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ScaleSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ScaleSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Scale : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Scale(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ScaleSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class RotateSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit RotateSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Rotate : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Rotate(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new RotateSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeZSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeZSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeZ : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeZ(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeZSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeLineEndSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeLineEndSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeLineEnd : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeLineEnd(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeLineEndSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeRadiusSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeRadiusSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeRadius : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeRadius(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeRadiusSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeColorSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeColorSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeColor : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColor(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeColorSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeLineWidthSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeLineWidthSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeLineWidth : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeLineWidth(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeLineWidthSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeFontSizeSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeFontSizeSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeFontSize : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFontSize(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeFontSizeSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeTextSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeTextSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeText(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeTextSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeIntSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeIntSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeInt : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeInt(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeIntSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeFloatSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeFloatSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeFloat : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFloat(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeFloatSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class EraseSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit EraseSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Erase : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Erase(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new EraseSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ClearSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ClearSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Clear : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Clear(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ClearSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S06_H
