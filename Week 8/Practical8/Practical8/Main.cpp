#include <iostream>

using namespace std;

static int comparisons = 0;

//Iterative Sequential search

int search(int dataArray[], int arraySize, int target) {
	comparisons = 0;

	for (int i = 0; i < arraySize; i++)
	{

		comparisons++;
		if (dataArray[i] == target) {
			return i;
		}
	}

	return -1;
}


//Recursive Sequential search

int search(int dataArray[], int arraySize,int start, int target) {
	comparisons = 0;
	if (dataArray[start] == target) {
		return start;
	}
	else if (start == target) {
		return -1;
	}
	else {
		return search(dataArray, arraySize, start + 1, target);
	}
}

//Iterative Binary search
int binarySearch(int dataArray[], int arraySize, int target) {
	int begin = 0;
	comparisons = 0;

	while (begin <= arraySize) {
		comparisons++;
		int mid = (begin + arraySize) / 2;
		if (dataArray[mid] == target) {
			return mid;
		}else if(dataArray[mid] > target) {
			arraySize = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}

	return -1;
}


//Recursive Binary search
int binarySearch(int dataArray[], int first, int last, int target){
	if (first > last) {
		return -1;
	}
	else {
		int mid = (first + last) / 2;
		if (dataArray[mid] == target) {
			return mid;
		}
		else if (target < dataArray[mid]) {
			return binarySearch(dataArray, first, mid - 1, target);
		}
		else {
			return binarySearch(dataArray, mid+1, last, target);

		}
	}
}

//Test case

int main() {
	int dataArray[1000];
	int target;

	for (int i = 0; i < 1000; i++)
	{
		dataArray[i] = (i + 1) * 2;
	}

	cout << "Enter a number to search : ";
	cin >> target;

	if (search(dataArray, 1000, target) == -1) {
		cout << "Not Found";
		cout << "No. of comparison: " << comparisons << endl;

	}
	else {
		cout << "Found" << endl;
		cout << "No. of comparison: " << comparisons << endl;
	}

	if (binarySearch(dataArray, 1000, target) == -1) {
		cout << "Not Found";
		cout << "No. of comparison: " << comparisons << endl;

	}
	else {
		cout << "Found";
		cout << "No. of comparison: " << comparisons << endl;

	}
}