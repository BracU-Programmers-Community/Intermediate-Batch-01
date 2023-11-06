#include<bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

int n;
vector<pair<int, int>> adj[nmax];   /// edge-id, node

bool visited[nmax];
int st[nmax], low[nmax];
int clk = 0;
vector<pair<int, int>> bridges;


/// does not handle parallel edges
void dfs(int u, int parEdge) {
    visited[u] = true;
    ++clk;
    st[u] = clk;
    low[u] = clk;


    for (auto [e, v] : adj[u]) {
        if (e == parEdge) continue;

        if (visited[v]) {       /// not part of dfs tree
            low[u] = min(low[u], st[v]);
        } else {                /// part of dfs tree
            dfs(v, e);
            low[u] = min(low[u], low[v]);
            if (st[u] < low[v])
                bridges.push_back({u, v});
        }
    }
}

void find_bridges(int n) {
    clk = 0;
    for(int i = 1; i<=n; i++){
        visited[i] = false;
        st[i] = -1;
        low[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i, -1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back({i, v});
        adj[v].push_back({i, u});
    }

    find_bridges(n);

    for(auto b : bridges){
        cout<<b.first<<" "<<b.second<<endl;
    }

}
