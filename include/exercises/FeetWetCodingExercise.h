// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef FEETWETCODINGEXERCISE_H
#define FEETWETCODINGEXERCISE_H

#include <include/lib/feetwetcodinglib.h>
#include <SeeOut.h>
#include <QThread>
#include <QKeySequence>
#include <QColor>

class ExerciseLauncher;

//class SolutionOrientation
//{
//public:

//    SolutionOrientation(FeetWetCodingExercise::RefBoxLayout initialOrientation);
//    ~SolutionOrientation();
//    RefBoxLayout getOrientation();
//    void setOrientation(FeetWetCodingExercise::RefBoxLayout);

//private:
//    RefBoxLayout itsOrientation;

//};

class FeetWetCodingExercise : public QThread
{
    Q_OBJECT
public:
    explicit FeetWetCodingExercise(QObject *parent = 0);
    virtual ~FeetWetCodingExercise();

    typedef enum {
        BLANK,
        LEFTRIGHT,
        TOPBOTTOM
    } RefBoxLayout;

    typedef enum
    {
        LINE,
        CIRCLE,
        CIRCLERGB,
        ELLIPSE,
        RECTANGLE,
        TEXT,
        INT,
        FLOAT,
        IMAGE
    } RenderItemType;

    //Container for render parameters
    //Some parameters are not needed for
    //some types (e.g. radius not needed
    //for text render type). Only the
    //needed parameters for the given
    //type need setting/getting.
    typedef struct
    {
        RenderItemType type;
        int ID;  //handle to the QGraphicsItem that will be added to the scene
                 //in case we want to operate on the rendered item later.
        std::string text;
        int x;
        int y;
        int xEnd;
        int yEnd;
        int width;
        int height;
        int radius;
        Color color;
        int linewidth;
        int fontsize;
        bool solid;
        int RGBred;
        int RGBgreen;
        int RGBblue;
        std::string imagefile;
        int intvalue;
        float floatvalue;
        int decimalplaces;
//        RefBoxLayout refboxlayout;
    } RenderItem;

    typedef enum
    {
        MOVE,
        DELETE,
        CHANGE_X_Y,
        CHANGE_XEND_YEND,
        CHANGE_WIDTH_AND_HEIGHT,
        CHANGE_RADIUS,
        CHANGE_COLOR,
        CHANGE_LINE_WIDTH,
        CHANGE_FONT_SIZE,
        CHANGE_INT_VAL,
        CHANGE_FLOAT_VAL
    } RenderItemUpdateType;

    typedef struct
    {
        RenderItemUpdateType type;
        int ID;
        int dx;
        int dy;
        int x;
        int y;
        int xEnd;
        int yEnd;
        int width;
        int height;
        int radius;
        Color color;
        int linewidth;
        int fontsize;
        int intval;
        float floatval;
    } RenderItemUpdate;

protected:

    static int renderedItemsCount;
    virtual void runExercise();
    virtual void setupSolution(QObject *parent=0){} //=0;
    std::string waitForKeyPress();
    std::string getKeyboardString();


//    SolutionOrientation mDrawingAreaLayout;
    bool mSoln;
    SeeOut seeout;
    FeetWetCodingExercise *mSolutionPtr;

    //Shift a drawn item's x/y location by xShift/yShift.
    void ShiftDrawnItem(int itemID, int xShift, int yShift);

    //Return ID of the item to be drawn. This ID can be used later
    //to operate on the corresponding QGraphicsItem.
    //Returns -1 if item could not be queued for drawing.
    int DrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness );
    int DrawCircle( int x, int y, int r, Color color, int thickness, bool solid=false);
    int DrawCircleRGB( int x, int y, int r, int thickness, int red, int green, int blue, bool solid=false );
    int DrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
    int DrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
    int DrawText( std::string text, int x, int y, Color color, int size=12);
    int DrawInt( int number, int x, int y, Color color, int size=12 );
    int DrawFloat( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
    int DrawImage( std::string filename, int x, int y );
    bool SendRenderRequest( RenderItem item );

    void DrawReferenceBox( RefBoxLayout layout=LEFTRIGHT );

    ExerciseLauncher *mParent;

private:
    void run();
};

#endif // FEETWETCODINGEXERCISE_H
