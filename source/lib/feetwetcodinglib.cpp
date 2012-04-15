// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QDialog>
#include <QFontMetrics>
#include <QFile>
#include <QDir>
#include <stdexcept>
#include <feetwetcodinglib.h>
#include <include/lib/FWCExerciseChooser.h>

using namespace std;

//Global variables needed in other files
FWCView *view(NULL);
QDialog *theWindow(NULL);
FWCExerciseChooser *exerciseChooser(NULL);
QTextEdit *exerciseOut(NULL);
QTextEdit *solnOut(NULL);


////////////////////////////////////////////
// FWC convenience functions for the user
////////////////////////////////////////////

QColor getQColor( Color color )
{
    switch (color) {
    case COLOR0:
        return Qt::gray;
    case COLOR1:
        return QColor(Qt::color1);
    case BLACK:
        return QColor(Qt::black);
    case WHITE:
        return QColor(Qt::white);
    case DARKGRAY:
        return QColor(Qt::darkGray);
    case GRAY:
        return QColor(Qt::gray);
    case LIGHTGRAY:
        return QColor(Qt::lightGray);
    case RED:
        return QColor(Qt::red);
    case GREEN:
        return QColor(Qt::green);
    case BLUE:
        return QColor(Qt::blue);
    case CYAN:
        return QColor(Qt::cyan);
    case MAGENTA:
        return QColor(Qt::magenta);
    case YELLOW:
        return QColor(Qt::yellow);
    case DARKRED:
        return QColor(Qt::darkRed);
    case DARKGREEN:
        return QColor(Qt::darkGreen);
    case DARKBLUE:
        return QColor(Qt::darkBlue);
    case DARKCYAN:
        return QColor(Qt::darkCyan);
    case DARKMAGENTA:
        return QColor(Qt::darkMagenta);
    case DARKYELLOW:
        return QColor(Qt::darkYellow);
    case TRANSPARENT:
        return QColor(Qt::transparent);
    case PINK:
        return QColor(255, 0, 255);             // decimal rgb
    case LAVENDER:
        return QColor("#aa88ff");               // hex rgb
    default:
        return Qt::black;
    };
}

std::string getNameForColor( Color color )
{
    switch (color) {
    case COLOR0:
        return "COLOR0";
    case COLOR1:
        return "COLOR1";
    case BLACK:
        return "BLACK";
    case WHITE:
        return "WHITE";
    case DARKGRAY:
        return "DARKGRAY";
    case GRAY:
        return "GRAY";
    case LIGHTGRAY:
        return "LIGHTGRAY";
    case RED:
        return "RED";
    case GREEN:
        return "GREEN";
    case BLUE:
        return "BLUE";
    case CYAN:
        return "CYAN";
    case MAGENTA:
        return "MAGENTA";
    case YELLOW:
        return "YELLOW";
    case DARKRED:
        return "DARKRED";
    case DARKGREEN:
        return "DARKGREEN";
    case DARKBLUE:
        return "DARKBLUE";
    case DARKCYAN:
        return "DARKCYAN";
    case DARKMAGENTA:
        return "DARKMAGENTA";
    case DARKYELLOW:
        return "DARKYELLOW";
    case TRANSPARENT:
        return "TRANSPARENT";
    case PINK:
        return "PINK";
    case LAVENDER:
        return "LAVENDER";
    default:
        return "ERROR";
    };
}

// random:  returns a random int between 0 and "biggest" inclusive
// for example random(100) returns an int between 0 and 100
int random(int biggest)
{
//    SeeOut seeout;
//    seeout << "rnd-ThreadID: " << qApp->thread()->currentThread() << "\n";

//    int ctime = QTime::currentTime().msec();
//    qsrand(ctime);

    if (biggest > 0)
    {
        //Seed the random number generator
        //qsrand(QTime::currentTime().msec());

        //Calculate a random number within the specified range
        return (qrand() % biggest + 1) -1;
    }
    else
    {
        return 0;
    }
}

