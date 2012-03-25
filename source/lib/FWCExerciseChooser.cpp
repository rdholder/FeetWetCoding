// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <include/lib/FWCExerciseChooser.h>
#include <include/exercises/exercises.h>
#include <MyCode.h>
#include <iostream>
#include <QFile>
#include <QDir>
#include <QDialog>

extern QDialog *theWindow;

FWCExerciseChooser::FWCExerciseChooser(QObject *parent)
    :QObject(parent)
    ,mSelectedExercise(NULL)
    ,mCurrentChapter("")
    ,mCurrentSection("")
    ,mCurrentExercise("")
    ,mChapterChooser(NULL)
    ,mSectionChooser(NULL)
    ,mExerciseChooser(NULL)
    ,mHlayout(NULL)
    ,mOkToRun(false)
{
    mHlayout = new QHBoxLayout();
    createExercisesMap();

    QObject::connect(qApp, SIGNAL(lastWindowClosed()),
                     this, SLOT(saveCurrentExercise()));

    QObject::connect(&mExerciseLauncher, SIGNAL(currentExerciseFinished()),
                     this, SLOT(currentExerciseFinished()));

    //Try the defaultconfig if config isn't found
    if ( loadPreviousExerciseEnabled() )
    {
        loadPreviousExercise();
    }

    //Need to choose a chapter, which will trigger selection
    //of a section and exercise. This will create and populate
    //the chapter, section, and exercise list boxes.
    selectChapter(mCurrentChapter);

    //Give the exercise chooser focus so user can use
    //arrow keys to run through the list.
    giveFocusToExerciseChooser();
}

FWCExerciseChooser::~FWCExerciseChooser()
{
}

