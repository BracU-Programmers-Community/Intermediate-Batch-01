#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;

ll tree[4*nmax];
ll arr[nmax];

void build(int id, int l, int r){

    if(l == r){
        tree[id] = arr[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id] = tree[2*id] + tree[2*id+1];   /// merging childs

}


void update(int id, int l, int r, int k, ll val){

    if(l == r){
        tree[id] = val;     /// update operation
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


    return 0;
}
