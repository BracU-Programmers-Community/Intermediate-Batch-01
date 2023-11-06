#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e6+10;

int tree[4*nmax];
int arr[nmax];

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


void update(int id, int l, int r, int k, int val){

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

int query(int id, int l, int r, int k){

    if(l == r)
        return l;

    int mid = (l+r)/2;

    if(tree[2*id] >= k)
        return query(2*id, l, mid, k);
    else{
        return query(2*id+1, mid+1, r, k-tree[2*id]);
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;


    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        arr[x]++;
    }


    build(1, 1, n);

    int sz = n;
    for(int i = 0; i<q; i++){
        int k;
        cin>>k;

        if(k > 0){
            update(1, 1, n, k, +1);
            sz++;
        }
        else{
            k = -k;
            int x = query(1, 1, n, k);
            update(1, 1, n, x, -1);
            sz--;
        }
    }

    if(sz == 0){
        cout<<0<<"\n";
    }
    else{
        cout<<query(1, 1, n, 1);
    }


    return 0;
}
