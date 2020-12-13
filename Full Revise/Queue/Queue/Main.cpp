#include <iostream>

#include "Queue.h"
#include "Stack.h"

int main() {
	Queue q;
	Stack s;
	
	string text;
	cout <<"Enter your vaule: ";
	cin >> text;

	for (int i = 0; i < text.size(); i++)
	{
		s.push(text[i]);
		q.enqueue(text[i]);
	}
	
	bool palindrone = true;

	while (!s.isEmpty()) {
		ItemType textA;
		ItemType textB;
		s.pop(textB);
		q.dequeue(textA);
		if (textA != textB) {
			palindrone = false;
			break;	
		}
	}

	if (palindrone) {
		cout << "It is a palidrome" << endl;
	}
	else {
		cout << "It is not a palindrome" << endl;
	}
}