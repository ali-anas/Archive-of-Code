#include <bits/stdc++.h>

using namespace std;

vector<int> getVoters(int *arr, int total) {
	sort(arr, arr+total);
	vector<int> voters;
	for(int i = 0; i < total; ) {
		int count = 0;
		int j = i;
		while(j < total && (arr[j] == arr[i])) {
			count++;
			j++;
		}
		if(count >= 2) {
			voters.push_back(arr[i]);
		}
		i = j;
	}
	return voters;
}

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int total = n1+n2+n3;
	int input[total];

	for(int i = 0; i < total; i++) {
		cin >> input[i];
	}

	vector<int> voters = getVoters(input, total);
	cout << voters.size() << endl;

	for(int i = 0; i < voters.size(); i++) {
		cout << voters[i] << endl;
	}
}