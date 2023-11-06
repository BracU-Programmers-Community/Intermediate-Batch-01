#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000+10];
int depth[100000+10];
/// adj[i] = adjacency list of node i

void dfs(int u, int par){
    if(par == -1){
        depth[u] = 0;
    }
    else{
        depth[u] = depth[par] + 1;
    }

    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
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

    int farthest = 1;
    for(int i = 1; i<=n; i++){
        if(depth[i] > depth[farthest])
            farthest = i;
    }

    cout<<"farthest "<<farthest<<endl;
    for(int i = 1; i<=n; i++){
        depth[i] = 0;
    }
    dfs(farthest, -1);



    for(int i = 1; i<=n; i++){
        if(depth[i] > depth[farthest])
            farthest = i;
    }

    cout<<"farthest "<<farthest<<endl;

    cout<<depth[farthest];


    return 0;
}

/*
13
1 2
2 5
2 6
1 4
4 7
7 8
7 9
7 10
1 3
3 11
3 12
12 13

*/

