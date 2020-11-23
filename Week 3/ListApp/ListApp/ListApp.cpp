#pragma once
#include<string>
#include <iostream>

#include "List.h";

using namespace std;

void initNameList(List& nameList);
void listNameList(List& nameList);
void addNameList(List& nameList, ItemType item);
void addNameList(List& nameList, ItemType item, int pos);
void delName(List& nameList, int index);
void search(List& nameList, ItemType item);

int main() {
    string item;
	List nameList;
	cout << "1st Part" << endl;
	initNameList(nameList);
	listNameList(nameList);
	cout << endl;

	cout << "2nd Part (Added brenda)" << endl;

	addNameList(nameList, "Brenda", 3);
	listNameList(nameList);

	cout << endl;

	cout << "3rd Part (Deleted 3rd Index)" << endl;

	delName(nameList, 3);
	listNameList(nameList);

	cout << endl;

	cout << "4th Part (Deleted 1st Index)" << endl;
	delName(nameList, 1);

	listNameList(nameList);


}


void initNameList(List& nameList) {
	addNameList(nameList, "Annie");
	addNameList(nameList, "Jacky");
	addNameList(nameList, "Wendy");
}

void addNameList(List& nameList, ItemType item) {
	nameList.add(item);
}

void addNameList(List& nameList, ItemType item, int pos) {
	nameList.add(pos, item);
}


void listNameList(List& nameList) {
	nameList.print();
}

void delName(List& nameList, int index)
{
	nameList.remove(index);
}

void search(List& nameList, ItemType item) {
	nameList.search(item);
}
