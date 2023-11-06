#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;
ll value[nmax];
vector<int> adj[nmax];
vector<int> dfsarr;
int st[nmax], en[nmax];

/// node i - subtree -> dfsarr (st[i], en[i])

void dfs(int u, int par){
    dfsarr.push_back(u);
    st[u] = dfsarr.size()-1;
    for(int v : adj[u]){
        if(v != par){
            dfs(v, u);
        }
    }
    en[u] = dfsarr.size()-1;
}

ll tree[4*nmax];

void build(int id, int l, int r){

    if(l == r){
        /// l position represents dfsarr[l]
        tree[id] = value[dfsarr[l]];
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

    int n, q;
    cin>>n>>q;

    for(int i = 1; i<=n; i++){
        cin>>value[i];
    }

    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

//    cout<<"dfs arr ";
//    for(int x : dfsarr){
//        cout<<x<<" ";
//    }
//    cout<<endl;

//    for(int i = 1; i<=n; i++){
//        cout<<i<<" : "<<st[i]<<" "<<en[i]<<endl;
//    }

    build(1, 0, n-1);

    for(int i = 0; i<q; i++){
        int type;
        cin>>type;
        if(type == 1){
            int s, x;
            cin>>s>>x;
            update(1, 0, n-1, st[s], x);
        }
        else{
            int s;
            cin>>s;
            cout<<query(1, 0, n-1, st[s], en[s])<<"\n";
        }
    }



}

/*
5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 3
1 5 3
2 3
*/
