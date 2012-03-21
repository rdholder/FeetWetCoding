// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <lib/feetwetcodinglib.h>
#include <exercises/FeetWetCodingExercise.h>
#include <lib/ColorViewer.h>
#include <lib/colors.h>
#include <SeeOut.h>
#include <string>

void ColorViewer::show()
{
    int x(0);
    int y(0);
    int r(75);
    int fontSize(8);
    int colorIndex(0);
    double xshift(r/3);
    double yshiftorig(r/8);
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
        //Space the circles out a bit
        y = i*r+r/2 + i*4 + 4;

        for (int j=0; j < 5; ++j)
        {
            //Space the circles out a bit
            x = j*r+r/2 + j*4 + 4;

            Color color = (Color)colorIndex;
            colorStrOrig = getNameForColor(color);
            colorStr = colorStrOrig;
            yshift = yshiftorig;

            position = colorStr.find(darkStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,darkStr.length(),"DARK\n");
                yshift = r/3.75;
            }

            position = colorStr.find(ightStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,ightStr.length(),"IGHT\n");
                yshift = r/3.75;
            }

            position = colorStr.find(transStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,transStr.length(),"TRANS\n");
                yshift = r/3.75;
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
