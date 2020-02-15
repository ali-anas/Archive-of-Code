#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int lcs_bruteForce(string a, string b) {
	// base case.
	if(a.size()== 0 || b.size() == 0) {
		return 0;
	}

	// recursive case.
	if(a[0] == b[0]) {
		return lcs_bruteForce(a.substr(1), b.substr(1)) + 1;
	}
	else {
		int x = lcs_bruteForce(a.substr(1), b);
		int y = lcs_bruteForce(a, b.substr(1));
		int z = lcs_bruteForce(a.substr(1), b.substr(1));
		return max(x, max(y, z));
	}
}

int lcs_mem(string a, string b, int **output) {
	int m = a.size();
	int n = b.size();

	if(m == 0 || n == 0) {
		return 0;
	}

	if(output[m][n] != -1) {
		return output[m][n];
	}

	if(a[0] == b[0]) {
		return lcs_mem(a.substr(1), b.substr(1), output)+1;		
	}
	else {
		int x = lcs_mem(a.substr(1), b, output);
		int y = lcs_mem(a, b.substr(1), output);
		int z = lcs_mem(a.substr(1), b.substr(1), output);
		int ans = max(x, max(y, z));
		output[m][n] = ans;
		return ans;
	}
}

int lcs_memoization(string a, string b) {
	int m = a.size();
	int n = b.size();
	int **output = new int*[m+1];
	for(int i = 0; i < m+1; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j < n+1; j++) {
			output[i][j] = -1;
		}
	}

	int ans = lcs_mem(a, b, output);
	for(int i = 0; i < m+1; i++) {
		delete []output[i];
	}
	delete []output;
	return ans;
}


int lcs_dp(string a, string b) {
	int m = a.size();
	int n = b.size();
	int **output = new int*[m+1];
	for(int i = 0; i <=m; i++) {
		output[i] = new int[n+1];
	}

	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[m-i] == b[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int x = output[i-1][j];
				int y = output[i][j-1];
				int z = output[i-1][j-1];
				output[i][j] = max(x, max(y, z));
			}
		}
	}

	int ans = output[m][n];
	for(int i = 0; i < m+1; i++) {
		delete []output[i];
	}
	delete []output;
	return ans;
}

int main() {
	string a;
	string b;
	cin >> a >> b;
	cout << lcs_bruteForce(a, b) << endl;

	cout << lcs_memoization(a, b) << endl;

	cout << lcs_dp(a, b) << endl;

	return 0;
}