#include<bits/stdc++.h>
using namespace std;

const int max = 1000002;

void createPrimes(int n, int* primes) {
    for(int i = 0; i <= n; i++) {
        primes[i] = i;
    }
    
    for(int i = 2; i*i <= n; i++) {
        if(primes[i] == i) {
            for(int j = 2*i; j <= n; j += i) {
                if(i < primes[j]) {
                	primes[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int* primes = new int[n+1];
    createPrimes(n, primes);
    
    bool mark[n+1];
    for(int i = 0; i <= n; i++) {
        mark[i] = false;
    }
    
    for(int i = n; i > 0; i--) {
        if(!mark[i]) {
            vector<int> temp;
            
            int x = i;
            temp.push_back(i);
            mark[i] = true;
            
            while(x != 1) {
                int lpd = primes[x];
                for(int j = i-lpd; j > 1; j -= lpd) {
                    if(!mark[j]) {
                    	temp.push_back(j);
                    	mark[j] = true;
                    }
                }
                
                // toggle to another prime factor
                while(x%lpd == 0)
                {
                    x /= lpd;
                }
            }
            sort(temp.begin(), temp.end(), greater<int>());
            for(int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
        }
    }
    delete []primes;
    return;
}

int main() {

	// Write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
    return 0;
}