// randomRange: return a number between smallest and biggest
// you can supply positive or negative ints, just make sure smallest < biggest
// for example calling it with 10,20 will give you a random int betwen 10 and 20
// supplying -30,20 will give a random int between -30 and 20
// if they need 0 through x they should use random(x);
// if they need -x through 0, they should use random(x) * -1;
int randomRange(int smallest, int biggest)
{
    if ( smallest < biggest && smallest != 0 && biggest != 0 )
    {
        return (qrand() % (biggest - (smallest + 1))) + smallest;
    }
    else
    {
        return 0;
    }
}

////////////////////////////////////////////
// FWC setup and initialization
////////////////////////////////////////////

void appSetup()
{
    initSettingsFile();
    setupDrawingUtils();
}

void setupDrawingUtils()
{
    //Seed the random number generator
    QTime time = QTime::currentTime();
    qsrand(time.msec()/4); // rdh5mar2012: why is this 4?  I forget, need to check

    // Setup the drawing area stuff
    QGraphicsScene *scene = new QGraphicsScene(-BORDER, -BORDER/2,
                                               WINDOW_WIDTH+BORDER*2,
                                               WINDOW_HEIGHT+BORDER);
    view = new FWCView(scene);
    view->setRenderHint(QPainter::TextAntialiasing);

    exerciseOut = new QTextEdit();
    exerciseOut->ensureCursorVisible();
    exerciseOut->setReadOnly(true);
    exerciseOut->setFocusPolicy(Qt::NoFocus);

    solnOut = new QTextEdit();
    solnOut->ensureCursorVisible();
    solnOut->setReadOnly(true);
    solnOut->setFocusPolicy(Qt::NoFocus);

    exerciseChooser = new FWCExerciseChooser();

    QHBoxLayout *hlayout1 = new QHBoxLayout();
    QPushButton *restartExercise = new QPushButton( QObject::tr( "Re-start Exercise") );
    restartExercise->setFocusPolicy(Qt::NoFocus);
    QObject::connect(restartExercise, SIGNAL(clicked()),
                     exerciseChooser, SLOT(runCurrentExercise()));
    QObject::connect(view, SIGNAL(keyPressSignal(QKeyEvent*)),
                     exerciseChooser, SLOT(handleKeyEvent(QKeyEvent*)));
    view->setMouseTracking(true);
    QObject::connect(view, SIGNAL(newMousePos(QPoint)),
                     exerciseChooser, SLOT(handleNewMousePosEvent(QPoint)));

    hlayout1->addStretch();
    hlayout1->addLayout(exerciseChooser->getChooserLayout());
    QFrame *f = new QFrame();
    f->setFrameStyle( QFrame::VLine | QFrame::Sunken );
    hlayout1->addWidget( f, 0 );
    hlayout1->addWidget(restartExercise);

    QHBoxLayout *hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(exerciseOut);
    hlayout2->addWidget(solnOut);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addLayout(hlayout1);
    vlayout->addWidget(view);
    vlayout->addLayout(hlayout2);

    // Create the run-time window
    theWindow = new QDialog();
    theWindow->setLayout(vlayout);
    theWindow->setGeometry(WINDOW_X, WINDOW_Y,
                           WINDOW_WIDTH+2.5*BORDER,
                           WINDOW_HEIGHT+2.5*BORDER+OUTTEXT_HEIGHT);
    theWindow->show();

    // Done creating drawing area, so ok to run.
    // Choose the first Exercise in the list
    exerciseChooser->setOkToRun(true);
    exerciseChooser->runCurrentExercise();
}

void initOutputArea()
{
    if ( NULL == exerciseOut || NULL == solnOut )
        return;

    exerciseOut->clear();
    solnOut->clear();

    SeeOut outboxes;
    outboxes.setIsSolution(false);
    outboxes.setColor(BLUE);
    outboxes.setFontSize(8);
    outboxes << "Exercise output\n\n";

    outboxes.setIsSolution(true);
    outboxes.setColor(BLUE);
    outboxes.setFontSize(8);
    outboxes << "Solution output\n\n";
}

