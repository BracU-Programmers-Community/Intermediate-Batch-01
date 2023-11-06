#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 1e5+10;

ll coins[nmax];
ll sum[nmax];
ll dp[nmax];

vector<int> adj[nmax];
vector<int> rev[nmax];
vector<int> condensed[nmax];

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

    for(int i = 1; i<=n; i++){
        cin>>coins[i];
    }

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

    for(int u = 1; u<=n; u++){
        sum[who[u]] += coins[u];
        for(int v : adj[u]){
            if(who[v] != who[u]){
                condensed[who[u]].push_back(who[v]);
            }
        }
    }

    ll ans = 0;

    /// We don't need new topsort for condensed graph as the algorithm outputs the components in topsorted order!
    for(int c = comps.size(); c>0; c--){
        for(int x : condensed[c]){
            dp[c] = max(dp[c], dp[x]);
        }

        dp[c] += sum[c];
        ans = max(ans, dp[c]);
    }

    cout<<ans<<endl;


    return 0;
}
/*
6 7
1 2
2 3
3 1
3 4
3 5
5 6
6 5
*/

