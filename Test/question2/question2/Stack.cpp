// Stack.cpp – Implementation of Stack (Array-based Implementation)
#include "Stack.h"

Stack::Stack() { top = -1; }

Stack::~Stack() { }

bool Stack::push(ItemType item)
{
    bool success = top < MAX_SIZE-1;
    if(success) {
        if (items[top - 1] < item) {
         top++;
        items[top] = item;
        return true;
        }

        for (int i = top; i >= 0; i--)
        {
            if (items[i] < item) {
                for (int a = top; a > i + 1 ; a--)
                { 
                    items[a + 1] = items[a];
                }

                top++;
                items[i + 1] = item;

                return true;
                //break 
            }
        }
        
        for (int a = top; a >= 0; a--)
        {
            items[a + 1] = items[a];
        }

        top++;
        items[0] = item;

        return true;
    }
    else {
        return false;
    }
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