FeetWetCodingExercise *
FWCExerciseChooser::getExerciseFromName( const QString & name )
{
    //Chapter 1

    //Section 2 - Getting_Started
    if( "Welcome" == name ){ return new Welcome(&mExerciseLauncher); }
    if( "ChangeText" == name ){ return new ChangeText(&mExerciseLauncher); }
    if( "ChangeX" == name ){ return new ChangeX(&mExerciseLauncher); }
    if( "ChangeY" == name ){ return new ChangeY(&mExerciseLauncher); }
    if( "ChangeXY" == name ){ return new ChangeXY(&mExerciseLauncher); }
    if( "ChangeColor" == name ){ return new ChangeColor(&mExerciseLauncher); }
    if( "ChangeFontSize" == name ){ return new ChangeFontSize(&mExerciseLauncher); }
    if( "DrawLines" == name ){ return new DrawLines(&mExerciseLauncher); }
    if( "DrawCircles" == name ){ return new DrawCircles(&mExerciseLauncher); }
    if( "DrawRectangles" == name ){ return new DrawRectangles(&mExerciseLauncher); }
    if( "DrawDots" == name ){ return new DrawDots(&mExerciseLauncher); }
    if( "DrawEllipses" == name ){ return new DrawEllipses(&mExerciseLauncher); }
    if( "DrawingText" == name ){ return new DrawingText(&mExerciseLauncher); }
    if( "DrawingImages" == name ){ return new DrawingImages(&mExerciseLauncher); }
    if( "seeoutIntro" == name ){ return new seeoutIntro(&mExerciseLauncher); }
    if( "seeoutFormatting" == name ){ return new seeoutFormatting(&mExerciseLauncher); }
    if( "OnYourOwn" == name ){ return new OnYourOwn(&mExerciseLauncher); }
    if( "ColorNames" == name ){ return new ColorNames(&mExerciseLauncher); }
    if( "FontProportions" == name ){ return new FontProportions(&mExerciseLauncher); }

    //Section 3 - Types_Variables
    if( "NumericTypes" == name ){ return new NumericTypes(&mExerciseLauncher); }
    if( "DrawingVersusSeeout" == name ){ return new DrawingVersusSeeout(&mExerciseLauncher); }
    if( "CONSTANTS" == name ){ return new CONSTANTS(&mExerciseLauncher); }
    if( "Chars" == name ){ return new Chars(&mExerciseLauncher); }
    if( "Booleans" == name ){ return new Booleans(&mExerciseLauncher); }
    if( "StandardStrings" == name ){ return new StandardStrings(&mExerciseLauncher); }
//    if( "Arrays" == name ){ return new Arrays(&mExerciseLauncher); }

    //Section 4 - Expessions_Syntax
    if( "AssignmentArithmetic" == name ){ return new AssignmentArithmetic(&mExerciseLauncher); }
    if( "OrderOfOperations" == name ){ return new OrderOfOperations(&mExerciseLauncher); }
    if( "PreAndPostIncAndDec" == name ){ return new PreAndPostIncAndDec(&mExerciseLauncher); }
    if( "ModulusOperator" == name ){ return new ModulusOperator(&mExerciseLauncher); }
    if( "BlocksAndScope" == name ){ return new BlocksAndScope(&mExerciseLauncher); }
    if( "MathFunctions" == name ){ return new MathFunctions(&mExerciseLauncher); }
    if( "randomAndrandomRange" == name ){ return new randomAndrandomRange(&mExerciseLauncher); }
    if( "DistanceEquation" == name ){ return new DistanceEquation(&mExerciseLauncher); }
    if( "Misdirection" == name ){ return new Misdirection(&mExerciseLauncher); }

    //Section 5 - Loops_Logic
    if( "WhileLoopIntro" == name ){ return new WhileLoopIntro(&mExerciseLauncher); }
    if( "ForLoopIntro" == name ){ return new ForLoopIntro(&mExerciseLauncher); }
    if( "WhileLoop1" == name ){ return new WhileLoop1(&mExerciseLauncher); }
    if( "InfiniteLooping1" == name ){ return new InfiniteLooping1(&mExerciseLauncher); }
    if( "OYO1" == name ){ return new C01S05_OYO1(&mExerciseLauncher); }
    if( "OYO2" == name ){ return new C01S05_OYO2(&mExerciseLauncher); }
    if( "WhileLoop2" == name ){ return new WhileLoop2(&mExerciseLauncher); }
    if( "WhileLoop3" == name ){ return new WhileLoop3(&mExerciseLauncher); }
    if( "OYO3" == name ){ return new C01S05_OYO3(&mExerciseLauncher); }
    if( "OYO4" == name ){ return new C01S05_OYO4(&mExerciseLauncher); }
    if( "WhileLoop4" == name ){ return new WhileLoop4(&mExerciseLauncher); }
    if( "WhileLoop5" == name ){ return new WhileLoop5(&mExerciseLauncher); }
    if( "ForLoops1" == name ){ return new ForLoops1(&mExerciseLauncher); }
    if( "ForLoops2" == name ){ return new ForLoops2(&mExerciseLauncher); }
    if( "ForLoops3" == name ){ return new ForLoops3(&mExerciseLauncher); }
    if( "IfThen1" == name ){ return new IfThen1(&mExerciseLauncher); }
    if( "IfThen2" == name ){ return new IfThen2(&mExerciseLauncher); }
    if( "IfThen3" == name ){ return new IfThen3(&mExerciseLauncher); }
    if( "IfThen4" == name ){ return new IfThen4(&mExerciseLauncher); }
    if( "Switch1" == name ){ return new Switch1(&mExerciseLauncher); }
    if( "DivideByZero" == name ){ return new DivideByZero(&mExerciseLauncher); }
    if( "Primes1" == name ){ return new Primes1(&mExerciseLauncher); }
    if( "OYO_Primes2" == name ){ return new OYO_Primes2(&mExerciseLauncher); }
    if( "OYO5" == name ){ return new C01S05_OYO5(&mExerciseLauncher); }

    //Section 6 - fwcTools
    if( "Sleep1" == name ){ return new Sleep1(&mExerciseLauncher); }
    if( "SingleKeyInput1" == name ){ return new SingleKeyInput1(&mExerciseLauncher); }
    if( "StringInput1" == name ){ return new StringInput1(&mExerciseLauncher); }
    if( "ShiftItem1" == name ){ return new ShiftItem1(&mExerciseLauncher); }
    if( "MoveItem1" == name ){ return new MoveItem1(&mExerciseLauncher); }
    if( "ScaleItem1" == name ){ return new ScaleItem1(&mExerciseLauncher); }
    if( "RotateItem1" == name ){ return new RotateItem1(&mExerciseLauncher); }
    if( "ChangeZ1" == name ){ return new ChangeZ1(&mExerciseLauncher); }
    if( "ChangeLineEnd1" == name ){ return new ChangeLineEnd1(&mExerciseLauncher); }
    if( "ChangeWidthAndHeight1" == name ){ return new ChangeWidthAndHeight1(&mExerciseLauncher); }
    if( "ChangeRadius1" == name ){ return new ChangeRadius1(&mExerciseLauncher); }
    if( "ChangeColor1" == name ){ return new ChangeColor1(&mExerciseLauncher); }
    if( "ChangeLineWidth1" == name ){ return new ChangeLineWidth1(&mExerciseLauncher); }
    if( "ChangeFontSize1" == name ){ return new ChangeFontSize1(&mExerciseLauncher); }
    if( "ChangeText1" == name ){ return new ChangeText1(&mExerciseLauncher); }
    if( "ChangeInt1" == name ){ return new ChangeInt1(&mExerciseLauncher); }
    if( "ChangeFloat1" == name ){ return new ChangeFloat1(&mExerciseLauncher); }
    if( "EraseItem1" == name ){ return new EraseItem1(&mExerciseLauncher); }
    if( "ClearItems1" == name ){ return new ClearItems1(&mExerciseLauncher); }

    //Section 7 - Storing_Data
    if( "Arrays1" == name ){ return new Arrays1(&mExerciseLauncher); }

    //Section 7 - ...

    //Section 8 - ...

    //Section 9 - ...

    //Section 9 - Classes Intro
    if( "Classes1" == name ){ return new Classes1(&mExerciseLauncher); }

    //Chapter 8 - Game_Programming

    //Section 3 - TopDown2D
    if( "TopDown2D" == name ){ return new TopDown2D(&mExerciseLauncher); }

    // MyCode "Chapter" (only one section)

    if( "MyCode0" == name ){ return new MyCode0(&mExerciseLauncher); }
    if( "MyCode1" == name ){ return new MyCode1(&mExerciseLauncher); }
    if( "MyCode2" == name ){ return new MyCode2(&mExerciseLauncher); }
    if( "MyCode3" == name ){ return new MyCode3(&mExerciseLauncher); }
    if( "MyCode4" == name ){ return new MyCode4(&mExerciseLauncher); }
    if( "MyCode5" == name ){ return new MyCode5(&mExerciseLauncher); }
    if( "MyCode6" == name ){ return new MyCode6(&mExerciseLauncher); }
    if( "MyCode7" == name ){ return new MyCode7(&mExerciseLauncher); }
    if( "MyCode8" == name ){ return new MyCode8(&mExerciseLauncher); }
    if( "MyCode9" == name ){ return new MyCode9(&mExerciseLauncher); }

    return NULL;
}

