#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


const int nmax = 3000+10;
vector<int> adj[nmax];

int dist[nmax][nmax];
int link[nmax][nmax];

set<tuple<int, int, int>> forbidden;

void bfs(int x, int y){

    for(int i = 0; i<nmax; i++){
        for(int j = 0; j<nmax; j++){
            dist[i][j] = 1e9;
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while(!q.empty()){
        pair<int, int> p = q.front();
        int cur = p.first;
        int prv = p.second;
        q.pop();

        for(int nxt : adj[cur]){
            if(forbidden.count(make_tuple(prv, cur, nxt)) > 0){
                continue;
            }
            if(dist[nxt][cur] != 1e9)
                continue;
            dist[nxt][cur] = dist[cur][prv]+1;
            link[nxt][cur] = prv;
            q.push({nxt, cur});
        }
    }
}

/// V E
/// V^2 VE

/// V^2  + VE = V(V+E) = VE


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    for(int i= 0; i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i<k; i++){
        int a, b, c;
        cin>>a>>b>>c;
        forbidden.insert(make_tuple(a, b, c));
    }

    bfs(1, 1);

    int best = 1;
    for(int prv = 1; prv <= n; prv++){
        if(dist[n][best] > dist[n][prv])
            best = prv;
    }

    if(dist[n][best] == 1e9){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[n][best]<<"\n";
        vector<int> path;
        int cur = n;
        int prv = best;
        while(prv != 1){
            path.push_back(cur);
            int tmp = link[cur][prv];
            cur = prv;
            prv = tmp;
        }
        path.push_back(cur);
        path.push_back(prv);

        reverse(path.begin(), path.end());
        for(int x : path){
            cout<<x<<" ";
        }

    }


    return 0;
}

