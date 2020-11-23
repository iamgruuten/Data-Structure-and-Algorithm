// Employee.h - specification

#pragma once
#include <iostream>

using namespace std;

class Employee {
    //Employee properties
private:
    string first_name;
    string last_name;
    int monthly_salary;

public:
    Employee(string firstName, string lastName, int Salary)
    {
        set_firstname(firstName);
        set_lastname(lastName);
        set_salary(Salary);
    }

    void set_firstname(string firstName) {
        first_name = firstName;
    }
    string get_firstname() {
        return first_name;
    }

    void set_lastname(string lastName) {
        last_name = lastName;
    }

    string get_lastname() {
        return last_name;
    }

    void set_salary(int salary) {
        if (salary < 0) {
            salary = 0;
        }
        monthly_salary = salary;
    }

    int get_salary() {
        return monthly_salary;
    }

};