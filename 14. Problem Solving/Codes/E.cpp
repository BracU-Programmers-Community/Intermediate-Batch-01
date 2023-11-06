#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 2e5+10;
vector<int> adj[nmax];
bool visited[nmax];
int parent[nmax];

vector<int> cycle;

void dfs(int u, int par){
    parent[u] = par;
    visited[u] = true;

    for(int v : adj[u]){
        if(v == par){
            continue;
        }
        if(visited[v]){
            if(cycle.empty()){
                int cur = u;
                while(true){
                    cycle.push_back(cur);
                    if(cur == v)
                        break;
                    cur = parent[cur];
                }
            }
            continue;
        }
        dfs(v, u);
    }
}


int subtree[nmax];
void dfs2(int u){
    visited[u] = true;
    subtree[u] = 1;

    for(int v : adj[u]){
        if(!visited[v]){
            dfs2(v);
            subtree[u] += subtree[v];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    for(int cs = 1; cs <= tc; cs++){
        int n;
        cin>>n;

        cycle.clear();
        for(int i = 1; i<=n; i++){
            adj[i].clear();
            visited[i] = false;
        }

        for(int i = 0; i<n; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        for(int i = 1; i<=n; i++){
            visited[i] = false;
        }

        for(int x : cycle){
            visited[x] = true;
        }

        for(int x : cycle){
            dfs2(x);
        }

        ll ans = 0;
        ans = 2ll * n * (n-1)/2;


        for(int x : cycle){
            ans -= 1ll * subtree[x] * (subtree[x] - 1) / 2 ;
        }

        cout<<ans<<"\n";

    }

    return 0;
}

