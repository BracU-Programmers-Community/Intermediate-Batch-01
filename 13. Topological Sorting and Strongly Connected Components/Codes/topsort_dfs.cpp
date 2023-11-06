#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

vector<int> adj[nmax];
vector<int> topsort;
int vis[nmax];  /// 0 - not-visited 1 - visiting 2 - visited

bool dfs(int u){
    vis[u] = 1;

    for(int v : adj[u]){
        if(vis[v] == 2)
            continue;
        if(vis[v] == 1)
            return false;
        if(dfs(v) == false)
            return false;
    }

    vis[u] = 2;
    topsort.push_back(u);
    return true;
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
    }

    for(int i = 1; i<=n; i++){
        if(vis[i] == 0)
            if(dfs(i) == false){
                cout<<"IMPOSSIBLE";
                return 0;
            }
    }

    reverse(topsort.begin(), topsort.end());
    for(int x : topsort){
        cout<<x<<" ";
    }


    return 0;
}
