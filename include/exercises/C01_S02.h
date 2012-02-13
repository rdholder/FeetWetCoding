// FeetWetCoding/include/exercises/C01_S02.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef C01_S02_H
#define C01_S02_H

#include <exercises/FeetWetCodingExercise.h>
#include <setup.h>


class WelcomeSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WelcomeSoln(QObject *parent = 0)
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

class Welcome : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Welcome(QObject *parent = 0)
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
        mSolutionPtr = new WelcomeSoln(); // Executes soln's runExercise();
    }
};

class ChangeTextSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeTextSoln(QObject *parent = 0)
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

class ChangeText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeText(QObject *parent = 0)
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
        mSolutionPtr = new ChangeTextSoln(); // Executes soln's runExercise();
    }
};

class ChangeXSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXSoln(QObject *parent = 0)
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

class ChangeX : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeX(QObject *parent = 0)
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
        mSolutionPtr = new ChangeXSoln(); // Executes soln's runExercise();
    }
};

class ChangeYSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeYSoln(QObject *parent = 0)
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

class ChangeY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeY(QObject *parent = 0)
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
        mSolutionPtr = new ChangeYSoln(); // Executes soln's runExercise();
    }
};

class ChangeXYSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXYSoln(QObject *parent = 0)
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

class ChangeXY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXY(QObject *parent = 0)
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
        mSolutionPtr = new ChangeXYSoln(); // Executes soln's runExercise();
    }
};

class ChangeColorSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColorSoln(QObject *parent = 0)
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

class ChangeColor : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColor(QObject *parent = 0)
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
        mSolutionPtr = new ChangeColorSoln(); // Executes soln's runExercise();
    }
};

class ChangeFontSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFontSoln(QObject *parent = 0)
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

class ChangeFont : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFont(QObject *parent = 0)
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
        mSolutionPtr = new ChangeFontSoln(); // Executes soln's runExercise();
    }
};

class DrawLinesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawLinesSoln(QObject *parent = 0)
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

class DrawLines : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawLines(QObject *parent = 0)
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
        mSolutionPtr = new DrawLinesSoln(); // Executes soln's runExercise();
    }
};

class DrawCirclesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawCirclesSoln(QObject *parent = 0)
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

class DrawCircles : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawCircles(QObject *parent = 0)
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
        mSolutionPtr = new DrawCirclesSoln(); // Executes soln's runExercise();
    }
};

class DrawRectanglesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawRectanglesSoln(QObject *parent = 0)
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

class DrawRectangles : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawRectangles(QObject *parent = 0)
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
        mSolutionPtr = new DrawRectanglesSoln(); // Executes soln's runExercise();
    }
};

class DrawDotsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawDotsSoln(QObject *parent = 0)
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

class DrawDots : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawDots(QObject *parent = 0)
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
        mSolutionPtr = new DrawDotsSoln(); // Executes soln's runExercise();
    }
};

class DrawEllipsesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawEllipsesSoln(QObject *parent = 0)
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

class DrawEllipses : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawEllipses(QObject *parent = 0)
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
        mSolutionPtr = new DrawEllipsesSoln(); // Executes soln's runExercise();
    }
};

class DrawingTextSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingTextSoln(QObject *parent = 0)
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

class DrawingText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingText(QObject *parent = 0)
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
        mSolutionPtr = new DrawingTextSoln(); // Executes soln's runExercise();
    }
};

class DrawingImagesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingImagesSoln(QObject *parent = 0)
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

class DrawingImages : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingImages(QObject *parent = 0)
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
        mSolutionPtr = new DrawingImagesSoln(); // Executes soln's runExercise();
    }
};

class seeoutIntroSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutIntroSoln(QObject *parent = 0)
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

class seeoutIntro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutIntro(QObject *parent = 0)
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
        mSolutionPtr = new seeoutIntroSoln(); // Executes soln's runExercise();
    }
};

class seeoutFormattingSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutFormattingSoln(QObject *parent = 0)
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

class seeoutFormatting : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit seeoutFormatting(QObject *parent = 0)
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
        mSolutionPtr = new seeoutFormattingSoln(); // Executes soln's runExercise();
    }
};

class ColorNames : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ColorNames(QObject *parent = 0)
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

class OnYourOwnSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OnYourOwnSoln(QObject *parent = 0)
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

class OnYourOwn : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit OnYourOwn(QObject *parent = 0)
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
        mSolutionPtr = new OnYourOwnSoln(); // Executes soln's runExercise();
    }
};

class FontProportionsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit FontProportionsSoln(QObject *parent = 0)
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

class FontProportions : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit FontProportions(QObject *parent = 0)
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
        mSolutionPtr = new FontProportionsSoln(); // Executes soln's runExercise();
    }
};

#endif // C01_S02_H