////////////////////////////////////////////
// FWC file I/O and configuration settings
////////////////////////////////////////////

QString getProjectSandboxPath()
{
    QString sandboxDir;
    try
    {
        sandboxDir = getProjectDirPath() + "/sandbox";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( sandboxDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getProjectSandboxPath(), unable to find sandbox path");
        throw std::runtime_error(errorMsg);
    }

    return ( sandboxDir );
}

QString getProjectDirPath()
{
    //Only figure this out once per run
    static QString projectPath;

    if ( false == projectPath.isEmpty() )
    {
        return projectPath;
    }

    //The name of the project directory (where the source code lives)
    //can be found in the "Makefile", which is in the main build directory,
    //so we need to get that directory first.
    QString buildDirPath;
    try
    {
        buildDirPath = getBuildDirPath();
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to determine build directory path");
        throw std::runtime_error(errorMsg);
    }

    //Find the Makefile in the build directory
    const QString makefilename(buildDirPath + "/Makefile");
    QFile makefile(makefilename);
    if ( false == makefile.exists() )
    {
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to find file " + makefilename.toStdString());
        throw std::runtime_error(errorMsg);
    }
    if ( false == makefile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to open file " + makefilename.toStdString() + " for reading");
        throw std::runtime_error(errorMsg);
    }

    //The main project directory contains the FeetWetCoding project file "FeetWetCoding.pro"
    //The Makefile contains the path to this file, so we need to parse the Makefile to get
    //that path.
    QString projectFilename("FeetWetCoding.pro");
    QString tempProjectPath;
    QTextStream in(&makefile);
    QString line;
    int index(0);
    QStringList parsedLine;

    //Read line by line until we reach the end of the file
    while (!in.atEnd())
    {
        line = in.readLine();
        index = line.indexOf(projectFilename);
        if ( -1 == index)
        {
            continue;
        }

        //Found a line with the filename in it. Split the line up
        //into space-delimited sections and find the section that
        //contains the filename
        parsedLine = line.split(" ", QString::SkipEmptyParts, Qt::CaseSensitive);

        for( int i=0; i < parsedLine.length(); i++)
        {
            if ( -1 == parsedLine.at(i).indexOf(projectFilename) )
            {
                continue;
            }

            //Found the section of this line that contains the filename. We know that
            //in the Makefile there's at least one instance of the project file path
            //that exists with no preceding or trailing characters. See if this instance
            //qualifies.
            if ( QFile(parsedLine.at(i)).exists() )
            {
                //This string contains the path to the file, but we need to remove the
                //project filename and the "/" that immediately precedes it to get
                //just the directory that contains the file. This is the project path.
                tempProjectPath = parsedLine.at(i);
                if ( -1 != tempProjectPath.indexOf(projectFilename) )
                {
                    // +1 for the "/"
                    tempProjectPath.chop(tempProjectPath.length()-tempProjectPath.indexOf(projectFilename)+1);
                }

#ifdef DEBUG
                qDebug() << "Initial projectPath: " << tempProjectPath;
#endif
                //If project path is a relative path in the same parent directory as current working
                //(this is the default) then replace the leading "../" with the parent directory to
                //get the absolute path.
                QString projectParentDir(tempProjectPath);
                QString buildParentDir(buildDirPath);
                int index(projectParentDir.lastIndexOf("/"));
                projectParentDir.chop(projectParentDir.length() - index);
                if ( ".." == projectParentDir )
                {
#ifdef DEBUG
                    qDebug() << "Replacing relative path with absolute path...";
#endif

                    buildParentDir.chop(buildParentDir.length()-buildParentDir.lastIndexOf("/"));
                    tempProjectPath.replace(0, 2, buildParentDir);
                }

                //Assign what we came up with to our projectPath, print out
                //some debugging info, then break out of the for loop.
                projectPath = tempProjectPath;

#ifdef DEBUG
                qDebug() << "-------------------------------------";
                qDebug() << "projectParentDir:     " << projectParentDir;
                qDebug() << "buildParentDir:       " << buildParentDir;
                qDebug() << "Absolute projectPath: " << projectPath;
                qDebug() << "-------------------------------------";
#endif
                break;
            }
        }

        //Break out of the while loop if we found the path
        if ( false == projectPath.isEmpty() )
        {
            break;
        }
    }

    makefile.close();

    //See if we have something to return. If not, throw.
    if ( projectPath.isEmpty() )
    {
        std::string errorMsg("ERROR: In getProjectDirPath(), unable to find project path");
        throw std::runtime_error(errorMsg);
    }

    return projectPath;
}

QString getBuildDirPath()
{
    //Only figure this out once per run
    static QString buildDirPath;

    if ( false == buildDirPath.isEmpty() )
    {
        return buildDirPath;
    }

    //The main build directory's name starts with "FeetWetCoding-build" but
    //the rest of the name varies depending on the build configuration, plus,
    //we don't know where in the system it is. Fortunately, the running program's
    //current working directory, which we can query for, is somewhere in that
    //main build directory, either at its top level or in some sub-directory.
    //We just need to find where the string "FeetWetCoding-build" occurs in
    //the current working directory string and then find the next "/" that
    //occurs after that. This will mark the end of the main build directory
    //path, and if anything else follows that "/" then it's sub-directories
    //that we can discard from the string.

    //Get the current working directory and check that it's valid.
    const QString cwd = QDir::currentPath();
    if ( false == QDir(cwd).isReadable() )
    {
        std::string errorMsg("ERROR: In getBuildDirPath(), QDir::currentPath() invalid");
        throw std::runtime_error(errorMsg);
    }

    //Assume main build dir is the same until we learn otherwise.
    buildDirPath = cwd;

    //To find the first "/" after the start of the build directory name, first
    //find the location of the partial main build directory name.
    const QString buildDirPartialName("FeetWetCoding-build");
    const int buildDirStartIndex(cwd.indexOf(buildDirPartialName));

    //Next, starting from that index, find the next "/" character in the path.
    const int buildDirEndIndex(cwd.indexOf("/", buildDirStartIndex));

    //If we didn't find a "/" following the build dir name then that
    //means our current working directory *is* the main build dir and
    //we're done looking for the main build dir. Else if we did find
    //it that means the current working directory is a subdirectory of
    //the main build directory. We only want the main build directory,
    //so remove the any build dir subdirectories from the path.
    if ( -1 != buildDirEndIndex )
    {
        //If index is valid (i.e. not -1), then we found sub-dirs
        //and need to remove them
        buildDirPath.chop(buildDirPath.length()-buildDirEndIndex);
    }

    //Print out some debugging and we're done
#ifdef DEBUG
    qDebug() << "-------------------------------------";
    qDebug() << "cwd:                        " << cwd;
    qDebug() << "buildDirPartialName:        " << buildDirPartialName;
    qDebug() << "Idx of buildDirPartialName: " << buildDirStartIndex;
    qDebug() << "Idx of following / :        " << buildDirEndIndex;
    qDebug() << "buildDirPath:               " << buildDirPath;
    qDebug() << "-------------------------------------";
#endif

    return buildDirPath;
}

QString getImgDirPath()
{
    QString imgDir;
    try
    {
        imgDir = getProjectSandboxPath() + "/img";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( imgDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getImgDirPath(), unable to find img path");
        throw std::runtime_error(errorMsg);
    }

    return ( imgDir );
}

QString getUserConfigDirPath()
{
    QString configDir;
    try
    {
        configDir = getProjectSandboxPath() + "/config_user";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( configDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getUserConfigDirPath(), unable to find user config path");
        throw std::runtime_error(errorMsg);
    }

    return ( configDir );
}

QString getDefaultConfigDirPath()
{
    QString configDir;
    try
    {
        configDir = getProjectSandboxPath() + "/config_default";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    //See if we have something to return. If not, throw.
    if ( configDir.isEmpty() )
    {
        std::string errorMsg("ERROR: In getDefaultConfigDirPath(), unable to find default config path");
        throw std::runtime_error(errorMsg);
    }

    return ( configDir );
}

QString getUserConfigFilePath()
{
    QString configFilePath;
    try
    {
        configFilePath = getUserConfigDirPath() + "/userconfig.txt";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    return ( configFilePath );
}

QString getDefaultConfigFilePath()
{
    QString configFilePath;
    try
    {
        configFilePath = getDefaultConfigDirPath() + "/defaultconfig.txt";
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
    }

    return ( configFilePath );
}

QString getCurrentConfigFilePath()
{
    //Try user config first
    QString configFilePath;

    if (QFile(getUserConfigFilePath()).exists())
    {
        configFilePath = getUserConfigFilePath();
    }
    else if (QFile(getDefaultConfigFilePath()).exists())
    {
        configFilePath = getDefaultConfigFilePath();
    }

    return configFilePath;
}

void initSettingsFile()
{
    //If there's already a user config file then we're done.
    QString userConfigFile(getUserConfigFilePath());

    if ( QFile(userConfigFile).exists() )
    {
        return;
    }

    try
    {
        //Copy the default config file to the user config dir.
        //If the user config directory doesn't exist create it.
        //It lives in the project's build directory (see getUserConfigDirPath())
        //so it's ok for us to write there. getUserConfigDirPath() throws if dir
        //can't be found
        QDir dir(getUserConfigDirPath());
        if ( !dir.exists() && !dir.mkdir(getUserConfigDirPath()) )
        {
             //program can still proceed, so no need to throw
             //but can't continue to init, so return
             return;
        }

        QFile srcFile(getDefaultConfigFilePath());
        qDebug() << "getDefaultConfigFilePath: " << getDefaultConfigFilePath();
        if ( srcFile.exists() )
        {
            qDebug() << "Copying default config file to user config file...";
            srcFile.copy(getUserConfigFilePath());
        }
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();

        //program can still proceed, so no need to throw
    }
}

void getSetting( const QString & settingKey, QString & settingVal )
{
    QString configFilePath(getCurrentConfigFilePath());

    QFile configFile(configFilePath);
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "WARNING: In getSetting(), unable to open file " << configFilePath << " for reading";
        return;
    }

    QTextStream in(&configFile);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList list = line.split(":", QString::SkipEmptyParts);
        if ( 2 != list.count() )
            continue;

        if ( list.at(0).contains(settingKey, Qt::CaseInsensitive) )
        {
            settingVal = list.at(1);
        }
    }

    configFile.close();
}

void getPreviousExerciseFromFile( QString pathToFile, QString & chapter, QString & section, QString & exercise )
{
    QFile file(pathToFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
#ifdef DEBUG
        qDebug() << "INFO: File \"" << pathToFile << "\" not found.\n";
#endif
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
            chapter = ( list.at(1) );
        }
        else if ( list.at(0).contains("section", Qt::CaseInsensitive) )
        {
            section = ( list.at(1) );
        }
        else if ( list.at(0).contains("exercise", Qt::CaseInsensitive) )
        {
            exercise = ( list.at(1) );
        }
    }

    file.close();
}

void saveCurrentExerciseToFile( QString pathToFile, QString chapter, QString section, QString exercise )
{
    QFile file(pathToFile);
    if ( file.exists() )
    {
        file.remove();
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "WARNING: Unable to write to file \"" << pathToFile << "\". Cannot save which exercise was viewed last.\n";
        return;
    }

    QTextStream out(&file);
    out << "chapter:" << chapter << "\n";
    out << "section:" << section << "\n";
    out << "exercise:" << exercise << "\n";

    file.close();
}

/////////////////////////////////
//FWC drawing utils
/////////////////////////////////

void ClearScreen()
{
    if ( view && view->scene() )
    {
        view->scene()->clear();
    }
    if ( exerciseChooser )
    {
        exerciseChooser->sceneCleared();
    }
}

QGraphicsItem* fwcLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth )
{
    QGraphicsLineItem *newLine = new QGraphicsLineItem(xStart, yStart, xEnd, yEnd);

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);
    newLine->setPen(pen);
    view->scene()->addItem(newLine);

    return newLine;
}

