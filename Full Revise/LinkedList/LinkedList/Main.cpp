#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List q;
	q.add("Hello");
	q.add("Hellos");
	q.add("Helloa");
	q.add("Hellow");
	q.add("Hellof");
	q.add("Hellob");
	q.add("Hellob");
	q.print();
	cout << endl;
	q.reverseR();
	q.print();
}