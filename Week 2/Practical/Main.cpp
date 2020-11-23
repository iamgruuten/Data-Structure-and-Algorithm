#include <iostream>

using namespace std;

void initPhoneList(List& phoneList);
void displayMenu();
void listPhoneNumbers(List phoneList);
void addPhoneNumber(List& phoneList);
void delPhoneNumber(List& phoneList);
void searchPhoneNumber(List phoneList);
init search(List phoneList, string name);

int main(){
    
}

void displayMenu(){
    cout << "------------ Main Menu ------------" << endl;
    cout << "[1] List the phone numbers" << endl;
    cout << "[2] Add a new contact" << endl;
    cout << "[3] Remove a contact" << endl;
    cout << "[4] Search for a phone number" << endl;
    cout << "[0] Exit" << endl;
    cout << "--------------------------------" << endl;
}
