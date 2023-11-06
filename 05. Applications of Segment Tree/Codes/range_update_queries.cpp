#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;

ll tree[4*nmax];
ll diffarr[nmax];
ll arr[nmax];

void build(int id, int l, int r){

    if(l == r){
        tree[id] = diffarr[l];
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




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    int q;
    cin>>n>>q;

    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    diffarr[1] = arr[1];

    for(int i = 2; i<=n; i++){
        diffarr[i] = arr[i] - arr[i-1];
    }

    build(1, 1, n);

    for(int i = 0; i<q; i++){
        int t;
        cin>>t;

        if(t == 1){
            int a, b;
            ll u;
            cin>>a>>b>>u;

            update(1, 1, n, a, +u);
            update(1, 1, n, b+1, -u);
        }
        else{
            int k;
            cin>>k;

            cout<<query(1, 1, n, 1, k)<<"\n";

        }
    }







    return 0;
}

