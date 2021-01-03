#include <iostream>
#include <string>
#include <algorithm>    // std::max

using namespace std;

int hash1(string str)
{
    int hash = 0;
    for (int i = 0; i < str.length(); i++)
        hash = hash * 31 + int(str.at(i));
    return hash;
}

int hash2(string str)
{
    int hash = 0;
    int skip = fmax(1, str.length() / 4);
    for (int i = 0; i < str.length(); i += skip)
        hash = hash * 31 + int(str.at(i));
    return hash;
}

int main() {
    cout << hash1("cvaqwera") << endl;
    cout << hash2("wearwear") << endl;
    cout << hash2("wearwera") << endl;
    cout << hash2("wearware") << endl;

}