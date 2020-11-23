#include <iostream>

using namespace std;

#include "Employee.h";

int main() {
	Employee e1("Lee", "Quan Sheng", 100000);
	Employee e2("Low", "Ben", 1000);

	cout << e1.get_firstname() << " " << e1.get_lastname() << "'s Salary: " << e1.get_salary() << endl;
	cout << e2.get_firstname() << " " << e2.get_lastname() << "'s Salary: " << e2.get_salary() << endl;

	//Raise salary
	e1.set_salary(e1.get_salary() * 1.10);
	e2.set_salary(e2.get_salary() * 1.10);

	cout << e1.get_firstname() << " " << e1.get_lastname() << "'s Salary: " << e1.get_salary() << endl;
	cout << e2.get_firstname() << " " << e2.get_lastname() << "'s Salary: " << e2.get_salary() << endl;
}