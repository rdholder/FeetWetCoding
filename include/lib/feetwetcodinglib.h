// FeetWetCoding/include/feetwetcodinglib.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef FEETWETCODINGLIB_H
#define FEETWETCODINGLIB_H

#include <include/lib/colors.h>
#include <QGraphicsView>
#include <QKeyEvent>


//////////////////////////////////////////////
//  FWC convenience functions for the user
//////////////////////////////////////////////

int random(int biggest);
int randomRange(int smallest, int biggest);
QColor getQColor( Color color );
std::string getNameForColor( Color color );



//////////////////////////////////////////////
//  FWC Internals
//////////////////////////////////////////////

//FWC setup and initialization
void appSetup();
void setupDrawingUtils();
void initOutputArea();

//FWC file I/O and configuration settings

//The "sandbox" is the safe area for writing files. It's a sub-directory of the main
//project directory and it's the only place that fwc files can be written to from code.
QString getProjectSandboxPath();   //Throws std::runtime_error if dir path cannot be determined

QString getProjectDirPath();       //Throws std::runtime_error if dir path cannot be determined
QString getBuildDirPath();         //Throws std::runtime_error if dir path cannot be determined
QString getDefaultConfigDirPath(); //Throws std::runtime_error if dir path cannot be determined
QString getUserConfigDirPath();    //Throws std::runtime_error if dir path cannot be determined
QString getDefaultConfigFilePath();
QString getUserConfigFilePath();
QString getCurrentConfigFilePath();
QString getLastExerciseFilePath();
void initSettingsFile();
void getSetting( const QString & settingKey, QString & settingVal );
void getPreviousExerciseFromFile( QString pathToFile, QString & chapter, QString & section, QString & exercise );
void saveCurrentExerciseToFile( QString pathToFile, QString chapter, QString section, QString exercise );

//FWC drawing utils
QGraphicsItem* fwcLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth );
QGraphicsItem* fwcCircleRender( int x, int y, int r, Color color, int linewidth, bool solid=false);
QGraphicsItem* fwcCircleRGBRender( int x, int y, int r, int linewidth, int red, int green, int blue, bool solid=false );
QGraphicsItem* fwcEllipseRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcRectangleRender( int x, int y, int w, int h, Color color, int linewidth, bool solid=false );
QGraphicsItem* fwcTextRender( std::string text, int x, int y, Color color, int size=12);
QGraphicsItem* fwcIntRender( int number, int x, int y, Color color, int size=12 );
QGraphicsItem* fwcFloatRender( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
QGraphicsItem* fwcImageRender( std::string filename, int x, int y );
void ClearScreen();

//FWCView class provides access to the scene and handles keyboard and mouse events
class FWCView : public QGraphicsView
{
    Q_OBJECT
public:

    explicit FWCView(QWidget *parent=0) : QGraphicsView(parent){}
    explicit FWCView(QGraphicsScene *scene, QWidget *parent=0):QGraphicsView(scene, parent){}
    ~FWCView(){}

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

signals:
    void keyPressSignal(QKeyEvent *);
    void newMousePos(QPoint);
    void sceneCleared();

protected:


private:

};

#endif // FEETWETCODINGLIB_H
