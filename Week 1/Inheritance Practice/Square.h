// Square.h – Specification
#pragma once		  
#include <iostream>     	   
#include <string>      	   
using namespace std;
#include "Shape.h" 	   

class Square : public Shape // inherit from Base class, Shape
{
  // data (properties)
  private:
     double length;

  // functions (methods)
  public:
     Square();
     Square(string, string, double);	
     void setLength(double);	
     double getLength();		
     double findArea();		
     void print();	
};