void FWCExerciseChooser::createExercisesMap()
{
    mExerciseMap.clear();

    std::map<QString, std::vector<QString> > sections;
    std::vector<QString> exercises;

    //C01-Beginner_Exercises
    sections.clear();

    //S02-Getting_Started
    exercises.clear();
    exercises.push_back( "Welcome" );
    exercises.push_back( "ChangeText" );
    exercises.push_back( "ChangeX" );
    exercises.push_back( "ChangeY" );
    exercises.push_back( "ChangeXY" );
    exercises.push_back( "ChangeColor" );
    exercises.push_back( "ChangeFontSize" );
    exercises.push_back( "DrawLines" );
    exercises.push_back( "DrawCircles" );
    exercises.push_back( "DrawRectangles" );
    exercises.push_back( "DrawDots" );
    exercises.push_back( "DrawEllipses" );
    exercises.push_back( "DrawingText" );
    exercises.push_back( "DrawingImages" );
    exercises.push_back( "seeoutIntro" );
    exercises.push_back( "seeoutFormatting" );
    exercises.push_back( "OnYourOwn" );
    exercises.push_back( "ColorNames" );
    exercises.push_back( "FontProportions" );
    sections["S02-Getting_Started"] = exercises;

    //S03-Types_Variables
    exercises.clear();
    exercises.push_back( "NumericTypes" );
    exercises.push_back( "DrawingVersusSeeout" );
    exercises.push_back( "CONSTANTS" );
    exercises.push_back( "Chars" );
    exercises.push_back( "Booleans" );
    exercises.push_back( "StandardStrings" );
//    exercises.push_back( "Arrays" );
    sections["S03-Types_Variables"] = exercises;

    //S04-Expressions_Syntax
    exercises.clear();
    exercises.push_back( "AssignmentArithmetic" );
    exercises.push_back( "OrderOfOperations" );
    exercises.push_back( "PreAndPostIncAndDec" );
    exercises.push_back( "ModulusOperator" );
    exercises.push_back( "BlocksAndScope" );
    exercises.push_back( "MathFunctions" );
    exercises.push_back( "randomAndrandomRange" );
    exercises.push_back( "DistanceEquation" );
    exercises.push_back( "Misdirection" );
    sections["S04-Expressions_Syntax"] = exercises;

    //S05-Loops_Logic
    exercises.clear();
    exercises.push_back( "WhileLoopIntro" );
    exercises.push_back( "ForLoopIntro" );
    exercises.push_back( "WhileLoop1" );
    exercises.push_back( "InfiniteLooping1" );
    exercises.push_back( "OYO1" );
    exercises.push_back( "OYO2" );
    exercises.push_back( "WhileLoop2" );
    exercises.push_back( "WhileLoop3" );
    exercises.push_back( "OYO3" );
    exercises.push_back( "OYO4" );
    exercises.push_back( "WhileLoop4" );
    exercises.push_back( "WhileLoop5" );
    exercises.push_back( "ForLoops1" );
    exercises.push_back( "ForLoops2" );
    exercises.push_back( "ForLoops3" );
    exercises.push_back( "IfThen1" );
    exercises.push_back( "IfThen2" );
    exercises.push_back( "IfThen3" );
    exercises.push_back( "IfThen4" );
    exercises.push_back( "Switch1" );
    exercises.push_back( "DivideByZero" );
    exercises.push_back( "Primes1" );
    exercises.push_back( "OYO_Primes2" );
    exercises.push_back( "OYO5" );
    sections["S05-Loops_Logic"] = exercises;

    //S06-fwcTools
    exercises.clear();
    exercises.push_back( "Sleep1" );
    exercises.push_back( "SingleKeyInput1" );
    exercises.push_back( "StringInput1" );
    exercises.push_back( "ShiftItem1" );
    exercises.push_back( "MoveItem1" );
    exercises.push_back( "ScaleItem1" );
    exercises.push_back( "RotateItem1" );
    exercises.push_back( "ChangeZ1" );
    exercises.push_back( "ChangeLineEnd1" );
    exercises.push_back( "ChangeWidthAndHeight1" );
    exercises.push_back( "ChangeRadius1" );
    exercises.push_back( "ChangeColor1" );
    exercises.push_back( "ChangeLineWidth1" );
    exercises.push_back( "ChangeFontSize1" );
    exercises.push_back( "ChangeText1" );
    exercises.push_back( "ChangeInt1" );
    exercises.push_back( "ChangeFloat1" );
    exercises.push_back( "EraseItem1" );
    exercises.push_back( "ClearItems1" );
    sections["S06-fwcTools"] = exercises;

    //S07-Storing_Data
    exercises.clear();
    exercises.push_back( "Arrays1" );
    sections["S07-Storing_Data"] = exercises;

    //S09-Classes_Intro
    exercises.clear();
    exercises.push_back( "Classes1" );
    sections["S09-Classes_Intro"] = exercises;

    mExerciseMap["C01-Beginner_Exercises"] = sections;


    //C08-Game_Programming
//    sections.clear();

//    //S03-TopDown2D
//    exercises.clear();
//    exercises.push_back( "TopDown2D" );
//    sections["S03-TopDown2D"] = exercises;

//    mExerciseMap["C08-Game_Programming"] = sections;

    //MyCode "Chapter"
    sections.clear();

    //MyCode "Exercises"
    exercises.clear();
    exercises.push_back( "MyCode0" );
    exercises.push_back( "MyCode1" );
    exercises.push_back( "MyCode2" );
    exercises.push_back( "MyCode3" );
    exercises.push_back( "MyCode4" );
    exercises.push_back( "MyCode5" );
    exercises.push_back( "MyCode6" );
    exercises.push_back( "MyCode7" );
    exercises.push_back( "MyCode8" );
    exercises.push_back( "MyCode9" );
    sections["MyCode"] = exercises;

    mExerciseMap["MyCode"] = sections;
}

