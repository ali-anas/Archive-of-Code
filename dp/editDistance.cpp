/* Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
	1. Delete a character

	2. Replace a character with another one

	3. Insert a character
	*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

int bruteForce(string s1, string s2){
    if(s1.size() == 0) {
        return s2.size();
    }
    
    if(s2.size() == 0) {
        return s1.size();
    }
    
    if(s1[0] == s2[0]) {
        return bruteForce(s1.substr(1), s2.substr(1));
    }
    else {
        int byInsert = bruteForce(s1.substr(1), s2) + 1;
        int byDelete = bruteForce(s1, s2.substr(1)) + 1;
        int byUpdate = bruteForce(s1.substr(1), s2.substr(1)) + 1;
        return min(byInsert, min(byDelete, byUpdate));
    }

}

// -------------------------------------------------------------
// memoization soln. top-down

int helper(string s1, string s2, int **output) {
    int m = s1.size();
    int n = s2.size();
    if(s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }
    
    if(output[m][n] != -1) {
        return output[m][n];
    }
    
    if(s1[0] == s2[0]) {
        return helper(s1.substr(1), s2.substr(1), output);
    }
    else {
        int byInsert = helper(s1.substr(1), s2, output)+1;
        int byDelete = helper(s1, s2.substr(1), output)+1;
        int byUpdate = helper(s1.substr(1), s2.substr(1), output)+1;
        int ans = min(byInsert, min(byDelete, byUpdate));
        output[m][n] = ans;
        return ans;
    }
}

int memoization(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int **output = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            output[i][j] = -1;
        }
    }
    
    int ans = helper(s1, s2, output);
    for(int i = 0; i <= m; i++) {
        delete []output[i];
    }
    delete []output;
    return ans;
}

// --------------------------------------------------------------

// dp solution. bottom-up
int dp(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	for(int j = 0; j <= n; j++) {
		output[0][j] = j;
	}

	for(int i = 1; i <= m; i++) {
		output[i][0] = i;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(s1[m-i] == s2[n-j]) {
				output[i][j] = output[i-1][j-1];
			}
			else {
				int x = output[i-1][j];
				int y = output[i][j-1];
				int z = output[i-1][j-1];
				output[i][j] = min(x, min(y, z)) + 1;
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

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  // cout << bruteForce(s1, s2) << endl;

  // cout << memoization(s1, s2) << endl;

  cout << dp(s1, s2) << endl;

}