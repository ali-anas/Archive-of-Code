#include <iostream>

using namespace std;

#include "pairTemplate.cpp"

int main() {
    Pair<int,int> p1;
    p1.setx(10);
    p1.sety(20);
    cout << "p1" << p1.getx() << endl;
    cout << p1.gety() <<endl;

    Pair<int,double> p2;
    p2.setx(10);
    p2.sety(20.11);
    cout << "p2" << p2.getx() << endl;
    cout << p2.gety() <<endl;

    Pair<Pair<int, int>, int> p3;
    p3.sety(10);

    Pair<int,int> p4;
    p4.setx(15);
    p4.sety(16);

    p3.setx(p4);
    cout << '<' <<p3.getx().getx() << " ,";
    cout << p3.getx().gety() <<'>' << " ,";
    cout << p3.gety() << endl;
}