void FWCExerciseChooser::selectChapter( const QString & selection )
{
    // Make sure the combobox has been created
    if ( NULL != mChapterChooser )
    {
        QObject::disconnect(mChapterChooser, SIGNAL(activated(QString)),
                            this, SLOT(chapterSelected(QString)));
        mHlayout->removeWidget(mChapterChooser);
        delete mChapterChooser;
        mChapterChooser = NULL;
    }

    mChapterChooser = new QComboBox();
    mChapterChooser->setMaxVisibleItems(50);
    QObject::connect(mChapterChooser, SIGNAL(activated(QString)),
                     this, SLOT(chapterSelected(QString)));
    for (mChptIter = mExerciseMap.begin(); mChptIter != mExerciseMap.end();
         ++mChptIter)
    {
        mChapterChooser->addItem(mChptIter->first);
    }

    mHlayout->addStretch();
    mHlayout->addWidget(mChapterChooser);

    // Find the selection and set it in the list
    if ( mExerciseMap.empty() )
        return;

    if ( selection.isEmpty() )
    {
        mCurrentChapter = mExerciseMap.begin()->first;
        mChapterChooser->setCurrentIndex(0);
    }

    else if ( mExerciseMap.find(selection) != mExerciseMap.end() )
    {
        mCurrentChapter = selection;
        mChapterChooser->setCurrentIndex(mChapterChooser->findText(mCurrentChapter));
    }

    // Update the Section list based on the chapter selection
    if ( NULL != mSectionChooser )
    {
        QObject::disconnect(mSectionChooser, SIGNAL(activated(QString)),
                            this, SLOT(sectionSelected(QString)));
        mHlayout->removeWidget(mSectionChooser);
        delete mSectionChooser;
        mSectionChooser = NULL;
    }

    mSectionChooser = new QComboBox();
    mSectionChooser->setMaxVisibleItems(50);
    QObject::connect(mSectionChooser, SIGNAL(activated(QString)),
                     this, SLOT(sectionSelected(QString)));

    for ( mSectIter = mExerciseMap[mCurrentChapter].begin();
          mSectIter != mExerciseMap[mCurrentChapter].end();
          ++mSectIter )
    {
        mSectionChooser->addItem(mSectIter->first);
    }

    mHlayout->addWidget(mSectionChooser);

    //Choose a section to go with the selected chapter.
    //If our current selection exists in the new section
    //list, great. If not, pass empty string and the first
    //section in the list will be selected by default.
    if ( mSectionChooser->findText(mCurrentSection) < 0 )
    {
        mCurrentSection.clear();
    }
    selectSection(mCurrentSection);
}

