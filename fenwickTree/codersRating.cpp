#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

struct coder{
    int hi;
    int oi;
    int index; // to print in original order
};

bool compare(coder c1, coder c2) {
    if(c1.hi == c2.hi) {
        return c1.oi < c2.oi;
    }
    return c1.hi < c2.hi;
}

void update(int y, int* BIT) {
    for( ; y <= MAX; y += y&(-y)) {
        BIT[y]++;
    }
}

int query(int y, int* BIT) {
    int count = 0;
    for( ; y > 0; y -= y&(-y)) {
        count += BIT[y];
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    coder* c = new coder[n]();
    int* BIT = new int[MAX+1]();
    for(int i = 0; i< n; i++) {
        scanf("%d%d", &c[i].hi, &c[i].oi); //cin >> c[i].hi >> c[i].oi;
        c[i].index = i;
    }

    sort(c, c+n, compare);
    int* ans = new int[n];

    for(int i = 0; i < n; ) {
        int endIndex = i;
        while(endIndex < n && c[i].hi == c[endIndex].hi && c[i].oi == c[endIndex].oi) {
            endIndex++;
        }
        // query
        for(int j = i; j < endIndex; j++) {
            ans[c[j].index] = query(c[j].oi, BIT);
        }
        // update
        for(int j = i; j < endIndex; j++) {
            update(c[j].oi, BIT);
        }
        i = endIndex;
    }

    for(int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }

    delete []c;
    delete []BIT;
    delete []ans;
    return 0;
}