// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef C08_S03_H
#define C08_S03_H

#include <exercises/FeetWetCodingExerciseBase.h>

// *****************************
// SpaceshipFlyerSoln solution Class
// *****************************
class SpaceshipFlyerSoln : public FeetWetCodingSolution
{
    Q_OBJECT
public:
    explicit SpaceshipFlyerSoln(QObject *parent=0);
    virtual ~SpaceshipFlyerSoln();

protected:
    void runExercise();
};

// **************************
// SpaceshipFlyer Exercise Class
// **************************
class SpaceshipFlyer : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit SpaceshipFlyer(QObject *parent = 0);
    virtual ~SpaceshipFlyer();

protected:
    void runExercise();
    void setupSolution(QObject *parent=0);

private:
    void movePlayer(int x, int y);
    void rotatePlayer(int angleInDegrees);
    void drawPlayer();
    void drawCoins();
    void handleKeyboardInput(std::string key);

    int mPlayerIconID;
    int mPlayerX;
    int mPlayerY;
    int mPlayerAngle;
    bool mQuit;

};

#endif // C08_S03_H
