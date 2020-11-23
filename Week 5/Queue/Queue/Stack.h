// Stack.h - Specification of Stack ADT (Pointer-based)
#pragma once
#include<string>
#include<iostream>
using namespace std;

typedef char ItemType;

class Stack
{
private:
    struct Node
    {
        ItemType item;	// item
        Node* next;	// pointer pointing to next item
    };

    Node* topNode;	// point to the first item

public:
    // constructor
    Stack();

    ~Stack();

    // push item on top of the stack
    bool push(ItemType item);

    // pop item from top of stack
    bool pop();

    // retrieve and pop item from top of stack
    bool pop(ItemType& item);


    // retrieve item from top of stack
    void getTop(ItemType& item);

    // check if the stack is empty
    bool isEmpty();

};

