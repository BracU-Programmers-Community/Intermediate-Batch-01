#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000+10];
int depth[100000+10];
int height[100000+10];
int subtree[100000+10];
/// adj[i] = adjacency list of node i

void dfs(int u, int par){
    if(par == -1){
        depth[u] = 0;
    }
    else{
        depth[u] = depth[par] + 1;
    }

    cout<<"dfs at "<<u<<endl;

    height[u] = 0;
    subtree[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
        height[u] = max(height[u], height[v] + 1);
        subtree[u] += subtree[v];
        //dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i = 0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    dfs(1, -1);

    for(int i = 1; i<=n; i++){
        cout<<i<<" subtree = "<<subtree[i]<<endl;
    }

    return 0;
}

/*
13
1 2
2 5
2 6
1 4
1 7
7 8
8 9
9 10
1 3
3 11
3 12
12 13

*/