void FWCExerciseChooser::selectSection( const QString & selection )
{
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].empty() )
        return;

    if ( selection.isEmpty() )
    {
        mCurrentSection = mExerciseMap[mCurrentChapter].begin()->first;
        mSectionChooser->setCurrentIndex(0);
    }

    else if ( mExerciseMap[mCurrentChapter].find(selection) !=
                mExerciseMap[mCurrentChapter].end() )
    {
        mCurrentSection = selection;
        mSectionChooser->setCurrentIndex(mSectionChooser->findText(mCurrentSection));
    }

    // Update the Section list based on the chapter selection
    if ( NULL != mExerciseChooser )
    {
        QObject::disconnect(mExerciseChooser, SIGNAL(activated(QString)),
                            this, SLOT(exerciseSelected(QString)));
        mHlayout->removeWidget(mExerciseChooser);
        delete mExerciseChooser;
        mExerciseChooser = NULL;
    }

    mExerciseChooser = new QComboBox();
    mExerciseChooser->setMaxVisibleItems(50);
    QObject::connect(mExerciseChooser, SIGNAL(activated(QString)),
                     this, SLOT(exerciseSelected(QString)));

    for ( mExIter = mExerciseMap[mCurrentChapter][mCurrentSection].begin();
          mExIter != mExerciseMap[mCurrentChapter][mCurrentSection].end();
          ++mExIter )
    {
        mExerciseChooser->addItem(*mExIter);
    }

    mHlayout->addWidget(mExerciseChooser);

    //Choose an exercise to go with the selected chapter.
    //If our current selection exists in the new section
    //list, great. If not, pass empty string and the first
    //section in the list will be selected by default.
    if ( mExerciseChooser->findText(mCurrentExercise) < 0 )
    {
        mCurrentExercise.clear();
    }
    selectExercise(mCurrentExercise);
}

