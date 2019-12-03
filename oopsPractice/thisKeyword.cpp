#include <iostream>
using namespace std;

class Student
{
    private :
    int rollNumber;
    public :
    int age;
    // constructors
    /*
    Student()
    {
        setAge(0);
        setRoll(0);
    }
    Student(int age)
    {
        setAge(age);
        setRoll(0);
    }*/
    Student(int age = 0, int rollNumber = 0)
    {
        setAge(age);
        setRoll(rollNumber);
    }
    // display
    void display()
    {
        cout << "age : " << getAge() << "  rollNumber : " << getRoll() << endl;
    }
    // getters
    int getAge()
    {
        return this->age;
    }
    int getRoll()
    {
        return this -> rollNumber;
    }
    //setters
    void setAge(int age)
    {
        this -> age = age;
    }
    // using same name as my private data member but "this" keyword will take care of it.
    void setRoll(int rollNumber)
    {
        if(rollNumber < 1)
        {
            return;
        }
        this -> rollNumber = rollNumber;
    }
};

int main()
{
    Student s1;
    cout << "s1 : "; s1.display();
    Student s2(20);
    cout << "s2 : "; s2.display();
    Student *s3 = new Student;
    cout << "s3 : "; s3 -> display();
    s3 -> age = 21;
    s3 -> setRoll(-1);
    cout << "s3 : " ; s3 -> display();
    return 0;
}
