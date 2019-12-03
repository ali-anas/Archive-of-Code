#include <iostream>
using namespace std;

#include "factor.cpp"

int main()
{
    Factor f1(5,12);
    Factor f2(7,12);
    f1.print();
    f2.print();
    f1.add(f2);
    f1.print();
    f2.print();
    return 0;
}
