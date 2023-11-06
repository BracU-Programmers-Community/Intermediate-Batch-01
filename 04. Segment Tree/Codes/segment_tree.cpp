#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;


/// segment tree
ll tree[4*nmax];

/// root -> id = 1, l = 1, r = n
ll arr[nmax];

void build(int id, int l, int r){       ///O(2n) = O(n)

    if(l == r){
        tree[id] = arr[l]; /// arr[r];
        return;
    }

    int mid = (l+r)/2;
    /// left child -> l, mid        right child -> mid+1, r

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = tree[2*id] + tree[2*id+1];

}


void update(int id, int l, int r, int k, ll val){   /// O(log n)

    if(l == r){
        tree[id] = val;
        return;
    }

    int mid = (l+r)/2;

    /// left child -> l, mid        right child -> mid+1, r

    if(k <= mid)
        update(2*id, l, mid, k, val);
    else
        update(2*id+1, mid+1, r, k, val);


    tree[id] = tree[2*id] + tree[2*id+1];
    return;
}

ll query(int id, int l, int r, int a, int b){    /// O(log n)
    if(b < l || r < a){     /// disjoint
        return 0;
    }

    if(a <= l && r <= b){   /// segment is completely inside [a, b]
        return tree[id];
    }


    int mid = (l+r)/2;

    /// left child -> l, mid        right child -> mid+1, r

    ll p = query(2*id, l, mid, a, b);
    ll q = query(2*id+1, mid+1, r, a, b);

    return p+q;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, q;
    cin>>n>>q;



    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    build(1, 1, n);         /// O(n)


    for(int i = 0; i<q; i++){           /// O(q log n)
        int t;
        cin>>t;
        if(t == 1){
            int k, u;
            cin>>k>>u;
            update(1, 1, n, k, u);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<"\n";
        }
    }


    return 0;
}
