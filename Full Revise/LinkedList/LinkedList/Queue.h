#pragma once
#include<string>
#include<iostream>
using namespace std;

typedef string ItemType;
const int MAX_SIZE = 5;

class Queue
{
private:

    
    int tail;	// point to the first item
    int rear;	// point to the first item
    int count;

    ItemType queue[MAX_SIZE];

public:
    // constructor
    Queue();

    ~Queue();

    // enqueue (add) item at the back of queue
    bool enqueue(ItemType item);

    // dequeue (remove) item from front of queue
    bool dequeue();

    // dequeue (remove) and retrieve item from front of queue
    bool dequeue(ItemType& item);

    // retrieve (get) item from front of queue
    void getFront(ItemType& item);

    // check if the queue is empty
    bool isEmpty();

    // display items in queue from front to back
    void displayItems();

    bool isFull();
};
