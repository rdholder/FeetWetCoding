// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef C01_S01_H
#define C01_S01_H

#include <exercises/FeetWetCodingExerciseBase.h>
#include <setup.h>


class WelcomeSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit WelcomeSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class Welcome : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Welcome(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new WelcomeSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeTextParameterSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeTextParameterSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeTextParameter : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeTextParameter(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeTextParameterSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeXParameterSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeXParameterSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeXParameter : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXParameter(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeXParameterSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeYParameterSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeYParameterSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeYParameter : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeYParameter(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeYParameterSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeXYParametersSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeXYParametersSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeXYParameters : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXYParameters(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeXYParametersSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeColorParameterSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeColorParameterSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeColorParameter : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColorParameter(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeColorParameterSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeFontSizeParameterSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeFontSizeParameterSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeFontSizeParameter : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFontSizeParameter(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeFontSizeParameterSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawLinesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawLinesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawLines : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawLines(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawLinesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawCirclesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawCirclesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawCircles : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawCircles(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawCirclesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawRectanglesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawRectanglesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawRectangles : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawRectangles(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawRectanglesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawDotsSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawDotsSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawDots : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawDots(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawDotsSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawEllipsesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawEllipsesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawEllipses : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawEllipses(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawEllipsesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawingTextSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawingTextSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawingText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingText(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawingTextSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class DrawingImagesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit DrawingImagesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class DrawingImages : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingImages(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new DrawingImagesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class seeoutIntroSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit seeoutIntroSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class seeoutIntro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutIntro(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new seeoutIntroSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class seeoutFormattingSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit seeoutFormattingSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class seeoutFormatting : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutFormatting(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new seeoutFormattingSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ColorNamesSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ColorNamesSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ColorNames : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ColorNames(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ColorNamesSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class OnYourOwn_OYOSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit OnYourOwn_OYOSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class OnYourOwn_OYO : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OnYourOwn_OYO(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new OnYourOwn_OYOSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class FontProportionsSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit FontProportionsSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class FontProportions : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit FontProportions(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new FontProportionsSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

#endif // C01_S01_H
