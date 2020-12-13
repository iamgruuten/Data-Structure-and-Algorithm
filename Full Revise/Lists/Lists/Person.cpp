#include <iostream>

#include "Person.h"

Person::Person() {

}

Person::Person(string name, string telNo) : name(name), telNo(telNo) {
    setName(name);
    setTelNo(telNo);
}

void Person::setName(string name) {
    this->name = name;
}

string Person::getName() {
    return name;
}

void Person::setTelNo(string telNo) {
    this->telNo = telNo;
}

string Person::getTelNo() {
    return telNo;
}