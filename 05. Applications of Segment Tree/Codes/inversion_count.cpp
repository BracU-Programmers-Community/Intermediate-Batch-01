#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;

ll tree[4*nmax];
ll arr[nmax];

void build(int id, int l, int r){

    if(l == r){
        tree[id] = 0;
        return;
    }

    int mid = (l+r)/2;

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = tree[2*id] + tree[2*id+1];   /// merging childs

}


void update(int id, int l, int r, int k, ll val){

    if(l == r){
        tree[id] += val;     /// update operation
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, val);
    else
        update(2*id+1, mid+1, r, k, val);


    tree[id] = tree[2*id] + tree[2*id+1];      /// merging child
    return;
}

ll query(int id, int l, int r, int a, int b){
    if(b < l || r < a){     /// disjoint case
        return 0;           /// return identity
    }

    if(a <= l && r <= b){   /// segment is completely inside [a, b] case
        return tree[id];    /// return node value
    }


    int mid = (l+r)/2;

    ll p = query(2*id, l, mid, a, b);
    ll q = query(2*id+1, mid+1, r, a, b);

    return p+q;         /// return merged answer
}


void compress(int n){
    set<int> st;
    for(int i = 0; i<n; i++){
        st.insert(arr[i]);
    }

    map<int, int> mp;

    int now = 1;
    for(int x : st){
        mp[x] = now;
        now++;
    }

    for(int i = 0; i<n; i++){
        arr[i] = mp[arr[i]];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;

    for(int cs = 1; cs <= tc; cs++){

        int n;
        cin>>n;

        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        compress(n);

        build(1, 1, n);

//        for(int i= 0; i<n; i++){
//            cout<<arr[i]<<" ";
//        }

        ll ans = 0;
        for(int i = 0; i<n; i++){
            ///arr[i] insert
            ans += query(1, 1, n, arr[i]+1, n);

            update(1, 1, n, arr[i], +1);
        }

        cout<<ans<<"\n";

    }

    return 0;
}

