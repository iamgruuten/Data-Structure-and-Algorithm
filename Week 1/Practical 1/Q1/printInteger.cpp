/**This program is created to separates the integer into its 
individual digits and prints the digits separated 
from one another by three space each

"""Pseudocode"""

Read A Number "n" From The User.
Using While Loop Make Sure Its Not Zero.
Take modulus 10 Of The Number "n".. This Will Give You Its Last Digit.
Then Divide The Number "n" By 10.. ...
Display Out The Number.
**/

#include <iostream> //Include resource
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    int digits, r, numOfDigits;
    
    cout << "Please Enter the digits: "
    cin >> digits;

    numOfDigits = to_string(digits).length() - 1;
    r = abs(pow(10, numOfDigits));

    for(int i = 0; i <= numOfDigits; i++){
        cout << (digits / r) % 10 << "   ";
        r = r / 10;
    }

    cout << endl;
    return 0;

}

