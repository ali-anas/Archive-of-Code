#include <cstring>
#include <iostream>

using namespace std;
#include "deepCopyVsShallowCopy.cpp"

int main()
{
    char name[] = "abcd";
    Student s1(101, 20, name);
    cout << "s1 : "; s1.display();

    name[3] = 'e';
    Student s2(102, 21, name);
    cout << "s2 : "; s2.display();
    cout << "s1 : "; s1.display();

    const Student s3 = s2;
    cout << "s3 : "; s3.display();
    cout << "s2 : "; s2.display();

    s3.name[2] = 'd';
    cout << "s3 : "; s3.display();
    cout << "s2 : "; s2.display();

    cout << s3.getRoll() << endl;

    return 0;

}
