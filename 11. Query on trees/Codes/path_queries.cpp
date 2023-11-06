#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;
ll value[nmax], sum[nmax];
vector<int> adj[nmax];
vector<int> dfsarr;
int st[nmax], en[nmax];

/// node i - subtree -> dfsarr (st[i], en[i])

void dfs(int u, int par){
    sum[u] = value[u];
    if(par != -1){
        sum[u] += sum[par];
    }
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
ll lazy[4*nmax];        /// lazy[i] = i-th node and it's subtree all require the lazy
ll arr[nmax];

void build(int id, int l, int r){
    lazy[id] = 0;

    if(l == r){
        /// at l position dfsarr[l];
        tree[id] = sum[dfsarr[l]];
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    tree[id] = tree[2*id] + tree[2*id+1];
    return;
}

void propagate(int id, int l, int r){
    if(l != r){
        lazy[2*id] += lazy[id];     /// pass lazy to left child
        lazy[2*id+1] += lazy[id];   /// pass lazy to right child
    }
    tree[id] += lazy[id] * (r-l+1);     /// apply lazy to itself
    lazy[id] = 0;               /// erase own lazy

}


/// (l,..., r) -> r-l+1
ll query(int id, int l, int r, int a, int b){
    propagate(id, l, r);
    /// disjoint case
    if(r < a || b < l)
        return 0;

    /// inside case
    if(a <= l && r <= b)
        return tree[id];


    int mid = (l+r)/2;
    ll p = query(2*id, l, mid, a, b);
    ll q = query(2*id+1, mid+1, r, a, b);
    return p+q;
}


void update(int id, int l, int r, int a, int b, ll val){
    propagate(id, l, r);

    /// disjoint case
    if(r < a || b < l){
        return;
    }

    /// inside case
    if(a <= l && r <= b){
        lazy[id] += val;
        propagate(id, l, r);
        return;
    }


    ///if(k <= tree[2*id])     --- WRONG, propagate from left child before


    int mid = (l+r)/2;
    update(2*id, l, mid, a, b, val);
    update(2*id+1, mid+1, r, a, b, val);

    tree[id] = tree[2*id] + tree[2*id+1];
    return;
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

            ll difference = x-value[s];
            value[s] = x;

            update(1, 0, n-1, st[s], en[s], difference);
        }
        else{
            int s;
            cin>>s;
            cout<<query(1, 0, n-1, st[s], st[s])<<"\n";
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

