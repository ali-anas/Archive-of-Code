#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007
#define MAX 1e6 + 1;

vector<vector<pair<int, int> > > components; // 2d vector of (x, y) pos of connected horses.
vector<ll> factorial(MAX);

void make_factorial() {
	factorial[0] = 1;
	for(int i = 1; i <= MAX; i++) {
		factorial[i] = (factorial[i-1] * i) % MOD;
	}
}

bool isSafe(int x, int y, int n, int m) {
	if(x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	} else {
		return false;
	}
}

void bfs(int** board, int starti, int startj, vector<pair<int, int> >& component, bool** visited, const int& n, const int& m) {
	queue<pair<int, int> > pending;
	pending.push(make_pair(starti, startj));
	visited[starti][startj] = true;
	int x_pos[] = {2, -2, 2, -2, 1, 1, -1, -1};
	int y_pos[] = {-1, 1, 1, -1, 2, -2, 2, -2};
	
	while(!pending.empty()) {
		pair<int, int> front = pending.front();
		component.push_back(front);
		pending.pop();
		for(int i = 0; i < 8; i++) {
			int x = front.first + x_pos[i];
			int y = front.second + y_pos[i];
			
			if(isSafe(x, y, n, m) && !visited[x][y] && board[x][y]) {
				visited[x][y] = true;
				pending.push(make_pair(x, y));
			}
		}
	} 
}

ll noOfPlacements(int** board, int n, int m) {
		bool** visited = new bool*[n];
		for(int i = 0; i < n; i++) {
			visited[i] = new bool[m];
			for(int j = 0; j < m; j++) {
				visited[i][j] = false;
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!visited[i][j] && board[i][j]) {
					vector<pair<int, int> > component;
					bfs(board, i, j, component, visited, n, m);
					components.push_back(component);
				}
			}
		}
		
		ll ans = 1;
		for(int i = 0; i < components.size(); i++) {
			int size = components[i].size();
			ans = ((factorial[size] % MOD) * (ans % MOD)) % MOD;
		}
		return ans;
}

int main() {
	int tc;
	cin >> tc;
	make_factorial();
	while(tc--) {
		int n, m, q;
		cin >> n >> m >> q;
		
		int** board = new int*[n];
		for(int i = 0; i < n; i++) {
			board[i] = new int[m];
			for(int j = 0; j < m; j++) {
				board[i][j] = 0;
			}
		}
		
		for(int i = 0; i < q; i++) {
			int j, k;
			cin >> j >> k;
			board[j-1][k-1] = 1;
		}
		
		cout << noOfPlacements(board, n, m) << endl;
		for(int i = 0; i < n; i++) {
			delete []board[i];
		}
		delete []board;
	}
	return 0;
}
