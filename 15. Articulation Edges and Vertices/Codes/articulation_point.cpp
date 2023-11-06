#include<bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

int n;
vector<int> adj[nmax];

bool visited[nmax];
int st[nmax], low[nmax];
int clk = 0;
int adjComp[nmax];      /// adjacent component

void dfs(int u, int par ) {
    visited[u] = true;
    clk++;
    st[u] = clk;
    low[u] = clk;
    int children=0;

    for (int v : adj[u]) {
        if (v == par) continue;

        if (visited[v]) {
            low[u] = min(low[u], st[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= st[u] && par!=-1)
                adjComp[u]++;
            ++children;
        }
    }
    if(par == -1 && children > 1)
        adjComp[u] = children-1;
}

void find_cutpoints(int n) {
    clk = 0;
    for(int i = 1; i<=n; i++){
        visited[i] = false;
        st[i] = -1;
        low[i] = -1;
        adjComp[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cutpoints(n);

    for(int i = 1; i<=n; i++){
        if(adjComp[i] > 0){
            cout<<i<<endl;
        }
    }

}
