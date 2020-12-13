#include <iostream>

#include "Stack.h"
#include <string>
using namespace std;

int main() {
    Stack back_stack;
    Stack front_stack;

    string temp;
    ItemType url = "";
    while (temp != "0")
    {
        cout << "Current URL: " << url << endl;
        cout << "[1] Visit URL\n[2] Back\n[3] Front\n[0] Exit\nYour Choice: ";
        cin >> temp;
        if (temp == "0")
            break;
        if (temp == "1") {
            cout << "Enter URL : ";
            back_stack.push(url);
            cin >> url;
            cout << endl << endl;
        }
        if (temp == "2") {
            if (!back_stack.isEmpty()) {

            front_stack.push(url);
            back_stack.pop(url);
            }
        }
        if (temp == "3") {
            if (!front_stack.isEmpty()) {
                back_stack.push(url);
                front_stack.pop(url);
            }
        }
    }
    return 0;

}