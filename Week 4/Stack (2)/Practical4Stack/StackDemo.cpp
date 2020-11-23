#include <iostream>
#include <string>
#include "Stack.h"
int main()
{
	Stack back_stack;
	Stack front_stack;

	string temp;
	string url = "";

	back_stack.~Stack();
	front_stack.~Stack();

	while (temp != "0")
	{
		

		cout << endl << "Location: " << url << endl;

		cout << "\n[1] Visit URL\n[2] Back\n[3] Front\n[4] Display Stack\n[5] Display Stack Insertion Order\n[0] Exit\nYour Choice: ";
		cin >> temp;
		if (temp == "0")
			break;
		else if (temp == "1") {
			cout << "Enter URL: ";
			cin >> url;
			back_stack.push(url);

		}
		else if (temp == "2") {

			if (!back_stack.isEmpty()) {
				back_stack.pop(url);
				front_stack.push(url);
				back_stack.getTop(url);
			}
			if (back_stack.isEmpty()) {
				cout << "=================No Record=================" << endl;
			}
		}
		else if (temp == "3")
		{
			//Actual pop from backstack

			if (!front_stack.isEmpty()) {
				front_stack.pop(url);
				back_stack.push(url);
				front_stack.getTop(url);
			}
			if (front_stack.isEmpty()) {
				cout << "=================No Record=================" << endl;
			}
		}
		else if (temp == "4") {
			cout << "Back Stack : ";
			back_stack.displayInOrder();

			cout << endl;

			cout << "Front Stack : ";
			front_stack.displayInOrder();
		}
		else if (temp == "5") {
			cout << "Back Stack : ";
			back_stack.displayInOrderOfInsertion();

			cout << endl;

			cout << "Front Stack : ";
			front_stack.displayInOrderOfInsertion();
		}


	}
	return 0;
}