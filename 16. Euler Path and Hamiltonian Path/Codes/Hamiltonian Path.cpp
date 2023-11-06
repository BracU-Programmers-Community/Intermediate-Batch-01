#include <bits/stdc++.h>
using namespace std;

int n;
bool adj[50][50];       /// adj[u][v] = is there an edge from u to v

bool visited[2000000][50];      /// [mask][v]
bool memo[2000000][50];         /// memo[mask][v] = there is a hamiltonian path using nodes of mask and ending at v
int link[2000000][50];

bool dp(int mask, int v){
    if(visited[mask][v])
        return memo[mask][v];

    visited[mask][v] = true;


    int mask2 = ( mask & ~(1<<v) );
    if(mask2 == 0)
        return memo[mask][v] = true;

    for(int u = 0; u<n; u++){
        if((mask2 & (1<<u)) > 0){
            if(adj[u][v] && dp(mask2, u)){
                link[mask][v] = u;
                return memo[mask][v] = true;
            }
        }
    }

    return memo[mask][v] = false;
}

/// 2^V * V^2

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = adj[v][u] = true;
    }


    int last = -1;
    int mask = (1<<n)-1;        /// mask representing all nodes are used
    for(int u = 0; u<n; u++){
        if(dp(mask, u)){
            last = u;
            break;
        }
    }


    if(last == -1){
        /// no hamiltonian path
    }
    else{
        for(int i = 0; i<n; i++){
            cout<<last<<endl;

            int nxt = link[mask][last];

            mask &= ~(1<<last);
            last = nxt;
        }
    }



    return 0;
}
