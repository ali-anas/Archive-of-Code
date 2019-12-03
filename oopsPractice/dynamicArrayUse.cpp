#include <iostream>

using namespace std;
#include "dynamicArray.cpp"

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    cout << "d1 : "; d1.print();
    DynamicArray d2(d1);


    d2.add(0, 100);
    cout << "d1 : "; d1.print();
    cout << "d2 : "; d2.print();
    DynamicArray d3 = d2;
    d3.add(0,200);
    cout << "d1 : "; d1.print();
    cout << "d2 : "; d2.print();
    cout << "d3 : "; d3.print();
    return 0;
}
