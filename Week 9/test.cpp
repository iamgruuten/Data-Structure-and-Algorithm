#include <iostream>
#include <string>

using namespace std;

string reverse(string str){
    char[] charArr = str.toCharArray();
        int size = charArr.length;
        Stack stack = new Stack(size);

        int i;
        for(i = 0; i < size; ++i) {
            stack.push(charArr[i]);
        }

        for(i = 0; i < size; ++i) {
            charArr[i] = stack.pop();
        }

        return String.valueOf(charArr);
}