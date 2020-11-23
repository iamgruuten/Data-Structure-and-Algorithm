// Shape.cpp – Implementation

#include "Shape.h"

Shape::Shape() { }	      
Shape::Shape(string t, string c) : type(t),colour(c) { }
void Shape::setType(string t) { type = t; }
string Shape::getType() { return type; }
void Shape::setColour(string c) { colour = c; }
string Shape::getColour() { return colour; }
double Shape::findArea() { return 0; }  
void Shape::print()
{
   cout << "\nShape: " << getType() << " " << getColour();
}
