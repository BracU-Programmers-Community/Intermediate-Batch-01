#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


const int nmax = 500+10;
/// (weight, adj node)
vector<pii> adj[nmax];

int dist[nmax];
int link[nmax];

void dijkstra(int s){
    for(int i = 0; i<nmax; i++)
        dist[i] = 1e9;

    /// (shortest distance to u, u)
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u])
            continue;

        for(pii p : adj[u]){
            int c = p.first;
            int v = p.second;

            if(max(d, c) < dist[v]){
                dist[v] = max(d, c);
                pq.push({max(d, c), v});
                link[v] = u;
            }
        }
    }

    return;
}

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int tc;
    cin>>tc;
    for(int cs = 1; cs <= tc; cs++){
        int n, m;
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            adj[i].clear();
        }


        for(int i = 0; i<m; i++){
            int u, v, c;
            cin>>u>>v>>c;

            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }

        int t;
        cin>>t;
        dijkstra(t);

        cout<<"Case "<<cs<<":\n";
        for(int i = 0; i<n; i++){
            if(dist[i] < 1e9)
                cout<<dist[i]<<"\n";
            else
                cout<<"Impossible\n";
        }
    }

    return 0;
}
