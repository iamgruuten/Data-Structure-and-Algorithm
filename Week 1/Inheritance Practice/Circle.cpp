// Circle.cpp - Implementation


#include "Circle.h" 

Circle::Circle() { radius = 0;}
Circle::Circle(string t, string c, double r) : Shape(t, c)
{
   radius = r;
}

void Circle::setRadius(double r) { radius = r; }
double Circle::getRadius() { return radius; }
double Circle::findArea() { return 3.142 * radius * radius; }
void Circle::print() 
{
   Shape::print();
   cout << " " << radius;
}
