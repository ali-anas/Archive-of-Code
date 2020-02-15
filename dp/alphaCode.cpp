#include <iostream>
using namespace std;
// recursive approach
int rec_num_codes(int *a, int size) {
	if(size == 0 || size == 1) {
		return 1;
	}

	int output = rec_num_codes(a, size-1);
	if(a[size-2]*10 + a[size-1] <= 26) {
		output += rec_num_codes(a, size-2);
	}
	return output;
}

// memoized approach
int memo_num_codes(int *a, int size, int* cached) {
	if(size == 0 || size == 1) {
		return 1;
	}

	if(cached[size] != 0) {
		return cached[size];
	}

	int output = memo_num_codes(a, size-1, cached);
	if(a[size-2]*10 + a[size-1] <= 26) {
		output += memo_num_codes(a, size-2, cached);
	}

	cached[size] = output;
	return output;
}

// dp approach.
int dp_num_codes(int* a, int size) {
	int* output = new int[size+1];
	output[0] = output[1] = 1;

	for(int i = 2; i <= size; i++) {
		output[i] = output[i-1];
		if(a[i-2]*10 + a[i-1] <= 26) {
			output[i] += output[i-2];
		}
	}

	int ans = output[size];
	delete []output;
	return ans;
}

int main() {
	int size;
	cin >> size;
	int* a = new int[size];
	for(int i = 0; i < size; i++) {
		cin >> a[i];
	}
	cout << "rec ans : " << rec_num_codes(a, size) << endl;
	int *arr = new int[size+1];
	for(int i = 0; i <= size; i++) {
		arr[i] = 0;
	}
	cout << "memo ans : " << memo_num_codes(a, size, arr) << endl;
	cout << "dp ans : " << dp_num_codes(a, size) << endl;

	return 0;
}