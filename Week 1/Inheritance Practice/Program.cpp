#include <iostream>

using namespace std;

#include "Shape.h"
#include "Circle.h"
#include "Square.h"

int main()
{
  Shape* shapeArray[3];   // store address of Shape objects
  Circle s1("Circle", "Red", 10.0);
  Square s2("Square", "Blue", 20.0);
  Circle s3("Circle", "Cyan", 30.0);
  shapeArray[0] = &s1;  
  shapeArray[1] = &s2;
  shapeArray[2] = &s3;
  for (int i = 0; i < 3; i++)
  {
    Shape* s = shapeArray[i]; // retrieve object (reference)
    s->print();               // invoke object’s print()
    cout << endl;
    cout << "Area : " << s->findArea() << endl; // invoke object’s findArea()
  }
} 
