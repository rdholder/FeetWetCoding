// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S02_H
#define C01_S02_H

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

class ChangeXSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeXSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeX : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeX(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeXSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeYSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeYSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeY(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeYSoln(parent);
        if ( mSolutionPtr )
        {
            mSolutionPtr->start();
        }
    }
};

class ChangeXYSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit ChangeXYSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class ChangeXY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXY(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new ChangeXYSoln(parent);
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

class OnYourOwnSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit OnYourOwnSoln(QObject *parent = 0)
        :FeetWetCodingSolution(parent){}

protected:
    void runExercise();
};

class OnYourOwn : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OnYourOwn(QObject *parent = 0)
        :FeetWetCodingExercise(parent)
    {
        //If this exercise has a solution, launch it
        this->setupSolution(parent);
    }

protected:
    void runExercise();

    void setupSolution(QObject *parent=0)
    {
        mSolutionPtr = new OnYourOwnSoln(parent);
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

#endif // C01_S02_H
