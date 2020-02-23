#include <iostream>
using namespace std;

sumOfDigits(int n) {
	if(n == 0) {
		return 0;
	}

	int smallAns = (n%10) + sumOfDigits(n/10);
	return smallAns;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
   return 0;
}