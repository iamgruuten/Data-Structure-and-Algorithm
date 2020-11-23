#include <iostream>

using namespace std;

int main(){

    int value1, value2;
    value1 = 200000;

    int* ptr;

    ptr = &value1;

    cout << "Ptr: " << ptr << endl;

    value2 = *ptr;

    cout << "Value: " << value2 << endl;

    cout << "Address of value 1 : " << &value1 << endl;

    cout << "Address of ptr : " << &ptr << endl;

    ptr = &value2;

    *ptr += 2000;

    cout << "Value of value1: " << value1 << endl;
    cout << "Value of value2: " << value2 << endl;

    return 0;

}
