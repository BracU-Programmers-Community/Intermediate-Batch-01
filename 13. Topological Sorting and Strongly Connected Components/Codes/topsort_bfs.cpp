
#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

vector<int> adj[nmax];
vector<int> topsort;
int indegree[nmax];

void bfs(int n){
    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(indegree[i]== 0)
            q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        topsort.push_back(u);

        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
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
        indegree[v]++;
    }

    bfs(n);

    if(topsort.size() != n){
        cout<<"IMPOSSIBLE";
    }
    else{
        for(int x : topsort){
            cout<<x<<" ";
        }
    }


    return 0;
}
