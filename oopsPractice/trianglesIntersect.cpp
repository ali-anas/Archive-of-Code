#include <iostream>

using namespace std;

struct point {
	double x, y;
};

struct triangle {
	point p[3];
};

void read_point(point &p) {
	cin >> p.x >> p.y;
}

void read_triangle(triangle &t) {
	read_point(t.p[0]);
	read_point(t.p[1]);
	read_point(t.p[2]);
}

void print_triangle(const triangle &t) {
	cout << '(' << t.p[0].x << ',' << t.p[0].y << ')' << " ";
	cout << '(' << t.p[1].x << ',' << t.p[1].y << ')' << " ";
	cout << '(' << t.p[2].x << ',' << t.p[2].y << ')' << endl;
	return;
}

bool intersect(triangle const &t1, triangle const &t2)
{
	//for(int i = t1.p[0].x;
}


int main() {
	triangle t1;
	triangle t2;
	read_triangle(t1);
	read_triangle(t2);
	print_triangle(t1);
	print_triangle(t2);
	// if(intersect(t1,t2))
	// 	cout << "YES!" << endl;
	// else
	// 	cout << "NO!" <<endl;
	return 0;
}
