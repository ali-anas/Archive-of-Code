/* the store contains N pieces of jewellery and each piece has some mass Mi
    and value Vi, mirko has K bags to store his loot, and each bag can hold
    some maximum mass Ci. He plans to store all his loots in these bags, but
    at most one jewellery piece in each bag, in order to reduce the likelihood
    of damage during escape.

    Find maximum total jewellery value that mirko can take.

    INPUT -
        first line: N and K(1<= N,K <= 3000000)
        N lines : pair of Mi ans Vi (1 <= Mi, Vi <= 1000000)
        K lines : Ci (1<= Ci <= 100000000).
    OUTPUT -
        maximum possible loot that can be taken.
}
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) {
        a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    int n, k;
    cin >> n >> k;
    pair<int, int>* pieces = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    sort(pieces, pieces+n, compare);

    multiset<int> bags;
    int allowed_weight;
    for(int i = 0; i < k; i++) {
        cin >> allowed_weight;
        bags.insert(allowed_weight);
    }

    long ans = 0;
    for(int i = 0; i < n; i++) {
        if(bags.empty()) {
            break;
        }
        else if(bags.lower_bound(pieces[i].first) != bags.end()) {
            ans += pieces[i].second;
            bags.erase(bags.lower_bound(pieces[i].first));
        }
    }

    cout << ans << endl;

}
