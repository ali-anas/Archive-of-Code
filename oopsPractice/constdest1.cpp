#include <iostream>

using namespace std;

class point{
	private:
		double x,y;
	public:
		point(double p,double q)
		{
			x = p;
			y = q;
			return;
		}
		void printpoint()
		{
			cout << "center : (" << x << "," << y << ")" << endl;
			return;
		}
};

class disk{
	private:
		point center;
		double radius;
	public:
		disk(double x, double y, double r):center(point(x,y)),radius(r)
	{
		return;
	}
		void print()
		{
			cout << "radius : " << radius<< endl;
			center.printpoint();
			return;
		}	
};

int main()
{
	disk a(0.0,0.0,3);
	a.print();
	disk b(4.0,4.0,2.0);
	b.print();
	return 0;
}
