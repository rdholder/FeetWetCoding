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

    // If config setting reload_prev_exercise is true, load
    // the previous exercise stored in the user's config file
    QString settingVal;
    getSetting("reload_prev_exercise", settingVal);
    if ( 0 == settingVal.compare("true", Qt::CaseInsensitive) ) //0 means they're equal
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
    //Chapter 1 - Beginner_Exercises

    //Section 1 - fwcTools1
    if( "Welcome" == name ){ return new Welcome(&mExerciseLauncher); }
    if( "ChangeTextParameter" == name ){ return new ChangeTextParameter(&mExerciseLauncher); }
    if( "ChangeXParameter" == name ){ return new ChangeXParameter(&mExerciseLauncher); }
    if( "ChangeYParameter" == name ){ return new ChangeYParameter(&mExerciseLauncher); }
    if( "ChangeXYParameters" == name ){ return new ChangeXYParameters(&mExerciseLauncher); }
    if( "ChangeColorParameter" == name ){ return new ChangeColorParameter(&mExerciseLauncher); }
    if( "ChangeFontSizeParameter" == name ){ return new ChangeFontSizeParameter(&mExerciseLauncher); }
    if( "DrawLines" == name ){ return new DrawLines(&mExerciseLauncher); }
    if( "DrawCircles" == name ){ return new DrawCircles(&mExerciseLauncher); }
    if( "DrawRectangles" == name ){ return new DrawRectangles(&mExerciseLauncher); }
    if( "DrawDots" == name ){ return new DrawDots(&mExerciseLauncher); }
    if( "DrawEllipses" == name ){ return new DrawEllipses(&mExerciseLauncher); }
    if( "DrawingText" == name ){ return new DrawingText(&mExerciseLauncher); }
    if( "DrawingImages" == name ){ return new DrawingImages(&mExerciseLauncher); }
    if( "seeoutIntro" == name ){ return new seeoutIntro(&mExerciseLauncher); }
    if( "seeoutFormatting" == name ){ return new seeoutFormatting(&mExerciseLauncher); }
    if( "OnYourOwn_OYO" == name ){ return new OnYourOwn_OYO(&mExerciseLauncher); }
    if( "ColorNames" == name ){ return new ColorNames(&mExerciseLauncher); }
    if( "FontProportions" == name ){ return new FontProportions(&mExerciseLauncher); }

    //Section 2 - Types_Variables
    if( "NumericTypes" == name ){ return new NumericTypes(&mExerciseLauncher); }
    if( "DrawingVersusSeeout" == name ){ return new DrawingVersusSeeout(&mExerciseLauncher); }
    if( "CONSTANTS" == name ){ return new CONSTANTS(&mExerciseLauncher); }
    if( "Chars" == name ){ return new Chars(&mExerciseLauncher); }
    if( "Booleans" == name ){ return new Booleans(&mExerciseLauncher); }
    if( "StandardStrings" == name ){ return new StandardStrings(&mExerciseLauncher); }

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
    if( "ForLoops2" == name ){ return new ForLoops2(&mExerciseLauncher); }
    if( "ForLoops3" == name ){ return new ForLoops3(&mExerciseLauncher); }
    if( "ForLoops4" == name ){ return new ForLoops4(&mExerciseLauncher); }
    if( "IfThen1" == name ){ return new IfThen1(&mExerciseLauncher); }
    if( "IfThen2" == name ){ return new IfThen2(&mExerciseLauncher); }
    if( "IfThen3" == name ){ return new IfThen3(&mExerciseLauncher); }
    if( "IfThen4_OYO" == name ){ return new IfThen4_OYO(&mExerciseLauncher); }
    if( "Switch1" == name ){ return new Switch1(&mExerciseLauncher); }
    if( "DivideByZero" == name ){ return new DivideByZero(&mExerciseLauncher); }
    if( "Primes1" == name ){ return new Primes1(&mExerciseLauncher); }
    if( "Primes2_OYO" == name ){ return new Primes2_OYO(&mExerciseLauncher); }
    if( "OYO5" == name ){ return new C01S05_OYO5(&mExerciseLauncher); }

    //Section 6 - fwcTools2
    if( "Sleep" == name ){ return new Sleep(&mExerciseLauncher); }
    if( "SingleKeyInput" == name ){ return new SingleKeyInput(&mExerciseLauncher); }
    if( "StringInput" == name ){ return new StringInput(&mExerciseLauncher); }
    if( "Shift" == name ){ return new Shift(&mExerciseLauncher); }
    if( "Relocate" == name ){ return new Relocate(&mExerciseLauncher); }
    if( "Scale" == name ){ return new Scale(&mExerciseLauncher); }
    if( "Rotate" == name ){ return new Rotate(&mExerciseLauncher); }
    if( "ChangeZ" == name ){ return new ChangeZ(&mExerciseLauncher); }
    if( "ChangeLineEnd" == name ){ return new ChangeLineEnd(&mExerciseLauncher); }
    if( "ChangeRadius" == name ){ return new ChangeRadius(&mExerciseLauncher); }
    if( "ChangeColor" == name ){ return new ChangeColor(&mExerciseLauncher); }
    if( "ChangeLineWidth" == name ){ return new ChangeLineWidth(&mExerciseLauncher); }
    if( "ChangeFontSize" == name ){ return new ChangeFontSize(&mExerciseLauncher); }
    if( "ChangeText" == name ){ return new ChangeText(&mExerciseLauncher); }
    if( "ChangeInt" == name ){ return new ChangeInt(&mExerciseLauncher); }
    if( "ChangeFloat" == name ){ return new ChangeFloat(&mExerciseLauncher); }
    if( "Erase" == name ){ return new Erase(&mExerciseLauncher); }
    if( "Clear" == name ){ return new Clear(&mExerciseLauncher); }
    if( "CenteredText" == name ){ return new CenteredText(&mExerciseLauncher); }

    //Section 7 - Storing_Data
    if( "WhyUseArrays" == name ){ return new WhyUseArrays(&mExerciseLauncher); }
    if( "Arrays1" == name ){ return new Arrays1(&mExerciseLauncher); }
    if( "MadLib" == name ){ return new MadLib(&mExerciseLauncher); }
    if( "FillAnArray" == name ){ return new FillAnArray(&mExerciseLauncher); }
    if( "BubbleSort1" == name ){ return new BubbleSort1(&mExerciseLauncher); }
    if( "BubbleSort2" == name ){ return new BubbleSort2(&mExerciseLauncher); }

    //Section 7 - ...

    //Section 8 - ...

    //Section 9 - ...

    //Section 9 - Classes Intro
    if( "Classes1" == name ){ return new Classes1(&mExerciseLauncher); }

    //Chapter 8 - Game_Programming

    //Section 3 - Top_Down_2D
    if( "SpaceshipFlyer" == name ){ return new SpaceshipFlyer(&mExerciseLauncher); }

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

    //S01-fwcTools1
    exercises.clear();
    exercises.push_back( "Welcome" );
    exercises.push_back( "ChangeTextParameter" );
    exercises.push_back( "ChangeXParameter" );
    exercises.push_back( "ChangeYParameter" );
    exercises.push_back( "ChangeXYParameters" );
    exercises.push_back( "ChangeColorParameter" );
    exercises.push_back( "ChangeFontSizeParameter" );
    exercises.push_back( "DrawLines" );
    exercises.push_back( "DrawCircles" );
    exercises.push_back( "DrawRectangles" );
    exercises.push_back( "DrawDots" );
    exercises.push_back( "DrawEllipses" );
    exercises.push_back( "DrawingText" );
    exercises.push_back( "DrawingImages" );
    exercises.push_back( "seeoutIntro" );
    exercises.push_back( "seeoutFormatting" );
    exercises.push_back( "OnYourOwn_OYO" );
    exercises.push_back( "ColorNames" );
    exercises.push_back( "FontProportions" );
    sections["S01-fwcTools1"] = exercises;

    //S02-Types_Variables
    exercises.clear();
    exercises.push_back( "NumericTypes" );
    exercises.push_back( "DrawingVersusSeeout" );
    exercises.push_back( "CONSTANTS" );
    exercises.push_back( "Chars" );
    exercises.push_back( "Booleans" );
    exercises.push_back( "StandardStrings" );
    sections["S02-Types_Variables"] = exercises;

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
    exercises.push_back( "ForLoops2" );
    exercises.push_back( "ForLoops3" );
    exercises.push_back( "ForLoops4" );
    exercises.push_back( "IfThen1" );
    exercises.push_back( "IfThen2" );
    exercises.push_back( "IfThen3" );
    exercises.push_back( "IfThen4_OYO" );
    exercises.push_back( "Switch1" );
    exercises.push_back( "DivideByZero" );
    exercises.push_back( "Primes1" );
    exercises.push_back( "Primes2_OYO" );
    exercises.push_back( "OYO5" );
    sections["S05-Loops_Logic"] = exercises;

    //S06-fwcTools2
    exercises.clear();
    exercises.push_back( "Sleep" );
    exercises.push_back( "SingleKeyInput" );
    exercises.push_back( "StringInput" );
    exercises.push_back( "Shift" );
    exercises.push_back( "Relocate" );
    exercises.push_back( "Scale" );
    exercises.push_back( "Rotate" );
    exercises.push_back( "Erase" );
    exercises.push_back( "Clear" );
    exercises.push_back( "ChangeZ" );
    exercises.push_back( "ChangeLineEnd" );
    exercises.push_back( "ChangeLineWidth" );
    exercises.push_back( "ChangeRadius" );
    exercises.push_back( "ChangeColor" );
    exercises.push_back( "ChangeFontSize" );
    exercises.push_back( "ChangeText" );
    exercises.push_back( "ChangeInt" );
    exercises.push_back( "ChangeFloat" );
    exercises.push_back( "CenteredText" );

    sections["S06-fwcTools2"] = exercises;

    //S07-Storing_Data
    exercises.clear();
    exercises.push_back( "WhyUseArrays" );
    exercises.push_back( "Arrays1" );
    exercises.push_back( "MadLib" );
    exercises.push_back( "FillAnArray" );
    exercises.push_back( "BubbleSort1" );
    exercises.push_back( "BubbleSort2" );
    sections["S07-Storing_Data"] = exercises;

    //S09-Classes_Intro
    exercises.clear();
    exercises.push_back( "Classes1" );
    sections["S09-Classes_Intro"] = exercises;

    mExerciseMap["C01-Beginner_Exercises"] = sections;

    // Chapters 2 thru 7 ...

    //C08-Game_Programming
    sections.clear();

    //S03-Top_Down_2D
    exercises.clear();
    exercises.push_back( "SpaceshipFlyer" );
    sections["S03-Top_Down_2D"] = exercises;

    mExerciseMap["C08-Game_Programming"] = sections;

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
    qDebug() << "INFO: FWCExerciseChooser::selectExercise(" << selection << ")";
