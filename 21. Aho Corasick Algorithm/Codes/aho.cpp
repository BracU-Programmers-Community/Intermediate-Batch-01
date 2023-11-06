#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;
const int alpha = 26;			//alphabet size
int tsz;
int nxt[nmax+1][alpha];			//nmax is sum of all string length
int parent[nmax+1], EndCnt[nmax+1], WordCnt[nmax+1];

/// THE CODE IS FOR LOWERCASE LETTERS, change the 'a' to 'A' for uppercase

//call makenode(-1) to initialize
int MakeNode(int par){
	if(par == -1) tsz = 0;
	parent[tsz] = par, EndCnt[tsz] = 0, WordCnt[tsz] = 0;
	memset(nxt[tsz], -1, sizeof(nxt[tsz]));
	int ret = tsz++;
//	cout<<ret<<endl;
	return ret;
}

int TrieInsert(char *str){
    int cur = 0;				//root
    WordCnt[cur]++;
    for(int i = 0; str[i] != 0; i++){

        if(nxt[cur][str[i] - 'a'] == -1)
            nxt[cur][str[i]-'a'] = MakeNode(cur);
        cur = nxt[cur][str[i]-'a'];
        WordCnt[cur]++;
    }
	EndCnt[cur]++;
    return cur;
}

int TrieSearch(char *str){
	int cur = 0;
	for(int i = 0; str[i] != 0; i++){
		if(nxt[cur][str[i] - 'a'] != -1)
			return 0;
		cur = nxt[cur][str[i]-'a'];
	}
	return EndCnt[cur];
}

/// failure[u] = lowest node v s.t. str(v) is a suffix of str(u)
int Failure[nmax+1], patEndCnt[nmax+1];
vector<int> adj[nmax+1];
void AhoCorasickBuild(){
    queue<int> q;
    Failure[0] = -1;
    for(int i = 0; i<alpha; i++){
        if(nxt[0][i] == -1) continue;
        Failure[nxt[0][i]] = 0;
        q.push(nxt[0][i]);
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();

		patEndCnt[v] += patEndCnt[Failure[v]] + EndCnt[v];
        for(int i = 0; i<alpha; i++){
            if(nxt[v][i] == -1){
                continue;
            }
            int n = nxt[v][i], cur = Failure[v];
            while(cur != 0 && nxt[cur][i] == -1) cur = Failure[cur];
            if(nxt[cur][i] != -1) cur = nxt[cur][i];
            Failure[n] = cur;
            q.push(n);
        }
    }
    for(int i = 0; i<tsz; i++)
	    adj[Failure[i]].push_back(i);		//adj[i] contains nodes whose failure link is i

    return;
}

int visitcnt[nmax+1];
int AhoCorasickSearch(char *str){
    int cur = 0;
    int found = 0;
    for(int i = 0; str[i] != 0; i++){
        while(cur != 0 && nxt[cur][str[i]-'a'] == -1) cur = Failure[cur];
        if(nxt[cur][str[i]-'a'] != -1) cur = nxt[cur][str[i]-'a'];
        found += patEndCnt[cur];
//        cout<<found<<endl;
        visitcnt[cur]++;
    }
    return found;
}

int dfs(int root){
    for(int n: adj[root])
        visitcnt[root] += dfs(n);
    return visitcnt[root];
}

char str[nmax];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    MakeNode(-1);

    int p;
    cin>>p;

    for(int i = 0; i<p; i++){
        cin>>str;
        TrieInsert(str);
    }


    AhoCorasickBuild();

    cin>>str;

    int cnt = AhoCorasickSearch(str);
    cout<<cnt<<endl;



}

