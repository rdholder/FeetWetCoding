// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C08_S03.h>

//extern FWCView *view;

SpaceshipFlyer::SpaceshipFlyer(QObject *parent)
    :FeetWetCodingExercise(parent)
    ,mPlayerIconID(-1)
    ,mPlayerX(0)
    ,mPlayerY(0)
    ,mPlayerAngle(0)
    ,mQuit(false)
{
    this->setupSolution(parent);
    //view->setFocus();
}

SpaceshipFlyer::~SpaceshipFlyer()
{
}

void SpaceshipFlyer::setupSolution(QObject *parent)
{
    mSolutionPtr = new SpaceshipFlyerSoln(parent);
    if ( mSolutionPtr )
    {
        mSolutionPtr->start();
    }
}

void SpaceshipFlyer::runExercise()
{
    seeout << "Use 'wasd' keys to move ship.\n";
    seeout << "MOVE SHIP MOVE SHIP MOVE SHIP MOVE SHIP\n";
    seeout << "YOU KNOW WHAT YOU DOING TAKE OFF EVERY ZIG\n";

    drawPlayer();
    drawCoins();

    std::string key;
    int sleepTimeInMiliseconds(10);

    while ( !mQuit )
    {
        key = waitForKeyPress();
        handleKeyboardInput(key);
        msleep(sleepTimeInMiliseconds);
    }
}

void SpaceshipFlyer::drawPlayer()
{
    //Draw the player if he hasn't been drawn yet
    if ( mPlayerIconID < 0 )
    {
        //Center our player to start
        mPlayerX = (WINDOW_WIDTH/2-BORDER)/2;
        mPlayerY = (WINDOW_HEIGHT-BORDER)/2;

        std::string playerImageFilename("spaceship25x30.png");
        mPlayerIconID = fwcImage(playerImageFilename, mPlayerX, mPlayerY);
        fwcChangeZ(mPlayerIconID, 1000);
        rotatePlayer(mPlayerAngle);

    }
}

void SpaceshipFlyer::drawCoins()
{
    const unsigned short NUM_COINS = 10;
    const unsigned short radius(5);
    unsigned short x, y;

    for ( int i=0; i < NUM_COINS; ++i )
    {
        x = random(WINDOW_WIDTH/2-BORDER);
        y = random(WINDOW_HEIGHT-BORDER);

        fwcCircle(x-(radius/2), y-(radius/2), radius, DARKYELLOW, 1, true);
    }
}

void SpaceshipFlyer::movePlayer( int x, int y )
{
    mPlayerX = x;
    mPlayerY = y;

    if ( mPlayerX < 0 )
        mPlayerX = WINDOW_WIDTH/2;

    if ( mPlayerX > WINDOW_WIDTH/2 )
        mPlayerX = 0;

    if ( mPlayerY < 0 )
        mPlayerY = WINDOW_HEIGHT;

    if ( mPlayerY > WINDOW_HEIGHT )
        mPlayerY = 0;

    fwcMoveItem(mPlayerIconID, mPlayerX, mPlayerY);
}

void SpaceshipFlyer::rotatePlayer( int angleInDegrees )
{
    fwcRotateItem(mPlayerIconID, angleInDegrees);
}

void SpaceshipFlyer::handleKeyboardInput(std::string key)
{
    const unsigned short INCR(5);
    const unsigned short ANGLE_INCR(5);

    if ( "w" == key || "W" == key )
    {
        mPlayerY -= INCR;

        if ( mPlayerAngle > 0 )
            mPlayerAngle -= ANGLE_INCR;
        else if ( mPlayerAngle < 0 )
            mPlayerAngle += ANGLE_INCR;
    }
    else if ( "s" == key || "S" == key )
    {
        mPlayerY += INCR;

        if ( mPlayerAngle > 180)
            mPlayerAngle -= ANGLE_INCR;
        else if ( mPlayerAngle < 180 )
            mPlayerAngle += ANGLE_INCR;
    }
    else if ( "a" == key || "A" == key )
    {
        mPlayerX -= INCR;

        if ( mPlayerAngle > 270)
            mPlayerAngle -= ANGLE_INCR;
        else if ( mPlayerAngle < 270 )
            mPlayerAngle += ANGLE_INCR;
    }
    else if ( "d" == key || "D" == key )
    {
        mPlayerX += INCR;

        if ( mPlayerAngle > 90)
            mPlayerAngle -= ANGLE_INCR;
        else if ( mPlayerAngle < 90 )
            mPlayerAngle += ANGLE_INCR;
    }
    else if ( "q" == key || "Q" == key )
    {
        mQuit = true;
    }

    movePlayer(mPlayerX, mPlayerY);
    rotatePlayer(mPlayerAngle);
}