QGraphicsItem* fwcCircleRender( int x, int y, int r, Color color, int linewidth, bool solid)
{
    //Usage: QGraphicsEllipseItem(x, y, width, height). Positions its top left corner at x, y.
    //Therefore, to make a circle with radius r and position its center at x,y, we need to
    //shift x,y by -radius and multiply r by 2 before passing them on to the QGraphicsEllipseItem
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, r*2, r*2);
    newCircle->setPos(x-r, y-r);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create an ellipse and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcCircleRGBRender( int x, int y, int r, int red, int green, int blue, int linewidth, bool solid )
{
    //Usage: QGraphicsEllipseItem(x, y, width, height). Positions its top left corner at x, y.
    //Therefore, to make a circle with radius r and position its center at x,y, we need to
    //shift x,y by -radius and multiply r by 2 before passing them on to the QGraphicsEllipseItem
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, r*2, r*2);
    newCircle->setPos(x-r, y-r);

    QColor color;

    // Create a line and add it to the scene
    QPen pen;
    color.setRed(red);
    color.setGreen(green);
    color.setBlue(blue);
    pen.setColor(color);
    pen.setWidth(linewidth);

    if ( solid )
    {
        QBrush brush(color, Qt::SolidPattern);
        newCircle->setBrush(brush);
    }

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcEllipseRender( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    //Shift position so that origin goes from top left corner to center of ellipse
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, w, h);
    newCircle->setPos(x-(w/2), y-(h/2));

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcRectangleRender( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    QGraphicsRectItem *newRect = new QGraphicsRectItem(0, 0, w, h);
    newRect->setPos(x, y);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newRect->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);
    newRect->setPen(pen);
    view->scene()->addItem(newRect);

    return newRect;
}


