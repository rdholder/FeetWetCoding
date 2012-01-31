// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter1/a0000.cpp
// Chapter 00 Exercise 00: DESC

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

namespace SolnNamespace
{

class Shape
{
public:
    Shape(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }
    ~Shape(){}

    virtual void drawMe()
    {
        // I can't really do anything
        // here cause I don't know what
        // to draw
    }

protected:
    int x;
    int y;
};

class Circle : public Shape
{
public:
    Circle(int xPos, int yPos)
        :Shape(xPos, yPos)
    {
    }

    ~Circle(){}

    void drawMe()
    {
        // The diameter is 10 and the
        // line-thickness is 3
        // Shift x and y by 1/2 the
        // radius so that the circle's
        // location defines the top left
        // "corner" of the circle instead
        // of its center.
        // TODO: EXPLAIN THIS BETTER
        DrawCircle(x+10, y+10, 20, GREEN, 3, true);
    }

};

class Square : public Shape
{
public:
    Square(int xPos, int yPos)
        :Shape(xPos, yPos)
    {
    }
    ~Square(){}

    void drawMe()
    {
        // The width and height are 20,
        // and line-thickness is 3
        DrawRectangle(x, y, 20, 20, PINK, 3, true);
    }
};

} // End namespace

using namespace SolnNamespace;

int IntroToClassesSoln::runExercise()
{
    Gsoln = true;

    std::vector<Shape *> myShapes;
    std::vector<Shape *>::iterator iter;

    int xPosition = 20;
    int yPosition = 0;

    for (int i=0; i < 5; i++)
    {
        yPosition += 30;
        Circle *c = new Circle(xPosition, yPosition);
        myShapes.push_back(c);

        yPosition += 30;
        Square *s = new Square(xPosition, yPosition);
        myShapes.push_back(s);
    }

    // Here's where it all pays off...
    for( iter = myShapes.begin(); iter != myShapes.end(); iter++ )
    {
        (*iter)->drawMe();
    }

    return 0;
}


