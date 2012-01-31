// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/include/exercises.h
// ---------------------------------------
// Class declarations for the individual exercises.  While the exercises are
// being written and the lesson plan is being organized, the exercises are
// contained in files named aXXXX.cpp to make it easier to add new exercises
// as we go.  By version 1.0 release, the exercise source files will be named
// the same as their classes here.

#ifndef exercises_H
#define exercises_H

#include <QObject>
#include <feetwetcodinglib.h>

int colortest();

class FeetWetCodingExercise : public QObject
{
    Q_OBJECT
public:
    explicit FeetWetCodingExercise(QObject *parent = 0);

signals:

public slots:
    virtual void update();
    virtual int runExercise()=0;

protected:
    SeeOut seeout;
};

////////////////////// I Beginner ///////////////////////////

class Intro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Intro(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class IntroSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntroSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class Welcome : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Welcome(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WelcomeSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WelcomeSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeText(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeTextSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeTextSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeX : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeX(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeXSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeY(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeYSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeYSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeXY : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXY(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeXYSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeXYSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeColor : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColor(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeColorSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeColorSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeFont : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFont(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class ChangeFontSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit ChangeFontSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class DrawingText : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingText(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class DrawingTextSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingTextSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class GraphicTools1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GraphicTools1(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class GraphicTools1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GraphicTools1Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class SeeOutIntro : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SeeOutIntro(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class SeeOutIntroSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SeeOutIntroSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class GetsAndPlusGets : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GetsAndPlusGets(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class GetsAndPlusGetsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GetsAndPlusGetsSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop1Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop2 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop2Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop2Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop3 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop3Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop3Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop4 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop4Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop4Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop5 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class WhileLoop5Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit WhileLoop5Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class IfThen1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class IfThen1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IfThen1Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class InfiniteLooping1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class InfiniteLooping1Soln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit InfiniteLooping1Soln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class DrawingPuzzles : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingPuzzles(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class DrawingPuzzlesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit DrawingPuzzlesSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class CirclesIdea1 : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit CirclesIdea1(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

////////////////////// II Intermediate ///////////////////////////
class IntroToClasses : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntroToClasses(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class IntroToClassesSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntroToClassesSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class IntroToEventHandling : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntroToEventHandling(QObject *parent = 0):FeetWetCodingExercise(parent)
    {
    }

signals:

public slots:
    virtual int runExercise();

};

class IntroToEventHandlingSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit IntroToEventHandlingSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

#endif // exercises_H
