#include <iostream>

using namespace std;
/*  x^0 = x
	x^1 = ~x

	flip the ith bit of n.
	0 -> 1
	1 -> 0
 */
void main() {
	int n, i;
	cin >> n >> i;
	int z = n ^ (1 << i);
	cout << z << endl;
	return 0;
}