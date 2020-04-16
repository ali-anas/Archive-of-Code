/* Distinct Query Problem
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) 
(1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct 
elements in the subsequence ai, ai+1, ..., aj.

Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).

Output
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
3
2
3 
*/



#include <bits/stdc++.h>
using namespace std;

int BIT[30001];
int lastIndex[1000001];
int arr[30001];

struct query{
    int start;
    int end;
    int index;
} q[200000];


bool operator < (query q1, query q2) {
    return q1.end < q2.end;
}

void update(int index, int value, int size) {
    for( ; index <= size; index += index&(-index)) {
        BIT[index] += value;
    }
}

int get(int index) {
    int ans = 0;
    for( ; index > 0; index -= index&(-index)) {
        ans += BIT[index];
    }
    return ans;
}


int main() {
    int n, d;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> d;
    for(int i = 0; i < d; i++) {
        cin >> q[i].start >> q[i].end;
        q[i].index = i;
    }

    sort(q, q+d);
    memset(lastIndex, -1, sizeof(lastIndex));

    int total = 0;
    int k = 0;
    int ans[d];

    for(int i = 1; i <= n; i++) {
        int value = arr[i];
        if(lastIndex[value] != -1) {
            update(lastIndex[value], -1, n);
        } else {
            total++;
        }
        update(i, 1, n);
        lastIndex[value] = i;

        while(k < d && q[k].end == i) {
            ans[q[k].index] = total - get(q[k].start-1);
            k++;
        }
    }

    for(k = 0; k < d; k++) {
        cout << ans[k] << "\n";
    }

    return 0;
}