void FWCExerciseChooser::selectExercise( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "FWCExerciseChooser::selectExercise(" << selection << ")";
#endif
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].find(mCurrentSection) ==
         mExerciseMap[mCurrentChapter].end() ||
         mExerciseMap[mCurrentChapter][mCurrentSection].empty() )
    {
        qDebug() << "FAILED TO FIND CURRENT SECTION!";
        return;
    }

    QString selectedExercise("");

    if ( selection.isEmpty() )
    {
#ifdef DEBUG
        qDebug() << "Empty selection, so selecting first exercise in current section";
#endif
        selectedExercise = mExerciseMap[mCurrentChapter][mCurrentSection].at(0);
        mExerciseChooser->setCurrentIndex(0);
    }

    else
    {
        for ( unsigned int i=0; i < mExerciseMap[mCurrentChapter][mCurrentSection].size(); ++i )
        {
            if ( selection == mExerciseMap[mCurrentChapter][mCurrentSection][i] )  // found it
            {
                selectedExercise = selection;
                mExerciseChooser->setCurrentIndex(i);
                break;
            }
        }
    }

    // Did we find it?
    if ( selectedExercise.isEmpty() )
    {
        qDebug() << "FAILED TO FIND SELECTED EXERCISE!";
        return; // nope, so don't do anything
    }

    // Start the new exercise
    // This stops the old one if it's still running.
    mCurrentExercise = selectedExercise;

#ifdef DEBUG
    qDebug() << "CALL runCurrentExercise() with mCurrentExercise==" << selectedExercise;
#endif
    runCurrentExercise();
}

void FWCExerciseChooser::chapterSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "chapterSelected(): " << selection << "\n";
#endif
    selectChapter(selection);
}

void FWCExerciseChooser::sectionSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "sectionSelected(): " << selection << "\n";
#endif
    selectSection(selection);
}

void FWCExerciseChooser::exerciseSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "exerciseSelected(): " << selection << "\n";
#endif
    selectExercise(selection);
}

void FWCExerciseChooser::stopExercise()
{
    //Tell launcher to stop the exercise *before* deleting it (below).
    //Chooser owns the pointer, but Launcher needs it in order to stop it.
    mExerciseLauncher.stopCurrentExercise();

    ClearScreen();
    initOutputArea();

    if ( mSelectedExercise )
    {
        delete mSelectedExercise;
        mSelectedExercise = NULL;
    }
    else
    {
#ifdef DEBUG
        qDebug() << "mSelectedExercise is NULL here: " << __LINE__;
#endif
    }
}

void FWCExerciseChooser::runExercise( const QString & exerciseName )
{
    if ( !mOkToRun )
        return;

    stopExercise();
    mSelectedExercise = getExerciseFromName( exerciseName );

    if ( NULL == mSelectedExercise )
    {
        qDebug() << "mSelectedExercise IS NULL!";
        return;
    }

    //FWCExerciseChooser retains ownership of the mSelectedExercise
    //pointer. ExerciseLauncher should not delete this passed in pointer!

    mExerciseLauncher.launchExercise(mSelectedExercise);

    //DO WE STILL NEED THIS HERE?
    giveFocusToExerciseChooser();
}

void FWCExerciseChooser::runCurrentExercise()
{
#ifdef DEBUG
    qDebug() << "\n\n\n*****************************************************";
    qDebug() << "START NEXT SELECTION - ENTER FWCExerciseChooser::runCurrentExercise()";
#endif
    runExercise( mCurrentExercise );
}

