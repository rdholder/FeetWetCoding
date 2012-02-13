// FeetWetCoding/source/lib/ColorViewer.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <include/feetwetcodinglib.h>
#include <include/lib/ColorViewer.h>
#include <include/colors.h>
#include <string>

void ColorViewer::show()
{
    int x(0);
    int y(0);
    int r(55);
    int fontSize(8);
    int colorIndex(0);
    double xshift(r/2.5);
    double yshiftorig(r/5);
    double yshift(yshiftorig);
    unsigned int position(std::string::npos);
    std::string darkStr = "DARK";
    std::string ightStr = "IGHT"; //works for "light" and "bright"
    std::string transStr = "TRANS";
    std::string colorStr, colorStrOrig;

    SeeOut seeout;
    seeout.setFontSize(8);

    for (int i=0; i < 7; ++i)
    {
        y = i*r+r/2;

        for (int j=0; j < 7; ++j)
        {
            x = j*r+r/2;

            Color color = (Color)colorIndex;
            colorStrOrig = getNameForColor(color);
            colorStr = colorStrOrig;
            yshift = yshiftorig;

            position = colorStr.find(darkStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,darkStr.length(),"DARK\n");
                yshift = r/2.75;
            }

            position = colorStr.find(ightStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,ightStr.length(),"IGHT\n");
                yshift = r/2.75;
            }

            position = colorStr.find(transStr);
            if ( std::string::npos != position  )
            {
                colorStr.replace(position,transStr.length(),"TRANS\n");
                yshift = r/2.75;
            }

            DrawCircle(x, y, r, color, 1, true);
            DrawCircle(x, y, r, BLACK, 1);

            switch (color) {

            case WHITE:
            case TRANSPARENT:
                DrawText(colorStr, x-xshift, y-yshift, BLACK, fontSize);
                seeout.setColor(BLACK);
                seeout << colorStrOrig << ":\t     "
                       << getQColor(color).name().toStdString() << "\n";
                break;

            case YELLOW:
            case CYAN:
            case GREEN:
                DrawText(colorStr, x-xshift, y-yshift, BLACK, fontSize);
                seeout.setColor(color);
                seeout << colorStrOrig << ": \t     "
                       << getQColor(color).name().toStdString() << "\n";
                break;

            default:
                DrawText(colorStr, x-xshift, y-yshift, WHITE, fontSize);
                seeout.setColor(color);
                seeout << colorStrOrig << ": \t     "
                       << getQColor(color).name().toStdString() << "\n";
            };

            if (NUMCOLORS == ++colorIndex) return;
        }
    }
}
