#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List aList;

	int array[] = { 10, 4, 6, 3, 5 };

	for (int i = 0; i < 5; i++)
		aList.add(array[i]);

	cout << "The middle value is: ";

	cout << aList.getMiddle() << endl;

	return 0;
}
