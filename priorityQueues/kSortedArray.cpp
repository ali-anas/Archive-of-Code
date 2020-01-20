#include <iostream>
#include <queue>

using namespace std;

void kSortedArray(int arr[], int n, int k) {
	priority_queue<int> pq;
	int j = 0;
	for(int i = 0; i < k; i++) {
		pq.push(arr[i]);
	}
	for(int i = k; i < n; i++) {
		arr[j] = pq.top();
		pq.pop();
		pq.push(arr[i]);
		j++;
	}
	while(!pq.empty()) {
		arr[j] = pq.top();
		pq.pop();
		j++;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	kSortedArray(arr, n, k);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}