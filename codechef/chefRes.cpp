#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    vector<pair<int,int> > intervals;
	    for(int i = 0; i < n; i++) {
	        int open, close;
	        cin >> open >> close;
	        intervals.push_back(make_pair(open, close));
	    }
	   // for(int i = 0; i < m; i++) {
	   //     cin >> query[i];
	   // }
	    
	    sort(intervals.begin(), intervals.end());
	    while(m--) {
	        int arr_time;
	        cin >> arr_time;
	        int pos = lower_bound(intervals.begin(), intervals.end(), make_pair(arr_time, 0)) - intervals.begin();
	        
	        if(pos == 0) {
	            int wait_time = intervals[0].first - arr_time;
	            cout << wait_time << endl;
	        }
	        else {
	            int wait_time = -1;
	            if(intervals[pos-1].second > arr_time) {
	                wait_time = 0;
	            }
	            else if(pos < intervals.size()) {
	                wait_time = intervals[pos].first - arr_time;
	            }
	            cout << wait_time << endl;
	        }
	    }
	}
	return 0;
}