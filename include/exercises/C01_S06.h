// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S06_H
#define C01_S06_H

#include <exercises/FeetWetCodingExerciseBase.h>

class Sleep1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit Sleep1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new Sleep1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class SingleKeyInput1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit SingleKeyInput1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new SingleKeyInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class StringInput1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit StringInput1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

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
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new StringInput1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ShiftItem1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ShiftItem1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ShiftItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ShiftItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ShiftItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class MoveItem1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit MoveItem1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class MoveItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MoveItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new MoveItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ScaleItem1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ScaleItem1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ScaleItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ScaleItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ScaleItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class RotateItem1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit RotateItem1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class RotateItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit RotateItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new RotateItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeZ1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeZ1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeZ1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeZ1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeZ1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeLineEnd1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeLineEnd1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeLineEnd1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeLineEnd1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeLineEnd1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeWidthAndHeight1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeWidthAndHeight1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeWidthAndHeight1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeWidthAndHeight1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeWidthAndHeight1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeRadius1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeRadius1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeRadius1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeRadius1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeRadius1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeColor1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeColor1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeColor1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColor1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeColor1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeLineWidth1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeLineWidth1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeLineWidth1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeLineWidth1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeLineWidth1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeFontSize1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeFontSize1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeFontSize1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFontSize1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeFontSize1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeText1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeText1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeText1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeText1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeText1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeInt1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeInt1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeInt1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeInt1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeInt1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeFloat1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeFloat1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeFloat1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFloat1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeFloat1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class EraseItem1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit EraseItem1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class EraseItem1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit EraseItem1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new EraseItem1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ClearItems1Soln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ClearItems1Soln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ClearItems1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ClearItems1(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ClearItems1Soln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S06_H
