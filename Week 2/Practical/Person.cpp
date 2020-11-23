#include <iostream>

#include "Person.h"

using namespace std;

Person:Person(){

}

Person:Person(String name, String telNo) : name(name), telNo(telNo){ 
    
}

void setName(String name){
    this->name = name;
}

String getName(){
    return name;
}

void setTelNo(string telNo){
    this-> telno = telNo;
}

String getTelNo(){
    return telno;
}