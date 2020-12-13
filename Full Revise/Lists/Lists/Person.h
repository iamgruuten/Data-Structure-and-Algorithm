using namespace std;
#include <string>

class Person {
    
private:
    string name;
    string telNo;

public:
    Person();

    Person(string, string);

    void setName(string);

    string getName();

    void setTelNo(string);

    string getTelNo();
};