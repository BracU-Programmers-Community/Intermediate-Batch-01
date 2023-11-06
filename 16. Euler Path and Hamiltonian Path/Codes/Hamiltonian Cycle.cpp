#include <bits/stdc++.h>
using namespace std;

int n, w;
bool adj[50][50];       /// adj[u][v] = is there an edge from u to v

bool visited[2000000][50];      /// [mask][v]
bool memo[2000000][50];         /// memo[mask][v] = there is a hamiltonian path using nodes of mask and ending at v

bool dp(int mask, int v){
    if(visited[mask][v])
        return memo[mask][v];

    visited[mask][v] = true;


    int mask2 = ( mask & ~(1<<v) );
    if(mask2 == 0)
        return memo[mask][v] = adj[w][v];

    for(int u = 0; u<n; u++){
        if((mask2 & (1<<u)) > 0){
            if(adj[u][v] && dp(mask2, u)){
                return memo[mask][v] = true;
            }
        }
    }

    return memo[mask][v] = false;
}


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

    w = n-1;        /// special node
    n--;


    int mask = (1<<n)-1;        /// mask representing all nodes are used
    for(int u = 0; u<n; u++){
        if(dp(mask, u) && adj[u][w]){
            cout<<"hamiltonian cycle found"<<endl;
            break;
        }
    }


    return 0;
}
