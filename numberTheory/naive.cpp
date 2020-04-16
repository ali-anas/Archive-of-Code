#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int count = 0;
    
    for(int i = 1; i <= n; i++) {
		int temp = 0;
		for(int j = 1; j <= i; j++) {
			if(i % j ==0) {
				temp++;
			}
		}
		if(temp == 2) {
			count++;
		}
	}
	
	cout << count << endl;

    return 0;
}
