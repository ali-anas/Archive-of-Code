void update(ll start, ll end, ll li, ll ri, ll ti, ll key){
    if(start > end) return;

    if(lazy[ti] != 0){
        tree[ti] += lazy[ti]*(end-start+1);

        if(start != end){
            lazy[2*ti] += lazy[ti];
            lazy[2*ti+1] += lazy[ti];
        }

        lazy[ti] = 0;
    }

    if(li > end || ri  < start) 
		return;
    else if(li <= start && end <= ri){
        tree[ti] += key*(end-start+1);
        if(start != end){
            lazy[2*ti] += key;
            lazy[2*ti+1] += key;
        }
        return;
    }

    ll mid = (start+end)/2;
    update(start, mid, li, ri, 2*ti, key);
    update(mid+1, end, li, ri, 2*ti+1, key);
    tree[ti] = tree[2*ti] + tree[2*ti+1];
}


ll query(ll start, ll end, ll li, ll ri, ll ti){
    if(start > end) 
		return 0;

    if(lazy[ti] != 0){
        tree[ti] += lazy[ti]*(end-start+1);

        if(start != end){
            lazy[2*ti] += lazy[ti];
            lazy[2*ti+1] += lazy[ti];
        }

        lazy[ti] = 0;
    }

    if(li > end || ri < start) 
		return 0;
    else if(li <= start && end <= ri) 
		return tree[ti];

    ll mid = (start+end)/2;
    ll x = query(start, mid, li, ri, 2*ti);
    ll y = query(mid+1, end, li, ri, 2*ti+1);
    return x+y;
}


int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, c;
        cin >> n >> c;

        for(ll i = 0; i < 4*MAX; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }

        ll type, li, ri, key;
        while(c--){
            cin >> type;
            if(type == 0){
                cin >> li >> ri >> key;
                update(0, n-1, li-1, ri-1, 1, key);
            }
            else{
                cin >> li >> ri;
                cout << query(0, n-1, li-1, ri-1, 1) << endl;
            }
        }
    }
    return 0;
}
