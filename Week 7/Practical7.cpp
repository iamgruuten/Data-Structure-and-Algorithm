#include <iostream>

using namespace std;


long power (int a, int n){
    if (n == 1){
        return a;
    }else{
        n = n - 1;
        return a * power(a, n);
    }
}


void printBackward(int array[], int n){
    if(n > 0){
        n = n -1;
        cout << array[n];
        printBackward(array, n);
    }
}

int maxArray(int array[], int start, int end){
    int highestValue = array[start];

    if(start > end){
        return 0;
    }else{
        int currentvalue = maxArray(array, start + 1, end);
        if(highestValue < currentvalue){
            return currentvalue;
        }
        return highestValue;
    }
}

int main(){

//Recursive power
cout << power(5,4) << endl;

//Print int backwards
int array[5] = {1,2,3,4,5};
printBackward(array, 5);


//Find max value
int Sizearray[5] = {1,2,3,4,500};
int start = 0;
int end = 4;
cout << endl << maxArray(Sizearray, start, end);
}
