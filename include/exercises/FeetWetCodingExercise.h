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
    } RenderItem;

    typedef enum
    {
        MOVE,
        SHIFT,
        ERASE,
        CHANGE_Z,
        SCALE,
        ROTATE,
        CHANGE_XEND_YEND,
        CHANGE_WIDTH_AND_HEIGHT,
        CHANGE_RADIUS,
        CHANGE_COLOR,
        CHANGE_LINE_WIDTH,
        CHANGE_FONT_SIZE,
        CHANGE_TEXT_VAL,
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
        int z;
        float scalefactor;
        float angledegrees;
        int xEnd;
        int yEnd;
        int width;
        int height;
        int radius;
        Color color;
        bool solid;
        int linewidth;
        int fontsize;
        std::string textval;
        int intval;
        float floatval;
    } RenderItemUpdate;

    bool solutionIsFinished();

protected:

    virtual void runExercise();
    virtual void setupSolution(QObject *parent=0){} //=0;
    std::string waitForKeyPress();
    std::string getKeyboardString();

    bool mSoln;
    int mPane;
    SeeOut seeout;
    FeetWetCodingExercise *mSolutionPtr;

    //Shift a drawn item's x/y location by xShift/yShift.
    void fwcMoveItem(int itemID, int newX, int newY);
    void fwcShiftItem(int itemID, int xShift, int yShift);
    void fwcEraseItem(int itemID);
    void fwcChangeZ(int itemID, int z);
    void fwcScaleItem(int itemID, float scalefactor);
    void fwcRotateItem(int itemID, float angledegrees);
    void fwcChangeLineEnd(int itemID, int xEnd, int yEnd);
    void fwcChangeWidthAndHeight(int itemID, int w, int h);
    void fwcChangeRadius(int itemID, int radius);
    void fwcChangeColor(int itemID, Color color, bool solid=false);
    void fwcChangeLineWidth(int itemID, int width);
    void fwcChangeFontSize(int itemID, int size);
    void fwcChangeText(int itemID, std::string text);
    void fwcChangeInt(int itemID, int intval);
    void fwcChangeFloat(int itemID, int floatval);
    void fwcClearItems();

    //Return ID of the item to be drawn. This ID can be used later
    //to operate on the corresponding QGraphicsItem.
    //Returns -1 if item could not be queued for drawing.
    int fwcDrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness );
    int fwcDrawCircle( int x, int y, int r, Color color, int thickness, bool solid=false);
    int fwcDrawCircleRGB( int x, int y, int r, int thickness, int red, int green, int blue, bool solid=false );
    int fwcDrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
    int fwcDrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid=false );
    int fwcDrawText( std::string text, int x, int y, Color color, int size=12);
    int fwcDrawInt( int number, int x, int y, Color color, int size=12 );
    int fwcDrawFloat( float number, int x, int y, Color color, int size=12, int decimalPlaces=3 );
    int fwcDrawImage( std::string filename, int x, int y );
    int SendRenderRequest( RenderItem item );
    void DrawReferenceBox( RefBoxLayout layout=LEFTRIGHT );

    std::vector<int> mDrawnItems;
    std::vector<int> mRefBoxItems;
    QMutex solutionmutex;
    ExerciseLauncher *mParent;

private:
    void run();
};

#endif // FEETWETCODINGEXERCISE_H
