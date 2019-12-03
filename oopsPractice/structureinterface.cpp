#include <iostream>
#include <cmath>

using namespace std;

struct V3
{
	double x, y, z;
	double length()
	{
		return sqrt((x*x) + (y*y)+ (z*z));
	}
	V3 sum(V3 const &b)
	{
		V3 v;
		v.x = x + b.x;
		v.y = y + b.y;
		v.z = z + b.z;
		return v;
	}
	V3 scale(double const factor)
	{
		V3 v;
		v.x = x * factor;
		v.y = y * factor;
		v.z = z * factor;
		return v;
	}
	void print()
	{
		cout << "x : " << x<< " | y : " << y<< " | z : " << z;
	}
};

int main()
{
	V3 a, b, *ptr;
	cin >> a.x >> a.y >> a.z;
	b = a.scale(2);
	cout << "b.x : " << b.x<< endl;
	cout << "b.length : " << b.length()<<endl;
	ptr = &b;
	// cout << "b -> x : "<<b->x<<endl; //b is not pointer type object
	cout << "ptr -> x : "<< ptr -> x << endl; 
	cout << "ptr -> length : "<< ptr -> length() << endl;
	cout << "ptr -> print : " ; ptr -> print(); cout << endl;
	cout << "b.print : "; b.print(); cout << endl;
	delete ptr;
	return 0;
}

