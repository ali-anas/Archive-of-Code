#include <bits/stdc++.h>
using namespace std;

class Points {
public:
	int x, y;
};

class Polygon {
public:
	Points* points;
	Polygon(int n) {
		points = new Points[n];
	}
};

double pArea(Polygon p, int n) {
	Points fixed;
	fixed.x = p.points[0].x;
	fixed.y = p.points[0].y;

	double area = 0;
	for(int i = 1; i < n-1; i++) {
		double x1 = p.points[i].x - fixed.x;
		double y1 = p.points[i].y - fixed.y;
		double x2 = p.points[i+1].x - fixed.x;
		double y2 = p.points[i+1].y - fixed.y;

		double cross_prod = (x1 * y2) - (x2 * y1);
		area += cross_prod;
	}

	return abs(area/2);
}

int main() {
	cout << "Enter the no of points\n";
	int n;
	cin >> n;
	Polygon p(n);
	cout << "\nEnter points\n";
	for(int i = 0; i < n; i++) {
		cin >> p.points[i].x;
		cin >> p.points[i].y;
	}

	double area = pArea(p, n);
	cout << area << endl;

}