#include<string>
#include<iostream>
#include "Queue.h"
#include "Stack.h"

#include <string.h>

using namespace std;

bool palindrome(string word);

int main() {

	Queue r; 

	
	r.enqueue('a');
	r.enqueue('b');

	char item;
	r.getFront(item);
	cout << item << endl;

	r.displayItems();
	r.dequeue();
	r.displayItems();

	string word;

	cin >> word;

	//Palindrome Question
	if (palindrome(word)) {
		cout << "It is a palindrome";
	}
	else {
		cout << "It is not a palindrome";
	}
}

bool palindrome(string word) {
	Queue r;
	Stack s;

	for (char& c: word )
	{
		r.enqueue(c);
		s.push(c);
	}

	bool equal = true;
	char rc;
	char sc;

	while (!r.isEmpty() && equal) {
		r.getFront(rc);
		s.getTop(sc);

		if (rc == sc) {
			r.dequeue();
			s.pop();
		}
		else {
			equal = false;
		}

	}

	return equal;
}