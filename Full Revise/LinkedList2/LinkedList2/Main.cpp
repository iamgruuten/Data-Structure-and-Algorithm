#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List list;

	list.add("Annie");
	list.add("Jacky");
	list.add("Wendy");
	list.print();

	list.add(1, "Brenda");

	list.print();

	list.remove(2);
	list.print();
	list.remove(0);
	list.print();
}