// Stack.cpp – Implementation of Stack (Array-based Implementation)
#include "Stack.h"

Stack::Stack() { top = -1; }

Stack::~Stack() { }

bool Stack::push(ItemType item)
{

}

void Stack::getTop(ItemType& item)
{
    bool success = !isEmpty();
    if (success)
        item = items[top];
}

bool Stack::isEmpty() { return top < 0; }

void Stack::displayInOrder()
{
    for (int i = top; i >= 0; i--)
        cout << items[i] << "  ";

    cout << endl;
}
