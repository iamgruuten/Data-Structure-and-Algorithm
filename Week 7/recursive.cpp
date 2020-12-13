#include <iostream>
#include <array>
using namespace std;
int calculate(int array[], int n);

int main(){
    int array[] = {10, 20, 30, 40, 50};

    int total = calculate(array, sizeof(array) / sizeof(int) - 1);
    cout << total << endl;
}


int calculate(int array[], int n){
    if(n < 0){
        return 0;
    }else{
        return array[n] + calculate(array, n-1);
    }
}
