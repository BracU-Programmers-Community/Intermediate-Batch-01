#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


const int nmax = 10000+10;
/// (weight, adj node)
vector<pii> adj[nmax];

int dist[nmax][2];

/// dist[u][0] = shortest distance to u using even edges
/// dist[u][1] = shortest distance to u using odd edges

void dijkstra(int s){
    for(int i = 0; i<nmax; i++){
        dist[i][0] = 1e9;
        dist[i][1] = 1e9;
    }

    /// (shortest distance to (u, k), (u, k))
    priority_queue< pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>> > pq;
    pq.push({0, {s, 0} });
    dist[s][0] = 0;


    while(!pq.empty()){
        int d = pq.top().first;
        pii node = pq.top().second;
        int u = node.first;
        int k = node.second;  /// 0/1

        pq.pop();

        if(d > dist[u][k])
            continue;

        for(auto p : adj[u]){
            int v = p.second;
            int c = p.first;

            /// current state is even
            if(k == 0){
                if(d+c < dist[v][1]){
                    dist[v][1] = d+c;
                    pq.push({d+c, {v, 1}});
                }
            }
            else{   /// current state is odd
                if(d+c < dist[v][0]){
                    dist[v][0] = d+c;
                    pq.push({d+c, {v, 0}});
                }
            }
        }

    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    while(cin>>n>>m){
        for(int i = 1; i<=n; i++){
            adj[i].clear();
        }

        for(int i = 0; i<m; i++){
            int u, v, c;
            cin>>u>>v>>c;
            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }

        dijkstra(1);

        if(dist[n][0] < 1e9){
            cout<<dist[n][0]<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }


    return 0;
}