QGraphicsItem* fwcTextRender( std::string text, int x, int y,  Color color, int size )
{
    QGraphicsTextItem *newText = new QGraphicsTextItem(text.c_str());

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(size);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcIntRender( int number, int x, int y, Color color, int fontSize )
{
    QString str;
    str.setNum(number);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcFloatRender( float number, int x, int y, Color color, int fontSize, int decimalPlaces )
{
    QString str;
    str.setNum(number, 'f', decimalPlaces);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcImageRender( std::string filename, int x, int y )
{
    QString imageFilePath;
    try
    {
        imageFilePath = getImgDirPath() + "/" + QString(filename.c_str());
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
        return NULL;
    }

    if ( false == QFile::exists(imageFilePath) )
    {
        SeeOut seeout;
        seeout << "ERROR: Can't find image file " << imageFilePath.toStdString() << "\n";
        return NULL;
    }

    QPixmap pixmap;
    if ( false == pixmap.load(imageFilePath) )
    {
        SeeOut seeout;
        seeout << "ERROR: Unable to create pixmap from image file " << imageFilePath.toStdString() << "\n";
        return NULL;
    }

    QGraphicsPixmapItem *newPixmap = new QGraphicsPixmapItem(pixmap);

    // Load an image from a file and add it to the scene
    newPixmap->setPos(x, y);
    view->scene()->addItem(newPixmap);

    return newPixmap;
}

////////////////////////////////////////////
//FWCView class
////////////////////////////////////////////

void FWCView::keyPressEvent( QKeyEvent *k )
{
    //Send signal to QObjects who wouldn't otherwise get it,
    //for example the exercise chooser, which will pass it into
    //the current exercise thread.
    emit keyPressSignal(k);
}

void FWCView::mouseMoveEvent(QMouseEvent *event)
{
    if ( !event )
        return;

    //Send signal to QObjects who wouldn't otherwise get it,
    //for example the exercise chooser, which will use the
    //mouse's current position to determine which exercise
    //pane should receive keyboard input.
    emit newMousePos(event->pos());
}
