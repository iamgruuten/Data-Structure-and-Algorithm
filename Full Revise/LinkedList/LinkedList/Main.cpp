#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	Queue q;
	q.enqueue("Hello");
	q.enqueue("Hellos");
	q.enqueue("Helloa");
	q.enqueue("Hellow");
	q.enqueue("Hellof");
	q.enqueue("Hellob");
	q.enqueue("Hellob");
	q.displayItems();

	q.dequeue();
	q.displayItems();
	q.enqueue("Hellow");
	q.displayItems();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.displayItems();

}
