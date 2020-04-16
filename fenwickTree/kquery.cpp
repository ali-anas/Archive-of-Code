#include <bits/stdc++.h>
using namespace std;

#define MAX 500000
typedef long long int ll;

int n, q;
int BIT[MAX];
int result[MAX];

struct data {
    ll value;
    int li;
    int ri;
    int index;
} input[MAX];

// compare for sort
bool compare(data a, data b) {
    if(a.value == b.value) {
        return a.li > b.li;
    }
    return a.value > b.value;
}

void update(ll index) {
    for( ; index <= n; index += index&(-index)) {
        BIT[index]++;
    }
}

int get(ll index) {
    int sum = 0;
    for( ; index > 0; index -= index&(-index)) {
        sum += BIT[index];
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    // input array
    for(int i = 1; i <= n; i++) {
        cin >> input[i].value;
        input[i].ri = i;
        input[i].li = 0;
        input[i].index = i;
    }
    // input queries
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> input[i+n].li >> input[i+n].ri >> input[n+i].value;
        input[i+n].index = i;
    }

    sort(input+1, input+n+q+1, compare);

    // for(int i = 0; i < MAX; i++) {
    //     BIT[i] = 0;
    // }

    for(int i = 1; i <= n+q; i++) {
        if(input[i].li == 0) {
            update(input[i].index);
        } else {
            result[input[i].index] = get(input[i].ri) - get(input[i].li-1);
        }
    }

    // print ans to queries
    for(int i = 1; i <= q; i++) {
        cout << result[i] << "\n";
    }


    return 0;
}