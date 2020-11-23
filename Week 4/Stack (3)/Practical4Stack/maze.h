// Stack.h – Specification of Stack (Pointer-based implementation)
#pragma once
#include <iostream>
#define N 12

using namespace std;

typedef string ItemType;


class Maze
{
private:
	struct Cell
	{
		int item;   
		int col; 
	};

public:
	Cell hasNeighbor(char[N][N], Cell);

	void display(char[N][N]);
};


