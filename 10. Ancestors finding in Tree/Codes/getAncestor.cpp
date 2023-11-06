#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;
vector<int> adj[nmax];
int ancestor[nmax][20];     /// 2^20 > 10^6
/// ancestor[x][i] = 2^i-th ancestor of x

void dfs(int u, int par){
    for(int i = 0; i<20; i++)
        ancestor[u][i] = -1;

    if(par != -1){
        ancestor[u][0] = par;
        for(int i = 1; i<20; i++){
            int v = ancestor[u][i-1];
            if(v == -1) break;
            ancestor[u][i] = ancestor[v][i-1];
        }
    }

    for(int v : adj[u]){
        dfs(v, u);
    }
}

int getAncestor(int u, int k){
    for(int i = 0; i<20; i++){
        if((k & (1<<i)) != 0){
            u = ancestor[u][i];
            if(u == -1)
                return -1;
        }
    }
    return u;
}
/// log n

/// binary lifting

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n;
    cin>>q;

    for(int i = 2; i<=n; i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }

    dfs(1, -1);

//    for(int i = 1; i<=n; i++){
//        cout<<"ancestors of "<<i<<" = ";
//        for(int j = 0; j<3; j++){
//            cout<<ancestor[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for(int i = 0; i<q; i++){
        int x, k;
        cin>>x>>k;

        cout<<getAncestor(x, k)<<"\n";
    }



    return 0;
}

/*
18
1 2
1 3
2 4
2 8
4 5
5 6
4 7
8 9
8 10
9 11
3 13
3 14
14 15
14 17
15 16
17 18
17 12
*/
