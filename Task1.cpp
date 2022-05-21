#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    void setName(string newName)
    {
        if (newName != "")
        {
            name = newName;
        }
    }

    void setLastName(string newLastName)
    {
        if (newLastName != "")
        {
            lastName = newLastName;
        }
    }

    void setAge(int newAge)
    {
        if (newAge >= 0)
        {
            age = newAge;
        }
    }

    string getName(void)
    {
        return name;
    }
    string getLastName(void)
    {
        return lastName;
    }
    int getAge(void)
    {
        return age;
    }

    void print() {
        cout << getName() << ' ' << getLastName() << " is " << getAge() << " years old\n";
    }

private:
    string name;
    string lastName;
    int age;

};