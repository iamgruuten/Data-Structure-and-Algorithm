// Q2.cpp : This file contains the 'main' function. 

#include <iostream>
#include "Stack.h"
int main()
{
	Stack s;
	int array[] = { 10, 4, 6, 3, 5 };
	for (int i = 0; i < 5; i++)
		s.push(array[i]);

	s.displayInOrder();
}
