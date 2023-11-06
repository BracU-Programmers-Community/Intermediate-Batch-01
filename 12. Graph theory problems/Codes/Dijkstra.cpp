#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


const int nmax = 1e5+10;
vector<pii> adj[nmax];

int dist[nmax];
int link[nmax];



int dijkstra(int s, int t){
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

        if(u == t)
            return d;

        for(pii p : adj[u]){
            int c = p.first;
            int v = p.second;

            if(d+c < dist[v]){
                dist[v] = d+c;
                pq.push({d+c, v});
                link[v] = u;
            }
        }
    }

    return 1e9;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    return 0;
}
