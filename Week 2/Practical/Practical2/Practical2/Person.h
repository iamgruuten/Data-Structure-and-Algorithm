using namespace std;

class Person {
    //
private:
    string name;
    string telNo;

    // function
public:
    Person();

    Person(string, string);

    void setName(string);

    string getName();

    void setTelNo(string);

    string getTelNo();
};