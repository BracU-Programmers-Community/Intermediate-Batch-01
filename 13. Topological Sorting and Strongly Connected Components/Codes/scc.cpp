#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;
vector<int> adj[nmax];
vector<int> rev[nmax];
vector<int> nodes;
int who[nmax];

bool vis[nmax];

void dfs1(int u){
    vis[u] = true;

    for(int v : adj[u]){
        if(vis[v])
            continue;
        dfs1(v);
    }
    nodes.push_back(u);
}

void dfs2(int u, vector<int> &C, int id){
    vis[u] = true;
    C.push_back(u);
    who[u] = id;

    for(int v : rev[u]){
        if(vis[v])
            continue;
        dfs2(v, C, id);
    }
    return;
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
        rev[v].push_back(u);
    }

    for(int i = 1; i<=n; i++){
        if(!vis[i])
            dfs1(i);
    }
    reverse(nodes.begin(), nodes.end());
    for(int i = 1; i<=n; i++)
        vis[i] = false;

    vector<vector<int>> comps;
    int id = 0;
    for(int u : nodes){
        if(!vis[u]){
            comps.push_back(vector<int>());
            dfs2(u, comps.back(), ++id);
        }
    }

    for(int i = 0; i<comps.size(); i++){
        cout<<"Component "<<i+1<<" : ";
        for(int j = 0; j<comps[i].size();j++){
            cout<<comps[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
/*
4 4
1 2
2 1
1 3
2 4
*/