#endif
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].find(mCurrentSection) ==
         mExerciseMap[mCurrentChapter].end() ||
         mExerciseMap[mCurrentChapter][mCurrentSection].empty() )
    {
        qDebug() << "ERROR: FWCExerciseChooser::selectExercise("<<selection<<") - Failed to find current section.";
        return;
    }

    QString selectedExercise("");

    if ( selection.isEmpty() )
    {
#ifdef DEBUG
        qDebug() << "INFO: Empty selection, so selecting first exercise in current section";
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
        qDebug() << "ERROR: FWCExerciseChooser::selectExercise("<<selection<<") - Failed to find selected exercise.";
        return; // nope, so don't do anything
    }

    // Start the new exercise
    // This stops the old one if it's still running.
    mCurrentExercise = selectedExercise;

#ifdef DEBUG
    qDebug() << "INFO: CALL runCurrentExercise() with mCurrentExercise==" << selectedExercise;
#endif
    runCurrentExercise();
}

void FWCExerciseChooser::chapterSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "INFO: chapterSelected(): " << selection << "\n";
#endif
    selectChapter(selection);
}

void FWCExerciseChooser::sectionSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "INFO: sectionSelected(): " << selection << "\n";
#endif
    selectSection(selection);
}

void FWCExerciseChooser::exerciseSelected( const QString & selection )
{
#ifdef DEBUG
    qDebug() << "INFO: exerciseSelected(): " << selection << "\n";
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
}

void FWCExerciseChooser::runExercise( const QString & exerciseName )
{
    if ( !mOkToRun )
        return;

    stopExercise();
    mSelectedExercise = getExerciseFromName( exerciseName );

    if ( NULL == mSelectedExercise )
    {
        qDebug() << "ERROR: FWCExerciseChooser::runExercise("<<exerciseName<<") - Failed to find exercise from name.";
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
    runExercise( mCurrentExercise );
}

void FWCExerciseChooser::saveCurrentExercise()
{
    saveCurrentExerciseToFile( getLastExerciseFilePath(), mCurrentChapter, mCurrentSection, mCurrentExercise );
}

void FWCExerciseChooser::loadPreviousExercise()
{
    getPreviousExerciseFromFile( getLastExerciseFilePath(), mCurrentChapter, mCurrentSection, mCurrentExercise );
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
