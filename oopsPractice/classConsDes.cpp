#include <iostream>
#include <cmath>

using namespace std;

class First
{
	private:
		double x,y,z;
	public:
		First(double fx, double fy, double fz)
		{
			x = fx;
			y = fy;
			z = fz;
			return;
		}

		First()
		{
			x = y = z = 0.0;
			return;
		}

		double length()
		{
			return sqrt( x*x + y*y + z*z);
		}
		~First()
		{
			if(length() == 0.0)
				cout << "Zero vector!"<< endl;
			return;
		}


};

int main()
{
	First a(1.0,2.0,3.0);
	cout << "1"<<endl;
	{
		First c;
		a = c;
	}
	First b;
	cout <<"2"<<endl;
	First *p, *q;
	p = new First(4.0,5.0,6.0);
	cout << "3"<<endl;
	q = new First;
	cout << "4"<<endl;
	delete p;
	cout << "5" << endl;
	delete q;
	cout << "6" << endl;
	return 0;
}
