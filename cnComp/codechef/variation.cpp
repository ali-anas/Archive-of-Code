#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);
	long count = 0;

	int i = 0;
	while(i < n) {
		int j = i+1;
		while(j < n && arr[j]-arr[i] < k) {
			j++;
		}
		if(j != n) {
			count += (n-j);
		}
		i++;
	}

	cout << count << endl;
	return 0;
}