#include <iostream>
using namespace std;

#include "polynomial.cpp"

int main()
{
    /*
    Polynomial p1;
    p1.setCoefficient(0,1);
    p1.print();
    p1.setCoefficient(1,1);
    p1.print();
    p1.setCoefficient(2,1);
    p1.print();
    p1.setCoefficient(3,1);
    p1.print();
    p1.setCoefficient(4,1);
    p1.print();
    p1.setCoefficient(5,1);
    p1.print();
    p1.setCoefficient(15,2);
    p1.print();
    Polynomial p2(p1);
    p2.print();
    Polynomial p3 = p1 + p2;
    p3.print();
    p1.setCoefficient(0,2);
    p1.print();
    */
    Polynomial p1;
    p1.setCoefficient(1,1);
    p1.setCoefficient(3,2);
    p1.setCoefficient(5,-4);
    Polynomial p2;
    p2.setCoefficient(0,4);
    p2.setCoefficient(1,2);
    p2.setCoefficient(2,-3);
    p2.setCoefficient(3,1);
    Polynomial p3 = p1 + p2;
    p3.print();
    return 0;
}
