#include <iostream>
#include <string>
#include "stack.h";

using namespace std;

int main() {
	Stack stack;

	cout << "Push 3 on top" << endl;

	stack.push(3);

	cout << "Push 4 on top" << endl;

	stack.push(4);

	ItemType item;
	stack.getTop(item);
	cout << "Getting top value: " << item << endl;

	stack.displayInOrder();

	cout << "Pop on top" << endl;

	stack.pop();

	stack.displayInOrder();
}