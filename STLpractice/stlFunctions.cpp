#include <iostream>
#include <algorithm>
#include <utility> // for swap
using namespace std;

int main() {
	int arr[] = {4, 5,6, 1, 3, 2};
	// std::sort()
	std::sort(arr, arr+6);
	for(int i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}


	// // sort in reverse order.
	// std::sort(arr, arr+6, std::greater<int>());
	// std::cout << "\nreverse order : ";
	// for(int i = 0; i < 6; i++) {
	// 	std::cout << arr[i] << " ";
	// }


	// std::binary_search()
	std::cout << std::endl;

	std::cout << std::binary_search(arr, arr+6, 5);

	std::cout << std::endl;

	// index of an element in array if present.
	// gives pointer to the element location.
	// if not found then gives pointer to next higher value.
	cout << std::lower_bound(arr, arr+6, 2) - arr << endl;

	// upper_bound
	// next higher index than the value.
	cout << "upper_bound: " << upper_bound(arr, arr+6, 2) - arr << endl;


	// gcd
	cout << "gcd: " << __gcd(10,6) << endl;

	// swap -> in <utility> library

	int x = 10;
	int y = 20;
	cout << "before swap - x: " << x << " y: " << y << endl;
	swap(x,y);
	cout << "after swap - x: " << x << " y: " << y << endl;

	return 0;
}