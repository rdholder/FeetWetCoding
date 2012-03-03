// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <include/lib/FWCExerciseChooser.h>
#include <include/exercises/exercises.h>
#include <MyCode.h>
#include <iostream>
#include <QFile>

//QMutex ExerciseLauncher::eventMutex;
//QMutex ExerciseLauncher::itemMutex;
//bool ExerciseLauncher::mNewKeyEventReceived(false);
//QKeySequence ExerciseLauncher::mKey(0);

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

    //Try the defaultconfig if config isn't found
    if ( loadPreviousExerciseEnabled() )
    {
        loadPreviousExercise();
    }

    //Need to choose a chapter, which will trigger selection
    //of a section and exercise. This will create and populate
    //the chapter, section, and exercise list boxes.
    selectChapter(mCurrentChapter);
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
    if( "ChangeText" == name ){ return new ChangeText(); }
    if( "ChangeX" == name ){ return new ChangeX(); }
    if( "ChangeY" == name ){ return new ChangeY(); }
    if( "ChangeXY" == name ){ return new ChangeXY(); }
    if( "ChangeColor" == name ){ return new ChangeColor(); }
    if( "ChangeFont" == name ){ return new ChangeFont(); }
    if( "DrawLines" == name ){ return new DrawLines(); }
    if( "DrawCircles" == name ){ return new DrawCircles(); }
    if( "DrawRectangles" == name ){ return new DrawRectangles(); }
    if( "DrawDots" == name ){ return new DrawDots(); }
    if( "DrawEllipses" == name ){ return new DrawEllipses(); }
    if( "DrawingText" == name ){ return new DrawingText(); }
    if( "DrawingImages" == name ){ return new DrawingImages(); }
    if( "seeoutIntro" == name ){ return new seeoutIntro(); }
    if( "seeoutFormatting" == name ){ return new seeoutFormatting(); }
    if( "OnYourOwn" == name ){ return new OnYourOwn(); }
    if( "ColorNames" == name ){ return new ColorNames(); }
    if( "FontProportions" == name ){ return new FontProportions(); }

    //Section 3 - Types_Variables
    if( "NumericTypes" == name ){ return new NumericTypes(); }
    if( "DrawingVersusSeeout" == name ){ return new DrawingVersusSeeout(); }
    if( "CONSTANTS" == name ){ return new CONSTANTS(); }
    if( "Chars" == name ){ return new Chars(); }
    if( "Booleans" == name ){ return new Booleans(); }
    if( "StandardStrings" == name ){ return new StandardStrings(); }
