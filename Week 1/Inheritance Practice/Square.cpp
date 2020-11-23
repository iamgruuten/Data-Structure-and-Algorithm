// Square.cpp - Implementation

#include "Square.h"
Square::Square() { } 
Square::Square (string t, string c, double l) : Shape(t, c)
{
   length = l;
}

void Square::setLength(double l) {length = l; }
double Square::getLength() { return length; }
double Square::findArea() { return length * length; }
void Square::print() 
{
   Shape::print();
   cout << " " << length;
}