void FWCExerciseChooser::saveCurrentExercise()
{
    QFile file("lastexercise.txt");
    if ( file.exists() )
    {
        file.remove();
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
#ifdef DEBUG
        qDebug() << "Failed to open file \"lastexercise.txt\" for writing."
                 << " Cannot save current exercise.\n";
#endif
        return;
    }

    QTextStream out(&file);
    out << "chapter:" << mCurrentChapter << "\n";
    out << "section:" << mCurrentSection << "\n";
    out << "exercise:" << mCurrentExercise << "\n";

    file.close();
}

void FWCExerciseChooser::loadPreviousExercise()
{
    QFile file("lastexercise.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file \"lastexercise.txt\" for reading."
                 << " Cannot load previous exercise.\n";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(":", QString::SkipEmptyParts);
        if ( 2 != list.count() )
            continue;

        if ( list.at(0).contains("chapter", Qt::CaseInsensitive) )
        {
            mCurrentChapter = ( list.at(1) );
        }
        else if ( list.at(0).contains("section", Qt::CaseInsensitive) )
        {
            mCurrentSection = ( list.at(1) );
        }
        else if ( list.at(0).contains("exercise", Qt::CaseInsensitive) )
        {
            mCurrentExercise = ( list.at(1) );
        }
    }

    file.close();
}

bool FWCExerciseChooser::getSettingLoadPreviousExerciseEnabled( const QString & filename )
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw false;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(":", QString::SkipEmptyParts);
        if ( 2 != list.count() )
            continue;

        if ( list.at(0).contains("reload_prev_exercise", Qt::CaseInsensitive) )
        {
            return ( list.at(1).contains("true", Qt::CaseInsensitive) );
        }
    }

    //Didn't find the setting
    throw false;
}

bool FWCExerciseChooser::loadPreviousExerciseEnabled()
{
    try
    {
        // Try the user's config file first.
        return getSettingLoadPreviousExerciseEnabled("config.txt");
    }
    catch ( bool val ) { qDebug() << "Failed to get prevEx setting from user config.\n"; }

    try
    {
        // Try the default config file.
        return getSettingLoadPreviousExerciseEnabled(getDefaultConfigFilePath());
    }
    catch ( bool val ) { qDebug() << "Failed to get prevEx setting from default config.\n"; }

    return false;
}

void FWCExerciseChooser::handleKeyEvent(QKeyEvent *event)
{
    mExerciseLauncher.setKeyEvent(*event);
}

void FWCExerciseChooser::handleNewMousePosEvent(QPoint pos)
{
    //Figure out which exercise pane should get keyboard inputs
    //based on where the mouse is located
    int x(pos.x());
    int y(pos.y());
    int pane(-1);

    switch ( mExerciseLauncher.getNumPanes() ) {

    case 2:
        if ( x > 0 && x < theWindow->width()/2-WINDOW_X )
            pane = 0;
        else if ( x >= (theWindow->width()/2-WINDOW_X) && x < theWindow->width() )
            pane = 1;
        break;

    case 4:
        if ( x > 0 && x < theWindow->width()/2-WINDOW_X )
        {
            if ( y > 0 && y < theWindow->height()/2 )
                pane = 0;
            else
                pane = 2;
        }
        else if ( x >= theWindow->width()/2-WINDOW_X && x < theWindow->width() )
        {
            if ( y > 0 && y < theWindow->height()/2 )
                pane = 1;
            else if ( y >= theWindow->height()/2 && y < theWindow->height() )
                pane = 3;
        }

        break;

    default:
        pane = 0;
        break;
    }

    //Make sure we got a valid pane
    if ( pane < 0 )
        pane = 0;

    mExerciseLauncher.setWhichPaneHasFocus(pane);
}

void FWCExerciseChooser::sceneCleared()
{
    mExerciseLauncher.sceneCleared();
}

void FWCExerciseChooser::currentExerciseFinished()
{
    giveFocusToExerciseChooser();
}

void FWCExerciseChooser::giveFocusToExerciseChooser()
{
    //Give the exercise chooser focus so user can use
    //arrow keys to run through the list.
    if ( NULL != mExerciseChooser )
    {
        mExerciseChooser->setFocus();
    }
}