//    if( "Arrays" == name ){ return new Arrays(); }

    //Section 4 - Expessions_Syntax
    if( "AssignmentArithmetic" == name ){ return new AssignmentArithmetic(); }
    if( "OrderOfOperations" == name ){ return new OrderOfOperations(); }
    if( "PreAndPostIncAndDec" == name ){ return new PreAndPostIncAndDec(); }
    if( "ModulusOperator" == name ){ return new ModulusOperator(); }
    if( "BlocksAndScope" == name ){ return new BlocksAndScope(); }
    if( "MathFunctions" == name ){ return new MathFunctions(); }
    if( "randomAndrandomRange" == name ){ return new randomAndrandomRange(); }
    if( "DistanceEquation" == name ){ return new DistanceEquation(); }
    if( "Misdirection" == name ){ return new Misdirection(); }

    //Section 5 - Loops_Logic
    if( "WhileLoopIntro" == name ){ return new WhileLoopIntro(); }
    if( "ForLoopIntro" == name ){ return new ForLoopIntro(); }
    if( "WhileLoop1" == name ){ return new WhileLoop1(); }
    if( "InfiniteLooping1" == name ){ return new InfiniteLooping1(); }
    if( "OYO1" == name ){ return new C01S05_OYO1(); }
    if( "OYO2" == name ){ return new C01S05_OYO2(); }
    if( "WhileLoop2" == name ){ return new WhileLoop2(); }
    if( "WhileLoop3" == name ){ return new WhileLoop3(); }
    if( "OYO3" == name ){ return new C01S05_OYO3(); }
    if( "OYO4" == name ){ return new C01S05_OYO4(); }
    if( "WhileLoop4" == name ){ return new WhileLoop4(); }
    if( "WhileLoop5" == name ){ return new WhileLoop5(); }
    if( "ForLoops1" == name ){ return new ForLoops1(); }
    if( "ForLoops2" == name ){ return new ForLoops2(); }
    if( "ForLoops3" == name ){ return new ForLoops3(); }
    if( "IfThen1" == name ){ return new IfThen1(); }
    if( "IfThen2" == name ){ return new IfThen2(); }
    if( "IfThen3" == name ){ return new IfThen3(); }
    if( "IfThen4" == name ){ return new IfThen4(); }
    if( "Switch1" == name ){ return new Switch1(); }
    if( "DivideByZero" == name ){ return new DivideByZero(); }
    if( "Primes1" == name ){ return new Primes1(); }
    if( "OYO_Primes2" == name ){ return new OYO_Primes2(); }
    if( "OYO5" == name ){ return new C01S05_OYO5(); }

    //Section 6 - Arrays
    if( "Arrays1" == name ){ return new Arrays1(); }

    //Section 7 - ...

    //Section 8 - ...

    //Section 9 - ...

    //Section 10 - Classes Intro
    if( "Classes1" == name ){ return new Classes1(); }

    //Section 11 - Event Handling With Qt
    if( "TheEventLoop" == name ){ return new TheEventLoop(); }


    //Chapter 8 - Game_Programming

    //Section 3 - TopDown2D
    if( "TopDown2D" == name ){ return new TopDown2D(); }

    // MyCode "Chapter" (only one section)

    if( "MyCode0" == name ){ return new MyCode0(); }
    if( "MyCode1" == name ){ return new MyCode1(); }
    if( "MyCode2" == name ){ return new MyCode2(); }
    if( "MyCode3" == name ){ return new MyCode3(); }
    if( "MyCode4" == name ){ return new MyCode4(); }
    if( "MyCode5" == name ){ return new MyCode5(); }
    if( "MyCode6" == name ){ return new MyCode6(); }
    if( "MyCode7" == name ){ return new MyCode7(); }
    if( "MyCode8" == name ){ return new MyCode8(); }
    if( "MyCode9" == name ){ return new MyCode9(); }

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
    exercises.push_back( "ChangeFont" );
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
    exercises.push_back( "Arrays" );
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

    //S06-Arrays
    exercises.clear();
    exercises.push_back( "Arrays1" );
    sections["S06-Arrays"] = exercises;

    //S10-Classes_Intro
    exercises.clear();
    exercises.push_back( "Classes1" );
    sections["S10-Classes_Intro"] = exercises;

    //S11-Event_Handling_With_Qt
    exercises.clear();
    exercises.push_back( "TheEventLoop" );
    sections["S11-Event_Handling_With_Qt"] = exercises;

    mExerciseMap["C01-Beginner_Exercises"] = sections;


    //C08-Game_Programming
    sections.clear();

    //S03-TopDown2D
    exercises.clear();
    exercises.push_back( "TopDown2D" );
    sections["S03-TopDown2D"] = exercises;

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

    //Give the exercise chooser focus so user can use
    //arrow keys to run through the list. (This is for
    //when exercise is selected programatically, as it
    //is here, rather than user selecting via the widget.)
    //mExerciseChooser->setFocus();
}

void FWCExerciseChooser::selectExercise( const QString & selection )
{
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].find(mCurrentSection) ==
         mExerciseMap[mCurrentChapter].end() ||
         mExerciseMap[mCurrentChapter][mCurrentSection].empty() )
    {
        return;
    }

    QString selectedExercise("");

    if ( selection.isEmpty() )
    {
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
        return; // nope, so don't do anything

    // Start the new exercise
    // This stops the old one if it's still running.
    mCurrentExercise = selectedExercise;
    runCurrentExercise();
}

void FWCExerciseChooser::chapterSelected( const QString & selection )
{
    qDebug() << "chapterSelected(): " << selection << "\n";
    selectChapter(selection);
}

void FWCExerciseChooser::sectionSelected( const QString & selection )
{
    qDebug() << "sectionSelected(): " << selection << "\n";
    selectSection(selection);
}

void FWCExerciseChooser::exerciseSelected( const QString & selection )
{
    qDebug() << "exerciseSelected(): " << selection << "\n";
    selectExercise(selection);
}

void FWCExerciseChooser::stopExercise()
{
    qDebug() << "FWCExerciseChooser::stopExercise()\n";

    //Stop the exercise *before* deleting below
    //since the exercise launcher still needs
    //access to the pointer to stop it.
    mExerciseLauncher.stopCurrentExercise();

    ClearScreen();
    initOutputArea();

    if ( mSelectedExercise )
    {
        qDebug() << "Deleting current exercise...\n";
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

    //FWCExerciseChooser retains ownership of the mSelectedExercise
    //pointer. ExerciseLauncher should not delete this passed in pointer!
    mExerciseLauncher.launchExercise(mSelectedExercise);
}

void FWCExerciseChooser::runCurrentExercise()
{
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
        qDebug() << "Failed to open file \"lastexercise.txt\" for writing."
                 << " Cannot save current exercise.\n";
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
        return getSettingLoadPreviousExerciseEnabled("../FeetWetCoding/defaultconfig.txt");
    }
    catch ( bool val ) { qDebug() << "Failed to get prevEx setting from default config.\n"; }

    return false;
}

void FWCExerciseChooser::handleKeyEvent(QKeyEvent *event)
{
    mExerciseLauncher.setKeyEvent(event);
}
