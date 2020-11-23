// Circle.h – Specification
#pragma once		   
#include <iostream>     	   
#include <string>      	  
using namespace std;
#include "Shape.h"

class Circle : public Shape // inherit from Base class, Shape
{
  // data (properties)
  private:
     double radius;

  // functions (methods)
  public:
     Circle();				// default constructor
     Circle(string, string, double);	// parameterized constructor
     void setRadius(double);		// set radius
     double getRadius();		// get radius
     double findArea();			// calculate area
     void print();			// print Circle properties
};
