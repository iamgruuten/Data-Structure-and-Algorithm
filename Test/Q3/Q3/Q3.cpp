// Q3.cpp
#include <iostream>
#include "Dictionary.h"
int main()
{
    string s[] = { "The", "quick", "brown", "fox", "jumps", "over",
                    "the", "lazy", "dog" };
    Dictionary dict;
    for (int i = 0; i < 9; i++)
        dict.add(s[i], i + 1);

    dict.printChainLength();

}
