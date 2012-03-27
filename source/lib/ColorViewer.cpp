// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <lib/feetwetcodinglib.h>
#include <exercises/FeetWetCodingExerciseBase.h>
#include <lib/ColorViewer.h>
#include <lib/colors.h>
#include <SeeOut.h>
#include <string>

void ColorViewer::show()
{
    int x(0);
    int y(0);
    int r(36);
    int fontSize(8);
    int colorIndex(0);
    double xshift(r/1.5);
    double yshiftorig(r/4);
    double yshift(yshiftorig);
    size_t position(std::string::npos);
    std::string darkStr = "DARK";
    std::string ightStr = "IGHT"; //works for "light" and "bright"
    std::string transStr = "TRANS";
    std::string colorStr, colorStrOrig;

    SeeOut seeout;
    seeout.setFontSize(8);

    for (int i=0; i < 5; ++i)
    {
        //Move to next location.
        y = i*2*r;

        // Shift from x,y at center to x,y at top left.
        y += r;

        //Space circles out by adding a few extra pixels.
        //(Start at i+1 to apply buffer even when i==0.)
        y += (i+1)*6;

        for (int j=0; j < 5; ++j)
        {
            //Move to next location.
            x = j*2*r;

            // Shift from x,y at center to x,y at top left.
            x += r;

            //Space circles out by adding a few extra pixels
            //(Start at j+1 to apply buffer even when j==0.)
            x += (j+1)*6;

            Color color = (Color)colorIndex;
            colorStrOrig = getNameForColor(color);
            colorStr = colorStrOrig;
            yshift = yshiftorig;

            position = colorStr.find(darkStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,darkStr.length(),"DARK\n");
                yshift = r/1.75;
            }

            position = colorStr.find(ightStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,ightStr.length(),"IGHT\n");
                yshift = r/1.75;
            }

            position = colorStr.find(transStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,transStr.length(),"TRANS\n");
                yshift = r/1.75;
            }

            fwcDrawCircle(x, y, r, color, 1, true);
            fwcDrawCircle(x, y, r, BLACK, 1);

            switch (color) {

            case WHITE:
            case TRANSPARENT:
                fwcDrawText(colorStr, x-xshift, y-yshift, BLACK, fontSize);
                seeout.setColor(BLACK);
                seeout << colorStrOrig << ":\t     "
                       << getQColor(color).name().toStdString() << "\n";
                break;

            case YELLOW:
            case CYAN:
            case GREEN:
                fwcDrawText(colorStr, x-xshift, y-yshift, BLACK, fontSize);
                seeout.setColor(color);
                seeout << colorStrOrig << ": \t     "
                       << getQColor(color).name().toStdString() << "\n";
                break;

            default:
                fwcDrawText(colorStr, x-xshift, y-yshift, WHITE, fontSize);
                seeout.setColor(color);
                seeout << colorStrOrig << ": \t     "
                       << getQColor(color).name().toStdString() << "\n";
            };

            if (NUMCOLORS == ++colorIndex) return;
        }
    }
}

int ColorViewer::fwcDrawCircle( int x, int y, int r, Color color, int linewidth, bool solid )
{
    FeetWetCodingExercise::RenderItem item;
    item.type = FeetWetCodingExercise::CIRCLE;
    item.x = x;
    item.y = y;
    item.radius = r;
    item.color = color;
    item.linewidth = linewidth;
    item.solid = solid;

    return mRenderServer->setRenderItem(item);
}

int ColorViewer::fwcDrawText( std::string text, int x, int y, Color color, int size )
{
    FeetWetCodingExercise::RenderItem item;
    item.type = FeetWetCodingExercise::TEXT;
    item.text = text;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;

    return mRenderServer->setRenderItem(item);
}
