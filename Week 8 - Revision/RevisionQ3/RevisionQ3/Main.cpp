#include <iostream>

using namespace std;

int gcdLoop(int x, int y);

int main() {
	cout << gcdLoop(60, 24);
}


int gcd(int x, int y) {
	if (x % y == 0) {
		return y;
	}
	else {
		return gcd(y, x % y);
	}
}

int gcdLoop(int x, int y) {
	while (y != 0) {
		int tempy = y;
		y = x % y;
		x = tempy;
	}

	return x;
}