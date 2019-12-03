#include <iostream>

using namespace std;

struct type{
	char z;
	int x,y;
};

int main()
{
	type p1;
	type *ob1;
	ob1 = &p1;
	*ob1 = {'c',2,3};
	(*ob1).x = 1 + (*ob1).y;
	cout << (*ob1).x<< " " << (*ob1).y;
	cout << "\n";
	return 0;
}
